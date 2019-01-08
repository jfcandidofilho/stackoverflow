/*******************************************************************************
 * 
 *   Created: tue jan 08 02:21:57 -02 2019
 *   Updated: 
 * 
 *------------------------------------------------------------------------------
 *
 *   [no name] - Made to solve pt.stackoverflow.com/questions/354602/
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
 ******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define ARQUIVO "./entrada.txt"

#define EOL '\n'


typedef struct _materia { /* Evite ambos 'typedef' e struct compartilhar nome */
    
    char nome[20];          /* 'nome' é melhor - referencia a matéria */
    char dia_semana[7][15]; /* 'dia_semana' é melhor (auto-explicativo) */
    
} materias;


void ler_disciplinas ();


int main(){
    
    materias m[100];
    FILE *f;
    
    printf("\n");
    
    f = fopen( ARQUIVO, "r" );
    
    fseek( f, 0L, SEEK_END ); 
    
    if( ftell( f ) > 0 ){ /* Só chama 'ler_disciplinas()' se 'f' não é vazio */
    
        rewind( f );
        
        ler_disciplinas( m, f );
    
    }
    
    fclose( f );
    
    printf("\n");
    
    /* Sempre retorne algum valor se sua main tem algum tipo (i.e. 'int') */
    return 0;
    
}


void ler_disciplinas( materias *m, FILE *f ){
    
    /* Nesta função:
    * 
    * - não faça o laço 'for' sem argumentos pois é uma péssima prática;
    * - há uma série de problemas quanto ao uso dos índices i, j, k;
    * - há uma série de problemas quanto ao uso de laços;
    * - há uma série de problemas quanto ao uso de ponteiros;
    * 
    * ! Atente-se ao funcionamento de laços e ponteiros. Reescrevi quase tudo.
    * 
    */
    
    int i, k, j;
    char temp;
    
    for( i = 0; i < 100; i++ ){
        
        j = -1;
        
        do { /* Obtém nome da materia */
            
            ++j;
            
            temp = fgetc( f );
            
            if( temp == ' ' || temp == EOL ) { /* EOL == Fim de linha */
                
                m[i].nome[j] = '\0'; /* Fecha a string */
                
                printf( "\t%s", m[i].nome );
            
                j = -1;     /* Sai do laço DO (j) */
                
            } else if( temp == EOF ){  /* EOF == Fim de arquivo */
                
                j = -1;     /* Sai do laço DO (j) */
                i = 100;    /* Sai do laço FOR (i) */
                
            } else {
                
                m[i].nome[j] = temp;
                
            }
            
        } while( j != -1 );
        
        
        for(j = 0; j < 7; j++){ /* Índice do dia da semana */
        
            k = 0;
            
            while (k != -1 ){ /* Obtém o nome do dia da semana */
                
                temp = fgetc( f );
            
                if( temp == ' ' ) {
                    
                    m[i].dia_semana[j][k] = '\0'; /* Fecha a string */
                    
                    printf( " %s", m[i].dia_semana[j] );
                    
                    k = -1;     /* Sai do laço WHILE (k) */
                    
                } else if( temp == EOL ) { /* EOL == Fim de linha */
                    
                    m[i].dia_semana[j][k] = '\0'; /* Fecha a string */
                    
                    printf( " %s\n", m[i].dia_semana[j] );
                    
                    k = -1;     /* Sai do laço WHILE (k) */
                    j = 7;      /* Sai do laço FOR (j) */
                    
                } else if( temp == EOF ){ /* EOF == Fim de arquivo */
                    
                    k = -1;     /* Sai do laço WHILE (k) */
                    j = 7;      /* Sai do laço FOR (j) */
                    i = 100;    /* Sai do laço FOR (i) */
                    
                } else {
                    
                    m[i].dia_semana[j][k] = temp;
                    
                    k++;
                    
                }
                
            }
            
        }
        
    }
    
}
