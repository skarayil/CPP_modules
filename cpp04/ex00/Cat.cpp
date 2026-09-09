/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 16:42:21 by skarayil          #+#    #+#             */
/*   Updated: 2026/09/07 12:49:06 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
    : Animal("Cat")
{
    std::cout << CONST << "Cat enters the wilderness"
              << FINAL << "\n\n";
}

Cat::Cat(const Cat& other)
    : Animal(other)
{
    std::cout << COPY << "A second cat appears, mirroring the first"
              << FINAL << "\n\n";
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << ASSIG << "Cat takes the form of another cat"
              << FINAL << "\n\n";

    if (this != &other)
    {
        Animal::operator=(other);
    }

    return (*this);
}

Cat::~Cat()
{
    std::cout << DEST << "Cat leaves the wilderness"
              << FINAL << "\n\n";
}

void Cat::makeSound() const
{
    std::cout << SOUND << "Cat says: MEOW MEOW!"
              << FINAL << "\n\n";
}
