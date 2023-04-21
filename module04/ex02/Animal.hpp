/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:48:44 by alboudje          #+#    #+#             */
/*   Updated: 2023/04/20 13:34:29 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
protected:
	std::string	_type;
public:
	Animal();
	Animal(const Animal&);
	virtual ~Animal();

	Animal&				operator=(const Animal&);

	void				setType(const std::string&);
	const std::string&	getType(void) const;
	virtual void		makeSound(void) const = 0;
};

#endif
