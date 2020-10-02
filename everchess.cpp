#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*
 * Struct to store pawn location
 * x stores the row movement
 * y stores column movement
 */
struct point{
    int x;
    char y;
};

/*
 * Struct to store a particular move
 * win tells if a move lead to a win
 * changePlayer tells whether turns must switch
 * end tells the last played location
 */
struct movement {
    bool win;
    bool changePlayer;
    struct point end;
};

/*
 * Class to store board information
 */
class Board {
    public:
        // board to store pawn states
        vector<vector<char>> board;
        int height = 8;
        int width = 8;
        // maps to convert pawn moves to board moves and vice-versa
        map<char, int> charToInt;
        map<int, char> intToChar;
        // initialize board and maps
        Board();
        void printBoard();
};

/*
 * Constructor to initialize data structures
 */
Board::Board() {
    charToInt.insert({'A', 0});
    charToInt.insert({'B', 1});
    charToInt.insert({'C', 2});
    charToInt.insert({'D', 3});
    charToInt.insert({'E', 4});
    charToInt.insert({'F', 5});
    charToInt.insert({'G', 6});
    charToInt.insert({'H', 7});

    intToChar.insert({0, 'A'});
    intToChar.insert({1, 'B'});
    intToChar.insert({2, 'C'});
    intToChar.insert({3, 'D'});
    intToChar.insert({4, 'E'});
    intToChar.insert({5, 'F'});
    intToChar.insert({6, 'G'});
    intToChar.insert({7, 'H'});

    board.resize(height);
    for (int i = 0; i < height; i++) {
        board[i].resize(8, ' ');
    }
    // 2nd row from top and bottom contains the pawns
    // B = Black
    // W = White
    for (int i = 0; i < width; i++) {
            board[1][i] = 'B';
            board[6][i] = 'W';
    }
};

/*
 * Method to print game board
 * No Params
 * Returns void
 */
void Board::printBoard() {
    // design to printing board
    cout << "\n   --------------------------------\n";
    for (int i = 0; i < height; i++) {
        cout << height - i << "  |";
        for (int j = 0; j < width; j++) {
            cout << " " << board[i][j] << " |";
        }
        cout << "\n   --------------------------------\n";
    }
    cout << "     A   B   C   D   E   F   G   H " << endl;
    cout << "   --------------------------------\n";
}

/*
 * Method to get all available moves
 * Params: Board, Player
 * Returns a vector of all available moves
 */
