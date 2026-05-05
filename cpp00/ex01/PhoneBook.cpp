/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 00:12:31 by skarayil          #+#    #+#             */
/*   Updated: 2026/05/05 17:28:51 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Colors.hpp"
#include "Utils.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook()
    : _startIndex(0)
    , _count(0)
{
}

std::string PhoneBook::_truncate(const std::string& str) const
{
    if (str.length() > 10) return (Utils::ftSubstr(str, 0, 9) + ".");
    return (str);
}

void    PhoneBook::_displayHeader() const
{
    std::cout << BOLD CYAN << "║" << BOLD WHITE << std::setw(10) << std::right << "INDEX" << RESET;
    std::cout << BOLD CYAN << "║" << BOLD WHITE << std::setw(10) << std::right << "FIRST NAME" << RESET;
    std::cout << BOLD CYAN << "║" << BOLD WHITE << std::setw(10) << std::right << "LAST NAME" << RESET;
    std::cout << BOLD CYAN << "║" << BOLD WHITE << std::setw(10) << std::right << "NICKNAME" << RESET;
    std::cout << BOLD CYAN << "║" << RESET << std::endl;
}

bool    PhoneBook::_getInput(const std::string& prompt, std::string& output)
{
    std::string     input;
    for (;;)
    {
        Utils::printColored(prompt, BOLD CYAN);
        if (!std::getline(std::cin, input))
        {
            std::cout << std::endl;
            return (false);
        }
        if (input.empty())
        {
            Utils::printColored("\n▶ Field cannot be empty. Try again.\n", BOLD RED, true);
            continue ;
        }
        bool        printable = true;
        const char      *ptr = input.c_str();
        for (std::string::size_type i = 0; i < input.length(); ++i)
        {
            if (!Utils::ftIsPrintable(*(ptr + i)))
            {
                printable = false;
                break ;
            }
        }
        if (!printable)
        {
            Utils::printColored("\n▶ Contains non-printable characters. Try again.\n", BOLD RED, true);
            continue ;
        }
        output = input;
        return (true);
    }
}

bool    PhoneBook::_getPhoneInput(const std::string& prompt, std::string& output)
{
    std::string     phone;
    for (;;)
    {
        if (!_getInput(prompt, phone)) return (false);
        bool        valid = true;
        const char      *ptr = phone.c_str();
        for (std::string::size_type i = 0; i < phone.length(); ++i)
        {
            if (i == 0 && *(ptr + i) == '+') continue ;
            if (!Utils::ftIsDigit(*(ptr + i)))
            {
                valid = false;
                break ;
            }
        }
        if (valid && phone.length() >= 1 && phone.length() <= 20)
        {
            output = phone;
            return (true);
        }
        Utils::printColored("\n▶ Invalid phone number!\n", BOLD RED, true);
    }
}

void    PhoneBook::addContact()
{
    std::string     fields[5];
    const char*     prompts[5] =
    {
        "FIRST NAME     : ",
        "LAST NAME      : ",
        "NICKNAME       : ",
        "PHONE NUMBER   : ",
        "DARKEST SECRET : "
    };
    Utils::printColored("\n════════════ ADDING NEW CONTACT ═════════════\n", BOLD CYAN, true);
    for (int i = 0; i < 5; ++i)
    {
        if (i == 3) { if (!_getPhoneInput(*(prompts + i), *(fields + i))) return ; } 
        else { if (!_getInput(*(prompts + i), *(fields + i))) return ; }
    }
    if (_count < 8)
    {
        int     physicalIndex = (_startIndex + _count) % 8;
        (_contacts + physicalIndex)->setFirstName(*fields);
        (_contacts + physicalIndex)->setLastName(*(fields + 1));
        (_contacts + physicalIndex)->setNickname(*(fields + 2));
        (_contacts + physicalIndex)->setPhoneNumber(*(fields + 3));
        (_contacts + physicalIndex)->setDarkestSecret(*(fields + 4));
        _count++;
    }
    else
    {
        (_contacts + _startIndex)->setFirstName(*fields);
        (_contacts + _startIndex)->setLastName(*(fields + 1));
        (_contacts + _startIndex)->setNickname(*(fields + 2));
        (_contacts + _startIndex)->setPhoneNumber(*(fields + 3));
        (_contacts + _startIndex)->setDarkestSecret(*(fields + 4));
        _startIndex = (_startIndex + 1) % 8;
    }
    Utils::printColored("\n═════════════════════════════════════════════", BOLD CYAN, true);
    std::string     msg = "\n▶ Contact added successfully! [" + Utils::ftItoa(_count) + "/8]";
    Utils::printColored(msg, BOLD GREEN, true);
}

void    PhoneBook::_printContactDetail(int idx) const
{
    int     physicalIndex = (_startIndex + idx) % 8;
    const Contact&      c = *(_contacts + physicalIndex);
    Utils::printColored("\n══════════════ CONTACT DETAILS ══════════════", BOLD CYAN, true);
    Utils::printColored("FIRST NAME     : ", BOLD CYAN);
    Utils::printColored(c.getFirstName(), BOLD WHITE, true);
    Utils::printColored("LAST NAME      : ", BOLD CYAN);
    Utils::printColored(c.getLastName(), BOLD WHITE, true);
    Utils::printColored("NICKNAME       : ", BOLD CYAN);
    Utils::printColored(c.getNickname(), BOLD WHITE, true);
    Utils::printColored("PHONE NUMBER   : ", BOLD CYAN);
    Utils::printColored(c.getPhoneNumber(), BOLD WHITE, true);
    Utils::printColored("DARKEST SECRET : ", BOLD CYAN);
    Utils::printColored(c.getDarkestSecret(), BOLD WHITE, true);
    Utils::printColored("═════════════════════════════════════════════", BOLD CYAN, true);
}

void    PhoneBook::searchContact()
{
    if (_count == 0)
    {
        Utils::printColored("▶ Phonebook is empty!", BOLD RED, true);
        return ;
    }
    Utils::printColored("\n╔═══════════════ CONTACT LIST ══════════════╗", BOLD CYAN, true);
    _displayHeader();
    for (int i = 0; i < _count; ++i)
    {
        int     physicalIndex = (_startIndex + i) % 8;
        const Contact&      c = *(_contacts + physicalIndex);
        std::cout << BOLD CYAN << "║" << BOLD WHITE << std::setw(10) << std::right << Utils::ftItoa(i) << RESET;
        std::cout << BOLD CYAN << "║" << BOLD WHITE << std::setw(10) << std::right << _truncate(c.getFirstName()) << RESET;
        std::cout << BOLD CYAN << "║" << BOLD WHITE << std::setw(10) << std::right << _truncate(c.getLastName()) << RESET;
        std::cout << BOLD CYAN << "║" << BOLD WHITE << std::setw(10) << std::right << _truncate(c.getNickname()) << RESET;
        std::cout << BOLD CYAN << "║" << RESET << std::endl;
    }
    Utils::printColored("╚═══════════════════════════════════════════╝", BOLD CYAN, true);
    std::string     input;
    std::cout << std::endl;
    Utils::printColored("▶ Enter index to display: ", BOLD MAGENTA);
    if (!std::getline(std::cin, input)) return ;
    const char      *ptr = input.c_str();
    if (input.length() == 1 && Utils::ftIsDigit(*ptr))
    {
        int     idx = *ptr - '0';
        if (idx >= 0 && idx < _count)
        {
            _printContactDetail(idx);
            return ;
        }
    }
    Utils::printColored("\n▶ Invalid index! Returning to main menu.", BOLD RED, true);
}
