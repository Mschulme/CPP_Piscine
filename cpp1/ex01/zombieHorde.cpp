/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 22:35:53 by mschulme          #+#    #+#             */
/*   Updated: 2024/07/08 12:58:18 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

std::string intToString(int x)
{
	std::string ret;
	std::stringstream string;

	string << x;
	ret = string.str();

	return (ret);
}

Zombie*	zombieHorde(int N, std::string str)
{
	Zombie* zombies = NULL;

	try
	{
		zombies = new Zombie[N];
	}
	catch (const std::bad_alloc &e)
	{
		std::cerr << "Memory allocation failed: " << e.what() << std::endl;
		return (NULL);
	}

	for (int i = 0; i < N; i++)
		zombies[i].setName(str + " " + intToString(i + 1));
	
	return (zombies);
}
