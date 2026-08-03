/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 17:35:50 by skarayil          #+#    #+#             */
/*   Updated: 2026/08/01 23:10:31 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0]
		          << " <filename> <s1> <s2>" << std::endl;
		return (1);
	}

	return (Replacer::run(argv[1], argv[2], argv[3]));
}