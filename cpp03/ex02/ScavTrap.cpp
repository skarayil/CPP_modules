/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 15:36:21 by skarayil          #+#    #+#             */
/*   Updated: 2026/08/30 21:19:47 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
    : ClapTrap()
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << CONST << "ScavTrap " << _name 
              << " has entered the arena!" 
              << FINAL << "\n\n";
}

ScavTrap::ScavTrap(const std::string& name)
    : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << CONST << "ScavTrap " << _name 
              << " has entered the arena!" 
              << FINAL << "\n\n";
}

ScavTrap::ScavTrap(const ScavTrap& other) 
    : ClapTrap(other)
{
    std::cout << COPY << "ScavTrap " << _name 
              << " tactical clone deployed!" 
              << FINAL << "\n\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    std::cout << ASSIG << "ScavTrap " << _name 
              << " loadout copied from " 
              << other._name 
              << FINAL << "\n\n";
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << DEST << "ScavTrap " << _name 
              << " has been eliminated!" 
              << FINAL << "\n\n";
}

void ScavTrap::attack(const std::string& target)
{
    if (_hitPoints == 0)
    {
        std::cout << ATTACK << "ScavTrap " << _name
                  << " is down, can't attack! Needs a medkit!"
                  << FINAL << "\n\n";
        return ;
    }
    if (_energyPoints == 0)
    {
        std::cout << ATTACK << "ScavTrap " << _name
                  << " is out of ammo, can't attack!" 
                  << FINAL << "\n\n";
        return ;
    }
    _energyPoints -= 1;
    std::cout << ATTACK << "ScavTrap " << _name 
              << " fires a shotgun at " << target << " for " 
              << _attackDamage << " damage! Boom!" 
              << FINAL << "\n\n";
}

void ScavTrap::guardGate(void) 
{
    std::cout << SPEC << "ScavTrap " << _name 
              << " is now in Gate keeper mode!" 
              << FINAL << "\n\n";
}
