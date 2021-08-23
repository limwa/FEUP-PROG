#include <iostream>
#include <vector>

using namespace std;

void remove_duplicates(vector<int> &v) {
    for (size_t i = 0; i < v.size(); i++) {
        int elem = v.at(i);
        for (size_t j = i + 1; j < v.size(); j++) {
            if (v.at(j) == elem) {
                for (size_t k = j + 1; k < v.size(); k++) {
                    v.at(k - 1) = v.at(k);
                }

                v.resize(v.size() - 1);
            }
        }
    }
}

int main(int, char**) {
    vector<int> v = { 7, 2, 3, 4, 1, 4, 5, 3, 2, 1, 0, -1 };
    remove_duplicates(v);

    for (auto elem : v)
        cout << elem << ' ';

    cout << endl;
}
