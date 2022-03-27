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
int validMode(int from, int to)
{
    while (true)
    {
        int mode = enterValidInt();
        for (int i = from; i <= to; i++)
            if (mode == i)
                return mode;
        cout << "Blogas skaicius" << endl;
    }
}