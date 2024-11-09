#ifndef HARL_HPP
#define HARL_HPP

#include <cstdlib>
#include <iostream>

class Harl
{
	private:
		std::string WarningLevels[4];
		void (Harl::*Pointer[4])();
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
	public:
		Harl(void);
		~Harl(void);
		void complain(std::string level);
};

#endif
