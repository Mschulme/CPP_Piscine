#include <algorithm>
#include <chrono>
#include <execution>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>


int main(void)
{
    const std::size_t N = 1000'000'000;
    std::vector<int> data(N);

    std::random_device rd;

    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dist(1, 10);

    for (auto &val : data)
    {
        val = dist(gen);
    }

    auto measure = [](auto&& func) {
        auto start = std::chrono::high_resolution_clock::now();
        auto result = func();
        auto stop  = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
        return std::make_pair(result, duration);
    };


    {
        auto [result, ms] = measure([&]() {
            return std::accumulate(data.begin(), data.end(), 0LL); // use long long to avoid overflow
        });
        std::cout << std::setw(38) << std::left << "std::accumulate (sequential)" 
                  << "Result: " << result 
                  << ", Time: " << ms << " ms\n";
    }


    {
        auto [result, ms] = measure([&]() {
            return std::reduce(std::execution::seq, data.begin(), data.end(), 0LL);
        });
        std::cout << std::setw(38) << std::left << "std::reduce(seq)" 
                  << "Result: " << result 
                  << ", Time: " << ms << " ms\n";
    }


    {
        auto [result, ms] = measure([&]() {
            return std::reduce(std::execution::par, data.begin(), data.end(), 0LL);
        });
        std::cout << std::setw(38) << std::left << "std::reduce(par)" 
                  << "Result: " << result 
                  << ", Time: " << ms << " ms\n";
    }


    {
        auto [result, ms] = measure([&]() {
            return std::reduce(std::execution::par_unseq, data.begin(), data.end(), 0LL);
        });
        std::cout << std::setw(38) << std::left << "std::reduce(par_unseq)" 
                  << "Result: " << result 
                  << ", Time: " << ms << " ms\n";
    }


    {
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

    }

    return EXIT_SUCCESS;
}