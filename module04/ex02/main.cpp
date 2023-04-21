/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:50:05 by alboudje          #+#    #+#             */
/*   Updated: 2023/04/20 13:35:39 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const Dog*	j = new Dog();
	const Cat*	i = new Cat();
	const Cat	k(*i);
	const Dog	l = *j;

	i->makeSound();
	delete j;
	delete i;
	k.makeSound();
	l.makeSound();
	return (0);
}
