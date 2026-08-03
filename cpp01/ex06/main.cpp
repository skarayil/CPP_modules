/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 22:40:56 by skarayil          #+#    #+#             */
/*   Updated: 2026/08/02 17:45:00 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << BOLD << "Usage: " << argv[0]
		          << " <DEBUG|INFO|WARNING|ERROR>" 
                  << FINAL << "\n\n";
		return (1);
	}
	Harl	harl;
	harl.complain(argv[1]);

	return (0);
}