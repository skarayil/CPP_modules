/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 15:31:55 by skarayil          #+#    #+#             */
/*   Updated: 2026/08/30 15:38:50 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    std::cout << START << "\n=== ARENA MATCH START ===\n" << FINAL << std::endl;

    ClapTrap soldier("CT-1");
    ClapTrap bandit("CT-2");

    std::cout << START << "\n=== BATTLE BEGINS ===\n" << FINAL << std::endl;

    soldier.attack("CT-2");
    bandit.takeDamage(3);

    bandit.attack("CT-1");
    soldier.takeDamage(0);

    soldier.beRepaired(2);
    bandit.beRepaired(1);

    std::cout << START << "\n=== FINAL STRIKE ===\n" << FINAL << std::endl;

    soldier.attack("CT-2");
    bandit.takeDamage(10);

    bandit.attack("CT-1");
    bandit.beRepaired(5);

    std::cout << START << "\n=== EXITING ARENA ===\n" << FINAL << std::endl;

    return (0);
}
