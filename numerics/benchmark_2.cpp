#include <iostream>
#include <omp.h>
#include <vector>
#include <random>
#include <chrono>

int main()
{
    // 1. Setup: problem size, random data generation
    const size_t N = 500'000'000; // 100 million elements
    std::vector<int> data(N);

    // Create random engine and distribution
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 10);

    // Fill the vector with random numbers
    for (size_t i = 0; i < N; ++i) {
        data[i] = dist(gen);
    }

    // A small helper for timing
    auto now_ms = []() {
        return std::chrono::high_resolution_clock::now();
    };
    
    // 2. Regular OpenMP-parallelized loop
    {
        long long sum = 0; // 64-bit to avoid overflow
        auto start = now_ms();

        #pragma omp parallel for reduction(+:sum)
        for (size_t i = 0; i < N; ++i) {
            sum += data[i];
        }

        auto end = now_ms();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        std::cout << "[Regular loop]   Sum: " << sum << ", Time: " << elapsed << " ms\n";
    }

    // 3. Manually unrolled loop (factor of 4)
    {
        long long sum = 0;
        auto start = now_ms();

        // We'll iterate i in steps of 4, and accumulate partial sums.
        #pragma omp parallel
        {
            long long local_sum = 0;
            #pragma omp for
            for (size_t i = 0; i < N; i += 4) {
                // Unroll by 4
                local_sum += data[i];
                if (i + 1 < N) local_sum += data[i + 1];
                if (i + 2 < N) local_sum += data[i + 2];
                if (i + 3 < N) local_sum += data[i + 3];
            }
            // Combine partial results
            #pragma omp atomic
            sum += local_sum;
        }

        auto end = now_ms();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        std::cout << "[Unrolled loop]  Sum: " << sum << ", Time: " << elapsed << " ms\n";
    }

    return 0;
}
