//#include <iostream>
//#include <vector>
//#include <string>
//
//using namespace std;
//
//class Ksiazka {
//private:
//    string tytul;
//    string autor;
//    bool dostepna;
//
//public:
//    Ksiazka(const string& tytul, const string& autor)
//        : tytul(tytul), autor(autor), dostepna(true) {}
//
//    const string& getTytul() const { return tytul; }
//    const string& getAutor() const { return autor; }
//    bool czyDostepna() const { return dostepna; }
//
//    void ustawDostepnosc(bool dostepnosc) { dostepna = dostepnosc; }
//};
//
//class Czytelnik {
//private:
//    string imie;
//    string nazwisko;
//    string email;
//
//public:
//    Czytelnik(const string& imie, const string& nazwisko, const string& email)
//        : imie(imie), nazwisko(nazwisko), email(email) {}
//
//    const string& getImie() const { return imie; }
//    const string& getNazwisko() const { return nazwisko; }
//    const string& getEmail() const { return email; }
//};
//
//class Biblioteka {
//private:
//    vector<Ksiazka> listaKsiazek;
//    vector<Czytelnik> listaOczekujacych;
//
//public:
//    void podanieCzytelnika(const Czytelnik& czytelnik) {
//        cout << "Czytelnik " << czytelnik.getImie() << " " << czytelnik.getNazwisko()
//            << " zarejestrowany.\n";
//    }
//
//    bool wyswietlenieDostepnosciKsiazki(const Ksiazka& ksiazka) const {
//        cout << "Dostepnosc ksiazki \"" << ksiazka.getTytul() << "\" autora "
//            << ksiazka.getAutor() << ": " << (ksiazka.czyDostepna() ? "Dostepna" : "Niedostepna")
//            << "\n";
//        return ksiazka.czyDostepna();
//    }
//
//    void zapisNaListeOczekujacych(const Czytelnik& czytelnik, const Ksiazka& ksiazka) {
//        cout << "Czytelnik " << czytelnik.getImie() << " " << czytelnik.getNazwisko()
//            << " zapisal sie na liste oczekujacych na ksiazke \"" << ksiazka.getTytul() << "\".\n";
//        listaOczekujacych.push_back(czytelnik);
//    }
//
//    void powiadomienieODostepnosciKsiazki(const Ksiazka& ksiazka) {
//        cout << "Powiadomienie o dostepnosci ksiazki \"" << ksiazka.getTytul() << "\" wyslane do ";
//        for (const auto& czytelnik : listaOczekujacych) {
//            cout << czytelnik.getEmail() << ", ";
//        }
//        cout << "\n";
//    }
//};
//
//int main() {
//    Biblioteka biblioteka;
//
//    Czytelnik czytelnik1("Jan", "Kowalski", "jan.kowalski@example.com");
//    Czytelnik czytelnik2("Anna", "Nowak", "anna.nowak@example.com");
//
//    biblioteka.podanieCzytelnika(czytelnik1);
//    biblioteka.podanieCzytelnika(czytelnik2);
//
//    Ksiazka ksiazka1("Wladca Pierscieni", "J.R.R. Tolkien");
//    Ksiazka ksiazka2("Harry Potter", "J.K. Rowling");
//
//    biblioteka.wyswietlenieDostepnosciKsiazki(ksiazka1);
//
//    biblioteka.zapisNaListeOczekujacych(czytelnik1, ksiazka1);
//    biblioteka.zapisNaListeOczekujacych(czytelnik2, ksiazka1);
//
//    ksiazka1.ustawDostepnosc(false);
//    biblioteka.powiadomienieODostepnosciKsiazki(ksiazka1);
//
//    return 0;
//}





//Wersja 2

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class czytelnik
{
private:
	string imie;
	string nazwisko;
	string nrId;
	bool status = false;

public:
	czytelnik(const string& imie, const string& nazwisko, const string& nrId)
		:imie(imie), nazwisko(nazwisko), nrId(nrId) {};

	const string& getImie() const { return imie; }
	const string& getNazwisko() const { return nazwisko; }
	const string& getId() const { return nrId; }
	bool czyPosiada() const { return status; }

	void ustawStatus(bool stat) { status = stat; }
};

class ksiazka
{
private:
	string nazwa;
	string autor;
	bool dostepna;

public:
	ksiazka(const string& nazwa, const string& autor)
		:nazwa(nazwa), autor(autor), dostepna(true) {}

	const string& getNazwa() const { return nazwa; }
	const string& getAutor() const { return autor; }
	bool czyDostepna() const { return dostepna; }

	void ustawDostepnosc(bool dostepnosc) { dostepna = dostepnosc; }
};

class Biblioteka
{
private:
	vector<ksiazka>listaKsiazek;
	vector<czytelnik>listaOczekujacych;

public:
	void podanieCzytelnika(const czytelnik& czytelnik)
	{
		cout << "Czytelnik " << czytelnik.getImie() << " " << czytelnik.getNazwisko() << " zarejestrowany." << endl;
	}

