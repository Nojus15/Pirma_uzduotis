#include <iostream>
#include <fstream>
#include <iomanip>
#include <random>
#include <vector>
#include <algorithm>
#include <functional>

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
    double vid;
    double med;
};

void ivestis(data &temp);
void isvedimas(data &temp, std::ofstream &fout);
double galutinisVid(vector<int> paz, int egz);
double galutinisMed(vector<int> paz, int egz);
int enterValidInt();
bool checkMark(int n);
void generateRandomMark(data &temp);
void enterMarkManually(data &temp);
bool modeCheck();
int generateRandomInt();
void read(std::ifstream &fin, std::vector<string> &length, std::vector<data> &studentai);

bool egz;
bool paz;
bool rez;
bool manual;

int main()
{
    srand(time(NULL));

    cout << "Jei norite rasyti pats spauskite 1, jei skaityti is failo spauskite 0" << endl;
    manual = !modeCheck();
    cout << "Jei norite skaiciuoti vidurki spauskite 1, jei mediana spauskite 0" << endl;
    rez = modeCheck();

    vector<string> length;

    vector<data> studentai;

    std::ofstream fout("rez.txt");

    if (manual)
    {
        std::ifstream fin("studentai.txt");
        read(fin, length, studentai);
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
        if (rez || manual)
            el.vid = galutinisVid(el.paz, el.egz);
        if (!rez || manual)
            el.med = galutinisMed(el.paz, el.egz);
    }

    std::sort(studentai.begin(), studentai.end(), [](data &a, data &b)
              { return a.vardas < b.vardas; });

    fout << std::left << std::setw(20) << "Vardas" << std::left << std::setw(20) << "Pavarde";
    if (rez || manual)
        fout << std::left << std::setw(20) << "Galutinis (Vid.)";
    if (!rez || manual)
        fout << std::left << std::setw(20) << "Galutinis (Med.)";
    fout << endl;
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
    if (manual)
        fout << std::left << std::setw(20) << std::setprecision(2) << temp.vid << std::left << std::setw(20) << std::setprecision(2) << temp.med << endl;
    else if (rez)
        fout << std::left << std::setw(20) << std::setprecision(2) << temp.vid << endl;
    else if (!rez)
        fout << std::left << std::setw(20) << std::setprecision(2) << temp.med << endl;
}
double galutinisVid(vector<int> paz, int egz)
{
    double sum = 0;
    for (auto &el : paz)
    {
        sum += el;
    }

    return sum / (paz.size() * 1.0) * 0.4 + egz * 0.6;
}
double galutinisMed(vector<int> paz, int egz)
{
    sort(paz.begin(), paz.end());
    if (paz.size() % 2 == 0)
    {
        return (paz[paz.size() / 2] + paz[paz.size() / 2 - 1]) * 1.0 / 2;
    }
    else
    {
        return paz[paz.size() / 2] * 0.4 + egz * 0.6;
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
void read(std::ifstream &fin, std::vector<string> &length, std::vector<data> &studentai)
{
    string t;
    while ((fin.peek() != '\n') && (fin >> t))
        length.push_back(t);
    length.resize(length.size() - 3);

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
}