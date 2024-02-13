#include <iostream>
#include <string>
#include <random>
#include <vector>

using namespace std;

char card() {
    // card function, randomly selects a number from 0 - 11
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(1, 11);
    auto random_number = distribution(gen);
    if (random_number == 1) {
        return 'A';
    }
    else if (random_number == 10) {
        std::uniform_int_distribution<int> distribution(0, 2);
        auto face_random = distribution(gen);
        if (face_random == 0) {
            return 'J';
        }
        else if (face_random == 1) {
            return 'Q';
        }
        else {
            return 'K';
        }
    }
    return static_cast<char>(random_number + '0');
}

vector<char> player() {
    // randomly selects two card values for the player
    vector<char> cards;
    cards.push_back(card());
    cards.push_back(card());
    cards.push_back(card());
    return cards;
    }

vector<char> dealer() {
    // randomly selects two card values for the dealer
    vector<char> cards;
    cards.push_back(card());
    cards.push_back(card());
    cards.push_back(card());
    return cards;
    }
int dealer_total() {
    int total = 0;
    vector<char> dealer_hand = dealer();
    
    for (char card : dealer_hand) {
            // Convert card character to numerical value and add to total
            switch (card) {
                case '2': total += 2; break;
                case '3': total += 3; break;
                case '4': total += 4; break;
                case '5': total += 5; break;
                case '6': total += 6; break;
                case '7': total += 7; break;
                case '8': total += 8; break;
                case '9': total += 9; break;
                case 'J':
                case 'Q':
                case 'K': total += 10; break;
                case 'A': total += 11; break; // For simplicity, assuming Ace is always 11
                default: /* handle invalid card */ break;
            }
        }
    return total;
}
int player_total();
void winner();

int main() {
    char startGame;
    int play_counter = 0;
    vector<char> player_hand = player();
    vector<char> dealer_hand = dealer();

    cout << "Welcome to BlackJack!" << endl;

    cout << "Press 'Enter' to start the game." << endl;
    cin.get(startGame);

    while (play_counter == 0) {
        if (startGame == '\n') {
            cout << "Player's hand: ";
            for (int i = 0; i < 2; ++i) {
                cout << player_hand[i] << " ";
            }
            cout << endl;
            cout << endl;

            cout << "Dealer's hand: ";
            for (int i = 0; i < 2; ++i) {
                if (i == 0) {
                    cout << '?' << " ";
                } else {
                    cout << dealer_hand[i] << endl;
                }
            }
            cout << endl;
            cout << "Dealer's points: " << dealer_total() << endl;
//            cout << "Player's points: " << player_total() << endl;
            string player_hit_pass;
            cout << "Would you like to hit or pass?" << endl;
            cin >> player_hit_pass;
            if (player_hit_pass != "pass" and player_hit_pass != "hit") {
                cout << "Sorry invalid answer, try again" << endl;
                cin >> player_hit_pass;
            }
            if (player_hit_pass == "hit") {
                play_counter = 1;
                cout << endl;
                }
            }
        }
    while (play_counter == 1) {
        for (int i = 0; i < player_hand.size(); ++i) {
            cout << player_hand[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
