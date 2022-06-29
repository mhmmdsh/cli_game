using namespace std;

// Define input key
#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100
#define KEY_Y 121
#define KEY_N 110
#define KEY_W_CAPS 87
#define KEY_A_CAPS 65
#define KEY_S_CAPS 83
#define KEY_D_CAPS 68
#define KEY_Y_CAPS 89
#define KEY_N_CAPS 78
#define KEY_ESC 27
#define KEY_ENTER 13
#define KEY_SPACE 32

// Global variable
const int mapX = 61;
const int mapY = 30;
int playerX = 1;
int playerY = 18;

struct Map
{
    string mapName;
    char mapContain[mapY][mapX];
};

/* Map legend
** In town                                 * In dungeon
*- @ = Player                              - 7 = Regular monster
*- = = Wall                                - 8 = Commander monster
*- _ = Soil                                - 9 = Boss monster
*- * = Grass                               -
*- # = Bush                                -
*- 8 = Water                               -
*- 1 = Sidewall / Tree Trunk               -
*- 0 = House                               -
*- O = Stone                               -
*- + = Windows                             -
*- H = Door                                -
*- : = Fence                               -
*- | = Bridge
*- ^ = Roof
*- T = Tree Leave
*/

// Map list
Map listMap[] = {
    {
        "Town",
        {
            "============================    ============================",
            "=*****^^^^^******TTT*******#____#************^^^^^^^^******=",
            "=***^^^^^`^^^***TTTTT******#____#*****&****^^^^`^^^`^^^^***=",
            "=*^^^^^`^^^^^^****1******###____###__&&__^^^^^`^^^^^`^^^^^*=",
            "=**100^^^^^^^^^^**1****###________###*****100^^^^^^^^^001**=",
            "=**10OO100BS001******###____________###&**10O01store10O01**=",
            "=**100010WOOO01****###_____[[[]]]_____###*100010IOO010001**=",
            "=******10WOOO01****#____[[[[8888]]]]____#*****10IOO01******=",
            "=#####*&______&*####___[[8888888888]]___####**&_____&*#####=",
            "=______________________[888888888888]______________________=",
            "=______________________[888888888888]______________________=",
            "=___######TTTT######___[888888888888]___######TTTT######___=",
            "=___#****TTTTTT****#___[888888888888]___#****TTTTTT****#___=",
            "=___#***___11___***#___[888888888888]___#***___11___***#___=",
            "=_________&11&_________[888888888888]_________&11&_________=",
            "=___#***________***#___[888888888888]___#***________***#___=",
            "=___#******__******#___[888888888888]___#******__******#___=",
            "=___#######__#######___[888888888888]___#######__#######___=",
            "=______________________||||||||||||||______________________=",
            "=______________________||||||||||||||______________________=",
            "=__*****^^^^^^^^*****__[888888888888]__*****^^^^^^^^*****__=",
            "=__*##^^^^^^^^^^^^##*__[888888888888]__*##^^^^^^^^^^^^##*__=",
            "=__*^^^^^^^^^^^^^^^^*__[888888888888]__*^^^^^^^^^^^^^^^^*__=",
            "=__*#10000000000001#*__[888888888888]__*#10000000000001#*__=",
            "=__*#10OO00HH00OO01#*__[888888888888]__*#10OO00HH00OO01#*__=",
            "=__*#100000HH000001#*__[888888888888]__*#100000HH000001#*__=",
            "=__*#######__#######*__[888888888888]__*#######__#######*__=",
            "=__********__********__[888888888888]__********__********__=",
            "=______________________[888888888888]______________________=",
            "============================================================"
        }
    },
    {
        "Jungle",
        {
            "====    ============================================    ====",
            "=                                                          =",
            "=                                                          =",
            "=                                                          =",
            "=                                                          =",
            "=                                                          =",
            "=                                                          =",
            "=                                                          =",
            "=                                                          =",
            "=                                                          =",
            "=                                                          =",
            "=                                                          =",
            "=8888888888                                                =",
            "=8888888888888888888                 &|||||&           8888=",
            "=888888888888888888888888888888888   |||||      88888888888=",
            "=88888888888888888888888888888888888|||||888888888888888888=",
            "=[[[[888888888888888888888888888888|||||8888888888888888888=",
            "=   [[[[     [[8888888888888888888|||||888888888888888888  =",
            "=                  [[[[[     8888|||||888888888888         =",
            "=                               |||||                      =",
            "=                             &|||||&                      =",
            "=       TTT               #_______#                        =",
            "=     TTTTTTT            ______                            =",
            "=        1            _________                            =",
            "=        1               __________                        =",
            "=                            _______                       =",
            "=                               ______                     =",
            "=                             _____                        =",
            "=                           _____                          =",
            "============================    ============================"
        }
    },
};

// To set color console text
void setColor(unsigned short color)
{
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon, color);
}

