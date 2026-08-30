/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 15:36:17 by skarayil          #+#    #+#             */
/*   Updated: 2026/08/30 15:47:09 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
    std::cout << START << "\n=== ARENA MATCH START ===\n" << FINAL << std::endl;

    ClapTrap soldier("CT-1");
    ScavTrap guardian("ST-1");

    std::cout << START << "\n=== BATTLE BEGINS ===\n" << FINAL << std::endl;

    soldier.attack("Bandit");
    guardian.attack("Bandit");

    soldier.takeDamage(5);
    guardian.takeDamage(20);

    soldier.beRepaired(3);
    guardian.beRepaired(10);

    std::cout << START << "\n=== SPECIAL ABILITY ===\n" << FINAL << std::endl;

    guardian.guardGate();

    std::cout << START << "\n=== FINAL STRIKE ===\n" << FINAL << std::endl;

    soldier.attack("Bandit");
    guardian.attack("Bandit");

    std::cout << START << "\n=== EXITING ARENA ===\n" << FINAL << std::endl;

    return (0);
}