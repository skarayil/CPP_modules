/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 14:37:08 by skarayil          #+#    #+#             */
/*   Updated: 2026/09/07 15:19:13 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	std::cout << BOLD << "\n=== WILD WORLD WITH BRAINS (ABSTRACT) ===\n" << FINAL << std::endl;

	const int size = 6;
	Animal* animals[size];

	std::cout << CONST << "\n--- CREATING ANIMALS ---\n" << FINAL << std::endl;
	for (int i = 0; i < size / 2; ++i)
		animals[i] = new Dog();
	for (int i = size / 2; i < size; ++i)
		animals[i] = new Cat();

	std::cout << COPY << "\n--- SOUNDS ---\n" << FINAL << std::endl;
	for (int i = 0; i < size; ++i)
		animals[i]->makeSound();

	std::cout << ASSIG << "\n--- DEEP COPY TEST (Dog) ---\n" << FINAL << std::endl;
	Dog originalDog;
	originalDog.getBrain()->setIdea(0, "Chase my tail");
	Dog copiedDog(originalDog);
	copiedDog.getBrain()->setIdea(0, "Sleep all day");

	std::cout << ITALIC << "Original Dog idea[0]: "
	          << originalDog.getBrain()->getIdea(0) << FINAL << std::endl;
	std::cout << ITALIC << "Copied   Dog idea[0]: "
	          << copiedDog.getBrain()->getIdea(0) << FINAL << std::endl;
	std::cout << "(Should be different if deep copy works!)\n" << std::endl;

	Dog anotherDog;
	anotherDog = originalDog;
	anotherDog.getBrain()->setIdea(0, "Bark at mailman");
	std::cout << ITALIC << "Original Dog idea[0] after assignment: "
	          << originalDog.getBrain()->getIdea(0) << FINAL << std::endl;
	std::cout << ITALIC << "Assigned Dog idea[0]: "
	          << anotherDog.getBrain()->getIdea(0) << FINAL << std::endl;

	std::cout << ASSIG << "\n--- DEEP COPY TEST (Cat) ---\n" << FINAL << std::endl;
	Cat originalCat;
	originalCat.getBrain()->setIdea(0, "Catch a mouse");
	Cat copiedCat(originalCat);
	copiedCat.getBrain()->setIdea(0, "Nap in the sun");

	std::cout << ITALIC << "Original Cat idea[0]: "
	          << originalCat.getBrain()->getIdea(0) << FINAL << std::endl;
	std::cout << ITALIC << "Copied   Cat idea[0]: "
	          << copiedCat.getBrain()->getIdea(0) << FINAL << std::endl;
	std::cout << "(Should be different if deep copy works!)\n" << std::endl;

	Cat anotherCat;
	anotherCat = originalCat;
	anotherCat.getBrain()->setIdea(0, "Climb the curtains");
	std::cout << ITALIC << "Original Cat idea[0] after assignment: "
	          << originalCat.getBrain()->getIdea(0) << FINAL << std::endl;
	std::cout << ITALIC << "Assigned Cat idea[0]: "
	          << anotherCat.getBrain()->getIdea(0) << FINAL << std::endl;

	std::cout << DEST << "\n--- CLEANUP ---\n" << FINAL << std::endl;
	for (int i = 0; i < size; ++i)
		delete animals[i];

	return 0;
}
