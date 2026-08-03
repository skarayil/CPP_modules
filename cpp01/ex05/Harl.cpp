/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 22:38:56 by skarayil          #+#    #+#             */
/*   Updated: 2026/08/02 16:50:29 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

Harl::Harl(void){ }

Harl::~Harl(void){ }

void	Harl::debug(void)
{
	std::cout << DEBUG << "[ DEBUG ]" << FINAL << "\n\n";
	std::cout << "I love having extra bacon for my "
	             "7XL-double-cheese-triple-pickle-special-ketchup burger. "
	             "I really do!" << "\n\n";
}

void	Harl::info(void)
{
	std::cout << INFO << "[ INFO ]" << FINAL << "\n\n";
	std::cout << "I cannot believe adding extra bacon costs more money. "
	             "You didn't put enough bacon in my burger! "
	             "If you did, I wouldn't be asking for more!" << "\n\n";
}

void	Harl::warning(void)
{
	std::cout << WARNING << "[ WARNING ]" << FINAL << "\n\n";;
	std::cout << "I think I deserve to have some extra bacon for free. "
	             "I've been coming for years whereas you started working "
	             "here since last month." << "\n\n";
}

void	Harl::error(void)
{
	std::cout << ERROR << "[ ERROR ]" << FINAL << "\n\n";
	std::cout << "This is unacceptable! I want to speak to the manager now." << "\n\n";
}

void	Harl::complain(std::string level)
{
	const std::string	levels[4]  = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*actions[4])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*actions[i])();
			return ;
		}
	}
	std::cout << WARNING << "[ Unknown level: " << level << " ]" << FINAL << "\n\n";
}
