/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:00:11 by alboudje          #+#    #+#             */
/*   Updated: 2023/04/23 19:04:58 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat b("Ali", 450);
		std::cout << b << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl; 
	}
	try
	{
		Bureaucrat b("Ali", 0);
		std::cout << b << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl; 
	}
	try
	{
		Bureaucrat b("Ali", 42);
		std::cout << b << std::endl;
		b.decrGrade(1);
		b.incrGrade(1);
		std::cout << b << std::endl;
		b.decrGrade(170);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl; 
	}
	return (0);
}
