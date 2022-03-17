#include "../headers/generate.h"

int generateRandomInt()
{
    return 1 + rand() % 10;
}
void generateRandomMark(data &temp)
{
    cout << "Jei norite generuoti pazymi iveskite 1, jei norite baigti iveskite 0" << endl;
    while (true)
    {
        int run = modeCheck();
        if (run)
        {
            temp.paz.push_back(generateRandomInt());
        }
        else
            break;
    }
}
data genStudent()
{
    data a;

    cout << randomInt(0, 9) << " ";

    a.vardas = randFirstName();
    a.pavarde = randLastName();
    int n = randomInt(5, 10);
    for (int i = 0; i < n; i++)
        a.paz.push_back(randomInt(1, 10));

    a.egz = randomInt(1, 10);
    return a;
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