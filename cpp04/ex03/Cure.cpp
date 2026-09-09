/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 14:28:28 by skarayil          #+#    #+#             */
/*   Updated: 2026/09/09 14:31:14 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure(void) 
    : AMateria("cure", "golden", CURE)
{
    std::cout << CURE << "Cure materia glows with healing light" << FINAL << "\n\n";
}

Cure::Cure(const Cure& other)
    : AMateria(other)
{
    std::cout << CURE << "Cure materia is copied" << FINAL << "\n\n";
}

Cure& Cure::operator=(const Cure& other)
{
    std::cout << CURE << "Cure materia is assigned" << FINAL << "\n\n";
    if (this != &other)
    {
        AMateria::operator=(other);
    }
    return (*this);
}

Cure::~Cure()
{
    std::cout << CURE << "Cure materia fades into warmth" << FINAL << "\n\n";
}

AMateria* Cure::clone() const
{
    return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
    std::cout << CURE << "* heals " << target.getName() << "'s wounds *" << FINAL << "\n\n";
}
