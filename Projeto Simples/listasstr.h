#include <string.h>
#define tam 8

typedef struct {
	char nome[30];
	int nr;
} elem;

typedef struct {
	elem m[tam];
	int fim;
} lista;

void linit(lista *l) {
	l->fim = 0;
}

void lins(lista *l,elem x) {
	if (l->fim < tam) {
		int i = l->fim;
		while (i > 0 && strcmp(x.nome,l->m[i-1].nome) < 0) {
			strcpy(l->m[i].nome,l->m[i-1].nome);
			l->m[i].nr = l->m[i-1].nr;
			i--;
		}
		strcpy(l->m[i].nome,x.nome);
		l->m[i].nr = x.nr;
		l->fim++;
	}
}

//char lrem(lista *l,elem x) {
//	int i=0;
//	while (i < l->fim && strcmp(x,l->m[i]) > 0)
//		i++;
//	if (i < l->fim && strcmp(x,l->m[i]) == 0) { // ou usar !strcmp ao invés de == 0;
//		while (i < l->fim-1) {
//			strcpy(l->m[i],l->m[i+1]);
//			i++;
//		}
//		l->fim--;
//		return 1;
//	}
//	else
//		return 0;
//}
