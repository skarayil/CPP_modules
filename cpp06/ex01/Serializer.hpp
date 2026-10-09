/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 20:22:44 by skarayil          #+#    #+#             */
/*   Updated: 2026/10/09 08:49:58 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include "Data.hpp"
# include <stdint.h>

# define R "\033[0m"
# define O "\033[1m"
# define D "\033[2m"
# define K "\033[38;5;68m"
# define S "\033[38;5;117m"
# define I "\033[38;5;81m"
# define B "\033[38;5;111m"
# define M "\033[38;5;147m"
# define C "\033[38;5;159m"

class Serializer
{
  public:
	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);

  private:
	Serializer();
	Serializer(const Serializer &);
	Serializer &operator=(const Serializer &);
	~Serializer();
};

#endif
