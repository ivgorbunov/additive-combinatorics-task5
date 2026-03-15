#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

int get_add(std::vector<int> &a, bool print = false) {
    std::set<int> b;
    for (auto v : a) {
        for (auto u : a) {
            b.insert(v + u);
        }
    }
    if (print) {
        for (auto v : b) {
            std::cout << v << ", ";
        }
    }
    return b.size();
}

int get_sub(std::vector<int> &a, bool print = false) {
    std::set<int> b;
    for (auto v : a) {
        for (auto u : a) {
            b.insert(v - u);
        }
    }
    if (print) {
        for (auto v : b) {
            std::cout << v << ", ";
        }
    }
    return b.size();
}

std::vector<int> arr;

void gen(int n) {
    if (n == -1) {
        if (get_add(arr) > get_sub(arr)) {
            std::cout << "Gotcha!\n";
            std::cout << "$$A = ";
            std::reverse(arr.begin(), arr.end());
            for (auto v : arr) {
                std::cout << v << ", ";
            }
            std::cout << "$$\n";
            std::cout << "$$A + A = " << "\\{ "; get_add(arr, true); std::cout << "\\} $$\n";
            std::cout << "$$|A + A| = " << get_add(arr, false) << "$$\n";
            std::cout << "$$A - A = " << "\\{ "; get_sub(arr, true); std::cout << "\\} $$\n";
            std::cout << "$$|A - A| = " << get_sub(arr, false) << "$$\n";
            exit(0);
        }
        return;
    }
    gen(n - 1);
    arr.push_back(n);
    gen(n - 1);
    arr.pop_back();
}

int main() {
    gen(20);
}