/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 19:14:10 by skarayil          #+#    #+#             */
/*   Updated: 2026/09/07 12:45:43 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
    std::cout << BOLD << "\n=== WILD WORLD SIMULATION ===\n" << FINAL << std::endl;

    std::cout << BOLD << "--- CORRECT POLYMORPHISM ---\n" << FINAL << std::endl;
    const Animal* meta = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << ITALIC << "Types: " 
              << meta->getType() << ", " 
              << dog->getType() << ", " 
              << cat->getType() 
              << FINAL << "\n\n";

    std::cout << "Calling makeSound() on each pointer:\n";
    meta->makeSound();
    dog->makeSound();
    cat->makeSound();

    std::cout << BOLD << "\n--- WRONG POLYMORPHISM (no virtual) ---\n" << FINAL << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << ITALIC << "Types: " 
              << wrongMeta->getType() << ", " 
              << wrongCat->getType() 
              << FINAL << "\n\n";

    std::cout << "Calling makeSound() on each pointer:\n";
    wrongMeta->makeSound();
    wrongCat->makeSound();

    std::cout << BOLD << "\n--- CLEANUP ---\n" << FINAL << std::endl;
    delete meta;
    delete dog;
    delete cat;
    delete wrongMeta;
    delete wrongCat;

    return (0);
}
