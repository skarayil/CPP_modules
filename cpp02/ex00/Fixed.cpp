/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 15:05:39 by skarayil          #+#    #+#             */
/*   Updated: 2026/08/30 21:25:20 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
	: _fixedPointValue(0)
{
	std::cout << CONST << "Default constructor invoked" << FINAL << "\n\n";
}

Fixed::Fixed(const Fixed &other) 
	: _fixedPointValue(other._fixedPointValue)
{
	std::cout << COPY << "Copy constructor invoked" << FINAL << "\n\n";
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << ASSIG << "Copy assignment operator invoked" << FINAL << "\n\n";
	if (this != &other)
	{
		this->_fixedPointValue = other._fixedPointValue;
	}
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << DEST << "Destructor invoked" << FINAL << "\n\n";
}

int Fixed::getRawBits(void) const
{
	std::cout << START << "getRawBits member function invoked" << FINAL << "\n";
	return (this->_fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}
