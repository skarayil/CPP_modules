/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 19:12:53 by skarayil          #+#    #+#             */
/*   Updated: 2026/08/02 14:56:28 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#define INFO "\033[3;30;100m"
#define START "\033[3;30;106m"
#define BOLD "\033[1;37m"
#define FINAL "\033[0m"

int	main(void)
{
	std::string brain = "HI THIS IS BRAIN";
	std::string *stringPTR = &brain;
	std::string &stringREF = brain;

	std::cout << START << "══════ Memory Addresses ══════" << FINAL << "\n\n";
	std::cout << INFO << "[INFO]" << FINAL << " brain    address : " << BOLD << &brain << FINAL << "\n\n";
	std::cout << INFO << "[INFO]" << FINAL << " stringPTR        : " << BOLD << stringPTR << FINAL << "\n\n";
	std::cout << INFO << "[INFO]" << FINAL << " stringREF address: " << BOLD << &stringREF << FINAL << "\n\n";
	std::cout << START << "══════ Values ══════" << FINAL << "\n\n";
	std::cout << INFO << "[INFO]" << FINAL << " brain    value : " << BOLD << brain << FINAL << "\n\n";
	std::cout << INFO << "[INFO]" << FINAL << " *stringPTR     : " << BOLD << *stringPTR << FINAL << "\n\n";
	std::cout << INFO << "[INFO]" << FINAL << " stringREF value: " << BOLD << stringREF << FINAL << "\n\n";

	return (0);
}