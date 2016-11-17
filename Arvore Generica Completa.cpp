#include <stdio.h>
#include <stdlib.h>

//Neste codigo utilizamos uma “lista de filhos”: um nó aponta apenas para seu primeiro (prim) filho, e cada um de seus filhos, exceto o último, aponta para o próximo (prox) irmão
struct arvoreGenerica {
 	char info; //Dado
 	struct arvoreGenerica *prim; //Primeiro filho
 	struct arvoreGenerica *prox; //Proximo irmao
};

typedef struct arvoreGenerica arvoreGenerica;
arvoreGenerica* cria (char c);
void insere (arvoreGenerica* a, arvoreGenerica* sa);
void imprime (arvoreGenerica* a);
int busca (arvoreGenerica* a, char c);
void libera (arvoreGenerica* a);
int altura (arvoreGenerica* r);


int main(){
	/* cria nós como folhas */
	arvoreGenerica* a = cria('a');
	arvoreGenerica* b = cria('b');
	arvoreGenerica* c = cria('c');
	arvoreGenerica* d = cria('d');
	arvoreGenerica* e = cria('e');
	arvoreGenerica* f = cria('f');
	arvoreGenerica* g = cria('g');
	arvoreGenerica* h = cria('h');
	arvoreGenerica* i = cria('i');
	arvoreGenerica* j = cria('j');
	arvoreGenerica* k = cria('k');
	arvoreGenerica* l = cria('l');
	arvoreGenerica* m = cria('m');
	/* monta a hierarquia */
	insere(d,m);
	insere(d,l);
	insere(d,k);
	insere(c,j);
	insere(c,i);
	insere(c,h);
	insere(b,g);
	insere(b,f);
	insere(b,e);
	insere(a,d);
	insere(a,c);
	insere(a,b);
	printf("Arvore:\n");
	imprime(a);//Imprime a arvore em pre-ordem a partir de a
	int alt = altura(a); //Altura a partir de a que eh a raiz
	printf("\nAltura: %d",alt);
	
		
	//system(pause);
	return 0;
}

arvoreGenerica* cria (char c) //Representa o Nó da árvore
{
 	arvoreGenerica *a =(arvoreGenerica *) malloc(sizeof(arvoreGenerica));
 	a->info = c;
 	a->prim = NULL;
 	a->prox = NULL;
 	return a;
}

void insere (arvoreGenerica* a, arvoreGenerica* sa) //Insere nova sub-árvore como filho de um dado nó, insere no início da lista
{
 	sa->prox = a->prim;
 	a->prim = sa;
}

void imprime (arvoreGenerica* a) //Imprime em pré--ordem, ou seja visita primeiro a raiz e depois os filhos
{
	arvoreGenerica* p;
 	printf("%c\n",a->info);
 	for (p=a->prim; p!=NULL; p=p->prox)
 	imprime(p);
}

int busca (arvoreGenerica* a, char c) //Busca a ocorrência de um determinado dado na árvore
{
 	arvoreGenerica* p;
 	if (a->info==c)
 		return 1;
 	else {
 		for (p=a->prim; p!=NULL; p=p->prox) {
 		if (busca(p,c))
 		return 1;
 	}
 }
 return 0;
}

void libera (arvoreGenerica* a)// Libera a memória alocada pela árvore
{
 	arvoreGenerica* p = a->prim;
 	while (p!=NULL) {
 		arvoreGenerica* t = p->prox;
 		libera(p);
 		p = t;
 	}
 free(a);
}

int altura (arvoreGenerica* a) {
	int hmax = -1; /* -1 para arv. sem filhos */
	arvoreGenerica* p;
	for (p=a->prim; p!=NULL; p=p->prox) {
		int h = altura(p);
		if (h > hmax)
			hmax = h;
	}
	return hmax + 1;
}
