/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 18:29:11 by mschulme          #+#    #+#             */
/*   Updated: 2024/07/02 19:23:08 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "Constructor called..."<< std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "Destructor called: " << name << std::endl;
}

void	Zombie::announce(void)
{
	std::string name_zombie = getName();
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(const std::string &str)
{
	name = str;
}

std::string	Zombie::getName(void)
{
	return (name);
}
