/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 14:43:15 by skarayil          #+#    #+#             */
/*   Updated: 2026/09/09 14:55:42 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main(void)
{
    std::cout << BOLD << "\n=== THE ALCHEMIST'S CIRCLE ===\n" << FINAL << std::endl;

    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    std::cout << BOLD << "\n=== ADDITIONAL TRIALS ===\n" << FINAL << std::endl;

    me->use(2, *bob);

    AMateria* extra = src->createMateria("ice");
    me->equip(extra);
    me->unequip(2);
    delete extra;
    me->use(2, *bob);

    Character original("original");
    AMateria* ice = src->createMateria("ice");
    original.equip(ice);
    Character copy(original);
    copy.use(0, *bob);

    delete bob;
    delete me;
    delete src;

    return (0);
}