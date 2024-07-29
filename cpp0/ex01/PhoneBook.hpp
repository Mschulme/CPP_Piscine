#ifndef PhoneBook_HPP
#define PhoneBook_HPP

#include "Contact.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <cctype>
#include <sstream>

class PhoneBook
{
	private:
		Contact		contacts[8];
		std::string	helperinput(std::string str, std::string message, int flag);
		std::string	helperinputIndex(std::string str);
		int			anotherhelper(std::string str);
		int			anotherhelperphone(std::string str);
		void		EnterIndex(void);
		void		PrintPhoneBook(void);

	public:
		void		AddFunction(int index);
		void		SearchFunction(void);
};

void	clear(void);

#endif
