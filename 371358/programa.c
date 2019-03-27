/*******************************************************************************
 * 
 *   Created: mon mar 26 22:35:15 -03 2019
 *   Updated: 
 * 
 *------------------------------------------------------------------------------
 *
 *   programa - Made to solve pt.stackoverflow.com/questions/371358/
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


typedef struct cadastro {
    
    char nome[30];
    char matricula[30];
    char Disciplinas[30];
    char notas[30];
    
    struct cadastro *proxno;
    
} alunos;


int inserir_aluno_inicio(alunos **lista);
int menu(void);

void opcoes(alunos **lista, int opc);
void imprimir(alunos **lista);

alunos *remover_aluno(alunos **lista);
alunos *liberar();
alunos *inicializar();


int main() {
    
    int opcao;
    alunos *lista = (alunos *)malloc(sizeof(alunos));
    
    lista = inicializar();
    
    do {
        opcao = menu();
        opcoes(&lista, opcao);
    } while (opcao < 4);
    
    return 0;
    
}


alunos *inicializar() { return NULL; }

int menu() {
    
    int ale;
    
    puts("\n  M E N U   E S C O L A R   V I N G A D O R E S \n");
    puts(" ===============================================\n");
    puts(" =  [ 0 ]  INSERIR ALUNO                       =\n");
    puts(" =  [ 1 ]  REMOVER ALUNO                       =\n");
    puts(" =  [ 2 ]  IMPRIMIR INFORMACOES DO ALUNO       =\n");
    puts(" =  [ 3 ]  LIMPAR LISTA DE ALUNOS              =\n");
    puts(" =  [ 4 ]  SAIR DA LISTA                       =\n");
    puts(" ===============================================\n");
    printf(" COMANDO > ");
    
    scanf("%d", &ale);
    
    return ale;
    
}  

int inserir_aluno_inicio(alunos **lista) {  
    
    alunos *novo = (alunos *) malloc( sizeof( alunos ) );
    
    
    if (novo == NULL)
    {
        puts(" Sem memória!");
        
        return 1;
    }
    
    
    printf("\n Digite o nome do aluno ou da aluna: ");
    scanf(" %s", novo->nome);
    
    printf(" Digite a matricula do aluno ou aluna [5 numeros ou letras]: ");
    scanf(" %s", novo->matricula);
    
    printf(" Digite a disciplina do aluno ou aluna: ");
    scanf(" %s", novo->Disciplinas);
    
    printf(" Digite a nota da aluna ou do aluno: ");
    scanf(" %s", novo->notas);
    
    puts("");
    
    
    novo->proxno = *lista;
    *lista = novo;
    
    
    return 0;
    
}  

void opcoes(alunos **lista, int opc) {
    
    switch (opc) {
        
        case 0:
            inserir_aluno_inicio(lista);
            break;
            
        case 1:
            break;
            
        case 2:
            imprimir(lista);
            break;
            
        case 3:
            break;
            
        case 4:
            puts("\n Ate a proxima!\n");
            break;  
            
        default:
            puts(" Nao existe essa opcao tente novamente!");
            
    }
    
}  

void imprimir(alunos **lista) {
    
    alunos *aux = *lista;
    
    while (aux != NULL){
        
        printf("\n\tO nome da aluna(o): %s\n", aux->nome);
        printf("\tA matricula do aluno(a) e: %s\n", aux->matricula);
        printf("\tA disciplina da aluna(o) e: %s\n",aux->Disciplinas);
        printf("\tA nota do aluno (a): %s\n", aux->notas);
        
        aux = aux->proxno;
        
    }
    
}  
