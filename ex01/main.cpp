/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomecker <tomecker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:41:18 by tecker            #+#    #+#             */
/*   Updated: 2024/12/12 20:08:50 by tomecker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// bool check_input(int argc, char **argv)
// {
//     if (argc != 2)
//         return (false);
//     std::string arg = argv[1];
//     if (!::is_operator(arg.back()))
//         return (false);
//     // if (std::count(arg.begin(), arg.end(), ' '));
//     std::cout << std::count(arg.begin(), arg.end(), ' ') << std::endl;
//     return (true);
// }

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Wrong amound of parameters!" << std::endl;
        return (1);
    }
    try
    {
        RPN Rpn(argv[1]);
        Rpn.calculate();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
}