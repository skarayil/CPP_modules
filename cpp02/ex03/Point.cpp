/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 20:43:56 by skarayil          #+#    #+#             */
/*   Updated: 2026/08/30 21:27:13 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void)
	: _x(0),
	  _y(0)
{
}

Point::Point(const float x, const float y)
	: _x(x),
	  _y(y)
{
}

Point::Point(const Point &other) 
	: _x(other._x),
	  _y(other._y)
{
}

Point &Point::operator=(const Point &other)
{
	(void)other;
	return (*this);
}

Point::~Point()
{
}

const Fixed &Point::getX() const
{
	return (_x);
}
const Fixed &Point::getY() const
{
	return (_y);
}