/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 22:38:47 by skarayil          #+#    #+#             */
/*   Updated: 2026/08/02 17:49:16 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>

# define ERROR "\033[3;30;101m"
# define WARNING "\033[3;30;43m"
# define INFO "\033[3;30;100m"
# define DEBUG "\033[3;30;102m"
# define BOLD "\033[1;37m"
# define FINAL "\033[0m"

class Harl
{
  private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);

  public:
	Harl(void);
	~Harl(void);

	void byIndex(int index);
	void complain(std::string level);
};

#endif