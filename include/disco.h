/**
 * @file disco.h
 * @author Allan de Miranda (allandemiranda@gmail.com)
 * @brief Class disco contendo informações do disco
 * @version 0.1
 * @date 2018-11-27
 * 
 * @copyright Copyright (c) 2018
 * 
 */

#ifndef DISCO_H
#define DISCO_H

#include <vector>

class disco
{
private:
    std::vector <int> lista_de_espera;  //! Lista de espera para acessar os cilindros do disco
    int posicao_inicial;                //! Posição inicial do cabeçote
    int max_cilindro = 199;             //! Posições máxima do cilindro
    int min_cilindro = 0;               //! Posição mínima do cilindro
public:
    disco(int, std::vector<int>);    
    std::vector<int>::iterator acessar_elemento_inicial(void);
    std::vector<int>::iterator acessar_elemento_final(void);
    int posicao_cabecote_inicial(void);
    int posicao_maxima_cilindro(void);
    int possicao_minima_cilindro(void);
};

#endif