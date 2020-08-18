//Simple console app game - TicTacToe by Djordje Janjic

#include <iostream>
using namespace std;

void drawingBoard(int x, char c)
{
    
    for (int i = 0; i <= 10; i++) {
        for (int j = 0; j <= 10; j++) {

            if ((x == 0) && (i == 1) && (j == 1)) {
                cout << c;
                continue;
            }
            if ((x == 1) && (i == 1) && (j == 5)) {
                cout << c;
                continue;
            }
            if ((x == 2) && (i == 1) && (j == 9)) {
                cout << c;
                continue;
            }
            if ((x == 3) && (i == 5) && (j == 1)) {
                cout << c;
                continue;
            }
            if ((x == 4) && (i == 5) && (j == 5)) {
                cout << c;
                continue;
            }
            if ((x == 5) && (i == 5) && (j == 9)) {
                cout << c;
                continue;
            }
            if ((x == 6) && (i == 9) && (j == 1)) {
                cout << c;
                continue;
            }
            if ((x == 7) && (i == 9) && (j == 5)) {
                cout << c;
                continue;
            }
            if ((x == 8) && (i == 9) && (j == 9)) {
                cout << c;
                continue;
            }
            if (i != 3 && i != 7) {
                if (j == 3 || j == 7) {
                    cout << "|";
                }
                else
                    cout << " ";
            }
            else {
                cout << "-";
            }
        }
        printf("\n");
    }      
}

bool gameLogic(int array[], int n) {
    
    int sum;

    for (int i = 0; i < n-2; i++) {
        sum = 0;
        sum += array[i];
        for (int j = i+1; j < n; j++) {
            sum += array[j];
        }
        if (sum == 3 || sum == 9 || sum == 12 || sum == 15) {
            cout << "\nGAME OVER\n";
            return true;
        }
    }
    return false;
}

void userInput() 
{
    int x, y, pozicija = 0;
    bool end = false;

    int xArray[5];
    int yArray[5];

    for (int i = 0; i < 5; i++) {
        do {
            cout << "Upisite u poziciju gde zelite da stavite X (0, 1, 2, 3, 4, 5, 6, 7, 8): ";
            cin >> x;
        } while (!(x >= 0 && x <= 8));

        xArray[pozicija] = x;

        drawingBoard(x, 'X');

        end = gameLogic(xArray, pozicija);

        if (end == true) {
            cout << "\nPobedio je IKS!\n";
            return;
        }

        do {
            cout << "Upisite u poziciju gde zelite da stavite O (0, 1, 2, 3, 4, 5, 6, 7, 8): ";
            cin >> y;
        } while (!(y >= 0 && y <= 8));

        yArray[pozicija] = y;

        drawingBoard(y, 'O');

        end = gameLogic(yArray, pozicija);

        if (end == true) {
            cout << "\nPobedio je OKS!\n";
            return;
        }

        pozicija++;
    } 
}

int main()
{
    userInput();
    
    return 0;
}

