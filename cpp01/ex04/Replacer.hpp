/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 17:35:50 by skarayil          #+#    #+#             */
/*   Updated: 2026/08/02 16:59:38 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACER_HPP
# define REPLACER_HPP

# include <string>

# define ERROR   "\033[3;30;101m"
# define INFO    "\033[3;30;100m"
# define DEBUG   "\033[3;30;102m"
# define BOLD    "\033[1;37m"
# define ITAL    "\033[3m"
# define FINAL   "\033[0m"

class Replacer
{
public:
	static int	run(const std::string& filename,
	                const std::string& s1,
	                const std::string& s2);
};

#endif