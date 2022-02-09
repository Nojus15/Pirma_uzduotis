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

int main()
{
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
    for (data *i = mas; i < mas + n; i++)
        i->rez = galutinisMed(i->paz, i->n);
    for (data *i = mas; i < mas + n; i++)
        isvedimas(*i);
}

void ivestis(data &temp)
{
    cout << "Iveskite varda: ";
    cin >> temp.vardas;
    cout << "Iveskite pavarde: ";
    cin >> temp.pavarde;
    cout << "Iveskite egzamino ivertinima: ";
    while (true)
    {
        cin >> temp.egz;
        if (temp.egz > 0 && temp.egz <= 10)
            break;
        else
            cout << "Blogas egzamino pazymys" << endl;
    }
    cout << "Jei norite ivesti pazymius rankom spauskite 1, jei norite generuoti automatiskai spauskite 0" << endl;
    int mode;
    while (true)
    {
        mode = enterValidInt();
        if (mode == 1 || mode == 0)
            break;
        else
            cout << "Blogas skaicius" << endl;
    }

    if (mode)
        enterMarkManually(temp);
    else
        generateRandomMark(temp);
    cout << "pazymiai suvesti" << endl;
}
void isvedimas(data &temp)
{
    cout << std::setw(20) << temp.vardas << std::setw(20) << temp.pavarde << endl;
    for (int i = 0; i < temp.n; i++)
    {
        cout << temp.paz[i] << " ";
    }
    cout << endl;
    cout << temp.egz << endl;
    cout << std::setprecision(2) << temp.rez << endl;
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
void generateRandomMark(data &temp)
{
    srand(time(NULL));
    cout << "Jei norite generuoti pazymi spauskite 1, jei norite baigti spauskite 0" << endl;
    int run;
    while (true)
    {
        run = enterValidInt();
        if (run == 1)
        {
            int newMark = 1 + rand() % 10;
            addNewMark(temp, newMark);
        }
        else if (run == 0)
            break;
        else
            cout << "Blogas skaicius" << endl;
    }

    1 + rand() % 10;
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