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
 * @brief Função para apontar para o início do vetor de espera
 * 
 * @return std::vector<int>::iterator Ponteiro para o início
 */
std::vector<int>::iterator disco::acessar_elemento_inicial(void){
    return lista_de_espera.begin();
}

/**
 * @brief Função para apontar para o final do vetor de espera
 * 
 * @return std::vector<int>::iterator Ponteiro para o final
 */
std::vector<int>::iterator disco::acessar_elemento_final(void){
    return lista_de_espera.end();
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
 * @brief Função para obter posiçaõ máxima do cilindro
 * 
 * @return int Posição
 */
int disco::posicao_maxima_cilindro(void){
    return max_cilindro;
}

/**
 * @brief Função para retornar posição mínima do cilindro
 * 
 * @return int POsição
 */
int disco::possicao_minima_cilindro(void){
    return  min_cilindro;
}