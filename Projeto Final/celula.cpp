#include "celula.h"

// Verifica se a c�lula est� minada
bool Celula::is_minada() {
    return minada;
}

// Verifica se a c�lula foi descoberta
bool Celula::is_descoberta() {
    return descoberta;
}

// Verifica se a c�lula foi marcada
bool Celula::is_marcada() {
    return marcada;
}

// Minar a c�lula
void Celula::minar() {
    minada = true;
}

// Descobrir a c�lula
void Celula::descobrir() {
    descoberta = true;
}

// Marcar a c�lula
void Celula::marcar() {
    marcada = !marcada; // Inverte o estado atual da marca��o
}

int Celula::get_qtd() {
    return qtd_proxima; // mostra quantas minas estão proximas da celula
}

void Celula::set_qtd(int qtd) {
    qtd_proxima = qtd;
}
