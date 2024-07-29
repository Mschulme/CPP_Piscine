/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:13:07 by mschulme          #+#    #+#             */
/*   Updated: 2024/07/08 12:54:18 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>

class Zombie
{
	private:
		std::string	name;
		int N;
	public:
		Zombie(void);
		~Zombie(void);
		void		announce(void);
		void		setName(const std::string &str);
		std::string	getName(void);
};

Zombie*	zombieHorde(int N, std::string name);
