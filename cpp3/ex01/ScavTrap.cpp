#include "ScavTrap.hpp"

// Orthodox canonical form

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100)
{
	Name = name;
	Hit_Points = 100;
	Energy_Points = 50;
	Attack_damage = 20;
	std::cout << "ScavTrap: Constructor called. " << name << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &obj)
{
    if(this != &obj)
    {
       	Name = obj.Name;
		Hit_Points = obj.Hit_Points;
		Energy_Points = obj.Energy_Points;
		Attack_damage = obj.Attack_damage;
    }
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap: Destructor called." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &obj)
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

void ScavTrap::attack(const std::string& target)
{
	std::cout << "ScavTrap " << Name << " attacks " << target << ", causing " << Attack_damage << " points of damage!" << std::endl;
} 


void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;
} 
