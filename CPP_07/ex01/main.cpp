/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 16:27:11 by skarayil          #+#    #+#             */
/*   Updated: 2026/10/10 16:27:57 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

#define RESET   "\033[0m"
#define B       "\033[1;97;40m"
#define O       "\033[38;5;208m"
#define G       "\033[3;90m"    
#define W       "\033[1;97m"   

template <typename T>
void printElem(T const& x) {
    std::cout << W << x << RESET << " ";
}

template <typename T>
void doubleIt(T& x) {
    x = x * 2;
}

int main(void)
{
    int arr[] = {1, 2, 3, 4, 5};

    std::cout << G "int array: " RESET;
    iter(arr, 5, printElem<int>);
    std::cout << std::endl;

    iter(arr, 5, doubleIt<int>);

    std::cout << O "doubled:   " RESET;
    iter(arr, 5, printElem<int>);
    std::cout << std::endl;

    std::string strs[] = {"hello", "world", "42"};

    std::cout << O "strings:   " RESET;
    iter(strs, 3, printElem<std::string>);
    std::cout << std::endl;

    const double darr[] = {1.1, 2.2, 3.3};

    std::cout << O "const dbl: " RESET;
    iter(darr, 3, printElem<double>);
    std::cout << std::endl;

    return (0);
}
