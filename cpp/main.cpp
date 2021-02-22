#include <iostream>
#include "reference.h"
// using namespace std;

using std::cout;
using std::endl;
void hello();
int main()
{
    hello();
    testReferenceVariable();
    return 0;
}
void hello()
{
    cout << "Hello World! using static import." << endl;
}