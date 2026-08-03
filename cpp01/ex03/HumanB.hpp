/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 13:00:24 by skarayil          #+#    #+#             */
/*   Updated: 2026/08/02 14:52:45 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <string>

class HumanB
{
  private:
	std::string _name;
	Weapon *_weapon;

  public:
	HumanB(const std::string &name);
	~HumanB(void);

	void setWeapon(Weapon &weapon);
	void attack(void) const;
};

#endif