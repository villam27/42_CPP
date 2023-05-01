/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 11:23:52 by alboudje          #+#    #+#             */
/*   Updated: 2023/04/24 11:50:13 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string name, const unsigned signedGrade, const unsigned execution) :	_name(name),
																							_signedGrade(signedGrade),
																							_executGrade(execution)
{
		if (signedGrade < 1 || execution < 1)
			throw (Form::GradeTooHighException());
		if (signedGrade > 150 || execution > 150)
			throw (Form::GradeTooLowException());
	_isSigned = false;
	std::cout << "Form Constructor called" << std::endl;
}

Form::Form(const Form& copy) : _name(copy.getName()), _signedGrade(copy.getSignedGrade()), _executGrade(copy.getExecGrade())
{
	std::cout << "Form Copy Constructor called" << std::endl;
	*this = copy;
}

Form::~Form()
{
	std::cout << "Form Destructor called" << std::endl;
}

Form& Form::operator=(const Form& copy)
{
	_isSigned = copy.getIsSigned();
	return (*this);
}

const std::string Form::getName() const
{
	return (_name);
}

unsigned Form::getIsSigned() const
{
	return (_isSigned);
}

unsigned Form::getExecGrade() const
{
	return (_executGrade);
}

unsigned Form::getSignedGrade() const
{
	return (_signedGrade);
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
		if (bureaucrat.getGrade() <= _signedGrade)
		{
			_isSigned = true;
			std::cout << bureaucrat.getName() << " signed " << _name << std::endl;
		}
		else
		{
			std::cout << bureaucrat.getName() << " couldn't sign " << _name << " because grade too low"<< std::endl;
			throw(Form::GradeTooLowException());
		}

}

std::ostream& operator<<(std::ostream& ostream, Form const &f)
{
	std::cout << f.getName() << " signed?: " << f.getIsSigned() << std::endl;
	std::cout << "minimum execution grade: " << f.getExecGrade() << std::endl;
	std::cout << "minimum signed grade: " << f.getSignedGrade();
	return (ostream);
}