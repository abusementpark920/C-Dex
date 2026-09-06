// A mood check & motivation generator!
// Giving the user 5 different moods to choose from!
// Based on the mood, presenting a short motivating message
// Handled invalid input and basic capitalization differences

#include <iostream>
#include <string>

using namespace std;

int main(){
    string userName{}; //To be displayed later in the statements
    
    cout << "Enter your name: ";
    cin >> userName;


    cout << "\n\n"; //Used this to get space in terminal (readability!)

    cout << "How are you feeling today, "
    << userName  << "!" << '\n'
    << "Are you: Sad, Happy, Angry, Sleepy or Excited, " << userName << "?: "; // Asking mood to the user

    string userMood{}; //Stores mood of the user
    cin >> userMood; 

    if (userMood == "Sad" or userMood == "sad"){
          cout << "Oh! " << userName << ", it's okay to not be okay sometimes. Good things take time! <3";
    }

    else if (userMood == "Happy" or userMood == "happy"){
        cout << "Yay! "<< userName << ", just know great things are about to find its way towards you!! keep smiling :3";
    }

    else if (userMood == "Sleepy" or userMood == "sleepy"){
        cout << "I see! "<< userName << ", You should give your body a rest. Keep the device aside and sleep! : P";
    }

    else if (userMood == "Angry" or userMood == "angry"){
        cout << "Hey.. " << userName << " You need to calm down, Think before you act!";
    }

    else if (userMood == "Excited" or userMood == "excited"){
        cout << "Hmmmm... I wonder what makes you excited, " << userName;
    }

    else {
       cout << "That isn't a mood, cmon!";
}

return 0;
}