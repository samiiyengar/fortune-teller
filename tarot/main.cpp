//
//  main.cpp
//  tarot
//
//  Created by Samyukta Iyengar on 7/11/20.
//  Copyright © 2020 Samyukta Iyengar. All rights reserved.
//

#include <iostream>
#include "drawing.hpp"

int main(int argc, const char * argv[]) {
    srand(static_cast<unsigned int>(time(NULL)));
    cout << "What is your name?" << endl;
    string name;
    cin >> name;
    cout << name << ", here is your fortune: " << endl; 
    Game g;
    g.deal_cards(); 
}
