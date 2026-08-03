/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 13:00:01 by skarayil          #+#    #+#             */
/*   Updated: 2026/08/02 14:57:04 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <string>

class HumanA
{
  private:
	std::string _name;
	Weapon &_weapon;

  public:
	HumanA(const std::string &name, Weapon &weapon);
	~HumanA(void);

	void attack(void) const;
};

#endif