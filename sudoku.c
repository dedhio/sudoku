#include <stdio.h>
int verifica_sudoku( int jogo[9][9])
{
    int i, j, k, soma_linha, soma_coluna, soma_quadrante, temp;
    soma_linha = 0;
    for (i = 0; i < 9; i++)
    {
        temp = 0;
        for (j = 0; j < 9; j++)
        {
            if(jogo[i][j] < 1 || jogo[i][j] > 9){
                return 0;
            }
            soma_linha =  soma_linha + jogo[i][j];
            if(jogo[i][j] == temp)
            {
                return 0;
            }
            else
            {
                temp = jogo[i][j];
            }
        }
        if (soma_linha != 45)
        {
            return 0;
        }
        soma_linha = 0;

        temp = 0;
        if (i % 3 == 0)
        {
            soma_quadrante = 0;
            for(k = i; k < (i + 4); k++)
            {
                temp = 0;
                for(j = 0; j < 4; j++)
                {
                    soma_quadrante = soma_quadrante + jogo[k][j];
                    if(jogo[k][j] == temp)
                    {
                        return 0;
                    }
                    else
                    {
                        temp = jogo[k][j];
                    }
                }
            }
            if (soma_quadrante != 45)
            {
                return 0;
            }
        }
    }

    soma_coluna = 0;
    for (j = 0; j < 9; j++)
    {
        temp = 0;
        for (i = 0; i < 9; i++)
        {
            if(jogo[i][j] < 1 || jogo[i][j] > 9){
                return 0;
            }
            soma_coluna =  soma_coluna + jogo[i][j];
            if(jogo[i][j] == temp)
            {
                return 0;
            }
            else
            {
                temp = jogo[i][j];
            }
        }
        if (soma_coluna != 45)
        {
            return 0;
        }
        soma_coluna = 0;

        temp = 0;
        if (j % 3 == 0)
        {
            soma_quadrante = 0;
            for(k = j; k < (j + 4); k++)
            {
                temp = 0;
                for(i = 0; i < 4; i++)
                {
                    soma_quadrante = soma_quadrante + jogo[i][k];
                    if(jogo[i][k] == temp)
                    {
                        return 0;
                    }
                    else
                    {
                        temp = jogo[i][k];
                    }
                }
            }
            if (soma_quadrante != 45)
            {
                return 0;
            }
        }
    }
    return 1;
}
int main ()
{   
    int valida_jogo = 0;
    int jogo_correto [ 9 ][ 9 ] = { { 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 }, 
                                    { 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 },
                                    { 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 },
                                    { 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 },
                                    { 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 },
                                    { 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 },
                                    { 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 },
                                    { 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 },
                                    { 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 }};
                                    
    valida_jogo = verifica_sudoku (jogo_correto);
    if (valida_jogo == 1)
    {
        printf ("Esta correto.");
    }
    else if (valida_jogo == 0)
    {
        printf ("Esta errado."); 
    }
    else
    {
        printf ("Erro na verificacao");
    }
    
    return 0;
}