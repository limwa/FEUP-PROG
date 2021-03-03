#include <iostream>
#include <limits>

using namespace std;

int main(int, char**) {
    int h1, m1, s1, h2, m2, s2;

    while (true) {
        cout << "Time1 (hours minutes seconds) ? " << flush;
        cin >> h1 >> m1 >> s1;

        if (!cin.fail())
            break;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    while (true) {
        cout << "Time2 (hours minutes seconds) ? " << flush;
        cin >> h2 >> m2 >> s2;

        if (!cin.fail())
            break;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    cout << endl;

    int seconds = s1 + s2;
    int minutes = m1 + m2;
    int hours = h1 + h2;
    int days = 0;

    minutes += seconds / 60;
    seconds %= 60;

    hours += minutes / 60;
    minutes %= 60;

    days += hours / 24;
    hours %= 24;

    cout << "Time1 + Time2 = ";
    if (days > 0) {
        cout << days;
        if (days == 1)
            cout << " day ";
        else
            cout << " days ";
    }

    if (hours > 0) {
        cout << hours;
        if (hours == 1)
            cout << " hour ";
        else
            cout << " hours ";
    }

    if (minutes > 0) {
        cout << minutes;
        if (minutes == 1)
            cout << " minute ";
        else
            cout << " minutes ";
    }

    if (seconds > 0) {
        cout << seconds;
        if (seconds == 1)
            cout << " second";
        else
            cout << " seconds";
    }

    cout << endl;
}
