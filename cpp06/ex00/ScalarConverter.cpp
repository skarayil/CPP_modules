/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 20:22:31 by skarayil          #+#    #+#             */
/*   Updated: 2026/10/09 08:52:32 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <sstream>

static bool	isChar(const std::string &s)
{
	return (s.length() == 3 && s[0] == '\'' && s[2] == '\'');
}

static bool	isPseudoFloat(const std::string &s)
{
	return (s == "-inff" || s == "+inff" || s == "nanf");
}

static bool	isPseudoDouble(const std::string &s)
{
	return (s == "-inf" || s == "+inf" || s == "nan");
}

static bool	isInt(const std::string &s)
{
	size_t	start;

	if (s.empty())
		return (false);
	start = (s[0] == '-' || s[0] == '+') ? 1 : 0;
	for (size_t i = start; i < s.length(); ++i)
	{
		if (!std::isdigit(s[i]))
			return (false);
	}
	return (s.length() > start);
}

static bool	isFloat(const std::string &s)
{
	bool	hasDot;
	size_t	start;

	if (s.empty() || s[s.length() - 1] != 'f')
		return (false);
	std::string inner = s.substr(0, s.length() - 1);
	hasDot = false;
	start = (inner[0] == '-' || inner[0] == '+') ? 1 : 0;
	for (size_t i = start; i < inner.length(); ++i)
	{
		if (inner[i] == '.')
		{
			if (hasDot)
				return (false);
			hasDot = true;
		}
		else if (!std::isdigit(inner[i]))
		{
			return (false);
		}
	}
	return (hasDot && inner.length() > start);
}

static bool	isDouble(const std::string &s)
{
	bool	hasDot;
	size_t	start;

	hasDot = false;
	start = (s[0] == '-' || s[0] == '+') ? 1 : 0;
	for (size_t i = start; i < s.length(); ++i)
	{
		if (s[i] == '.')
		{
			if (hasDot)
				return (false);
			hasDot = true;
		}
		else if (!std::isdigit(s[i]))
		{
			return (false);
		}
	}
	return (hasDot && s.length() > start);
}

static std::string formatNumber(double value)
{
	std::ostringstream oss;
	oss << value;
	std::string s = oss.str();
	if (s.find('.') == std::string::npos)
		s += ".0";
	return (s);
}

static void	printChar(double value, bool impossible)
{
	std::cout << C << "char: " << R;
	if (impossible || value < 0 || value > 127 || std::isnan(value)
		|| std::isinf(value))
	{
		std::cout << K << "impossible" << R << std::endl;
	}
	else if (!std::isprint(static_cast<int>(value)))
	{
		std::cout << I << "Non displayable" << R << std::endl;
	}
	else
	{
		std::cout << S << "'" << static_cast<char>(value) << "'" << R << std::endl;
	}
}

static void	printInt(double value, bool impossible)
{
	std::cout << C << "int: " << R;
	if (impossible || std::isnan(value) || std::isinf(value)
		|| value > std::numeric_limits<int>::max()
		|| value < std::numeric_limits<int>::min())
	{
		std::cout << K << "impossible" << R << std::endl;
	}
	else
	{
		std::cout << S << static_cast<int>(value) << R << std::endl;
	}
}

static void	printFloat(double value, bool impossible)
{
	float	f;

	std::cout << C << "float: " << R;
	if (impossible)
	{
		std::cout << K << "impossible" << R << std::endl;
		return ;
	}
	f = static_cast<float>(value);
	if (std::isinf(f) || std::isnan(f))
	{
		std::cout << M << f << "f" << R << std::endl;
		return ;
	}
	std::cout << S << formatNumber(f) << "f" << R << std::endl;
}

static void	printDouble(double value, bool impossible)
{
	std::cout << C << "double: " << R;
	if (impossible)
	{
		std::cout << K << "impossible" << R << std::endl;
		return ;
	}
	if (std::isinf(value) || std::isnan(value))
	{
		std::cout << M << value << R << std::endl;
		return ;
	}
	std::cout << S << formatNumber(value) << R << std::endl;
}

static void	printResults(double value, bool impossible)
{
	printChar(value, impossible);
	printInt(value, impossible);
	printFloat(value, impossible);
	printDouble(value, impossible);
}

void ScalarConverter::convert(const std::string &literal)
{
	double	value;
	bool	impossible;
	char	*end;
	long	lv;

	value = 0.0;
	impossible = false;
	if (isChar(literal))
	{
		value = static_cast<double>(literal[1]);
	}
	else if (isPseudoFloat(literal) || isPseudoDouble(literal))
	{
		std::string base = (literal[literal.length()
				- 1] == 'f') ? literal.substr(0, literal.length()
				- 1) : literal;
		if (base == "nan" || base == "nanf")
			value = std::numeric_limits<double>::quiet_NaN();
		else if (base == "+inf" || base == "+inff")
			value = std::numeric_limits<double>::infinity();
		else
			value = -std::numeric_limits<double>::infinity();
	}
	else if (isInt(literal))
	{
		errno = 0;
		lv = std::strtol(literal.c_str(), &end, 10);
		if (errno != 0)
			impossible = true;
		else
			value = static_cast<double>(lv);
	}
	else if (isFloat(literal))
	{
		value = static_cast<double>(std::atof(literal.c_str()));
	}
	else if (isDouble(literal))
	{
		value = std::atof(literal.c_str());
	}
	else
	{
		impossible = true;
	}
	printResults(value, impossible);
}
