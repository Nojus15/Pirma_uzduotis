#include "../headers/rezCalc.h"
#include <algorithm>
#include <iterator>

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
bool isVargsas(data a)
{
    if (a.med < 5 || a.vid < 5)
        return true;
    return false;
}
void sortStudents2(vector<data> &kietiakai, vector<data> &vargsai)
{
    auto sortStart = hrClock::now();
    copy_if(kietiakai.begin(), kietiakai.end(), back_inserter(vargsai), isVargsas);
    kietiakai.erase(remove_if(kietiakai.begin(), kietiakai.end(), isVargsas), kietiakai.end());
    cout << "Studentu dalinimo i dvi grupes laikas: " << durationDouble(hrClock::now() - sortStart).count() << " s" << endl;
}
void sortStudents2(list<data> &kietiakai, list<data> &vargsai)
{
    auto sortStart = hrClock::now();
    copy_if(kietiakai.begin(), kietiakai.end(), back_inserter(vargsai), isVargsas);
    kietiakai.erase(remove_if(kietiakai.begin(), kietiakai.end(), isVargsas), kietiakai.end());
    cout << "Studentu dalinimo i dvi grupes laikas: " << durationDouble(hrClock::now() - sortStart).count() << " s" << endl;
}
void sortStudents2(deque<data> &kietiakai, deque<data> &vargsai)
{
    auto sortStart = hrClock::now();
    copy_if(kietiakai.begin(), kietiakai.end(), back_inserter(vargsai), isVargsas);
    kietiakai.erase(remove_if(kietiakai.begin(), kietiakai.end(), isVargsas), kietiakai.end());
    cout << "Studentu dalinimo i dvi grupes laikas: " << durationDouble(hrClock::now() - sortStart).count() << " s" << endl;
}
void sortStudents(vector<data> &kietiakai, vector<data> &vargsai, vector<data> &studentai)
{
    auto sortStart = hrClock::now();
    for (auto &stud : studentai)
    {
        if (stud.vid < 5 || stud.med < 5)
        {
            vargsai.push_back(stud);
        }
        else
        {
            kietiakai.push_back(stud);
        }
    }
    studentai.clear();
    cout << "Studentu dalinimo i dvi grupes laikas: " << durationDouble(hrClock::now() - sortStart).count() << " s" << endl;
}

void sortStudents(list<data> &kietiakai, list<data> &vargsai, list<data> &studentai)
{
    auto sortStart = hrClock::now();
    for (auto &stud : studentai)
    {
        if (stud.vid < 5 || stud.med < 5)
        {
            vargsai.push_back(stud);
        }
        else
        {
            kietiakai.push_back(stud);
        }
    }
    studentai.clear();
    cout << "Studentu dalinimo i dvi grupes laikas: " << durationDouble(hrClock::now() - sortStart).count() << " s" << endl;
}
void sortStudents(deque<data> &kietiakai, deque<data> &vargsai, deque<data> &studentai)
{
    auto sortStart = hrClock::now();
    for (auto &stud : studentai)
    {
        if (stud.vid < 5 || stud.med < 5)
        {
            vargsai.push_back(stud);
        }
        else
        {
            kietiakai.push_back(stud);
        }
    }
    studentai.clear();
    cout << "Studentu dalinimo i dvi grupes laikas: " << durationDouble(hrClock::now() - sortStart).count() << " s" << endl;
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
void calcRez(list<data> &studentai, bool rez, bool manual)
{
    for (auto &el : studentai)
    {
        if (rez || !manual)
            el.vid = galutinisVid(el.paz, el.egz);
        if (!rez || !manual)
            el.med = galutinisMed(el.paz, el.egz);
    }
}
void calcRez(deque<data> &studentai, bool rez, bool manual)
{
    for (auto &el : studentai)
    {
        if (rez || !manual)
            el.vid = galutinisVid(el.paz, el.egz);
        if (!rez || !manual)
            el.med = galutinisMed(el.paz, el.egz);
    }
}