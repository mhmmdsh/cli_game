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
int enemies = 0;

struct Map
{
    string mapName;
    char mapContain[mapY][mapX];
};

/* Map legend
** In town                                 * In dungeon
*- @ = Player                              - R = Regular monster
*- = = Wall                                - C = Commander monster
*- _ = Soil                                - B = Boss monster
*- * = Grass                               - $ = Treasure/gold
*- # = Bush                                - V = Fire
*- 8 = Water                               
*- 1 = Sidewall / Tree Trunk               
*- 0 = House                               
*- O = Stone                               
*- + = Windows                             
*- H = Door                                
*- [ = Fence                               
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
            "=**10OO100bs001******###____________###&**10O01store10O01**=",
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
            "============================================================",
            "=&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&=",
            "=&&&&&&&&&&&&&&&&&$$$&&&V__C___C__V&&$$$$&&&&&&&&&&&&&&&&&&=",
            "=&&&$$$&&R___R&&&_____&&_R___B___R_&&____&&&R___R&&&$$$&&&&=",
            "=&&_____&__C__&&_____&&&___C___C___&&&____&&__C__&&&_____&&=",
            "=&______&R___R&&__V___&&_R___R___R_&&__V__&&R___R&______&&&=",
            "=&______V|||||V&&____&&V|||||||||||V&____&&V|||||V______$&&=",
            "=&&______1___11111__1111111_____1111&&__&&&11___1_______&&&=",
            "=&&&_____1_______________11_______1111__111_____1________&&=",
            "=&&___V___________________________________________________&=",
            "=&_________111111111111______________________111_____V____&=",
            "=[[[[[]]TT__________$$1111111111111111_____111&&&&_______&&=",
            "=8888888888______&##T************&&&&1_____1&&&&&$_______$&=",
            "=8888888888888888888_____________#&&&&|||||&****###____8888=",
            "=888888888888888888888888888888888[[[|||||]]]__&88888888888=",
            "=88888888888888888888888888888888888|||||888888888888888888=",
            "=[[[]888888888888888888888888888888|||||8888888888888888888=",
            "=****[[]&____[]8888888888888888888|||||8888888888TTTT8888&&=",
            "=**************____[[[[]____&8888|||||8888888888TTTTTT___**=",
            "=****************************__&|||||[___]]]___TTTTTTTT_***=",
            "=*****______******************&|||||&********_____11_____**=",
            "=****___TTT___***********#####_______#******______11______*=",
            "=***__TTTTTTT__******#####__________##*******____&11_____**=",
            "=**_____111_____****##_________######*********__________***=",
            "=***____111&___*********_________####**********________****=",
            "=****____&____**********#####_______##*********************=",
            "=*****_______***************###_______*********************=",
            "=*************************####_____##**********************=",
            "=*************************#______###***********************=",
            "============================    ============================"
        }
    },
};

Map mainMap[] = {listMap[0], listMap[1]};

// To set color console text
void setColor(unsigned short);

// Check player movement
void checkPlayerMovement(int *checkInput, int &mapIndex, char &inputDirection)
{
    char check;

    if (inputDirection == 'W')
    {
        check = listMap[mapIndex].mapContain[playerY - 1][playerX];
    }
    else if (inputDirection == 'S')
    {
        check = listMap[mapIndex].mapContain[playerY + 1][playerX];
    }
    else if (inputDirection == 'A')
    {
        check = listMap[mapIndex].mapContain[playerY][playerX - 1];
    }
    else if (inputDirection == 'D')
    {
        check = listMap[mapIndex].mapContain[playerY][playerX + 1];
    }
    
    if (check == 'O' || check == '0' || check == '1' || check == '8' || check == '=')
    {
        *checkInput = 0;
    }
    else if (check == '#' || check == '&' || check == '^' || check == '[' || check == ']')
    {
        *checkInput = 0;
    }
}

// Player movement input
void inputPlayerKey(int *inputMovement, int &mapIndex)
{
    // Player input
    int checkInput = 1;
    char inputDirection;
    *inputMovement = getch();

    // Move player
    if (*inputMovement == KEY_W || *inputMovement == KEY_W_CAPS)
    {
        inputDirection = 'W';
        checkPlayerMovement(&checkInput, mapIndex, inputDirection);
        if (checkInput == 1)
        {
            playerY--;
        }
    }
    else if (*inputMovement == KEY_S || *inputMovement == KEY_S_CAPS)
    {
        inputDirection = 'S';
        checkPlayerMovement(&checkInput, mapIndex, inputDirection);
        if (checkInput == 1)
        {
            playerY++;
        }
    }
    else if (*inputMovement == KEY_A || *inputMovement == KEY_A_CAPS)
    {
        inputDirection = 'A';
        checkPlayerMovement(&checkInput, mapIndex, inputDirection);
        if (checkInput == 1)
        {
            playerX--;
        }
    }
    else if (*inputMovement == KEY_D || *inputMovement == KEY_D_CAPS)
    {
        inputDirection = 'D';
        checkPlayerMovement(&checkInput, mapIndex, inputDirection);
        if (checkInput == 1)
        {
            playerX++;
        }            
    }
    else if (*inputMovement == KEY_ESC)
    {
    escInput:
        system("cls");
        cout << textTab + "Press (ESC) to return the game" << endl;
        cout << textTab + "Press (SPACE) to reset the map" << endl;
        cout << textTab + "Press (ENTER) to exit the game" << endl;
        *inputMovement = getch();

        if (*inputMovement == KEY_SPACE)
        {
            mainMap[0] = listMap[0];
            mainMap[1] = listMap[1];
            playerX = 1;
            playerY = 18;
            mapIndex = 0;

            cout << "\n" + textTab + "Please wait, resetting the map..\n";
        }
        else if (*inputMovement == KEY_ESC)
        {
            backToTheGame:
            cout << "\n" + textTab + "Return to the game..\n";
        }
        else if (*inputMovement == KEY_ENTER)
        {
            cout << "\n" + textTab + "Are you sure want to exit? (Y/N)\n";
            *inputMovement = getch();

            if (*inputMovement == KEY_N)
            {
                goto backToTheGame;
            }
            else if (*inputMovement == KEY_Y || *inputMovement == KEY_Y_CAPS)
            {
                cout << "\n" + textTab + "Game will exit..\n";
            }
            else
            {
                cout << "\n" + textTab + "Input invalid..\n";
                goto escInput;
            }
        }
        else
        {
            cout << "\n" + textTab + "Input invalid..\n";
            goto escInput;
        }

        Sleep(2000);
    }
}

// Check player position
void checkPlayerPosition(int &mapIndex, Hero &playerDetails)
{    
    char mapCheck = mainMap[mapIndex].mapContain[playerY][playerX];

    if (mapCheck == 'R' || mapCheck == 'C' || mapCheck == 'B')
    {
        monsterBattle(mapCheck, playerDetails);
        mainMap[mapIndex].mapContain[playerY][playerX] = '_';
        enemies--;
    }
    else if (mapCheck == '$')
    {
        srand(time(NULL));
        int goldRandom = rand() % 500 + 1;
        playerDetails.gold += goldRandom;
        mainMap[mapIndex].mapContain[playerY][playerX] = '_';
    }
}

// Print player info
void printPlayerInfo(Hero &playerDetails, int &mapIndex, int iterator)
{
    switch (iterator)
        {
        case 0:
            cout << "=====================================";
            break;
        case 2:
            cout << "\t      PLAYER POSITION" << "\t\t=";
            break;
        case 4:
            cout << "\tY: " << playerY << "\tX: " << playerX << "\t\t\t=";
            break;
        case 7:
            cout << "\t\tPLAYER INFO" << "\t\t=";
            break;
        case 9:
            cout << "\tName: " << playerDetails.playerName << "\t\t\t=";
            break;
        case 11:
            cout << "\tHero: " << playerDetails.heroName << "\t\t\t=";
            break;
        case 13:
            cout << "\tRole: " << playerDetails.heroRole << "\t\t\t=";
            break;
        case 15:
            cout << "\tHp  : " << playerDetails.hp << "\t\t\t=";
            break;
        case 17:
            cout << "\tAtk : " << playerDetails.atk << "\t\t\t=";
            break;
        case 19:
            cout << "\tDef : " << playerDetails.def << "\t\t\t=";
            break;
        case 21:
            cout << "\tGold: " << playerDetails.gold << "\t\t\t\t=";
            break;
        case 24:
            cout << "\t\t  MAP INFO" << "\t\t=";
            break;
        case 26:
            cout << "\tMap : " << mainMap[mapIndex].mapName << "\t\t\t=";
            break;
        case 29:
            cout << "=====================================";
            break;
        default:
            cout << "\t\t\t\t\t=";
            break;
        }
}

// Print inteface (map, player info, etc)
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

    // Print map and player info
    for (int y = 0; y < mapY; y++)
    {
        cout << mapTab;
        
        // Print map
        for (int x = 0; x < mapX; x++)
        {
            char index = mainMap[mapIndex].mapContain[y][x];            

            if (index == '1' || index == '|' || index == '[' || index == ']' || index == '$')
            {
                setColor(6);
            }
            else if (index == '`' || index == 'H' || index == 'V' || index == 'B')
            {
                setColor(4);
            }
            else if (index == '^' || index == 'T' || index == 'C')
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

        printPlayerInfo(playerDetails, mapIndex, y);
    }
}
