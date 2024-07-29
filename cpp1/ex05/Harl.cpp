/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 21:21:37 by mschulme          #+#    #+#             */
/*   Updated: 2024/07/08 17:01:39 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	WarningLevels[0] = "DEBUG";
	WarningLevels[1] = "INFO";
	WarningLevels[2] = "WARNING";
	WarningLevels[3] = "ERROR";

	Pointer[0] = &Harl::debug;
	Pointer[1] = &Harl::info;
	Pointer[2] = &Harl::warning;
	Pointer[3] = &Harl::error;

	std::cout << "Harl: Constructor called." << std::endl;
	
}

Harl::~Harl(void)
{
	std::cout << "Harl: Destructor called." << std::endl;
}

void	Harl::debug(void)
{
	std::cout << "Debug Text" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "Info Text" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "Warning Text" << std::endl;
}

void	Harl::error(void)
{
	std::cout << "Error Text" << std::endl;
}

void	Harl::complain(std::string level)
{
	for (int i = 0; i < 4; i++)
	{
		if (WarningLevels[i] == level)
			(this->*Pointer[i])();
			return;
	}
}
