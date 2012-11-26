/*
* The information in this file is
* Copyright(c) 2012, Gabriele Colosimo, Andrea Nascetti <gabriele.colosimo, andrea.nascetti>@uniroma1.it
* and is subject to the terms and conditions of the
* GNU Lesser General Public License Version 2.1
* The license text is available from
* http://www.gnu.org/licenses/lgpl.html
*/

/* Programma per la risoluzione del problema di Cauchy dell'esercitazione 1  
 * con i tre metodi di Eulero, Heun e Runge-Kutta
 *
 * Calcola la soluzione numerica di equazioni differenziali del primo ordine
 * con il metodo di Eulero esplicito
 * 
 * Funzioni:
 * - f(t,y): termine noto dell’equazione differenziale 
 * - g(t): soluzione analitica del problema di Cauchy
 *
 * Input:
 * - matricola del candidato
 * - selezione del metodo
 *
 * Output:
 * - xi: nodo i-esimo
 * - yi: approssimazione al nodo xi
 * - ei: errore al passo i
 */
 
#include <stdio.h>
#include <math.h>

double f(double x,double y);
double g(double t); 

void eulero (int n, double h, double t0, double y0);
void heun (int n, double h, double t0, double y0);
void runge_kutta (int n, double h, double t0, double y0);
 
int main()
{
	// Allocazione e inizializzazione delle variabili
	int n = 0, metodo = 0;
	double t0 = 0., y0 = 0., h = 0.;
	
	// Recupero dei dati dati di input
	printf("Inserire il numero di matricola = \n");
	scanf("%d", &n);
	
	n = n%1000;
	h = 2.0/n;
	t0 = -2.0;
	y0 = 0.0;

	printf("Selezionare il metodo che si vuole utilizzare 1:Eulero 2:Heun 3:Runge-Kutta \n");
	scanf("%d", &metodo);
		
	printf("n = %d \t h = % 14.8lf \t t0 = % 14.8lf \t y0 = % 14.8lf\n\n",n,h,t0,y0);
	
	if (metodo == 1)
	{
		eulero(n,h,t0,y0);	
	}
	else if (metodo == 2)
	{
		heun(n,h,t0,y0);
	}
	else if (metodo == 3)
	{
		runge_kutta(n,h,t0,y0);
	}
	else
	{
		printf("Errore nella scelta del metodo\n");
	}
		
 	return 0;
}


 double f(double x,double y)
 {
 	return y+cos(x);
 }


 double g(double x)
 {
 	return 0.5*((exp(2+x))*(cos(2)+sin(2))-cos(x)+sin(x));
 }
 
 void eulero (int n, double h, double t0, double y0)
 {
 	int k=0;
	double ti = 0., yi = 0., err = 0.;
	
	FILE *OUT = NULL;
	
    /* Apertura file di output */
	OUT = fopen("Eulero_output.txt", "w");
	// Controllo apertura file
	if(OUT == NULL)
	{
		printf("Errore nell'apertura del file\n");
		printf("Riprovare\n");
		return;
	} /* if */
	
	// Implementazione dell'algoritmo di Eulero
	ti = t0;
	yi = y0;
	
	printf(" Indice      t              y           errore\n");
	
	for (k=1; k<=n; k++)
	{
		yi = yi + h*f(ti,yi);
		ti = ti + h;
		// Calcolo dell'errore
		err = g(ti) - yi;
		// Stampa dei risultati 		
		printf("%4d % 14.8lf % 14.8lf % 14.12e\n", k, ti, yi, err);
		fprintf(OUT, "%4d % 14.8lf % 14.8lf % 14.12e\n", k, ti, yi, err);
	}
	
	fclose(OUT); 
 }
 
  
 void heun (int n, double h, double t0, double y0)
 {
 	int k=0;
	double ti = 0., yi = 0., err = 0.;
	
	FILE *OUT = NULL;
	
    /* Apertura file di output */
	OUT = fopen("Heun_output.txt", "w");
	// Controllo apertura file
	if(OUT == NULL)
	{
		printf("Errore nell'apertura del file\n");
		printf("Riprovare\n");
		return;
	} /* if */
	
	// Implementazione dell'algoritmo di Eulero
	ti = t0;
	yi = y0;
	
	printf(" Indice      t              y           errore\n");
	
	for (k=1; k<=n; k++)
	{
		yi = yi + 0.5*h*(f(ti,yi) + f(ti+h,yi+h*f(ti,yi)));
		ti = ti + h;
		// Calcolo dell'errore
		err = g(ti)-yi;
		// Stampa dei risultati 		
		printf("%4d % 14.8lf % 14.8lf % 14.12e\n", k, ti, yi, err);
		fprintf(OUT, "%4d % 14.8lf % 14.8lf % 14.12e\n", k, ti, yi, err);
	}
	
	fclose(OUT); 
 }
 
  void runge_kutta (int n, double h, double t0, double y0)
 {
 	int k=0;
	double ti = 0., yi = 0., err = 0.;
	
	FILE *OUT = NULL;
	
    /* Apertura file di output */
	OUT = fopen("Runge-Kutta_output.txt", "w");
	// Controllo apertura file
	if(OUT == NULL)
	{
		printf("Errore nell'apertura del file\n");
		printf("Riprovare\n");
		return;
	} /* if */
	
	// Implementazione dell'algoritmo di Eulero
	ti = t0;
	yi = y0;
	
	printf(" Indice      t              y           errore\n");
	
	double k1=0,k2=0,k3=0,k4=0;
	
	for (k=1; k<=n; k++)
	{
		k1 = f(ti,yi);
		k2 = f(ti + 0.5*h, yi + 0.5*h*k1);
		k3 = f(ti + 0.5*h, yi + 0.5*h*k2);
		k4 = f(ti + h, yi + h*k3);
	
		yi = yi + h*(k1 + 2.0*k2 + 2.0*k3 + k4)/6.0;
		ti = ti + h;
		// Calcolo dell'errore
		err = g(ti)-yi;
		// Stampa dei risultati 		
		printf("%4d % 14.8lf % 14.8lf % 14.12e\n", k, ti, yi, err);
		fprintf(OUT, "%4d % 14.8lf % 14.8lf % 14.12e\n", k, ti, yi, err);
	}
	
	fclose(OUT); 
 }
