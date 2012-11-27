/*  ____  
 * |___ \ 
 *   __) |
 *  |__ < 
 *  ___) |
 * |____/ 
 *
 * Created on 24. November 2012, 14:55
 * 
 */
#include "mp3Tag.h"
#include "mp3TagList.h"
#include "myError.h"
#include <cstdlib>
#include <vector>

using namespace std;

int main() {

    try {
        mp3TagList liste; //object for mp3Tag objects, contains vector of mp3Tag

        mp3Tag lied; //object with default constructor
        mp3Tag lied1("Iron Maiden", "Run to the Hills", 2, 50, true, mp3Tag::Rock);
        mp3Tag lied2("Devil Driver", "Shitlist", 2, 32, true, mp3Tag::Rock);
        mp3Tag lied3("Lady Gaga", "Pokerface", 3, 52, true, mp3Tag::Pop);
        mp3Tag lied4("Bob Marley", "No woman no cry", 4, 3, true, mp3Tag::Reggae);
        mp3Tag lied5("Beethoven", "5te", 25, 00, true, mp3Tag::Klassik);
        mp3Tag lied6("Kenny G.", "Songbird", 3, 1, true, mp3Tag::Jazz);
        mp3Tag lied7("Megadeth", "I thought i knew it all", 5, 00, true, mp3Tag::Rock);
        mp3Tag lied8("AC DC", "Thunderstruck", 2, 4, true, mp3Tag::Rock);
        mp3Tag lied9("Iced Earth", "The Reckoning", 3, 23, true, mp3Tag::Rock);
        mp3Tag lied10("In Flames", "The Quiet Place", 3, 23, true, mp3Tag::Rock);

        liste.populate(lied1);
        liste.populate(lied2);
        liste.populate(lied3);
        liste.populate(lied4);
        liste.populate(lied5);
        liste.populate(lied6);
        liste.populate(lied7);
        liste.populate(lied8);
        liste.populate(lied9);
        liste.populate(lied10);

        liste.printall();

        return 0;
    } catch (mp3Tag::Invalid) {
        cerr << "Die Dauer des Titels ist ungueltigt";
    } catch (exception &e) {
        cerr << "Ausname: " << e.what();
    } catch (...) {
        cerr << "Unbekannter Fehler";
    }

}

