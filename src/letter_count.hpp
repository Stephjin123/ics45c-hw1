// letter_count.hpp
#pragma once
#include <cctype>
#include <iostream>
#include <string>

constexpr int N_CHARS = 26;

// converts a letter to its array index: 'A' or 'a' -> 0, 'B' or 'b' -> 1, ...
inline int char_to_index(char n) {
    unsigned char uc = static_cast<unsigned char>(n);
    return std::toupper(uc) - 'A';
}

// converts an index back to its uppercase letter: 0 -> 'A', 1 -> 'B', ...
inline char index_to_char(int i) {
    return static_cast<char>('A' + i);
}

// given a line and the array of counts, increments the entry for each
// letter in the line, ignoring every character that is not a letter
inline void count(std::string s, int counts[]) {
    for (char c : s) {
        unsigned char uc = static_cast<unsigned char>(c);
        if (std::isalpha(uc)) {
            int idx = char_to_index(c);
            if (idx >= 0 && idx < N_CHARS) {
                counts[idx]++;
            }
        }
    }
}

// writes each letter with its count, one per line, A through Z, to cout
inline void print_counts(int counts[], int len) {
    for (int i = 0; i < len; i++) {
        std::cout << index_to_char(i) << ' ' << counts[i] << '\n';
    }
}
