/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 17:25:17 by mschulme          #+#    #+#             */
/*   Updated: 2023/08/14 18:53:38 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int	main(int argc, char **argv)
{
	std::string	str;
	int			i;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		i = 1;
		while (argv[i] != NULL)
		{
			str = argv[i];
			for (unsigned int j = 0; j < str.size(); j++)
				str[j] = toupper(str[j]);
			std::cout << str;
			i++;
		}
		std::cout << std::endl;
	}
	return (EXIT_SUCCESS);
}
