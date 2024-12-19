/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tecker <tecker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:41:10 by tecker            #+#    #+#             */
/*   Updated: 2024/12/19 14:38:16 by tecker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}
PmergeMe::PmergeMe(const PmergeMe &src)
{
    (void)src;
}
PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
    (void)src;
    return (*this);
}