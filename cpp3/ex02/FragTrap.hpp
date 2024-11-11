#ifndef FRAGTRAP_HP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
	private:
		;
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &other);
		~FragTrap(void);
 		FragTrap &operator=(const FragTrap &obj);

		void attack(const std::string& target);
		void highFiveGuys(void);
};

#endif