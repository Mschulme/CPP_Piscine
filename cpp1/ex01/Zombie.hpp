#include <string>
#include <sstream>
#include <cstdlib>
#include <iostream>

class Zombie
{
	private:
		int N;
		std::string	name;
	public:
		Zombie(void);
		~Zombie(void);

		void		announce(void);
		void		setName(const std::string &str);
		std::string	getName(void);
};

Zombie*	zombieHorde(int N, std::string name);
