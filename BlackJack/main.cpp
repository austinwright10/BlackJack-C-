#include <iostream>
#include <string>
#include <random>
#include <vector>

using namespace std;

int card() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(0, 21);
    int random_number = distribution(gen);
    return random_number;
}

vector<int> player() {
    vector<int> nums = {};
    int i = 1;
    
    do {
        int cardResult = card();
        nums.push_back(cardResult);
        i++;
    } while (i < 3);
    

    
    return nums;
}
void dealer();
void winner();
void run_game();

int main() {
    
    char startGame;
    int cardResult = card();
    vector<int> player_hand = player();
    
    cout << "Welcome to BlackJack!" << endl;
    
    cout << "Press 'Enter' to start the game." << endl;
    cin.get(startGame);
    
    if (startGame == '\n') {
        cout << "Card generated: " << cardResult << endl;
        cout << "Player's hand generated " << endl;
        for (int card: player_hand) {
            cout << card << " ";
        }
        cout << endl;
    }
    return 0;
}
