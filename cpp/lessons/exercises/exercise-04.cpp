#include <iostream>
#include <vector>

#define ROWS 3
#define COLUMNS 3

using namespace std;

// Estrutura jogador
struct Player {

    Player(string name, char piece, bool playing = false, int points = 0) {
        this->name = name;
        this->piece = piece;
        this->points = points;
        this->playing = playing;
    }   

    int points;
    char piece;
    string name;
    bool playing;
};


// Imprime o header do jogo
void print_header(struct Player *ptr_player1, struct Player *ptr_player2) {
    system("cls");
    system("clear");
    cout << flush;

    cout << "==============================================" << endl;
    cout << "================ JOGO DO GALO ================" << endl;
    cout << "==============================================" << endl;
    cout << "Nome: " << ptr_player1->name << " Pontos: " << ptr_player1->points << " Peca: "<< ptr_player1->piece << endl;
    cout << "Nome: " << ptr_player2->name << " Pontos: " << ptr_player2->points << " Peca: "<< ptr_player2->piece << endl;
    cout << endl;
}


// Imprime o tabuleiro do jogo
void print_board(char game_board[ROWS][COLUMNS]) {
    cout << "Tabuleiro Atual:" << endl;
    cout << "     ";
    for (int i = 0; i < ROWS; i++) {
         cout << " " << i << " ";
    }

    cout << endl;

    cout << "     ";
    for (int i = 0; i < ROWS; i++) {
         cout << "---";
    }

    cout << endl;

    for (int i = 0; i < ROWS; i++) {
        cout << " " << i << " | ";

        for (int j = 0; j < COLUMNS; j++) {
            cout << " " << game_board[i][j] << " ";
        }

        cout << endl;
    }
 
    cout << endl;
}


// Validad se a jogada e valida
bool validate_play(int row, int column, char game_board[ROWS][COLUMNS]) {
    if (row < 0 || row > ROWS-1) {
        cout << "Ops, o valor \"" <<  row << "\" inserido para a linha nao e valido" << endl;
        return false;
    }

    if (column < 0 || column > COLUMNS-1) {
        cout << "Ops, o valor \"" <<  column << "\" inserido para a coluna nao e valido" << endl;
        return false;
    }  

    if (game_board[row][column] != '-') {
        cout << "Ops, esse campo ja esta preenchido" << endl;
        return false;
    }
    
    return true;  
}


// Jogada do utilizador
void play(struct Player *ptr_player, char game_board[ROWS][COLUMNS]) {
    int row, column;

    do {
        cout << ptr_player->name << " \""<< ptr_player->piece <<"\" " << "indique um numero enter [0-" << ROWS-1 << "] para a linha: ";
        cin >> row;
        cout << ptr_player->name << " indique um numero enter [0-" << COLUMNS-1 << "] para a coluna: ";
        cin >> column;   
    } while(!validate_play(row, column, game_board));
 
    game_board[row][column] = ptr_player->piece;
}


// Verifica se alguem ganhou
char check_winner(char game_board[ROWS][COLUMNS]) {
    bool no_winner = false;

    for (int i = 0; i < ROWS; i++) {
        if (game_board[i][0] != '-' && game_board[i][0] == game_board[i][1] && game_board[i][1] == game_board[i][2]) {
            return game_board[i][0];
        }       
    }   

    for (int i = 0; i < COLUMNS; i++) {
        if (game_board[0][i] != '-' && game_board[0][i] == game_board[1][i] && game_board[1][i] == game_board[2][i]) {
            return game_board[0][i];
        }       
    }    

    if (game_board[0][0] != '-' && game_board[0][0] == game_board[1][1] && game_board[1][1] == game_board[2][2]) {
        return game_board[0][0];
    }

    if (game_board[2][0] != '-' && game_board[2][0] == game_board[1][1] && game_board[1][1] == game_board[0][2]) {
        return game_board[2][0];
    }  

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (game_board[i][j] == '-') {
               no_winner = true; 
            }
        }
    }

    if (!no_winner) {
        return 'e';
    }

    return '-';
}


// Restart game_board
void restart_game_board(char game_board[ROWS][COLUMNS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            game_board[i][j] = '-';
        }
    }
}


// Existe um vencedor
void winner(struct Player *ptr_player, char game_board[ROWS][COLUMNS]) {
    cout << "Parabens! O utilizador \"" << ptr_player->name << "\" ganhou!" << endl;
    cout << "Vamos continuar a jogar!" << endl;

    ptr_player->points++;

    restart_game_board(game_board);
}

// Sem vencedor
void no_winner(char game_board[ROWS][COLUMNS]) {
    cout << "Empataram" << endl;
    cout << "Vamos continuar a jogar!" << endl;

    restart_game_board(game_board);
}




int main() {

    struct Player player1("Jogador 1", 'x', true);
    struct Player *ptr_player1 = &player1;

    struct Player player2("Jogador 2", '0');
    struct Player *ptr_player2 = &player2;

    char check;
    char game_board[ROWS][COLUMNS] = { {'-','-','-'}, {'-','-','-'}, {'-','-','-'} };

    do {
        print_header(ptr_player1, ptr_player2);
        print_board(game_board);

        if (ptr_player1->playing) {
            play(ptr_player1, game_board);
            ptr_player1->playing = false;
            ptr_player2->playing = true;
        } else {
            play(ptr_player2, game_board);
            ptr_player2->playing = false;
            ptr_player1->playing = true;
        }

        check = check_winner(game_board);

        if (check == ptr_player1->piece) {
            winner(ptr_player1, game_board);
        }
        else if (check == ptr_player2->piece) {
            winner(ptr_player1, game_board);
        } else if (check == 'e') {
            no_winner(game_board);
        }    

    } while(true);

    return 0;
}