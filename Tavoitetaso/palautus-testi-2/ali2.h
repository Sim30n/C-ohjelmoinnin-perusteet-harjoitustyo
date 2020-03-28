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
# define RIVI 9
# define SARAKE 12

Solmu* solmuLisaa(Solmu *pA, char *tila, int epochAika, int paiva,
  int kuukausi, int vuosi, int tunti, int minuutti, int maara, int *maksimit);
Solmu *tyhjenna(Solmu *pA);
Solmu *analysoiKaytto(Solmu *pA, char *tilaNimi, char *pvm);
void analysoi(Solmu *pA, char *tilaNimi);
void tulosta(Solmu *pA);
void kysyTiedostonimi(char *tiedostoNimi);
void kysyTilanimi(char *tilaNimi);
void kysyPvm(char *pvm);
/*******************************************************************/
/* eof */
