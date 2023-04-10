/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:39:38 by alboudje          #+#    #+#             */
/*   Updated: 2023/04/10 13:33:02 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

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
	
	private:
		int					_raw;
		static const int	_fractional;
};

#endif //FIXED_HPP