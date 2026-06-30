/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 11:26:15 by kpineda-          #+#    #+#             */
/*   Updated: 2026/06/30 11:41:29 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : _maxSize(n)
{
    
}

Span::Span(const Span& src) : _numbers(src._numbers), _maxSize(src._maxSize)
{
    
}

Span::~Span()
{
    
}

Span& Span::operator=(const Span& src)
{
    if(this != &src)
	{
		this->_numbers = src._numbers;
        this->_maxSize = src._maxSize;
	}
	return(*this);
}

void Span::addNumber(int n)
{
    if(_numbers.size() >= _maxSize)
        throw std::runtime_error("Span is full");
    _numbers.push_back(n);
}

int Span::shortestSpan() const
{
    if (_numbers.size() < 2)
        throw std::runtime_error("Not enough numbers for span");
    
    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());

    int minSpan = sorted[1] - sorted[0];
    for ( size_t i = 2; i < sorted.size(); i++)
    {
        int span = sorted[i] - sorted[i - 1];
        if (span < minSpan)
            minSpan = span;
    }
    
    return minSpan;
}

int Span::longestSpan() const
{
    if (_numbers.size() < 2)
        throw std::runtime_error("Not enough numbers for span");

    int min = *std::min_element(_numbers.begin(), _numbers.end());
    int max = *std::max_element(_numbers.begin(), _numbers.end());

    return max - min;
}