/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 08:59:09 by skarayil          #+#    #+#             */
/*   Updated: 2026/08/02 14:49:05 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(void) : _name(""){ }

Zombie::~Zombie(void)
{
	std::cout << DEBUG << "[DEBUG]" << FINAL << " Zombie " << BOLD << _name << FINAL << " has been destroyed." << "\n";
}

void Zombie::announce(void) const
{
	std::cout << BOLD << _name << FINAL << ": BraiiiiiiinnnzzzZ..." << "\n";
}

void Zombie::setName(const std::string &name)
{
	_name = name;
}
