#include <iostream>
#include <stdlib.h>
using namespace std;
// criando modelo de arvore
struct Arv{
	char info;
	Arv* Esq;
	Arv* Dir;
};
//arvore vazia
Arv* Cria_Vazia(void){
	return NULL;
}

//cria arvore de vdd
Arv* Cria_Arv(char *C, Arv* Sae, Arv* Sad){
	Arv* P = (Arv*)malloc(sizeof(Arv));
	P->info = *C;
	P->Esq = Sae;
	P->Dir = Sad;
	return P;
}
// impressões da arvore
/*
Algoritimo
	há tres formas de percorrer uma Arvore
	1. Pré- Ordem
		raiz // processa
		sae
		sad
	2. In-Ordem
		sae
		raiz //processa
		sad
	3. Pós Ordem
		sae
		sad 
		raiz// processa
	note que os tres casos ultilizam do backtracking para realizar operações :) omagaaa
*/
// pre-ordem
void Imprime_Pre_Ordem(Arv* arv){
	if(arv != NULL){
		cout<<arv->info<< " ";
		Imprime_Pre_Ordem(arv->Esq);
		Imprime_Pre_Ordem(arv->Dir);
	}
}
//In-Ordem
void Imprime_In_Ordem(Arv* arv){
	if(arv!= NULL){
		Imprime_Pre_Ordem(arv->Esq);
		cout<<arv->info<< " ";
		Imprime_Pre_Ordem(arv->Dir);
	}
}
//pós-ordem
void Imprime_Pos_Ordem(Arv* arv){
	if(arv != NULL){
		Imprime_Pre_Ordem(arv->Esq);
		Imprime_Pre_Ordem(arv->Dir);
		cout<<arv->info<< " ";
	}
	
}

int main(){
	setlocale(LC_ALL, "portuguese");
	char Arv1 = 'a', Arv2 = 'b', Arv3 = 'c', Arv4 = 'd', Arv5 = 'e', Arv6= 'f';
	//criando Arvore :)
	Arv* Ar = Cria_Arv(&Arv1, Cria_Arv(&Arv2, Cria_Arv(&Arv4, NULL, NULL), NULL), Cria_Arv(&Arv3, Cria_Arv(&Arv5, NULL, NULL), Cria_Arv(&Arv6, NULL, NULL)));// arvore propriamente criada.
	//cout << Ar->Dir->Esq->info; // teste de cout
	cout<<"Pré-Ordem"<< endl;
	Imprime_Pre_Ordem(Ar);
	
	cout<<endl;
	
	cout<<"In-Ordem"<<endl;
	Imprime_In_Ordem(Ar);
	
	cout<<endl;
	
	cout<<"Pós-Ordem: "<< endl;
	Imprime_Pos_Ordem(Ar);
	return 0;
}
