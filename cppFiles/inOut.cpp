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
        temp.egz = randomInt(1, 10);

    ////////// pazymiu vedimas ///////////
    if (paz)
        enterMarkManually(temp);
    else
        generateRandomMark(temp);
    cout << "pazymiai suvesti" << endl;
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
void bufer_read(vector<data> &studentai, bool gen, string genFile_name, double &fopenTime)
{
    std::string line;
    std::stringstream my_buffer;

    std::ifstream open_f;
    auto stime = hrClock::now();
    openFile(open_f);
    fopenTime = durationDouble(hrClock::now() - stime).count();

    auto readStart = hrClock::now();
    my_buffer << open_f.rdbuf();
    open_f.close();
    std::getline(my_buffer, line);

    int counter = 0;
    while (my_buffer)
    {
        std::getline(my_buffer, line);
        if (line.length() == 0)
            break;
        data t;
        std::istringstream lineStream(line);
        lineStream >> t.vardas >> t.pavarde;
        int mark;
        while (lineStream >> mark)
        {
            t.paz.push_back(mark);
        }
        t.egz = t.paz.back();
        t.paz.pop_back();
        studentai.push_back(t);
    }
    cout << "Failo skaitymas uztruko: " << durationDouble(hrClock::now() - readStart).count() << " s" << endl;
}
void bufer_read(list<data> &studentai, bool gen, string genFile_name, double &fopenTime)
{
    std::string line;
    std::stringstream my_buffer;

    std::ifstream open_f;
    auto stime = hrClock::now();
    openFile(open_f);
    fopenTime = durationDouble(hrClock::now() - stime).count();

    auto readStart = hrClock::now();
    my_buffer << open_f.rdbuf();
    open_f.close();
    std::getline(my_buffer, line);

    int counter = 0;
    while (my_buffer)
    {
        std::getline(my_buffer, line);
        if (line.length() == 0)
            break;
        data t;
        std::istringstream lineStream(line);
        lineStream >> t.vardas >> t.pavarde;
        int mark;
        while (lineStream >> mark)
        {
            t.paz.push_back(mark);
        }
        t.egz = t.paz.back();
        t.paz.pop_back();
        studentai.push_back(t);
    }
    cout << "Failo skaitymas uztruko: " << durationDouble(hrClock::now() - readStart).count() << " s" << endl;
}
void bufer_read(deque<data> &studentai, bool gen, string genFile_name, double &fopenTime)
{
    std::string line;
    std::stringstream my_buffer;

    std::ifstream open_f;
    auto stime = hrClock::now();
    openFile(open_f);
    fopenTime = durationDouble(hrClock::now() - stime).count();

    auto readStart = hrClock::now();
    my_buffer << open_f.rdbuf();
    open_f.close();
    std::getline(my_buffer, line);

    int counter = 0;
    while (my_buffer)
    {
        std::getline(my_buffer, line);
        if (line.length() == 0)
            break;
        data t;
        std::istringstream lineStream(line);
        lineStream >> t.vardas >> t.pavarde;
        int mark;
        while (lineStream >> mark)
        {
            t.paz.push_back(mark);
        }
        t.egz = t.paz.back();
        t.paz.pop_back();
        studentai.push_back(t);
    }
    cout << "Failo skaitymas uztruko: " << durationDouble(hrClock::now() - readStart).count() << " s" << endl;
}

