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
    cout << "Ar norite generuoti failus? Jei taip, iveskite 1, jei ne - 0" << endl;
    bool gen = validMode(0, 1);
    if (gen)
    {
        for (int i = 1000; i <= 10000000; i *= 10)
        {
            genFile(i, "studentai" + std::to_string(i) + ".txt", randomInt(10, 20));
        }
        return 0;
    }
    else
    {
        cout << "Jei norite rasyti pats spauskite 1, jei skaityti is failo spauskite 0" << endl;
        manual = validMode(0, 1);
    }

    if (!manual)
    {
        cout << "Pasirinkite konteinerio tipa: 1 - vector, 2 - list, 3 - deque" << endl;
        int contType = validMode(1, 3);
        std::stringstream kietiakai;
        std::stringstream vargsai;
        if (contType == 1)
        {
            vector<data> studentai;
            bufer_read(studentai, gen, "studentai1000.txt");
            calcRez(studentai, rez, manual);
            sortStudents(kietiakai, vargsai, studentai);
        }
        else if (contType == 2)
        {
            list<data> studentai;
            bufer_read(studentai, gen, "studentai1000.txt");
            calcRez(studentai, rez, manual);
            sortStudents(kietiakai, vargsai, studentai);
        }
        else if (contType == 3)
        {
            deque<data> studentai;
            bufer_read(studentai, gen, "studentai1000.txt");
            calcRez(studentai, rez, manual);
            sortStudents(kietiakai, vargsai, studentai);
        }
        auto newWrite = hrClock::now();
        ssToFile("kietiakai.txt", kietiakai);
        ssToFile("vargsai.txt", vargsai);
        cout << "Surusiuotu studentu isvedimas i naujus failus uztruko: " << durationDouble(hrClock::now() - newWrite).count() << " s" << endl;
    }
    else
    {
        vector<data> studentai;
        cout << "Jei norite skaiciuoti vidurki spauskite 1, jei mediana spauskite 0" << endl;
        rez = validMode(0, 1);
        cout << "Jei norite egzamino rezultata ivesti ranka spauskite 1, jei generuoti automatiskai spauskite 0" << endl;
        egz = validMode(0, 1);
        cout << "Jei norite pazymius ivesti ranka spauskite 1, jei generuoti automatiskai spauskite 0" << endl;
        paz = validMode(0, 1);

        while (true)
        {
            cout << "Jei norite ivesti studenta spauskite 1, jei norite baigti spauskite 0" << endl;
            bool run = validMode(0, 1);
            if (!run)
                break;
            else
            {
                data temp;
                ivestis(temp);
                studentai.push_back(temp);
            }
        }

        // calcRez(studentai, rez, manual);
        // std::sort(studentai.begin(), studentai.end(), [](data &a, data &b)
        //           { return a.vardas < b.vardas; });

        // bufer_write("rez.txt", studentai, manual, rez);
    }
    cout << "Visos programos veikimo laikas: " << durationDouble(hrClock::now() - programStart).count() << " s" << endl;
    cout << "-------------------------" << endl;
}
