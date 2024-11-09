#include "Zombie.hpp"

Zombie::Zombie(const std::string &str)
{
	name = str;
	std::cout << "Constructor called: " << name << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "Destructor called: " << name << std::endl;
}

void Zombie::announce(void)
{
	std::cout << name <<": BraiiiiiiinnnzzzZ..." << std::endl;
}
