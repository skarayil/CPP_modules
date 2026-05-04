/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 00:12:39 by skarayil          #+#    #+#             */
/*   Updated: 2026/05/03 00:12:41 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "Utils.hpp"
#include <iostream>

bool Utils::ftIsPrintable(char c) { return (c >= 32 && c <= 126); }

bool Utils::ftIsDigit(char c) { return (c >= '0' && c <= '9'); }

void Utils::printColored(const std::string &text, const std::string &color, bool addNewLine)
{
	std::cout << color << text << RESET;
	if (addNewLine) std::cout << std::endl;
}

std::string Utils::ftSubstr(const std::string &str, size_t start, size_t len)
{
	const char      *ptr = str.c_str();
	size_t      strLen =  str.length();
	std::string result = "";
	if (start >= strLen) return (result);
	for (size_t i = 0; i < len && (start + i) < strLen; ++i) { result += *(ptr + start + i); }
	return (result);
}

std::string Utils::ftItoa(int n)
{
	bool        isNeg = (n < 0);;
	std::string     res = "";
	unsigned int        un;
	char        c;
	if (isNeg) un = (unsigned int)(-(n + 1)) + 1;
	else un = (unsigned int)n;
	do
	{
		c = (un % 10) + '0';
		res = c + res;
		un /= 10;
	}
    while (un > 0);
	if (isNeg) res = "-" + res;
	return (res);
}
