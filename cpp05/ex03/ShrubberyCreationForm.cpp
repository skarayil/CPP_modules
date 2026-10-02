/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 16:10:19 by skarayil          #+#    #+#             */
/*   Updated: 2026/10/02 17:15:15 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm",
	145, 137), _target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm",
	145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other),
	_target(other._target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
		_target = other._target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

const std::string &ShrubberyCreationForm::getTarget() const
{
	return (_target);
}

void ShrubberyCreationForm::executeAction() const
{
	std::ofstream out((_target + "_shrubbery").c_str());
	if (!out.is_open())
	{
		std::cerr << "\033[1;31mCould not open file: " << _target
			+ "_shrubbery" << "\033[0m" << std::endl;
		return ;
	}

	out << "       ###\n"
		<< "      #o###\n"
		<< "    #####o###\n"
		<< "   #o#\\#|#/###\n"
		<< "    ###\\|/#o#\n"
		<< "     # }|{  #\n"
		<< "       }|{\n";
	out.close();

	std::cout << "\033[1;32mShrubbery created at " << _target
		+ "_shrubbery" << "\033[0m" << std::endl;
}
