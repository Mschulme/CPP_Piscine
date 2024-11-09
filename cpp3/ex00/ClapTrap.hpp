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
		// orthodox canoncial form
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &other);
		~ClapTrap(void);
 		ClapTrap &operator=(const ClapTrap &obj);
		// member functions 
		void attack(const std::string& target) const;
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif
