#ifndef CELULA_H
#define CELULA_H

#include <iostream>

class Celula
{
    public:
        bool is_minada();
        bool is_descoberta();
        bool is_marcada();
        void minar();
        void descobrir();
        void marcar();
        int get_qtd();
        void set_qtd(int qtd);
        void reset();
    private:
        bool minada = false;
        bool descoberta = false;
        bool marcada = false;
        int qtd_proxima = 0;
};

#endif
