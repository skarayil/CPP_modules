/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 15:36:15 by skarayil          #+#    #+#             */
/*   Updated: 2026/08/30 17:10:37 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

# define CONST "\033[1;4;92m"
# define COPY "\033[1;4;96m"
# define ASSIG "\033[1;4;93m"
# define DEST "\033[1;4;91m"

# define ATTACK "\033[3;30;47m"
# define DAMAGE "\033[3;37;40m"
# define REPAIR "\033[3;37;100m"

# define SPEC "\033[3;30;48;2;128;128;128m"

# define START "\033[1;37m"
# define FINAL "\033[0m"

class ClapTrap
{
  protected:
	std::string _name;
	unsigned int _hitPoints;
	unsigned int _energyPoints;
	unsigned int _attackDamage;

  public:
	ClapTrap(void);
	ClapTrap(const std::string &name);
	ClapTrap(const ClapTrap &other);
	ClapTrap &operator=(const ClapTrap &other);
	~ClapTrap();

	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif