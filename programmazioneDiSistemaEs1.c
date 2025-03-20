/*Scrivere un programma concorrente che realizzi il seguente comando:

cat costituzione.txt | more*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>


int main(int argc, char *argv []){


    if(argc != 2){//è un controllo dei numeri di argomenti(argv[0] = a.out, argv[1] = l'input che inseriamo)
        printf("ERRORE");
        exit(0);
    }

    int pid;
    int p1p0[2];
    pipe(p1p0);

    pid = fork();

    if (pid == 0)
    {
        close(p1p0[0]);//Essendo che cat legge E BASTA allora dobbiamo chiudere il canale input
        close(1);//Liberiamo il nostro canale output dallo standard output del terminale così gli facciamo leggere quello che vogliamo
        dup(p1p0[1]);//Dupplichiamo il canale output della pipe che prendera il post 1 del standrd output del terminale
        close(p1p0[1]);//Chiudiamo il canale che non ci serve
        execl("/usr/bin/cat","cat",argv[1],(char*)0);//Eseguiamo il commando con excel dove gli diamo il percorso del commando che vogliamo eseguire, il commando, cosa vogliamo eseguire che in questo caso è argv[1]
        exit(0);
    }

    pid = fork();

    if (pid == 0)
    {//E il contrario della cat perchè more lovora come input utilizzando le frecci o gli spazi della tastiera
        close(p1p0[1]);
        close(0);
        dup(p1p0[0]);
        close(p1p0[0]);
        execl("/usr/bin/less","less",(char*)0);
        exit(0);
    }
    //Facciamo il close di TUTTO PERCHE IL MAIN NON DEVE FARE NIENTE
    close(p1p0[0]);
    close(p1p0[1]);
    wait(&pid);
    wait(&pid);

    return 0;
    
    
}