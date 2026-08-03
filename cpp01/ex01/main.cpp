/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 08:59:14 by skarayil          #+#    #+#             */
/*   Updated: 2026/08/02 14:50:05 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int	main(void)
{
	int		N;
	Zombie	*horde;
	Zombie	*empty;

	std::cout << START << "══════ Creating a horde of 4 zombies ══════" << FINAL << "\n\n";
	N = 4;
	horde = zombieHorde(N, "Zed");
	for (int i = 0; i < N; i++) { horde[i].announce(); }
	std::cout << "\n" << INFO << "══════ clearing the horde with delete[] ══════" << FINAL << "\n\n";
	delete[] horde;
	std::cout << "\n" << INFO << "══════ Edge case: N=0 ══════" << FINAL << "\n\n";
	empty = zombieHorde(0, "Ghost");
	if (empty == NULL) std::cout << "Returned NULL for N=0. Safe." << "\n\n";
    
	return (0);
}
