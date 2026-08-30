/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 13:44:24 by skarayil          #+#    #+#             */
/*   Updated: 2026/08/30 21:25:51 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) 
	: _fixedPointValue(0)
{
	std::cout << CONST << "Default constructor invoked" << FINAL << "\n\n";
}

Fixed::Fixed(const int value)
	: _fixedPointValue(value << _fractionalBits)
{
	std::cout << VALUE << "Integer" << CONST << " constructor invoked" << FINAL << "\n\n";
}

Fixed::Fixed(const float value)
	: _fixedPointValue(roundf(value * (1 << _fractionalBits)))
{
	std::cout << VALUE << "Float" << CONST << " constructor invoked" << FINAL << "\n\n";
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
	std::cout << START << "getRawBits member function invoked" << FINAL << std::endl;
	return (this->_fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}

float Fixed::toFloat(void) const
{
	float result = static_cast<float>(_fixedPointValue);

	result /= (1 << _fractionalBits);

	return (result);
}

int Fixed::toInt(void) const
{
	return (this->_fixedPointValue >> _fractionalBits);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}