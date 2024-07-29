/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:11:23 by mschulme          #+#    #+#             */
/*   Updated: 2024/07/08 15:12:35 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string str, Weapon &weapon) : weapon(weapon)
{
	name = str;
}

HumanA::~HumanA(void)
{
	std::cout << "HumanA: Destructor called." << std::endl;
}

void HumanA::attack(void)
{
	std::cout << name << " attacks with " << weapon.getType() << std::endl;
}
