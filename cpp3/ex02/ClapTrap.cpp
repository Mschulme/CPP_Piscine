#include "ClapTrap.hpp"


ClapTrap::ClapTrap() : Hit_Points(10), Energy_Points(10), Attack_damage(0)
{
	std::cout << "ClapTrap: Default Constructor called." << std::endl;
}


ClapTrap::ClapTrap(std::string name): Name(name), Hit_Points(10), Energy_Points(10), Attack_damage(0)
{
	std::cout << "ClapTrap: Parametrized Constructor called. " << name << std::endl;
}


ClapTrap::ClapTrap(ClapTrap const &other)
{
	if(this != &other)
	{
        Name = other.Name;
		Hit_Points = other.Hit_Points;
		Energy_Points = other.Energy_Points;
		Attack_damage = other.Attack_damage;
	}
}


ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap: Destructor called." << std::endl;
}


ClapTrap &ClapTrap::operator=(const ClapTrap &other)
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


void	ClapTrap::attack(const std::string& target)
{
	if (Energy_Points == 0)
    {
		std::cout << "ClapTrap " << Name << " does not have enough energy to attack" << std::endl;
		return ;
	}
	if (Hit_Points == 0)
    {
		std::cout << "ClapTrap " << Name << " is dead and cannot attack!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << Name << " attacks " << target << ", causing " << Attack_damage << " points of damage!" << std::endl;
	Energy_Points -= 1;
	return ;
}


void ClapTrap::takeDamage(unsigned int amount)
{
	if (Hit_Points <= 0)
	{
		std::cout << "Stop! Stop! He's Already Dead!" << std::endl;
		return ;
	}

	if (static_cast<int>(amount) >= Hit_Points)
	{
		Hit_Points = 0;
		std::cout << "Hero took " << amount << " damage and is now dead." << std::endl;
	}
	else
	{
		Hit_Points -= amount;
		std::cout << "Hero took " << amount << " damage." << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (Energy_Points <= 0)
	{
		std::cout << "No energy points available." << std::endl;
		Energy_Points -= 1;
		return ;
	}
	if (Hit_Points <= 0)
	{
		std::cout << "No repair possible. No Hit_Points left." << std::endl;
		return ;
	}
	Hit_Points += amount;
	Energy_Points -= 1;
	std::cout << "ClapTrap: " << Name << " gained " << amount <<  " health points." <<std::endl;
}
