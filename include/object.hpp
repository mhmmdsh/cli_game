using namespace std;

// Hero class
struct Hero
{
    string playerName;
    string heroRole;
    string heroName;
    int hp;
    int atk;
    int def;
    int gold;

    void doAttack(int *monsterHp, int *monsterDef)
    {
        *monsterHp = *monsterHp - (atk - *monsterDef);
    }
};

// Monster class
struct Monster
{
    string monsterName;
    string monsterType;
    int hp;
    int atk;
    int def;
};

// Weapon class
struct Weapon
{
    string weaponName;
    int level;
    int damage;
    int shield;
};

// Item class
struct Item
{
    string itemName;
    int damage;
    int shield;
    int heal;
};

// Define list of hero
Hero heroList[] = {
    {"", "Swords", "Mihawk", 700, 80, 70},
    {"", "Spears", "Zenin", 600, 90, 60},
    {"", "Archer", "Legolas", 550, 100, 40},
    {"", "Shield", "Maple", 1000, 45, 100}
};

// Define list of monster
Monster monsterList[] = {
    {"Ashtoleton", "Regular", 100, 10, 10},
    {"Inferghoul", "Regular", 150, 15, 15},
    {"Toxhound", "Commander", 300, 20, 20},
    {"Demon serpent", "Boss", 700, 50, 50},
};

// To set color console text
void setColor(unsigned short);

// Get input for player hero
void inputPlayerDetails(Hero &player)
{
    int index;
    char inputHero;
    string name;

    system("cls");
    gameTitle();

    cout << textTab << "Enter your name: ";
    getline(cin, name);
    player.playerName = name;

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
        index = 0;
        break;
    case '2':
        index = 1;
        break;
    case '3':
        index = 2;
        break;
    case '4':
        index = 3;
        break;
    default:
        cout << textTab + "Invalid input!\n";
        goto inputHero;
        break;
    }

    player.heroRole = heroList[index].heroRole;
    player.heroName = heroList[index].heroName;
    player.hp = heroList[index].hp;
    player.atk = heroList[index].atk;
    player.def = heroList[index].def;
}

void monsterBattle(char &monsterType, Hero &player)
{
    Monster mainMonster;
    if (monsterType == 'R')
    {
        srand(time(NULL));
        int randomMonster = rand() % 2;
        mainMonster = monsterList[randomMonster];
    }
    else if (monsterType == 'C')
    {
        mainMonster = monsterList[2];
    }
    else if (monsterType == 'B')
    {
        mainMonster = monsterList[3];
    }

    system("cls");
    cout << textTab + "You encountered " << mainMonster.monsterName;
    getch();

    // Battle Loop
    while (true)
    {
        system("cls");

        char input_battle;
        cout << textTab + "Battle!" << endl;
        cout << textTab + "Player HP  : ";
        setColor(10);
        cout << player.hp << endl;
        setColor(7);
        cout << textTab + "Monster HP : ";
        setColor(4);
        cout << mainMonster.hp << endl;
        setColor(7);
        cout << textTab + "Press Q button to attack!";
        input_battle = getch();

        if (input_battle == 'q' || input_battle == 'Q')
        {
            player.doAttack(&mainMonster.hp, &mainMonster.def);
        }

        if (mainMonster.hp <= 0)
        {
            break;
        }
    }
}