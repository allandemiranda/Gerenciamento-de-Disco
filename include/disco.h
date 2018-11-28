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
#include <iterator>

class disco
{
private:
    std::vector <int> lista_de_espera;  //! Lista de espera para acessar os cilindros do disco
    int posicao_inicial;                //! Posição inicial do cabeçote
    int max_cilindro = 199;             //! Posições máxima do cilindro
    int min_cilindro = 0;               //! Posição mínima do cilindro
public:
    disco(int, std::vector<int>);
    int tamanho_lista_de_espera(void);
    std::vector<int>::iterator acessar_elemento_inicial(void);
    int posicao_cabecote_inicial(void);
    int distancia(std::vector<int>::iterator, std::vector<int>::iterator);
};

#endif