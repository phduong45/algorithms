#include <iostream>
#include <vector>

// Returns a sorted copy of v using 3-way quicksort.
// Pivot partitions values into less / equal / greater.
std::vector<int> quicksort(const std::vector<int>& v) {
    if (v.size() <= 1) {
        return v;
    }

    std::vector<int> less{};
    std::vector<int> equal{};
    std::vector<int> greater{};

    int pivot = v[0];

    for (int value : v) {
        if (value < pivot) {
            less.push_back(value);
        } else if (value == pivot) {
            equal.push_back(value);
        } else {
            greater.push_back(value);
        }
    }

    std::vector<int> sorted_less = quicksort(less);
    std::vector<int> sorted_greater = quicksort(greater);

    sorted_less.insert(sorted_less.end(), equal.begin(), equal.end());
    sorted_less.insert(sorted_less.end(), sorted_greater.begin(), sorted_greater.end());

    return sorted_less;
}

void print_vector(const std::vector<int>& v) {
    std::cout << "{ ";

    for (int value : v) {
        std::cout << value << ' ';
    }

    std::cout << "}\n";
}

int main() {
    for (const auto& values : {
             std::vector<int>{5, 3, 8, 1, 2},
             std::vector<int>{2, 2, 2, 2},
             std::vector<int>{},
             std::vector<int>{1},
             std::vector<int>{1, 2, 3, 4, 5},
         }) {
        print_vector(quicksort(values));
    }

    return 0;
}
