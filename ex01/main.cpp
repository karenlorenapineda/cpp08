#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int main() {
    // Test with vector
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    try {
        std::vector<int>::iterator it = easyfind(vec, 3);
        std::cout << "Found in vector: " << *it << std::endl;
    } catch (std::exception& e) {
        std::cout << "Vector: " << e.what() << std::endl;
    }

    try {
        easyfind(vec, 99);
    } catch (std::exception& e) {
        std::cout << "Vector (99): " << e.what() << std::endl;
    }

    // Test with list
    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);

    try {
        std::list<int>::iterator it = easyfind(lst, 20);
        std::cout << "Found in list: " << *it << std::endl;
    } catch (std::exception& e) {
        std::cout << "List: " << e.what() << std::endl;
    }

    // Test with deque
    std::deque<int> deq;
    deq.push_back(100);
    deq.push_front(50);

    try {
        std::deque<int>::iterator it = easyfind(deq, 50);
        std::cout << "Found in deque: " << *it << std::endl;
    } catch (std::exception& e) {
        std::cout << "Deque: " << e.what() << std::endl;
    }

    return 0;
}