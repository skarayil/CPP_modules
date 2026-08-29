/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 20:43:46 by skarayil          #+#    #+#             */
/*   Updated: 2026/08/29 23:07:20 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static int orientation(const Point& first, const Point& second, const Point& target)
{
    Fixed value;

    value = (second.getX() - first.getX())
          * (target.getY() - first.getY())
          - (second.getY() - first.getY())
          * (target.getX() - first.getX());

    if (value > 0)
        return 1;
    if (value < 0)
        return -1;
    return 0;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    int ab = orientation(a, b, point);
    int bc = orientation(b, c, point);
    int ca = orientation(c, a, point);

    if (ab == 0 || bc == 0 || ca == 0)
        return false;

    return (ab == bc && bc == ca);
}