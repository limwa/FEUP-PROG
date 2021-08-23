#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

time_t time_elapsed() {
    static time_t time_of_first_call = 0;
    if (time_of_first_call == 0)
        time_of_first_call = time(NULL);

    return time(NULL) - time_of_first_call;
}

int main(int, char**) {
    cout << "First call: " << time_elapsed() << endl;
    this_thread::sleep_for(chrono::seconds(2));
    cout << "Second call: " << time_elapsed() << endl;
    this_thread::sleep_for(chrono::seconds(5));
    cout << "Third call: " << time_elapsed() << endl;
    this_thread::sleep_for(chrono::seconds(10));
    cout << "Fourth call: " << time_elapsed() << endl;
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Fifth call: " << time_elapsed() << endl;
}
