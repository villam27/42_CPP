/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:00:11 by alboudje          #+#    #+#             */
/*   Updated: 2023/03/14 16:10:54 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	int	i;
	int j;

	i = 1;
	j = 0;
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE. *" << std::endl;
		return (0);
	}
	while (i < argc)
	{
		j = 0;
		while (argv[i][j]	)
		{
			std::cout << static_cast<char>(std::toupper(argv[i][j]));
			j++;
		}
		if (i != argc - 1)
			std::cout << " ";
		i++;
	}
	std::cout << std::endl;
	return (0);
}