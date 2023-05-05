/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:00:11 by alboudje          #+#    #+#             */
/*   Updated: 2023/05/05 11:58:13 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <ctime>
#include <cstdlib>

Base	*generate(void)
{
	int	i;

	i = std::rand() % 3;
	switch (i)
	{
	case 0:
		return (new A());
		break;
	case 1:
		return (new B());
		break;
	case 2:
		return (new C());
		break;
	default:
		return (NULL);
		break;
	}
}

void	identify(Base *b)
{
	std::cout << "Pointer identify" << std::endl;
	if (dynamic_cast<A *>(b) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(b) != NULL)
		std::cout << "B" << std::endl;
	else
		std::cout << "C" << std::endl;
}

void	identify(Base &b)
{
	std::cout << "Reference identify" << std::endl;
	try
	{
		A &a = dynamic_cast<A&>(b);
		static_cast<void>(a);
		std::cout << "A" << std::endl;
	}
	catch (...)
	{}
	try
	{
		B &bt = dynamic_cast<B&>(b);
		static_cast<void>(bt);
		std::cout << "B" << std::endl;
	}
	catch (...)
	{}
	try
	{
		C &c = dynamic_cast<C&>(b);
		static_cast<void>(c);
		std::cout << "C" << std::endl;
	}
	catch (...)
	{}
}

int	main(void)
{
	Base	*rbase;

	srand(std::time(0));
	rbase = generate();
	identify(rbase);
	identify(*rbase);
	delete rbase;
}