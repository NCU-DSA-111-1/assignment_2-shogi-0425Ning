#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
#include "shogi.h"

#define MAX 8
#define MIDDLE 4
#define L_ASCII_MIN 97 //the min ASCII CODE of lower case letters
#define L_ASCII_MAX 122 //the max ASCII CODE of lower case letters
#define U_ASCII_MIN 65 //the min ASCII CODE of upper case letters
#define U_ASCII_MAX 90 //the max ASCII CODE of upper case letters

static bool con = true;

void PrintfChess()//輸出棋盤
{
    for(int j = 0; j < COL; j++)
    {
        printf(" %d  ", j);
    }
    printf("\n");
    for (int i = 0; i < ROW; i++)
    {
        printf("| %c | %c | %c | %c | %c | %c | %c | %c | %c | %d\n", chess_board[i][0], chess_board[i][1], chess_board[i][2], chess_board[i][3], chess_board[i][4], chess_board[i][5], chess_board[i][6], chess_board[i][7], chess_board[i][8], i);
        if (i < ROW - 1)
            printf("|---|---|---|---|---|---|---|---|---|\n");
    }
}

clock_t t1_1, t2_1;
static double time_1 = 0;
int row_1, col_1;
int new_row_1, new_col_1;
int rule_row_1, rule_col_1;
bool correct_1 = false;
SHOGI_1 * PlayerOneNew(SHOGI_1 * ptr_1)
{
    printf("Player 1 - Please input the NEW position of the chess: ");
    scanf("%d %d", &new_row_1, &new_col_1);
    if(chess_board[new_row_1][new_col_1] != ' ')
    {
        printf("Player 1 - The position already has another chess.\n");
        PlayerOneNew(ptr_1);
    }
    else if(chess_board[row_1][col_1] == 'L')
    {
        rule_col_1 = new_col_1 - col_1;
        rule_row_1 = new_row_1 - row_1;
        if(rule_col_1 != 0 || rule_row_1 > 0)
        {
            printf("Player 1 - Wrong step.\n");
            PlayerOneNew(ptr_1);
        }
        else
        {
            correct_1 = true;
        }
    }
    else if(chess_board[row_1][col_1] == 'N')
    {
        rule_col_1 = new_col_1 - col_1;
        rule_row_1 = new_row_1 - row_1;
        if((rule_col_1 != 1 && rule_col_1 != -1) || rule_row_1 != -2)
        {
            printf("Player 1 - Wrong step.\n");
            PlayerOneNew(ptr_1);
        }
        else
        {
            correct_1 = true;
        }
    }
    else if(chess_board[row_1][col_1] == 'S')
    {
        rule_col_1 = new_col_1 - col_1;
        rule_row_1 = new_row_1 - row_1;
        if((rule_col_1 != 1 && rule_col_1 != -1) || (rule_row_1 != 1 && rule_row_1 != -1))
        {
            if(rule_col_1 != 0 || rule_row_1 != -1)
            {
                printf("Player 1 - Wrong step.\n");
                PlayerOneNew(ptr_1);
            }
            else
            {
                correct_1 = true;
            }
        }
        else
        {
            correct_1 = true;
        }
    }
    else if(chess_board[row_1][col_1] == 'G')
    {
        rule_col_1 = new_col_1 - col_1;
        rule_row_1 = new_row_1 - row_1;
        if((rule_col_1 != 1 && rule_col_1 != 0 && rule_col_1 != -1) || (rule_row_1 != 0 && rule_row_1 != -1))
        {
            if(rule_col_1 != 0 || rule_row_1 != 1)
            {
                printf("Player 1 - Wrong step.\n");
                PlayerOneNew(ptr_1);
            }
            else
            {
                correct_1 = true;
            }
        }
        else
        {
            correct_1 = true;
        }
    }
    else if(chess_board[row_1][col_1] == 'K')
    {
        rule_col_1 = new_col_1 - col_1;
        rule_row_1 = new_row_1 - row_1;
        if((rule_col_1 != 1 && rule_col_1 != 0 && rule_col_1 != -1) || (rule_row_1 != 1 && rule_row_1 != 0 && rule_row_1 != -1))
        {
            printf("Player 1 - Wrong step.\n");
            PlayerOneNew(ptr_1);
        }
        else
        {
            correct_1 = true;
        }
    }
    else if(chess_board[row_1][col_1] == 'B')
    {
        rule_col_1 = new_col_1 - col_1;
        rule_row_1 = new_row_1 - row_1;
        if(rule_col_1 != rule_row_1)
        {
            if(rule_col_1 != -rule_row_1)
            {
                printf("Player 1 - Wrong step.\n");
                PlayerOneNew(ptr_1);
            }
            else
            {
                correct_1 = true;
            }
        }
        else
        {
            correct_1 = true;
        }
    }
    else if(chess_board[row_1][col_1] == 'R')
    {
        rule_col_1 = new_col_1 - col_1;
        rule_row_1 = new_row_1 - row_1;
        if(rule_col_1 != 0)
        {
            if(rule_row_1 != 0)
            {
                printf("Player 1 - Wrong step.\n");
                PlayerOneNew(ptr_1);
            }
            else
            {
                correct_1 = true;
            }
        }
        else
        {
            correct_1 = true;
        }
    }
    else if(chess_board[row_1][col_1] == 'P')
    {
        rule_col_1 = new_col_1 - col_1;
        rule_row_1 = new_row_1 - row_1;
        if(rule_col_1 != 0 || rule_row_1 != -1)
        {
            printf("Player 1 - Wrong step.\n");
            PlayerOneNew(ptr_1);
        }
        else
        {
            correct_1 = true;
        }
    }
    if(correct_1)
    {
        chess_board[new_row_1][new_col_1] = chess_board[row_1][col_1];
        chess_board[row_1][col_1] = ' ';
        PrintfChess();
        correct_1 = false;
        ptr_1->ptr_next = (SHOGI_1*)malloc(sizeof(SHOGI_1));
        SHOGI_1 * p1 = ptr_1;
        ptr_1 = ptr_1->ptr_next;
        ptr_1->name = chess_board[new_row_1][new_col_1];
        ptr_1->row = new_row_1;
        ptr_1->col = new_col_1;
        ptr_1->ptr_pre = p1;
        ptr_1->ptr_next = NULL;
        t2_1 = clock();
        time_1 += (t2_1 - t1_1);
        printf("Player 1 - use %f seconds\n\n", time_1/(double)(CLOCKS_PER_SEC));
        //printf("ptr %c %d %d\n", ptr_1->name, ptr_1->row, ptr_1->col);
        //printf("pre %c %d %d\n", p1->name, p1->row, p1->col);
        return ptr_1;
    }
}

