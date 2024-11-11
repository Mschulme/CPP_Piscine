#ifndef SCAVTRAP_HP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	private:
		;
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &other);
		~ScavTrap(void);
 		ScavTrap &operator=(const ScavTrap &obj);

		void attack(const std::string& target);
		void guardGate(void);
};

#endif