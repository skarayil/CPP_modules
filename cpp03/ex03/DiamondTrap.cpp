/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 17:20:56 by skarayil          #+#    #+#             */
/*   Updated: 2026/08/30 21:09:05 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
    : ClapTrap(),
      ScavTrap(),
      FragTrap(),
      _name("unnamed")
{
    ClapTrap::_name = _name + "_clap_name";
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 30;
    
    std::cout << CONST << "DiamondTrap " << _name
              << " materialized in the arena!"
              << FINAL << "\n\n";
}

DiamondTrap::DiamondTrap(const std::string &name)
    : ClapTrap(name + "_clap_name"),
      ScavTrap(name),
      FragTrap(name),
      _name(name)
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 30;

    std::cout << CONST << "DiamondTrap " << _name
              << " materialized in the arena!"
              << FINAL << "\n\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
    : ClapTrap(other),
      ScavTrap(other),
      FragTrap(other),
      _name(other._name)
{
    std::cout << COPY << "DiamondTrap " << _name
              << " tactical clone deployed!"
              << FINAL << "\n\n";
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    std::cout << ASSIG << "DiamondTrap " << _name 
              << " loadout copied from " 
              << other._name 
              << FINAL << "\n\n";
    if (this != &other)
    {
        ClapTrap::operator=(other);
        _name = other._name;
    }
    return (*this);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << DEST << "DiamondTrap " << _name 
              << " has been eliminated!" 
              << FINAL << "\n\n";
}

void DiamondTrap::whoAmI(void)
{
    std::cout << SPEC << "DiamondTrap " << _name 
              << " says: I am " << _name 
              << " (ClapTrap name: " << ClapTrap::_name << ")"
              << FINAL << "\n\n";
}