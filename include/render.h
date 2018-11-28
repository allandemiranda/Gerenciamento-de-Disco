/**
 * @file render.h
 * @author Allan de Miranda (allandemiranda@gmail.com)
 * @brief Class render para imprimir informações na tela
 * @version 0.1
 * @date 2018-11-27
 * 
 * @copyright Copyright (c) 2018
 * 
 */

#ifndef RENDER_H
#define RENDER_H

#include <string>
#include <vector>

class render
{
private:
    std::string nome_metodo;    //! Nome do método analisado
    std::vector <int> ordem;    //! Ordem de leitura dos cilindros
    int cilindros;              //! Quantidade de movimentos
public:
    render(std::string, std::vector <int>, int);
    void print(void);
};

#endif