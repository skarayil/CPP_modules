/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 16:23:26 by skarayil          #+#    #+#             */
/*   Updated: 2026/10/10 16:25:36 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>
#include <string>

#define R   "\033[0m"
#define B       "\033[30;107m"
#define O       "\033[38;5;208m"
#define G       "\033[3;90m"    
#define W       "\033[1;97m"

int main(void)
{
    int a = 2;
    int b = 3;
    ::swap(a, b);

    std::cout << B "a" R " = " W << a << R
              << "  " B "b" R " = " W << b << R << std::endl;

    std::cout << O "min" R "( " B "a" R ", " B "b" R " ) = "
              << W << ::min(a, b) << R << std::endl;

    std::cout << O "max" R "( " B "a" R ", " B "b" R " ) = "
              << W << ::max(a, b) << R << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);

    std::cout << B "c" R " = " W << c << R
              << "  " B "d" R " = " W << d << R << std::endl;

    std::cout << O "min" R "( " B "c" R ", " B "d" R " ) = "
              << W << ::min(c, d) << R << std::endl;

    std::cout << O "max" R "( " B "c" R ", " B "d" R " ) = "
              << W << ::max(c, d) << R << std::endl;

    return 0;
}