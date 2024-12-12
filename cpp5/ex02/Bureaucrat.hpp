#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "AForm.hpp"

#include <string>
#include <cstdlib>
#include <iostream>
#include <exception>

class AForm;

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

		int getGrade(void) const;
		std::string getName(void);

		void signForm(AForm &form);
        void executeForm(AForm const &form) const;

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
