#include "Zombie.hpp"

Zombie*	newZombie(const std::string &str)
{
	Zombie *New_Zombie = NULL;

	try
	{
		New_Zombie = new Zombie(str);
	}
	catch (const std::bad_alloc &e)
	{
		std::cerr << "Memory allocation failed: " << e.what() << std::endl;
	}
	return (New_Zombie);
}
