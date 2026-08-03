/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 00:40:27 by skarayil          #+#    #+#             */
/*   Updated: 2026/08/02 14:47:12 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int	main(void)
{
	Zombie	*heapZombie;

	std::cout << START << "══════ randomChump (stack) ══════" << FINAL << "\n\n";
	randomChump("Alice");
	std::cout << std::endl;
	std::cout << START << "══════ newZombie (heap) ══════" << FINAL << "\n\n";
	heapZombie = newZombie("Bob");
	heapZombie->announce();
	std::cout << std::endl;
	std::cout << INFO << "══════ destroying heap zombie with delete ══════" << FINAL << "\n\n";
	delete	heapZombie;
	
	return (0);
}
