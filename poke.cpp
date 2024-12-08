#include "iostream"
#include <string>
#include <ctime> // we need time () to seed the random func
#include <cstdlib>//to be able to use rand() and srand()
#include <string>
#include <windows.h>  //required to use Sleep();
#include <SFML/Audio.hpp>
using namespace std;

//path variables for the sound files....
string sfxencounter = "Audio/encounter.ogg";
string sfxwatergun = "Audio/WaterGun.ogg";
string sfxBlizzard = "Audio/Blizzard.ogg";
string sfxPsychic = "Audio/Psychic.ogg";
string sfxEnergyBall = "Audio/EnergyBall.ogg";
string sfxDamage = "Audio/damage.ogg";
string sfxMiss = "Audio/miss.wav";
string sfxParalyzed = "Audio/paralyzed.wav";
string sfxCry1 = "Audio/cry1.wav";
string sfxCry2 = "Audio/cry2.wav";




//To instantly implement the ansii escape sequences for the plain build file...
void ANSI_FLUSH() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE) return;

    DWORD dwMode = 0;
    if (GetConsoleMode(hOut, &dwMode)) {
        dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
        SetConsoleMode(hOut, dwMode);
    }
} 

void uyu() {
    Sleep(200);
}
class Pokemon1 {
private:

    string name;
    int hp, speed;
    int isParalyzed;
    
    sf::SoundBuffer buffer1,buffer2,buffer3,buffer4;
    sf::Sound sfx1,sfx2,sfx3,sfx4;

    sf::SoundBuffer Bufferdmg,Buffermiss,Bufferprl;
    sf::Sound sfxdmg,sfxmiss,sfxprl;
    

public:
    Pokemon1() {
        name = "Psyduck";
        hp = 100;
        speed = 40;
        isParalyzed = 100;
        
        buffer1.loadFromFile(sfxwatergun);
        sfx1.setBuffer(buffer1);
        buffer2.loadFromFile(sfxBlizzard);
        sfx2.setBuffer(buffer2);
        buffer3.loadFromFile(sfxPsychic);
        sfx3.setBuffer(buffer3);
        buffer4.loadFromFile(sfxEnergyBall);
        sfx4.setBuffer(buffer4);
        Bufferdmg.loadFromFile(sfxDamage);
        sfxdmg.setBuffer(Bufferdmg);
        Buffermiss.loadFromFile(sfxMiss);
        sfxmiss.setBuffer(Buffermiss);
        Bufferprl.loadFromFile(sfxParalyzed);
        sfxprl.setBuffer(Bufferprl);

    }

    string getName() {
        return name;
    }

    int getHp() {
        return hp;
    }

    int getSpeed() {
        return speed;
    }


    void hpUpdate(int dmg) {
        hp -= (dmg * 0.35);
    }
    void Paralyze() {
        isParalyzed = 1 + rand() % 100;
        
    }
    int WaterGun(void) {
       
        int dmg = 40;
        Sleep(350);
        sfx1.play();
        for (int x = 0; x < 2;x++) {
            cout << "\r\t\t\t\t\t\t\033[34m WaterGun:\033[0m \033[31m \\ \033[0m";
            cout.flush();
            uyu();
            cout << "\r\t\t\t\t\t\t\033[34m WaterGun: \033[36m | \033[0m";
            cout.flush();
            uyu();
            cout << "\r\t\t\t\t\t\t\033[34m WaterGun: \033[32m / \033[0m";
            cout.flush();
            uyu();
            cout << "\r\t\t\t\t\t\t\033[34m WaterGun: \033[0m\033[33m - \033[0m";
            cout.flush();
            uyu();
        }
        if(isParalyzed <=49){
            isParalyzed = 1 + rand() % 100;
            int nodmg = 0;
            cout << "Paralyzed\n";
            sfxprl.play();
            uyu();
            return nodmg;
        }
        else {
            isParalyzed = 100;
            cout << "Hit" << "\n";
            sfxdmg.play();
            return dmg;
        }
        
    }

