#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


int main(int argc, char *argv[]){

    if(argc!=2){
        printf("Errore argomenti \n");
        exit(1);
    }

    char alfabeto[] = "abcdefghijklmnopqrstuvwxyz";
    int fd,nread;
    
    fd = open(argv[1], O_WRONLY | O_CREAT, 0644);/*0644: è la modalità del file, che rappresenta i permessi di accesso 
    (in questo caso, permette la lettura e scrittura per il proprietario, e solo la lettura per gli altri utenti).*/

    write (fd, alfabeto, strlen(alfabeto));//La quantità di dati da scrivere, che in questo caso è la lunghezza della stringa, calcolata con strlen().

    close(fd);

    return 0;
}