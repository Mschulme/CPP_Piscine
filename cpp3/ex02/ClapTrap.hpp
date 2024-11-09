#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <cstdlib>
#include <iostream>

class	ClapTrap
{
	private:
		std::string	Name;
		int			Hit_Points;
		int			Energy_Points;
		int			Attack_damage;
		
	public:
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &other); // Copy constructor
		~ClapTrap(void);
 		ClapTrap &operator=(const ClapTrap &obj); // Assignment operator

		// Member functions
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif
