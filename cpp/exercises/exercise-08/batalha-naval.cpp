#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;


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
            cout << "POSICAO" << endl;
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

    bool addShipPosition(vector<string> positions) {
        for (int i = 0; i < positions.size(); i++) {
            cout << "POSICAOOOOOOOOOOO " << positions[i] << endl;

            if (!this->isFreePosition(positions[i])) {
                return false;
            }

            this->shipPositions.push_back(positions[i]);
        }

        return true;
    }

    bool isFreePosition(string position) {
        if (this->shipPositions.empty()) {
            return true;
        }

        for (int i = 0; i < shipPositions.size(); i++) {
            cout << "     E LIVRE " << shipPositions[i] << " " << position << endl;
            if (shipPositions[i] == position) {
                return false;
            }
            
        }

        return true;
    }


    void debug() {
        
        //this->shipPositions

        cout << "Tabuleiro do jogador " << player->getName() << endl;
        cout << "Vitorias: " << player->getWins() << endl;
        cout << "----------------------------" << endl;

        cout << "  ";
        for (int i = 0; i < this->ROWS; i++) {
            char ch = (char)(i + 65);
            cout << " " << ch;
        }

        cout << endl;
        
        for (int i = 0; i < this->ROWS; i++) {
            cout << " " << (i + 1);

            for (int j = 0; j < this->COLUMNS; j++) {
                printf("\x1B[36m %c\033[0m", this->matriz[i][j]);
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

    void start() {
        vector<string> positions;

        this->printASCIIData();
  
        string playerName1 = this->askPlayerName("primeiro");
        string playerName2 = this->askPlayerName("segundo");

        this->player1 = new Player(playerName1);
        this->player2 = new Player(playerName2);


        this->board1 = new Board(player1);
        this->board2 = new Board(player2);

        cout << endl;
        this->board1->debug();
        cout << endl;
        cout << endl;
        this->board2->debug();


        int counter = 0;
        do {
            positions = this->askShipsPosition(this->player1, counter + 2);

            if (this->board1->addShipPosition(positions)) {
                this->board1->debug();
                counter++;
            }
            else {
                printf("\033[0;31mOs valores inseiridos nao sao validos! Tente novamente.\033[0m");
                cout << endl;
            }

        } while(counter < this->shipLimit);


        /*
        for (int i = 0; i < this->shipLimit; i++) {
            int size = i + 2;
            positions = this->askShipsPosition(size);

            //Ship* ship = new Ship(size, positions);
            //this->board1->addShip(ship);
            
            
            //for (int i = 0; i < positions.size(); i++) {
            //    cout << positions[i] << endl;
            //}
            
            this->board1->addShipPosition(positions);
        }
        */
    }

    vector<string> askShipsPosition(Player* player, int gridSpace) {
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

    void printASCIIData() {
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
    game->start(); 

    return 0;
}
