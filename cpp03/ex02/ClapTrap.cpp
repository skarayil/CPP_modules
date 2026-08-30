/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 15:36:13 by skarayil          #+#    #+#             */
/*   Updated: 2026/08/30 17:23:08 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("unnamed"), 
    _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << CONST << "ClapTrap " << _name 
              << " spawned into the arena!" 
              << FINAL << "\n\n";
}

ClapTrap::ClapTrap(const std::string &name) : _name(name), 
    _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << CONST << "ClapTrap " << _name 
              << " spawned into the arena!" 
              << FINAL << "\n\n";
}

ClapTrap::ClapTrap(const ClapTrap& other) : _name(other._name), 
    _hitPoints(other._hitPoints), _energyPoints(other._energyPoints),
    _attackDamage(other._attackDamage)
{
    std::cout << COPY << "ClapTrap " << _name 
              << " tactical clone deployed!" 
              << FINAL << "\n\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << ASSIG << "ClapTrap " << _name 
              << " loadout copied from " 
              << other._name 
              << FINAL << "\n\n";
    if (this != &other)
    {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << DEST << "ClapTrap " << _name
              << " has been eliminated!" 
              << FINAL << "\n\n";
}

void ClapTrap::attack(const std::string& target)
{
    if (_hitPoints == 0)
    {
        std::cout << ATTACK << "ClapTrap " << _name
                  << " is down, can't attack! Needs a medkit!"
                  << FINAL << "\n\n";
        return ;
    }
    if (_energyPoints == 0)
    {
        std::cout << ATTACK << "ClapTrap " << _name
                  << " is out of ammo, can't attack!" 
                  << FINAL << "\n\n";
        return ;
    }
    _energyPoints -= 1;
    std::cout << ATTACK << "ClapTrap " << _name 
              << " shoots " << target << " for " 
              << _attackDamage << " damage! Headshot!" 
              << FINAL << "\n\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints <= amount)
    {
        _hitPoints = 0;
        std::cout << DAMAGE << "ClapTrap " << _name 
                  << " got hit for " << amount 
                  << " HP! Eliminated!" 
                  << FINAL << "\n\n";
    }
    else
    {
        _hitPoints -= amount;
        std::cout << DAMAGE << "ClapTrap " << _name 
                  << " got hit for " << amount 
                  << " HP! Health remaining: " 
                  << _hitPoints << FINAL << "\n\n";
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_hitPoints == 0)
    {
        std::cout << REPAIR << "ClapTrap " << _name
                  << " is down, can't use medkit!"
                  << FINAL << "\n\n";
        return ;
    }
    if (_energyPoints == 0)
    {
        std::cout << REPAIR << "ClapTrap " << _name 
                  << " is out of supplies, can't heal!" 
                  << FINAL << "\n\n";
        return;
    }
    _energyPoints -= 1;
    _hitPoints += amount;
    std::cout << REPAIR << "ClapTrap " << _name 
              << " uses a medkit, +" 
              << amount << " HP! Total: " 
              << _hitPoints << FINAL << "\n\n";
}
