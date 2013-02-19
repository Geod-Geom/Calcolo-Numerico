/*
* The information in this file is
* Copyright(c) 2012, Gabriele Colosimo, Andrea Nascetti <gabriele.colosimo, andrea.nascetti>@uniroma1.it
* and is subject to the terms and conditions of the
* GNU Lesser General Public License Version 2.1
* The license text is available from
* http://www.gnu.org/licenses/lgpl.html
*/

/* Programma per la generazione di un set di punti appartenenti ad una retta
 * la cui equazione è funzione della matricola del candidato.
 * Ai punti viene aggiunto un errore secondo una funzione random.
 * 
 * Input: Matricola
 *
 * Output: file Vettore.dat
 *
 * Per compilare il programma eseguire il comando:
 * gcc -Wall -o generatore_retta.out generatore_retta.c 
 *
 * Per eseguire il programma dal terminale:
 * ./generatore_retta.out
 *
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int i=0;
	char str[8] = {'\0'};
	const double rand_norm = 1.0/(RAND_MAX + 1.0);
	double a, b; /* Coefficiente angolare e intercetta della retta */
	FILE *OUT=NULL;
	
	printf("Inserire il numero di matricola = \n");
	scanf("%s", str);	
	printf("La tua matricola inserita:  %s\n\n", str);
	
	a = b = 0.;
	a = atof(str)/1e8;
	char buf[2] = {'\0'};
	strncpy(buf, str, 2);
	b = atof(buf);
	
	printf("La retta relativa alla matricola ha coefficiente angolare e intercetta pari a:\n");
	printf("a = %10.4lf  b = %10.4lf\n", a, b);
	
	/* Apertura file Vettore.dat */	
	OUT = fopen("Vettore.dat", "w");
	if(OUT == NULL)
	{
		printf("Impossibile aprire il file %s in scrittura\n", "Vettore.dat");
		printf("Riprovare\n");
	}
		
	for(i=-500; i <= 500; i++)
		fprintf(OUT, "%3d   %12lf\n", i, a*i + b + rand_norm*rand());
	
	fclose(OUT);

	printf("Il file \"Vettore.dat\" e' stato correttamente generato\n");

	return 0;
}













