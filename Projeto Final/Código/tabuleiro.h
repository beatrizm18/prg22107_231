#ifndef TABULEIRO_H
#define TABULEIRO_H

#include <random>
#include <QMainWindow>
#include <QApplication>
#include <QtWidgets>
#include <QMessageBox>
#include <QVector>
#include <QTime>
#include <QRandomGenerator>

#include <iostream>
#include <array>
#include "celula.h"

const int DIMENSAO = 10;

class Tabuleiro
{
public:
    void descobrir_celula(int x, int y);
    bool marcar_celula(int x, int y);
    Celula &get_celula(int x, int y);
    void mostrarTabuleiro();

private:
    std::array<std::array<Celula, DIMENSAO>, DIMENSAO> celulas;
};

#endif
