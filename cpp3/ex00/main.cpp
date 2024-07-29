/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:13:03 by mschulme          #+#    #+#             */
/*   Updated: 2024/07/11 14:37:56 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap Hero("Hero");
	
	Hero.attack("Villain");
	Hero.takeDamage(3);
	Hero.beRepaired(3);
	
	Hero.takeDamage(7);
	Hero.beRepaired(3);
	
	Hero.takeDamage(7);
	Hero.beRepaired(3);

	Hero.beRepaired(0);
	Hero.beRepaired(0);
	Hero.beRepaired(0);
	Hero.beRepaired(0);
	Hero.beRepaired(0);
	Hero.beRepaired(0);
	Hero.beRepaired(0);
	Hero.beRepaired(0);
	Hero.beRepaired(0);
	Hero.beRepaired(0);
	Hero.beRepaired(0);	
	
	return (EXIT_SUCCESS);
}
