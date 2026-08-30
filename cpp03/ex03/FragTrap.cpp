/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 17:02:09 by skarayil          #+#    #+#             */
/*   Updated: 2026/08/30 20:56:14 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
    : ClapTrap()
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << CONST << "FragTrap " << _name 
              << " jumps into the arena!" 
              << FINAL << "\n\n";
}

FragTrap::FragTrap(const std::string& name)
    : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << CONST << "FragTrap " << _name 
              << " jumps into the arena!" 
              << FINAL << "\n\n";
}

FragTrap::FragTrap(const FragTrap& other)
    : ClapTrap(other)
{
    std::cout << COPY << "FragTrap " << _name 
              << " tactical clone deployed!" 
              << FINAL << "\n\n";
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    std::cout << ASSIG << "FragTrap " << _name 
              << " loadout copied from " 
              << other._name 
              << FINAL << "\n\n";
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << DEST << "FragTrap " << _name 
              << " has been eliminated!" 
              << FINAL << "\n\n";
}

void FragTrap::attack(const std::string& target)
{
    if (_hitPoints == 0)
    {
        std::cout << ATTACK << "FragTrap " << _name
                  << " is down, can't attack! Needs a medkit!"
                  << FINAL << "\n\n";
        return ;
    }
    if (_energyPoints == 0)
    {
        std::cout << ATTACK << "FragTrap " << _name
                  << " is out of ammo, can't attack!" 
                  << FINAL << "\n\n";
        return ;
    }
    _energyPoints -= 1;
    std::cout << ATTACK << "FragTrap " << _name 
              << " hurls a grenade at " << target << " for " 
              << _attackDamage << " damage! Explosion!" 
              << FINAL << "\n\n";
}

void FragTrap::highFivesGuys(void)
{
    std::cout << SPEC << "FragTrap " << _name 
              << " requests a positive high-five, guys!" 
              << FINAL << "\n\n";
}
