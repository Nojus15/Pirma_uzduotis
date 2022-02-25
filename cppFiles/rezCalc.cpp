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