    int Blizzard(void) {
        srand(time(0));
        int dmg = 110, acc = 70;
        Sleep(285);
        sfx2.play();
        for (int x = 0; x < 2;x++) {
            cout << "\r\t\t\t\t\t\t\033[36m Blizzard:\033[0m \033[31m \\ \033[0m";
            cout.flush();
            uyu();
            cout << "\r\t\t\t\t\t\t\033[36m Blizzard: \033[36m | \033[0m";
            cout.flush();
            uyu();
            cout << "\r\t\t\t\t\t\t\033[36m Blizzard: \033[32m / \033[0m";
            cout.flush();
            uyu();
            cout << "\r\t\t\t\t\t\t\033[36m Blizzard: \033[0m\033[33m - \033[0m";
            cout.flush();
            uyu();
        }
        if (isParalyzed <= 49) {
            isParalyzed = 1 + rand() % 100;
            

            int nodmg = 0;
            cout << "Paralyzed\n";
            sfxprl.play();
            uyu();
            return nodmg;
        }
        else {
            isParalyzed = 100;
            if (1 + rand() % 100 <= acc) {

                cout << "Hit";
                sfxdmg.play();
                return dmg;
            }
            else {
                cout << "Missed";
                sfxmiss.play();
                return 0;
            }
        }
    }

    int Psychic(void) {
        srand(time(0));
        int dmg = 110, acc = 70;
        Sleep(285);
        sfx3.play();
        for (int x = 0; x < 2;x++) {
            cout << "\r\t\t\t\t\t\t\033[35m Psychic:\033[0m \033[31m \\ \033[0m";
            cout.flush();
            uyu();
            cout << "\r\t\t\t\t\t\t\033[35m Psychic: \033[36m | \033[0m";
            cout.flush();
            uyu();
            cout << "\r\t\t\t\t\t\t\033[35m Psychic: \033[32m / \033[0m";
            cout.flush();
            uyu();
            cout << "\r\t\t\t\t\t\t\033[35m Psychic: \033[0m\033[33m - \033[0m";
            cout.flush();
            uyu();
        }
        if (isParalyzed <= 49) {
            isParalyzed = 1 + rand() % 100;
            int nodmg = 0;
            cout << "Paralyzed\n";
            sfxprl.play();
            uyu();
            return nodmg;
        }
        else {
            isParalyzed = 100;
            if (1 + rand() % 100 <= acc) {

                cout << "Hit";
                sfxdmg.play();
                return dmg;
            }
            else {
                cout << "Missed";
                sfxmiss.play();
                return 0;
            }
        }
    }

    int EnergyBall() {
        srand(time(0));
        int dmg = 120, acc = 50;
        Sleep(285);
        sfx4.play();
        for (int x = 0; x < 2;x++) {
            cout << "\r\t\t\t\t\t\t\033[32m Energy Ball:\033[0m \033[31m \\ \033[0m";
            cout.flush();
            uyu();
            cout << "\r\t\t\t\t\t\t\033[32m Energy Ball: \033[36m | \033[0m";
            cout.flush();
            uyu();
            cout << "\r\t\t\t\t\t\t\033[32m Energy Ball: \033[32m / \033[0m";
            cout.flush();
            uyu();
            cout << "\r\t\t\t\t\t\t\033[32m Energy Ball: \033[0m\033[33m - \033[0m";
            cout.flush();
            uyu();
        }
        if (isParalyzed <= 49) {
            isParalyzed = 1 + rand() % 100;
            int nodmg = 0;
            cout << "Paralyzed\n";
            sfxprl.play();
            uyu();
            return nodmg;
        }
        else {
            isParalyzed = 100;
            if (1 + rand() % 100 <= acc) {

                cout << "Hit";
                sfxdmg.play();
                return dmg;
            }
            else {
                cout << "Missed";
                sfxmiss.play();
                return 0;
            }
        }
    }
    
};

class Pokemon2 {
private:
    string name;
    int hp, speed;
    //int isParalyzed;

    sf::SoundBuffer buffer1, buffer2, buffer3, buffer4;
    sf::Sound sfx1, sfx2, sfx3, sfx4;

    sf::SoundBuffer Bufferdmg, Buffermiss;
    sf::Sound sfxdmg, sfxmiss;

public:
    Pokemon2() {
        name = "Poliwag";
        hp = 85;
        speed = 60;
        
        buffer1.loadFromFile(sfxwatergun);
        sfx1.setBuffer(buffer1);
        buffer2.loadFromFile(sfxBlizzard);
        sfx2.setBuffer(buffer2);
        buffer3.loadFromFile(sfxPsychic);
        sfx3.setBuffer(buffer3);
        buffer4.loadFromFile(sfxEnergyBall);
        sfx4.setBuffer(buffer4);
        Bufferdmg.loadFromFile(sfxDamage);
        sfxdmg.setBuffer(Bufferdmg);
        Buffermiss.loadFromFile(sfxMiss);
        sfxmiss.setBuffer(Buffermiss);


    }

    string getName() {
        return name;
    }

    int getHp() {
        return hp;
    }

    int getSpeed() {
        return speed;
    }

