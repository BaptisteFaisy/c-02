/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaisy <bfaisy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 21:25:59 by bfaisy            #+#    #+#             */
/*   Updated: 2023/12/27 22:18:40 by bfaisy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP


#include <cmath>
#include <iostream>

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

	int getRawBits(void) const;

	void setRawBits(int const raw);

	bool    operator>( const Fixed &rhs ) const ;
    bool    operator<( const Fixed &rhs ) const ;
    bool    operator>=( const Fixed &rhs ) const ;
    bool    operator<=( const Fixed &rhs ) const ;
    bool    operator==( const Fixed &rhs ) const ;
    bool    operator!=( const Fixed &rhs ) const ;

    Fixed   operator+( const Fixed &rhs ) const ;
    Fixed   operator-( const Fixed &rhs ) const ;
    Fixed   operator*( const Fixed &rhs ) const ;
    Fixed   operator/( const Fixed &rhs ) const ;

    Fixed&  operator++( void );// avant
    Fixed   operator++( int );// apres
    Fixed&  operator--( void );//avant
    Fixed   operator--( int );// apres

//  Static Function Members
// 			En déclarant un membre de fonction comme statique, vous le rendez indépendant de tout objet particulier de la classe.
//          objet particulier de la classe. Une fonction membre statique peut être appelée 
//          même si aucun objet de la classe n'existe et que les fonctions statiques sont accessibles
//          en utilisant uniquement le nom de la classe et l'opérateur de résolution de portée : :.

//         Une fonction membre statique ne peut accéder qu'à un membre de données statique, à d'autres fonctions membres statiques et à toute autre fonction extérieure à la classe.
//         et à toute autre fonction extérieure à la classe.

//         Les fonctions membres statiques ont une portée de classe et n'ont pas accès au pointeur this de la classe.
//         au pointeur this de la classe. Vous pouvez utiliser une fonction membre statique
//         pour déterminer si certains objets de la classe ont été créés ou non
//         voili voilou
    static Fixed& min( Fixed &a, Fixed &b );
    static const Fixed& min( const Fixed &a, const Fixed &b );
    static Fixed& max( Fixed &a, Fixed &b );
    static const Fixed& max( const Fixed &a, const Fixed &b );
};

//juste pour print et custom selon le type
std::ostream& operator<<(std::ostream& o, const Fixed& fixed);
#endif