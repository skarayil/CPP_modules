/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 15:33:56 by skarayil          #+#    #+#             */
/*   Updated: 2026/09/07 15:18:08 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
	: type("Animal")
{
	std::cout << CONST << "Animal enters the wilderness"
	          << FINAL << "\n\n";
}

Animal::Animal(const std::string &type)
	: type(type)
{
	std::cout << CONST << "Animal enters the wilderness with type: "
	          << type
	          << FINAL << "\n\n";
}

Animal::Animal(const Animal &other)
	: type(other.type)
{
	std::cout << COPY << "A second animal " << type
	          << " appears, mirroring the first"
	          << FINAL << "\n\n";
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << ASSIG << "Animal " << type
	          << " takes the form of "
	          << other.type
	          << FINAL << "\n\n";

	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}

Animal::~Animal()
{
	std::cout << DEST << "The animal " << type
	          << " leaves the wilderness"
	          << FINAL << "\n\n";
}

std::string Animal::getType() const
{
	return (type);
}
