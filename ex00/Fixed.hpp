/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 21:25:59 by bfaisy            #+#    #+#             */
/*   Updated: 2023/12/27 15:35:58 by bfaisy           ###   ########.fr       */
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
	// Copie a vers b
	Fixed(const Fixed& other);
	// Partage la memoire entre a et b donc les valeurs
	Fixed &operator=(const Fixed& other);
	~Fixed();

	int getRawBits(void) const;

	void setRawBits(int const raw);
};

#endif