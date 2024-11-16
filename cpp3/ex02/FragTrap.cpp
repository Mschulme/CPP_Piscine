#include "ClapTrap.hpp"
#include "FragTrap.hpp"


FragTrap::FragTrap()
{
	Hit_Points = 100;
	Energy_Points = 100;
	Attack_damage = 30;
	std::cout << "FragTrap: Default constructor called." << std::endl;
}


FragTrap::FragTrap(std::string name)
{
	Name = name;
	Hit_Points = 100;
	Energy_Points = 100;
	Attack_damage = 30;
	std::cout << "FragTrap: Parametrized constructor called. " << name << std::endl;
}


FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	if(this != &other)
	{
		Name = other.Name;
		Hit_Points = other.Hit_Points;
		Energy_Points = other.Energy_Points;
		Attack_damage = other.Attack_damage;
	}
}


FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap: Destructor called." << std::endl;
}


FragTrap &FragTrap::operator=(const FragTrap &other)
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


// Member functions FragTrap


void	FragTrap::attack(const std::string& target)
{
	if (Energy_Points <= 0)
    {
		std::cout << "FragTrap " << Name << " does not have enough energy to attack" << std::endl;
		return ;
	}
	if (Hit_Points <= 0)
    {
		std::cout << "FragTrap " << Name << " is dead and cannot attack!" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << Name << " attacks " << target << ", causing " << Attack_damage << " points of damage!" << std::endl;
	Energy_Points -= 1;
	return ;
}


void FragTrap::highFiveGuys(void)
{
	std::cout << "FragTrap: " << Name << " high fives." << std::endl;
} 
