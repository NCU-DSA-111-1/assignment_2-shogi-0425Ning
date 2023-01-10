
#define ROW 9
#define COL 9

struct shogi{
    char name;
    int row;
    int col;
    struct shogi* ptr_pre;
    struct shogi* ptr_next;
};
typedef struct shogi SHOGI_1, SHOGI_2;

static char chess_board[ROW][COL];//定義棋盤
