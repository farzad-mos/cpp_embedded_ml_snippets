// Smart Pointer (RAII)
#include <memory>
std::unique_ptr<int> ptr = std::make_unique<int>(42);

// Range-based for loop
std::vector<int> v = {1, 2, 3};
for (int x : v) {
    std::cout << x << std::endl;
}

// Const correctness
void print(const std::string& msg) {
    std::cout << msg << std::endl;
}

// Inline functions for performance
inline int add(int a, int b) {
    return a + b;
}