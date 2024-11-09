#include "HumanA.hpp"

HumanA::HumanA(std::string str, Weapon &weapon) : weapon(weapon)
{
	name = str;
	std::cout << "HumanA: Constructor called." << std::endl;
}

HumanA::~HumanA(void)
{
	std::cout << "HumanA: Destructor called." << std::endl;
}

void HumanA::attack(void)
{
	std::cout << name << " attacks with " << weapon.getType() << std::endl;
}
