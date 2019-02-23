/*******************************************************************************
 * 
 *   Created: fri feb 21 00:58:03 -03 2019
 *   Updated: 
 * 
 *------------------------------------------------------------------------------
 *
 *   [no name] - Made to solve pt.stackoverflow.com/questions/364375/
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

struct vet{
	
	int tam;
	int key[10];
	char content[10][60];
	
};

typedef struct vet vetor;

void insert(vetor *s, int ind, char cnt[]){
	
	int i;
	
	s->key[s->tam] = ind;
	
	for(i = 0; i < 60; i++){
		
		s->content[s->tam][i] = cnt[i];
		
		if (cnt[i] == '\0') break;
		
	}
	
	s->tam++;
	
}

int search(vetor *s, int ind){
	
	int i;
	
	for(i = 0; i < s->tam; i++) {
		
		if (s->key[i] == ind)
			return 1;
		
	}
	
	return 0;
	
}

int main(){
	
	vetor s1;
	s1.tam = 0;
	
	insert(&s1, 11, "acre");
	
	if (search(&s1, 11)) printf("Found\n");
	else 				 printf("Not found\n");
	
	return 0;
	
}
