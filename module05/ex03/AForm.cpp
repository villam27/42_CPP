/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 11:23:52 by alboudje          #+#    #+#             */
/*   Updated: 2023/04/24 12:35:36 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(const std::string name, const unsigned signedGrade, const unsigned execution) :	_name(name),
																							_signedGrade(signedGrade),
																							_executGrade(execution)
{
		if (signedGrade < 1 || execution < 1)
			throw (AForm::GradeTooHighException());
		if (signedGrade > 150 || execution > 150)
			throw (AForm::GradeTooLowException());
	_isSigned = false;
	std::cout << "AForm Constructor called" << std::endl;
}

AForm::AForm(const AForm& copy) : _name(copy.getName()), _signedGrade(copy.getSignedGrade()), _executGrade(copy.getExecGrade())
{
	std::cout << "AForm Copy Constructor called" << std::endl;
	*this = copy;
}

AForm::~AForm()
{
	std::cout << "AForm Destructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& copy)
{
	_isSigned = copy.getIsSigned();
	return (*this);
}

const std::string AForm::getName() const
{
	return (_name);
}

unsigned AForm::getIsSigned() const
{
	return (_isSigned);
}

unsigned AForm::getExecGrade() const
{
	return (_executGrade);
}

unsigned AForm::getSignedGrade() const
{
	return (_signedGrade);
}

void	AForm::setSigned(const bool sign)
{
	_isSigned = sign;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
		if (bureaucrat.getGrade() <= _signedGrade)
		{
			_isSigned = true;
			std::cout << bureaucrat.getName() << " signed " << _name << std::endl;
		}
		else
		{
			std::cout << bureaucrat.getName() << " couldn't sign " << _name << " because grade too low"<< std::endl;
			throw(AForm::GradeTooLowException());
		}

}

std::ostream& operator<<(std::ostream& ostream, AForm const &f)
{
	std::cout << f.getName() << " signed?: " << f.getIsSigned() << std::endl;
	std::cout << "minimum execution grade: " << f.getExecGrade() << std::endl;
	std::cout << "minimum signed grade: " << f.getSignedGrade();
	return (ostream);
}