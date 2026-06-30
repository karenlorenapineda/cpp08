/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 10:27:20 by kpineda-          #+#    #+#             */
/*   Updated: 2026/06/30 11:14:08 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

// ANSI color codes for clean and beautiful terminal output
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

// Helper template function to print container elements
template <typename T>
void print_container(const T& container) {
    std::cout << "[ ";
    for (typename T::const_iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "]";
}

// Helper template function to automate and format tests
template <typename T>
void run_test(T& container, int value_to_find, const std::string& container_name) {
    std::cout << CYAN << "[TEST] " << RESET << "Searching for " << YELLOW << value_to_find 
              << RESET << " in " << BOLD << container_name << RESET << " ";
    print_container(container);
    std::cout << "... ";
    
    try {
        typename T::iterator it = easyfind(container, value_to_find);
        std::cout << GREEN << BOLD << "[OK] " << RESET << "Found value: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << BOLD << "[KO] " << RESET << "Exception caught: " << e.what() << std::endl;
    }
}


    /* 1. Tests with std::vector
        2. Tests with std::list (including duplicates and negative numbers)
        3. Tests with std::deque
        4. Edge case: Empty container */
        
int main() {
    std::cout << BOLD << "--- STARTING EASYFIND TESTS ---" << RESET << "\n" << std::endl;

   
    std::cout << BOLD << "=== TEST: STD::VECTOR ===" << RESET << std::endl;
    std::vector<int> vec;
    for (int i = 1; i <= 5; ++i) vec.push_back(i);

    run_test(vec, 3, "std::vector");
    run_test(vec, 99, "std::vector");
    std::cout << std::endl;

    
    std::cout << BOLD << "=== TEST: STD::LIST ===" << RESET << std::endl;
    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(-42);
    lst.push_back(20);
    lst.push_back(10);

    run_test(lst, 20, "std::list");
    run_test(lst, -42, "std::list"); 
    run_test(lst, 5, "std::list");   
    std::cout << std::endl;

   
    std::cout << BOLD << "=== TEST: STD::DEQUE ===" << RESET << std::endl;
    std::deque<int> deq;
    deq.push_back(100);
    deq.push_front(50);
    deq.push_back(200);

    run_test(deq, 50, "std::deque"); 
    run_test(deq, 500, "std::deque"); 
    std::cout << std::endl;

   
    std::cout << BOLD << "=== EDGE CASE: EMPTY CONTAINER ===" << RESET << std::endl;
    std::vector<int> empty_vec;
    run_test(empty_vec, 42, "std::vector (empty)");
    std::cout << std::endl;

    std::cout << BOLD << "--- TESTS FINISHED ---" << RESET << std::endl;
    return 0;
}