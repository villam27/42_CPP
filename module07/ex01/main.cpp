/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:00:11 by alboudje          #+#    #+#             */
/*   Updated: 2023/05/06 15:41:18 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>
#include "Iter.hpp"

int main( void )
{
	int *array = NULL;
	int array2[3] = {4, 5, 6};
	std::string s[3] = {"abc", "def", "ghi"};

	iter<int *>(array, 42, print_i<int>);
	iter<int *>(array2, 3, print_i<int>);
	iter<std::string *>(s, 3, print_i<std::string>);
	return 0;
}