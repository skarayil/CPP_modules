/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 15:47:45 by skarayil          #+#    #+#             */
/*   Updated: 2026/10/02 22:32:37 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define CYAN    "\033[1;36m"

int	main(void)
{
	std::srand(std::time(NULL));

	std::cout << CYAN << "===== ex02: Abstract AForm + 3 Forms =====" << RESET << std::endl << std::endl;

	Bureaucrat boss("Boss", 1);
	std::cout << BLUE << "Boss " << RESET << boss << std::endl << std::endl;

	std::cout << YELLOW << "[Test 1] ShrubberyCreationForm" << RESET << std::endl;
	{
		ShrubberyCreationForm s("home");
		boss.signForm(s);
		boss.executeForm(s);
	}
	std::cout << std::endl;

	std::cout << YELLOW << "[Test 2] RobotomyRequestForm (x3, 50/50)" << RESET << std::endl;
	{
		for (int i = 0; i < 3; ++i)
		{
			RobotomyRequestForm r("Bender");
			boss.signForm(r);
			boss.executeForm(r);
			std::cout << "  ---" << std::endl;
		}
	}
	std::cout << std::endl;

	std::cout << YELLOW << "[Test 3] PresidentialPardonForm" << RESET << std::endl;
	{
		PresidentialPardonForm p("Marvin");
		boss.signForm(p);
		boss.executeForm(p);
	}
	std::cout << std::endl;

	std::cout << YELLOW << "[Test 4] Execute without signing" << RESET << std::endl;
	{
		ShrubberyCreationForm s("garden");
		boss.executeForm(s);
	}
	std::cout << std::endl;

	std::cout << YELLOW << "[Test 5] Execute with too-low grade" << RESET << std::endl;
	{
		Bureaucrat intern("Intern", 130);
		PresidentialPardonForm p("Ford");
		std::cout << BLUE << "Intern " << RESET << intern << std::endl;
		intern.signForm(p);
		intern.executeForm(p);
	}
	std::cout << std::endl;

	std::cout << YELLOW << "[Test 6] Polymorphism via AForm*" << RESET << std::endl;
	{
		AForm *forms[3];
		forms[0] = new ShrubberyCreationForm("poly1");
		forms[1] = new RobotomyRequestForm("poly2");
		forms[2] = new PresidentialPardonForm("poly3");

		for (int i = 0; i < 3; ++i)
		{
			boss.signForm(*forms[i]);
			boss.executeForm(*forms[i]);
			delete forms[i];
			std::cout << "  ---" << std::endl;
		}
	}

	return (0);
}
