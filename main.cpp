#include "queue.h"



int main() {
    // Instantiate the queue with integers and push 10 values into the queue
    unsigned int seed_value = static_cast<unsigned int>(time(0)); // helps to randomize numbers each run
    srand(seed_value);
    
    CQ::queue<int> q(10);
    for (int i = 1; i <= 10; ++i) {
        q.push(rand()%10);
    }

    // Copy the queue to q_copy
    CQ::queue<int> q_copy = q;

    // Display all the elements in the queue for testing purposes
    std::cout << "Queue contents: ";
    size_t size = q.size();
    for (size_t i = 0; i < size; ++i) {
        int front_elem = q.front();
        std::cout << front_elem << " ";
        q.pop();
        q.push(front_elem); // Keep the element in the queue
    }
    std::cout << std::endl;

    // Move the front element to the rear of the queue
    q.move_to_rear();
    std::cout << "After moving front to rear: ";
    size = q.size();
    for (size_t i = 0; i < size; ++i) {
        int front_elem = q.front();
        std::cout << front_elem << " ";
        q.pop();
        q.push(front_elem); // Keep the element in the queue
    }
    std::cout << std::endl;
    std::vector<int> v;
    int target = 2; 

    for (size_t i = 0; i < 10; ++i) {
        v.push_back(rand()%10); //pushes random numbers into vector 
    
        std::cout << v[i] << " ";
    }
    int last_occurrence = vector_linear_search(v, target, 0, -1); //calls the function to find the last occurrence of the target where -1 is returned if the target is not found
    if (last_occurrence != -1)
        std::cout << "\nLast occurrence of " << target << " found at position: " << last_occurrence << std::endl;
    else
        std::cout << "\nTarget not found in the queue." << std::endl;
    // Sorting and output
    q_copy.insertion_sort();
    std::cout << "Queue contents after sorting: "; 
    size = q_copy.size(); 
    while (size > 0) {
        std::cout << q_copy.front() << " "; 
        q_copy.pop(); 
        size--;
    }
    std::cout << std::endl;

    return 0;
}
