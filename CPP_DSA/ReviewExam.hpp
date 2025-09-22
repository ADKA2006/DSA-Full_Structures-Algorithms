// Simulate a coin with denomination int. Implement a stack of coins only priority 
#ifndef ReviewExam_hpp
#define ReviewExam_hpp
#include "PriorityQueue.hpp"
#include <iostream>
using namespace std;

namespace Demo {
    class ReviewExam {
        public:
        static void run() {
            struct Coin{
                int denom_value;
                int priority;
            };

            Coin coin;

            cout << "Enter the maximum number of coins in the stack possible: ";
            int maxNumCoins;
            cin >> maxNumCoins;
            if (maxNumCoins <= 0) {
                cout << "Invalid maximum number of coins. Exiting." << endl;
                return;
            }

            PriorityQueue<Coin> pq(maxNumCoins);   // API already availble in the Priority Queue

            for (int i = 0; i < maxNumCoins; i++) {
                cout << "Enter the coin denomination" << endl;
                cin >> coin.denom_value;
                coin.priority = i;
                if (pq.insert(coin)) {
                    cout << "Coin with denomination " << coin.denom_value << " and priority " << coin.priority << " added successfully." << endl;
                } else {
                    cout << "Failed to add coin. Priority Queue is full." << endl;
                }
            }
            // getting the coin with the max value
            cout << "\nExample of removing from the priority queue:" << endl;
            Coin removedCoin;
            while (pq.getMax(removedCoin)) {
                cout << "Removed coin: " << removedCoin.denom_value << " with priority " << removedCoin.priority << endl;
            }
            cout << "No more coins to remove." << endl;

        }
    };
}

#endif