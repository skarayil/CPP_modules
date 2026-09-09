/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 13:15:31 by skarayil          #+#    #+#             */
/*   Updated: 2026/09/07 14:40:45 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>
# include "Colors.hpp"

class Brain
{
  private:
	std::string ideas[100];

  public:
	Brain(void);
	Brain(const Brain &other);
	Brain &operator=(const Brain &other);
	~Brain();

	std::string getIdea(int index) const;
	void setIdea(int index, const std::string &idea);
};

#endif