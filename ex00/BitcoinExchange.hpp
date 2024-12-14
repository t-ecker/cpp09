/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomecker <tomecker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:41:14 by tecker            #+#    #+#             */
/*   Updated: 2024/12/13 23:24:43 by tomecker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>

class BCE
{
    private:
        std::map<std::string, double> _data;
        std::string _inputFile;
    public:
        BCE();
        BCE(std::string filename);
        ~BCE();
        BCE(const BCE &src);
        BCE &operator=(const BCE &src);
        void calculate(void);
        void load_database(void);
};


#endif