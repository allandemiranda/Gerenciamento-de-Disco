/**
 * @file fcfs.cpp
 * @author Allan de Miranda (allandemiranda@gmail.com)
 * @brief Funções da class fcfs
 * @version 0.1
 * @date 2018-11-27
 * 
 * @copyright Copyright (c) 2018
 * 
 */

#include <vector>
#include <iterator>
#include "../include/fcfs.h"
#include "../include/disco.h"
#include "../include/render.h"

/**
 * @brief Construct a new fcfs::fcfs object
 * 
 * @param Disco_ Estatus inicial do disco
 */
fcfs::fcfs(disco Disco_){
    for(std::vector<int>::iterator i = Disco_.acessar_elemento_inicial(); i<Disco_.acessar_elemento_final(); ++i){
        lista_de_espera.push_back(*(i));        
    }
    posicao_atual = Disco_.posicao_cabecote_inicial();      
}

/**
 * @brief Função para resolver e imprimir resposta
 * 
 */
void fcfs::resolvendo(void){
    //! Adicionar posição inicial
    ordem_acessada.push_back(posicao_atual);
    //! O primeiro que solicita será o primeiro a ser lido -> FCFS
    while(lista_de_espera.size() != 0){
        //! Adicione a jornada entre cilindros
        int temp = (lista_de_espera[0] - posicao_atual);
        if(temp < 0){
            jornada_total += temp * (-1);
        } else {
            jornada_total += temp;
        }
        //! Adicione o lido a ordem de acesso
        ordem_acessada.push_back(lista_de_espera[0]);
        //! Atualize a posição atual
        posicao_atual = lista_de_espera[0];
        //! Apague a solicitação
        lista_de_espera.erase(lista_de_espera.begin());  
    }    
    //! Imrima a resposta como solicitado no trabalho
    render imprimir_("FCFS", ordem_acessada, jornada_total);
    imprimir_.print();
}