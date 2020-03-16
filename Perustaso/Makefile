HarjPerustaso: paaohjelma.o ali1.o ali2.o
	gcc paaohjelma.o ali1.o ali2.o -o HarjPerustaso -Wall -std=c99 -pedantic
paaohjelma.o: paaohjelma.c ali1.h ali2.h
	gcc paaohjelma.c -c -Wall -std=c99 -pedantic
ali1.o: ali1.c ali1.h
	gcc ali1.c -c -Wall -std=c99 -pedantic
ali2.o: ali2.c ali2.h
	gcc ali2.c -c -Wall -std=c99 -pedantic