	bool wyswietlenieDostepnosci(const ksiazka& ksiazka) const 
	{
		cout << "Dostepnosc ksiazki \"" << ksiazka.getNazwa() << "\" autorstwa " << ksiazka.getAutor() << ": " << (ksiazka.czyDostepna() ? "Dostepna": "Niedostepna");
		cout << endl;
		return ksiazka.czyDostepna();
	}

	void zapisNaListe(const czytelnik& czytelnik, const ksiazka& ksiazka)
	{
		cout << "Czytelnik " << czytelnik.getImie() << " " << czytelnik.getNazwisko() << " zapisal sie na liste oczekujacych" << endl;
		cout << "na ksiazke \"" << ksiazka.getNazwa() << "\"." << endl;
		listaOczekujacych.push_back(czytelnik);
	}

	void wypozycz(czytelnik& czytelnik, ksiazka& ksiazka)
	{
		if (ksiazka.czyDostepna())
		{
			cout << "Ksiazka \"" << ksiazka.getNazwa() << "\" wypozuczona przez " << czytelnik.getImie() << " " << czytelnik.getNazwisko() << "." << endl;
			ksiazka.ustawDostepnosc(false);
			czytelnik.ustawStatus(true);
		}
		else
		{
			cout << "Ksiazka niedostepna. Zapis czytelnika " << czytelnik.getImie() << " " << czytelnik.getNazwisko() << " na liste oczekujacych." << endl;
			zapisNaListe(czytelnik, ksiazka);
		}
	}

	void zwrocKsiazke(czytelnik& czytelnik, ksiazka& ksiazka)
	{
		cout << "Ksiazka \"" << ksiazka.getNazwa() << "\" zwrocona przez " << czytelnik.getImie() << " " << czytelnik.getNazwisko() << "." << endl;
		ksiazka.ustawDostepnosc(true);
		powiadomODostepnosciKsiazki(ksiazka);
	}

	void powiadomODostepnosciKsiazki(const ksiazka& ksiazka)
	{
		cout << "Powiadomienie o dostepnosci ksiazki \"" << ksiazka.getNazwa() << "\" wyslane do:" << endl;
		for (const auto& czytelnik : listaOczekujacych)
		{
			cout << czytelnik.getId() << ", ";
		}
		cout << endl;
	}
};

czytelnik wczytajDane()
{
	string imie, nazwisko, id;
	cout << "Podaj imie: ";
	cin >> imie;
	cout << "Podaj nazwisko: ";
	cin >> nazwisko;
	cout << "Podaj ID: ";
	cin >> id;
	cin.get();
	return czytelnik(imie, nazwisko, id);
}

ksiazka podajKsiazke()
{
	string nazwa, autor;
	cout << "Podaj nazwe ksiazki ktora chcesz wypozyczyc: ";
	getline(cin, nazwa);
	//cin.get();
	cout << "Podaj autora: ";
	getline(cin, autor);
	//cin.get();
	return ksiazka(nazwa, autor);
}

void wyswietlKsiazke(ksiazka ksiazka)
{
	cout << "Nazwa: \"" << ksiazka.getNazwa() << "\"" << endl;
	cout << "Autor: " << ksiazka.getAutor() << endl;
	cout << "Dostepnosc: " << (ksiazka.czyDostepna() ? "Dostepna" : "Niedostepna") << endl;
}

int main()
{
	Biblioteka biblioteka;
	int k;

	czytelnik czytelnik1 = wczytajDane();
	ksiazka ksiazka1 = podajKsiazke();

	wyswietlKsiazke(ksiazka1);

	biblioteka.podanieCzytelnika(czytelnik1);
	cout << endl;

	do
	{
		cout << "Wybierz co chcesz zrobic:" << endl;
		cout << "1. Wypozycz ksiazke" << endl;
		cout << "2. Zwroc ksiazke" << endl;
		cout << "3. Sprawdz dostepnosc ksiazki" << endl;
		cout << "4. Zakoncz program" << endl << endl;

		cin >> k;

		switch (k)
		{
		case 1:
			if (ksiazka1.czyDostepna())
			{
				biblioteka.wypozycz(czytelnik1, ksiazka1);
			}
			break;

		case 2:
			if (czytelnik1.czyPosiada())
			{
				biblioteka.zwrocKsiazke(czytelnik1, ksiazka1);
			}
			else
			{
				cout << "Nie mozesz zwrocic ksiazki, ktorej nie posiadasz." << endl;
			}
			break;

		case 3:
			biblioteka.wyswietlenieDostepnosci(ksiazka1);
			break;

		case 4:
			cout << "Koniec programu." << endl;
			break;
		default:
			cout << "Bledna instrukcja." << endl;
			break;

		}
	} while (k != 4);

}