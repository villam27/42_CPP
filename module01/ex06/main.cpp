/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:21:00 by alboudje          #+#    #+#             */
/*   Updated: 2023/04/10 09:57:47 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl harl;

	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <LEVEL>" << std::endl;
		return (1);
	}
	harl.complainFilter(argv[1]);
	return (0);
}