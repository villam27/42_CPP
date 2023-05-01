/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 11:19:52 by alboudje          #+#    #+#             */
/*   Updated: 2023/04/24 11:36:36 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
	public:
		Form(const std::string name, const unsigned signGrade, const unsigned execGrade);
		Form(const Form& copy);
		~Form();
		Form& operator=(const Form& copy);

		const std::string getName() const;
		unsigned getIsSigned() const;
		unsigned getSignedGrade() const;
		unsigned getExecGrade() const;

		void beSigned(const Bureaucrat& bureaucrat);
		
		class GradeTooHighException : public std::exception
		{
			const char *what() const throw(){ return "grade too high";};
		};

		class GradeTooLowException : public std::exception
		{
		   const char *what() const throw(){ return "grade too low";};
		};

	private:
		const std::string	_name;
		const unsigned		_signedGrade;
		const unsigned		_executGrade;
		bool				_isSigned;
};

std::ostream& operator<<(std::ostream& ostream, Form const &f);

#endif //FORM_HPP