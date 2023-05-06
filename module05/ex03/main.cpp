/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:00:11 by alboudje          #+#    #+#             */
/*   Updated: 2023/05/06 13:22:53 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int	main(void)
{
	srand(std::time(0));
	std::cout << "	EX 1	:	ShrubberyCreationForm" << std::endl;
	try
	{
		Intern intern;
		Bureaucrat	ali("Ali", 1);
		AForm *f;

		f = intern.makeForm("not robotomy request", "Not working");
		ali.signForm(*f);
		ali.executeForm(*f);
		delete f;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl; 
	}
	std::cout << "	EX 2	:	ShrubberyCreationForm" << std::endl;
	try
	{
		Intern intern;
		Bureaucrat	ali("Ali", 1);
		AForm *f;

		f = intern.makeForm("presidential pardon", "Working");
		ali.signForm(*f);
		ali.executeForm(*f);
		delete f;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl; 
	}
	return (0);
}
