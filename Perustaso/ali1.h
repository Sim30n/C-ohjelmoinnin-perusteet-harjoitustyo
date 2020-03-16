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
struct Node{
  char tila[30];
  int epochAika;
  int paiva;
  int kuukausi;
  int vuosi;
  int tunti;
  int minuutti;
  int maara;
  struct Node *pNext;
};
typedef struct Node Solmu;
Solmu* lueTiedot(char *tiedostoNimi);
void tallenna(Solmu *pA, char *tilaNimi);
/*******************************************************************/
/* eof */
