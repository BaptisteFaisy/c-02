/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 21:25:59 by bfaisy            #+#    #+#             */
/*   Updated: 2023/12/27 16:10:48 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
private :
	int nbr_virg;
	static const int nbr_fraction = 8;
public :
	Fixed();
	Fixed(int a);
	Fixed(float a);
	// Copie a vers b
	Fixed(const Fixed& other);
	// Partage la memoire entre a et b donc les valeurs
	Fixed &operator=(const Fixed& other);
	~Fixed();

	float toFloat( void ) const;
	int toInt( void ) const;
};

#endif