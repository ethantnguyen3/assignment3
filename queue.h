
#include <iostream> 
#include <stdexcept>
#include <vector>
namespace CQ { // Circular Queue namespace

template<typename Item_Type>
class queue {
public:
    // Constructor
    queue(size_t capacity = DEFAULT_CAPACITY);

    // Copy constructor
    queue(const queue& other);

    // Assignment operator
    //queue& operator=(const queue& other);

    // Destructor
    ~queue();

    // Add an item to the back of the queue
    void push(const Item_Type& item);

    // Remove the front item from the queue
    void pop();

    // Access the front item of the queue
    Item_Type front() const;

    // Get the current number of items in the queue
    size_t size() const;

    // Check if the queue is empty
    bool empty() const;

    // Move the element at the front of the queue to the rear
    void move_to_rear();
    // Sorts a queue in ascending order using insertion sort.
    void insertion_sort();
private:
    // Default capacity of the queue
    static const size_t DEFAULT_CAPACITY = 10;

    // Queue data members
    size_t capacity;
    size_t num_items;
    size_t front_index;
    size_t rear_index;
    Item_Type* the_data;
};
    template<typename Item_Type>
        queue<Item_Type>::queue(size_t capacity) 
            : capacity(capacity), num_items(0), front_index(0), rear_index(capacity - 1) {
            the_data = new Item_Type[capacity];
        } 
        // Copy constructor (deep copy)
        template<typename Item_Type>
        queue<Item_Type>::queue(const queue& other) 
            : capacity(other.capacity), num_items(other.num_items), front_index(other.front_index), rear_index(other.rear_index) {
            the_data = new Item_Type[capacity];
            for (size_t i = 0; i < num_items; ++i) {
                the_data[(front_index + i) % capacity] = other.the_data[(other.front_index + i) % other.capacity];
            }
        }

        // Assignment operator (deep copy)
        /*template<typename Item_Type>
        queue<Item_Type>&
        queue<Item_Type>::operator=(const queue& other) {
            if (this != &other) { // Avoid self-assignment
                delete[] the_data;

                capacity = other.capacity;
                num_items = other.num_items;
                front_index = other.front_index;
                rear_index = other.rear_index;

                the_data = new Item_Type[capacity];
                for (size_t i = 0; i < num_items; ++i) {
                    the_data[(front_index + i) % capacity] = other.the_data[(other.front_index + i) % other.capacity];
                }
            }
            return *this;
        }*/

        // Destructor
        template<typename Item_Type>
        queue<Item_Type>::~queue() {
            delete[] the_data;
        }

        // Add an item to the back of the queue
        template<typename Item_Type>
        void queue<Item_Type>::push(const Item_Type& item) {
            if (num_items == capacity) {
                throw std::overflow_error("Queue is full");
            }
            rear_index = (rear_index + 1) % capacity;
            the_data[rear_index] = item;
            num_items++;
        }

        // Remove the front item from the queue
        template<typename Item_Type>
        void queue<Item_Type>::pop() {
            if (empty()) {
                throw std::underflow_error("Queue is empty");
            }
            front_index = (front_index + 1) % capacity;
            num_items--;
        }

        // Access the front item of the queue
        template<typename Item_Type>
        Item_Type queue<Item_Type>::front() const {
            if (empty()) {
                throw std::underflow_error("Queue is empty");
            }
            return the_data[front_index];
        }

        // Get the current number of items in the queue
        template<typename Item_Type>
        size_t queue<Item_Type>::size() const {
            return num_items;
        }

        // Check if the queue is empty
        template<typename Item_Type>
        bool queue<Item_Type>::empty() const {
            return num_items == 0;
        }

        // Move the element at the front of the queue to the rear
        template<typename Item_Type>
        void queue<Item_Type>::move_to_rear() {
            if (!empty()) {
                Item_Type front_item = front(); // Get the front item
                pop();                           // Remove the front item
                push(front_item);                // Push it to the rear
            }
        }

    //sorts the queue in ascending order
    template<typename Item_Type>
    void queue<Item_Type>::insertion_sort() {
        int i, j, key;
        bool insertionNeeded = false;

        std::vector<Item_Type> num; 
        while (empty()) {
            num.push_back(front()); 
            pop();
        }
        for (j = 1; j < num.size(); j++) {
            key = num[j];           // Set the current element as the 'key' for comparison
            insertionNeeded = false; // Reset flag for each new key element

            // Move elements of the sorted portion [0..j-1] that are greater than 'key'
            // one position to the right, creating a slot for 'key'
            for (i = j - 1; i >= 0 && num[i] > key; i--) {
                num[i + 1] = num[i];   // Shift element to the right
                insertionNeeded = true; // Mark that an insertion is needed
            }

            // If an insertion was needed, place 'key' into its correct position
            if (insertionNeeded) {
                num[i + 1] = key; // Insert 'key' into its correct location
            }
        }
        for (int i = 0; i < num.size(); i++) 
            push(num[i]);

        }
}

// Searches for a target value in a vector, returns the last found position or -1 if not found.
template<typename Item_Type>
int vector_linear_search(std::vector<Item_Type> v, const Item_Type& target, int current_pos, int last_found);
template<typename Item_Type>
int vector_linear_search(std::vector<Item_Type> v, const Item_Type& target, int current_pos, int last_found) {
    // Base case: no more items to check
    if (current_pos == v.size()) return last_found;


    // Check if the current item matches the target
    if (v[current_pos] == target) {
        last_found = current_pos;  // Update last found position
    }

    // Recursive call: move to the next item
    return vector_linear_search(v, target, current_pos + 1, last_found);
}



