# Projeto Final Programação Orientado à Objetos - Campo Minado
## 1 - Regras do jogo:
* Se você descobrir uma mina, o jogo acaba.
* Se descobrir um quadrado vazio, o jogo continua.
* Se aparecer um número, ele informará quantas minas estão escondidas nos quadrados que o cercam.
## 2 - Caso de Uso: Campo minado
* Atores: Jogador

* Descrição: No início, é mostrado ao jogador um tabuleiro que é dividido em vários quadrados sem qualquer marcação, depois de clicar em deles, os quadrados em volta desaparecem, em alguns aparecerão 0 e outros terão números diferentes de 0, com a ajuda dos números, será possível descobrir quais possuem minas e quais podem ser clicados para evitar pisar em uma mina. O jogo começa com o jogador colocando seu nome e a quantidadde de minas desejadas, ajustando a dificuldade de ganhar o jogo. Em seguida, o programa pede ao jogador que ele entre com uma coordenada, ou seja uma célula que depois de escolhida, a célula aparecerá descoberta. Se célula escolhida conter: O número 0, significa que não há perigo de ter minas ao redor da célula; Números diferentes de 0, como 1 e 2 por exemplo, esses números indicam a quantidade de minas em torno da célula; Como uma última opção se a coordenada descoberta conter uma mina o jogo acaba! Para ganhar o jogo é necessário descobrir todas as células que não contém minas.
