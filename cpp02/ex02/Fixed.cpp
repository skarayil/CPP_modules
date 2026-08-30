/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 16:55:54 by skarayil          #+#    #+#             */
/*   Updated: 2026/08/30 21:26:19 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void)
	: _fixedPointValue(0)
{
}

Fixed::Fixed(const int value)
	: _fixedPointValue(value << _fractionalBits)
{
}

Fixed::Fixed(const float value) 
	: _fixedPointValue(roundf(value * (1 << _fractionalBits)))
{
}

Fixed::Fixed(const Fixed &other)
	: _fixedPointValue(other._fixedPointValue)
{
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
	{
		this->_fixedPointValue = other._fixedPointValue;
	}
	return (*this);
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits(void) const
{
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

bool Fixed::operator>(const Fixed &other) const
{
	return (_fixedPointValue > other._fixedPointValue);
}

bool Fixed::operator<(const Fixed &other) const
{
	return (_fixedPointValue < other._fixedPointValue);
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (_fixedPointValue >= other._fixedPointValue);
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (_fixedPointValue <= other._fixedPointValue);
}

bool Fixed::operator==(const Fixed &other) const
{
	return (_fixedPointValue == other._fixedPointValue);
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (_fixedPointValue != other._fixedPointValue);
}

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed result;

	result._fixedPointValue = this->_fixedPointValue + other._fixedPointValue;

	return (result);
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed result;

	result._fixedPointValue = this->_fixedPointValue - other._fixedPointValue;

	return (result);
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed result;
	long long temp;

	temp = static_cast<long long>(this->_fixedPointValue)
		* other._fixedPointValue;

	result._fixedPointValue = temp / (1 << _fractionalBits);

	return (result);
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed result;
	long long temp;

	temp = static_cast<long long>(this->_fixedPointValue)
		* (1 << _fractionalBits);

	result._fixedPointValue = temp / other._fixedPointValue;

	return (result);
}

Fixed &Fixed::operator++(void)
{
	++this->_fixedPointValue;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	++(*this);
	return (temp);
}

Fixed &Fixed::operator--(void)
{
	--this->_fixedPointValue;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	--(*this);
	return (temp);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return ((a < b) ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return ((a < b) ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return ((a > b) ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return ((a > b) ? a : b);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}