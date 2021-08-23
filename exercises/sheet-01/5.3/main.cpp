#include <iostream>
#include <cstring>

using namespace std;

int compare(const void* s1, const void* s2) {
    return strcmp(*(const char**) s1, *(const char**) s2);
}

int main(int, char**) {
    const char* arr[] = { "Andre", "Maria", "Joana", "Luisa", "Mario" };
    qsort(arr, 5, sizeof(const char *), compare);

    for (size_t i = 0; i < 5; i++) {
        cout << arr[i] << ' ';
    }

    cout << endl;
}
