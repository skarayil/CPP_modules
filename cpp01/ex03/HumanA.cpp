/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 13:25:30 by skarayil          #+#    #+#             */
/*   Updated: 2026/08/02 14:59:53 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(const std::string &name, Weapon &weapon) : _name(name), _weapon(weapon)
{
	std::cout << DEBUG << "[DEBUG]" << FINAL
              << " HumanA " << BOLD << _name
              << FINAL << " created (always armed)."
              << "\n\n";
}

HumanA::~HumanA(void)
{
	std::cout << DEBUG << "[DEBUG]" << FINAL
              << " HumanA " << BOLD << _name
              << FINAL << " destroyed."
              << "\n\n";
}

void HumanA::attack(void) const
{
	std::cout << BOLD << _name << FINAL
              << " attacks with their "
              << ITAL << _weapon.getType()
              << FINAL << "\n\n";
}
