/* ************************************************************************** */	
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 18:30:29 by mschulme          #+#    #+#             */
/*   Updated: 2023/08/16 19:51:43 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int		N = 5;
	Zombie	*Zombies_heap;

	Zombies_heap = zombieHorde(N, "Zombie");
	if (Zombies_heap == NULL)
		return (EXIT_FAILURE);
	for (int i = 0; i < N; i++)
		Zombies_heap[i].announce();
	delete[] Zombies_heap;
	return (EXIT_SUCCESS);
}