vector<pair<struct point, struct point>> getAvailableMoves(Board &b, char player) {
    vector<pair<struct point, struct point>> availableMoves;
    if (player == 'B') {
        for (int i = 0; i < b.height - 1; i++) {
            for (int j = 0; j < b.width; j++) {
                // boundary checks
                if (j == 0) {
                    // down and right diagonal
                    if (b.board[i][j] == player && b.board[i+1][j+1] == 'W') {
                        struct point start;
                        struct point end;
                        start.x = b.height - i;
                        start.y = b.intToChar[j];

                        end.x = b.height - i - 1;
                        end.y = b.intToChar[j+1];
                        availableMoves.push_back({start, end});
                    }
                }
                // boundary checks
                if (j == 7) {
                    // down and left diagonal
                    if (b.board[i][j] == player && b.board[i+1][j-1] == 'W') {
                        struct point start;
                        struct point end;
                        start.x = b.height - i;
                        start.y = b.intToChar[j];

                        end.x = b.height - i - 1;
                        end.y = b.intToChar[j-1];
                        availableMoves.push_back({start, end});
                    }
                }
                else {
                    if (b.board[i][j] == player && b.board[i+1][j+1] == 'W') {
                        struct point start;
                        struct point end;
                        start.x = b.height - i;
                        start.y = b.intToChar[j];

                        end.x = b.height - i - 1;
                        end.y = b.intToChar[j+1];
                        availableMoves.push_back({start, end});
                    }
                    if (b.board[i][j] == player && b.board[i+1][j-1] == 'W') {
                        struct point start;
                        struct point end;
                        start.x = b.height - i;
                        start.y = b.intToChar[j];

                        end.x = b.height - i - 1;
                        end.y = b.intToChar[j-1];
                        availableMoves.push_back({start, end});
                    }
                }
            }
        }
    }

    if (player == 'W') {
        for (int i = 0; i < b.height - 1; i++) {
            for (int j = 0; j < b.width; j++) {
                // boundary checks
                if (j == 0) {
                    // up and right diagonal
                    if (b.board[i][j] == player && b.board[i-1][j+1] == 'B') {
                        struct point start;
                        struct point end;
                        start.x = b.height - i;
                        start.y = b.intToChar[j];

                        end.x = b.height - i + 1;
                        end.y = b.intToChar[j+1];
                        availableMoves.push_back({start, end});
                    }
                }
                // boundary checks
                if (j == 7) {
                    // up and left diagonal
                    if (b.board[i][j] == player && b.board[i-1][j-1] == 'B') {
                        struct point start;
                        struct point end;
                        start.x = b.height - i;
                        start.y = b.intToChar[j];

                        end.x = b.height - i + 1;
                        end.y = b.intToChar[j-1];
                        availableMoves.push_back({start, end});
                    }
                }
                else {
                    if (b.board[i][j] == player && b.board[i-1][j+1] == 'B') {
                        struct point start;
                        struct point end;
                        start.x = b.height - i;
                        start.y = b.intToChar[j];

                        end.x = b.height - i + 1;
                        end.y = b.intToChar[j+1];
                        availableMoves.push_back({start, end});
                    }
                    if (b.board[i][j] == player && b.board[i-1][j-1] == 'B') {
                        struct point start;
                        struct point end;
                        start.x = b.height - i;
                        start.y = b.intToChar[j];

                        end.x = b.height - i + 1;
                        end.y = b.intToChar[j-1];
                        availableMoves.push_back({start, end});
                    }
                }
            }
        }
    }
    return availableMoves;
}

/*
 * Method to check if a given pair of start and end locations exists in all possible moves
 * Params: Vector of all possible locations, start loc, end loc
 * returns bool
 */
bool checkAvailable(vector<pair<struct point, struct point>> allMoves, struct point start, struct point end) {
    for (int i = 0; i < allMoves.size(); i++) {
        if (start.x == allMoves[i].first.x &&
        start.y == allMoves[i].first.y && 
        end.x == allMoves[i].second.x &&
        end.y == allMoves[i].second.y) {
            return true;
        }
    }
    return false;
}

/*
 * Method to check if a player is in a winning position
 * Params: Board, player
 * returns bool
 */
bool checkWin(Board &b, char player) {
    if (player != 'B' || player != 'W') {
        return false;
    }

    if (player == 'B') {
        for (int i = 0; i < b.width; i++) {
            if (b.board[7][i] == 'B') {
                return true;
            }
        }
    }

    if (player == 'W') {
        for (int i = 0; i < b.width; i++) {
            if (b.board[0][i] == 'W') {
                return true;
            }
        }
    }
    return false;
}

/*
 * Method to check if a player has any moves left
 * Params: Board, player
 * returns bool
 */
bool checkNoMoves(Board &b, char player) {
    vector<pair<struct point, struct point>> allMoves = getAvailableMoves(b, player);

    if (allMoves.size() > 0) {
        return false;
    }

    if (player == 'B') {
       for (int i = 0; i < b.height - 1; i++) {
           for (int j = 0; j < b.width; j++) {
               if (b.board[i][j] == player && b.board[i+1][j] == ' ') {
                   return false;
               }
           }
       }
    }
    if (player == 'W') {
       for (int i = 0; i < b.height - 1; i++) {
           for (int j = 0; j < b.width; j++) {
               if (b.board[i][j] == player && b.board[i-1][j] == ' ') {
                   return false;
               }
           }
       }
    }

    return true;
}

/*
 * Method to move a pawn to a particular location
 * Params: Board, player, start loc, end loc.
 * returns movement struct
 */
struct movement movePawn(Board &b, char player, struct point start, struct point end) {
    // cout << "Inside Move Pawn" << endl;
    struct movement result;
    struct point finalEnd;
    finalEnd.x = -1;
    finalEnd.y = 'X';
    result.win = false;
    result.changePlayer = false;
    result.end = finalEnd;

