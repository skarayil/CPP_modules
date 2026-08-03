/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 17:35:50 by skarayil          #+#    #+#             */
/*   Updated: 2026/08/02 17:56:05 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"
#include <iostream>
#include <fstream>

static const char* ftStrStr(const char* haystack, const char* needle)
{
    if (!haystack || !needle) return NULL;
    if (*needle == '\0') return haystack;
    for (const char* h = haystack; *h != '\0'; ++h)
    {
        const char* h_iter = h;
        const char* n_iter = needle;
        while (*n_iter != '\0' && *h_iter == *n_iter)
        {
            ++h_iter;
            ++n_iter;
        }
        if (*n_iter == '\0') return h;
    }
    return NULL;
}

static std::string replaceLine(const std::string& line,
                               const std::string& s1,
                               const std::string& s2)
{
    std::string result;
    const char* start = line.c_str();
    const char* current = start;
    const char* found;

    while ((found = ftStrStr(current, s1.c_str())) != NULL)
    {
        result.append(current, found - current);
        result += s2;
        current = found + s1.length();
    }
    result += current;
    return result;
}

static bool validateInput(const std::string& s1)
{
    if (s1.empty())
    {
        std::cerr << ERROR << "[ERROR]" << FINAL
                  << " Search string (s1) cannot be empty." << "\n\n";
        return false;
    }
    return true;
}

static bool openFiles(const std::string& filename,
                      const std::string& s1,
                      const std::string& s2,
                      std::ifstream& inFile,
                      std::ofstream& outFile,
                      std::string& outName)
{
    inFile.open(filename.c_str());
    if (!inFile.is_open())
    {
        std::cerr << ERROR << "[ERROR]" << FINAL
                  << " Cannot open file: " 
                  << BOLD << filename << FINAL << "\n\n";
        return false;
    }
    outName = filename + ".replace";
    outFile.open(outName.c_str());
    if (!outFile.is_open())
    {
        std::cerr << ERROR << "[ERROR]" << FINAL
                  << " Cannot create file: " 
                  << BOLD << outName << FINAL << "\n\n";
        inFile.close();
        return false;
    }
    std::cout << INFO << "[INFO]" << FINAL
              << " Replacing " << BOLD << s1 << FINAL
              << " -> " << BOLD << s2 << FINAL
              << " in " << ITAL << filename << FINAL << "\n\n";
    return true;
}

static int processFiles(std::ifstream& inFile,
                        std::ofstream& outFile,
                        const std::string& s1,
                        const std::string& s2,
                        const std::string& outName)
{
    std::string line;
    bool firstLine = true;
    while (std::getline(inFile, line))
    {
        if (!firstLine) outFile << "\n";
        outFile << replaceLine(line, s1, s2);
        firstLine = false;
    }
    std::cout << DEBUG << "[DEBUG]" << FINAL
              << " Output written to: " 
              << BOLD << outName << FINAL << "\n\n";
    inFile.close();
    outFile.close();
    return 0;
}

int Replacer::run(const std::string& filename,
                  const std::string& s1,
                  const std::string& s2)
{
    if (!validateInput(s1)) return 1;
    std::ifstream inFile;
    std::ofstream outFile;
    std::string outName;
    if (!openFiles(filename, s1, s2, inFile, outFile, outName)) return 1;
    return processFiles(inFile, outFile, s1, s2, outName);
}
