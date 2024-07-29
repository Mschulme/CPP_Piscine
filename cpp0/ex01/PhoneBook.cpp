/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:22:44 by mschulme          #+#    #+#             */
/*   Updated: 2023/08/14 18:25:35 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

void	press_any_key()
{
	std::cout << "Press Enter to Continue";
	std::string temp;
	std::getline(std::cin, temp);
}

int	PhoneBook::anotherhelper(std::string str)
{
	unsigned int	j;

	for (j = 0; j < str.size(); j++)
	{
		if (!isdigit(str[j]))
			return (1);
	}
	if (j == 0)
		return (1);
	return (0);
}

void PhoneBook::PrintPhoneBook(void)
{
	std::string	str;
	int i = 0;

	std::cout << std::setw(13) << "" << std::setw(10) << "First name" <<  std::setw(12) <<"Last name" << std::setw(13) << "Nickname" << std::endl;
	while (i < 8)
	{
		std::cout << std::setw(10) << "Index: " << i << " | ";
 		if (contacts[i].FirstName.length() > 10)
			std::cout << std::setw(10) << contacts[i].FirstName.substr(0, 9) + "." << " | ";
		else
			std::cout << std::setw(10) << contacts[i].FirstName << " | ";
		if (contacts[i].LastName.length() > 10)
			std::cout << std::setw(10) << contacts[i].LastName.substr(0, 9) + "." << " | ";
		else
			std::cout << std::setw(10) << contacts[i].LastName << " | ";
		if (contacts[i].Nickname.length() > 10)
			std::cout << std::setw(10) << contacts[i].Nickname.substr(0, 9) + "." << std::endl;
		else
			std::cout << std::setw(10) << contacts[i].Nickname << std::endl;
		i++;
	}
}

std::string	PhoneBook::helperinputIndex(std::string str)
{
	int	stop = -1;
	int	index_book = 0;

	while (stop == -1)
	{
		std::getline(std::cin, str);
		if (anotherhelper(str) == 1)
			;
		else
		{
			index_book = std::stoi(str);
			if (index_book < 0 || index_book > 7)
				;
			else
				stop = 0;
		}
		std::cout << "Invalid input: Enter index between 0 and 7" << std::endl;
	}
	return (str);
}

void PhoneBook::EnterIndex(void)
{
	int			index_book;
	std::string	str;

	std::cout << "Enter index (without spaces): " << std::endl;
	str = helperinputIndex(str);
	index_book = std::stoi(str);

	clear();
	std::cout << "First name: " << contacts[index_book].FirstName << std::endl;
	std::cout << "Last name: " << contacts[index_book].LastName << std::endl;
	std::cout << "Nickname: " << contacts[index_book].Nickname << std::endl;
	std::cout << "Phone number: " << contacts[index_book].PhoneNumber << std::endl;
	std::cout << "Darkest Secret: " << contacts[index_book].Secret << std::endl;
	std::cout << std::endl;
	press_any_key();
}

void	PhoneBook::SearchFunction(void)
{
	PrintPhoneBook();
	EnterIndex();
}