SHOGI_1 * PlayerOneMove(SHOGI_1 * ptr_1)
{
    t1_1 = clock();
    printf("Player 1 - Please input the position of the chess that you want to move: ");
    scanf("%d %d", &row_1, &col_1);
    if(chess_board[row_1][col_1] == ' ')
    {
        printf("Player 1 - Not the correct position.\n");
        PlayerOneMove(ptr_1);
    }
    else if((int)chess_board[row_1][col_1] >= L_ASCII_MIN && (int)chess_board[row_1][col_1] <= L_ASCII_MAX)
    {
        printf("Player 1 - Not your chess's position.\n");
        PlayerOneMove(ptr_1);
    }
    else
    {
        printf("Player 1 - the chess is: %c \n", chess_board[row_1][col_1]);
        ptr_1->ptr_next = (SHOGI_1*)malloc(sizeof(SHOGI_1));
        SHOGI_1 * p1 = ptr_1;
        ptr_1 = ptr_1->ptr_next;
        ptr_1->name = chess_board[row_1][col_1];
        ptr_1->row = row_1;
        ptr_1->col = col_1;
        ptr_1->ptr_pre = p1;
        ptr_1->ptr_next = NULL;
    }
    return PlayerOneNew(ptr_1);
}

clock_t t1_2, t2_2;
static double time_2 = 0;
int row_2, col_2;
int new_row_2, new_col_2;
int rule_row_2, rule_col_2;
bool correct_2 = false;
SHOGI_2 * PlayerTwoNew(SHOGI_2 * ptr_2)
{
    printf("Player 2 - Please input the NEW position of the chess: ");
    scanf("%d %d", &new_row_2, &new_col_2);
    if(chess_board[new_row_2][new_col_2] != ' ')
    {
        printf("Player 2 - The position already has another chess.\n");
        PlayerTwoNew(ptr_2);
    }
    else if(chess_board[row_2][col_2] == 'l')
    {
        rule_col_2 = new_col_2 - col_2;
        rule_row_2 = new_row_2 - row_2;
        if(rule_col_2 != 0 || rule_row_2 < 0)
        {
            printf("Player 2 - Wrong step.\n");
            PlayerTwoNew(ptr_2);
        }
        else
        {
            correct_2 = true;
        }
    }
    else if(chess_board[row_2][col_2] == 'n')
    {
        rule_col_2 = new_col_2 - col_2;
        rule_row_2 = new_row_2 - row_2;
        if((rule_col_2 != 1 && rule_col_2 != -1) || rule_row_2 != 2)
        {
            printf("Player 2 - Wrong step.\n");
            PlayerTwoNew(ptr_2);
        }
        else
        {
            correct_2 = true;
        }
    }
    else if(chess_board[row_2][col_2] == 's')
    {
        rule_col_2 = new_col_2 - col_2;
        rule_row_2 = new_row_2 - row_2;
        if((rule_col_2 != 1 && rule_col_2 != -1) || (rule_row_2 != 1 && rule_row_2 != -1))
        {
            if(rule_col_2 != 0 || rule_row_2 != 1)
            {
                printf("Player 2 - Wrong step.\n");
                PlayerTwoNew(ptr_2);
            }
            else
            {
                correct_2 = true;
            }
        }
        else
        {
            correct_2 = true;
        }
    }
    else if(chess_board[row_2][col_2] == 'g')
    {
        rule_col_2 = new_col_2 - col_2;
        rule_row_2 = new_row_2 - row_2;
        if((rule_col_2 != 1 && rule_col_2 != 0 && rule_col_2 != -1) || (rule_row_2 != 0 && rule_row_2 != 1))
        {
            if(rule_col_2 != 0 || rule_row_2 != -1)
            {
                printf("Player 2 - Wrong step.\n");
                PlayerTwoNew(ptr_2);
            }
            else
            {
                correct_2 = true;
            }
        }
        else
        {
            correct_2 = true;
        }
    }
    else if(chess_board[row_2][col_2] == 'k')
    {
        rule_col_2 = new_col_2 - col_2;
        rule_row_2 = new_row_2 - row_2;
        if((rule_col_2 != 1 && rule_col_2 != 0 && rule_col_2 != -1) || (rule_row_2 != 1 && rule_row_2 != 0 && rule_row_2 != -1))
        {
            printf("Player 2 - Wrong step.\n");
            PlayerTwoNew(ptr_2);
        }
        else
        {
            correct_2 = true;
        }
    }
    else if(chess_board[row_2][col_2] == 'b')
    {
        rule_col_2 = new_col_2 - col_2;
        rule_row_2 = new_row_2 - row_2;
        if(rule_col_2 != rule_row_2)
        {
            if(rule_col_2 != -rule_row_2)
            {
                printf("Player 2 - Wrong step.\n");
                PlayerTwoNew(ptr_2);
            }
            else
            {
                correct_2 = true;
            }
        }
        else
        {
            correct_2 = true;
        }
    }
    else if(chess_board[row_2][col_2] == 'r')
    {
        rule_col_2 = new_col_2 - col_2;
        rule_row_2 = new_row_2 - row_2;
        if(rule_col_2 != 0)
        {
            if(rule_row_2 != 0)
            {
                printf("Player 2 - Wrong step.\n");
                PlayerTwoNew(ptr_2);
            }
            else
            {
                correct_2 = true;
            }
        }
        else
        {
            correct_2 = true;
        }
    }
    else if(chess_board[row_2][col_2] == 'p')
    {
        rule_col_2 = new_col_2 - col_2;
        rule_row_2 = new_row_2 - row_2;
        if(rule_col_2 != 0 || rule_row_2 != 1)
        {
            printf("Player 2 - Wrong step.\n");
            PlayerTwoNew(ptr_2);
        }
        else
        {
            correct_2 = true;
        }
    }
    if(correct_2)
    {
        chess_board[new_row_2][new_col_2] = chess_board[row_2][col_2];
        chess_board[row_2][col_2] = ' ';
        PrintfChess();
        correct_2 = false;
        ptr_2->ptr_next = (SHOGI_2*)malloc(sizeof(SHOGI_2));
        SHOGI_2 * p2 = ptr_2;
        ptr_2 = ptr_2->ptr_next;
        ptr_2->name = chess_board[new_row_2][new_col_2];
        ptr_2->row = new_row_2;
        ptr_2->col = new_col_2;
        ptr_2->ptr_pre = p2;
        ptr_2->ptr_next = NULL;
        t2_2 = clock();
        time_2 += (t2_2 - t1_2);
        printf("Player 2 - use %f seconds\n\n", time_2/(double)(CLOCKS_PER_SEC));
        //printf("ptr %c %d %d\n", ptr_2->name, ptr_2->row, ptr_2->col);
        //printf("pre %c %d %d\n", p2->name, p2->row, p2->col);
        printf("Do you want to continue the game? [0(NO)/1(YES)] ");
        scanf("%d", &con);
        return ptr_2;
    }
}

