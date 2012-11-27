/*
   date.cpp
   yymmdd-OSk
   Demonstriert Grundzüge einer einfache Klasse für Datumsangaben
 * 
 */
#include "date.h"
using std::string;

//--------------------------------

Date::Date() // Standardkonstruktor
//    : y( 2001 ), m( Jan ), d( 1 )
: y(default_date().year()),
m(default_date().month()),
d(default_date().day()) {
}

//--------------------------------

Date::Date(int yy, Month mm, int dd) // ein weiterer Konstruktor
: y(yy), m(mm), d(dd) {
    if (!check()) throw Invalid();
}

//--------------------------------

bool Date::ist_schaltjahr(int i) {

    bool schaltjahr = false;

    if ((i % 4) == 0) {
        schaltjahr = true;
        if ((i % 100) == 0) {
            schaltjahr = false;
            if ((i % 400) == 0) {
                schaltjahr = true;
            }
        }
    }
    return schaltjahr;
}

bool Date::check() { // Invarianten prüfen
    bool schaltjahr = false;
    if (1800 > y || 2200 < y) return false; // Jahresbereich
    if (Jan > m || Dez < m) return false; // falscher Monat, kann passieren z.B. durch Date::Month(13)
    if (d < 1) return false; // Tag kann minimal der 1. sein
    //Alle vier Jahre gibt es ein Schaltjahr;
    //alle 100 Jahre nicht, aber
    //alle 400 Jahre wieder doch!

    schaltjahr = ist_schaltjahr(y);

    if (schaltjahr == false) {
        switch (m) { // Tag kann maximal pro Monat 28./29. oder 30. oder 31. sein
            case Feb: // kein Schaltjahr
                if (d > 28) return false;
            case Apr: case Jun: case Sep: case Nov:
                if (d > 30) return false;
            default:
                if (d > 31) return false;
        }
    } else {

        switch (m) { // Tag kann maximal pro Monat 28./29. oder 30. oder 31. sein
            case Feb: //  Schaltjahr
                if (d > 29) return false;
            case Apr: case Jun: case Sep: case Nov:
                if (d > 30) return false;
            default:
                if (d > 31) return false;
        }

    }
    return true;
}

//--------------------------------
// Aufgabe: finden Sie den Bug in dieser Methode!
//
//Fehler: Sobald bim Hochzählen der Monate der Dezember erreicht wird,
//wird y inkrementiert. Dies sollte allerdings erst passieren, 
//sobald ein Monat>12 erreicht wird!

void Date::add_month(int n) { // Monate (vor und zurück)
    if (n >= 0) { // vor
        if (((n + m) % 12) == 0) {
            y += ((n + m) / 12) - 1;
        } else {
            int a = (n + m) / 12;
            y += a; // wie viele Jahreswechsel?
        }
        int t = m + (n % 12);
        if (12 < t) t -= 12; // Monat finden
        m = Month(t);
    } else { // zurück
        int a = (n + m) / 12;
        if (m <= -n) --a;
        y += a; // wie viele Jahreswechsel?
        int t = m + (n % 12);
        if (1 > t) t += 12; // Monat finden
        m = Month(t);
    }
    if (!check()) throw Invalid(); // 31.Mrz + 1 Monat = 31.Apr -- FEHLER
}

void Date::inc_day_modulo(int t, int w) {
    //int mein_neuer_tag = d;


    if (((t + d) % w) == 0) {
        int a = ((d + t) / w) - 1;
        add_month(a);
    } else {
        int a = (t + d) / w; //Monatswechsel
        if (t >= 0) {
            add_month(a);
        } else {
            if (d <= -t) --a;
            int z = m + a;

            switch (z) {
                case Jan: case Mrz: case Mai: case Jul: case Aug: case Okt: case Dez:
                    a += 31 - w;
                    break;
                case Feb:
                    a += 28 - w;
                    break;
                case Apr: case Jun: case Sep: case Nov:
                    a += 30 - w;
                    break;
            }

            //       d= mein_neuer_tag;
            std::cout << a;
            add_month(a);

        }

    }

    if (t >= 0) {
        d = (d + t) % w;
    } else {

        int h = d + (t % w);
        if (1 > h) h += w;
        d = h;
        //d = h;
    }

}

void Date::inc_day(int t) {
    switch (m) {

        case Jan: case Mrz: case Mai: case Jul: case Aug: case Okt: case Dez:
            inc_day_modulo(t, 31);
            break;
        case Feb:
            inc_day_modulo(t, 28);
            break;
        case Apr: case Jun: case Sep: case Nov:
            inc_day_modulo(t, 30);
            break;
    }
    if (!check()) throw Invalid(); // 31.Mrz + 1 Monat = 31.Apr -- FEHLER
}

const Date& default_date() { // liefert "das Standarddatum" zur Initialisierung (KEIN Klassenmember)
    static const Date defDate(2001, Date::Jan, 1);
    return defDate;
}

//--------------------------------

ostream& operator<<(ostream& os, const Date& d) { // Stream Insertion << Operator Overloading (KEIN Klassenmember)
    return os << d.day() << '-' << d.month() << '-' << d.year();
}

void Date::print() {
    string monat = " ";
    switch (m) {
        case Jan:
            monat = "Jan";
            break;
        case Feb:
            monat = "Feb";
            break;
        case Mrz:
            monat = "Mrz";
            break;
        case Apr:
            monat = "Apr";
            break;
        case Mai:
            monat = "Mai";
            break;
        case Jun:
            monat = "Jun";
            break;
        case Jul:
            monat = "Jul";
            break;
        case Aug:
            monat = "Aug";
            break;
        case Sep:
            monat = "Sep";
            break;
        case Okt:
            monat = "Okt";
            break;
        case Nov:
            monat = "Nov";
            break;
        case Dez:
            monat = "Dez";
            break;
    }
    if (d < 10) {
        std::cout << y << " - " << monat << " - " << "0" << d << "\n";
    } else {
        std::cout << y << " - " << monat << " - " << d << "\n";

    }
}

//--------------------------------

Date::Month operator++(Date::Month& m) { // Prefix ++ Operator Overloading (KEIN Klassenmember)
    m = (m == Date::Dez) ? Date::Jan : Date::Month(m + 1);
    return m;
}

Date::Month Date::inc(Date::Month& m) { // Prefix ++ Operator Overloading (KEIN Klassenmember)
    m = (m == Date::Dez) ? Date::Jan : Date::Month(m + 1);
    
    return m;
}

int Date::compareTo(Date& comitted, Date& comitted2) {
    int returnvalue(0);
    int jahr(0);
    int monat(0);
    int tag(0);

    jahr = comitted.y - comitted2.y;
    //std::cout<<jahr<<"\n";
    monat = comitted.m - comitted2.m;
    //std::cout<<monat<<"\n";
    tag = comitted.d - comitted2.d;
    //std::cout<<tag<<"\n";

    if (jahr == 0 && monat == 0 && tag == 0) {
        returnvalue = 0;
    }
    if (jahr < 0) {
        returnvalue = -1;
    }
    if (jahr > 0) {
        returnvalue = 1;
    }
    if (jahr == 0 && monat != 0) {
        if (monat < 0) {
            returnvalue = -1;
        } else {
            returnvalue = 1;
        }
    }
    if (jahr == 0 && monat == 0 && tag != 0) {
        if (tag < 0) {
            returnvalue = -1;
        } else {
            returnvalue = 1;
        }
    }


    return returnvalue;
}
