/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 20:43:52 by skarayil          #+#    #+#             */
/*   Updated: 2026/08/29 22:49:03 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main(void)
{
	bool	result;

	// Üçgen köşeleri
	Point a(0.0f, 0.0f);
	Point b(4.0f, 0.0f);
	Point c(0.0f, 4.0f);
	// Test noktaları
	Point inside(1.0f, 1.0f);  // İçeride
	Point outside(5.0f, 5.0f); // Dışarıda
	Point onEdge(2.0f, 0.0f);  // Kenar üzerinde
	Point vertex(0.0f, 0.0f);  // Köşe noktası
	// Inside test
	result = bsp(a, b, c, inside);
	std::cout << VALUE << "Inside (1,1): " << FINAL;
	std::cout << (result ? TRUE : FALSE) << (result ? "True" : "False") << FINAL << std::endl;
	// Outside test
	result = bsp(a, b, c, outside);
	std::cout << VALUE << "Outside (5,5): " << FINAL;
	std::cout << (result ? TRUE : FALSE) << (result ? "True" : "False") << FINAL << std::endl;
	// On edge test
	result = bsp(a, b, c, onEdge);
	std::cout << VALUE << "On edge (2,0): " << FINAL;
	std::cout << (result ? TRUE : FALSE) << (result ? "True" : "False") << FINAL << std::endl;
	// Vertex test
	result = bsp(a, b, c, vertex);
	std::cout << VALUE << "Vertex (0,0): " << FINAL;
	std::cout << (result ? TRUE : FALSE) << (result ? "True" : "False") << FINAL << std::endl;
	return (0);
}
