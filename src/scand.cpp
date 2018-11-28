/**
 * @file scand.cpp
 * @author Allan de Miranda (allandemiranda@gmail.com)
 * @brief Funções para class scand -> SCAN considerando o bit de sentido como DESCE
 * @version 0.1
 * @date 2018-11-28
 * 
 * @copyright Copyright (c) 2018
 * 
 */

#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>
#include "../include/scand.h"
#include "../include/disco.h"
#include "../include/render.h"

/**
 * @brief Construct a new scand::scand object
 * 
 * @param Disco_ Estatus inicial do disco
 */
scand::scand(disco Disco_){
    for(std::vector<int>::iterator i = Disco_.acessar_elemento_inicial(); i<Disco_.acessar_elemento_final(); ++i){
        lista_de_espera.push_back(*(i));        
    }
    posicao_atual = Disco_.posicao_cabecote_inicial();   
}

/**
 * @brief Função para resolver e imprimir resposta
 * 
 */
void scand::resolvendo(void){
    //! Criar uma ordem crescente e decrescente de escaneamento
    std::vector <int> crescente;
    std::vector <int> decrescente;
    lista_de_espera.push_back(posicao_atual);    
    for(int i : lista_de_espera){
        if(i <= posicao_atual){
            decrescente.push_back(i);
        } else {
            crescente.push_back(i);
        }
    }
    std::sort(crescente.begin(), crescente.end());
    std::sort(decrescente.begin(), decrescente.end(), std::greater<int>());
    //! Criando ordem de acesso
    for(int i : decrescente){
        ordem_acessada.push_back(i);
    }
    for(int i : crescente){
        ordem_acessada.push_back(i);
    }    
    //! Calcular jornada entre os pontos
    for(int i(1); i<ordem_acessada.size(); ++i){
        //! Adicione a jornada entre cilindros
        int temp = (ordem_acessada[i] - ordem_acessada[i-1]);
        if(temp < 0){
            jornada_total += temp * (-1);
        } else {
            jornada_total += temp;
        }
    } 
    //! Imrima a resposta como solicitado no trabalho
    render imprimir_("SCAN DESCE", ordem_acessada, jornada_total);
    imprimir_.print();
}