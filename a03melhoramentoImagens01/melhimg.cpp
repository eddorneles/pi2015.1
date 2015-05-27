#include "melhimg.hpp"

#include <stdio.h>

#define MAX_PIXEL_VALUE 255
#define MIN_PIXEL_VALUE 0

#define TRUE 1
#define FALSE 0

using namespace cv;

/***************************************************************************************************
(equalizacaoHistograma)
Realização a equalização por histograma na imagem passada.
FUNCIONA EM IMAGENS EM NÍVEIS DE CINZA
RECEBE:
    -> Mat & imagem1 , imagem a ser equalizada
    -> Mat & imagemResultante, imagem retornada por referência após as
        operações
RETORNA:
    -> TRUE, se as operações ocorreram corretamente
    -> FALSE, se não for possível realizar
****************************************************************************************************/
int equalizacaoHistograma( Mat &imagem1 , Mat &imagemResultante ){

    unsigned int histograma[ MAX_PIXEL_VALUE + 1];
    unsigned int histogramaAcumulado[ MAX_PIXEL_VALUE + 1];

    unsigned int i , j;


    /* Se a imagem passada for válida */
    if( imagem1.data ){
        int unsigned linhas = imagem1.rows,
                     colunas = imagem1.cols;

        printf( "DIMENSÕES DA IMAGEM:%d\t%d" , linhas , colunas );
        /* Retorna o histograma por referência */
        montaHistogramaImagem( imagem1 , histograma );

        double fator = (double) (MAX_PIXEL_VALUE)/(linhas * colunas);

        /* Retorna o histograma Acumulado por referência */
        acumulaHistograma( histograma , MAX_PIXEL_VALUE + 1  , histogramaAcumulado );

        imagemResultante.create( linhas , colunas , CV_8UC1 );

        for( i = 0 ; i < linhas ; i++ ){
            for( j = 0 ; j < colunas ; j++ ){
                imagemResultante.at<uchar>( i , j ) =
                    fator * histogramaAcumulado[ imagem1.at<uchar>( i , j ) ];
            }
        }
        return TRUE;
    }// END if
    return FALSE;
}//Fim equalizacaoHistograma

/***************************************************************************************************
(montaHistogramaImagem)
Cria um histograma baseado na frequência dos valores de pixel de uma imagem. Retorna o histograma
por referência.
RECEBE:
    ->unsigned int &histograma, vetor que representa um histograma;
    ->unsigned int histograma, endereço do vetor histograma;
RETORNA:
    ->TRUE, se ocorreu tudo corretamente;
    ->FALSE, se houve algum problema durante a execução
    ->unsigned int histograma, retornado por REFERÊNCIA ;
****************************************************************************************************/
int montaHistogramaImagem( Mat imagem , unsigned int *histograma ){

    int i , j;
    /* Validação da imagem passada */
    if( imagem.data ){

        limpaVetorUnsInt( histograma , MAX_PIXEL_VALUE + 1 );
        for( i = 0 ; i < imagem.rows ; i++ ){
            for( j = 0 ; j < imagem.cols ; j++ ){
                /* Incrementa a frequência do pixel no histograma */
                histograma[ imagem.at<uchar>( i , j ) ]++;
            }
        }
        return TRUE;

    }//END if( imagem && imagem.data )
    return FALSE;
}


/***************************************************************************************************
(acumulaHistograma)
Recebe um vetor que funcione como histograma, cada índice corresponde a um
elemento, o valor no elemento corresponde à quantidade de ocorrências do
elemento no caso, e por fim retorna por referência o histograma acumulado,
(histogramaAcumulado[i] = histograma[i] + histogramaAcumulado[i-1]).
RECEBE:
    ->unsigned int &histograma, vetor que representa um histograma;
    ->unsigned int tamanho, quantidade de elementos presente no histograma;
    ->unsigned int &histogramaAcumulado, endereço do vetor (histograma) acumulado a ser retornado
RETORNA:
    ->TRUE, se ocorreu tudo corretamente;
    ->FALSE, se houve algum problema durante a execução
****************************************************************************************************/
int acumulaHistograma( unsigned int *histograma , unsigned int tamanho , unsigned int *histogramaAcumulado ){

    unsigned int i;

    if( histograma != NULL && tamanho > 0 && histogramaAcumulado != NULL ){
        histogramaAcumulado[0] = histograma[0];
        for( i = 1 ; i < tamanho ; i++ ){
            histogramaAcumulado[i] = histograma[i] + histogramaAcumulado[i-1];
        }
        return TRUE;
    }
    return FALSE;
}


int limpaVetorDoub( double *vetor , unsigned int tamanho ){
    unsigned int i;

    if( vetor != NULL ){
        for( i = 0 ; i < tamanho ; i++){
            vetor[i] = 0;
        }
        return TRUE;
    }
    return FALSE;
}

int limpaVetorUnsInt( unsigned int *vetor , unsigned int tamanho ){
    unsigned int i;

    if( vetor != NULL ){
        for( i = 0 ; i < tamanho ; i++){
            vetor[i] = 0;
        }
        return TRUE;
    }
    return FALSE;
}


int mostraHistograma( ){
    int i;

    for( i = 0 ; i < MAX_PIXEL_VALUE ; i++ ){

    }
    return 1;
}


int maiorElmVetor( int *vetor , int tamanho ){
    int i ;
    int maior;

    if( vetor != NULL && tamanho > 0 ){
        maior = vetor[0];
        for( i = 1 ; i < tamanho ; i++ ){
            if( maior < vetor[i] ){
                maior = vetor[i];
            }
        }
        return maior;
    }
    return 0;
}


