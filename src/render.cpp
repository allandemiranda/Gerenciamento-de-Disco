/**
 * @file render.cpp
 * @author Allan de Miranda (allandemiranda@gmail.com)
 * @brief Funções class render
 * @version 0.1
 * @date 2018-11-27
 * 
 * @copyright Copyright (c) 2018
 * 
 */

#include <iostream>
#include <vector>
#include <string>
#include "../include/render.h"

/**
 * @brief Construct a new render::render object
 * 
 * @param nome 
 * @param lista 
 * @param resposta 
 */
render::render(std::string nome, std::vector <int> lista, int resposta){
    nome_metodo = nome;
    ordem = lista;
    cilindros = resposta;
}

/**
 * @brief Função para printar na tela as informações obtidas
 * 
 */
void render::print(void){
    std::cout << nome_metodo << std::endl;
    std::cout << "        Ordem: ";
    for(int i(0); i<ordem.size(); ++i){
        if(i == (ordem.size()-1)){
            std::cout << ordem[i];
        } else {
            std::cout << ordem[i] << ", ";
        }    
    }
    std::cout << std::endl;
    std::cout << "        Cilindros: " << cilindros << std::endl;
}