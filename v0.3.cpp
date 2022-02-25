#include "headers/data.h"
#include "headers/validation.h"
#include "headers/inOut.h"
#include "headers/rezCalc.h"

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
