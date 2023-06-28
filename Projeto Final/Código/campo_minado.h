#ifndef CAMPO_MINADO_H
#define CAMPO_MINADO_H

#include <random>
#include <QMainWindow>
#include <QApplication>
#include <QtWidgets>
#include <QMessageBox>
#include <QVector>
#include <QTime>
#include <QRandomGenerator>

#include "jogador.h"
#include "tabuleiro.h"
#include "minebutton.h"

class CampoMinado {
public:
    CampoMinado(Jogador& jogador, Tabuleiro& tabuleiro)
        : jogador(jogador), tabuleiro(tabuleiro) {}

    void reset();

    // M todo para iniciar o jogo
    void iniciarJogo(int minas);

    // M todo para realizar uma jogada
    bool realizarJogada(int x, int y);

    // M todo para marcar uma c lula
    bool marcarCelula(int x, int y);

    // Verifica se o jogo terminou
    bool jogoTerminou();

    // Verifica se o jogador venceu
    bool jogadorVenceu();

    void contarCelulas();

    void revela_mina(MineButton *button, int row, int col);
    void reiniciar_jogo();
    void inicia_jogo();
    void descobre_mina(int x, int y);

private:
    Jogador& jogador;
    Tabuleiro& tabuleiro;
    std::array<std::array<MineButton*, 10>, 10> board;
    QWidget *window;
    QGridLayout *boardLayout;
};

#endif
