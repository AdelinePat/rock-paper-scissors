
#include "main.hpp"

int main(int argc, char const *argv[])
{
    std::setlocale(LC_ALL, ".utf8");
    int choice{0};
    hand random_value{hand::paper};
    int bot_score{0};
    int user_score{0};
    int number_turn{0};

    do {
        number_turn++;
        choice = displayMenu();
        if (choice < 0 || choice > 3) {
            cout<<"Entrée invalide, veuillez recommencer !"<<endl<<endl;
            continue;
        } else if (choice != 0) {
            random_value = getRandomNumber();
            calculateScore(static_cast<hand>(choice-1), random_value, user_score, bot_score);
            displayChoice(static_cast<hand>(choice-1), random_value);
            displayResult(user_score, bot_score, number_turn);
        }
        
    } while (choice != 0);
    cout<<"Merci d'avoir joué ! Bye Bye ..."<<endl;
    return 0;
}

/// @brief print the main menu
/// @return the choice from the menu
int displayMenu() {
    auto choice{0};
    cout<<"Veuillez choisir parmi ces possibilités :"<<endl;
    cout<<"0. Quitter"<<endl;
    cout<<"1. "<<str_rock<<endl;
    cout<<"2. "<<str_paper<<endl;
    cout<<"3. "<<str_scissors<<endl;
    cin>>choice;
    return choice;
}

void displayChoice (const hand choice, const hand random_value) {
    string user_string = setString(choice);
    string bot_string = setString(random_value);
    cout<<"Vous avez choisi "<<user_string<<endl;
    cout<<"Le bot a choisi "<<bot_string<<endl<<endl;
}

/// @brief Generate string "rock" "paper" "scissors" depending on the int choice made by user or bot
/// @param choice int
/// @return Rock Paper or Scissors
string setString(const hand choice) {
    string final_string = "";
    if (choice == hand::rock){
        final_string = str_rock;
    } else if (choice == hand::paper) {
        final_string = str_paper;
    } else {
        final_string = str_scissors;
    }
    return final_string;
}

hand getRandomNumber() {
    std::srand(time(nullptr)); //get the value to shuffle the random number
    auto random_value {std::rand()};
    return static_cast<hand>(random_value%3);
}

/// @brief compare the choice and randomValue to increment user_score or bot_score
/// @param choice user_choice from menu cast into hand
/// @param random_value value from getRandomNumber AKA bot choice
/// @param user_score 
/// @param bot_score 
void calculateScore(const hand choice, const hand random_value, int& user_score, int& bot_score) {
    switch (choice) {
        case hand::rock:
            if (random_value == hand::scissors) {
                user_score++;     
            } else if (random_value == hand::paper) {
                bot_score++;
            }
            break;
        case hand::paper:
            if (random_value == hand::rock) {
                user_score++;     
            } else if (random_value == hand::scissors) {
                bot_score++;
            }
            break;
        case hand::scissors:
            if (random_value == hand::paper) {
                user_score++;     
            } else if (random_value == hand::rock) {
                bot_score++;
            }
            break;
    }
}