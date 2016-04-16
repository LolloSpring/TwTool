#include "twitter.h"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int dim=256;
const int est=4;
const int formato_data=8;

void concatena (const char a[], const char estensione[], char c[], int len_a);



int main (int argc, char* argv[]){
    
    
    fstream my_in, my_out;          //i due stream: input e output su file
    char hashtag[dim];              //dichiaro la stringa hashtag
    char tema[dim];                //è file da cui prendo hashtags
    char output[dim];               //è file di uscita del tweet;
    char data[dim];                 //questa è la data
    char estensione[]=".txt";
    char input[dim];
    char scelta;
    
    
    /*
    if (argc!=3){
        cout<< "Sintassi: ./a.out <input> <output>\n";
        exit(0);
    }*/
    
    cout<<"Ciao e benvenuto!\n";
    cout<<"Che giorno è oggi?\n";
    
    
    cout<<"Metti: ggmmaaaa\n";            //inserimento data
    cin >>data;
    
    cout<<"Quale tema di hashtag desideri?";    //quale tema degli hashtags
    cout<<"Digita 'u' per hashtags su università, \n    't' per per hashtags su politica trentina, \n     's'     per hashtags su Scuola di Politiche \n";
    cin >> scelta;
    
    switch (scelta) {
        case 'u': char tema[]="uni";
            break;
        case 't': tema[]="poltn";
            break;
        case 's': tema[]="sdp";
        default: cout << "Errore nella compilazione\n";
            break;
    }
    
    
    concatena(data,estensione,output,strlen(data));
    
    concatena(tema,estensione,input,strlen(tema));
    
    
    
    my_in.open(input, ios::in);
    my_out.open(output, ios::out);
    
    while (my_in>>hashtag) {
        
        if (hashtag[0]=='#'){
            my_out << hashtag << endl;
        }
    }
    
    
    my_in.close();
    my_out.close();
    

    
}


void concatena (const char a[], const char estensione[], char c[], int len_a){
    for (int i=0; i<len_a;i++)
        c[i]=a[i];
    for (int i=0; i<est;i++)
        c[i+len_a]=estensione[i];
    
}




/*TODO

0.1far vedere i temi di hashtag per scegliere con 1 lettera
0.2far aggiungere gli hashtag da un file che contiene già un tweet da pubblicare
0.3 mettere tutti i messaggi di benvenuto in una procedura unica di saluto.
0.4 mettere procedura di saluto su file.h
0.5 fare procedura apposita per aggiungere il .txt alla data
0.6 creare possibilità di riscrivere il tema scelto
*/