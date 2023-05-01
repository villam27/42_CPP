/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:04:57 by alboudje          #+#    #+#             */
/*   Updated: 2023/05/01 16:15:47 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : Form("Shrubbery", 145, 137), target(target)
{
	std::cout << "Shrubbery constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : Form(copy.getName(), 145, 137), target(copy.getTarget())
{
	std::cout << "Shrubbery Copy Constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Shrubbery Destructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
	target = copy.getTarget();
	if (copy.getIsSigned())
		setSigned(true);
	return (*this);
}

std::string ShrubberyCreationForm::getTarget() const
{
	return (target);
}

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (!getIsSigned())
		throw ShrubberyCreationForm::NotSignedException();
	else if (executor.getGrade() > 137)
		throw ShrubberyCreationForm::GradeTooLowException();
	else
	{
		std::ofstream file(std::string(getTarget() + "_shrubbery").c_str(), std::ios::out | std::ios::trunc);
		if (!file)
		{
			std::cout << "error while creating the file" << std::endl;
			return ;
		}
		for (int i = 0; i < 4; i++)
		{
			file << "       _-_"		<< std::endl;
			file << "    /~~   ~~\\"	<< std::endl;
			file << " /~~         ~~\\"	<< std::endl;
			file << "{               }"<< std::endl;
			file << " \\  _-     -_  /"<< std::endl;
			file << "   ~  \\\\ //  ~"<< std::endl;
			file << "_- -   | | _- _"<< std::endl;
			file << "  _ -  | |   -_"<< std::endl;
			file << "      // \\\\"<< std::endl;
		}
	}
}