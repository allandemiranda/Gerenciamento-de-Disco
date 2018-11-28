/**
 * @file main.cpp
 * @author Allan de Miranda (allandemiranda@gmail.com)
 * @brief Menu
 * @version 0.1
 * @date 2018-11-27
 * 
 * @copyright Copyright (c) 2018
 * 
 */

#include <iostream>
#include <vector>

#include "../include/disco.h"
#include "../include/render.h"
#include "../include/fcfs.h"

int main(int argc, char const *argv[])
{
    //! Capturando dados de entrada
    std::vector <int> dados_de_entrada;
    int num;
    int cont(0);
    int inicial_p;
    while(std::cin >> num){
        if(num == 0){
            inicial_p = num;
            ++cont;
            continue;
        }
        if(num == 1){
            continue;
        }
        if(num > 1){
            dados_de_entrada.push_back(num);
        }       
    }
    //! Declarando o disco
    disco Disc_(inicial_p, dados_de_entrada);
    fcfs metodo_1(Disc_);
    metodo_1.resolvendo();

    return 0;
}
