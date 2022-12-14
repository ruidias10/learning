#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

string tolowercase(string input) {
    char ch;
    int dec;
    string output;

    for (int i = 0; i < input.length(); i++) {
        dec = (int)input[i];

        if (dec > 64 && dec < 91) {
            char ch = (char)(int)input[i] + 32;
            output += ch;
        } else {
            output += input[i];
        }
    }

    return output;
}


class Player {
private:
    int wins;
    bool isPlaying;

public:
    string name;

    Player(string name): name (name) {
        this->wins = 0;
        this->isPlaying = false;
    }

    string getName() {
        return this->name;
    }

    int getWins() {
        return this->wins;
    }
    void addwin() {
        this->wins+=1;
    }

    bool getIsPlaying() {
        return this->isPlaying;
    }
    void toggleIsPlaying() {
        this->isPlaying = !this->isPlaying;
    }
};

class Ship {
private:
    int size;
    char shipValue;
    vector<string> positions;

public:
    Ship(int size, vector<string> positions): size (size), positions (positions) {
        this->shipValue = 'A';
    }

    void getPositions() {
        for (int i = 0; i < this->positions.size(); i++) {
            cout << this->positions[i] << endl;
        }
    }
};


class Board {
private:
    Player* player;
    vector<string> shipPositions;

    char** matriz;
    char defaultChar;

    const int ROWS = 7;
    const int COLUMNS = 7;

public:
    Board(Player* player): player (player) {
        this->defaultChar = '~';
        this->startBoard();
    }

    void startBoard() {
        this->matriz = new char* [this->ROWS];

        for (int i = 0; i < this->ROWS; i++) {
            this->matriz[i] = new char[this->COLUMNS];

            for (int j = 0; j < this->COLUMNS; j++) {
                this->matriz[i][j] = this->defaultChar;
            }
        }
    }

    bool shipAttackPosition(string position) {
        int irow, icolumn;
        string column;
        char ccolumn;

        irow = stoi(position.substr (0,1)) - 1;
        column = tolowercase(position.substr (1,1));

        ccolumn = column[0];
        icolumn = ccolumn;
        icolumn = icolumn - 97;

        if ((irow >= 0 && irow < 7) && (icolumn >= 0 && icolumn < 7)) {
            if (this->matriz[irow][icolumn] == 'B') {

                this->matriz[irow][icolumn] = '*';

                // barco ao fundo
                int cnt = 0;
                bool isLime = false;
                for (int i = 0; i < this->ROWS; i++) {
                    for (int j = 0; j < this->COLUMNS; j++) {
                        
                        if (this->matriz[i][j] == '*') {
                            cnt++;
                        }

                        if (i == irow && j == icolumn) {
                            isLime = true;
                       }
                    }
                }  

                cout << "cntcntcntcntcntcnt " << cnt << endl;
                
                if (isLime && cnt > 1) {
                    printf("\033[0;32mBarco de %d quadrados ao fundo!\033[0m\n", cnt);
                }               
                
                return true;
            }


            if (this->matriz[irow][icolumn] != '*') {
                this->matriz[irow][icolumn] = 'X';
            }
            
            return false;
        }

        return false;
    }

    bool addShipPosition(vector<string> positions) {
        for (int i = 0; i < positions.size(); i++) {
            if (!this->isFreePosition(positions[i])) {
                return false;
            }

            if (!this->isValidPosition(positions[i])) {
                return false;
            }  

            // falta validar se positions tem os elementos na orizontal ou na vertical          

            this->shipPositions.push_back(positions[i]);
        }
        
        this->updateShipPositionInMatriz();
        return true;
    }

    bool isFreePosition(string position) {
        if (this->shipPositions.empty()) {
            return true;
        }

        for (int i = 0; i < this->shipPositions.size(); i++) {
            if (shipPositions[i] == position) {
                return false;
            }
        }

        return true;
    }


    bool isValidPosition(string position) {
        int irow, icolumn;
        string column;
        char ccolumn;

        irow = stoi(position.substr (0,1)) - 1;
        column = tolowercase(position.substr (1,1));

        ccolumn = column[0];
        icolumn = ccolumn;
        icolumn = icolumn - 97;

        return ((irow >= 0 && irow < 7) && (icolumn >= 0 && icolumn < 7));
    }

    void updateShipPositionInMatriz() {
        int irow, icolumn;
        string column;
        char ccolumn;

        for (int i = 0; i < this->shipPositions.size(); i++) {
            irow = stoi(shipPositions[i].substr (0,1)) - 1;
            column = tolowercase(shipPositions[i].substr (1,1));

            ccolumn = column[0];
            icolumn = ccolumn;
            icolumn = icolumn - 97;

            this->matriz[irow][icolumn] = 'B';
        }   
    }

    void playerInfo() {
        cout << "Tabuleiro do jogador " << player->getName() << endl;
        cout << "Vitorias: " << player->getWins() << endl;
        cout << "----------------------------" << endl;
    }

    void debug() {
        cout << "  ";
        for (int i = 0; i < this->ROWS; i++) {
            char ch = (char)(i + 65);
            cout << " " << ch;
        }

        cout << endl;
        
        for (int i = 0; i < this->ROWS; i++) {
            cout << " " << (i + 1);

            for (int j = 0; j < this->COLUMNS; j++) {
                if (this->matriz[i][j] == 'B') {
                    printf("\033[0;32m %c\033[0m", this->matriz[i][j]);
                } else if (this->matriz[i][j] == '~') {
                    printf("\x1B[36m %c\033[0m", this->matriz[i][j]);
                } else {
                    printf("\033[0;31m %c\033[0m", this->matriz[i][j]);
                }
            }

            cout << endl;
        }
    }
};


