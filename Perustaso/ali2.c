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

Solmu* solmuLisaa(Solmu *pA, char *tila, int epochAika, int paiva,
  int kuukausi, int vuosi, int tunti, int minuutti, int maara){
  Solmu *ptr, *ptrUusi;
  // muistin varaus
  if((ptrUusi=(Solmu*)malloc(sizeof(Solmu))) == NULL){
    perror("Muistin varaus epäonnistui");
    exit(1);
  }
  // solmun alustus
  strcpy(ptrUusi -> tila, tila);
  ptrUusi -> epochAika = epochAika;
  ptrUusi -> paiva = paiva;
  ptrUusi -> kuukausi = kuukausi;
  ptrUusi -> vuosi = vuosi;
  ptrUusi -> tunti = tunti;
  ptrUusi -> minuutti = minuutti;
  ptrUusi -> maara = maara;
  ptrUusi -> pNext = NULL;
  // uuden alkion lisäys listaan
  if (pA == NULL){
    pA = ptrUusi;
  } else {
    ptr = pA;
    while(ptr->pNext != NULL){
      ptr = ptr->pNext;
    }
    ptr->pNext = ptrUusi;
  }
  return pA;
}

Solmu *tyhjenna(Solmu *pA){
  Solmu *ptr = pA;
  while(ptr != NULL){
    pA = ptr->pNext;
    free(ptr);
    ptr = pA;
  }
  return pA;
}

void analysoi(Solmu *pA, char *tilaNimi){
  int rivit = 0;
  int sum = 0;
  int min = 0;
  int max = 0;
  Solmu *ptr = pA;
  while(ptr != NULL){
    if(strcmp(tilaNimi, ptr->tila) == 0){
      if(min>ptr->maara){
        min = ptr->maara;
      }
      if(max<ptr->maara){
        max = ptr->maara;
      }
      sum += ptr->maara;
      rivit++;
    }
    ptr = ptr->pNext;
  }
  printf("Opetustilan %s käyttöanalyysi, %d alkiota:\n",tilaNimi, rivit);
  printf("  Avg  Min  Max\n");
  printf("%5d%5d%5d\n", sum/rivit, min, max);
}
/*******************************************************************/
/* eof */
