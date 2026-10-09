/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 20:22:26 by skarayil          #+#    #+#             */
/*   Updated: 2026/10/09 08:50:35 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << O << K << "Usage: " << R << I << "./convert " << R << M << "<literal>" << R << std::endl;
		return (1);
	}
	std::cout << O << M << "========== SCALAR CONVERTER ==========" << R << std::endl;
	std::cout << B << "  input : " << R << I << "\"" << argv[1] << "\"" << R << std::endl;
	std::cout << O << M << "======================================" << R << std::endl;
	ScalarConverter::convert(argv[1]);
	std::cout << O << M << "======================================" << R << std::endl;
	return (0);
}
