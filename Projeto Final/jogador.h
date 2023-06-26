#ifndef JOGADOR_H
#define JOGADOR_H

#include <iostream>

class Jogador
{
public:
    // Construtor que inicializa o jogador com um nome
    Jogador(const std::string &nome_jogador);

    // Retorna o nome do jogador
    std::string get_nome() const;

    // Define o nome do jogador
    void set_nome(const std::string &nome_jogador);

    // Retorna os pontos do jogador
    int get_pontos() const;

    // Aumenta a pontua��o do jogador em um ponto
    void aumenta_ponto();

private:
    std::string nome;
    int pontos = 0;
};

#endif
