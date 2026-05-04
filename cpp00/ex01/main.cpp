/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 00:12:23 by skarayil          #+#    #+#             */
/*   Updated: 2026/05/03 00:13:08 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Colors.hpp"
#include "Utils.hpp"

int	main(void)
{
	PhoneBook       pb;
	std::string     cmd;
	Utils::printColored("\n═════════════════ PHONEBOOK ═════════════════", BOLD MAGENTA, true);
	for (;;)
	{
		Utils::printColored("\n▶ Enter command [ADD] [SEARCH] [EXIT]: ", BOLD MAGENTA);
		if (!std::getline(std::cin, cmd) || cmd == "EXIT")
		{
			Utils::printColored("\n═════════════ PHONEBOOK EXITED ══════════════", BOLD MAGENTA, true);
			if (std::cin.eof()) std::cout << std::endl;
			break ;
		}
		if (cmd == "ADD") pb.addContact();
		else if (cmd == "SEARCH") pb.searchContact();
		else Utils::printColored("\n▶ Invalid command. Please try again.", BOLD RED, true);
	}

	return (0);
}