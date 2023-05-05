/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:00:11 by alboudje          #+#    #+#             */
/*   Updated: 2023/05/05 15:42:00 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	srand(std::time(0));
	std::cout << "	EX 1	:	ShrubberyCreationForm" << std::endl;
	try
	{
		Bureaucrat	ali("Ali", 1);
		ShrubberyCreationForm shru("AAAA");
		ali.executeForm(shru);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl; 
	}
	std::cout << "	EX 2" << std::endl;
	try
	{
		Bureaucrat	ali("Ali", 1);
		ShrubberyCreationForm shru("AAAA");
		ali.signForm(shru);
		ali.executeForm(shru);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl; 
	}
	std::cout << "	EX 3" << std::endl;
	try
	{
		Bureaucrat	ali("Ali", 138);
		ShrubberyCreationForm shru("AAAA");
		ali.signForm(shru);
		ali.executeForm(shru);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl; 
	}
	std::cout << "	EX 4	:	RobotomyRequestForm" << std::endl;
	try
	{
		Bureaucrat	ali("Ali", 1);
		RobotomyRequestForm rob("AAAA");
		ali.executeForm(rob);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl; 
	}
	std::cout << "	EX 5" << std::endl;
	try
	{
		Bureaucrat	ali("Ali", 1);
		RobotomyRequestForm rob("AAAA");
		ali.signForm(rob);
		ali.executeForm(rob);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl; 
	}
	std::cout << "	EX 6" << std::endl;
	try
	{
		Bureaucrat	ali("Ali", 46);
		RobotomyRequestForm rob("AAAA");
		ali.signForm(rob);
		ali.executeForm(rob);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl; 
	}

	std::cout << "	EX 7	:	PresidentialPardonForm" << std::endl;
	try
	{
		Bureaucrat	ali("Ali", 1);
		PresidentialPardonForm rob("AAAA");
		ali.executeForm(rob);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl; 
	}
	std::cout << "	EX 8" << std::endl;
	try
	{
		Bureaucrat	ali("Ali", 1);
		PresidentialPardonForm rob("AAAA");
		ali.signForm(rob);
		ali.executeForm(rob);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl; 
	}
	std::cout << "	EX 9" << std::endl;
	try
	{
		Bureaucrat	ali("Ali", 6);
		PresidentialPardonForm rob("AAAA");
		ali.signForm(rob);
		ali.executeForm(rob);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl; 
	}
	return (0);
}
