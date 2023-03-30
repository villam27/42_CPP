/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:21:00 by alboudje          #+#    #+#             */
/*   Updated: 2023/03/30 14:48:17 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

void	ft_sed(std::ifstream &inFile, std::ofstream& outFile, const std::string s1, const std::string s2)
{
	std::string	line;
	std::size_t	index;

	while (std::getline(inFile, line))
	{
		index = 0;
		while (1)
		{
			index = line.find(s1, index);
			if (index == std::string::npos)
				break ;
			line.erase(index, s1.size());
			line.insert(index, s2);
			index += s2.length();
		}
		outFile << line << std::endl;
	}
}

int	main(int argc, char **argv)
{
	std::string	filename;
	std::string s1, s2;

	if (argc != 4)
	{
		std::cerr << "Usage: ./set.out <filename> <search> <replace>" << std::endl;
		return (1);
	}
	filename = argv[1];
	std::ifstream inFile(argv[1]);
	if (!inFile.is_open())
	{
		std::cerr << "ERROR: cannot open " << filename << std::endl;
		return (1);
	}
	std::ofstream outFile(std::string(filename + ".replace").c_str(), std::ios::out | std::ios::trunc);
	if (!outFile.is_open())
	{
		std::cerr << "ERROR: cannot create replace file" << std::endl;
		return (1);
	}
	ft_sed(inFile, outFile, argv[2], argv[3]);
	return (0);
}