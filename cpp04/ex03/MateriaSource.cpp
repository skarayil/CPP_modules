/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 14:40:30 by skarayil          #+#    #+#             */
/*   Updated: 2026/09/09 14:43:00 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
    for (int i = 0; i < 4; ++i)
        _templates[i] = 0;
    std::cout << CONST << "An alchemical source awakens" << FINAL << "\n\n";
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
    for (int i = 0; i < 4; ++i)
    {
        if (other._templates[i])
            _templates[i] = other._templates[i]->clone();
        else
            _templates[i] = 0;
    }
    std::cout << COPY << "The source's knowledge is duplicated" << FINAL << "\n\n";
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    std::cout << ASSIG << "One source merges with another" << FINAL << "\n\n";
    if (this != &other)
    {
        for (int i = 0; i < 4; ++i)
        {
            delete _templates[i];
            if (other._templates[i])
                _templates[i] = other._templates[i]->clone();
            else
                _templates[i] = 0;
        }
    }
    return (*this);
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; ++i)
        delete _templates[i];
    std::cout << DEST << "The alchemical source returns to silence" << FINAL << "\n\n";
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (!m) return;
    for (int i = 0; i < 4; ++i)
    {
        if (!_templates[i])
        {
            _templates[i] = m->clone();
            std::cout << ITALIC << "The source learns the essence of " << m->getType() << FINAL << "\n\n";
            return;
        }
    }
    std::cout << ITALIC << "The source cannot learn more essences" << FINAL << "\n\n";
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; ++i)
    {
        if (_templates[i] && _templates[i]->getType() == type)
            return _templates[i]->clone();
    }
    return (0);
}
