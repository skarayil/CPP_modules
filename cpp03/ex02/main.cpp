/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 17:02:20 by skarayil          #+#    #+#             */
/*   Updated: 2026/08/30 17:26:20 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    std::cout << START << "\n=== ARENA MATCH START ===\n" << FINAL << std::endl;

    ClapTrap soldier("CT-1");
    ScavTrap guardian("ST-1");
    FragTrap grenadier("FT-1");

    std::cout << START << "\n=== BATTLE BEGINS ===\n" << FINAL << std::endl;

    soldier.attack("Bandit");
    guardian.attack("Bandit");
    grenadier.attack("Bandit");

    soldier.takeDamage(5);
    guardian.takeDamage(20);
    grenadier.takeDamage(15);

    soldier.beRepaired(3);
    guardian.beRepaired(10);
    grenadier.beRepaired(8);

    std::cout << START << "\n=== SPECIAL ABILITIES ===\n" << FINAL << std::endl;

    guardian.guardGate();
    grenadier.highFivesGuys();

    std::cout << START << "\n=== FINAL STRIKE ===\n" << FINAL << std::endl;

    soldier.attack("Bandit");
    guardian.attack("Bandit");
    grenadier.attack("Bandit");

    std::cout << START << "\n=== EXITING ARENA ===\n" << FINAL << std::endl;

    return (0);
}
