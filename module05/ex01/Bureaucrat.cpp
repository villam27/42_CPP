/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 18:38:13 by alboudje          #+#    #+#             */
/*   Updated: 2023/04/24 11:42:20 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(std::string name, unsigned grade) : _name(name), _grade(150)
{
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	std::cout << "Constructor called" << std::endl;
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy)
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = copy;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy)
{
	_name = copy.getName();
	_grade = copy.getGrade();
	return (*this);
}

std::string Bureaucrat::getName() const
{
	return (_name);
}

unsigned int Bureaucrat::getGrade() const
{
	return (_grade);
}

std::ostream& operator<<(std::ostream& ostream, Bureaucrat const& b)
{
	std::cout << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (ostream);
}

void	Bureaucrat::incrGrade(unsigned grade)
{
	if (_grade - grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else
		_grade -= grade;
}

void	Bureaucrat::decrGrade(unsigned grade)
{
	if (_grade + grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	else
		_grade += grade;
}

void	Bureaucrat::signForm(Form &form)
{
	if (form.getIsSigned())
		std::cout << form.getName() << " is already signed !" << std::endl;
	else
		form.beSigned(*this);
}