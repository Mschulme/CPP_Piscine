#include "ClapTrap.hpp"
#include "ScavTrap.hpp"


ScavTrap::ScavTrap()
{
	Hit_Points = 100;
	Energy_Points = 50;
	Attack_damage = 20;
	std::cout << "ScavTrap: Default constructor called." << std::endl;
}


ScavTrap::ScavTrap(std::string name)
{
	Name = name;
	Hit_Points = 100;
	Energy_Points = 50;
	Attack_damage = 20;
	std::cout << "ScavTrap: Parametrized constructor called. " << name << std::endl;
}


ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	if(this != &other)
	{
		Name = other.Name;
		Hit_Points = other.Hit_Points;
		Energy_Points = other.Energy_Points;
		Attack_damage = other.Attack_damage;
	}
}


ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap: Destructor called." << std::endl;
}


ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		Name = other.Name;
		Hit_Points = other.Hit_Points;
		Energy_Points = other.Energy_Points;
		Attack_damage = other.Attack_damage;
	}
	return (*this);
}


void	ScavTrap::attack(const std::string& target)
{
	if (Energy_Points == 0)
    {
		std::cout << "ScavTrap " << Name << " does not have enough energy to attack" << std::endl;
		return ;
	}
	if (Hit_Points == 0)
    {
		std::cout << "ScavTrap " << Name << " is dead and cannot attack!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << Name << " attacks " << target << ", causing " << Attack_damage << " points of damage!" << std::endl;
	Energy_Points -= 1;
	return ;
}


void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap: " << Name << " is now in Gate keeper mode." << std::endl;
} 
