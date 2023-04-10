/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:50:32 by alboudje          #+#    #+#             */
/*   Updated: 2023/04/10 09:55:21 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
#define HARL_H

#include <iostream>
#include <string>

#define DEBUG	0
#define INFO	1
#define WARNING	2
#define ERROR	3
#define DEFAULT 4

class Harl
{
private:
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);

public:
	Harl();
	~Harl();

	int		getLevel(const std::string level);
	void	complain(const int level);
	void	complainFilter(const std::string level);
};

#endif //HARL_H