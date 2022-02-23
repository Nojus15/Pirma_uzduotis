#include <iostream>
#include <fstream>
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
void isvedimas(data &temp, std::ofstream &fout);
double galutinisVid(vector<int> paz);
double galutinisMed(vector<int> paz);
int enterValidInt();
bool checkMark(int n);
void generateRandomMark(data &temp);
void enterMarkManually(data &temp);
bool modeCheck();
int generateRandomInt();

bool egz;
bool paz;
bool rez;

int main()
{
    srand(time(NULL));

    cout << "Jei norite rasyti pats spauskite 1, jei skaityti is failo spauskite 0" << endl;
    bool manual = modeCheck();
    cout << "Jei norite skaiciuoti vidurki spauskite 1, jei mediana spauskite 0" << endl;
    rez = modeCheck();

    vector<string> length;

    vector<data> studentai;

    std::ofstream fout("rez.txt");

    if (!manual)
    {
        std::ifstream fin("studentai.txt");
        string t;
        while ((fin.peek() != '\n') && (fin >> t))
            length.push_back(t);
        length.resize(length.size() - 3);
        cout << length.size() << endl;

        while (!fin.eof())
        {
            int p;
            data t;
            fin >> t.vardas >> t.pavarde;
            for (auto &el : length)
            {
                fin >> p;
                t.paz.push_back(p);
            }
            fin >> t.egz;
            studentai.push_back(t);
        }
        cout << studentai.size() << endl;
    }
    else
    {
        cout << "Jei norite egzamino rezultata ivesti ranka spauskite 1, jei generuoti automatiskai spauskite 0" << endl;
        egz = modeCheck();
        cout << "Jei norite pazymius ivesti ranka spauskite 1, jei generuoti automatiskai spauskite 0" << endl;
        paz = modeCheck();

        while (true)
        {
            cout << "Jei norite ivesti studenta spauskite 1, jei norite baigti spauskite 0" << endl;
            bool run = modeCheck();
            if (!run)
                break;
            else
            {
                data temp;
                ivestis(temp);
                studentai.push_back(temp);
            }
        }
    }
    for (auto &el : studentai)
    {
        if (rez == 1)
            el.rez = galutinisVid(el.paz);
        else
            el.rez = galutinisMed(el.paz);
    }
    fout << std::left << std::setw(20) << "Vardas" << std::left << std::setw(20) << "Pavarde";
    if (rez)
        fout << "Galutinis (Vid.)" << endl;
    else
        fout << "Galutinis (Med.)" << endl;
    fout << "-------------------------------------------------------------------------------------------------------------------" << endl;
    for (auto &el : studentai)
        isvedimas(el, fout);
}

void ivestis(data &temp)
{
    cout << "Iveskite varda: ";
    cin >> temp.vardas;
    cout << "Iveskite pavarde: ";
    cin >> temp.pavarde;

    if (egz)
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
    if (paz)
        enterMarkManually(temp);
    else
        generateRandomMark(temp);
    cout << "pazymiai suvesti" << endl;
}
void isvedimas(data &temp, std::ofstream &fout)
{
    fout << std::left << std::setw(20) << temp.vardas << std::left << std::setw(20) << temp.pavarde;
    fout << std::setprecision(2) << temp.rez * 0.4 + temp.egz * 0.6 << endl;
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
