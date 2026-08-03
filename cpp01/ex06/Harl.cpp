/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 22:40:44 by skarayil          #+#    #+#             */
/*   Updated: 2026/08/02 17:49:37 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

Harl::Harl(void)
{
}

Harl::~Harl(void)
{
}

void	Harl::debug(void)
{
	std::cout << DEBUG << "[ DEBUG ]" << FINAL << "\n";
	std::cout << "I love having extra bacon for my "
	             "7XL-double-cheese-triple-pickle-special-ketchup burger. "
	             "I really do!" << "\n\n";
}

void	Harl::info(void)
{
	std::cout << INFO << "[ INFO ]" << FINAL << "\n";
	std::cout << "I cannot believe adding extra bacon costs more money. "
	             "You didn't put enough bacon in my burger! "
	             "If you did, I wouldn't be asking for more!"<< "\n\n";
}

void	Harl::warning(void)
{
	std::cout << WARNING << "[ WARNING ]" << FINAL << "\n";
	std::cout << "I think I deserve to have some extra bacon for free. "
	             "I've been coming for years whereas you started working "
	             "here since last month." << "\n\n";
}

void	Harl::error(void)
{
	std::cout << ERROR << "[ ERROR ]" << FINAL << "\n";
	std::cout << "This is unacceptable! I want to speak to the manager now."<< "\n\n";
}
void Harl::byIndex(int index)
{
    switch (index)
    {
        case 0:
            debug();
            std::cout << std::endl;
        case 1:
            info();
            std::cout << std::endl;
        case 2:
            warning();
            std::cout << std::endl;
        case 3:
            error();
            break;
        default:
            std::cout << WARNING << "[ Probably complaining about insignificant problems ]"
                      << FINAL << "\n\n";
    }
}

void Harl::complain(std::string level)
{
    const std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int index = -1;
    for (int i = 0; i < 4; ++i)
    {
        if (levels[i] == level)
        {
            index = i;
            break;
        }
    }
    byIndex(index);
}