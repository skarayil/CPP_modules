/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 15:36:39 by skarayil          #+#    #+#             */
/*   Updated: 2026/10/02 16:14:51 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form() : _name("default"), _isSigned(false), _signGrade(150),
	_execGrade(150)
{
}

Form::Form(const std::string &name, int signGrade, int execGrade) : _name(name),
	_isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &other) : _name(other._name), _isSigned(other._isSigned),
	_signGrade(other._signGrade), _execGrade(other._execGrade)
{
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	return (*this);
}

Form::~Form()
{
}

const std::string &Form::getName() const
{
	return (_name);
}
bool Form::getIsSigned() const
{
	return (_isSigned);
}
int Form::getSignGrade() const
{
	return (_signGrade);
}
int Form::getExecGrade() const
{
	return (_execGrade);
}

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > _signGrade)
		throw GradeTooLowException();
	_isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Form grade is too high! (minimum is 1)");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Form grade is too low! (maximum is 150)");
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
	os << "Form \"" << f.getName() << "\" "
		<< "[sign: " << f.getSignGrade()
		<< ", exec: " << f.getExecGrade()
		<< ", signed: " << (f.getIsSigned() ? "yes" : "no") << "]";
	return (os);
}