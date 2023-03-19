/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:21:00 by alboudje          #+#    #+#             */
/*   Updated: 2023/03/18 15:39:50 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"

int	main(void)
{
	Zombie	stack = Zombie("stack");
	Zombie	*heap = newZombie("heap");
	if (!heap)
		return (1);
	heap->announce();
	stack.announce();
	randomChump("stack 2");
	delete heap;
	return (0);
}