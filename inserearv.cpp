#include <iostream>
#include <stdlib.h>
using namespace std;
/* este é meu primeiro codigo de arvore binaria :)*/
struct Arv {
	char Info; //conteudo do nó da arvore, poderia ser num, float... etc
	int Chave;
	Arv* Esq; // ponteiro pra esquerda sae
	Arv* Dir; // ponteiro pra direita sad
};
/*
vamos criar uma arvore e imprimir ela :)
0. função que cria arvore vazia
	0.1 retorna tipo arv, retorna void.
	0.2 retorna null.
1. criar uma função que crie um nó// insere um nó
	1.1. passar valores a ser inseridos por ref(na função com *, e no main com &), e ponteiros
	da direita e a esquerda da arvore.
	1.2. alocar memoria em um ponteiro P de tamanho arv
	1.3. inserir valores em p.	
2. função que vé se tá vazia

int Arvore_Vazia(Arv* A){
	int Ret;
	if(A != NULL){
		Ret = 1;
	}else{
		if(A == NULL){
			Ret = 0;
		}
	}
	return Ret;
}
*/
Arv* Cria_Arv_Vazia(void){
	return NULL;
}

Arv* Cria_Arv(char *Caracter,int *Num, Arv* Sae, Arv* Sad){
	Arv* P = (Arv*)malloc(sizeof(Arv));
	P->Chave = *Num;
	P->Info = *Caracter;
	P->Esq = Sae;
	P->Dir = Sad;
	return P;
}

int Arv_Vazia(Arv* P){
	int ret;
	if(P != NULL){
		ret = 1;
	}else{
		ret = 0;
	}
	return ret;
}
/*como imprimir está bomba.

*/

int main(){
	setlocale(LC_ALL, "portuguese");
	int bn = 3;
	char bc = 'b';
	//criando segundo elemento
	int cn = 2;
	char cc = 'c';
	
	Arv* a1 = Cria_Arv(&bc, &bn, Cria_Arv_Vazia(),Cria_Arv_Vazia());//primeiro nó :)
	Arv* a2 = Cria_Arv(&cc, &cn, Cria_Arv_Vazia(), Cria_Arv_Vazia()); // segundo nó :)
	/*
	  b  c
	/ \ / \
	n n n n
	*/
	// juntar ambos em a
	int an = 1;
	char ac = 'a';
	Arv* a3 = Cria_Arv(&ac, &an, a1, a2);
	
	/*
	    a
	  /  \
   	 b    c
	/ \ / \
	n n n n
	*/
	
	// outra forma de fazer essa palhaçada
	char a = 'a', b = 'b', c = 'c';
	Arv* Ar = Cria_Arv(&a, &an, 
		Cria_Arv(&b, &bn, Cria_Arv_Vazia(), Cria_Arv_Vazia()),
		Cria_Arv(&c, &cn, Cria_Arv_Vazia(), Cria_Arv_Vazia())
	);
	
	if(Arv_Vazia(Ar) == 1){
		cout<<"Deu certo, por incrivel que pareça deu certo."<<endl;
	}else{
		cout<<"Erro planejado :)"<< endl;
	}
	return 0;	
}
