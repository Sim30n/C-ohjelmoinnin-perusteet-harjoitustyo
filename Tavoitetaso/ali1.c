/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot:
 * Tekijä: Petteri Särkkä
 * Opiskelijanumero: 0556780
 * Päivämäärä: 28.2.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto: Ei yhteistyötä,
 * lähde kurssimateriaali.
 */
/*******************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ali1.h"
#include "ali2.h"

// luetaan tiedot annetusta tiedostosta ja lisätään luodaan linkitetty lista
Solmu *lueTiedot(char *tiedostoNimi, Solmu *pAlku){
  if(pAlku != NULL){
    tyhjenna(pAlku);
  }
  pAlku = NULL;
  int rivit = 0;
  int epochAika; int paiva; int kuukausi; int vuosi; int tunti;
  int minuutti; int maara;
  int maksimit[LISTANKOKO]= {0,0,0,0,0,0,0,0,0,0,0,0};
  FILE* tiedosto;
  char rivi[LEN];
  char *tila;
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
    // lisätään tidot linkitetyn listan päähän
    pAlku = solmuLisaa(
      pAlku, tila, epochAika, paiva, kuukausi, vuosi, tunti,
      minuutti, maara, maksimit);
    rivit++;
  }
  printf("Tiedosto '%s' luettu, %d riviä.\n",tiedostoNimi, rivit);
  fclose(tiedosto);
  return pAlku;
}

// tallennetaan käyttötiedot tiedostoon, case 2
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
// tallennetaan käyttöanalyysin tulostiedot, case 6
void tallennaTulosTiedot(Solmu *pA){
  FILE* tiedosto;
  Solmu *ptr = pA;
  int i;
  if ((tiedosto = fopen("tulostiedot.csv", "w")) == NULL){
    perror("Tiedostoon kirjoittaminen epäonnistui");
    exit(0);
  }
  fprintf(tiedosto, "Klo;07:00-08:00;08:00-09:00;09:00-10:00;10:00-11:00;"
                    "11:00-12:00;12:00-13:00;13:00-14:00;14:00-15:00;"
                    "15:00-16:00;16:00-17:00;17:00-18:00;18:00-19:00\n");
  while(ptr != NULL){
    fprintf(tiedosto, "%s %d.%d.%d",ptr->tila, ptr->paiva, ptr->kuukausi,
            ptr->vuosi);
    for(i=0; i<12; i++){
      fprintf(tiedosto, ";%d",ptr->maksimit[i]);
    }
    fprintf(tiedosto,"\n");
    ptr = ptr->pNext;
  }
  fclose(tiedosto);
  printf("Tiedot tallennettu tiedostoon: 'tulostiedot.csv'\n");
}

/*******************************************************************/
/* eof */
