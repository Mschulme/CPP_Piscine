#include "Zombie.hpp"

std::string intToString(int x)
{
	std::string ret;
	std::stringstream string;

	string << x;
	ret = string.str();

	return (ret);
}

Zombie*	zombieHorde(int N, std::string str)
{
	Zombie* zombies = NULL;

	try
	{
		zombies = new Zombie[N];
	}
	catch (const std::bad_alloc &e)
	{
		std::cerr << "Memory allocation failed: " << e.what() << std::endl;
		return (NULL);
	}

	for (int i = 0; i < N; i++)
		zombies[i].setName(str + " " + intToString(i + 1));
	
	return (zombies);
}
