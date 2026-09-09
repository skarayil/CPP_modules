/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 14:24:35 by skarayil          #+#    #+#             */
/*   Updated: 2026/09/09 14:24:46 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
  public:
	Ice(void);
	Ice(const Ice &other);
	Ice &operator=(const Ice &other);
	virtual ~Ice();

	AMateria *clone() const;
	void use(ICharacter &target);
};

#endif