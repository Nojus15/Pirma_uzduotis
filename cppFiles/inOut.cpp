#include "../headers/inOut.h"

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
        fout << std::left << std::setw(20) << std::setprecision(2) << temp.vid << std::left << std::setw(20) << std::setprecision(2) << temp.med;
    else if (rez)
        fout << std::left << std::setw(20) << std::setprecision(2) << temp.vid;
    else if (!rez)
        fout << std::left << std::setw(20) << std::setprecision(2) << temp.med;

    fout << "   ";
    for (auto &paz : temp.paz)
        fout << paz << " ";

    fout << endl;
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