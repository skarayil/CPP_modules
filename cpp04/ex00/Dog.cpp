/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 18:03:28 by skarayil          #+#    #+#             */
/*   Updated: 2026/09/07 12:48:44 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
    : Animal("Dog")
{
    std::cout << CONST << "Dog enters the wilderness"
              << FINAL << "\n\n";
}

Dog::Dog(const Dog& other)
    : Animal(other)
{
    std::cout << COPY << "A second dog appears, mirroring the first"
              << FINAL << "\n\n";
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << ASSIG << "Dog takes the form of "
              << other.type
              << FINAL << "\n\n";

    if (this != &other)
    {
        Animal::operator=(other);
    }

    return (*this);
}

Dog::~Dog()
{
    std::cout << DEST << "Dog leaves the wilderness"
              << FINAL << "\n\n";
}

void Dog::makeSound() const
{
    std::cout << SOUND << "Dog says: WOOF WOOF!"
              << FINAL << "\n\n";
}
