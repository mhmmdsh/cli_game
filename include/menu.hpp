using namespace std;

const string lineTab = "\n\n\t\t\t\t\t\t";
const string textTab = "\n\t\t\t\t\t\t";
const string mapTab = "\n\t\t\t";

// Game title
void gameTitle()
{
    cout << (R"(




     /$$$$$$$  /$$   /$$ /$$   /$$  /$$$$$$  /$$$$$$$$  /$$$$$$  /$$   /$$       /$$$$$$$  /$$   /$$  /$$$$$$  /$$   /$$
    | $$__  $$| $$  | $$| $$$ | $$ /$$__  $$| $$_____/ /$$__  $$| $$$ | $$      | $$__  $$| $$  | $$ /$$__  $$| $$  | $$
    | $$  \ $$| $$  | $$| $$$$| $$| $$  \__/| $$      | $$  \ $$| $$$$| $$      | $$  \ $$| $$  | $$| $$  \__/| $$  | $$
    | $$  | $$| $$  | $$| $$ $$ $$| $$ /$$$$| $$$$$   | $$  | $$| $$ $$ $$      | $$$$$$$/| $$  | $$|  $$$$$$ | $$$$$$$$
    | $$  | $$| $$  | $$| $$  $$$$| $$|_  $$| $$__/   | $$  | $$| $$  $$$$      | $$__  $$| $$  | $$ \____  $$| $$__  $$
    | $$  | $$| $$  | $$| $$\  $$$| $$  \ $$| $$      | $$  | $$| $$\  $$$      | $$  \ $$| $$  | $$ /$$  \ $$| $$  | $$
    | $$$$$$$/|  $$$$$$/| $$ \  $$|  $$$$$$/| $$$$$$$$|  $$$$$$/| $$ \  $$      | $$  | $$|  $$$$$$/|  $$$$$$/| $$  | $$
    |_______/  \______/ |__/  \__/ \______/ |________/ \______/ |__/  \__/      |__/  |__/ \______/  \______/ |__/  |__/





    )");
}

// Before main menu
void beforeMenu()
{
    gameTitle();
    cout << textTab + textTab + "PRESS ANY KEY TO CONTINUE...";
}

// Main menu when in start choice
void mainStart()
{
    gameTitle();
    cout << R"(      


                                               __     ___ _            _       __
                                               \ \   / __| |_ __ _ _ _| |_    / /
                                                > >  \__ \  _/ _` | '_|  _|  < < 
                                               /_/   |___/\__\__,_|_|  \__|   \_\)";
    
    cout << (R"(

                                                                  _ _   
                                                          _____ _(_) |_ 
                                                         / -_) \ / |  _|
                                                         \___/_\_\_|\__|
    )");                               
    
}

// Main menu when in exit choice
void mainExit()
{
    gameTitle();
    cout << (R"(          


                                                      ___ _            _      
                                                     / __| |_ __ _ _ _| |_    
                                                     \__ \  _/ _` | '_|  _|  
                                                     |___/\__\__,_|_|  \__|
    )");

    cout << R"(               
                                               __                 _ _          __
                                               \ \        _____ _(_) |_       / /
                                                > >      / -_) \ / |  _|     < <
                                               /_/       \___/_\_\_|\__|      \_\)";  
}

// Open the menu
int openMenu()
{
    // Input var declaration
    int input;

    // Showing before main menu
    beforeMenu();
    getch();

    // Loop the menu
    while (true)
    {
        // Clearscreen
        system("cls");

        // Showing main menu in start choice first
        mainStart();
        input = getch();

        // Check for input
        if (input == 80 || input == 115)
        {   
            // Show main menu in exit choice
            mainExit: 
            system("cls");
            mainExit();
            input = getch();

            // Check for input
            if (input == 72 || input == 119)
            {
                continue;
            }
            else if (input == 13)
            {
                return 0;
                break;
            }
            else
            {
                goto mainExit;
            } 
        }
        else if (input == 13)
        {
            return 1;
            break;
        }
    }
}