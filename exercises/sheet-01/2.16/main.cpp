#include "ansi.h"

using namespace std;
using namespace ansi;

int main(int, char**) {
    cout << "hello " << foreground_color(250, 195, 241) << "there" << endl;
}