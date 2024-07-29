/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AddFunction.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:21:13 by mschulme          #+#    #+#             */
/*   Updated: 2023/08/15 16:06:19 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int	PhoneBook::anotherhelperphone(std::string str)
{
	unsigned int	j;

	for (j = 0; j < str.size(); j++)
	{
		if (!isdigit(str[j]) && !isspace(str[j]))
			return (1);
	}
	if (j == 0)
		return (1);
	return (0);
}

std::string	PhoneBook::helperinput(std::string str, std::string message, int flag)
{
	int	stop = -1;

	while (stop == -1)
	{
		clear();
		std::cout << message << std::endl;
		std::getline(std::cin, str);
		for (unsigned int j = 0; j < str.size(); j++)
		{
			if (isspace(str[j]) == 0)
				stop = 0;
		}
		if (stop == 0 && flag == 1)
		{
			stop = -1;
			if (anotherhelperphone(str) == 0)
				stop = 0;
		}
	}
	std::istringstream	ss(str);
	std::string			output;
	std::string			word;
	bool first = true;
	while (ss >> word)
	{
		if (first)
		{
			output += word;
			first = false;
		}
		else
			output += " " + word;
	}
	return (output);
}

void	PhoneBook::AddFunction(int index)
{
	std::string str;
	std::string message;

	message = "Enter your first name:";
	str = helperinput(str, message, 0);
	contacts[index % 8].FirstName = str;

	message = "Enter your last name:";
	str = helperinput(str, message, 0);
	contacts[index % 8].LastName = str;

	message = "Enter your nickname:";
	str = helperinput(str, message, 0);
	contacts[index % 8].Nickname = str;

	message = "Enter your phone number:";
	str = helperinput(str, message, 1);
	contacts[index % 8].PhoneNumber = str;

	message = "Enter a secret:";
	str = helperinput(str, message, 0);
	contacts[index % 8].Secret = str;
}
