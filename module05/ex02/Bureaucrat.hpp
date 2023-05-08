/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 18:31:04 by alboudje          #+#    #+#             */
/*   Updated: 2023/05/08 10:18:44 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream> 
#include <exception> 

class AForm;

class Bureaucrat
{
	public:
		Bureaucrat(std::string name, unsigned grade);
		Bureaucrat(const Bureaucrat& copy);
		~Bureaucrat();
		Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat& copy);
	
		std::string		getName() const;
		unsigned int	getGrade() const;
		void			incrGrade(unsigned grade);
		void			decrGrade(unsigned grade);

		void			signForm(AForm &form);
		void			executeForm(AForm const &form);
	
		class GradeTooHighException : public std::exception
		{
			const char *what() const throw()
			{
				return "grade too high";
			}
		};
		class GradeTooLowException : public std::exception
		{
			const char *what() const throw()
			{
				return "grade too low";
			}
		};
	
	private:
		const std::string	_name;
		unsigned			_grade;
};

std::ostream& operator<<(std::ostream& ostream, Bureaucrat const &b);

#endif