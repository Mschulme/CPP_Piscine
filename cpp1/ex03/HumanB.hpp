#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include <cstdlib>
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	private:
		std::string name;
		Weapon *weapon_human_b;
	public:
		HumanB(std::string str);
		~HumanB(void);
		
		void attack(void);
		void setWeapon(Weapon &weapon_human_b);
};

#endif
