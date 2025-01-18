#include <iostream>
#include "airlines.cpp"

using namespace std;

int main()
{
    airlines bluesky;

    system("CLS");
    cout << "\n   *********************************************" << endl;
    cout << "\t    AIRLINE RESERVATION SYSTEM \n";
    cout << "   *********************************************\n"
         << endl;

    bluesky.menu();

    return 0;
}
