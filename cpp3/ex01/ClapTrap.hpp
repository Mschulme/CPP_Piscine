/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:20:12 by mschulme          #+#    #+#             */
/*   Updated: 2024/07/05 16:35:12 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>
#include <cstdlib>

class	ClapTrap
{
	private:
		std::string	Name;
		int			Hit_Points;
		int			Energy_Points;
		int			Attack_damage;
		
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(std::string name, unsigned int Energy);
		ClapTrap(const ClapTrap &other);
		~ClapTrap(void);
 		ClapTrap &operator=(const ClapTrap &obj);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif
