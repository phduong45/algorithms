#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>

// Returns true when any value appears at least twice.
bool has_duplicate(const std::vector<int>& v) {
    std::unordered_set<int> seen;

    for (int value : v) {
        if (seen.find(value) != seen.end()) {
            return true;
        }

        seen.insert(value);
    }

    return false;
}

// Counts how many times each value appears.
std::unordered_map<int, int> frequency_count(const std::vector<int>& v) {
    std::unordered_map<int, int> freq;

    for (int value : v) {
        freq[value] += 1;
    }

    return freq;
}

int main() {
    std::vector<int> values{3, 5, 2, 5};

    std::cout << std::boolalpha;
    std::cout << "has_duplicate = " << has_duplicate(values) << '\n';

    auto freq = frequency_count(values);
    for (const auto& [value, count] : freq) {
        std::cout << value << " -> " << count << '\n';
    }

    return 0;
}
