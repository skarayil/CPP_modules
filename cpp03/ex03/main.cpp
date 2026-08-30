/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 17:25:31 by skarayil          #+#    #+#             */
/*   Updated: 2026/08/30 17:25:59 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
    std::cout << START << "\n=== ARENA MATCH START ===\n" << FINAL << std::endl;

    ClapTrap soldier("CT-1");
    ScavTrap guardian("ST-1");
    FragTrap grenadier("FT-1");
    DiamondTrap champion("DT-1");

    std::cout << START << "\n=== BATTLE BEGINS ===\n" << FINAL << std::endl;

    soldier.attack("Bandit");
    guardian.attack("Bandit");
    grenadier.attack("Bandit");
    champion.attack("Bandit");

    std::cout << START << "\n=== SPECIAL ABILITIES ===\n" << FINAL << std::endl;

    guardian.guardGate();
    grenadier.highFivesGuys();
    champion.whoAmI();

    std::cout << START << "\n=== FINAL STRIKE ===\n" << FINAL << std::endl;

    soldier.attack("Bandit");
    guardian.attack("Bandit");
    grenadier.attack("Bandit");
    champion.attack("Bandit");

    std::cout << START << "\n=== EXITING ARENA ===\n" << FINAL << std::endl;

    return (0);
}