// Print interface (map, player info, etc)
void printInterface(Hero &playerDetails, int &mapIndex)
{
    if (playerY < 0)
    {
        mapIndex++;
        playerY = mapY - 1;
    }
    else if (playerY > mapY - 1)
    {
        mapIndex--;
        playerY = 0;
    }

    system("cls");

    // Print map and player position
    for (int y = 0; y < mapY; y++)
    {
        cout << mapTab;

        // Print map
        for (int x = 0; x < mapX; x++)
        {
            char index = listMap[mapIndex].mapContain[y][x];

            if (index == '1' || index == '|' || index == '[' || index == ']')
            {
                setColor(6);
            }
            else if (index == '^' || index == 'T')
            {
                setColor(12);
            }
            else if (index == '_' || index == '0')
            {
                setColor(14);
            }
            else if (index == 'I' || index == 'W')
            {
                setColor(13);
            }
            else if (index == '`' || index == 'H')
            {
                setColor(4);
            }
            else if (index == '&')
            {
                setColor(8);
            }
            else if (index == '*')
            {
                setColor(10);
            }
            else if (index == '#')
            {
                setColor(2);
            }
            else if (index == 'O')
            {
                setColor(3);
            }
            else if (index == '8')
            {
                setColor(9);
            }
            else
            {
                setColor(7);
            }

            // Print player position
            if (playerY == y && playerX == x)
            {
                setColor(11);
                cout << '@';
            }
            else
            {
                cout << index;
            }
        }

        switch (y)
        {
        case 0:
            cout << "================================";
            break;
        case 2:
            cout << "\tPlayer name: " << playerDetails.playerName;
            break;
        case 4:
            cout << "\tPostion Y: " << playerY;
            break;
        case 6:
            cout << "\tPostion X: " << playerX;
            break;
        }
    }
}

// Check player movement UP
void checkUpPlayerMovement(int *checkInput, int &mapIndex)
{
    char checkUp = listMap[mapIndex].mapContain[playerY - 1][playerX];
    if (checkUp == 'O' || checkUp == '0' || checkUp == '1' || checkUp == '8' || checkUp == '=')
    {
        *checkInput = 0;
    }
    else if (checkUp == '#' || checkUp == '&' || checkUp == '^' || checkUp == '[' || checkUp == ']')
    {
        *checkInput = 0;
    }
    else
    {
        *checkInput = 1;
    }
}

// Check player movement Down
void checkDownPlayerMovement(int *checkInput, int &mapIndex)
{
    char checkDown = listMap[mapIndex].mapContain[playerY + 1][playerX];
    if (checkDown == 'O' || checkDown == '0' || checkDown == '1' || checkDown == '8' || checkDown == '=')
    {
        *checkInput = 0;
    }
    else if (checkDown == '#' || checkDown == '&' || checkDown == '^' || checkDown == '[' || checkDown == ']')
    {
        *checkInput = 0;
    }
    else
    {
        *checkInput = 1;
    }
}

// Check player movement Left
void checkLeftPlayerMovement(int *checkInput, int &mapIndex)
{
    char checkLeft = listMap[mapIndex].mapContain[playerY][playerX - 1];
    if (checkLeft == 'O' || checkLeft == '0' || checkLeft == '1' || checkLeft == '8' || checkLeft == '=')
    {
        *checkInput = 0;
    }
    else if (checkLeft == '#' || checkLeft == '&' || checkLeft == '^' || checkLeft == '[' || checkLeft == ']')
    {
        *checkInput = 0;
    }
    else
    {
        *checkInput = 1;
    }
}

// Check player movement Right
void checkRightPlayerMovement(int *checkInput, int &mapIndex)
{
    char checkRight = listMap[mapIndex].mapContain[playerY][playerX + 1];
    if (checkRight == 'O' || checkRight == '0' || checkRight == '1' || checkRight == '8' || checkRight == '=')
    {
        *checkInput = 0;
    }
    else if (checkRight == '#' || checkRight == '&' || checkRight == '^' || checkRight == '[' || checkRight == ']')
    {
        *checkInput = 0;
    }
    else
    {
        *checkInput = 1;
    }
}

// Check player movement input
void inputPlayerMovement(int *inputMovement, int &mapIndex)
{
    // Player input
    int checkInput = 1;
    *inputMovement = getch();

    // Move player
    if (*inputMovement == KEY_W || *inputMovement == KEY_W_CAPS)
    {
        checkUpPlayerMovement(&checkInput, mapIndex);
        if (checkInput == 1)
        {
            playerY--;
        }
    }
    else if (*inputMovement == KEY_S || *inputMovement == KEY_S_CAPS)
    {
        checkDownPlayerMovement(&checkInput, mapIndex);
        if (checkInput == 1)
        {
            playerY++;
        }
    }
    else if (*inputMovement == KEY_A || *inputMovement == KEY_A_CAPS)
    {
        checkLeftPlayerMovement(&checkInput, mapIndex);
        if (checkInput == 1)
        {
            playerX--;
        }
    }
    else if (*inputMovement == KEY_D || *inputMovement == KEY_D_CAPS)
    {
        checkRightPlayerMovement(&checkInput, mapIndex);
        if (checkInput == 1)
        {
            playerX++;
        }            
    }
    else if (*inputMovement == KEY_ESC)
    {
    exitInput:
        system("cls");
        cout << textTab + "Are you sure want to exit?" << endl;
        cout << textTab + "input (y/n): ";
        *inputMovement = getch();

        if (*inputMovement == KEY_N || *inputMovement == KEY_N_CAPS)
        {
            cout << "\n" + textTab + "Return to the game..\n";
        }
        else if (*inputMovement == KEY_Y || *inputMovement == KEY_Y_CAPS)
        {
            cout << "\n" + textTab + "Game will exit..\n";
        }
        else
        {
            cout << "\n" + textTab + "Input invalid..\n";
            goto exitInput;
        }

        Sleep(2000);
    }
}
