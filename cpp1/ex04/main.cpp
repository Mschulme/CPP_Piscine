/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 00:11:52 by mschulme          #+#    #+#             */
/*   Updated: 2024/07/08 16:54:15 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cstdlib>

int	main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "Wrong number of arguments." << std::endl;
		return (EXIT_FAILURE);
	}
	else
	{
		std::string filename = argv[1];
		std::string old_word = argv[2];
		std::string new_word = argv[3];
		std::string new_file = filename + ".replace";

		std::ifstream source(filename.c_str());
		if (!source)
		{
			std::cout << "Error: Unable to open file." << std::endl;
			return (EXIT_FAILURE);
		}
		std::ofstream destination(new_file.c_str());
		std::string	line;
		while (std::getline(source, line))
		{
			size_t pos = 0;
			std::string new_line;
			while ((pos = line.find(old_word)) != std::string::npos)
			{
				new_line += line.substr(0, pos) + new_word;
				line = line.substr(pos + old_word.length());
			}
			new_line =  new_line + line;
			destination << new_line << std::endl;
		}
		source.close();
		destination.close();
	}
}
