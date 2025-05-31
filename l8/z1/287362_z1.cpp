#include <iostream>

using namespace std;

//klasa bazowa
class Pojazd
{
private:
    string marka;
    string model;
    int rok_produkcji;

public:
    Pojazd(string m, string md, int r) : marka(m), model(md), rok_produkcji(r) {}

    virtual void wyswietl()
    {
         cout << "marka: " << marka << endl;
         cout << "model: " << model << endl;
         cout << "rok produkcji: " << rok_produkcji << endl;
    }
};

//klasa dziedziczaca dla samochodu  z dodatkowym atrybutem drzwi
class Samochod : public Pojazd
{
private:
    int liczba_drzwi;

public:
    Samochod(string m, string md, int r, int ld) : Pojazd(m, md, r), liczba_drzwi(ld) {}

    //przeciazenie metody
    void wyswietl()
    {
        Pojazd::wyswietl();
        cout << "liczba drzwi: " << liczba_drzwi << endl;
    }

    Samochod dodajSamochod(string marka, string model, int rok_produkcji, int liczba_drzwi)
    {
        return Samochod(marka, model, rok_produkcji, liczba_drzwi);
    }
};

//klasa dziedziczaca dla roweru z dodatkowym atrybutem rower
class Rower: public Pojazd
{
private:
    int liczba_przerzutek;

public:
    Rower(string m, string md, int r, int lp) : Pojazd(m, md, r), liczba_przerzutek(lp) {}


    //przeciazenie metody
    void wyswietl()
    {
        Pojazd::wyswietl();
        cout << "liczba przerzutek " << liczba_przerzutek << endl;
    }

    Rower dodajrower(string marka, string model, int rok_produkcji, int liczba_przerzutek)
    {
        return Rower(marka, model, rok_produkcji, liczba_przerzutek);

    }

};



int main()
{
    string markasam, modelsam;
    int roksam, drzwi;

    cout << "podaj marke, model, rok oraz ilosc drzwi w samochodzie" << endl;
    cin >> markasam >> modelsam >> roksam >> drzwi;

    string markaro, modelro;
    int rokro, przerzutki;

    cout << "podaj marke, model, rok oraz ilosc przerzutek w rowerze" << endl;

    cin >> markaro >> modelro >> rokro >> przerzutki;

    Samochod samochod(markasam, modelsam, roksam, drzwi);
    Rower rower(markaro, modelro, rokro, przerzutki);

    samochod.wyswietl();
    rower.wyswietl();


    return 0;
}
