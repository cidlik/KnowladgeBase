#include <iostream>
#include <vector>


void print_array(int *p, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << p[i] << " ";
    }
    std::cout << std::endl;
}


int main() {
    std::vector<int> v {1, 2, 3};
    std::cout << v[0] << std::endl;
    return 0;
}
