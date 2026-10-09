/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 20:22:46 by skarayil          #+#    #+#             */
/*   Updated: 2026/10/09 08:53:53 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <cstdlib>
#include <ctime>

Base::~Base()
{
}

Base	*generate(void)
{
	static bool	seeded = false;
	int			r;

	if (!seeded)
	{
		std::srand(static_cast<unsigned int>(std::time(NULL)));
		seeded = true;
	}
	r = std::rand() % 3;
	if (r == 0)
		return (new A);
	if (r == 1)
		return (new B);
	return (new C);
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << O << S << "A" << R << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << O << I << "B" << R << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << O << M << "C" << R << std::endl;
	else
		std::cout << O << K << "unknown" << R << std::endl;
}

void	identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << O << S << "A" << R << std::endl;
		return ;
	}
	catch (...)
	{
	}
	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << O << I << "B" << R << std::endl;
		return ;
	}
	catch (...)
	{
	}
	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << O << M << "C" << R << std::endl;
		return ;
	}
	catch (...)
	{
	}
	std::cout << O << K << "unknown" << R << std::endl;
}
