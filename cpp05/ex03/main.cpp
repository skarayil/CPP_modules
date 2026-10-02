/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 16:23:37 by skarayil          #+#    #+#             */
/*   Updated: 2026/10/02 22:33:10 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
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

	std::cout << CYAN << "===== ex03: Intern + makeForm =====" << RESET << std::endl << std::endl;

	Intern intern;
	Bureaucrat boss("Boss", 1);
	std::cout << BLUE << "Boss " << RESET << boss << std::endl << std::endl;

	std::cout << YELLOW << "[Test 1] Create valid forms" << RESET << std::endl;
	{
		AForm *f1 = intern.makeForm("shrubbery creation", "home");
		AForm *f2 = intern.makeForm("robotomy request", "Bender");
		AForm *f3 = intern.makeForm("presidential pardon", "Marvin");

		if (f1)
		{
			boss.signForm(*f1);
			boss.executeForm(*f1);
			delete f1;
		}
		if (f2)
		{
			boss.signForm(*f2);
			boss.executeForm(*f2);
			delete f2;
		}
		if (f3)
		{
			boss.signForm(*f3);
			boss.executeForm(*f3);
			delete f3;
		}
	}
	std::cout << std::endl;

	std::cout << YELLOW << "[Test 2] Unknown form name" << RESET << std::endl;
	{
		AForm *f = intern.makeForm("coffee making", "office");
		if (f == NULL)
			std::cout << GREEN << "  OK  Returned NULL as expected" << RESET << std::endl;
		else
		{
			std::cout << RED << "  ERR Should have returned NULL" << RESET << std::endl;
			delete f;
		}
	}
	std::cout << std::endl;

	std::cout << YELLOW << "[Test 3] Copy / assignment" << RESET << std::endl;
	{
		Intern i1;
		Intern i2(i1);
		Intern i3;
		i3 = i1;

		AForm *a = i1.makeForm("robotomy request", "R2D2");
		AForm *b = i2.makeForm("robotomy request", "C3PO");
		AForm *c = i3.makeForm("robotomy request", "BB8");

		if (a) delete a;
		if (b) delete b;
		if (c) delete c;
		std::cout << GREEN << "  OK  All created and deleted" << RESET << std::endl;
	}

	return (0);
}
