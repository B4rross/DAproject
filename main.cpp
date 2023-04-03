#include <iostream>
#include "CPheadquarters.h"

using namespace std;
int main() {
    CPheadquarters CP;
    CP.read_files();
    CP.getLines().print();


    return 1;
}
