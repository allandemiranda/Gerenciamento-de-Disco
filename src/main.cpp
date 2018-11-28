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
#include "../include/sstf.h"
#include "../include/scand.h"
#include "../include/scanc.h"

int main(int argc, char const *argv[])
{
    //! Capturando dados de entrada
    std::vector <int> dados_de_entrada;
    int num;
    int cont(0);
    int inicial_p;
    while(std::cin >> num){
        if(cont == 0){
            inicial_p = num;
            ++cont;
            continue;
        }
        if(cont == 1){
            ++cont;
            continue;
        }
        if(cont > 1){
            dados_de_entrada.push_back(num);
        }       
    }
    //! Declarando o disco
    disco Disc_(inicial_p, dados_de_entrada);
    //! Simulação do método FCFS
    fcfs metodo_1(Disc_);
    metodo_1.resolvendo();
    //! Simulação do método SSTF
    sstf metodo_2(Disc_);
    metodo_2.resolvendo();
    //! Simulação método SCAN considerando o bit de sentido como DESCE
    scand metodo_3(Disc_);
    metodo_3.resolvendo();
    //! Simulação método SCAN considerando o bit de sentido como SOBE
    scanc metodo_4(Disc_);
    metodo_4.resolvendo();

    return 0;
}