    // cout << "Player -- > " << player << endl;
    char opponent;
    opponent = (player == 'W')? 'B': 'W';

    if (start.x < 1 || start.x > 8) {
        cout << "Invalid row " << endl;
        return result;
    }

    if (end.x < 1 || end.x > 8) {
        cout << "Invalid col " << endl;
        return result;
    }

    if (b.charToInt.find(start.y) == b.charToInt.end()) {
        cout << "Invalid col " << endl;
        return result;
    }

    if (b.charToInt.find(end.y) == b.charToInt.end()) {
        cout << "Invalid col " << endl;
        return result;
    }

    if (b.board[b.height - start.x][b.charToInt[start.y]] != player) {
        cout << "No Pawn in that location" << endl;
        return result;
    }

    bool captureMove = false;
    vector<pair<struct point, struct point>> allMoves = getAvailableMoves(b, player);

    if (allMoves.size() > 0) {
        captureMove = true;
    }

    if (player == 'B') {
        if (captureMove) {
            if (!checkAvailable(allMoves, start, end)) {
                cout << "Cannot Move there"<<endl;
                return result;
            }
        }
    }

    if (player == 'W') {
        if (captureMove) {
            if (!checkAvailable(allMoves, start, end)) {
                cout << "Cannot Move there"<<endl;
                return result;
            }
        }
    }

    if (!captureMove) {
        if (b.board[b.height - end.x][b.charToInt[end.y]] == opponent) {
            cout << "Cannot Move there" << endl;
            return result;
        }
    }

    b.board[b.height - end.x][b.charToInt[end.y]] = player;
    b.board[b.height - start.x][b.charToInt[start.y]] = ' ';
    b.printBoard();

    if (checkWin(b, player)) {
        cout << "Player " << player << " has won";
        result.win = true;
        return result;
    }

    if (checkNoMoves(b, opponent)) {
        cout << "Player " << opponent << " has 0 moves, " << " Player " << player << " Wins";
        result.win = true;
        return result;
    }

    if(captureMove) {
        result.end = end;
        return result;
    }

    result.changePlayer = true;
    return result;
}

bool checkAlreadyDone(vector<struct point> capturedMoves, struct point start) {
    for (int i = 0; i < capturedMoves.size(); i++) {
        if (start.x == capturedMoves[i].x &&
        start.y == capturedMoves[i].y) {
            return true;
        }
    }
    return false;
}

int main() {
    Board b;

    bool playerWins = false;
    char currPlayer = 'W';
    cout << "This game is called EVERCHESS" << endl;
    cout << "Let's have some fun" << endl;
    cout << "The board looks something like the chess board, but contains only pawns" << endl;

    b.printBoard();
    while (!playerWins) {
        vector<struct point> captureMoves;
        bool isDone = false;
        while (!isDone) {
            cout << "\nPlayer " << currPlayer << " makes the move";
            int sRow,eRow;
            char sCol, eCol;
            cout << "\nEnter Pawn Row Number --> ";
            cin >> sRow;
            cout << "\nEnter Pawn Col Number --> ";
            cin >> sCol;
            cout << "\nEnter Row Number to move pawn to --> ";
            cin >> eRow;
            cout << "\nEnter Col Number to move pawn to--> ";
            cin >> eCol;

            cout << "\n";

            struct point start;
            struct point end;
            start.x = sRow;
            start.y = sCol;
            end.x = eRow;
            end.y = eCol;

            if (checkAlreadyDone(captureMoves, start)) {
                cout << "\nThis pawn captured in the last move, it is resting.";
                cout << "\nPlease try something else";
                continue;
            }

            struct movement result = movePawn(b, currPlayer, start, end);

            if (result.win == true) {
                playerWins = true;
                isDone = true;
                break;
            }
            if (result.changePlayer == true) {
                if (currPlayer == 'W') {
                    currPlayer = 'B';
                } else {
                    currPlayer = 'W';
                }
                isDone = true;
            } else {
                if (result.end.x != -1 && result.end.y != 'X') {
                    captureMoves.push_back(result.end);
                    continue;
                }
            }
        }
    }
    return 0;
}