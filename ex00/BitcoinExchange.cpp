/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tecker <tecker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:41:10 by tecker            #+#    #+#             */
/*   Updated: 2024/12/13 14:33:04 by tecker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void RPN::calculate(void)
{
    
}

RPN::RPN()
    :   _stack()
{
}
RPN::RPN(std::string str)
    :   _str(str), _stack()
{
    
}
RPN::~RPN()
{
}
RPN::RPN(const RPN &src)
    : _stack()
{
    _str = src._str;
    _stack = src._stack;
}
RPN &RPN::operator=(const RPN &src)
{
    if (this != &src)
    {
        _str = src._str;
        _stack = src._stack;
    }
    return (*this);
}