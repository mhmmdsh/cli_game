using namespace std;

// Hero ability class
struct Hero
{
    string playerName;
    string heroRole;
    string heroName;
    int hp;
    int atk;
    int def;
};

struct Monster
{
    string monsterName;
    string monsterType;
    int hp;
    int atk;
    int def;
};

// Define warrior role hero class
Hero heroList[] = {
    {"", "Swords", "Mihawk", 700, 80, 70},
    {"", "Spears", "Zenin", 600, 90, 60},
    {"", "Archer", "Legolas", 550, 100, 40},
    {"", "Shield", "Maple", 1000, 45, 100}};

Monster monsterList[] = {
    {"Ashtoleton", "Regular", 100, 10, 10},
    {"Inferghoul", "Regular", 150, 15, 15},
    {"Toxhound", "Commander", 300, 20, 20},
    {"Demon serpent", "Boss", 700, 50, 50},
};

// Get input for player hero
void inputPlayerDetails(Hero &playerDetails)
{
    string name;
    char inputHero;

    system("cls");
    gameTitle();

    cout << textTab << "Enter your name: ";
    getline(cin, name);
    playerDetails.playerName = name;

    // Select hero
inputHero:
    cout << lineTab + "Select your hero!\n";
    cout << textTab + "1. " + heroList[0].heroName + "\n";
    cout << textTab + "2. " + heroList[1].heroName + "\n";
    cout << textTab + "3. " + heroList[2].heroName + "\n";
    cout << textTab + "4. " + heroList[3].heroName + "\n";
    cout << textTab + "Select (1-5): ";
    cin >> inputHero;

    // Check for input
    switch (inputHero)
    {
    case '1':
        playerDetails.heroRole = heroList[0].heroRole;
        playerDetails.heroName = heroList[0].heroName;
        playerDetails.hp = heroList[0].hp;
        playerDetails.atk = heroList[0].atk;
        playerDetails.def = heroList[0].def;
        break;
    case '2':
        playerDetails.heroRole = heroList[1].heroRole;
        playerDetails.heroName = heroList[1].heroName;
        playerDetails.hp = heroList[1].hp;
        playerDetails.atk = heroList[1].atk;
        playerDetails.def = heroList[1].def;
        break;
    case '3':
        playerDetails.heroRole = heroList[2].heroRole;
        playerDetails.heroName = heroList[2].heroName;
        playerDetails.hp = heroList[2].hp;
        playerDetails.atk = heroList[2].atk;
        playerDetails.def = heroList[2].def;
        break;
    case '4':
        playerDetails.heroRole = heroList[3].heroRole;
        playerDetails.heroName = heroList[3].heroName;
        playerDetails.hp = heroList[3].hp;
        playerDetails.atk = heroList[3].atk;
        playerDetails.def = heroList[3].def;
        break;
    default:
        cout << textTab + "Invalid input!\n";
        goto inputHero;
        break;
    }
}
