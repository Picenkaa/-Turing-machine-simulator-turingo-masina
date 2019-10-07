#include <iostream>
#include <fstream> // nuskaitymas
#include <windows.h> // set console position ir sleepui
#include <conio.h> // khbit geth
#include <thread> // threadams
#include <string> // string

using namespace std;

struct Komandos
{
    string busena1;
    string busena2;
    char simbolis1;
    char simbolis2;
    char kryptis;
};

class TuringoMasina
{
private:
    int rodykle = 0;
    int eiluciuKiekis = 0; // fd eilutems
    int jokiosbusenos; // sustabdymas del busenos
    string choice; // meniu pasirinkimas

    Komandos komandos[99];

    char juosta[99];
    char pasirinkimas; // darbo pabaigos pasrinktis

    string pradinesBusenos[99];
    string symbol;

    bool stop = false,
         Kartojam = true;
public:
    void Menu()
    {
        cout << "Pasirinkite programa:            " << endl;
        cout << " 1 Programa                      " << endl;
        cout << " 2 Programa                      " << endl;
        cout << " 3 Programa                      " << endl;
        cout << " 4 Programa                      " << endl;
        cout << " 5 Visos programos su threadais  " << endl;

        cin >> choice;
        system("cls");
        void Input();
    }
    string pasirinkti()
    {
        return choice;
    }

    void Input()
    {
        string file = pasirinkti() +".txt";
        // cout << file << " failas " << endl;
        if(file!="5.txt")
        {
            ifstream fd(file);
            fd >> rodykle;
            //cout << rodykle << " rodykle " << endl;
            fd.ignore();
            fd >> symbol;
            fd.close();
            ifstream fr(file);
            fr >> rodykle;
            fr.ignore();
            for (int i = 0; i < symbol.length(); i++)
            {
                fr >> juosta[i];
                //cout << juosta[i];
            }
            fr.ignore();
            while (!fr.eof())
            {
                fr >> komandos[eiluciuKiekis].busena1
                   >> komandos[eiluciuKiekis].simbolis1
                   >> komandos[eiluciuKiekis].simbolis2
                   >> komandos[eiluciuKiekis].kryptis
                   >> komandos[eiluciuKiekis].busena2;
                eiluciuKiekis ++;
                fr.ignore();

            }
            fr.close();


            for (int i = 0; i < symbol.length(); i++)
            {
                pradinesBusenos[i] = '0';
            }
            rodykle--;
        }
        else
        {
            cout << "laikinai neveikia " << endl;
            ExitProcess(0);
        }
    }
    void Logic()
    {
        while (!stop)
        {
            if (_kbhit())
            {
                if (_getch() == 's')
                {
                    stop = true;
                }
            }
            Israsymas();
            jokiosbusenos = 0;
            for (int i = 0; i < eiluciuKiekis; i++)
            {
                if (pradinesBusenos[rodykle] == komandos[i].busena1
                        && juosta[rodykle] == komandos[i].simbolis1)
                {

                    jokiosbusenos += 1;
                    juosta[rodykle] = komandos[i].simbolis2;
                    if (komandos[i].kryptis == 'R')
                    {
                        if (rodykle + 1 < symbol.length())
                        {
                            rodykle++;
                        }
                        else
                        {
                            stop = true;
                        }
                    }
                    if (komandos[i].kryptis == 'L')
                    {
                        if (rodykle - 1 >= 0)
                        {
                            rodykle--;
                        }
                        else
                        {
                            stop = true;
                        }
                    }
                    pradinesBusenos[rodykle] = komandos[i].busena2;
                }
            }
            if (jokiosbusenos == 0)
            {
                stop = true;
            }
        }
        Israsymas();
        cout << " Masina sustabdyta arba baige darba " << endl;
        system("pause");
    }

    void Israsymas()
    {
        for (int i = 0; i < symbol.length(); i++)
        {
            gotoxy(i, 0);
            cout << juosta[i];
        }
        cout << endl;
        Arrow(rodykle);
    }

    void again()
    {
        system("cls");
        cout << "t - grizti" << endl;
        cout << "n - baigti darba " << endl;
        cin >> pasirinkimas;
        if (pasirinkimas == 't')
        {
            Kartojam = true;
        }
        if (pasirinkimas == 'n')
        {
            Kartojam = false;
        }
        system("cls");
    }

    void Arrow(int x)
    {
        gotoxy(0, 1);
        cout << "                                                                                                                                 ";
        gotoxy(x, 1);
        cout << '|' << endl;
    }

    void gotoxy(int x, int y)
    {
        COORD p = { x, y };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p); // komand linui interfacas
    }

    bool IsNaujo()
    {
        return Kartojam;
    }
    void Threadai()
    {
        ifstream f1("1.txt");
        ifstream f2("2.txt");
        ifstream f3("3.txt");
        ifstream f4("4.txt");
        void Input();


    }



};

int main()
{
    //  string kazkas;
    TuringoMasina turingoMasina;
    while (turingoMasina.IsNaujo())
    {
        turingoMasina.Menu();
        turingoMasina.pasirinkti();
        turingoMasina.Input();
        turingoMasina.Logic();
        turingoMasina.again();
        turingoMasina.Threadai();

    }
}
