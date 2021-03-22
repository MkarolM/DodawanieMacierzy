#include <iostream>
using namespace std;

#define r 3

class Macierz
{
    float tab[r][r];
public:
    Macierz()
    {
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < r; j++)
            {
                tab[i][j] = 0;
            }
        }
    }
    void wczytajDane()
    {
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < r; j++)
            {
                cout << "Podaj liczbe na pozycji [" << i + 1 << "][" << j + 1 << "]";
                cin >> tab[i][j];
            }
        }
    }
    void wypisz()
    {
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < r; j++)
            {
                cout << tab[i][j] << "\t";
            }
            cout << endl;
        }
    }
    friend Macierz* Dodaj(Macierz& a, Macierz& b);
};

Macierz* Dodaj(Macierz& a, Macierz& b)
{
    Macierz* wsk;
    wsk = new Macierz;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < r; j++)
        {
            wsk->tab[i][j] = a.tab[i][j] + b.tab[i][j];
        }
    }

    return wsk;
}

int main()
{
    Macierz m1, m2;
    Macierz* w;
    m1.wczytajDane();
    m1.wypisz();
    m2.wczytajDane();
    m2.wypisz();
    w = Dodaj(m1, m2);
    w->wypisz();
    delete w;
}