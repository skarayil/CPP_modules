/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 00:16:39 by skarayil          #+#    #+#             */
/*   Updated: 2026/08/02 14:47:24 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(const std::string &name) : _name(name)
{
	std::cout << DEBUG << "[DEBUG]" << FINAL << " Zombie " << BOLD << _name << FINAL << " has been created." << "\n\n";
}

Zombie::~Zombie(void)
{
	std::cout << DEBUG << "[DEBUG]" << FINAL << " Zombie " << BOLD << _name << FINAL << " has been destroyed." << "\n\n";
}

void Zombie::announce(void) const
{
	std::cout << BOLD << _name << FINAL << ": " << ITAL << "BraiiiiiiinnnzzzZ..." << FINAL << "\n\n";
}
