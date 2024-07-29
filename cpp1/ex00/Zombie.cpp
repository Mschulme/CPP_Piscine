/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:22:56 by mschulme          #+#    #+#             */
/*   Updated: 2024/07/08 12:45:50 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(const std::string &str)
{
	name = str;
	std::cout << "Constructor called: " << name << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "Destructor called: " << name << std::endl;
}

void Zombie::announce(void)
{
	std::cout << name <<": BraiiiiiiinnnzzzZ..." << std::endl;
}
