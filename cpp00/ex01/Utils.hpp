/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 00:12:44 by skarayil          #+#    #+#             */
/*   Updated: 2026/05/05 12:05:15 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <string>

namespace Utils
{
	bool		ftIsPrintable(char c);
	bool		ftIsDigit(char c);
	void		printColored(const std::string &text, const std::string &color, bool addNewLine = false);
	std::string ftSubstr(const std::string &str, size_t start, size_t len);
	std::string ftItoa(int n);
}

#endif
