#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <cstdlib>
#include <iostream>
#include <exception>

class Zombie
{
	private:
		std::string name;
	public:
		Zombie(const std::string &str);
		~Zombie(void);

		void announce(void);
};

Zombie*	newZombie(const std::string &str);
void	randomChump(const std::string &name);

#endif
