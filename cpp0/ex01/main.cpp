/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 18:15:07 by mschulme          #+#    #+#             */
/*   Updated: 2023/08/15 15:08:40 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

void	clear(void)
{
	system("clear");
}

std::string	input_phonebook(std::string input_str)
{	
	clear();
	std::cout << "Options: 'ADD', 'SEARCH', 'EXIT'!" << std::endl;
	std::getline(std::cin, input_str);
	clear();
	return (input_str);
}

int	main(void)
{
	PhoneBook	MyPhoneBook;
	int			index;
	std::string	str;

	std::cout << "PhoneBook!" << std::endl;
	index = 0;
	while (1)
	{
		str = input_phonebook(str);
		if (str.compare("EXIT") == 0 || str.compare("exit") == 0)
			break ;
		else if (str.compare("ADD") == 0 || str.compare("add") == 0)
		{
			MyPhoneBook.AddFunction(index);
			index++;
		}
		else if (str.compare("SEARCH") == 0 || str.compare("search") == 0)
			MyPhoneBook.SearchFunction();
	}
}
