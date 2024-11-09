#include "Weapon.hpp"

Weapon::Weapon(const std::string &str)
{
	weapon_type = str;
	std::cout << str << " Default constructor called." << std::endl;
}

void	Weapon::setType(const std::string &str)
{
	weapon_type = str;
}

const std::string &Weapon::getType()
{
	return (weapon_type);
}
