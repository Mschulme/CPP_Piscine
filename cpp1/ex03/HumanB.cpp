#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string str)
{
	name = str;
	std::cout << "HumanB: Constructor called." << std::endl;
}

HumanB::~HumanB(void)
{
	std::cout << "HumanB: Destructor called." << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	weapon_human_b = &weapon;
}

void HumanB::attack(void)
{
	std::cout << name << " attacks with " << weapon_human_b->getType() << std::endl;
}
