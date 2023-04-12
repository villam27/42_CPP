/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:39:38 by alboudje          #+#    #+#             */
/*   Updated: 2023/04/12 09:34:58 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <ostream>

#define GET_DECIMAL(STEPS) (1 << (STEPS))

class Fixed
{
	public:
		Fixed();
		Fixed(const int raw);
		Fixed(const float raw);
		Fixed(const Fixed &copy);
		~Fixed();
		Fixed &operator = (const Fixed &copy);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
	
		float	toFloat(void) const;
		int		toInt(void) const;

	private:
		int					_raw;
		static const int	_fractional;
};

std::ostream	&operator << (std::ostream &output, const Fixed &fixed);

#endif //FIXED_HPP