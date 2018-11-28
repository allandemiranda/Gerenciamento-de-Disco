/**
 * @file sstf.cpp
 * @author Allan de Miranda (allandemiranda@gmail.com)
 * @brief Funções da class sstf
 * @version 0.1
 * @date 2018-11-28
 * 
 * @copyright Copyright (c) 2018
 * 
 */

#include "../include/sstf.h"
#include "../include/disco.h"
#include "../include/render.h"

/**
 * @brief Construct a new sstf::sstf object
 * 
 * @param Disco_ Estatus inicial do disco
 */
sstf::sstf(disco Disco_){
    for(std::vector<int>::iterator i = Disco_.acessar_elemento_inicial(); i<Disco_.acessar_elemento_final(); ++i){
        lista_de_espera.push_back(*(i));        
    }
    posicao_atual = Disco_.posicao_cabecote_inicial();  
    quant_cilindros = Disco_.posicao_maxima_cilindro() - Disco_.possicao_minima_cilindro();  
}

/**
 * @brief Função para resolver e imprimir resposta
 * 
 */
void sstf::resolvendo(void){
    //! Adicionar posição inicial
    ordem_acessada.push_back(posicao_atual);
    //! Ir apra o mais próximo -> SSTF
    while(lista_de_espera.size() != 0){        
        //! Procurar menor jornada
        int posicao_menor;
        int jornada_menor = quant_cilindros + 1;
        for(int i(0); i<lista_de_espera.size(); ++i){
            int temp_um = (lista_de_espera[i] - posicao_atual);
            if(temp_um < 0){
                temp_um = temp_um * (-1);
            }
            if(temp_um < jornada_menor){
                jornada_menor = temp_um;
                posicao_menor = i;
            }
        } 
        //! Adicione a jornada entre cilindros
        int temp = (lista_de_espera[posicao_menor] - posicao_atual);
        if(temp < 0){
            jornada_total += temp * (-1);
        } else {
            jornada_total += temp;
        }
        //! Adicione o lido a ordem de acesso
        ordem_acessada.push_back(lista_de_espera[posicao_menor]);
        //! Atualize a posição atual
        posicao_atual = lista_de_espera[posicao_menor];
        //! Apague a solicitação
        lista_de_espera.erase(lista_de_espera.begin()+posicao_menor);  
    }    
    //! Imrima a resposta como solicitado no trabalho
    render imprimir_("SSTF", ordem_acessada, jornada_total);
    imprimir_.print();
}