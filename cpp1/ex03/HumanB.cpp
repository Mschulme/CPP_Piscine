/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:14:03 by mschulme          #+#    #+#             */
/*   Updated: 2024/07/08 15:13:17 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string str)
{
	name = str;
}

HumanB::~HumanB(void)
{
	std::cout << "HumanB: Destructor called." << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	weapon_human_b = &weapon;
}

void HumanB::attack(void)
{
	std::cout << name << " attacks with " << weapon_human_b->getType() << std::endl;
}
