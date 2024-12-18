#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

#include <string>
#include <cstdlib>
#include <iostream>
#include <exception>

class Bureaucrat;

class Form
{
	private: 
		const std::string name;
		bool isSigned;
		const int gradeToSign;
		const int gradeToExecute;

	public:
		Form(void);
		Form(const std::string &name, int gradeToSign, int gradeToExecute);

		~Form(void);
		Form(const Form &other);
		Form &operator=(const Form &other);

		bool getIsSigned(void) const;
		int getGradeToSign(void) const;
		std::string getName(void) const;
		int getGradeToExecute(void) const;

		void beSigned(const Bureaucrat &bureaucrat);

		class GradeTooLowException : public std::exception
		{
			virtual const char *what() const throw();
		};

		class GradeTooHighException : public std::exception
		{
			virtual const char *what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &o, const Form &a);

#endif