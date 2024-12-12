/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tecker <tecker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:41:10 by tecker            #+#    #+#             */
/*   Updated: 2024/12/12 14:50:00 by tecker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool is_operator(char c)
{
    return (c == '+' || c == '-' || c == '/' || c == '*');
}

int do_operation(int a, int b, char c)
{
    switch (c)
    {
    case '+':
        return (b + a);
        break;
    case '-':
        return (b - a);
        break;
    case '/':
        return (b / a);
        break;
    case '*':
        return (b * a);
        break;
    default:
        return (-1);
        break;
    }
}

void RPN::calculate(void)
{
    if (_str.empty())
        throw std::out_of_range("input was empty!");
    std::cout << _str[1] << std::endl;
    for (int i = 0; _str[i]; i++)
    {
        if (i % 2 == 1)
        {
            if (_str[i] != ' ')
                throw std::invalid_argument("invalid input!");   
        }
        else
        {
            if (is_operator(_str[i]))
            {
                if (_stack.size() != 2)
                    throw std::invalid_argument("invalid operator!");
                int a = _stack.top();
                _stack.pop();
                int b = _stack.top();
                _stack.pop();
                int res = do_operation(a, b, _str[i]);
                if (res == -1)
                {
                    std::cerr << "ERROR" << std::endl;
                    throw std::exception();   
                }
                _stack.push(res);
            }
            else
            {
                if (!std::isdigit(_str[i]))
                    throw std::invalid_argument("missing number!");    
                _stack.push(_str[i]);
            }
        }
    }
    std::cout << _stack.top();
    
    
}

RPN::RPN()
    :   _str(nullptr), _stack()
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