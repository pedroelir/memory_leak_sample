#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

const size_t MB = 1024 * 1024; // Define 1 MB as 1024 * 1024 bytes

void allocateMemory(std::vector<char *> &allocatedMemory)
{
    try
    {
        char *block = new char[1 * MB];   // Allocate 1 MB
        std::fill(block, block + 1 * MB, '0');
        allocatedMemory.push_back(block); // Store the pointer to the allocated memory
        std::cout << "1 MB of memory allocated." << std::endl;
    }
    catch (std::bad_alloc &e)
    {
        std::cerr << "Memory allocation failed: " << e.what() << std::endl;
    }
}

int main()
{
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::vector<char *> allocatedMemory; // Vector to keep track of allocated memory blocks
    const int numAllocations = 5;       // Number of times to allocate 5 MB

    for (int i = 0; i < numAllocations; ++i)
    {
        allocateMemory(allocatedMemory);
    }

    std::this_thread::sleep_for(std::chrono::seconds(10));
    // Free the allocated memory
    for (char *block : allocatedMemory)
    {
        delete[] block;
    }
    std::cout << "All allocated memory has been freed." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));

    return 0;
}
