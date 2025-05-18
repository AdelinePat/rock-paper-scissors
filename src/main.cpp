
#include "main.h"



int main(int argc, char const *argv[])
{
    auto choice{-1};
    auto random_value{-1};
    auto bot_score{0};
    auto user_score{0};
    auto number_turn{0};

    while (choice != 0) {
        number_turn++;
        choice = displayMenu();
        if (choice != 0) {
            choice--;
            random_value = getRandomNumber();
            calculateScore(choice, random_value, user_score, bot_score);
            displayChoice(choice, random_value);
            displayResult(user_score, bot_score, number_turn);
            choice++;
        }
    }
    cout<<"Merci d'avoir joué ! Bye Bye ..."<<endl;
    return 0;
}

/// @brief print the main menu
/// @return the choice from the menu
int displayMenu() {
    auto choice{0};
    cout<<"Veuillez choisir parmi ces possibilités :"<<endl;
    cout<<"0. Quitter"<<endl;
    cout<<"1. Pierre"<<endl;
    cout<<"2. Papier"<<endl;
    cout<<"3. Ciseaux"<<endl;
    cin>>choice;
    return choice;
}

void displayChoice (const int choice, const int random_value) {
    string user_string = setString(choice);
    string bot_string = setString(random_value);
    cout<<"Vous avez choisi "<<user_string<<endl;
    cout<<"Le bot a choisi "<<bot_string<<endl<<endl;
}

/// @brief Generate string "rock" "paper" "scissors" depending on the int choice made by user or bot
/// @param choice int
/// @return Rock Paper or Scissors
string setString(const int choice) {
    string final_string = "";
    if (choice == static_cast<int>(hand::rock)){
        final_string = "pierre";
    } else if (choice == static_cast<int>(hand::paper)) {
        final_string = "papier";
    } else {
        final_string = "ciseaux";
    }
    return final_string;
}

int getRandomNumber() {
    std::srand(time(nullptr)); //get the value to shuffle the random number
    auto random_value {std::rand()};
    return random_value%3;
}

/// @brief compare the choice and randomValue to increment user_score or bot_score
/// @param choice user_choice from menu
/// @param random_value value from getRandomNumber AKA bot choice
/// @param user_score 
/// @param bot_score 
void calculateScore(const int choice, const int random_value, int& user_score, int& bot_score) {
    switch (choice) {
        case static_cast<int>(hand::rock): // Rock
            if (random_value == static_cast<int>(hand::scissors)) {
                user_score++;     
            } else if (random_value == static_cast<int>(hand::paper)) {
                bot_score++;
            }
            break;
        case static_cast<int>(hand::paper): // Paper
            if (random_value == static_cast<int>(hand::rock)) {
                user_score++;     
            } else if (random_value == static_cast<int>(hand::scissors)) {
                bot_score++;
            }
            break;
        case static_cast<int>(hand::scissors): // Scissors
            if (random_value == static_cast<int>(hand::paper)) {
                user_score++;     
            } else if (random_value == static_cast<int>(hand::rock)) {
                bot_score++;
            }
            break;
    }
}