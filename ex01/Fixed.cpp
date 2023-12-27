/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 21:26:09 by bfaisy            #+#    #+#             */
/*   Updated: 2023/12/27 16:05:43 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void) : nbr_virg(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
	: nbr_virg(other.nbr_virg)
{
	std::cout << "Copy constructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return nbr_virg;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	nbr_virg = raw;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Assignment operator called" << std::endl;
    nbr_virg = other.nbr_virg;
    return *this;
}