class Game {
private:
    Board* board1;
    Board* board2;

    Player* player1;
    Player* player2;

    int shipLimit;

public:
    Game() {
        this->board1 = nullptr;
        this->board2 = nullptr;
        this->player1 = nullptr;
        this->player2 = nullptr;

        this->shipLimit = 3;
    }

    void run() {
        
        this->printASCIILogo();
  
        string playerName1 = this->askPlayerName("primeiro");
        string playerName2 = this->askPlayerName("segundo");

        this->player1 = new Player(playerName1);
        this->player2 = new Player(playerName2);

        this->board1 = new Board(player1);
        this->board2 = new Board(player2);


        cout << endl;
        this->board1->playerInfo();
        //this->board1->debug();
        this->playerChooseChipsPositions(this->player1, this->board1);

        cout << endl;
        cout << endl;

        this->board2->playerInfo();
        //this->board2->debug();        
        this->playerChooseChipsPositions(this->player2, this->board2);

        
        this->playersChooseAttack(this->player1, this->board2);
        this->playersChooseAttack(this->player2, this->board1);
    }

    void playersChooseAttack(Player* player, Board* board) {
//1a, 1b
//4a, 5a, 6a
//3e, 4e, 5e, 6e

        int shots = 3;
        string position;

        cout << endl;
        board->debug();
        cout << endl;           

         do {
            cout << player->getName() << " tem " << shots << " jogadas" << endl;
            cout << "indique a posicao para atacar : exemplo (1a) ";

            getline(cin, position);

            if (board->shipAttackPosition(position)) {
                printf("\033[0;32mOtima jogada..\033[0m");
                cout << endl;    
            } else {
                printf("\033[0;31mAinda nao foi desta! Tente novamente.\033[0m");
                cout << endl;                
            }

            cout << endl;
            board->debug();
            cout << endl;            

            shots--;
        } while(shots > 0);    
    }

    void playerChooseChipsPositions(Player* player, Board* board) {
        vector<string> positions;

        int counter = 0;
        do {
            int gridSpace = counter + 2;

            positions = this->askShipPosition(player, gridSpace);

            if (positions.size() == gridSpace && board->addShipPosition(positions)) {
                //cout << endl;
                //board->debug();
                //cout << endl;
                counter++;
            }
            else {
                printf("\033[0;31mOs valores inseiridos nao sao validos! Tente novamente.\033[0m");
                cout << endl;
            }

        } while(counter < this->shipLimit);
    }


    vector<string> askShipPosition(Player* player, int gridSpace) {
        string example;
        string position;
        vector<string> positions;

        for (int i = 1; i <= gridSpace; i++) {
            example = example +  to_string(i) + "a, ";
        }

        example.erase(example.size() - 2);

        cout << player->getName() << " indique a posicao para o barco de " << gridSpace << " quadrados: exemplo (" << example << ") ";
        getline(cin, position);

        stringstream streamPositions(position);

        while (streamPositions.good()) {
            string token;
            getline(streamPositions, token, ',');

            token.erase(token.find_last_not_of(' ') + 1); //suffixing spaces
            token.erase(0, token.find_first_not_of(' ')); //prefixing spaces

            positions.push_back(token);
        }

        return positions;
    }


    string askPlayerName(string position) {
        string name;

        cout << "Indique o nome do " << position << " jogador: ";
        getline(cin, name);

        return name;
    }

    void printASCIILogo() {
        cout << "                       $o" << endl;
        cout << "                       $                     ........." << endl;
        cout << "                      $$$      .oo..     'oooo'oooo'ooooooooo...." << endl;
        cout << "                       $       $$$$$$$" << endl;
        cout << "                   .ooooooo.   $$!!!!!" << endl;
        cout << "                 .'.........'. $$!!!!!      o$$oo.   ...oo,oooo,oooo'ooo''" << endl;
        cout << "    $          .o'  oooooo   '.$$!!!!!      $$!!!!!       'oo''oooo''" << endl;
        cout << " ..o$ooo...    $                '!!''!.     $$!!!!!" << endl;
        cout << " $    ..  '''oo$$$$$$$$$$$$$.    '    'oo.  $$!!!!!" << endl;
        cout << " !.......      '''..$$ $$ $$$   ..        '.$$!!''!" << endl;
        cout << " !!$$$!!!$$!$$!!!!!!!!!!oo.....     ' ''  o$$o .      ''oo.." << endl;
        cout << " !!!$$!!!!!!!!!!!!!!!!!!!!!!!!!!!!ooooo..      'o  oo..    $" << endl;
        cout << "  '!!$$!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!oooooo..  ''   ,$" << endl;
        cout << "  '!!$$!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!oooooo..  ''   ,$" << endl;
        cout << "   '!!$!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!oooo..$$" << endl;
        cout << "    !!$!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!$'" << endl;
        cout << "    '$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$!!!!!!!!!!!!!!!!!!," << endl;
        cout << ".....$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$....." << endl;


        cout << endl;
        cout << "_____________________________________________________________________" << endl;

        cout << "BATALHA NAVAL" << endl;
    }

};









int main() {
    Game* game = new Game();
    game->run(); 

    return 0;
}
