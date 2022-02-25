#include "../headers/validation.h"

using namespace std;

int enterValidInt()
{
    int n;
    while (true)
    {
        cin >> n;
        if (cin.good())
            return n;
        else
        {
            cout << "Ne numeris" << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
    }
}
bool checkMark(int n)
{
    if (n > 0 && n <= 10)
        return true;
    else
    {
        cout << "Blogas pazymys" << endl;
        return false;
    }
}
bool modeCheck()
{
    while (true)
    {
        int mode = enterValidInt();
        if (mode == 1 || mode == 0)
            return mode;
        else
            cout << "Blogas skaicius" << endl;
    }
}