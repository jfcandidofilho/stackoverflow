/*******************************************************************************
 * 
 *   Created: mon mar 26 16:37:04 -03 2019
 *   Updated: 
 * 
 *------------------------------------------------------------------------------
 *
 *   programa - Made to solve pt.stackoverflow.com/questions/371255/
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


#define LINHAS 5
#define COLUNAS 5


typedef struct matriz
{
    int n_elementos;
    int **elementos;

} Matriz;


void criar_matriz( Matriz *m, int mat[5][5] );
void imprimir_matriz( Matriz *m );
void limpar_matriz( Matriz *m );


int main( void ){
    
    Matriz m;
    int mat[LINHAS][COLUNAS] = { 
        {   0, 185, 119, 152, 133 }, 
        { 185,   0, 121, 150, 200 }, 
        { 199, 121,   0, 174, 120 }, 
        { 152, 150, 174,   0, 199 }, 
        { 133, 200, 120, 199,   0 } 
    };

    criar_matriz( &m, mat );
    
    imprimir_matriz( &m );
    
    limpar_matriz( &m );
    
    return 0;
    
}


void criar_matriz( Matriz *m, int mat[5][5] ){
    
    int i, j;
    
    m->n_elementos = LINHAS * COLUNAS;
    
    m->elementos = (int **) malloc( LINHAS * sizeof(int *) );
    
    for ( i = 0; i < LINHAS; i++ ){
        
        m->elementos[i] = (int *) calloc( COLUNAS , sizeof(int) );
        
        for ( j = 0; j < COLUNAS; j++ ) m->elementos[i][j] = mat[i][j];
        
    }
    
}

void imprimir_matriz( Matriz *m ){
    
    int i, j;
    
    printf("\nMatriz\n\n");

    for( i = 0; i < LINHAS; i++ ){
        
        for( j = 0; j < COLUNAS; j++ ) printf("%d ", m->elementos[i][j]);

        printf("\n");
        
    }
    
    printf("\n");
    
}

void limpar_matriz( Matriz *m ){
 
    int i;
    
    for( i = 0; i < LINHAS; i++ ){
            
        free(m->elementos[i]);
        
        m->elementos[i] = NULL;
            
    }
    
    free(m->elementos);
    
    m->elementos = NULL;
    
}
