class Token {
public:
    char kind; // die 7 Kategorien der Eingabesymbole
    double value; // Bei Zahlenkategorie: der Wert
    // Memberfunktion: erstelle ein Token aus einem char

    Token();
    
    Token(char ch)
    : kind(ch), value(0.0) {
        /* mache nichts sonst */
    }
    // Memberfunktion: erstelle ein Token aus einem char und einem double

    Token(char ch, double val)
    : kind(ch), value(val) {
        /* mache nichts sonst */
    }
};