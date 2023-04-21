/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 12:37:17 by alboudje          #+#    #+#             */
/*   Updated: 2023/04/20 12:52:29 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain: constructor called" << std::endl;
	for (int i=0; i<100; i++)
	{
		_ideas[i] = "some idea";
	}
}

Brain::Brain(const Brain& ref)
{
	const std::string*	idea = ref.getIdeas();

	std::cout << "Brain: copy constructor called" << std::endl;
	for (int i=0; i<100; i++)
	{
		_ideas[i] = idea[i];
	}
}

Brain::~Brain()
{
	std::cout << "Brain: destructor called" << std::endl;
}

Brain&	Brain::operator=(const Brain& ref)
{
	const std::string*	idea = ref.getIdeas();

	std::cout << "Brain: copy assignment operator called" << std::endl;
	for (int i=0; i<100; i++)
	{
		_ideas[i] = idea[i];
	}
	return (*this);
}

const std::string*	Brain::getIdeas(void) const
{
	return (_ideas);
}