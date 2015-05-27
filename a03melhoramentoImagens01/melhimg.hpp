#include <opencv2/opencv.hpp>
using namespace cv;

#ifndef melhimg_hpp
    #define melhimg_hpp


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
int equalizacaoHistograma( Mat &imagem1 , Mat &imagemResultante );

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
int montaHistogramaImagem( Mat imagem , unsigned int *histograma );

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
int acumulaHistograma( unsigned int *histograma , unsigned int tamanho , unsigned int *histogramaAcumulado );







int limpaVetorUnsInt( unsigned int *vetor , unsigned int tamanho );

int maiorElmVetor( int *vetor , int tamanho );
#endif

