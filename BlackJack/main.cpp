#include <iostream>
#include <string>
#include <random>
#include <vector>

using namespace std;

int card() {
    // card function, randomly selects a number from 0 - 11
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(0, 11);
    int random_number = distribution(gen);
    return random_number;
}

vector<int> player() {
    // randomly selects two card values for the player
    vector<int> nums = {};
    int i = 1;
    
    do {
        int cardResult = card();
        nums.push_back(cardResult);
        i++;
    } while (i < 3);
    
    return nums;
}

vector<int> dealer() {
    // randomly selects two card values for the dealer
    vector<int> nums = {};
    int i = 1;
    
    do {
        int cardResult = card();
        nums.push_back(cardResult);
        i++;
    } while (i < 3);
    
    return nums;
}
void winner();
void run_game();

int main() {
    char startGame;
    int play_counter = 0;
    vector<int> player_hand = player();
    vector<int> dealer_hand = dealer();

    cout << "Welcome to BlackJack!" << endl;

    cout << "Press 'Enter' to start the game." << endl;
    cin.get(startGame);

    while (play_counter < 2) {
        if (startGame == '\n') {
            cout << "Player's hand: ";
            for (int card : player_hand) {
                cout << card << " ";
            }
            cout << endl;

            cout << "Dealer's hand: ";
            for (int card : dealer_hand) {
                cout << card << " ";
            }
            cout << endl;

            play_counter++;
        }
    }
    return 0;
}
