/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:56:48 by mschulme          #+#    #+#             */
/*   Updated: 2024/05/01 11:56:43 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*Foo_heap;

	Foo_heap = newZombie("Foo_heap");
	if (Foo_heap == NULL)
		return (EXIT_FAILURE);
	Foo_heap->announce();
	delete Foo_heap;

	std::cout << std::endl;

	randomChump("Foo_Stack");
	return (EXIT_SUCCESS);
}
