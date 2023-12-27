/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 21:26:09 by bfaisy            #+#    #+#             */
/*   Updated: 2023/12/27 22:17:24 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

Fixed::Fixed(void) : nbr_virg(0)
{
}
Fixed::Fixed(int a)
{
	nbr_virg = (a << nbr_fraction);
}

Fixed::Fixed(float const val)
{
	nbr_virg = int(roundf(val * (1 << nbr_fraction)));
}

Fixed::~Fixed(void)
{
}

Fixed::Fixed(const Fixed& other)
{
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

bool    Fixed::operator>( const Fixed &a ) const {
    return getRawBits() > a.getRawBits();
}

bool    Fixed::operator<( const Fixed &a ) const {
    return getRawBits() < a.getRawBits();
}

bool    Fixed::operator>=( const Fixed &a ) const {
    return getRawBits() >= a.getRawBits();
}

bool   Fixed::operator<=( const Fixed &a ) const {
    return getRawBits() <= a.getRawBits();
}

bool  Fixed::operator==( const Fixed &a ) const {
    return getRawBits() == a.getRawBits();
}

bool    Fixed::operator!=( const Fixed &a ) const {
    return getRawBits() != a.getRawBits();
}


Fixed   Fixed::operator+( const Fixed &a ) const {
    return Fixed( toFloat() + a.toFloat() );
}

Fixed   Fixed::operator-( const Fixed &a ) const {
    return Fixed( toFloat() - a.toFloat() );
}

Fixed   Fixed::operator*( const Fixed &a ) const {
    return Fixed( toFloat() * a.toFloat() );
}

Fixed   Fixed::operator/( const Fixed &a ) const {
    return Fixed( toFloat() / a.toFloat() );
}


Fixed&   Fixed::operator++( void ) {
    ++nbr_virg;
    return *this;
}
// le int en arg est une convention
Fixed   Fixed::operator++( int ) {
    Fixed tmp( *this );
    tmp.nbr_virg = nbr_virg++;
    return tmp;
}

Fixed& Fixed::operator--( void ) {
    --nbr_virg;
    return *this;
}

Fixed Fixed::operator--( int ) {
    Fixed tmp( *this );
    tmp.nbr_virg = nbr_virg--;
    return tmp;
}


Fixed& Fixed::min( Fixed &a, Fixed &b ) {
    if ( a.getRawBits() < b.getRawBits() )
        return a;
    return b;
}

const Fixed& Fixed::min( const Fixed &a, const Fixed &b ) {
    if ( a.getRawBits() < b.getRawBits() )
        return a;
    return b;
}

Fixed& Fixed::max( Fixed &a, Fixed &b ) {
    if ( a.getRawBits() > b.getRawBits() )
        return a;
    return b;
}

const Fixed& Fixed::max( const Fixed &a, const Fixed &b ) {
    if ( a.getRawBits() > b.getRawBits() )
        return a;
    return b;
}