/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 20:22:48 by skarayil          #+#    #+#             */
/*   Updated: 2026/10/09 08:53:45 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>

# define R "\033[0m"
# define O "\033[1m"
# define D "\033[2m"
# define K "\033[38;5;68m"
# define S "\033[38;5;117m"
# define I "\033[38;5;81m"
# define X "\033[38;5;111m"
# define M "\033[38;5;147m"
# define Y "\033[38;5;159m"

struct	Base
{
	virtual ~Base();
};

struct A : public Base
{
};
struct B : public Base
{
};
struct C : public Base
{
};

Base	*generate(void);
void	identify(Base *p);
void	identify(Base &p);

#endif
