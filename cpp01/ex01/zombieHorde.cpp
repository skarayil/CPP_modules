/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 08:59:06 by skarayil          #+#    #+#             */
/*   Updated: 2026/08/02 14:49:31 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*horde;

	if (N <= 0) return (NULL);
	horde = new Zombie[N];
	for (int i = 0; i < N; i++) { horde[i].setName(name); }
	return (horde);
}
