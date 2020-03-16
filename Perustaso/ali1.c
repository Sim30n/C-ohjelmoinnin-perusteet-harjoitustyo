/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot:
 * Tekijä: Petteri Särkkä
 * Opiskelijanumero: 0556780
 * Päivämäärä: 24.2.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto: Ei yhteistyötä,
 * lähde kurssimateriaali.
 */
/*******************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ali1.h"
#include "ali2.h"
#define LEN 80

Solmu *lueTiedot(char *tiedostoNimi){
  int rivit = 0;
  int epochAika; int paiva; int kuukausi; int vuosi; int tunti;
  int minuutti; int maara;
  //char tila[30];
  Solmu *pAlku = NULL;
  FILE* tiedosto;
  char rivi[LEN], *tila;
  printf("Luetaan tiedosto '%s'\n", tiedostoNimi);
  if((tiedosto = fopen(tiedostoNimi, "r"))==NULL){
    perror("Tiedoston lukeminen epäonnistui");
    exit(0);
  }
  // listan luominen
  fgets(rivi, LEN, tiedosto); // luetaan ensimmäinen rivi pois
  while (fgets(rivi, LEN, tiedosto) != NULL){
    if (rivi[0] != '\n'){
      tila = strtok(rivi , ";");
      epochAika = atoi(strtok(NULL, ";"));
      paiva = atoi(strtok(NULL, ";"));
      kuukausi = atoi(strtok(NULL, ";"));
      vuosi = atoi(strtok(NULL, ";"));
      tunti = atoi(strtok(NULL, ";"));
      minuutti = atoi(strtok(NULL, ";"));
      maara = atoi(strtok(NULL, ";"));
    }
    pAlku = solmuLisaa(pAlku, tila, epochAika, paiva, kuukausi, vuosi, tunti,
      minuutti, maara);
    rivit++;
  }
  printf("Tiedosto '%s' luettu, %d riviä.\n",tiedostoNimi, rivit);
  fclose(tiedosto);
  return pAlku;
}

void tallenna(Solmu *pA, char *tilaNimi){
  FILE* tiedosto;
  Solmu *ptr = pA;
  if ((tiedosto = fopen("tulostiedot.txt", "w")) == NULL){
    perror("Tiedostoon kirjoittaminen epäonnistui");
    exit(0);
  }
  fprintf(tiedosto, "Opetustila: %s\n", tilaNimi);
  fprintf(tiedosto, "Pvm Klo Lkm\n");
  while(ptr != NULL){
    if(strcmp(tilaNimi, ptr->tila) == 0){
      fprintf(tiedosto, "%d.%d.%d %02d:%02d %d\n", ptr->paiva, ptr->kuukausi,
        ptr->vuosi, ptr->tunti, ptr->minuutti, ptr->maara);
    }
    ptr = ptr->pNext;
  }
  fclose(tiedosto);
  printf("Käyttödata tallennettu.\n");
}

/*******************************************************************/
/* eof */
