/*
* The information in this file is
* Copyright(c) 2012, Gabriele Colosimo, Andrea Nascetti <gabriele.colosimo, andrea.nascetti>@uniroma1.it
* and is subject to the terms and conditions of the
* GNU Lesser General Public License Version 2.1
* The license text is available from
* http://www.gnu.org/licenses/lgpl.html
*/

/* Programma per la generazione di un Sistema Lineare AX = B 
 * in funzione della matricola del candidato.
 *
 * Input: Matricola
 *
 * Output: file ASCII MatriceA.dat e VettoreB.dat (per controllare il loro contenuto
 *         possono essere aperti con un qualsiasi editor di testo, non è consigliato 
 *         l'utilizzo del blocco note di windows)
 *
 * Per compilare il programma eseguire il comando:
 * gcc -Wall -o generatore_sistema.out generatore_sistema.c 
 *
 * Per eseguire il programma dal terminale:
 * ./generatore_sistema.out
 *
 */ 
 
#include <stdio.h>

int main()
{
	int i=0,j=0;
	char str[8] = {'\0'};

	printf("Inserire il numero di matricola = \n");
	scanf("%s", str);	
	printf("La tua matricola inserita:  %s\n\n", str);
	
	FILE *MatA, *VetB;
	MatA = fopen("MatriceA.dat","w");
	VetB = fopen("VettoreB.dat","w");
		
	int N =6;
	printf("%10s %75s\n\n","MatriceA","VettoreB");
		
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(j == i)
			{
			    printf("%10.5lf", 1.0+i+str[i]-'0'); 
			    fprintf(MatA,"% 10.5lf ", 1.0+i+str[i]-'0');
			}
			else if(j == i-1){
				printf("%10.5lf", 1.0/(double)(1.0+str[i-1]-'0'));
				fprintf(MatA,"% 10.5lf ", 1.0/(double)(1.0+str[i-1]-'0'));}
			else if(j == i + 1){
				printf("%10.5lf", (double)((1+str[i]-'0')+(1+str[i]-'0'))/(double)((1+str[i]-'0')*(1+str[i]-'0')));
				fprintf(MatA,"% 10.5lf ", (double)((1.0+str[i]-'0')+(1.0+str[i]-'0'))/(double)((1.0+str[i]-'0')*(1.0+str[i]-'0')));}
			else {
				printf("%10.5lf", 0.);
				fprintf(MatA,"% 10.5lf ", 0.);}
		}
		if (i == 0) { 
			printf("%25.5lf",1.);
			fprintf(VetB,"%10.5lf",1.);}
		else {
			printf("%25.5lf",0.);
			fprintf(VetB,"%10.5lf",0.);}
		printf("\n");
		fprintf(MatA,"\n");
		fprintf(VetB,"\n");
	}
	fclose(MatA);
	fclose(VetB);
	printf("\nSono stati generati correttamente i due file 'MatriceA.dat' e 'VettoreB.dat'\n");	
	printf("Utilizzare i file generati per risolvere il sistema lineare AX = B\n");
	
	return 0;	
}
