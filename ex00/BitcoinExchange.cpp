/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomecker <tomecker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:41:10 by tecker            #+#    #+#             */
/*   Updated: 2024/12/14 01:31:43 by tomecker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void BCE::load_database(void)
{
    std::ifstream file("data.csv");
	if (!file.is_open())
		throw std::invalid_argument("database failed to open!");
    std::string line;
    std::string date;
    double value;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        date = line.substr(0, line.find(','));
        value = std::stod(line.substr(line.find(',') + 1));
        _data.emplace(date, value);
    }
}

bool check_line(std::string date, double value)
{
    if (value < 0)
        return (std::cerr << "ERROR: " << "value is negativ! => " << value << std::endl, false);
    if (value > INT_MAX)
        return (std::cerr << "ERROR: " << "value is too large => " << std::fixed << value << std::endl, false);
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return (std::cerr << "ERROR: " << "date has wrong format! => " << date << std::endl, false);

    int year = std::stoi(date.substr(0, 4));
    int month = std::stoi(date.substr(5, 2));
    int day = std::stoi(date.substr(8, 2));

    if (month < 0 || month > 12)
        return (std::cerr << "ERROR: " << "month has wrong value! => " << month << std::endl, false);
    if (day < 1 || day > 31)
        return (std::cerr << "ERROR: " << "day has wrong value! => " << day << std::endl, false);
    if (year < 2009 || (year == 2009 && month == 1 && day == 1))
        return (std::cerr << "ERROR: " << "year is too early. Bitcoin didnt exist yet! => " << date << std::endl, false);
    
    std::tm tm = {};
    tm.tm_year = year - 1900;
    tm.tm_mon = month - 1;
    tm.tm_mday = day;

    std::time_t converted_time = std::mktime(&tm);
    if (converted_time == -1)
        return (std::cerr << "ERROR: " << "Error converting date to time_t!" << std::endl, false);
    
    std::time_t today = std::time(nullptr);
    if (converted_time > today)
        return (std::cerr << "ERROR: " << "date is in the future! => " << date << std::endl, false);
    
    return (true);
}

void BCE::calculate(void)
{
    if (_inputFile.empty())
        throw std::out_of_range("invalid input file!");
    std::ifstream file(_inputFile);
	if (!file.is_open())
		throw std::invalid_argument("database failed to open!");
    std::string line;
    std::string date;
    double value;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        date = line.substr(0, line.find(' '));
        value = std::stod(line.substr(line.rfind(' ') + 1));
        if (check_line(date, value))
        {
            std::map<std::string, double>::iterator it = _data.find(date);
            if (it == _data.end())
            {
                it = _data.upper_bound(date);
                it--;
            }
            std::cout << date << " => " << value << " = " << value * it->second << std::endl;
        }
    }
}

BCE::BCE()
{
}

BCE::BCE(std::string filename)
    : _inputFile(filename)
{
}


BCE::~BCE()
{
}
BCE::BCE(const BCE &src)
    : _data(src._data), _inputFile(src._inputFile)
{
    
}
BCE &BCE::operator=(const BCE &src)
{
    if (this != &src)
    {
        _inputFile = src._inputFile;
        _data = src._data;
    }
    return (*this);
}