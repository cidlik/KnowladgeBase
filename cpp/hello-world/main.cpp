#include <iostream>


int main() {
    std::cout << "Hello World!" << std::endl;
    printf("Hello World!\n");
    fprintf(stdout, "Hello World!\n");

    float pi = 3.14;
    std::cout << "Pi ~= " << pi << std::endl;
    printf("Pi ~= %.2f\n", pi);
    return 0;
}
