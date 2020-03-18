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
#define KOKO 30
#define LISTANKOKO 12
#define LEN 80

struct Node{
  char tila[KOKO];
  int epochAika;
  int paiva;
  int kuukausi;
  int vuosi;
  int tunti;
  int minuutti;
  int maara;
  int maksimit[LISTANKOKO];
  struct Node *pNext;
};
typedef struct Node Solmu;

Solmu* lueTiedot(char *tiedostoNimi, Solmu *pAlku);
void tallenna(Solmu *pA, char *tilaNimi);
void tallennaTulosTiedot(Solmu *pA);
/*******************************************************************/
/* eof */
