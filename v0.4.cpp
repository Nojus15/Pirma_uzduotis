#include "headers/validation.h"
#include "headers/inOut.h"
#include "headers/rezCalc.h"
#include "headers/generate.h"
#include "headers/data.h"

bool egz;
bool paz;
bool rez;
bool manual;

int main()
{
    auto programStart = hrClock::now();
    vector<data> studentai;

    cout << "Ar norite generuoti faila? Jei taip, iveskite 1, jei ne - 0" << endl;
    bool gen = modeCheck();
    string genFile_name;
    if (gen)
    {
        cin.ignore();
        cout << "Koks turetu buti failo pavadinimas?(studentai.txt by default): ";
        getline(cin, genFile_name);
        genFile_name.empty() ? genFile_name = "studentai.txt" : genFile_name += ".txt";
        cout << "Kiek generuoti studentų?" << endl;
        int studCount;
        studCount = enterValidInt();
        cout << "Kiek generuoti namu darbu?" << endl;
        int ndCount;
        ndCount = enterValidInt();
        genFile(studCount, genFile_name, ndCount);
        manual = false;
    }
    else
    {
        cout << "Jei norite rasyti pats spauskite 1, jei skaityti is failo spauskite 0" << endl;
        manual = modeCheck();
    }

    if (!manual)
    {
        bufer_read(studentai, gen, genFile_name);

        calcRez(studentai, rez, manual);
        std::stringstream kietiakai;
        std::stringstream vargsai;
        sortStudents(kietiakai, vargsai, studentai);

        auto newWrite = hrClock::now();
        ssToFile("kietiakai.txt", kietiakai);
        ssToFile("vargsai.txt", vargsai);
        cout << "Surusiuotu studentu isvedimas i naujus failus uztruko: " << durationDouble(hrClock::now() - newWrite).count() << endl;
    }
    else
    {
        cout << "Jei norite skaiciuoti vidurki spauskite 1, jei mediana spauskite 0" << endl;
        rez = modeCheck();
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

        calcRez(studentai, rez, manual);
        std::sort(studentai.begin(), studentai.end(), [](data &a, data &b)
                  { return a.vardas < b.vardas; });

        bufer_write("rez.txt", studentai, manual, rez);
    }
    cout << "Visos programos veikimo laikas: " << durationDouble(hrClock::now() - programStart).count() << endl;
}
