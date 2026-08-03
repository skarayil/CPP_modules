/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 13:25:20 by skarayil          #+#    #+#             */
/*   Updated: 2026/08/02 14:58:19 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(const std::string& type) : _type(type)
{
	std::cout << DEBUG << "[DEBUG]" << FINAL
	          << " Weapon " << BOLD << _type << FINAL
	          << " created." << "\n\n";
}

Weapon::~Weapon(void)
{
	std::cout << DEBUG << "[DEBUG]" << FINAL
	          << " Weapon " << BOLD << _type << FINAL
	          << " destroyed." << "\n\n";
}

const std::string&	Weapon::getType(void) const { return (_type); }

void	Weapon::setType(const std::string& type)
{
	std::cout << WARNING << "[WARNING]" << FINAL
	          << " Weapon type changed: "
	          << BOLD << _type << FINAL
	          << " -> "
	          << BOLD << type << FINAL << "\n\n";
	_type = type;
}
