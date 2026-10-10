/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 16:29:55 by skarayil          #+#    #+#             */
/*   Updated: 2026/10/10 21:17:05 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <string>

#define R       "\033[0m"
#define B       "\033[1;97;40m" 
#define O       "\033[38;5;208m"
#define G       "\033[3;90m"
#define W       "\033[1;97m"

int main(void)
{
    Array<int> empty;
    std::cout << G "empty size: " R << W << empty.size() << R << std::endl;

    Array<int> arr(5);
    for (unsigned int i = 0; i < arr.size(); ++i)
        arr[i] = static_cast<int>(i * 10);

    std::cout << O "arr: " R;
    for (unsigned int i = 0; i < arr.size(); ++i)
        std::cout << W << arr[i] << R << " ";
    std::cout << std::endl;

    Array<int> copy = arr;
    copy[0] = 999;

    std::cout << B " arr[0] " R " after copy[0]=999: "
              << W << arr[0] << R << std::endl;

    std::cout << B " copy[0] " R " after copy[0]=999: "
              << W << copy[0] << R << std::endl;

    Array<std::string> strs(3);
    strs[0] = "hello";
    strs[1] = "world";
    strs[2] = "42";

    std::cout << O "strs: " R
              << W << strs[0] << R << " "
              << W << strs[1] << R << " "
              << W << strs[2] << R << std::endl;

    try {
        std::cout << arr[100] << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << O "Exception: " R
                  << W << e.what() << R << std::endl;
    }
    
    return (0);
}