/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 14:19:18 by skarayil          #+#    #+#             */
/*   Updated: 2026/09/09 14:19:47 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "Colors.hpp"
# include <iostream>
# include <string>

class	ICharacter;

class AMateria
{
  protected:
	std::string _type;
	std::string _element;
	std::string _colorCode;

  public:
	AMateria(void);
	AMateria(std::string const &type, std::string const &element,
		std::string const &colorCode);
	AMateria(const AMateria &other);
	AMateria &operator=(const AMateria &other);
	virtual ~AMateria();

	std::string const &getType() const;
	std::string const &getElement() const;
	std::string const &getColorCode() const;

	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);
};

#endif