#include "../headers/generate.h"

void generateRandomMark(data &temp)
{
    cout << "Jei norite generuoti pazymi iveskite 1, jei norite baigti iveskite 0" << endl;
    while (true)
    {
        int run = modeCheck();
        if (run)
        {
            temp.paz.push_back(randomInt(1, 10));
        }
        else
            break;
    }
}
std::stringstream genStudentString(int ndCount)
{
    std::stringstream stud;

    stud << left << setw(20) << randFirstName();
    stud << left << setw(20) << randLastName();
    for (int i = 0; i < ndCount; i++)
        stud << left << setw(7) << randomInt(1, 10);
    stud << left << setw(7) << randomInt(1, 10) << endl;
    return stud;
}

int randomInt(int from, int to)
{
    std::uniform_int_distribution<int> dist(from, to);
    return dist(mt);
}
string randFirstName()
{
    return firstNames[randomInt(0, firstNames.size() - 1)];
}
string randLastName()
{
    return lastNames[randomInt(0, lastNames.size() - 1)];
}