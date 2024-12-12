#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "Form.hpp"

#include <string>
#include <cstdlib>
#include <iostream>
#include <exception>

class Form;

class Bureaucrat
{
	private:
        int grade_bureaucrat;
		std::string name_bureaucrat;

	public:
		Bureaucrat();
		Bureaucrat(const std::string &str, int grade);
		~Bureaucrat(void);

		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);

        void increase_grade(int grade_change);
        void decrease_grade(int grade_change);

		int getGrade(void);
		std::string getName(void);

		void signForm(Form &form);

		class GradeTooLowException : public std::exception
		{
			virtual const char *what() const throw();
		};

		class GradeTooHighException : public std::exception
		{
			virtual const char *what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat *a);

#endif
