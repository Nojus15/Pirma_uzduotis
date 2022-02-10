#include <iostream>
#include <iomanip>
#include <random>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

struct data
{
    string vardas, pavarde;
    vector<int> paz;
    int egz;
    double rez;
};

void ivestis(data &temp);
void isvedimas(data &temp);
double galutinisVid(vector<int> paz);
double galutinisMed(vector<int> paz);
int enterValidInt();
bool checkMark(int n);
void generateRandomMark(data &temp);
void enterMarkManually(data &temp);
bool modeCheck();
int generateRandomInt();

int main()
{
    srand(time(NULL));

    cout << "Iveskite studentu kieki: ";
    int n = enterValidInt();
    if (n <= 0)
    {
        cout << "Blogas studentu kiekis";
        return 0;
    }

    data *mas = new data[n];
    for (data *i = mas; i < mas + n; i++)
        ivestis(*i);
    cout << endl;

    cout << "Jei norite skaiciuoti vidurki spauskite 1, jei mediana spauskite 0" << endl;
    int rez = modeCheck();

    for (data *i = mas; i < mas + n; i++)
    {
        if (rez == 1)
            i->rez = galutinisVid(i->paz);
        else
            i->rez = galutinisMed(i->paz);
    }
    cout << std::left << std::setw(20) << "Vardas" << std::left << std::setw(20) << "Pavarde";
    if (rez)
        cout << "Galutinis (Vid.)" << endl;
    else
        cout << "Galutinis (Med.)" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
    for (data *i = mas; i < mas + n; i++)
        isvedimas(*i);
}

void ivestis(data &temp)
{
    cout << "Iveskite varda: ";
    cin >> temp.vardas;
    cout << "Iveskite pavarde: ";
    cin >> temp.pavarde;
    cout << "Jei norite egzamino rezultata ivesti ranka spauskite 1, jei generuoti automatiskai spauskite 0" << endl;
    bool mode = modeCheck();
    if (mode)
    {
        cout << "Iveskite egzamino ivertinima: ";
        while (true)
        {
            int egz = enterValidInt();
            if (checkMark(egz))
            {
                temp.egz = egz;
                break;
            }
        }
    }
    else
        temp.egz = generateRandomInt();

    ////////// pazymiu vedimas ///////////
    cout << "Jei norite pazymius ivesti ranka spauskite 1, jei generuoti automatiskai spauskite 0" << endl;
    mode = modeCheck();
    if (mode)
        enterMarkManually(temp);
    else
        generateRandomMark(temp);
    cout << "pazymiai suvesti" << endl;
}
void isvedimas(data &temp)
{
    cout << std::left << std::setw(20) << temp.vardas << std::left << std::setw(20) << temp.pavarde;
    cout << std::setprecision(2) << temp.rez * 0.4 + temp.egz * 0.6 << endl;
    for (int i = 0; i < temp.paz.size(); i++)
    {
        cout << temp.paz[i] << " ";
    }
    cout << endl;
}
double galutinisVid(vector<int> paz)
{
    int sum = 0;
    for (int i = 0; i < paz.size(); i++)
    {
        sum += paz[i];
    }

    return sum / (paz.size() * 1.0);
}
double galutinisMed(vector<int> paz)
{
    sort(paz.begin(), paz.end());
    if (paz.size() % 2 == 0)
    {
        return (paz[paz.size() / 2] + paz[paz.size() / 2 - 1]) * 1.0 / 2;
    }
    else
    {
        return paz[paz.size() / 2];
    }
}
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
void enterMarkManually(data &temp)
{
    cout << "Veskite pazymius. Baige vedima iveskite 0" << endl;

    int t;
    while (true)
    {
        t = enterValidInt();
        if (t == 0)
            break;
        else if (checkMark(t))
            temp.paz.push_back(t);
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
