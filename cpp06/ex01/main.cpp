/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 20:22:31 by skarayil          #+#    #+#             */
/*   Updated: 2026/10/09 08:53:36 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int	main(void)
{
	Data		d;
	uintptr_t	raw;
	Data		*restoK;

	d.id = 42;
	d.name = "TestData";
	d.value = 3.14;
	std::cout << O << M << "========== SERIALIZER TEST ==========" << R << std::endl;
	std::cout << std::endl;
	std::cout << O << C << "[ ORIGINAL ]" << R << std::endl;
	std::cout << B << "  pointer : " << R << I << &d << R << std::endl;
	std::cout << B << "  id      : " << R << S << d.id << R << std::endl;
	std::cout << B << "  name    : " << R << S << d.name << R << std::endl;
	std::cout << B << "  value   : " << R << S << d.value << R << std::endl;
	raw = Serializer::serialize(&d);
	std::cout << std::endl;
	std::cout << O << C << "[ SERIALIZE ]" << R << std::endl;
	std::cout << B << "  raw (uintptr_t) : " << R << I << raw << R << std::endl;
	restoK = Serializer::deserialize(raw);
	std::cout << std::endl;
	std::cout << O << C << "[ DESERIALIZE ]" << R << std::endl;
	std::cout << B << "  pointer : " << R << I << restoK << R << std::endl;
	std::cout << B << "  id      : " << R << S << restoK->id << R << std::endl;
	std::cout << B << "  name    : " << R << S << restoK->name << R << std::endl;
	std::cout << B << "  value   : " << R << S << restoK->value << R << std::endl;
	std::cout << std::endl;
	if (restoK == &d)
		std::cout << O << S << "SUCCESS: pointers match." << R << std::endl;
	else
		std::cout << O << K << "FAIL: pointers differ." << R << std::endl;
	std::cout << std::endl;
	std::cout << O << M << "=====================================" << R << std::endl;
	return (0);
}
