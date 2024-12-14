#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

#include <string>
#include <cstdlib>
#include <iostream>
#include <exception>

class Bureaucrat;

class AForm
{
	private: 
		const std::string name;
		bool isSigned;
		const int gradeToSign;
		const int gradeToExecute;

	public:
		AForm(void);
		AForm(const std::string &name, int gradeToSign, int gradeToExecute);

		virtual ~AForm(void);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);

		bool getIsSigned(void) const;
		int getGradeToSign(void) const;
		std::string getName(void) const;
		int getGradeToExecute(void) const;

		void beSigned(Bureaucrat &bureaucrat);

        virtual void execute(Bureaucrat const &executor) const = 0;


	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw();
	};

	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw();
	};

	class FormNotSignedException : public std::exception
	{
		virtual const char *what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &o, const AForm &a);

#endif
