/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:00:11 by alboudje          #+#    #+#             */
/*   Updated: 2023/05/16 14:14:41 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RNP.hpp"

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
	{
		std::cerr << "Usage: ./RNP <numbers>" << std::endl;
		return (1);
	}
	return (0);
}