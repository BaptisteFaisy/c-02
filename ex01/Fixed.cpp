/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 21:26:09 by bfaisy            #+#    #+#             */
/*   Updated: 2023/12/27 19:05:59 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

Fixed::Fixed(void) : nbr_virg(0)
{
	std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(int a)
{
	nbr_virg = (a << nbr_fraction);
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(float const val)
{
	std::cout << "Float constructor called" << std::endl;
	nbr_virg = int(roundf(val * (1 << nbr_fraction)));
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	std::cout << "Copy assignment operator called" << std::endl;
	nbr_virg = other.getRawBits();
}
// decalage vers la gauche diviser par 2^fraction
float Fixed::toFloat(void) const
{
	return float(nbr_virg) / (1 << nbr_fraction);
}
// decalage vers la droite, équivaut à une division par 2^fraction
int Fixed::toInt(void) const
{
	return nbr_virg >> nbr_fraction;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    nbr_virg = other.getRawBits();
    return *this;
}

std::ostream& operator<<(std::ostream& o, const Fixed& fixed)
{
	o << fixed.toFloat();
	return o;
}

void Fixed::setRawBits(int const raw)
{
	nbr_virg = raw;
	return ;
}

int Fixed::getRawBits(void) const
{
	return nbr_virg;
}