    void hpUpdate(int dmg) {
        hp -= (dmg * 0.35);
    }
    int WaterGun(void) {
        int dmg = 40;
        Sleep(350);
        sfx1.play();
        for (int x = 0; x < 2;x++) {
            cout << "\r\t\t\t\t\t\t\033[34m WaterGun:\033[0m \033[31m \\ \033[0m";
            cout.flush();
            uyu();
            cout << "\r\t\t\t\t\t\t\033[34m WaterGun: \033[36m | \033[0m";
            cout.flush();
            uyu();
            cout << "\r\t\t\t\t\t\t\033[34m WaterGun: \033[32m / \033[0m";
            cout.flush();
            uyu();
            cout << "\r\t\t\t\t\t\t\033[34m WaterGun: \033[0m\033[33m - \033[0m";
            cout.flush();
            uyu();
        }
        sfxdmg.play();
        cout << "Hit";
        
        Sleep(300);
        return dmg;
    }

    int Blizzard(void) {
        srand(time(0));
        int dmg = 110, acc = 70;
        Sleep(285);
        sfx2.play();
        for (int x = 0; x < 2;x++) {
            cout << "\r\t\t\t\t\t\t\033[36m Blizzard:\033[0m \033[31m \\ \033[0m";
            cout.flush();
            uyu();
            cout << "\r\t\t\t\t\t\t\033[36m Blizzard: \033[36m | \033[0m";
            cout.flush();
            uyu();
            cout << "\r\t\t\t\t\t\t\033[36m Blizzard: \033[32m / \033[0m";
            cout.flush();
            uyu();
            cout << "\r\t\t\t\t\t\t\033[36m Blizzard: \033[0m\033[33m - \033[0m";
            cout.flush();
            uyu();
        }
        if (1 + rand() % 100 <= acc) {
            cout << "Hit...";
            sfxdmg.play();
            Sleep(300);
            return dmg;
        }
        else {
            cout  << "Missed";
            sfxmiss.play();
            Sleep(300);
            return 0;
        }
    }

    void ThunderWave(void) {
        srand(time(0));
        
        Sleep(285);
        sfx3.play();
        for (int x = 0; x < 2;x++) {
            cout << "\r\t\t\t\t\t\t\033[33m Thunder Wave:\033[0m \033[31m \\ \033[0m";
            cout.flush();
            uyu();
            cout << "\r\t\t\t\t\t\t\033[33m Thunder Wave: \033[36m | \033[0m";
            cout.flush();
            uyu();
            cout << "\r\t\t\t\t\t\t\033[33m Thunder Wave: \033[32m / \033[0m";
            cout.flush();
            uyu();
            cout << "\r\t\t\t\t\t\t\033[33m Thunder Wave: \033[0m\033[33m - \033[0m";
            cout.flush();
            uyu();
        }
        
        cout  << "Hit...";
        sfxdmg.play();
        Sleep(300);
        
        
       
    }

    int ZapCannon() {
        srand(time(0));
        Sleep(285);
        sfx4.play();
        int dmg = 120, acc = 50;
        for (int x = 0; x < 2;x++) {
            cout << "\r\t\t\t\t\t\t\033[33m Zap Cannon:\033[0m \033[31m \\ \033[0m";
            cout.flush();
            uyu();
            cout << "\r\t\t\t\t\t\t\033[33m Zap Cannon: \033[36m | \033[0m";
            cout.flush();
            uyu();
            cout << "\r\t\t\t\t\t\t\033[33m Zap Cannon: \033[32m / \033[0m";
            cout.flush();
            uyu();
            cout << "\r\t\t\t\t\t\t\033[33m Zap Cannon: \033[0m\033[33m - \033[0m";
            cout.flush();
            uyu();
        }
        if (1 + rand() % 100 <= acc) {
            cout  << "Hit...";
            sfxdmg.play();
            Sleep(300);
            return dmg;
        }
        else {
            cout  << "Missed";
            sfxmiss.play();
            Sleep(1000);
            return 0;
        }
    }
};

