/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:36:30 by alboudje          #+#    #+#             */
/*   Updated: 2023/05/06 13:12:15 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern& copy);
		~Intern();
		Intern	&operator=(const Intern& copy);

		AForm	*makeForm(const std::string &name, const std::string &target);
		class NameNotExist : public std::exception
		{
			const char *what() const throw()
			{
				return "name doesn't exist";
			}
		};
};

#endif //INTERN_HPP