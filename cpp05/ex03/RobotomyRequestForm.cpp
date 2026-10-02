/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 15:47:57 by skarayil          #+#    #+#             */
/*   Updated: 2026/10/02 17:15:37 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72,
	45), _target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm",
	72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other),
	_target(other._target)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
		_target = other._target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

const std::string &RobotomyRequestForm::getTarget() const
{
	return (_target);
}

void RobotomyRequestForm::executeAction() const
{
	std::cout << "\033[1;33m* BZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ *\033[0m" << std::endl;

	if (std::rand() % 2 == 0)
		std::cout << "\033[1;32m" << _target << " has been robotomized successfully.\033[0m" << std::endl;
	else
		std::cout << "\033[1;31m" << _target << " robotomy failed.\033[0m" << std::endl;
}