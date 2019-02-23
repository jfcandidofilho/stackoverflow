/*******************************************************************************
 * 
 *   Created: fri feb 21 00:58:03 -03 2019
 *   Updated: 
 * 
 *------------------------------------------------------------------------------
 *
 *   exemplo_02 - Made to solve pt.stackoverflow.com/questions/364375/
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


struct estrutura {
    int id;
    };

typedef struct estrutura Estrutura;


void mudando_x(Estrutura *referencia);


int main (void) {

    Estrutura x;

    x.id = 1;
    mudando_x( &x );

    printf("O valor de X é %d\n", x.id);

    return 0;
	
}


void mudando_x(Estrutura *referencia){

    referencia->id = 2;

}
