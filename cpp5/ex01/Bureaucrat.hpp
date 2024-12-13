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
		std::string name_bureaucrat;
        int grade_bureaucrat;

	public:
		Bureaucrat();
		Bureaucrat(const std::string &str, int grade);
		~Bureaucrat(void);

		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);

        void increase_grade(int grade_change);
        void decrease_grade(int grade_change);

		int getGrade(void) const ;
		std::string getName(void) const;

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

std::ostream	&operator<<(std::ostream &o, const Bureaucrat &a);

#endif
