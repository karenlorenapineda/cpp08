/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 11:26:10 by kpineda-          #+#    #+#             */
/*   Updated: 2026/06/30 12:03:41 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

// ANSI color codes for clean and beautiful terminal output
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

/*

*/

int main() {
   
    std::srand(std::time(NULL));

    std::cout << BOLD << "--- STARTING SPAN TESTS ---" << RESET << "\n" << std::endl;

    
    std::cout << BOLD << "=== TEST 1: SUBJECT BASIC TEST ===" << RESET << std::endl;
    std::cout << CYAN << "[INFO]" << RESET << " Creating Span of size 5 and adding: 6, 3, 17, 9, 11" << std::endl;
    
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << GREEN << BOLD << "[SUCCESS] " << RESET << "Shortest Span: " << YELLOW << sp.shortestSpan() << RESET << " (Expected: 2)" << std::endl;
    std::cout << GREEN << BOLD << "[SUCCESS] " << RESET << "Longest Span:  " << YELLOW << sp.longestSpan() << RESET << " (Expected: 14)" << std::endl;
    std::cout << std::endl;

    
    std::cout << BOLD << "=== TEST 2: EDGE CASES & EXCEPTIONS ===" << RESET << std::endl;
    
    
    std::cout << CYAN << "[TEST]" << RESET << " Attempting to add a 6th element to a Span of size 5... " << std::endl;
    try {
        sp.addNumber(42);
        std::cout << RED << BOLD << "[KO] " << RESET << "Error: Exception was not thrown!" << std::endl;
    } catch (const std::exception& e) {
        std::cout << GREEN << BOLD << "[OK] " << RESET << "Exception caught successfully: " << RED << e.what() << RESET << std::endl;
    }

   
    std::cout << CYAN << "[TEST]" << RESET << " Attempting to calculate spans on an empty Span... " << std::endl;
    Span emptySpan(5);
    try {
        emptySpan.shortestSpan();
        std::cout << RED << BOLD << "[KO] " << RESET << "Error: Exception was not thrown!" << std::endl;
    } catch (const std::exception& e) {
        std::cout << GREEN << BOLD << "[OK] " << RESET << "Exception caught successfully: " << RED << e.what() << RESET << std::endl;
    }

    
    std::cout << CYAN << "[TEST]" << RESET << " Attempting to calculate spans on a Span with 1 element... " << std::endl;
    Span oneElementSpan(5);
    oneElementSpan.addNumber(42);
    try {
        oneElementSpan.longestSpan();
        std::cout << RED << BOLD << "[KO] " << RESET << "Error: Exception was not thrown!" << std::endl;
    } catch (const std::exception& e) {
        std::cout << GREEN << BOLD << "[OK] " << RESET << "Exception caught successfully: " << RED << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    
    std::cout << BOLD << "=== TEST 3: LARGE TEST (10,000+ NUMBERS VIA ITERATORS) ===" << RESET << std::endl;
    
    unsigned int bigSize = 10000;
    std::cout << CYAN << "[INFO]" << RESET << " Generating " << bigSize << " random numbers..." << std::endl;
    
    std::vector<int> randomNumbers;
    for (unsigned int i = 0; i < bigSize; i++) {
        randomNumbers.push_back(std::rand() % 100001); 
    }

    Span bigSpan(bigSize);
    std::cout << CYAN << "[TEST]" << RESET << " Inserting all numbers at once using iterator range... " << std::flush;
    try {
        bigSpan.addNumber(randomNumbers.begin(), randomNumbers.end());
        std::cout << GREEN << BOLD << "[OK]" << RESET << std::endl;
        
        // Calculate results
        std::cout << GREEN << BOLD << "[SUCCESS] " << RESET << "Big Shortest Span: " << YELLOW << bigSpan.shortestSpan() << RESET << std::endl;
        std::cout << GREEN << BOLD << "[SUCCESS] " << RESET << "Big Longest Span:  " << YELLOW << bigSpan.longestSpan() << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << BOLD << "[KO] " << RESET << "Insertion failed: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << BOLD << "--- TESTS FINISHED ---" << RESET << std::endl;
    return 0;
}