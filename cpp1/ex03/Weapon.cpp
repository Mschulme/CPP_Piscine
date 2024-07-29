/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:21:15 by mschulme          #+#    #+#             */
/*   Updated: 2024/07/08 14:36:27 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string &str)
{
	weapon_type = str;
	std::cout << str << " Default constructor called." << std::endl;
}

void	Weapon::setType(const std::string &str)
{
	weapon_type = str;
}

const std::string &Weapon::getType()
{
	return (weapon_type);
}
