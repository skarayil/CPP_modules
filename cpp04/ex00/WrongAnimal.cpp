/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 18:19:26 by skarayil          #+#    #+#             */
/*   Updated: 2026/09/07 12:44:37 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
    : type("WrongAnimal")
{
    std::cout << CONST << "Something unnatural enters the wilderness."
              << FINAL << "\n\n";
}

WrongAnimal::WrongAnimal(const std::string& type)
    : type(type)
{
    std::cout << CONST << "An unnatural presence enters the wilderness."
              << FINAL << "\n\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
    : type(other.type)
{
    std::cout << COPY << "A second unnatural presence appears."
              << FINAL << "\n\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    std::cout << ASSIG << "The unnatural presence takes another's form."
              << FINAL << "\n\n";

    if (this != &other)
    {
        type = other.type;
    }
    return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << DEST << "The unnatural presence leaves the wilderness."
              << FINAL << "\n\n";
}

std::string WrongAnimal::getType() const
{
    return (type);
}

void WrongAnimal::makeSound() const
{
    std::cout << WRONG << "WrongAnimal makes a strange noise..."
              << FINAL << "\n\n";
}
