/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 19:09:34 by skarayil          #+#    #+#             */
/*   Updated: 2026/09/07 12:41:57 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
    : WrongAnimal("WrongCat")
{
    std::cout << CONST << "A strange cat enters the wilderness."
              << FINAL << "\n\n";
}

WrongCat::WrongCat(const WrongCat& other)
    : WrongAnimal(other)
{
    std::cout << COPY << "A second strange cat appears."
              << FINAL << "\n\n";
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    std::cout << ASSIG << "The strange cat takes another's form."
              << FINAL << "\n\n";

    if (this != &other)
    {
        WrongAnimal::operator=(other);
    }
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << DEST << "The strange cat leaves the wilderness."
              << FINAL << "\n\n";
}

void WrongCat::makeSound() const
{
    std::cout << WRONG << "WrongCat says: HISS HISS!"
              << FINAL << "\n\n";
}
