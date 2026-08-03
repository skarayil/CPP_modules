/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 18:16:02 by skarayil          #+#    #+#             */
/*   Updated: 2026/08/02 14:56:10 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

# define INFO "\033[3;30;100m"
# define DEBUG "\033[3;30;102m"
# define START "\033[3;30;106m"
# define FINAL "\033[0m"
# define BOLD "\033[1;37m"
# define ITAL "\033[3m"

class Zombie
{
  private:
	std::string _name;

  public:
	Zombie(const std::string &name);
	~Zombie();

	void announce() const;
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif