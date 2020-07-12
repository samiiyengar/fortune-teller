//
//  drawing.hpp
//  tarot
//
//  Created by Samyukta Iyengar on 7/11/20.
//  Copyright © 2020 Samyukta Iyengar. All rights reserved.
//

#ifndef drawing_hpp
#define drawing_hpp

#include <stdio.h>
#include <algorithm>
#include <cassert>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <time.h>

using namespace std;

// card struct
struct Card {
    string name;
    string uprightDescription;
    string reversedDescription;
    Card(string name_in, string uD, string rD) {
        name = name_in;
        uprightDescription = uD;
        reversedDescription = rD;
    }
};

class Game {
public:
    size_t generate_rand(size_t bound) {
        return rand() % bound;
    }
    
    void deal_cards() {
        size_t cards_dealt = 1;
        while (cards_dealt != 4) {
            bool duplicate = true;
            size_t index = 0;
            while (duplicate) {
                index = generate_rand(deck.size());
                if (find(rands.begin(), rands.end(), index) != rands.end()) {
                    continue;
                } else {
                    rands.push_back(index);
                    break;
                }
            }
            Card card = deck[index];
            cout << "Card " << cards_dealt << ": " << card.name;
            size_t upright = generate_rand(2);
            if (upright == 0) {
                cout << " upright" << endl;
                cout << "Represents " << card.uprightDescription << endl;
            } else {
                cout << " reversed" << endl;
                cout << "Represents " << card.reversedDescription << endl;
            }
            cards_dealt++;
        }
    }
private:
    vector<size_t> rands;
    vector<Card> deck = {
        {"The World", "fulfillment, harmony, completion", "incompletion, no closure"},
        {"Judgement", "reflection, reckoning, awakening", "lack of self awareness, doubt, self loathing"},
        {"The Sun", "joy, success, celebration, positivity", "negativity, depression, sadness"},
        {"The Moon", "unconscious, illusions, intuition", "confusion, fear, misinterpretation"},
        {"The Star", "hope, faith, rejuvenation", "faithlessness, discouragement, insecurity"},
        {"The Tower", "sudden upheaval, broken pride, disaster", "disaster avoided, delayed disaster, fear of suffering"},
        {"The Devil", "addiction, materialism, playfulness", "freedom, release, restoring control"},
        {"Temperance", "middle path, patience, finding meaning", "extremes, excess, lack of balance"},
        {"Death", "end of cycle, beginnings, change, metamorphosis", "fear of change, holding on, stagnation, decay"},
        {"The Hanged Man", "sacrifice, release, martyrdom", "stalling, needless sacrifice, fear of sacrifice"},
        {"Justice", "cause and effect, clarity, truth", "dishonesty, unaccountability, unfairness"},
        {"The Wheel of Fortune", "change, cycles, inevitable fate", "no control, clinging to control, bad luck"},
        {"The Hermit", "contemplation, search for truth, inner guidance", "loneliness, isolation, lost your way"},
        {"Strength", "inner strength, bravery, compassion, focus", "self doubt, weakness, insecurity"},
        {"The Chariot", "direction, control, willpower", "lack of control, lack of direction, aggression"},
        {"The Lovers", "partnerships, duality, union", "loss of balance, one-sidedness, disharmony"},
        {"The Hierophant", "tradition, conformity, morality, ethics", "rebellion, subversiveness, new approaches"},
        {"The Emperor", "authority, structure, control, fatherhood", "tyranny, rigidity, coldness"},
        {"The Empress", "motherhood, fertility, nature", "dependence, smothering, emptiness, nosiness"},
        {"The High Priestess", "intuitive, unconscious, inner voice", "lack of center, lost inner voice, repressed feelings"},
        {"The Magician", "willpower, desire, creation, manifestation", "trickery, illusions, out of touch"},
        {"The Fool", "innocence, new beginnings, free spirit", "recklessness, taken advantage of, inconsideration"}
    };
};

#endif /* drawing_hpp */
