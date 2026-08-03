/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 12:30:27 by skarayil          #+#    #+#             */
/*   Updated: 2026/08/02 14:55:42 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

# define WARNING "\033[3;30;43m"
# define INFO "\033[3;30;100m"
# define DEBUG "\033[3;30;102m"
# define START "\033[3;30;106m"
# define BOLD "\033[1;37m"
# define ITAL "\033[3m"
# define FINAL "\033[0m"

class Weapon
{
  private:
	std::string _type;

  public:
	Weapon(const std::string &type);
	~Weapon(void);

	const std::string &getType(void) const;
	void setType(const std::string &type);
};

#endif