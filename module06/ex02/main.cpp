/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:00:11 by alboudje          #+#    #+#             */
/*   Updated: 2023/05/05 11:22:58 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
	Data		*d = new (std::nothrow)Data;
	Data		*d2;
	uintptr_t	p;

	if (!d)
		return (1);
	d->i = 15;
	std::cout << "i: " << d->i << std::endl;
	p = Serializer::serialize(d);
	d2 = Serializer::deserialize(p);
	std::cout << "i: " << d->i << std::endl;
	std::cout << "i2: " << d2->i << std::endl;
	delete d;
	return (0);
}