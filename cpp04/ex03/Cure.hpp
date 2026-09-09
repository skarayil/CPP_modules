/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 14:27:47 by skarayil          #+#    #+#             */
/*   Updated: 2026/09/09 14:28:00 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
  public:
	Cure(void);
	Cure(const Cure &other);
	Cure &operator=(const Cure &other);
	virtual ~Cure();

	AMateria *clone() const;
	void use(ICharacter &target);
};

#endif