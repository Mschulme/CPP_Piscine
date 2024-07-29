#include "Array.tpp"
#include "Array.cpp"

int main()
{
	Array<int> arr(10);

	for (unsigned int i = 0; i < arr.size(); ++i)
		std::cout << arr[i] << ' ';

	
	std::cout << std::endl;

	try
	{
		std::cout << "Try index out of bounds: " << std::endl;
		arr[40] = 42;
	}
	catch(const std::exception& e)
	{
        std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	
	return (EXIT_SUCCESS);
}
