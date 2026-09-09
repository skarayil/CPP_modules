/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 14:20:20 by skarayil          #+#    #+#             */
/*   Updated: 2026/09/09 14:24:26 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(void) 
    : _type("unknown"), 
      _element("unknown"), 
      _colorCode(ITALIC)
{
    std::cout << CONST << "A raw materia forms from the void" << FINAL << "\n\n";
}

AMateria::AMateria(std::string const & type, std::string const & element, std::string const & colorCode)
    : _type(type),
      _element(element), 
      _colorCode(colorCode)
{
    std::cout << CONST << "A " << _type << " materia crystallizes from " 
              << _element << " energy" << FINAL << "\n\n";
}

AMateria::AMateria(const AMateria& other)
    : _type(other._type),
      _element(other._element),
      _colorCode(other._colorCode)
{
    std::cout << COPY << "The essence of " << _type << " is duplicated"
              << FINAL << "\n\n";
}

AMateria& AMateria::operator=(const AMateria& other)
{
    std::cout << ASSIG << "One materia essence merges with another" << FINAL << "\n\n";
    if (this != &other)
    {
        _type = other._type;
        _element = other._element;
        _colorCode = other._colorCode;
    }
    return (*this);
}

AMateria::~AMateria()
{
    std::cout << DEST << "The " << _type << " materia dissolves into pure energy"
              << FINAL << "\n\n";
}

std::string const & AMateria::getType() const { return (_type); }
std::string const & AMateria::getElement() const { return (_element); }
std::string const & AMateria::getColorCode() const { return (_colorCode); }

void AMateria::use(ICharacter& target)
{
    (void)target;
    std::cout << _colorCode << "* unknown energy surges *" << FINAL << "\n\n";
}
