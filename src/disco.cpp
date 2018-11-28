/**
 * @file disco.cpp
 * @author Allan de Miranda (allandemiranda@gmail.com)
 * @brief Funções da class disco
 * @version 0.1
 * @date 2018-11-27
 * 
 * @copyright Copyright (c) 2018
 * 
 */

#include "../include/disco.h"

/**
 * @brief Construct a new disco::disco object
 * 
 * @param p_inicial Posição inicial do cabeçote
 * @param fila Fila de espera para ler cilindro
 */
disco::disco(int p_inicial, std::vector <int> fila){
    posicao_inicial = p_inicial;  //! Posição inicial do cabeçote
    for(int i : fila){
        lista_de_espera.push_back(i);   //! Criar fila de espera
    }
}

/**
 * @brief Função para verificar quantos elementos existe na lista de espera
 * 
 * @return int Quantidade de elementos na lista de espera
 */
int disco::tamanho_lista_de_espera(void){
    return lista_de_espera.size();
}

/**
 * @brief Função para apontar para o início do vetor de espera
 * 
 * @return std::vector<int>::iterator Ponteiro para o início
 */
std::vector<int>::iterator disco::acessar_elemento_inicial(void){
    return lista_de_espera.begin();
}

/**
 * @brief Verificar posição do cabeçote
 * 
 * @return int Retorna posição do cabeçote
 */
int disco::posicao_cabecote_inicial(void){
    return posicao_inicial;
}

/**
 * @brief Medir distancia entre dois pontos
 * 
 * @param p_inicial Ponteiro inicial
 * @param p_final Ponteiro final
 * @return int Distância entre os pontos
 */
int disco::distancia(std::vector<int>::iterator p_inicial, std::vector<int>::iterator p_final){
    int resposta = p_final - p_inicial;
    if(resposta<0){
        resposta = resposta * (-1);
    }
    return resposta;
}