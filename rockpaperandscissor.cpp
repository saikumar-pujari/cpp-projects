#include <iostream>
#include <string>
#include <cstdlib> //for rand() to genrate random function
#include <ctime>
using namespace std;

int main()
{
    string player;
    string oppenent;
    int playerscore = 0;
    int oppenentscore = 0;
    string rps[] = {"rock", "paper", "scissor"};
    srand((unsigned int)time(NULL));
    while (true)
    {
        cout << "enter rock, paper or scissor: ";
        getline(cin, player);
        if (player != "rock" && player != "paper" && player != "scissor")
        {
            break;
        }
        oppenent = rps[rand() % 3];                                                     //its genrates a random function and it gets divided by 3 ans 1 is for rock,2 for paper and 3 for scissor
        cout << "oppenent chooses: " << oppenent << endl;
        if (player == oppenent)
        {
            cout<<"its a tie"<<endl;
          //  playerscore++;
           // oppenentscore++;
        }
        else if (player == "rock")
        {
            if (oppenent == "scissor")
                playerscore++;
            else if (oppenent == "paper")
                oppenentscore++;
        }
        else if (player == "paper")
        {
            if (oppenent == "rock")
                playerscore++;
            else if (oppenent == "scissor")
                oppenentscore++;
        }
        else if (player == "scissor")
        {
            if (oppenent == "paper")
                playerscore++;
            else if (oppenent == "rock")
                oppenentscore++;
        }
        cout << "player: " << playerscore << " oppenent: " << oppenentscore << endl;
    }
    cout << "player: " << playerscore << " oppenent: " << oppenentscore << endl;
    if (playerscore > oppenentscore)
    {
        cout << "player win";
    }
    else if (oppenentscore > playerscore)
    {
        cout << "oppenent wins";
    }
    else
    {
        cout << "TIE";
    }

    return 0;
}