int main() {
    ANSI_FLUSH();
    sf::Music background;
    background.openFromFile(sfxencounter);
    background.setVolume(70);
    background.play();
    restart:
    /*sf::SoundBuffer buffercry1, buffercry2;
    sf::Sound cry1, cry2;
    buffercry1.loadFromFile(sfxCry1);
    buffercry2.loadFromFile(sfxCry2);
    cry1.setBuffer(buffercry1);
    cry2.setBuffer(buffercry2);
    cry1.play();*/
    Pokemon1 Psyduck;
    Pokemon2 Poliwag;

    int choice1 = 1, choice2 = 1;
    while (true) {
        cout <<"\n" << "\t\t\t\t\t\t\033[4;31mPokeBattle Sim BETA\033[0m" << endl;
        cout << endl << "\t\t\t\033[1;33mYour Pokemon: \033[0m" << "\t\t\t\t\t\t\033[1;36mGary's Pokemon: \033[0m" << endl <<endl<<
            "\t\t\t\033[33mName: \033[0m" << Psyduck.getName() << "\t\t\t\t\t\t\033[36mName: \033[0m"<< Poliwag.getName() << endl <<
            "\t\t\t\033[33mHP: \033[0m" << Psyduck.getHp() << "\t\t\t\t\t\t\t\033[36mHP \033[0m" << Poliwag.getHp() << endl <<
            "\t\t\t\033[33mSpeed: \033[0m" << Psyduck.getSpeed() << "\t\t\t\t\t\t\033[36mSpeed: \033[0m" << Poliwag.getSpeed() << endl;

        Sleep(285);
        
        cout <<endl << endl << endl << "  \033[35;1mPlease Make a Move\033[0m (1 = \033[34mWaterGun (Water) \033[0m|| \033[36m2 = Blizzard (Ice)\033[0m ||\033[35m 3 =  Psychic (Psy)\033[0m ||\033[32m 4 =  Energy Ball (Grass)\033[0m)" << "\n\n";
        cout << "  Choice: ";
        //cry2.play();
        do {
            cin >> choice1;
            cout << "\n";
        } while (!(choice1 < 6 && choice1>0));

        /*Sleep(1000);
        Sleep(3000);*/
        srand(time(0));
        
        
        //implements the choosen attack by player
        switch (choice1) {
        case 1:
            Poliwag.hpUpdate(Psyduck.WaterGun());           
            break;
        case 2:
            Poliwag.hpUpdate(Psyduck.Blizzard());
            break;
        case 3:
            Poliwag.hpUpdate(Psyduck.Psychic());
            break;
        case 4:
            Poliwag.hpUpdate(Psyduck.EnergyBall());
            break;
        }

        string close;//varible to check the user input for restart or close
        if (Poliwag.getHp() < 1) {
            system("cls");
            string message = "Psyduck is The Winner";
            cout << "\n\n\n\n\n\n\n\n\n\n" << "\t\t\t\t\t\t   **********************" << endl;
            cout << "\t\t\t\t\t\t * " << message << " * " << endl;
            cout << "\t\t\t\t\t\t   **********************" << endl;
            Sleep(3000);
            system("cls");
            do {
                cout << "Would You like to play (Y/N)";
                cin >> close;
            } while (!(close == "y" || close =="Y"|| close == "n"|| close == "N"));
            if (close == "y" || close == "Y") {
                system("cls");
                goto restart;// to prevent taking whole main into a while loop
            }
            else {
                return 0;
            }


        }
        cout << endl << "  \n\n\t\t\t*\033[33m**************************\\\033[0m  Opponents Turn \033[33m/*************************\033[0m*" << endl;
        
        Sleep(1500);
        
        //picking and implementning the foe's attack
        choice2 = 1 + rand() % 4;
        switch (choice2) {
        case 1:
            cout << "\n\n";
            Psyduck.hpUpdate(Poliwag.WaterGun());
            
            break;
        case 2:
            cout << "\n\n";
            Psyduck.hpUpdate(Poliwag.Blizzard());
            break;
        case 3:
            cout << "\n\n";
            Poliwag.ThunderWave();
            Psyduck.Paralyze();
            break;
        case 4:
            cout << "\n\n";
            Psyduck.hpUpdate(Poliwag.ZapCannon());
            break;
        }
        Sleep(1500);
        if (Psyduck.getHp() <1) {
            system("cls");
            string messagex = "Poliwag is The Winner";

            cout << "\n\n\n\n\n\n\n\n\n\n" << "\t\t\t\t\t\t   **********************" << endl;
            cout << "\t\t\t\t\t\t * " << messagex << " * " << endl;
            cout << "\t\t\t\t\t\t   **********************" << endl;
            Sleep(3000);
            system("cls");
            do {
                cout << "Would You like to play (Y/N)";
                cin >> close;
            } while (!(close == "y"|| close == "Y"|| close == "n"|| close == "N"));
            if (close == "y" || close == "Y") {
                system("cls");
                goto restart;// to prevent taking whole main into a while loop
            }
            else {
                return 0;
            }
            
            
        }
        
        
        system("cls");
        continue;
        
        
    }     
    return 0;
}