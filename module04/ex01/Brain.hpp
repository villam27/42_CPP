/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 12:29:09 by alboudje          #+#    #+#             */
/*   Updated: 2023/04/20 12:52:33 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain
{
private:
	std::string	_ideas[100];
public:
	Brain();
	Brain(const Brain&);
	~Brain();

	Brain&				operator=(const Brain&);
	const std::string*	getIdeas(void) const;
};

#endif