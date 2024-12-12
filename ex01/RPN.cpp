/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomecker <tomecker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:41:10 by tecker            #+#    #+#             */
/*   Updated: 2024/12/12 20:55:07 by tomecker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int is_operator(char c)
{
    return (c == '+' || c == '-' || c == '/' || c == '*');
}

double do_operation(double a, double b, char c)
{
    switch (c)
    {
        case '+':
            return (b + a);
        case '-':
            return (b - a);
        case '/':
            if (a == 0)
                throw std::invalid_argument("division by 0!");
            return (b / a);
        case '*':
            return (b * a);
        default:
            return (-1);
    }
}

void RPN::calculate(void)
{
    if (_str.empty())
        throw std::out_of_range("input was empty!");
    for (int i = 0; _str[i]; i++)
    {
        // if (i % 2 != 0)
        // {
        //     if (_str[i] != ' ')
        //         throw std::invalid_argument("invalid input!");   
        // }
        // else
            
        if (_str[i] != ' ')
        {
            if (is_operator(_str[i]))
            {
                if (_stack.size() < 2)
                    throw std::invalid_argument("missing numbers!");
                double a = _stack.top();
                _stack.pop();
                double b = _stack.top();
                _stack.pop();
                _stack.push(do_operation(a, b, _str[i]));
            }
            else
            {
                if (!std::isdigit(_str[i]))
                    throw std::invalid_argument("ERROR");
                _stack.push(static_cast<int>(_str[i] - '0'));
            }
        }
    }
    if (_stack.size() != 1)
        throw std::invalid_argument("ERROR");
    std::cout << _stack.top() << std::endl;
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