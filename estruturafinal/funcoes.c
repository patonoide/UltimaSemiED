/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include"cabecalho.h"
#include <stdio.h>
#include <stdlib.h>


Grafo *criaGrafo(int v){
    Grafo *g = (Grafo*) malloc(sizeof(Grafo));
    g->vertices = v;
    g->matriz = (int**) malloc(sizeof(int*)*v);
    int i, j;
    for(i=0;i<v;i++){
        g->matriz[i]=(int*) malloc(sizeof(int)*v);
    }
    for(i=0;i<v;i++){
        for(j=0;j<v;j++){
            g->matriz[i][j]=BRANCO;
        }
    }
    return g;
}

Res *criaResultado(int v){
    Res *r = (Res*) malloc(sizeof(Res));
    r->cor= (int*) malloc(sizeof(int)*v);
    r->predecessor= (int*) malloc(sizeof(int)*v);
    r->distancia= (int*) malloc(sizeof(int)*v);
    int i;
    
    for(i=0;i<v;i++){
        r->cor[i]=BRANCO;
        r->predecessor[i]=-1;
        r->distancia[i]=0;
    }
    
    return r;
}

Res *bfs(Grafo *g, int origem){
    int a; //adjacente
    Res *r = criaResultado(g->vertices);
    r->cor[origem] = CINZA;
    Fila *f = criaFila();
    insereFinal(f, origem);
    while(f->n != 0){
        int atual = retiraInicio(f);
        for(a=0;a<g->vertices;a++){
            if(g->matriz[atual][a]==1) {
               
                if(r->cor[a] == BRANCO){
                    r->cor[a] = CINZA;
                    insereFinal(f,a);
                    r->predecessor[a]=atual;
                    r->distancia[a]=1+r->distancia[atual];
                }
               
            }
        }
        r->cor[atual]=PRETO;
    }
    return r;
}

//funcoes Fila:

Fila * criaFila() {
    Fila * f = (Fila*) malloc(sizeof (Fila));
    f->n = 0;
    f->ini = 0;
    return f;
}

void insereFinal(Fila* f, int v) {
    int fim;
    if (f->n != 10) {
        fim = (f->ini + f->n) % 10;
        f->vet[fim] = v;
        f->n++;

    } else {
        printf("cheia");
        exit(1);
    }
}

int retiraInicio(Fila * f) {
    int v;
    if (f->n != 0) {
        v = f-> vet[f-> ini ];
        f->n--;
        f->ini = (f->ini + 1) % 10;
        return v;
    } else {
        printf("vazia");
        exit(1);
    }
}