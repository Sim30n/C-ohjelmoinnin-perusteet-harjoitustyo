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
#include "ali1.h"
#include "ali2.h"

int main(void){
  int nValinta;
  char tiedostoNimi[30];
  char tilaNimi[30];
  Solmu *pAlku = NULL;
  printf("Tämä ohjelma analysoi tilan käyttö -tiedostoja.\n");
  do{
    printf("\n");
    printf("Valitse haluamasi toiminto alla olevasta valikosta:\n");
    printf("1) Lue tilan käyttö -tiedosto\n");
    printf("2) Tallenna listan tiedot\n");
    printf("3) Analysoi tiedot\n");
    printf("0) Lopeta\n");
    printf("Valintasi: ");
    scanf("%d", &nValinta);
    switch (nValinta){
      case 1:
        pAlku = tyhjenna(pAlku);
        printf("Anna luettavan tiedoston nimi: ");
        scanf("%s", tiedostoNimi);
        pAlku = lueTiedot(tiedostoNimi);
        break;
      case 2:
        if (pAlku != NULL){
          printf("Anna opetustilan nimi: ");
          scanf("%s", tilaNimi);
          tallenna(pAlku, tilaNimi);
        } else {
          printf("Ei tallennettavaa, lue ensin käyttötiedosto.\n");
        }
        break;
      case 3:
        if (pAlku != NULL){
          printf("Anna opetustilan nimi: ");
          scanf("%s", tilaNimi);
          analysoi(pAlku, tilaNimi);
        } else {
          printf("Ei analysoitavaa, lue ensin käyttötiedosto.\n");
        }
        break;
      case 0:
        pAlku = tyhjenna(pAlku);
        printf("Kiitos ohjelman käytöstä.\n");
        printf("\n");
        break;
      default:
        printf("Tuntematon valinta, yritä uudestaan.\n");
        break;
    }
  } while(nValinta != 0);

  return(0);
}

/*******************************************************************/
/* eof */
