/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 14:38:24 by skarayil          #+#    #+#             */
/*   Updated: 2026/09/07 15:18:32 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	ideas[0] = "Survive";
	ideas[1] = "Explore";
	ideas[2] = "Rest";
	std::cout << CONST << "A brain is formed, filled with thoughts and dreams." 
	          << FINAL << "\n\n";
}

Brain::Brain(const Brain &other)
{
	for (int i = 0; i < 100; ++i)
		ideas[i] = other.ideas[i];
	std::cout << COPY << "A second brain is born, mirroring every thought of the first." 
	          << FINAL << "\n\n";
}

Brain &Brain::operator=(const Brain &other)
{
	std::cout << ASSIG << "One mind adopts the ideas of another." 
	          << FINAL << "\n\n";
	if (this != &other)
	{
		for (int i = 0; i < 100; ++i)
			ideas[i] = other.ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << DEST << "The brain fades away, thoughts dissolving into silence." 
	          << FINAL << "\n\n";
}

std::string Brain::getIdea(int index) const
{
	if (index < 0 || index >= 100)
		return ("");
	return (ideas[index]);
}

void Brain::setIdea(int index, const std::string &idea)
{
	if (index < 0 || index >= 100)
		return ;
	ideas[index] = idea;
}
