/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:00:11 by alboudje          #+#    #+#             */
/*   Updated: 2023/04/24 11:53:21 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int	main(void)
{
	try
	{
		Form		f("Form", 0, 42);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl; 
	}
	try
	{
		Form		f2("Form", 42, 422);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl; 
	}
	std::cout << "+++++++++++++++++++++++++++++++++++++" << std::endl;
	try
	{
		Bureaucrat	ali("Ali", 1);
		Bureaucrat	ducky("Ducky", 42);
		Form		f("Form", 1, 1);
		Form		f2("Form2", 150, 150);
		Form		f3 = f;
		std::cout << std::endl;
		std::cout << f << std::endl;
		std::cout << f2 << std::endl;
		std::cout << std::endl;
		ali.signForm(f);
		ali.signForm(f);
		std::cout << f << std::endl;
		std::cout << std::endl;
		ducky.signForm(f2);
		ali.signForm(f2);
		ducky.signForm(f3);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl; 
	}	
	return (0);
}
