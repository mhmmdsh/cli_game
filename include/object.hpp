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

    // Attack function
    void doAttack(int *monsterHp, int *monsterDef)
    {
        int damage = ((atk / *monsterDef) * atk);
        *monsterHp = *monsterHp - ((atk / *monsterDef) * atk);

        cout << textTab + "You deal " << damage << " damage";
        cout << " with basic attack!\n";
    }

    // Skill function
    void doSkill(int *monsterHp, int *monsterDef)
    {
        if (heroRole == "Swords")
        {
            cout << textTab + "Hawk-eye..!!\n";
        }
        else if (heroRole == "Spears")
        {
            cout << textTab + "Heavenly restriction..!!\n";
        }
        else if (heroRole == "Archer")
        {
            cout << textTab + "Electrobolt..!!\n";
        }
        else if (heroRole == "Shield")
        {
            cout << textTab + "Machine God..!!\n";
        }

        int damage = ((atk * 5 / *monsterDef) * atk);
        *monsterHp = *monsterHp - ((atk * 5 / *monsterDef) * atk);

        cout << textTab + "You deal " << damage << " damage";
        cout << " with skill attack!\n";
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

    void doAttack(int *heroHp, int *heroDef)
    {
        int damage = ((atk / *heroDef) * atk);
        *heroHp = *heroHp - ((atk / *heroDef) * atk);

        cout << textTab + "The monster deal " << damage << " damage";
        cout << " to you!\n";
    }
};

// Weapon class
struct Weapon
{
    string weaponName;
    int level;
    int damage;
    int shield;
    int price;
};

// Item class
struct Item
{
    string itemName;
    int damage;
    int shield;
    int heal;
    int price;
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
    {"Ashtoleton", "Regular", 500, 40, 35},
    {"Inferghoul", "Regular", 650, 45, 40},
    {"Toxhound", "Commander", 700, 55, 50},
    {"Demon serpent", "Boss", 1200, 75, 70},
};

// To set color console text
void setColor(unsigned short);

// Get input for player hero
void inputPlayerDetails(Hero &player)
{
    // Variable declaration
    int index;
    char inputHero;
    string name;

    system("cls");
    gameTitle();

    // Input player name
    cout << "\n\n\n\n\n" + textTab + "Enter your name: ";
    getline(cin, name);
    player.playerName = name;

    system("cls");
    gameTitle();

    // Select hero
inputHero:
    cout << "\n\n" + lineTab + "\tSelect your hero!\n";
    cout << textTab + "\t1. " + heroList[0].heroName + "\n";
    cout << textTab + "\t2. " + heroList[1].heroName + "\n";
    cout << textTab + "\t3. " + heroList[2].heroName + "\n";
    cout << textTab + "\t4. " + heroList[3].heroName + "\n";
    cout << textTab + "\tSelect (1-4): ";
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

// Monster battle function
void monsterBattle(char &monsterType, Hero &player)
{
    Monster mainMonster;

    // Check monster type
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
        srand(time(NULL));
        int randomMonsterAttack = rand() % 2;
        system("cls");

        char inputBattle;
        cout << textTab + "Battle!\n";
        cout << textTab + "Player HP  : ";
        setColor(10);
        cout << player.hp << endl;
        setColor(7);
        cout << textTab + "Monster HP : ";
        setColor(4);
        cout << mainMonster.hp << endl;
        setColor(7);
        cout << textTab + "Press Q button to do basic attack,\n";
        cout << textTab + "Press E button to do skill attack.\n";
        inputBattle = getch();

        // Player attack
        if (inputBattle == 'q' || inputBattle == 'Q')
        {
            player.doAttack(&mainMonster.hp, &mainMonster.def);
            getch();
        }
        else if (inputBattle == 'e' || inputBattle == 'E')
        {
            player.doSkill(&mainMonster.hp, &mainMonster.def);
            getch();
        }

        // Monster attack
        if (randomMonsterAttack == 1)
        {
            mainMonster.doAttack(&player.hp, &player.def);
            getch();
        }

        // Condition when monster death
        if (mainMonster.hp <= 0)
        {
            break;
        }
    }
}