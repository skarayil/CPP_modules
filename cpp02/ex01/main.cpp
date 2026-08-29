/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 13:44:19 by skarayil          #+#    #+#             */
/*   Updated: 2026/08/29 16:44:40 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);

	a = Fixed(1234.4321f);

	std::cout << START << "a is " << a << FINAL << "\n\n";
	std::cout << START << "b is " << b << FINAL << "\n\n";
	std::cout << START << "c is " << c << FINAL << "\n\n";
	std::cout << START << "d is " << d << FINAL << "\n\n";

	std::cout << START << "a is " << a.toInt() << " as integer" << FINAL << "\n\n";
	std::cout << START << "b is " << b.toInt() << " as integer" << FINAL << "\n\n";
	std::cout << START << "c is " << c.toInt() << " as integer" << FINAL << "\n\n";
	std::cout << START << "d is " << d.toInt() << " as integer" << FINAL << "\n\n";

	return (0);
}