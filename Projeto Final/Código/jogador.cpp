#include "jogador.h"

// Construtor que inicializa o jogador com um nome
Jogador::Jogador(const std::string& nome_jogador) : nome(nome_jogador) {}

// Retorna o nome do jogador
std::string Jogador::get_nome() const {
    return nome;
}

// Define o nome do jogador
void Jogador::set_nome(const std::string& nome_jogador) {
    nome = nome_jogador;
}

// Retorna os pontos do jogador
int Jogador::get_pontos() const {
    return pontos;
}

// Aumenta a pontua��o do jogador em um ponto
void Jogador::aumenta_ponto() {
    pontos++;
}

