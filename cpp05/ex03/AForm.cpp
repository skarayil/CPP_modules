/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 16:07:41 by skarayil          #+#    #+#             */
/*   Updated: 2026/10/03 00:14:28 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("default"), _isSigned(false), _signGrade(150),
	_execGrade(150)
{
}

AForm::AForm(const std::string &name, int signGrade,
	int execGrade) : _name(name), _isSigned(false), _signGrade(signGrade),
	_execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &other) : _name(other._name),
	_isSigned(other._isSigned), _signGrade(other._signGrade),
	_execGrade(other._execGrade)
{
}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	return (*this);
}

AForm::~AForm()
{
}

const std::string &AForm::getName() const
{
	return (_name);
}
bool AForm::getIsSigned() const
{
	return (_isSigned);
}
int AForm::getSignGrade() const
{
	return (_signGrade);
}
int AForm::getExecGrade() const
{
	return (_execGrade);
}

void AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > _signGrade)
		throw GradeTooLowException();
	_isSigned = true;
}

void AForm::execute(const Bureaucrat &executor) const
{
	if (!_isSigned)
		throw NotSignedException();
	if (executor.getGrade() > _execGrade)
		throw GradeTooLowException();
	executeAction();
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("grade is too high (minimum is 1)");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("grade is too low (maximum is 150)");
}

const char *AForm::NotSignedException::what() const throw()
{
	return ("form is not signed");
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
	os << "AForm \"" << f.getName() << "\" "
		<< "[sign: " << f.getSignGrade()
		<< ", exec: " << f.getExecGrade()
		<< ", signed: " << (f.getIsSigned() ? "yes" : "no") << "]";
	return (os);
}
