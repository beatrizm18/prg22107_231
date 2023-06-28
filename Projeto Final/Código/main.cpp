#include <QMainWindow>
#include <QApplication>
#include <QtWidgets>
#include <QMessageBox>
#include <QVector>
#include <QTime>
#include <QRandomGenerator>

#include "jogador.h"
#include "campo_minado.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Jogador jogador1("Beatriz");
    Tabuleiro tabuleiro;

    CampoMinado campoMinado(jogador1, tabuleiro);

    QString player_name = QString::fromStdString(jogador1.get_nome());
    // Exibir uma mensagem de início do jogo
    QMessageBox::information(nullptr, "Campo Minado", QString("Olá %1, clique em Ok para iniciar o jogo!").arg(player_name));

        campoMinado.inicia_jogo();

    return app.exec();
}