SHOGI_2 * PlayerTwoMove(SHOGI_2 *ptr_2)
{
    t1_2 = clock();
    printf("Player 2 - Please input the position of the chess that you want to move: ");
    scanf("%d %d", &row_2, &col_2);
    if(chess_board[row_2][col_2] == ' ')
    {
        printf("Player 2 - Not the correct position.\n");
        PlayerTwoMove(ptr_2);
    }
    else if((int)chess_board[row_2][col_2] >= U_ASCII_MIN && (int)chess_board[row_2][col_2] <= U_ASCII_MAX)
    {
        printf("Player 2 - Not your chess's position.\n");
        PlayerTwoMove(ptr_2);
    }
    else
    {
        printf("Player 2 - the chess is: %c \n", chess_board[row_2][col_2]);
        ptr_2->ptr_next = (SHOGI_2*)malloc(sizeof(SHOGI_2));
        SHOGI_2 * p2 = ptr_2;
        ptr_2 = ptr_2->ptr_next;
        ptr_2->name = chess_board[row_2][col_2];
        ptr_2->row = row_2;
        ptr_2->col = col_2;
        ptr_2->ptr_pre = p2;
        ptr_2->ptr_next = NULL;
    }
    return PlayerTwoNew(ptr_2);
}

void InitGame()
{
    for (int i = 0; i <= MIDDLE; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if((i == 0 && j == 0)||(i == 0 && j == 8))
            {
                chess_board[i][j] = 'l'; //Lance 香車
                chess_board[MAX-i][j] = 'L';
            }
            else if((i == 0 && j == 1)||(i == 0 && j == 7))
            {
                chess_board[i][j] = 'n'; //Knight 桂馬
                chess_board[MAX-i][j] = 'N';
            }
            else if((i == 0 && j == 2)||(i == 0 && j == 6))
            {
                chess_board[i][j] = 's'; //Sliver General 銀將
                chess_board[MAX-i][j] = 'S';
            }
            else if((i == 0 && j == 3)||(i == 0 && j == 5))
            {
                chess_board[i][j] = 'g'; //Gold General 金將
                chess_board[MAX-i][j] = 'G';
            }
            else if((i == 0 && j == 4))
            {
                chess_board[i][j] = 'k'; //King 玉將 王將
                chess_board[MAX-i][j] = 'K';
            }
            else if((i == 1 && j == 1))
            {
                chess_board[i][j] = 'r'; //Rook 飛車
                chess_board[MAX-i][MAX-j] = 'R';
            }
            else if((i == 1 && j == 7))
            {
                chess_board[i][j] = 'b'; //Bishop 角行
                chess_board[MAX-i][MAX-j] = 'B';
            }
            else if(i == 2)
            {
                chess_board[i][j] = 'p'; //Pawn 步兵
                chess_board[MAX-i][j] = 'P';
            }
            else
            {
                chess_board[i][j] = ' ';
                chess_board[MAX-i][j] = ' ';
            }
        }
    }
}

