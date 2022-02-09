#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;
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

int main()
{
    int n;
    cout << "Iveskite studentu kieki: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Blogas studentu kiekis";
        return 0;
    }

    data *mas = new data[n];
    for (data *i = mas; i < mas + n; i++)
        ivestis(*i);
    cout << std::endl;
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
    }

    /*for (int i = 0; i < temp.n; i++)
    {
        cout << "Iveskite " << i + 1 << " pazymi: ";
        cin >> temp.paz[i];
    }*/

    cout << "Veskite pazymius. Baige vedima iveskite 0" << std::endl;

    int t;
    while (true)
    {
        cin >> t;
        if (t == 0)
            break;
        else if (t > 0 && t <= 10)
        {
            int *M = new int[temp.n];
            for (int i = 0; i < temp.n; i++)
                M[i] = temp.paz[i];
            delete temp.paz;
            temp.n++;
            temp.paz = new int[temp.n];
            for (int i = 0; i < temp.n - 1; i++)
                temp.paz[i] = M[i];
            temp.paz[temp.n - 1] = t;
            delete M;
        }
        else
            cout << "Blogas pazymys" << std::endl;
    }
    cout << "pazymiai suvesti" << std::endl;
}
void isvedimas(data &temp)
{
    cout << std::setw(20) << temp.vardas << std::setw(20) << temp.pavarde << std::endl;
    for (int i = 0; i < temp.n; i++)
    {
        cout << temp.paz[i] << " ";
    }
    cout << std::endl;
    cout << temp.egz << std::endl;
    cout << std::setprecision(2) << temp.rez << std::endl;
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