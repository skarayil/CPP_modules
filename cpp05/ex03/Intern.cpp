/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 15:49:17 by skarayil          #+#    #+#             */
/*   Updated: 2026/10/02 22:59:07 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &)
{
}

Intern &Intern::operator=(const Intern &)
{
	return (*this);
}

Intern::~Intern()
{
}

static AForm	*createShrubbery(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm	*createRobotomy(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

static AForm	*createPresidential(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(const std::string &formName,
	const std::string &target) const
{
	static const struct FormEntry
	{
		const char *name;
		AForm *(*creator)(const std::string &);
	} forms[] = {{"shrubbery creation", createShrubbery}, {"robotomy request",
		createRobotomy}, {"presidential pardon", createPresidential}};
	static const std::size_t count = sizeof(forms) / sizeof(forms[0]);

	for (std::size_t i = 0; i < count; ++i)
	{
		if (formName == forms[i].name)
		{
			std::cout << "\033[1;32mIntern creates " << formName << "\033[0m" << std::endl;
			return (forms[i].creator(target));
		}
	}

	std::cout << "\033[1;31mIntern: unknown form \"" << formName << "\"\033[0m" << std::endl;
	return (NULL);
}