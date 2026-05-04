/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 02:20:49 by skarayil          #+#    #+#             */
/*   Updated: 2026/05/02 23:25:15 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include "Utils.hpp"
# include <iomanip>
# include <iostream>
# include <string>

class PhoneBook
{
  private:
	Contact _contacts[8];
	int _startIndex;
	int _count;

	std::string _truncate(const std::string &str) const;
	void _displayHeader() const;
	bool _getInput(const std::string &prompt, std::string &output);
	bool _getPhoneInput(const std::string &prompt, std::string &output);
	void _printContactDetail(int idx) const;

  public:
	PhoneBook();

	void addContact();
	void searchContact();
};

#endif