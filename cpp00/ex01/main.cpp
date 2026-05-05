/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* main.cpp                                           :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2026/05/02 14:25:29 by skarayil          #+#    #+#             */
/* Updated: 2026/05/05 12:45:00 by skarayil         ###   ########.fr       */
/* */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Colors.hpp"
#include "Utils.hpp"
#include <iostream>

int	main(void)
{
	PhoneBook	pb;
	std::string	cmd;
	bool		isRunning = true;

	Utils::printColored("\n═════════════════ PHONEBOOK ═════════════════", BOLD MAGENTA, true);
	while (isRunning)
	{
		Utils::printColored("\n▶ Enter command [ADD] [SEARCH] [EXIT]: ", BOLD MAGENTA, false);
		if (!std::getline(std::cin, cmd))
		{
			std::cin.clear();
			Utils::printColored("\n\n═════════════ EOF EXIT ══════════════", BOLD RED, true);
			isRunning = false;
			continue ;
		}
		if (cmd == "EXIT")
		{
			Utils::printColored("\n═════════════ PHONEBOOK EXITED ══════════════", BOLD MAGENTA, true);
			isRunning = false;
		}
		else if (cmd == "ADD") 
			pb.addContact();
		else if (cmd == "SEARCH") 
			pb.searchContact();
		else if (!cmd.empty()) 
			Utils::printColored("\n▶ Invalid command. Please try again.", BOLD RED, true);
	}
	return (0);
}