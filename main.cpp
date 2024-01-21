#include <iostream>
#include "MyPriorityQueue.hpp"

int main() {
    std::cout << "-- Integers --" << std::endl;
    int arr_i[] = {3, 4, 1, 2, 5};
    MyPriorityQueue<int> pq_i;
    for (size_t i = 0; i < 5; i++) {
        std::cout << "Pushing " << arr_i[i] << std::endl;
        pq_i.push(arr_i[i]);
    }
    std::cout << "Pushed. Size: " << pq_i.size() << std::endl;
    for (size_t i = 0; i < 5; i++) {
        std::cout << "Popping " << pq_i.peek() << std::endl;
        pq_i.pop();
        std::cout << "Size: " << pq_i.size() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "-- Doubles --" << std::endl;
    double arr_d[] = {3.1, 4.1, 1.1, 2.1, 5.1};
    MyPriorityQueue<double> pq_d;
    for (int i = 0; i < 5; i++) {
        std::cout << "Pushing " << arr_d[i] << std::endl;
        pq_d.push(arr_d[i]);
    }
    std::cout << "Pushed. Size: " << pq_d.size() << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "Popping " << pq_d.peek() << std::endl;
        pq_d.pop();
        std::cout << "Size: " << pq_d.size() << std::endl;
    }

    return 0;
}
