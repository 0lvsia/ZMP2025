#include <iostream>

using namespace std;

// sortowanie babelkowe na kolejce fifo

struct Kolejka //na podstawie kodu na stronie dr. Michalskiego
{
    struct wezel // pojedyncze element kolejki
    {
        int dane;
        wezel* nastepny;
        wezel(int wartosc) //ustawia dane, zeruje wskaŸnik
        {
            dane=wartosc;
            nastepny=nullptr; //nullptr to pusty wskaŸnik
        }
    };

    wezel* poczatek; //wskaznik na poczatek kolejki
    wezel* koniec; //wskaznik na koniec kolejki

    Kolejka() //poczatkowo robi kolejke pust¹; program nie szuka danych tam gdize ich nie ma
    {
        poczatek=nullptr;
        koniec=nullptr;
    }

    void dodaj(int wartosc) //metoda która dodaje element na koniec kolejki
    {
        wezel* nowy=new wezel(wartosc); //tworzy nowy wezel z dana wartoscia
        if(!poczatek) //jezeli to pierwszy element tu to ustawia oba wskazniki (poczatek i koniec) na ten nowy element
        {
            poczatek=koniec=nowy;
        } else
        {
            koniec->nastepny=nowy;  // poprzedni ostatni element wskazuje na nowy;
            /*
            koniec to wskaznik na jakis element
            -> to przejscie do pola w obiekcie na ktory wskazuje wskaŸnik
            poruszanie sie po liscie
            */
            koniec=nowy; // nowy element jako ostatni
        }
    }

    int rozmiar() //liczy ile elementow ma kolejka;
    {
        int licznik=0;
        wezel* obecny=poczatek;
        while (obecny)
        {
            licznik++;
            obecny=obecny -> nastepny;
        }
        return licznik;
    }

    void dotablicy(int* tablica) //kopiuje elementy kolejki do zwyklej tablicy
    // int* to wskaznik na tablice intow
    {
        wezel* obecny=poczatek;
        int i=0;
        while(obecny)
        {
            tablica[i++]=obecny->dane;
            obecny=obecny->nastepny;
        }
    }

    void ztablicy(int* tablica, int n) //czysci kolejke i tworzy na nowo z danych z tablicy;
    {
        wyczysc();
        for(int i=0; i<n; i++)
        {
            dodaj(tablica[i]);
        }
    }

    void wyczysc() //czysci
    {
        while(poczatek)
        {
            wezel* tymczasowy=poczatek;
            poczatek=poczatek->nastepny;
            delete tymczasowy;
        }
        koniec = nullptr;
    }

    void wypisz() //wyswietla liczby w kolejce, od pierwszego do ostatniego
    {
        wezel* obecny=poczatek;
        while(obecny)
        {
            cout << obecny->dane << " ";
            obecny = obecny -> nastepny;
        }
        cout << endl;
    }
    ~Kolejka()
    {
        wyczysc();
    }
};

//sortowanie babelkowe
void babelki(int* tablica, int n)
{
    for (int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(tablica[j]>tablica[j+1])
            {
                int temp=tablica[j];
                tablica[j]=tablica[j+1];
                tablica[j+1]=temp;

            }
        }
    }
}


int main()
{
    Kolejka kolejka;
    int n;
    cout << "podaj liczbe elementow ";
    cin >> n;

    for(int i=0; i<n; i++)
    {
        int liczby;
        cout << "podaj " << i+1 << " liczbe ";
        cin >> liczby;
        kolejka.dodaj(liczby);
    }
    int* tablica=new int[n]; //tworzy nowa dynamiczna tablice
    kolejka.dotablicy(tablica); //przepisuje dane z kolejki do tablicy
    babelki(tablica, n); //sortuje tablice
    kolejka.ztablicy(tablica, n); //tworzy nowa kolejke na podstawie posortowanej tablicy
    delete[] tablica; //usuwa tablica z pamieci

    cout << "posortowane elementy; ";
    kolejka.wypisz();

  return 0;
}
