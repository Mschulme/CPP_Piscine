#include "ClapTrap.hpp"

// Orthodox canonical form

ClapTrap::ClapTrap()
{

}


ClapTrap::ClapTrap(std::string name, unsigned int Energy)
{
	Name = name;
	Hit_Points = 10;
	Energy_Points = Energy;
	Attack_damage = 0;
	std::cout << "ClapTrap: Constructor called. " << name << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	Name = name;
	Hit_Points = 10;
	Energy_Points = 10;
	Attack_damage = 0;
	std::cout << "ClapTrap: Constructor called. " << name << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &obj)
{
    if(this != &obj)
    {
       	Name = obj.Name;
		Hit_Points = obj.Hit_Points;
		Energy_Points = obj.Energy_Points;
		Attack_damage = obj.Attack_damage;
    }
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap: Destructor called." << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &obj)
{
    if (this != &obj)
    {
       	Name = obj.Name;
		Hit_Points = obj.Hit_Points;
		Energy_Points = obj.Energy_Points;
		Attack_damage = obj.Attack_damage;
    }
    return (*this);
}

// Member functions

void ClapTrap::attack(const std::string& target)
{
	std::cout << "ClapTrap " << Name << " attacks " << target << ", causing " << Attack_damage << " points of damage!" << std::endl;
} 

void ClapTrap::takeDamage(unsigned int amount)
{
	if (Hit_Points < 0)
	{
		std::cout << "Stop! Stop! He's Already Dead!" << std::endl;
		return;
	}

	Hit_Points -= amount;
	std::cout << "Hero took " << amount << " damage." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (Energy_Points <= 0)
	{
		std::cout << "No energy points available." << std::endl;
		Energy_Points -= 1;
		return;
	}
	if (Hit_Points <= 0)
	{
		std::cout << "No repair possible. No Hit_Points left." << std::endl;
		return;
	}
	Hit_Points += amount;
	Energy_Points -= 1;
	std::cout << "ClapTrap: " << Name << " gained " << amount <<  " health points." <<std::endl;
}
