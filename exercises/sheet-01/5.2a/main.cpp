#include <iostream>
#include <vector>
#include <functional>
#include "limwa.h"

using namespace std;

void bubble_sort(vector<string> &v, char order) {
    function<bool(string, string)> comparator;

    if (order == 'a') {
        comparator = [] (auto s1, auto s2) {
            return s1 < s2;
        };
    } else if (order == 'd') {
        comparator = [] (auto s1, auto s2) {
            return s1 > s2;
        };
    } else
        return;

    bool has_changed;
    do {
        has_changed = false;

        for (size_t i = 0; i < v.size() - 1; i++) {
            if (!comparator(v.at(i), v.at(i + 1))) {
                string temp = v.at(i);
                v.at(i) = v.at(i + 1);
                v.at(i + 1) = temp;

                has_changed = true;
            }
        }
    } while (has_changed);
}

int main(int, char**) {
    vector<string> vec = { "hello", "geronimo", "feup", "prog" };
    char order = 'a'; // or 'd'

    bubble_sort(vec, 'a');
    for (auto s : vec) {
        cout << s << ' ';
    }

    cout << endl;
}
