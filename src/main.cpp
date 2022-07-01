#include <iostream>
#include <conio.h>
#include <windows.h>
#include "../include/menu.hpp"
#include "../include/object.hpp"
#include "../include/map.hpp"

using namespace std;

// To set color console text
void setColor(unsigned short color)
{
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon, color);
}

// Main function
int main()
{
    // Var declaration
    int playerInput;
    int mapIndex = 0;

    // Definie player struct
    Hero mainPlayer;
    mainPlayer.gold = 0;

    // Play main bgm
    PlaySound(TEXT("../audio/intro_bgm.wav"), NULL, SND_LOOP | SND_ASYNC);

    // Check input from player, wanna start or exit game
    int start = openMenu();
    if (start == 0)
    {
        cout << textTab + "Game exitted...\n";
        getch();
        return 0;
    }

    // Input player name
    inputPlayerDetails(mainPlayer);

    // Stop main bgm
    PlaySound(NULL, NULL, 0);

    // Game loop
    while(true)
    {
        // Print map, player info, etc
        printInterface(mainPlayer, mapIndex);

        // Check player position
        checkPlayerPosition(mapIndex, mainPlayer);

        // Input and check player movement
        inputPlayerKey(&playerInput, mapIndex);
        if (playerInput == KEY_Y || playerInput == KEY_Y_CAPS)
        {
            break;
        }
        else if (playerInput == KEY_N || playerInput == KEY_N_CAPS)
        {
            continue;
        }

    }

    // Game end
    cout << textTab + "Thank you for playing" << endl;
    cout << textTab;
    system("pause");
    return 0;
}