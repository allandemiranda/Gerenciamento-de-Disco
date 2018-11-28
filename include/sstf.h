/**
 * @file sstf.h
 * @author Allan de Miranda (allandemiranda@gmail.com)
 * @brief Class para metodo SSTF
 * @version 0.1
 * @date 2018-11-28
 * 
 * @copyright Copyright (c) 2018
 * 
 */

#ifndef SSTF_H
#define SSTF_H

#include <vector>
#include "../include/disco.h"

class sstf
{
private:
    int jornada_total = 0;              //! Quantidade de cilindros percorrido
    std::vector <int> ordem_acessada;   //! Ordem de cilindros acessados
    std::vector <int> lista_de_espera;  //! Lista de espera para acessar os cilindros do disco
    int posicao_atual;                  //! Posição atual do cabeçote
    int quant_cilindros;                //! Quantidade de cilindros no disco
public:
    sstf(disco _disc);
    void resolvendo(void);
};

#endif