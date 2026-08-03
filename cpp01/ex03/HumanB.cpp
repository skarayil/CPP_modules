/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 13:26:03 by skarayil          #+#    #+#             */
/*   Updated: 2026/08/02 15:01:34 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string &name) : _name(name), _weapon(NULL)
{
	std::cout << DEBUG << "[DEBUG]" << FINAL
              << " HumanB " << BOLD << _name 
              << FINAL << " created (unarmed)." 
              << "\n\n";
}

HumanB::~HumanB(void)
{
	std::cout << DEBUG << "[DEBUG]" << FINAL 
              << " HumanB " << BOLD << _name 
              << FINAL << " destroyed." 
              << "\n\n";
}

void HumanB::setWeapon(Weapon &weapon)
{
	std::cout << INFO << "[INFO]" << FINAL 
              << " HumanB " << BOLD << _name 
              << FINAL << " armed with " 
              << ITAL << weapon.getType() 
              << FINAL << "\n\n";
	_weapon = &weapon;
}

void HumanB::attack(void) const
{
	if (_weapon == NULL)
	{
		std::cout << WARNING << "[WARNING]" << FINAL << " " << BOLD << _name << FINAL << " has no weapon to attack with!" << "\n\n";
		return ;
	}
	std::cout << BOLD << _name << FINAL 
              << " attacks with their " 
              << ITAL << _weapon->getType() 
              << FINAL << "\n\n";
}
