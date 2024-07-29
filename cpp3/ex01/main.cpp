/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:13:03 by mschulme          #+#    #+#             */
/*   Updated: 2024/07/05 16:15:32 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap Hero("Hero");
	
	
	Hero.attack("Villain");
	Hero.takeDamage(3);
	Hero.beRepaired(3);
	
	Hero.guardGate();
	
	return (EXIT_SUCCESS);
}
