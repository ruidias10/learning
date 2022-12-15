#include <iostream>
#include <sstream>
#include <string>
#include <vector>

/*
1a, 1b
4a, 5a, 6a
3e, 4e, 5e, 6e
*/

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

    void echoPlayerInfo() {
      cout << "----------------------------------" << endl;
      cout << "Jogador: " << this->getName() << endl;
      cout << "Vitorias: " << this->getWins() << endl;
      cout << "----------------------------------" << endl;
    } 

    void echoPlayerWin() {
      cout << "----------------------------------" << endl;
      printf("\033[0;32mParabens! Parabens! Parabens! \033[0m");
      cout << endl << "O jogador " << this->getName() << " venceu!!!"<< endl;
      cout << "Vitorias: " << this->getWins() << endl;
      cout << "----------------------------------" << endl;
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
    
    vector<string> shipSizeTwo;
    vector<string> shipSizeThree;
    vector<string> shipSizeFour;

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

    bool thereAreShipsToAttack() {
      return !(this->shipSizeTwo.empty() && this->shipSizeThree.empty() && this->shipSizeFour.empty());
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
                for (int i = 0; i < this->shipSizeTwo.size(); i++) {
                  if (position == this->shipSizeTwo[i]) {
                    this->shipSizeTwo.erase(this->shipSizeTwo.begin()+ i);
                    if (this->shipSizeTwo.empty()) {
                      printf("\033[0;32mBarco de 2 quadrados ao fundo!\033[0m\n");
                      return true;
                    }
                  }
                }

                for (int i = 0; i < this->shipSizeThree.size(); i++) {
                  if (position == this->shipSizeThree[i]) {
                    this->shipSizeThree.erase(this->shipSizeThree.begin()+ i);
                    if (this->shipSizeThree.empty()) {
                      printf("\033[0;32mBarco de 3 quadrados ao fundo!\033[0m\n");
                      return true;
                    }
                  }
                }

                for (int i = 0; i < this->shipSizeFour.size(); i++) {
                  if (position == this->shipSizeFour[i]) {
                    this->shipSizeFour.erase(this->shipSizeFour.begin()+ i);
                    if (this->shipSizeFour.empty()) {
                      printf("\033[0;32mBarco de 4 quadrados ao fundo!\033[0m\n");
                      return true;
                    }
                  }
                }

                return true;
            }

            if (this->matriz[irow][icolumn] != '*') {
                this->matriz[irow][icolumn] = 'X';
            }
        }

        return false;
    }

    bool addShipPosition(vector<string> positions) {
        int size = positions.size();
        for (int i = 0; i < size; i++) {
            if (!this->isFreePosition(positions[i])) {
                return false;
            }

            if (!this->isValidPosition(positions[i])) {
                return false;
            }  

            // falta validar se positions tem os elementos juntos na orizontal ou na vertical

            this->shipPositions.push_back(positions[i]);

            switch(size) {
              case 2:
                this->shipSizeTwo.push_back(positions[i]);
                break;
              case 3:
                this->shipSizeThree.push_back(positions[i]);
                break;
              default:
                this->shipSizeFour.push_back(positions[i]);
            }        
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
        this->player1->echoPlayerInfo();
        this->playerChooseChipsPositions(this->player1, this->board1);

        cout << endl;
        this->player2->echoPlayerInfo();
        this->playerChooseChipsPositions(this->player2, this->board2);


        do {
            cout << endl;
            this->player1->echoPlayerInfo();
            this->player1->toggleIsPlaying();
            this->playersChooseAttack(this->player1, this->board2);

            if (!this->board2->thereAreShipsToAttack()) {
              break;
            }

            cout << endl;
            this->player2->echoPlayerInfo();
            this->player2->toggleIsPlaying();
            this->playersChooseAttack(this->player2, this->board1);
            
            if (!this->board1->thereAreShipsToAttack()) {
              break;
            }            

        } while(true);

        if (this->player1->getIsPlaying()) {
          this->player1->addwin();
          this->player1->echoPlayerWin();
        }
        else {
          this->player1->addwin();
          this->player1->echoPlayerWin();
        }

        this->printASCIIWin();
    }


    void playersChooseAttack(Player* player, Board* board) {
        int shots = 3;
        string position;

        cout << endl;
        board->debug();
        cout << endl;

         do {
            cout << "----------------------------" << endl;
            cout << player->getName() << " tem " << shots << " jogadas" << endl;
            cout << "Indique a posicao para atacar: exemplo (1a): ";
            
            getline(cin, position);

            if (board->shipAttackPosition(position)) {
                printf("\033[0;32mOtima jogada..\033[0m");
            } else {
                printf("\033[0;31mAcertou na agua!\033[0m");
            }

            cout << endl << endl;
            board->debug();
            cout << endl;

            shots--;

            if (!board->thereAreShipsToAttack()) {
              break;
            }

        } while(shots > 0);
    }

    void playerChooseChipsPositions(Player* player, Board* board) {
        vector<string> positions;

        int counter = 0;
        do {
            int gridSpace = counter + 2;

            positions = this->askShipPosition(player, gridSpace);

            if (positions.size() == gridSpace && board->addShipPosition(positions)) {
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

    void printASCIIWin() {
        cout << "     _______________" << endl;
        cout << "    |@@@@|     |####|" << endl;
        cout << "    |@@@@|     |####|" << endl;        
        cout << "    |@@@@|     |####|" << endl;        
        cout << "    \\@@@@|     |####/" << endl;
        cout << "     \\@@@|     |###/" << endl;        
        cout << "      `@@|_____|##'" << endl;
        cout << "           (O)'" << endl;                
        cout << "        .-'''''-.'" << endl;                
        cout << "      .'  * * *  `.'" << endl;                        
        cout << "     :  *       *  :" << endl;                        
        cout << "    : ~ A S C I I ~ :" << endl;                        
        cout << "    : ~ A W A R D ~ :" << endl;                        
        cout << "     :  *       *  :" << endl;                        
        cout << "      `.  * * *  .'" << endl;
        cout << "        `-.....-''" << endl; 
        cout << "" << endl;          
    }
};


int main() {
    Game* game = new Game();
    game->run(); 

    return 0;
}
