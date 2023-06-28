#include "tabuleiro.h"

// Descobre uma célula no tabuleiro
void Tabuleiro::descobrir_celula(int x, int y)
{
//    // Verifica se as coordenadas estão dentro dos limites do tabuleiro
//    if (x >= 0 && x < DIMENSAO && y >= 0 && y < DIMENSAO)
//    {
//        if (!get_celula(x, y).is_minada() && celulas[x][y].get_qtd() == 0) { // função recursiva, usando backtracking
//            if (x-1 >= 0) {
//                board[5][5]->clicked(true);
//                board[5][5]->setFlat(true);
//                descobrir_celula(x-1, y);
//            }
//            if (y+1 <= 9) descobrir_celula(x, y+1);
//            if (x+1 <= 9) descobrir_celula(x+1, y);
//            if (y-1 >= 0) descobrir_celula(x, y-1);
//        }
//    }
}

// Marca uma célula no tabuleiro
bool Tabuleiro::marcar_celula(int x, int y)
{
    // Verifica se as coordenadas estão dentro dos limites do tabuleiro
    if (x >= 0 && x < DIMENSAO && y >= 0 && y < DIMENSAO)
    {
        // Verifica se a celula não está descoberta antes de marcar
        if (!celulas[x][y].is_descoberta())
        {
            celulas[x][y].marcar();
            return true; // Operação bem sucedida
        }
    }
    return false; // Operação falhou (coordenadas fora dos limites ou c�lula descoberta)
}

// Retorna uma referência à celula nas coordenadas dadas
Celula &Tabuleiro::get_celula(int x, int y)
{
    // Verifica se as coordenadas estão dentro dos limites do tabuleiro
    if (x >= 0 && x < DIMENSAO && y >= 0 && y < DIMENSAO)
    {
        return celulas[x][y];
    }
    else
    {
        throw std::out_of_range("Coordenadas fora dos limites do tabuleiro");
    }
}

void Tabuleiro::mostrarTabuleiro()
{
    for (int i = 0; i < DIMENSAO; ++i)
    {
        for (int j = 0; j < DIMENSAO; ++j)
        {
            Celula &celula = celulas[i][j];

            if (celula.is_marcada())
            {
                std::cout << "M ";
            }
            else if (!celula.is_descoberta())
            {
                std::cout << "# ";
            }
            else if (celula.is_minada())
            {
                std::cout << "* ";
            }
            else
            {
                // // Imprime um "." para as células que estão descobertas e não estão minadas
                // std::cout << ". ";
                // mostra a quantidade de minas proximas a celula
                std::cout << celula.get_qtd() << " ";
            }
        }
        std::cout << std::endl;
    }
}

