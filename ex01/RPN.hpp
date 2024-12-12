/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tecker <tecker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:41:14 by tecker            #+#    #+#             */
/*   Updated: 2024/12/12 14:16:02 by tecker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <string.h>
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <stack>

bool is_operator(char c);

class RPN
{
    private:
        std::string _str;
        std::stack<int> _stack;
    public:
        RPN();
        RPN(std::string str);
        ~RPN();
        RPN(const RPN &src);
        RPN &operator=(const RPN &src);
        void calculate(void);
};


#endif