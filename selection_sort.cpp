#include <iostream>
#include <utility>
#include <vector>

// Sorts the vector in ascending order using selection sort.
// Each outer loop places the smallest remaining value at index i.
void selection_sort(std::vector<int>& v) {
    int n = static_cast<int>(v.size());

    for (int i = 0; i < n; i++) {
        int min_index = i;

        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[min_index]) {
                min_index = j;
            }
        }

        std::swap(v[i], v[min_index]);
    }
}

void print_vector(const std::vector<int>& v) {
    for (int value : v) {
        std::cout << value << ' ';
    }

    std::cout << '\n';
}

int main() {
    std::vector<int> values{5, 3, 6, 2, 10};

    selection_sort(values);
    print_vector(values);

    return 0;
}
