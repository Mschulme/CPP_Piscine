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
		ClapTrap();
		ClapTrap(std::string name);
		~ClapTrap(void);
		ClapTrap(const ClapTrap &other);
 		ClapTrap &operator=(const ClapTrap &obj);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif
