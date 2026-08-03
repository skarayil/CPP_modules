/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 08:59:12 by skarayil          #+#    #+#             */
/*   Updated: 2026/08/02 14:56:18 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

# define INFO "\033[3;30;100m"
# define DEBUG "\033[3;30;102m"
# define START "\033[3;30;106m"
# define BOLD "\033[1;37m"
# define FINAL "\033[0m"

class Zombie
{
  private:
	std::string _name;

  public:
	Zombie(void);
	~Zombie(void);

	void announce(void) const;
	void setName(const std::string &name);
};

Zombie	*zombieHorde(int N, std::string name);

#endif