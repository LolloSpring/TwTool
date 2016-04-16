#include "twitter.h"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int dim=256;
const int est=4;
const int formato_data=8;

void concatena (const char data[], const char estensione[], char c[]);


int main (int argc, char* argv[]){
    
    
    fstream my_in, my_out;          //i due stream: input e output su file
    char hashtag[dim];              //dichiaro la stringa hashtag
    char input[dim];                //è file da cui prendo hashtags
    char output[dim];               //è file di uscita del tweet;
    char data[dim];                 //questa è la data
    char estensione[]=".txt";
    
    
    /*
    if (argc!=3){
        cout<< "Sintassi: ./a.out <input> <output>\n";
        exit(0);
    }*/
    
    cout<<"Ciao e benvenuto!\n";
    cout<<"Che giorno è oggi?\n";
    
    
    cout<<"Metti: ggmmaaaa\n";            //inserimento data
    cin >>data;
    
    cout<<"Quale tema di hashtag desideri?";//quale tema degli hashtag
    cin >> input;
    
    concatena(data,estensione,output);
    cout << "L'output è: " << output<< endl;
    
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

void concatena (const char data[], const char estensione[], char c[]){
    for (int i=0; i<formato_data;i++)
        c[i]=data[i];
    for (int i=0; i<est;i++)
        c[i+formato_data]=estensione[i];
    
}

/*void concatenaArray(const double a[], const double b[], double c[], int n1, int n2)
{
    for (int i=0;i<n1;i++)
        c[i]=a[i];
    for (int i=0;i<n2;i++)
        c[i+n1]=b[i];
}
 */



/*TODO

01.chiedere la data e nominarlo con la data
02.far vedere i temi di hashtag per scegliere con 1 lettera
03.far aggiungere gli hashtag da un file che contiene già un tweet da pubblicare
04. mettere tutti i messaggi di benvenuto in una procedura unica di saluto.
0.5 mettere procedura di saluto su file.h
0.6 fare procedura apposita per aggiungere il .txt alla data
*/