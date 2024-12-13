/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tecker <tecker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:41:14 by tecker            #+#    #+#             */
/*   Updated: 2024/12/13 14:32:27 by tecker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string.h>
#include <iostream>
#include <iomanip>
#include <map>

class BCE
{
    private:
        std::map<std::string, double> data;
    public:
        BCE();
        BCE(std::string str);
        ~BCE();
        BCE(const BCE &src);
        BCE &operator=(const BCE &src);
        void calculate(void);
};


#endif