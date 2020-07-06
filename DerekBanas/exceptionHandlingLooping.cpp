#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <regex>
#include <iterator>
#include <unordered_set>
#include <cmath>
#include <queue>
#include <sstream>

using namespace std;

int main() {
    double num1 = 0, num2 = 0;
    std::cin >> num1;
    std::cin >> num2;

    try {
        if (num2 == 0) {
            throw "Division by zero is not possilbe";
        }
        else {
            printf("%.1f / %.1f = %.2f", num1, num2, (num1 / num2));
        }
    }

    catch (const char* exp) {
        std::cout << "Error : " << exp << "\n";
    }

    return 0;
}

    // exp.what()
    // catch(...) catch all!    
    // std::runtime_error("")