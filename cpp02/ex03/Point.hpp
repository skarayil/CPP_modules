/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 20:43:58 by skarayil          #+#    #+#             */
/*   Updated: 2026/08/29 22:40:20 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

# define TRUE "\033[1;4;92m"
# define FALSE "\033[1;4;91m"
# define VALUE "\033[1;3;97m"
# define FINAL "\033[0m"

class Point
{
  private:
	Fixed const _x;
	Fixed const _y;

  public:
	Point(void);
	Point(const float x, const float y);
	Point(const Point &other);
	Point &operator=(const Point &other);
	~Point(void);

	const Fixed &getX() const;
	const Fixed &getY() const;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif