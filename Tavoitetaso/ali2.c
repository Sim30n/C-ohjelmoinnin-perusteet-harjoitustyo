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
#include <time.h>
#include "ali1.h"
#include "ali2.h"
// lisätään alkio linkitetyn listan päähän
Solmu* solmuLisaa(Solmu *pA, char *tila, int epochAika, int paiva,
  int kuukausi, int vuosi, int tunti, int minuutti, int maara, int *maksimit){
  Solmu *ptr, *ptrUusi;
  int jLuku;
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
  // lista maksimiarvoja varten
  for (jLuku=0; jLuku<SARAKE; jLuku++){
    ptrUusi -> maksimit[jLuku] = maksimit[jLuku];
  }
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
// analysoidaan käyttötiedot ja luodaan uusi linkitetty lista, case 4
Solmu *analysoiKaytto(Solmu *pA, char *tilaNimi, char *pvm){
  int pv = atoi(strtok(pvm , "."));
  int kk = atoi(strtok(NULL, "."));
  int vv = atoi(strtok(NULL, "."));
  Solmu *ptr  = pA;
  Solmu *ptrTark = pA;
  Solmu *pAlku = NULL;
  int jLuku  = 0;
  int max = 0;
  int epochVertaa = 1;
  int maksimit[KOKO] = {0,0,0,0,0,0,0,0,0,0,0,0};
  int pvmToEpoch = 0;
  while(ptr != NULL){
    /* tarkistetaan käyttäjän antama päivämäärä ja muutetaan se epoch ajaksi
    tiedotossa olevan datan avulla */
    if(pv == ptr->paiva && kk == ptr->kuukausi && vv == ptr->vuosi
      && epochVertaa != 0){
          pvmToEpoch = ptr->epochAika;
          epochVertaa = 0;
        }
    // huomioidaan ainoastaan listan alkiot joiden päivämäärä on annetun jälkeen
    if(strcmp(tilaNimi, ptr->tila) == 0 && pvmToEpoch <= ptr->epochAika
      && pvmToEpoch != 0){
      // huomiodaan vain aikaväli 7-19
      while(ptr->tunti < 19 && ptr->tunti > 6){
        ptrTark = ptr;
        if(max<ptr->maara){
          max = ptr->maara;
        }
        ptr = ptr->pNext;
        // alustetaan maksimt listan arvot
        if(ptrTark->tunti != ptr->tunti){
          maksimit[jLuku] = max;
          max = 0;
          jLuku++;
        }
      }
      if(ptr->tunti>18){
        // luodaan linkitetty lista
        pAlku = solmuLisaa(pAlku, tilaNimi, 0, ptrTark->paiva,
                      ptrTark->kuukausi, ptrTark->vuosi, 0, 0, 0, maksimit);
        jLuku = 0;
        pvmToEpoch = pvmToEpoch+604800;
      }
    }
    ptr = ptr->pNext;
  }
  return pAlku;
}

// tyhjennetään lista, csae 7
Solmu *tyhjenna(Solmu *pA){
  Solmu *ptr = pA;
  while(ptr != NULL){
    pA = ptr->pNext;
    free(ptr);
    ptr = pA;
  }
  return pA;
}
// tulostetaan käyttöanalyysi, case 5
void tulosta(Solmu *pA){
  Solmu *ptr = pA;
  int i;
  while(ptr != NULL){
    printf("Opetustilan %s käyttöanalyysi %d.%d.%d\n",ptr->tila, ptr->paiva,
            ptr->kuukausi, ptr->vuosi);
    printf("Klo:");
    for(i=7; i<19; i++){
      printf("%5d",i);
    }
    printf("\n");
    printf("Lkm:");
    for(i=0; i<12; i++){
      printf("%5d",ptr->maksimit[i]);
    }
    printf("\n");
    ptr = ptr->pNext;
  }
}
// analysoidaan käyttö, case 3
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
  if(sum != 0 && rivit != 0){
    printf("%5d%5d%5d\n", sum/rivit, min, max);
  }  
}

void kysyTiedostonimi(char *tiedostoNimi){
  printf("Anna luettavan tiedoston nimi: ");
  scanf("%s", tiedostoNimi);
}

void kysyTilanimi(char *tilaNimi){
  printf("Anna opetustilan nimi: ");
  scanf("%s", tilaNimi);
}

void kysyPvm(char *pvm){
  printf("Anna päivämäärä (päivä.kuukausi.vuosi): ");
  scanf("%s", pvm);
}
/*******************************************************************/
/* eof */