void Show(SHOGI_1 * show_1, SHOGI_2 * show_2)
{

    InitGame();
    show_1 = show_1->ptr_next;
    SHOGI_1 * show_1_front = show_1;
    show_1 = show_1->ptr_next;
    show_2 = show_2->ptr_next;
    SHOGI_2 * show_2_front = show_2;
    show_2 = show_2->ptr_next;
    printf("\nstart to show the chess!\n");
    while(true)
    {
        chess_board[show_1->row][show_1->col] = show_1->name;
        chess_board[show_1_front->row][show_1_front->col] = ' ';
        PrintfChess();
        printf("\n");
        if(show_1->ptr_next != NULL)
        {
            show_1_front = show_1_front->ptr_next->ptr_next;
            show_1 = show_1->ptr_next->ptr_next;
        }
        chess_board[show_2->row][show_2->col] = show_2->name;
        chess_board[show_2_front->row][show_2_front->col] = ' ';
        PrintfChess();
        printf("\n");
        if(show_2->ptr_next != NULL)
        {
            show_2_front = show_2_front->ptr_next->ptr_next;
            show_2 = show_2->ptr_next->ptr_next;
        }
        else
        {
            break;
        }
    }
}

void StartGame()
{
    char winner;
    //1 初始化棋盤
    InitGame();
    SHOGI_1 * ptr_1 = (SHOGI_1*)malloc(sizeof(SHOGI_1));
    ptr_1->ptr_pre = NULL;
    ptr_1->ptr_next = NULL;
    SHOGI_1 * show_1 = ptr_1;
    SHOGI_2 * ptr_2 = (SHOGI_2*)malloc(sizeof(SHOGI_2));
    ptr_2->ptr_pre = NULL;
    ptr_2->ptr_next = NULL;
    SHOGI_2 * show_2 = ptr_2;
    //2 進入遊戲

    //3 輸出棋盤
    PrintfChess();
    //4玩家下棋
    while(con == true)
    {
        ptr_1 = PlayerOneMove(ptr_1);
        ptr_2 = PlayerTwoMove(ptr_2);
    }
    //5重播下棋過程
    Show(show_1, show_2);
}

int main(int argc, char* argv[])
{
    StartGame();
    
    return 0;
}