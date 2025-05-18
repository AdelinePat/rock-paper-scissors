#ifndef __MAIN_H__
#define __MAIN_H__
#include <iostream>
#include <string>
#include <time.h>
#define str_paper "Papier"
#define str_rock "Pierre"
#define str_scissors "Ciseaux"

// creating my aliases
using std::cout;
using std::endl;
using std::cin;
using std::string;

enum class hand {
    rock,
    paper,
    scissors
};

int displayMenu();
void displayChoice(const hand choice, const hand random_value);
inline void displayResult(const int user_score, const int bot_score, int number_turn) {
    cout<<"Score joueur : "<<user_score<<"/"<<number_turn<<endl;
    cout<<"Score bot : "<<bot_score<<"/"<<number_turn<<endl<<endl;
}
hand getRandomNumber();
void calculateScore(const hand choice, const hand random_value, int& user_score, int& bot_score);
string setString(const hand choice);
#endif