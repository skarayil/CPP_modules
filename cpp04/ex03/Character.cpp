/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 14:32:34 by skarayil          #+#    #+#             */
/*   Updated: 2026/09/09 14:38:25 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void)
    : _name("unnamed")
{
    for (int i = 0; i < 4; ++i)
        _inventory[i] = 0;
    std::cout << CONST << "A nameless alchemist steps forward" << FINAL << "\n\n";
}

Character::Character(std::string const & name)
    : _name(name)
{
    for (int i = 0; i < 4; ++i)
        _inventory[i] = 0;
    std::cout << CONST << "The alchemist " << _name << " enters the circle" << FINAL << "\n\n";
}

Character::Character(const Character& other)
    : _name(other._name)
{
    for (int i = 0; i < 4; ++i)
    {
        if (other._inventory[i])
            _inventory[i] = other._inventory[i]->clone();
        else
            _inventory[i] = 0;
    }
    std::cout << COPY << "The essence of " << _name << " is duplicated" << FINAL << "\n\n";
}

Character& Character::operator=(const Character& other)
{
    std::cout << ASSIG << "The alchemist " << _name << " merges with "
              << other._name << FINAL << "\n\n";
    if (this != &other)
    {
        _name = other._name;
        for (int i = 0; i < 4; ++i)
        {
            delete _inventory[i];
            if (other._inventory[i])
                _inventory[i] = other._inventory[i]->clone();
            else
                _inventory[i] = 0;
        }
    }
    return (*this);
}

Character::~Character()
{
    for (int i = 0; i < 4; ++i)
        delete _inventory[i];
    std::cout << DEST << "The alchemist " << _name << " fades into legend" << FINAL << "\n\n";
}

std::string const & Character::getName() const
{
    return (_name);
}

void Character::equip(AMateria* m)
{
    if (!m) return;
    for (int i = 0; i < 4; ++i)
    {
        if (!_inventory[i])
        {
            _inventory[i] = m;
            std::cout << ITALIC << _name << " binds " << m->getType()
                      << " to slot " << i << FINAL << "\n\n";
            return;
        }
    }
    std::cout << ITALIC << _name << "'s essence slots are full, materia not bound" << FINAL << "\n\n";
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4 || !_inventory[idx])
    {
        std::cout << ITALIC << "No energy resides at slot " << idx << FINAL << "\n\n";
        return;
    }
    std::cout << ITALIC << _name << " releases " << _inventory[idx]->getType()
              << " from slot " << idx << FINAL << "\n\n";
    _inventory[idx] = 0;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && _inventory[idx])
    {
        _inventory[idx]->use(target);
    }
    else
    {
        std::cout << ITALIC << "No energy to channel at slot " << idx << FINAL << "\n\n";
    }
}
