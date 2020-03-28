/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot:
 * Tekijä: Petteri Särkkä
 * Opiskelijanumero: 0556780
 * Päivämäärä: 28.3.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto: Ei yhteistyötä,
 * lähde kurssimateriaali.
 */
/*******************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "ali1.h"
#include "ali2.h"

// pääohjelma
int main(void){
  int nValinta;
  char tiedostoNimi[KOKO];
  char tilaNimi[KOKO];
  char pvm[KOKO];
  Solmu *pAlku = NULL;
  Solmu *pAlkuKaytto = NULL;
  printf("Tämä ohjelma analysoi tilan käyttö -tiedostoja.\n");
  do{
    printf("\n");
    printf("Valitse haluamasi toiminto alla olevasta valikosta:\n");
    printf("1) Lue tilan käyttö -tiedosto\n");
    printf("2) Tallenna listan tiedot\n");
    printf("3) Analysoi tiedot\n");
    printf("4) Suorita käyttöanalyysi opetustilalle\n");
    printf("5) Tulosta kaikki tulokset\n");
    printf("6) Tallenna tulokset tiedostoon\n");
    printf("7) Tyhjennä analyysilista\n");
    printf("0) Lopeta\n");
    printf("Valintasi: ");
    scanf("%d", &nValinta);
    switch (nValinta){
      case 1:
        kysyTiedostonimi(tiedostoNimi);
        pAlku = lueTiedot(tiedostoNimi, pAlku, pAlkuKaytto);
        break;
      case 2:
        if (pAlku != NULL){
          kysyTilanimi(tilaNimi);
          tallenna(pAlku, tilaNimi, pAlkuKaytto);
        } else {
          printf("Ei tallennettavaa, lue ensin käyttötiedosto.\n");
        }
        break;
      case 3:
        if (pAlku != NULL){
          kysyTilanimi(tilaNimi);
          analysoi(pAlku, tilaNimi);
        } else {
          printf("Ei analysoitavaa, lue ensin käyttötiedosto.\n");
        }
        break;
      case 4:
        if (pAlku != NULL){
          kysyTilanimi(tilaNimi);
          kysyPvm(pvm);
          tyhjenna(pAlkuKaytto);
          pAlkuKaytto = analysoiKaytto(pAlku, tilaNimi, pvm);
          if(pAlkuKaytto != NULL){
            printf("Aikavälianalyysi valmis.\n");
          } else {
            printf("Ei analysoitavia alkioita\n");
          }
        } else {
          printf("Ei analysoitavaa, lue ensin käyttötiedosto.\n");
        }
        break;
      case 5:
        if(pAlkuKaytto != NULL){
          tulosta(pAlkuKaytto);
        } else {
          printf("Tuloslista on tyhjä.\n");
        }
        break;
      case 6:
        if(pAlkuKaytto != NULL){
          tallennaTulosTiedot(pAlkuKaytto, pAlku);
        } else {
          printf("Tuloslista on tyhjä.\n");
        }
        break;
      case 7:
        pAlkuKaytto = tyhjenna(pAlkuKaytto);
        printf("Tuloslista tyhjennetty.\n");
        break;
      case 0:
        pAlkuKaytto = tyhjenna(pAlkuKaytto);
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
