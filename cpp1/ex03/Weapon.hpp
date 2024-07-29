#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>
#include <cstdlib>

class Weapon
{
	private:
		std::string weapon_type;
	public:
		Weapon(const std::string &str);
		void setType(const std::string &str);
		const std::string &getType();
};

#endif
