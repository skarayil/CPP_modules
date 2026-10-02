/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 15:36:35 by skarayil          #+#    #+#             */
/*   Updated: 2026/10/02 22:32:02 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define CYAN    "\033[1;36m"

int	main(void)
{
	std::cout << CYAN << "===== ex01: Form + signForm =====" << RESET << std::endl << std::endl;

	std::cout << YELLOW << "[Test 1] Valid Form" << RESET << std::endl;
	try
	{
		Form f("TaxForm", 50, 30);
		std::cout << GREEN << "  OK  " << RESET << f << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "  ERR " << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;

	std::cout << YELLOW << "[Test 2] Form signGrade too high (0)" << RESET << std::endl;
	try
	{
		Form f("BadForm", 0, 30);
		std::cout << GREEN << "  OK  " << RESET << f << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "  ERR " << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;

	std::cout << YELLOW << "[Test 3] Form execGrade too low (200)" << RESET << std::endl;
	try
	{
		Form f("BadForm", 50, 200);
		std::cout << GREEN << "  OK  " << RESET << f << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "  ERR " << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;

	std::cout << YELLOW << "[Test 4] Successful signing" << RESET << std::endl;
	try
	{
		Bureaucrat alice("Alice", 10);
		Form tax("TaxForm", 50, 30);
		std::cout << BLUE << "  Bureaucrat " << RESET << alice << std::endl;
		std::cout << BLUE << "  Before     " << RESET << tax << std::endl;
		alice.signForm(tax);
		std::cout << BLUE << "  After      " << RESET << tax << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "  ERR " << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;

	std::cout << YELLOW << "[Test 5] Failed signing (grade too low)" << RESET << std::endl;
	try
	{
		Bureaucrat bob("Bob", 100);
		Form top("TopSecret", 5, 5);
		std::cout << BLUE << "  Bureaucrat " << RESET << bob << std::endl;
		std::cout << BLUE << "  Before     " << RESET << top << std::endl;
		bob.signForm(top);
		std::cout << BLUE << "  After      " << RESET << top << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "  ERR " << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;

	std::cout << YELLOW << "[Test 6] Boundary signing (grade == signGrade)" << RESET << std::endl;
	try
	{
		Bureaucrat exact("Exact", 42);
		Form f("AnswerForm", 42, 42);
		exact.signForm(f);
		std::cout << BLUE << "  After " << RESET << f << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "  ERR " << e.what() << RESET << std::endl;
	}

	return (0);
}
