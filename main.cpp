// Treasure Hunt
// A treasure is hidden on a 5x5 grid. Guess where it is using hot/cold hints!

#include <iostream>
#include <cstdlib>   // rand(), abs()
#include <ctime>     // time()
using namespace std;

int main() {
    srand(time(0));                 // makes the treasure spot different every game

    const int SIZE = 5;             // grid is 5 x 5
    int treasureRow = rand() % SIZE;
    int treasureCol = rand() % SIZE;
    int tries = 6;

    cout << "=== TREASURE HUNT ===\n";
    cout << "A treasure is buried on a 5x5 island.\n";
    cout << "Pick a row and column (1-5). You have " << tries << " digs!\n\n";

    while (tries > 0) {
        int row, col;
        cout << "Digs left: " << tries << "\n";
        cout << "Row (1-5): ";
        cin >> row;
        cout << "Column (1-5): ";
        cin >> col;

        // Check the input is valid (a number between 1 and 5)
        if (cin.fail() || row < 1 || row > SIZE || col < 1 || col > SIZE) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Oops! Enter numbers from 1 to 5.\n\n";
            continue;               // doesn't use up a dig
        }

        row--;                      // arrays/grids start at 0, players start at 1
        col--;

        if (row == treasureRow && col == treasureCol) {
            cout << "\n*** YOU FOUND THE TREASURE! You win! ***\n";
            return 0;
        }

        // Distance = how many steps away the guess is
        int distance = abs(row - treasureRow) + abs(col - treasureCol);

        if (distance <= 2) {
            cout << "HOT! You're very close!\n\n";
        } else if (distance <= 4) {
            cout << "WARM... getting closer.\n\n";
        } else {
            cout << "COLD. Try somewhere else.\n\n";
        }

        tries--;
    }

    cout << "Out of digs! The treasure was at row " << treasureRow + 1
         << ", column " << treasureCol + 1 << ".\n";
    cout << "Better luck next time!\n";
    return 0;
}
