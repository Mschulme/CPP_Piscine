/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:22:51 by mschulme          #+#    #+#             */
/*   Updated: 2024/07/08 12:45:54 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <exception>

class Zombie
{
	private:
		std::string name;
	public:
		Zombie(const std::string &str);
		~Zombie(void);
		void announce(void);
};

Zombie*	newZombie(const std::string &str);
void	randomChump(const std::string &name);

#endif
