//
//  main.cpp
//  BlackJack
//
//  Created by Austin Wright on 1/21/24.
//

#include <iostream>
#include <string>
using namespace std;

void player();
void dealer();
void winner();
void run_game();


int main() {
    
    char startGame;
    
    cout << "Welcome to BlackJack!" << endl;
    
    cout << "Press 'Enter' to start the game." << endl;
    cin.get(startGame);
    
    if (startGame == '\n') {
        cout << "worked" << endl;
    }
    return 0;
}
