/**
 * @file fcfs.h
 * @author Allan de Miranda (allandemiranda@gmail.com)
 * @brief Class para o método FCFS
 * @version 0.1
 * @date 2018-11-27
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef FCFS_H
#define FCFS_H

#include <vector>
#include "../include/disco.h"

class fcfs
{
private:
    int jornada_total = 0;                      //! Quantidade de cilindros percorrido
    std::vector <int> ordem_acessada;           //! Ordem de cilindros acessados
    std::vector <int> lista_de_espera;          //! Lista de espera para acessar os cilindros do disco
    int posicao_atual;                          //! Posição atual do cabeçote
public:
    fcfs(disco _disc);   
    void resolvendo(void);
};

#endif