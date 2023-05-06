/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:39:56 by alboudje          #+#    #+#             */
/*   Updated: 2023/05/06 13:03:09 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Constructor called" << std::endl;
}

Intern::Intern(const Intern& copy)
{
	(void)copy;
	std::cout << "Copy constructor called" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Destructor called" << std::endl;
}

Intern	&Intern::operator=(const Intern& copy)
{
	(void)copy;
	std::cout << "Assignement operator called" << std::endl;
	return (*this);
}

AForm	*Intern::makeForm(const std::string &name, const std::string &target)
{
	size_t	index;

	index = 4;
	std::string	names[3] =
	{
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	for (size_t i = 0; i < 3; i++)
	{
		if (names[i] == name)
			index = i;
	}
	if (index == 4)
	{
		throw (NameNotExist());
		return (NULL);
	}
	switch (index)
	{
	case 0:
		return (new ShrubberyCreationForm(target));
		break;
	case 1:
		return (new RobotomyRequestForm(target));
		break;
	case 2:
		return (new PresidentialPardonForm(target));
		break;
	default:
		throw (Intern::NameNotExist());
		return (NULL);
	}
}