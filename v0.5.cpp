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
        string genFile_name;
        cin.ignore();
        cout << "Koks turetu buti failo pavadinimas?(studentai.txt by default): ";
        getline(cin, genFile_name);
        genFile_name.empty() ? genFile_name = "studentai.txt" : genFile_name += ".txt";
        cout << "Kiek generuoti studentu?" << endl;
        int studCount;
        studCount = enterValidInt();
        cout << "Kiek generuoti namu darbu?" << endl;
        int ndCount;
        ndCount = enterValidInt();
        cout << "-------------------------" << endl;
        genFile(studCount, genFile_name, ndCount);
        return 0;
    }
    else
    {
        cout << "Jei norite rasyti pats spauskite 1, jei skaityti is failo spauskite 0" << endl;
        manual = validMode(0, 1);
    }

    if (!manual)
    {
        double fopenTime = 0;
        cout << "Pasirinkite konteinerio tipa: 1 - vector, 2 - list, 3 - deque" << endl;
        int contType = validMode(1, 3);
        if (contType == 1)
        {
            vector<data> studentai;
            vector<data> kietiakai;
            vector<data> vargsai;

            auto programStart = hrClock::now();
            bufer_read(studentai, gen, "studentai1000.txt", fopenTime);
            calcRez(studentai, rez, manual);
            sortStudents(kietiakai, vargsai, studentai);

            std::sort(kietiakai.begin(), kietiakai.end(), [](data &a, data &b)
                      { return a.vardas < b.vardas; });
            std::sort(vargsai.begin(), vargsai.end(), [](data &a, data &b)
                      { return a.vardas < b.vardas; });

            auto newWrite = hrClock::now();
            containerToFile("kietiakai.txt", kietiakai);
            containerToFile("vargsai.txt", vargsai);
            cout << "Surusiuotu studentu isvedimas i naujus failus uztruko: " << durationDouble(hrClock::now() - newWrite).count() << " s" << endl;
            cout << "Visos programos veikimo laikas: " << durationDouble(hrClock::now() - programStart).count() - fopenTime << " s" << endl;
            cout << "-------------------------" << endl;
        }
        else if (contType == 2)
        {
            list<data> studentai;
            list<data> kietiakai;
            list<data> vargsai;

            auto programStart = hrClock::now();
            bufer_read(studentai, gen, "studentai1000.txt", fopenTime);
            calcRez(studentai, rez, manual);
            sortStudents(kietiakai, vargsai, studentai);

            kietiakai.sort(compare);
            vargsai.sort(compare);

            auto newWrite = hrClock::now();
            containerToFile("kietiakai.txt", kietiakai);
            containerToFile("vargsai.txt", vargsai);
            cout << "Surusiuotu studentu isvedimas i naujus failus uztruko: " << durationDouble(hrClock::now() - newWrite).count() << " s" << endl;
            cout << "Visos programos veikimo laikas: " << durationDouble(hrClock::now() - programStart).count() - fopenTime << " s" << endl;
            cout << "-------------------------" << endl;
        }
        else if (contType == 3)
        {
            deque<data> studentai;
            deque<data> kietiakai;
            deque<data> vargsai;

            auto programStart = hrClock::now();
            bufer_read(studentai, gen, "studentai1000.txt", fopenTime);
            calcRez(studentai, rez, manual);
            sortStudents(kietiakai, vargsai, studentai);

            auto newWrite = hrClock::now();
            std::sort(kietiakai.begin(), kietiakai.end(), [](data &a, data &b)
                      { return a.vardas < b.vardas; });
            std::sort(vargsai.begin(), vargsai.end(), [](data &a, data &b)
                      { return a.vardas < b.vardas; });

            containerToFile("kietiakai.txt", kietiakai);
            containerToFile("vargsai.txt", vargsai);
            cout << "Surusiuotu studentu isvedimas i naujus failus uztruko: " << durationDouble(hrClock::now() - newWrite).count() << " s" << endl;
            cout << "Visos programos veikimo laikas: " << durationDouble(hrClock::now() - programStart).count() - fopenTime << " s" << endl;
            cout << "-------------------------" << endl;
        }
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

        calcRez(studentai, rez, manual);
        std::sort(studentai.begin(), studentai.end(), [](data &a, data &b)
                  { return a.vardas < b.vardas; });

        bufer_write("rez.txt", studentai, manual, rez);
        cout << "Visos programos veikimo laikas: " << durationDouble(hrClock::now() - programStart).count() << " s" << endl;
        cout << "-------------------------" << endl;
    }
}
