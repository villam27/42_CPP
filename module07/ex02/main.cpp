/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:00:11 by alboudje          #+#    #+#             */
/*   Updated: 2023/05/10 09:34:20 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <climits>
#include <string.h>
#include "Array.hpp"
#include "Array.tpp"

int main(void)
{
	Array <int>			array(5);
	Array <int>			a(5);
	Array <std::string>	arrayString(4);

	srand(time(NULL));
	for (int i = 0; i < 5; i++)
	{
		array[i] = i;
		a[i] = rand() % INT_MAX;
	}
	for (int i = 0; i < 5; i++)
		std::cout << array[i] << " " << a[i] << " ";
	std::cout << std::endl;
	arrayString[0] = "Bonjour";
	arrayString[1] = "j'aime";
	arrayString[2] = "les";
	arrayString[3] = "CANARDS!!";
	for (int i = 0; i < 5; i++)
	{
		try
		{
			std::cout << arrayString[i] << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what();
		}
	}
	return (0);
}