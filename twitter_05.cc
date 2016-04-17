#include "twitter.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>


using namespace std;

void concatena (const char a[], const char estensione[], char c[], int len_a, int len_b);
void saluto ();
void get_data (char data[dim]);
char get_scelta ();


void concatena (const char a[], const char b[], char c[], int len_a, int len_b){
    for (int i=0; i<len_a;i++)
        c[i]=a[i];
    for (int i=0; i<len_b;i++)
        c[i+len_a]=b[i];
}

void saluto (){
  cout<<"Ciao e benvenuto!\n";
}

void get_data (char data[dim]){
  cout<<"Che giorno è oggi?\n";

  cout<<"Metti: ggmmaaaa\n";            //inserimento data
  cin >>data;

}

char get_scelta (){
  char carattere;

  cout<<"Quale tema di hashtag desideri?\n";    //quale tema degli hashtags
 cout<<"Digita 'u' per hashtags su università, \n    't' per per hashtags su politica trentina, \n     's'     per hashtags su Scuola di Politiche \n";
  cin >> carattere;

  return carattere;
}

/*TOdo

0.5 fare pulizia di variabili inutili
0.6 fare controllo per immissioni dati da linea di comando
0.7 mettere i temi degli hashtag su un file esterno
0.8 mettere azione di aggiunta di un tema con hashtag specifici
*/
