/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 14:25:03 by skarayil          #+#    #+#             */
/*   Updated: 2026/09/09 14:27:04 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice(void) 
    : AMateria("ice", "mercurial", ICE)
{
    std::cout << ICE << "Ice materia shimmers with frost" << FINAL << "\n\n";
}

Ice::Ice(const Ice& other) 
    : AMateria(other)
{
    std::cout << ICE << "Ice materia is copied" << FINAL << "\n\n";
}

Ice& Ice::operator=(const Ice& other)
{
    std::cout << ICE << "Ice materia is assigned" << FINAL << "\n\n";
    if (this != &other)
    {
        AMateria::operator=(other);
    }
    return (*this);
}

Ice::~Ice()
{
    std::cout << ICE << "Ice materia melts into water" << FINAL << "\n\n";
}

AMateria* Ice::clone() const
{
    return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
    std::cout << ICE << "* shoots an ice bolt at " << target.getName() << " *" << FINAL << "\n\n";
}