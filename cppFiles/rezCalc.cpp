#include "../headers/rezCalc.h"

double galutinisVid(vector<int> paz, int egz)
{
    double sum = 0;
    for (auto &el : paz)
    {
        sum += el;
    }
    if (paz.size() != 0)
        return sum / (paz.size() * 1.0) * 0.4 + egz * 0.6;
    else
        return egz * 0.6;
}
double galutinisMed(vector<int> paz, int egz)
{
    sort(paz.begin(), paz.end());
    if (paz.size() % 2 == 0 && paz.size() != 0)
    {
        return (paz[paz.size() / 2] + paz[paz.size() / 2 - 1]) * 1.0 / 2;
    }
    else if (paz.size() % 2 != 0 && paz.size() != 0)
    {
        return paz[paz.size() / 2] * 0.4 + egz * 0.6;
    }
    else
        return egz * 0.6;
}
void sortStudents(std::stringstream &kietiakai, std::stringstream &vargsai, vector<data> &studentai)
{
    auto sortStart = hrClock::now();
    for (auto &stud : studentai)
    {
        if (stud.vid < 5)
        {
            vargsai << left << setw(20) << stud.vardas;
            vargsai << left << setw(20) << stud.pavarde;
            vargsai << left << setw(20) << stud.vid;
            vargsai << left << setw(20) << stud.med;
            vargsai << endl;
        }
        else
        {
            kietiakai << left << setw(20) << stud.vardas;
            kietiakai << left << setw(20) << stud.pavarde;
            kietiakai << left << setw(20) << stud.vid;
            kietiakai << left << setw(20) << stud.med;
            kietiakai << endl;
        }
    }
    studentai.clear();
    cout << "Studentu dalinimo i dvi grupes laikas: " << durationDouble(hrClock::now() - sortStart).count() << endl;
}
void calcRez(vector<data> &studentai, bool rez, bool manual)
{
    for (auto &el : studentai)
    {
        if (rez || !manual)
            el.vid = galutinisVid(el.paz, el.egz);
        if (!rez || !manual)
            el.med = galutinisMed(el.paz, el.egz);
    }
}