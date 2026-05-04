/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 15:47:19 by skarayil          #+#    #+#             */
/*   Updated: 2026/05/02 23:46:34 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

static char ftToupper(char c)
{
    if (c >= 'a' && c <= 'z') return (c - ('a' - 'A'));
    return (c);
}

static void printChar(char c)
{
    std::cout << ftToupper(c);
}

static void shoutArgument(const char *arg)
{
    for (const char *ptr = arg; *ptr != '\0'; ++ptr) { printChar(*ptr); }
}

static void defaultNoise(void)
{
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}

int main(int ac, char *av[])
{
    bool hasArguments = (ac > 1);

    if (hasArguments == false)
    {
        defaultNoise();
        return (0);
    }

    for (int i = 1; i < ac; ++i) { shoutArgument(*(av + i)); }

    std::cout << std::endl;
    
    return (0);
}