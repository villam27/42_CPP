/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:04:57 by alboudje          #+#    #+#             */
/*   Updated: 2023/05/05 15:06:22 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("Shrubbery", 72, 45), target(target)
{
	std::cout << "Robotomy constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy.getName(), 145, 137), target(copy.getTarget())
{
	std::cout << "Robotomy Copy Constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Robotomy Destructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy)
{
	target = copy.getTarget();
	if (copy.getIsSigned())
		setSigned(true);
	return (*this);
}

std::string RobotomyRequestForm::getTarget() const
{
	return (target);
}

void	RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	int	i;

	if (!getIsSigned())
		throw RobotomyRequestForm::NotSignedException();
	else if (executor.getGrade() > 45)
		throw RobotomyRequestForm::GradeTooLowException();
	i = std::rand() % 2;
	std::cout << "Make some drill noises" << std::endl;
	if (i == 0)
		std::cout << getTarget() << " has been robotomized successfully" << std::endl;
	else
		std::cout << getTarget() << " failed" << std::endl;
}