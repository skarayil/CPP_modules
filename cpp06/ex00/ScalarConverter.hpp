/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 20:22:33 by skarayil          #+#    #+#             */
/*   Updated: 2026/10/09 08:50:29 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>

# define R "\033[0m"
# define O "\033[1m"
# define D "\033[2m"
# define K "\033[38;5;68m"
# define S "\033[38;5;117m"
# define I "\033[38;5;81m"
# define B "\033[38;5;111m"
# define M "\033[38;5;147m"
# define C "\033[38;5;159m"

class ScalarConverter
{
  public:
	static void convert(const std::string &literal);

  private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &);
	ScalarConverter &operator=(const ScalarConverter &);
	~ScalarConverter();
};

#endif