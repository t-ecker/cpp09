/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomecker <tomecker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:41:14 by tecker            #+#    #+#             */
/*   Updated: 2024/12/19 19:26:09 by tomecker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <iostream>
#include <stdexcept>
#include <stack>

int is_operator(char c);

class RPN
{
    private:
        std::string _str;
        std::stack<double> _stack;
    public:
        RPN();
        RPN(std::string str);
        ~RPN();
        RPN(const RPN &src);
        RPN &operator=(const RPN &src);
        void calculate(void);
};


#endif