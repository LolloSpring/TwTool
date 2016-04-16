#include "twitter.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>


using namespace std;

const int dim=256;
const int est=4;

void concatena (const char a[], const char estensione[], char c[], int len_a, int len_b);

int main (int argc, char* argv[]){


    fstream my_in_bozza, my_in_tema, my_out;          //i due stream: input e output su file
    char c;
    char hashtag[dim];              //dichiaro la stringa hashtag
    char tema[dim];                //è file da cui prendo hashtags
    char output[dim];               //è file di uscita del tweet;
    char data[dim];                 //questa è la data
    char estensione[]=".txt";
    //char input[dim];
    char input[]="uni.txt";
    char scelta;
    char vuoto[]="";
      char universita[]="uni";
      char politicatrentina[]="poltn";
      char scuoladipolitiche[]="sdp";

    cout<<"Ciao e benvenuto!\n";
    cout<<"Che giorno è oggi?\n";

    cout<<"Metti: ggmmaaaa\n";            //inserimento data
    cin >>data;

    cout<<"Quale tema di hashtag desideri?\n";    //quale tema degli hashtags
   cout<<"Digita 'u' per hashtags su università, \n    't' per per hashtags su politica trentina, \n     's'     per hashtags su Scuola di Politiche \n";
    cin >> scelta;

    switch (scelta) {
        case 'u':
        strcpy(tema,universita);
            break;
        case 't':
        strcpy(tema,politicatrentina);
            break;
        case 's':
        strcpy(tema,scuoladipolitiche);
            break;
        default: cout << "Errore nella compilazione\n";
            break;
    }
cout << tema << endl;

    strcat(tema,estensione);
    strcpy(input,tema);

    concatena(data,estensione,output,strlen(data),strlen(estensione)+1);


cout << input << endl;
cout << output << endl;


    my_in_bozza.open(argv[1],ios::in);
    my_out.open(output, ios::out|ios::app);


//copio carattere per carattere il tweet bozza
    while (my_in_bozza.get(c)) {
        my_out.put(c);
      }

    my_in_bozza.close();


//aggiungo hashtags tematici al tweet
    my_in_tema.open(input, ios::in);
        while (my_in_tema>>hashtag) {

            if (hashtag[0]=='#'){
                my_out << hashtag << " ";
            }
        }

    my_in_tema.close();

    my_out.close();

}

/*
concatena(vuoto,politicatrentina,tema,strlen(vuoto),strlen(politicatrentina));
char vuoto[]="";
char politicatrentina[]="poltn";
*/
void concatena (const char a[], const char b[], char c[], int len_a, int len_b){
    for (int i=0; i<len_a;i++)
        c[i]=a[i];
    for (int i=0; i<len_b;i++)
        c[i+len_a]=b[i];
}

/*TOdo

0.1far vedere i temi di hashtag per scegliere con 1 lettera
0.2far aggiungere gli hashtag da un file che contiene già un tweet da pubblicare
0.3 mettere tutti i messaggi di benvenuto in una procedura unica di saluto.
0.4 mettere procedura di saluto su file.h
0.5 fare procedura apposita per aggiungere il .txt alla data
0.6 creare possibilità di riscrivere il tema scelto
0.7 fare pulizzia di variabili inutili
0.8 fare controllo per immissioni dati da linea di comando
*/