void bufer_write(std::string write_vardas, vector<data> &studentai, bool manual, bool rez)
{
    std::stringstream outputas;
    outputas << left << setw(20) << "Vardas";
    outputas << left << setw(20) << "Pavarde";
    if (rez || !manual)
        outputas << std::left << std::setw(20) << "Galutinis (Vid.)";
    if (!rez || !manual)
        outputas << std::left << std::setw(20) << "Galutinis (Med.)";
    outputas << endl;
    if (!manual)
    {
        for (auto &stud : studentai)
        {
            outputas << left << setw(20) << stud.vardas;
            outputas << left << setw(20) << stud.pavarde;
            outputas << left << setw(20) << stud.vid;
            outputas << left << setw(20) << stud.med;
            outputas << endl;
        }
    }
    else if (rez)
    {
        for (auto &stud : studentai)
        {
            outputas << left << setw(20) << stud.vardas;
            outputas << left << setw(20) << stud.pavarde;
            outputas << left << setw(20) << stud.vid;
            outputas << endl;
        }
    }
    else if (!rez)
    {
        for (auto &stud : studentai)
        {
            outputas << left << setw(20) << stud.vardas;
            outputas << left << setw(20) << stud.pavarde;
            outputas << left << setw(20) << stud.med;
            outputas << endl;
        }
    }
    studentai.clear();

    std::ofstream out_f(write_vardas);
    out_f << outputas.rdbuf();
    out_f.close();
}
void bufer_write(std::string write_vardas, list<data> &studentai, bool manual, bool rez)
{
    std::stringstream outputas;
    outputas << left << setw(20) << "Vardas";
    outputas << left << setw(20) << "Pavarde";
    if (rez || !manual)
        outputas << std::left << std::setw(20) << "Galutinis (Vid.)";
    if (!rez || !manual)
        outputas << std::left << std::setw(20) << "Galutinis (Med.)";
    outputas << endl;
    if (!manual)
    {
        for (auto &stud : studentai)
        {
            outputas << left << setw(20) << stud.vardas;
            outputas << left << setw(20) << stud.pavarde;
            outputas << left << setw(20) << stud.vid;
            outputas << left << setw(20) << stud.med;
            outputas << endl;
        }
    }
    else if (rez)
    {
        for (auto &stud : studentai)
        {
            outputas << left << setw(20) << stud.vardas;
            outputas << left << setw(20) << stud.pavarde;
            outputas << left << setw(20) << stud.vid;
            outputas << endl;
        }
    }
    else if (!rez)
    {
        for (auto &stud : studentai)
        {
            outputas << left << setw(20) << stud.vardas;
            outputas << left << setw(20) << stud.pavarde;
            outputas << left << setw(20) << stud.med;
            outputas << endl;
        }
    }
    studentai.clear();

    std::ofstream out_f(write_vardas);
    out_f << outputas.rdbuf();
    out_f.close();
}
void bufer_write(std::string write_vardas, deque<data> &studentai, bool manual, bool rez)
{
    std::stringstream outputas;
    outputas << left << setw(20) << "Vardas";
    outputas << left << setw(20) << "Pavarde";
    if (rez || !manual)
        outputas << std::left << std::setw(20) << "Galutinis (Vid.)";
    if (!rez || !manual)
        outputas << std::left << std::setw(20) << "Galutinis (Med.)";
    outputas << endl;
    if (!manual)
    {
        for (auto &stud : studentai)
        {
            outputas << left << setw(20) << stud.vardas;
            outputas << left << setw(20) << stud.pavarde;
            outputas << left << setw(20) << stud.vid;
            outputas << left << setw(20) << stud.med;
            outputas << endl;
        }
    }
    else if (rez)
    {
        for (auto &stud : studentai)
        {
            outputas << left << setw(20) << stud.vardas;
            outputas << left << setw(20) << stud.pavarde;
            outputas << left << setw(20) << stud.vid;
            outputas << endl;
        }
    }
    else if (!rez)
    {
        for (auto &stud : studentai)
        {
            outputas << left << setw(20) << stud.vardas;
            outputas << left << setw(20) << stud.pavarde;
            outputas << left << setw(20) << stud.med;
            outputas << endl;
        }
    }
    studentai.clear();
    std::ofstream out_f(write_vardas);
    out_f << outputas.rdbuf();
    out_f.close();
}
void genFile(int size, string file_name, int ndCount)
{
    auto genStart = hrClock::now();
    std::stringstream outputas;
    outputas << left << setw(20) << "Vardas";
    outputas << left << setw(20) << "Pavarde";
    for (int i = 1; i <= ndCount; i++)
    {
        outputas << left << "ND" << setw(5) << i;
    }
    outputas << left << setw(7) << "Egz" << endl;
    for (int i = 0; i < size; i++)
    {
        outputas << genStudentString(ndCount).str();
    }
    std::ofstream out_f(file_name);
    out_f << outputas.rdbuf();
    out_f.close();
    cout << size << " irasu failo generavimo laikas: " << durationDouble(hrClock::now() - genStart).count() << " s" << endl;
}
void containerToFile(string file_name, vector<data> &data)
{
    std::stringstream out;
    for (auto &stud : data)
    {
        out << left << setw(20) << stud.vardas;
        out << left << setw(20) << stud.pavarde;
        out << left << setw(20) << stud.vid;
        out << left << setw(20) << stud.med;
        out << endl;
    }
    std::ofstream out_f(file_name);
    out_f << out.rdbuf();
    out_f.close();
}
void containerToFile(string file_name, list<data> &data)
{
    std::stringstream out;
    for (auto &stud : data)
    {
        out << left << setw(20) << stud.vardas;
        out << left << setw(20) << stud.pavarde;
        out << left << setw(20) << stud.vid;
        out << left << setw(20) << stud.med;
        out << endl;
    }
    std::ofstream out_f(file_name);
    out_f << out.rdbuf();
    out_f.close();
}
void containerToFile(string file_name, deque<data> &data)
{
    std::stringstream out;
    for (auto &stud : data)
    {
        out << left << setw(20) << stud.vardas;
        out << left << setw(20) << stud.pavarde;
        out << left << setw(20) << stud.vid;
        out << left << setw(20) << stud.med;
        out << endl;
    }
    std::ofstream out_f(file_name);
    out_f << out.rdbuf();
    out_f.close();
}
void openFile(std::ifstream &open_f)
{
    bool error = true;
    cin.ignore();
    while (error)
    {
        cout << "Iveskite failo pavadinima(numatysis pavadinimas: studentai.txt): ";
        string file_name;
        getline(cin, file_name);

        if (file_name.empty())
            file_name = "studentai.txt";
        try
        {
            open_f.open(file_name);
            if (open_f.fail())
                throw std::invalid_argument("Klaida! Neteisingas failo pavadinimas.");
            error = false;
        }
        catch (const std::invalid_argument &e)
        {
            cout << e.what() << std::endl;
        }
    }
}