/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:39:38 by alboudje          #+#    #+#             */
/*   Updated: 2023/04/11 14:17:06 by alboudje         ###   ########.fr       */
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
		Fixed			&operator = (const Fixed &copy);

		bool			operator>(const Fixed &fixed);
    	bool			operator<(const Fixed &fixed);
    	bool			operator>=(const Fixed &fixed);
    	bool			operator<=(const Fixed &fixed);
    	bool			operator==(const Fixed &fixed);
    	bool			operator!=(const Fixed &fixed);

    	Fixed			operator+(const Fixed &fixed);
    	Fixed			operator-(const Fixed &fixed);
    	Fixed			operator*(const Fixed &fixed);
    	Fixed			operator/(const Fixed &fixed);

    	Fixed			&operator++();
    	Fixed			&operator--();
    	Fixed			operator++(int);
    	Fixed			operator--(int);

    	static const Fixed	min(const Fixed &nb1, const Fixed &nb2);
    	static Fixed		min(Fixed &nb1, Fixed &nb2);
    	static const Fixed	max(const Fixed &nb1, const Fixed &nb2);
    	static Fixed		max(Fixed &nb1, Fixed &nb2);

		float			toFloat(void) const;
		int				toInt(void) const;

		int				getRawBits(void) const;
		void			setRawBits(int const raw);
	
	private:
		int					_raw;
		static const int	_fractional;
};

std::ostream	&operator << (std::ostream &output, const Fixed &fixed);

#endif //FIXED_HPP