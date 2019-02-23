/*******************************************************************************
 * 
 *   Created: thu feb 21 02:31:37 -03 2019
 *   Updated: sat deb 23 00:56:32 -03 2019
 * 
 *------------------------------------------------------------------------------
 *
 *   verBilheteria - Made to solve pt.stackoverflow.com/questions/363858/
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

#include <iostream>
#include <vector>


int main(void){
    
    /* 
     * Declarações
     */
    
    int qtd_pessoas, altura, contagem;
    
    std::size_t i;
    
    std::vector<int> alturas;
    
    
    /* 
     * Obtém a quantidade de pessoas as respectivas alturas 
     */
    
    std::cin >> qtd_pessoas;
    
    alturas.reserve( qtd_pessoas );
    
    for( i = 0; i < (size_t) qtd_pessoas; i++ ) std::cin >> alturas[i];
    
    
    /*
     * Verifica quantos conseguem ver a bilheteria
     */
    
    altura   = alturas[0];
    contagem = 1;
    
	for( i = 1; i < (size_t) qtd_pessoas; i++ ) if( alturas[i] > altura ){
            
            contagem++;
            
            altura = alturas[i];
            
        }
    
    std::cout << contagem << std::endl;
    
    
    /* 
     * Encerra o programa sem erros
     */
    
    return 0;
    
}
