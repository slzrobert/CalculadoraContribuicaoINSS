#include <iostream>
#include <stdio.h>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define FAIXA1 1100.00
#define FAIXA2 2203.48
#define FAIXA3 3305.22
#define FAIXA4 6433.57

#define FAIXA1_PERC 0.075
#define FAIXA2_PERC 0.09
#define FAIXA3_PERC 0.12
#define FAIXA4_PERC 0.14

main(int argc, char** argv) {
	
	double resultado, salario;
	
	cout << "=== CALCULADORA DESCONTO INSS ( CONTRIBUICAO ) === " << endl << endl;
	
	cout << "Calcula o teto do INSS conforme as novas regras para aposentadoria,\naplicando as aliquotas de forma progressiva." << endl << endl;
	
	cout << "VALOR DO SALARIO BRUTO (ex.: 1100.00): ";
	cin >> salario;
	
	cout << endl << endl;
	
	if ( salario <= FAIXA1 ){
		
		resultado = (salario * FAIXA1_PERC); // 7,5%
		printf("FAIXA 1 - CONTRIBUICAO DE R$ %.2f \n", resultado);
		
	}
	else if(salario > FAIXA1 && salario <= FAIXA2){
		
		resultado = (FAIXA1 * FAIXA1_PERC);
		
		if( salario < FAIXA2 ){
			resultado += (salario - FAIXA1) * FAIXA2_PERC;
		}
		else {
			resultado += (FAIXA2 - FAIXA1) * FAIXA2_PERC; // 9%
		}
		
		printf("FAIXA 2 - CONTRIBUICAO DE R$ %.2f \n", resultado);
		
	}
	else if(salario > FAIXA2 && salario <= FAIXA3){
		
		resultado = (FAIXA1 * FAIXA1_PERC);
		resultado += (FAIXA2 - FAIXA1) * FAIXA2_PERC;
		
		if( salario < FAIXA3 ){
			resultado += (salario - FAIXA2) * FAIXA3_PERC;
		}
		else {
			resultado += (FAIXA3 - FAIXA2) * FAIXA3_PERC; // 12%
		}
		
		printf("FAIXA 3 - CONTRIBUICAO DE R$ %.2f \n", resultado);
		
	}
	else if(salario > FAIXA3){
		
		resultado = (FAIXA1 * FAIXA1_PERC);
		resultado += (FAIXA2 - FAIXA1) * FAIXA2_PERC;
		resultado += (FAIXA3 - FAIXA2) * FAIXA3_PERC;
		
		if( salario < FAIXA4 ){
			resultado += (salario - FAIXA3) * FAIXA4_PERC;
		}
		else {
			resultado += (FAIXA4 - FAIXA3) * FAIXA4_PERC; // 14%
		}
		
		printf("FAIXA 4 - CONTRIBUICAO DE R$ %.2f \n", resultado);
	
	}
}
