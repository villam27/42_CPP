/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 11:19:52 by alboudje          #+#    #+#             */
/*   Updated: 2023/05/01 16:28:16 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <ctime>
#include <cstdlib>

class AForm
{
	public:
		AForm(const std::string name, const unsigned signGrade, const unsigned execGrade);
		AForm(const AForm& copy);
		virtual ~AForm();
		AForm& operator=(const AForm& copy);

		const std::string	getName() const;
		unsigned 			getIsSigned() const;
		unsigned 			getSignedGrade() const;
		unsigned 			getExecGrade() const;

		void				setSigned(const bool sign);

		void beSigned(const Bureaucrat& bureaucrat);
		virtual void execute(Bureaucrat const &bureaucrat) const = 0;
		
		class GradeTooHighException : public std::exception
		{
			const char *what() const throw(){ return "grade too high";};
		};

		class GradeTooLowException : public std::exception
		{
		   const char *what() const throw(){ return "grade too low";};
		};
		
		class NotSignedException : public std::exception
		{
		   const char *what() const throw(){ return "form not signed";};
		};

	private:
		const std::string	_name;
		const unsigned		_signedGrade;
		const unsigned		_executGrade;
		bool				_isSigned;
};

std::ostream& operator<<(std::ostream& ostream, AForm const &f);

#endif //FORM_HPP