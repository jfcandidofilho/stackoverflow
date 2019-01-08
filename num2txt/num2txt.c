/*******************************************************************************
* 
*   Created: sat sep 10 21:18:53 -03 2016
*   Updated: tue jan 08 00:39:46 -02 2019
* 
*-------------------------------------------------------------------------------
*
*   num2txt - transforms natural numbers' symbols (0-999) into spelled text form
* 
*   Copyright (C) 2016 J. F. Candido Filho <jfcandidofilho [at] gmail.com>
* 
*   This program is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main( int argc, char **argv ) {

    /* Declaração de variáveis */
    short unsigned int numero, unidade, dezena, centena;

    /* Nomes das unidades numéricas */
    char * nomes_unidades[] = {
        "Zero", "Um", "Dois", "Três", "Quatro",
        "Cinco", "Seis", "Sete", "Oito", "Nove"
    };
    /* Nomes das dezenas numéricas */
    char * nomes_dezenas[] = {
        "", "", "Vinte", "Trinta", "Quarenta",
        "Cinquenta", "Sessenta", "Setenta", "Oitenta", "Noventa"
    };
    /* Nomes das centenas numéricas */
    char * nomes_centenas[] = {
        "", "Cento", "Duzentos", "Trezentos", "Quatrocentos",
        "Quinhentos", "Seiscentos", "Setecentos", "Oitocentos", "Novecentos"
    };
    /* Nomes especiais de dezenas numéricas */
    char * nomes_especiais[] = {
        "Dez", "Onze", "Doze", "Treze", "Catorze",
        "Quinze", "Dezesseis", "Dezessete", "Dezoito", "Dezenove"
    };

    /* Entrada de dados para execução do programa */
    if( argc > 1 ) {

        /* Converte 'string' para integer e faz typecast para unsigned short int  */
        numero = (unsigned short int) atoi( argv[1] );

        /* Verifica se a entrada obedeve as regras */
        if( numero > 999 || numero < 0 ){
            
            printf("\nATENÇÂO:\n");
            printf("O número deve ser um inteiro e estar no intervalo [0,999]\n\n");

            return( 0 );
            
        }

    } 
    /* Explica como se dá o uso do programa caso inexista entrada */
    else {
        
        printf("\nUso: ./num2txt número\n");
        printf("O número deve ser um natural e estar no intervalo [0,999]\n\n");

        return( 0 );
        
    }

    /* Separador do número em unidade, dezena e centena */
    unidade = numero % 10;
    dezena  = ( numero / 10 ) % 10;
    centena = numero / 100;

    /* Informações de saida */
    printf("\nNúmero: %3hu\n\n", numero);
    printf(
        "\tUnidade: %3hu\n\tDezena: %3hu\n\tCentena: %3hu\n\n",
        unidade, dezena, centena
    );
    printf("Resultado: ");

    /* Conversor das centenas com 'printf' & configurador da unidade ZERO */
    if( centena > 0 && ( dezena > 0 || unidade > 0 ) ){
        
        printf("%s e ", nomes_centenas[centena]);
        
    } else {

        if( centena == 1 ) printf("Cem");
        else printf("%s", nomes_centenas[centena]);

        /* Faz não imprimir "Zero" com centenas maiores que 0 e unidade = 0
         * Também permite não ter que repetir o conversor de dezenas e unidades 
         */
        if( centena > 0 ) nomes_unidades[0] = "";
        
    }

    /* Conversor de dezenas e unidades com 'printf' */
    if( dezena > 1 ){

        if( unidade > 0){
            
            printf("%s e %s", nomes_dezenas[dezena], nomes_unidades[unidade]);
            
        } else printf("%s", nomes_dezenas[dezena]);

    } else {

        if( dezena == 1 ) printf("%s", nomes_especiais[unidade]);
        else printf("%s", nomes_unidades[unidade]);

    }

    /* Pulo de linhas - visual apenas */
    printf("\n\n");

    /* Encerra o programa */
    return( 0 );

}
