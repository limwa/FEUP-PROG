#include <iostream>
#include <math.h>

#define PI 3.14159265

using namespace std;

int main(int, char**) {
    cout << "ang\t  sin   \t  cos   \t  tan" << endl;
    
    cout << fixed;
    cout.precision(6);
    for (int angle = 0; angle <= 90; angle += 15) {
        double rads = angle * PI / 180;
        cout << angle << '\t' << sin(rads) << '\t' << cos(rads) << '\t';
        if ((angle - 90) % 180 == 0)
            cout << "infinite";
        else
            cout << tan(rads);

        cout << endl;
    }

    return 0;
}
