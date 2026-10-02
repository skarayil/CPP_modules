/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 15:18:38 by skarayil          #+#    #+#             */
/*   Updated: 2026/10/02 22:31:29 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define CYAN    "\033[1;36m"

int	main(void)
{
	std::cout << CYAN << "===== ex00: Bureaucrat =====" << RESET << std::endl << std::endl;

	std::cout << YELLOW << "[Test 1] Valid construction" << RESET << std::endl;
	try
	{
		Bureaucrat a("Alice", 42);
		std::cout << GREEN << "  OK  " << RESET << a << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "  ERR " << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;

	std::cout << YELLOW << "[Test 2] Grade too high (0)" << RESET << std::endl;
	try
	{
		Bureaucrat b("Bob", 0);
		std::cout << GREEN << "  OK  " << RESET << b << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "  ERR " << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;

	std::cout << YELLOW << "[Test 3] Grade too low (151)" << RESET << std::endl;
	try
	{
		Bureaucrat c("Charlie", 151);
		std::cout << GREEN << "  OK  " << RESET << c << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "  ERR " << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;

	std::cout << YELLOW << "[Test 4] Increment (2 -> 1 -> overflow)" << RESET << std::endl;
	Bureaucrat d("Dave", 2);
	std::cout << BLUE << "  START " << RESET << d << std::endl;
	try
	{
		d.incrementGrade();
		std::cout << GREEN << "  OK    " << RESET << d << std::endl;
		d.incrementGrade();
		std::cout << GREEN << "  OK    " << RESET << d << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "  ERR   " << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;

	std::cout << YELLOW << "[Test 5] Decrement (149 -> 150 -> overflow)" << RESET << std::endl;
	Bureaucrat e("Eve", 149);
	std::cout << BLUE << "  START " << RESET << e << std::endl;
	try
	{
		e.decrementGrade();
		std::cout << GREEN << "  OK    " << RESET << e << std::endl;
		e.decrementGrade();
		std::cout << GREEN << "  OK    " << RESET << e << std::endl;
	}
	catch (std::exception &ex)
	{
		std::cout << RED << "  ERR   " << ex.what() << RESET << std::endl;
	}

	return (0);
}
