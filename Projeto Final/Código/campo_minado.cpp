#include "tabuleiro.h"
#include "campo_minado.h"

void CampoMinado::reset() {
    QLayoutItem* item;

    // Inicia um novo jogo
    this->inicia_jogo();
}
void CampoMinado::revela_mina(MineButton *button, int row, int col)
{
    if (tabuleiro.get_celula(row, col).is_minada()) {
        button->setStyleSheet("background-color: red;");
        QMessageBox::information(nullptr, "Campo Minado", "Game Over! Você encontrou uma mina!");
            this->reset();
    }
}

void CampoMinado::descobre_mina(int x, int y)
{
    if (!tabuleiro.get_celula(x, y).is_descoberta()) {
        tabuleiro.get_celula(x, y).descobrir();
        if (!tabuleiro.get_celula(x, y).is_minada() && tabuleiro.get_celula(x, y).get_qtd() == 0) {
            if (x - 1 >= 0) {
                board[x-1][y]->clicked(true);
                board[x-1][y]->setFlat(true);
                descobre_mina(x-1, y);
            }
            if (y + 1 <= 9) {
                board[x][y+1]->clicked(true);
                board[x][y+1]->setFlat(true);
                descobre_mina(x, y+1);
            }
            if (x + 1 <= 9) {
                board[x+1][y]->clicked(true);
                board[x+1][y]->setFlat(true);
                descobre_mina(x+1, y);
            }
            if (y - 1 >= 0) {
                board[x][y-1]->clicked(true);
                board[x][y-1]->setFlat(true);
                descobre_mina(x, y-1);
            }
        }
    }
}

void CampoMinado::inicia_jogo()
{
    QWidget *window;
    QGridLayout *boardLayout;

    window = new QWidget;
    window->setWindowTitle("Campo Minado 10x10");
    window->setMinimumSize(500, 500);

    // Cria um layout de grade para o tabuleiro
    boardLayout = new QGridLayout(window);


    // Define o tamanho do tabuleiro
    int numRows = DIMENSAO;
    int numCols = DIMENSAO;
    int numMines = 10; // Número de minas desejado

    // reseta todas as celulas do tabuleiro
    for (int row = 0; row < numRows; ++row) {
        for (int col = 0; col < numCols; ++col) {
            Celula &celula = tabuleiro.get_celula(row, col);
            celula.reset();
        }
    }

    // Cria uma matriz para representar o tabuleiro

    //    QVector<QVector<QPushButton*>> board(10, QVector<QPushButton*>(10));

    // Adiciona as minas aleatoriamente no tabuleiro
    QRandomGenerator generator = QRandomGenerator::securelySeeded();

    for (int i = 0; i < numMines; ++i) {
        int randomRow = generator.bounded(numRows);
        int randomCol = generator.bounded(numCols);

        while (tabuleiro.get_celula(randomRow, randomCol).is_minada()) {
            randomRow = generator.bounded(numRows);
            randomCol = generator.bounded(numCols);
        }
        tabuleiro.get_celula(randomRow, randomCol).minar();
    }
    contarCelulas();

    // Loop para criar as células do tabuleiro
    for (int row = 0; row < numRows; ++row) {
        for (int col = 0; col < numCols; ++col) {
            // Cria um QPushButton para representar a célula do tabuleiro
            MineButton *cell = new MineButton(window);
            cell->setFixedSize(50, 50);
            cell->setCheckable(true); // Permite clicar no botão
            cell->setAutoExclusive(false); // Garante que apenas um botão esteja selecionado por vez

            cell->setStyleSheet("background-color: lightgray;");

            // Adiciona a célula ao layout da grade
            boardLayout->addWidget(cell, row, col);

            // Armazena a célula no tabuleiro
            board[row][col] = cell;

            // Conecta o sinal de clique do botão à função de revelação das minas
            QObject::connect(cell, &MineButton::clicked, [cell, this, row, col]() {
                revela_mina(cell, row, col);
                cell->setFlat(true);
                cell->setEnabled(false); // para não clicar novamente no botão
                cell->setText(QString::number(tabuleiro.get_celula(row, col).get_qtd()));
                descobre_mina(row, col);
            });
        }
    }

    window->show();
}

bool CampoMinado::jogoTerminou()
{
    // Vamos considerar que o jogo termina se todas as c lulas que n o est o minadas foram descobertas
    // ou se o jogador descobriu uma mina.
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            Celula &celula = tabuleiro.get_celula(i, j);
            if (!celula.is_minada() && !celula.is_descoberta())
            {
                // Se encontramos uma c lula que n o est  minada e ainda n o foi descoberta, o jogo n o terminou
                return false;
            }
        }
    }
    // Se todas as c lulas que n o est o minadas foram descobertas, o jogo terminou
    return true;
}

void CampoMinado::contarCelulas()
{
    int counter = 0; // faz a contagem de quantas minas estão proximas das casas
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (!tabuleiro.get_celula(i, j).is_minada())
            {
                if (i != 0 && j != 9)
                {
                    if (tabuleiro.get_celula(i-1, j+1).is_minada()) counter++;
                }
                if (i != 9 && j != 0)
                {
                    if (tabuleiro.get_celula(i+1, j-1).is_minada()) counter++;
                }
                if (i != 0)
                {
                    if (tabuleiro.get_celula(i-1, j).is_minada()) counter++;
                }
                if (j != 0)
                {
                    if (tabuleiro.get_celula(i, j-1).is_minada()) counter++;
                }
                if (i != 9)
                {
                    if (tabuleiro.get_celula(i+1, j).is_minada()) counter++;
                }
                if (j != 9)
                {
                    if (tabuleiro.get_celula(i, j+1).is_minada()) counter++;
                }
                if (i != 9 && j != 9)
                {
                    if (tabuleiro.get_celula(i+1, j+1).is_minada()) counter++;
                }
                if (i != 0 && j != 0)
                {
                    if (tabuleiro.get_celula(i-1, j-1).is_minada()) counter++;
                }
                tabuleiro.get_celula(i, j).set_qtd(counter);
                counter = 0;
            }
        }
    }
}

void Celula::reset() {
    minada = false;
    descoberta = false;
    marcada = false;
    qtd_proxima = 0;
}
