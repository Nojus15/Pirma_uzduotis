#include <iostream>
#include <iomanip>
#include <random>

using std::cin;
using std::cout;
using std::endl;
using std::string;

struct data
{
    string vardas, pavarde;
    int n = 0;
    int *paz = nullptr;
    int egz;
    double rez;
};

void ivestis(data &temp);
void isvedimas(data &temp);
double galutinisVid(int *paz, int kiek);
double galutinisMed(int *paz, int kiek);
int enterValidInt();
bool checkMark(int n);
void generateRandomMark(data &temp);
void enterMarkManually(data &temp);
void addNewMark(data &temp, int mark);
bool modeCheck();
int generateRandomInt();

int main()
{
    srand(time(NULL));

    data *studentai = nullptr;

    int studKiek = 0;
    while (true)
    {
        cout << "Jei norite ivesti studenta spauskite 1, jei norite baigti spauskite 0" << endl;
        bool run = modeCheck();
        if (!run)
            break;
        else
        {
            studKiek++;
            data temp;
            ivestis(temp);
            data *newStudentai = new data[studKiek - 1];
            for (int i = 0; i < studKiek - 1; i++)
                newStudentai[i] = studentai[i];
            delete[] studentai;
            studentai = new data[studKiek];
            for (int i = 0; i < studKiek - 1; i++)
                studentai[i] = newStudentai[i];
            studentai[studKiek - 1] = temp;
            delete[] newStudentai;
        }
    }
    cout << "Jei norite skaiciuoti vidurki spauskite 1, jei mediana spauskite 0" << endl;
    int rez = modeCheck();

    for (data *i = studentai; i < studentai + studKiek; i++)
    {
        if (rez == 1)
            i->rez = galutinisVid(i->paz, i->n);
        else
            i->rez = galutinisMed(i->paz, i->n);
    }
    cout << std::left << std::setw(20) << "Vardas" << std::left << std::setw(20) << "Pavarde";
    if (rez)
        cout << "Galutinis (Vid.)" << endl;
    else
        cout << "Galutinis (Med.)" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
    for (data *i = studentai; i < studentai + studKiek; i++)
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
    for (int i = 0; i < temp.n; i++)
    {
        cout << temp.paz[i] << " ";
    }
    cout << endl;
}
double galutinisVid(int *paz, int kiek)
{
    int sum = 0;
    for (int i = 0; i < kiek; i++)
    {
        sum += paz[i];
    }

    return sum / (kiek * 1.0);
}
double galutinisMed(int paz[], int kiek)
{
    for (int i = 0; i < kiek; i++) // ciklas sudedantis skaicius i variacine eilute
    {
        for (int j = 0; j < kiek; j++)
        {
            if (paz[i] < paz[j])
            {
                int t = paz[i];
                paz[i] = paz[j];
                paz[j] = t;
                j--;
            }
        }
    }
    if (kiek % 2 == 0)
    {
        return (paz[kiek / 2] + paz[kiek / 2 - 1]) * 1.0 / 2;
    }
    else
    {
        return paz[kiek / 2];
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
            addNewMark(temp, generateRandomInt());
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
            addNewMark(temp, t);
    }
}
void addNewMark(data &temp, int mark)
{
    int *M = new int[temp.n];
    for (int i = 0; i < temp.n; i++)
        M[i] = temp.paz[i];
    delete temp.paz;
    temp.n++;
    temp.paz = new int[temp.n];
    for (int i = 0; i < temp.n - 1; i++)
        temp.paz[i] = M[i];
    temp.paz[temp.n - 1] = mark;
    delete M;
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
