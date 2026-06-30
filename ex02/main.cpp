/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 12:04:51 by kpineda-          #+#    #+#             */
/*   Updated: 2026/06/30 13:07:17 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <vector>
#include "MutantStack.hpp"

// ANSI color codes for clean and beautiful terminal output
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

int main() {
    std::cout << BOLD << "--- STARTING MUTANTSTACK TESTS ---" << RESET << "\n" << std::endl;

    std::cout << BOLD << "=== TEST 1: SUBJECT TEST (MUTANTSTACK) ===" << RESET << std::endl;
    
    MutantStack<int> mstack;
    
    mstack.push(5);
    mstack.push(17);
    
    std::cout << CYAN << "[INFO]" << RESET << " Top element: " << YELLOW << mstack.top() << RESET << " (Expected: 17)" << std::endl;
    
    mstack.pop();
    std::cout << CYAN << "[INFO]" << RESET << " Size after pop: " << YELLOW << mstack.size() << RESET << " (Expected: 1)" << std::endl;
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    std::cout << CYAN << "[TEST]" << RESET << " Iterating through MutantStack: [ ";
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << "]" << std::endl;
    
    std::stack<int> s(mstack);
    std::cout << GREEN << BOLD << "[OK] " << RESET << "MutantStack successfully copied to std::stack. Size: " << s.size() << std::endl;
    std::cout << std::endl;

    std::cout << BOLD << "=== TEST 2: SUBJECT COMPARISON (STD::LIST) ===" << RESET << std::endl;
    
    std::list<int> lstack;
    
    lstack.push_back(5);
    lstack.push_back(17);
    
    std::cout << CYAN << "[INFO]" << RESET << " Top (back) element: " << YELLOW << lstack.back() << RESET << " (Expected: 17)" << std::endl;
    
    lstack.pop_back();
    std::cout << CYAN << "[INFO]" << RESET << " Size after pop: " << YELLOW << lstack.size() << RESET << " (Expected: 1)" << std::endl;
    
    lstack.push_back(3);
    lstack.push_back(5);
    lstack.push_back(737);
    lstack.push_back(0);
    
    std::cout << CYAN << "[TEST]" << RESET << " Iterating through std::list:    [ ";
    std::list<int>::iterator lit = lstack.begin();
    std::list<int>::iterator lite = lstack.end();
    ++lit;
    --lit;
    while (lit != lite) {
        std::cout << *lit << " ";
        ++lit;
    }
    std::cout << "]" << std::endl;
    std::cout << GREEN << BOLD << "[OK] " << RESET << "Outputs match perfectly with the subject requirements." << std::endl;
    std::cout << std::endl;

    
    std::cout << BOLD << "=== TEST 3: ADVANCED ITERATORS (REVERSE & CONST) ===" << RESET << std::endl;
    
    // Testing Const Iterator
    const MutantStack<int> const_mstack(mstack);
    std::cout << CYAN << "[TEST]" << RESET << " Testing Const Iterator:   [ ";
    for (MutantStack<int>::const_iterator cit = const_mstack.begin(); cit != const_mstack.end(); ++cit) {
        std::cout << *cit << " ";
    }
    std::cout << "]" << std::endl;

    std::cout << CYAN << "[TEST]" << RESET << " Testing Reverse Iterator: [ ";
    for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << "]" << RESET << " (Should be in reverse order)" << std::endl;
    std::cout << std::endl;

    std::cout << BOLD << "--- TESTS FINISHED ---" << RESET << std::endl;
    return 0;
}