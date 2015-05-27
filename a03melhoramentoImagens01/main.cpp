/*
EDUARDO DORNELES FERREIRA DE SOUZA 2011003238
PROCESSAMENTO DE IMAGENS
PROFESSOR ARISTÓFANES
ATIVIDADE 01 - QUANTIZAÇÃO DE IMAGENS
*/

/**
LEMBRETES
PARA COMPILAR: g++ a02operacoesImagens.cpp -o operacoesImagens `pkg-config --cflags --libs opencv`

Função para destruir uma janela:
                                    destroyWindow(const string& winname);
                                    destroyAllWindows();

Encontrar a referência da biblioteca do opencv:
	export PKG_CONFIG_PATH=/usr/local/lib/pkgconfig/
**/

#include <iostream>
#include <stdio.h>
#include <string.h>


#include <opencv2/opencv.hpp>
#include "melhimg.hpp"


using namespace std;
using namespace cv;

int main( int argc , char **argv ){

    char *opTecMelhoramento = argv[1];
    char *nomeImagem = argv[2];


    //strcpy( opTecMelhoramento , argv[1] );
    /**
        VALIDAÇÃO DA ENTRADA
    */

    if( argc != 3 ){
        cout << "Especifique a imagem e a tecnica de melhoramento: ./a03melhoramentoImagens01 <path_da_imagem> <tecnica_melhoramento>"
             <<endl;
        cout << "<tecnica_melhorament>: -equalizacao" << endl << "-stretch" << endl;
        return -1;
    }

    Mat imagem = imread( nomeImagem, CV_LOAD_IMAGE_GRAYSCALE );

    if( !imagem.data ){
        cout << "Especifique um arquivo de imagem valido." << endl;
        return -1;
    }

    if( !( !strcmp( opTecMelhoramento , "-equalizacao" ) || !strcmp( opTecMelhoramento , "-stretch"  ) )  ){
        cout << "Especifique uma tecnica de melhoramento correta: ./a03melhoramentoImagens01 <tecnica_melhoramento <path_da_imagem>" << endl;
        cout << "<tecnica_melhoramento>: -equalizacao ou -stretch" << endl;
        return -1;
    }
    /**
        FIM DA VALIDAÇÃO DA ENTRADA
    */

    Mat imagemResultante;

    /* Realiza o histograma de equalização para melhorar a imagem */
    if( !strcmp(opTecMelhoramento , "-equalizacao" )  ){
        equalizacaoHistograma( imagem , imagemResultante );
    }



    namedWindow( "a03melhoramentoImagens01: Equalizacao de Histograma" , WINDOW_AUTOSIZE );
    imshow( "a03melhoramentoImagens01: Equalizacao de Histograma" , imagemResultante );
    imwrite( "imagemEqualizada.jpg" , imagemResultante );
    waitKey(0);

    return 0;
}
