#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

const size_t MB = 1024 * 1024; // Define 1 MB as 1024 * 1024 bytes

void allocateMemory(std::vector<char *> &allocatedMemory)
{
    try
    {
        char *block = new char[5 * MB];   // Allocate 5 MB
        allocatedMemory.push_back(block); // Store the pointer to the allocated memory
        std::cout << "5 MB of memory allocated." << std::endl;
    }
    catch (std::bad_alloc &e)
    {
        std::cerr << "Memory allocation failed: " << e.what() << std::endl;
    }
}

int main()
{
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::vector<char *> allocatedMemory; // Vector to keep track of allocated memory blocks
    const int numAllocations = 1;       // Number of times to allocate 5 MB

    for (int i = 0; i < numAllocations; ++i)
    {
        allocateMemory(allocatedMemory);
    }

    std::this_thread::sleep_for(std::chrono::seconds(10));
    std::cout << "All allocated memory has NOT been freed." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));

    return 0;
}
