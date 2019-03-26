/*******************************************************************************
 * 
 *   Created: mon mar 25 22:12:24 -03 2019
 *   Updated: 
 * 
 *------------------------------------------------------------------------------
 *
 *   programa - Made to solve pt.stackoverflow.com/questions/370931/
 * 
 *   Copyright (C) 2019 J. F. Candido Filho <jfcandidofilho [at] gmail.com>
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
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int isPerfect(int *number) {
    
    size_t i;   /* Boa prática para laços */
    int    sum;
    
    sum = 0;
    
    for( i = 1; i < (size_t) *number; ++i ) if( *number % i == 0 ) sum += i;
    
    if( sum == *number ) return 1; /* É perfeito */
    else                 return 0; /* Não é perfeito */
    
}


int main( int argc, char **argv )  {

    int *number;
    
    
    setlocale(LC_ALL, "Portuguese");

    
    number = (int *) malloc(sizeof(int));
    
    if( argc > 1 ) *number = atoi( argv[1] );
    else {
    
        printf("> Digite um número inteiro: ");
        scanf("%d", number);

    }
    
    
    if( isPerfect( number ) ) printf("> %d é número perfeito\n", *number);
    else                      printf("> %d não é número perfeito\n", *number);

    
    return 0;
    
}
