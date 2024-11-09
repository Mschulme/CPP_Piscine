#ifndef FragTrap_HPP
#define FragTrap_HPP

#include <string>
#include <cstdlib>
#include <iostream>

class	FragTrap
{
	private:
		std::string	Name;
		int			Hit_Points;
		int			Energy_Points;
		int			Attack_damage;
		
	public:
		FragTrap(std::string name);
		FragTrap(const FragTrap &other); // Copy constructor
		~FragTrap(void);
 		FragTrap &operator=(const FragTrap &obj); // Assignment operator

		// Member functions
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif
