/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:04:57 by alboudje          #+#    #+#             */
/*   Updated: 2023/05/05 15:06:22 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("Presidential", 72, 45), target(target)
{
	std::cout << "Robotomy constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy.getName(), 145, 137), target(copy.getTarget())
{
	std::cout << "Robotomy Copy Constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Robotomy Destructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy)
{
	target = copy.getTarget();
	if (copy.getIsSigned())
		setSigned(true);
	return (*this);
}

std::string PresidentialPardonForm::getTarget() const
{
	return (target);
}

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	if (!getIsSigned())
		throw PresidentialPardonForm::NotSignedException();
	else if (executor.getGrade() > 5)
		throw PresidentialPardonForm::GradeTooLowException();
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}