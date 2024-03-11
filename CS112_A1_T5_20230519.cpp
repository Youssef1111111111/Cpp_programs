/*Program: Two players compete in this strategy mathematics game while holding a stack of money or other tokens in between them.Each player takes a coin out of the pile in turn.
 always taking out a non-zero square number of coins (1, 4, 9, 16,...), and the winner is the one who removes the last coin*/

//author:youssef yasser Elsayed

//id:20230519

//version:1.0

//Date: 2 march.2024


#include <iostream>
#include <cmath>
#include <random>

using namespace std;
// Function to check if a number is a perfect square
bool isPerfectSquare(int n) {
    int root = sqrt(n);
    return n == root * root;
}
// Function to generate a random number within a given range
int getRandomNumber(int min, int max) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

int main() {
    cout << "Welcome to the square game" << endl;
    cout << "Have a great game! Good luck" << endl;

    while (true) {
        int num_of_tokens;
          // Selecting the initial number of tokens
        cout << "Please select a choice" << endl;
        cout << "1) Random number" << endl;
        cout << "2) Select a number" << endl;

        int user_input;
        cin >> user_input;

        if (user_input == 1) {
            num_of_tokens = getRandomNumber(10, 600);  // Random number between 10 and 600
        } else {
            cout << "Select a number: ";
            cin >> num_of_tokens;

            while (!isPerfectSquare(num_of_tokens)) {
                cout << "enter  the number : ";
                cin >> num_of_tokens;
            }
        }

        cout << "Starting number of coins: " << num_of_tokens << endl;

        int current_player = 1;
        // Ensure the entered number is a perfect square
        while (num_of_tokens > 0) {
            int player_turn;

            cout << "Player " << current_player << "'s turn, please select the number of tokens: ";
            cin >> player_turn;

            if (isPerfectSquare(player_turn) && player_turn <= num_of_tokens) {
                num_of_tokens -= player_turn;
                cout << "The remaining tokens are " << num_of_tokens << endl;

                if (num_of_tokens <= 0) {
                    cout << "Player " << current_player << " wins!" << endl;
                    break;
                }

                // Switch player
                current_player = (current_player == 1) ? 2 : 1;
            } else {
                cout << "Please select a valid choice." << endl;
            }
        }
        // Ask if the players want to play again
        string continue_game;
        cout << "Do you want to try again? (choose yes or no)" << endl;
        cin >> continue_game;

        if (continue_game != "yes") {
            break;
        }
    }

    return 0;
}