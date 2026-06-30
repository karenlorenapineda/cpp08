/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 11:26:03 by kpineda-          #+#    #+#             */
/*   Updated: 2026/06/30 11:49:20 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>

class Span
{
    std::vector<int>    _numbers;
    unsigned int        _maxSize;

public:
    Span(unsigned int n);
    Span(const Span& src);
    ~Span();

    Span& operator=(const Span& src);

    void addNumber(int n);
    int shortestSpan() const;
    int longestSpan() const;

    template <typename Iterator>
    void addNumber(Iterator begin, Iterator end)
    {
        while (begin != end)
        {
            addNumber(*begin);
            ++begin;
        }
    }
    
};

#endif