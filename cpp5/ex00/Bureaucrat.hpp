#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <cstdlib>
#include <iostream>

class Bureaucrat
{
	private:
		std::string name_bureaucrat;
        int grade_bureaucrat;
	public:
		// Orthodox canonical form
		Bureaucrat(const std::string &str, int grade);
		~Bureaucrat(void);

		// Increase and decrease function
        void increase_grade(int grade_change);
        void decrease_grade(int grade_change);

		// Getter functions
		std::string getName(void);
		int getGrade(void);

		// Classes for the TooLow and TooHigh Exception.
		class GradeTooLowException : public std::exception
		{
		public:
			virtual const char *what() const throw();
		};

		class GradeTooHighException : public std::exception
		{
		public:
			virtual const char *what() const throw();
		};

};

std::ostream	&operator<<(std::ostream &o, Bureaucrat *a);

#endif
