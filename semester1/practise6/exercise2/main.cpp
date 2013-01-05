/* 
 * Exercise 2
 *
 * Created on 14. Dezember 2012, 10:05
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
void tolower (char* cs){
    int counter (0);
    char itemp (0);
    char ctemp(' ');
    
    while (cs[counter] != '\0'){
        itemp= cs[counter];
        if (itemp>64 && itemp<91){
            ctemp=itemp+32;
        }else{
            ctemp=itemp;
        }
        counter++;
        cout<<ctemp;
    }
    cout<<endl;
}
char* cstring_copier( const char* cs){
    int counter (0);
    while (cs[counter] !='\0'){
        counter++;
    }
    
    char* ac(new char [counter]) ;
    
    for (int i=0; i<counter;i++){
        ac[i]=cs[i];
    }
    cout<<"Original: ";
    for (int i=0; i<counter;i++){
        cout<<cs[i];
    }
    
    cout<<endl;
    cout<<"Kopie: ";
    for (int i=0; i<counter;i++){
        cout<<ac[i];
    }
    
    cout<<endl;
    return ac;
    
}
int main(int argc, char** argv) {
    //Aufgabe 2a
    
    //Testfälle
    char ac []="Hallo C++";
    char bc []="Guten Morgen";
    char cc []="Zwerg#7";
    char dc []="Praktikum_6";
    char ec []="Berliner Allee 6";
    char fc []="1234567890";
    char gc []="";
    char hc []="Bären";
    char ic []="H_DA";
    char jc []="h-da";
    char kc []="ProgrammierEn";
    //Ausgabe
    tolower (ac);
    tolower (bc);
    tolower (cc);
    tolower (dc);
    tolower (ec);
    tolower (fc);
    tolower (gc);
    tolower (hc);
    tolower (ic);
    tolower (jc);
    tolower (kc);
    cout<<endl;
    
    //Aufgabe 2b
    char test []= "Hallo C++";
    
    //Ausgabe Kopien
    cstring_copier(test);
    cstring_copier(ac);
    cstring_copier(bc);
    cstring_copier(cc);
    cstring_copier(dc);
    cstring_copier(ec);
    cstring_copier(fc);
    cstring_copier(gc);
    cstring_copier(hc);
    cstring_copier(ic);
    cstring_copier(jc);
    cstring_copier(kc);
    
    return 0;
}

