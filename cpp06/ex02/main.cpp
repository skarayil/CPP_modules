/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 20:22:51 by skarayil          #+#    #+#             */
/*   Updated: 2026/10/09 08:55:43 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int	main(void)
{
	Base *obj = NULL;

	std::cout << O << M << "========= IDENTIFY TEST =========" << R << std::endl;
	for (int i = 0; i < 6; ++i)
	{
		std::cout << std::endl;
		std::cout << O << Y << "[ Test #" << (i + 1) << " ]" << R << std::endl;
		obj = generate();
		std::cout << X << "  pointer   : " << R;
		identify(obj);
		std::cout << X << "  reference : " << R;
		identify(*obj);
		delete obj;
		obj = NULL;
	}
	std::cout << std::endl;
	std::cout << O << M << "================================" << R << std::endl;
	return (0);
}
