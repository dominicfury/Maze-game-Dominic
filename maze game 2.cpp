#include <iostream>
#include <string>
#include<Windows.h>
#include<conio.h>
using std::endl;
using std::cout;
using std::cin;
using std::string;

void welcome();
char keypress();
void pLevel(int);
void setMe(int);
bool isExit(int, int, int);
bool isWall(int, int, int);
int getPos(int, int&);
int getX(int, int &);
void update(int, int, int);
void makeSpace(int, int, int);
void setItems();
int getBlank(int, int &);

const char space = ' ';
const char me = '@';
const char item = '+';

// maze options

char lvl1[5][5] = { { '#', '#', '#', '#', '#'},
                  { 'X', ' ', ' ', ' ', '#' },
                  { '#', '#', '#', ' ', '#' },
                  { '#', '#', ' ', ' ', '#' },
                  { '#', 'O', ' ', '#', '#' } };

char lvl2[10][10] = { { '#', '#', '#', '#', '#', '#', '#', '#', 'X', '#'},
                    { '#', '#', '#', '#', '#', '#', '#', '#', ' ', '#'},
                    { '#', '#', '#', '#', '#', '#', '#', '#', ' ', '#'},
                    { '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
                    { '#', '#', '#', ' ', '#', '#', '#', '#', '#', '#'},
                    { '#', '#', '#', ' ', '#', '#', '#', '#', '#', '#'},
                    { '#', '#', '#', ' ', '#', '#', '#', '#', '#', '#'},
                    { '#', '#', '#', ' ', '#', '#', '#', '#', '#', '#'},
                    { '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
                    { '#', '#', '#', '#', '#', '#', '#', 'O', '#', '#'} };


char lvl3[15][15] = { { '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
                    { 'X', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
                    { '#', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
                    { '#', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
                    { '#', '#', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
                    { '#', '#', '#', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
                    { '#', '#', '#', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
                    { '#', '#', '#', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
                    { '#', '#', '#', ' ', '#', '#', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', 'O' },
                    { '#', '#', '#', ' ', '#', '#', '#', '#', '#', ' ', '#', '#', '#', '#', '#' },
                    { '#', '#', '#', ' ', ' ', ' ', '#', '#', '#', ' ', '#', '#', '#', '#', '#' },
                    { '#', '#', '#', '#', '#', ' ', '#', '#', '#', ' ', '#', '#', '#', '#', '#' },
                    { '#', '#', '#', '#', '#', ' ', '#', '#', '#', ' ', '#', '#', '#', '#', '#' },
                    { '#', '#', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', '#', '#' },
                    { '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' } };

char lvl4[20][20] = { { '#', '#', '#', '#','#', '#','#', '#','#', '#','#', '#','#', '#','#', '#','#', '#', '#', '#' },
                      { '#', '#', '#', '#','#', '#','#', '#','#', '#','#', '#','#', '#','#', '#','#', 'X', '#', '#' },
                      { '#', '#', '#', '#','#', '#','#', '#','#', '#','#', '#','#', '#','#', '#','#', ' ', '#', '#' },
                      { '#', '#', '#', '#','#', '#','#', '#','#', '#','#', '#','#', '#','#', '#','#', ' ', '#', '#' },
                      { '#', '#', '#', ' ',' ', ' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#' },
                      { '#', '#', '#', ' ','#', '#','#', '#','#', '#','#', '#','#', '#','#', '#','#', '#', '#', '#' },
                      { '#', '#', '#', ' ',' ', ' ',' ', ' ',' ', ' ',' ', ' ','#', '#','#', '#','#', '#', '#', '#' },
                      { '#', '#', '#', '#','#', '#','#', '#','#', '#','#', ' ','#', '#','#', '#','#', '#', '#', '#' },
                      { '#', '#', '#', '#','#', ' ',' ', ' ',' ', ' ',' ', ' ','#', '#','#', '#','#', '#', '#', '#' },
                      { '#', '#', '#', '#','#', ' ','#', '#','#', '#','#', '#','#', '#','#', '#','#', '#', '#', '#' },
                      { '#', '#', '#', '#','#', ' ',' ', ' ',' ', ' ',' ', ' ',' ', ' ',' ', '#','#', '#', '#', '#' },
                      { '#', '#', '#', '#','#', '#','#', '#','#', '#','#', '#','#', '#',' ', '#','#', '#', '#', '#' },
                      { '#', '#', '#', '#',' ', ' ',' ', ' ',' ', ' ',' ', ' ',' ', ' ',' ', '#','#', '#', '#', '#' },
                      { '#', '#', '#', '#','#', '#','#', '#','#', '#','#', '#','#', '#',' ', '#','#', '#', '#', '#' },
                      { '#', '#', '#', '#','#', '#','#', '#','#', '#','#', '#','#', '#',' ', '#','#', '#', '#', '#' },
                      { '#', '#', '#', '#','#', '#','#', '#','#', '#','#', '#','#', '#',' ', '#','#', '#', '#', '#' },
                      { '#', '#', '#', '#',' ', ' ',' ', ' ',' ', ' ',' ', ' ',' ', ' ',' ', '#','#', '#', '#', '#' },
                      { '#', '#', '#', ' ',' ', '#','#', '#','#', '#','#', '#','#', '#','#', '#','#', '#', '#', '#' },
                      { '#', '#', '#', ' ','#', '#','#', '#','#', '#','#', '#','#', '#','#', '#','#', '#', '#', '#' },
                      { '#', '#', '#', 'O','#', '#','#', '#','#', '#','#', '#','#', '#','#', '#','#', '#', '#', '#' }};






int main(void){
    welcome();
begin:
    system("CLS");
    cout << "\n\n\n\n\n\n\n    \t\t\t";
    cout << "PLEASE SELECT A LEVEL \n\n    \t\t\t1---2---3---4\n    \t\t\t";
    int lvl;
    cin >> lvl;

    system("CLS");
    setMe(lvl);

    pLevel(lvl);
    int x, y;

    while (1){

        char move = keypress();

        switch (move){

        case 'u':
            x = getPos(lvl, y);
            if (!isWall(x - 1, y, lvl)){
                if (isExit(x - 1, y, lvl)){
                    system("CLS");
                    cout << "You Win!" << endl;
                    Sleep(2000);
                    goto begin;;
                }
                system("CLS");
                makeSpace(lvl, x, y);
                update(lvl, x - 1, y);
            }
            break;
        case 'd':
            x = getPos(lvl, y);
            if (!isWall(x + 1, y, lvl)){
                if (isExit(x + 1, y, lvl)){
                    system("CLS");
                    cout << "You Win!" << endl;
                    Sleep(2000);
                    goto begin;;
                }
                system("CLS");
                makeSpace(lvl, x, y);
                update(lvl, x + 1, y);
            }
            break;
        case 'l':
            x = getPos(lvl, y);
            if (!isWall(x, y - 1, lvl)){
                if (isExit(x, y - 1, lvl)){
                    system("CLS");
                    cout << "You Win!" << endl;
                    Sleep(2000);
                    goto begin;;
                }
                system("CLS");
                makeSpace(lvl, x, y);
                update(lvl, x, y - 1);
            }
            break;
        case 'r':
            x = getPos(lvl, y);
            if (!isWall(x, y + 1, lvl)){
                if (isExit(x, y + 1, lvl)){
                    system("CLS");
                    cout << "You Win!" << endl;
                    Sleep(2000);
                    goto begin;;
                }
                system("CLS");
                makeSpace(lvl, x, y);
                update(lvl, x, y + 1);
            }
            break;
        default:
            break;
        }

    }

    return 0;
}

void welcome(){
    string start = "Indiana Jones Maze Escape";
    string indev = "By Dominic Fury";
    string howto = "Use the arrow keys to move around the maze, go to the O to complete the maze";
    cout << endl;
    cout << "\n\n\n\n\n\n\n    \t\t\t";
    for (auto ch : start){
        cout << ch;
        Sleep(40);
    } cout << endl << endl;
    cout << "    \t   ";
    for (auto ch : indev){
        cout << ch;
        Sleep(40);
    } cout << endl << endl << endl;
    cout << "\t";
    for (auto ch : howto){
        cout << ch;
        Sleep(40);
    }
    Sleep(1500);
}


void pLevel(int lvl){
    cout << "\n\n\n\n\n";
    if (lvl == 1){
        for (int i = 0; i != 5; ++i){
            cout << endl << "\t\t\t\t";
            for (int j = 0; j != 5; ++j){
                cout << lvl1[i][j];
            }
        } cout << endl;
    }
    if (lvl == 2){
        for (int i = 0; i != 10; ++i){
            cout << endl << "\t\t\t\t";
            for (int j = 0; j != 10; ++j){
                cout << lvl2[i][j];
            }
        } cout << endl;
    }
       if (lvl == 3){
        for (int i = 0; i != 15; ++i){
            cout << endl << "\t\t\t\t";
            for (int j = 0; j != 15; ++j){
                cout << lvl3[i][j];
            }
        } cout << endl;
    }
       if (lvl == 4){
        for (int i = 0; i != 20; ++i){
            cout << endl << "\t\t\t\t";
            for (int j = 0; j != 20; ++j){
                cout << lvl4[i][j];
            }
        } cout << endl;
    }
}

void setMe(int lvl){
    int x, y;
    if (lvl == 1){
        x = getX(lvl, y);
        lvl1[x][y] = me;
    }
    if (lvl == 2){
        x = getX(lvl, y);
        lvl2[x][y] = me;
    }
    if (lvl == 3){
        x = getX(lvl, y);
        lvl3[x][y] = me;
    }
      if (lvl == 4){
        x = getX(lvl, y);
        lvl4[x][y] = me;
      }
}
void setItems(int lvl){
    int x, y;
    if (lvl == 1){
        x = getBlank(lvl, y);
        lvl1[x][y] = item;
    }
}

char keypress(){

    char key = 127;

    key = _getch();

    if (key == 0 || key == -32){

        key = _getch();

        if (key == 72) {
            key = 'u';
        } else if (key == 75){
            key = 'l';
        } else if (key == 77){
            key = 'r';
        } else if (key == 80){
            key = 'd';
        }
    }
    return key;
}

bool isExit(int x, int y, int lvl){
    if (lvl == 1){
        if (lvl1[x][y] == 'O'){
            return true;
        }
        else {
            return false;
        }
    }
    if (lvl == 2){
        if (lvl2[x][y] == 'O'){
            return true;
        }
        else {
            return false;
        }
    }
     if (lvl == 3){
        if (lvl3[x][y] == 'O'){
            return true;
        }
        else {
            return false;
        }
    }
     if (lvl == 4){
        if (lvl4[x][y] == 'O'){
            return true;
        }
        else {
            return false;
        }
    }
    return true;
}

int getPos(int lvl, int &y){
    int xCoord;
    if (lvl == 1){
        for (int i = 0; i != 5; ++i){
            for (int j = 0; j != 5; ++j){
                if (lvl1[i][j] == '@'){
                    xCoord = i;
                    y = j;
                    return xCoord;
                }
            }
        }
    }
    if (lvl == 2){
        for (int i = 0; i != 10; ++i){
            for (int j = 0; j != 10; ++j){
                if (lvl2[i][j] == '@'){
                    xCoord = i;
                    y = j;
                    return xCoord;
                }
            }
        }
    }
     if (lvl == 3){
        for (int i = 0; i != 15; ++i){
            for (int j = 0; j != 15; ++j){
                if (lvl3[i][j] == '@'){
                    xCoord = i;
                    y = j;
                    return xCoord;
                }
            }
        }
    }
     if (lvl == 4){
        for (int i = 0; i != 20; ++i){
            for (int j = 0; j != 20; ++j){
                if (lvl4[i][j] == '@'){
                    xCoord = i;
                    y = j;
                    return xCoord;
                }
            }
        }
    }

    return 0;
}

bool isWall(int x, int y, int lvl){
    if (lvl == 1){
        if (lvl1[x][y] == '#'){
            cout << "\n\t\t\tCannot move! That is a wall";
            Sleep(400);
            system("CLS");
            pLevel(lvl);
            return true;
        }
        else {
            return false;
        }
    }
    if (lvl == 2){
        if (lvl2[x][y] == '#'){
            cout << "\n\t\t\tCannot move! That is a wall.";
            Sleep(400);
            system("CLS");
            pLevel(lvl);
            return true;
        }
        else {
            return false;
        }
    }
     if (lvl == 3){
        if (lvl3[x][y] == '#'){
            cout << "\n\t\t\tCannot move! That is a wall.";
            Sleep(400);
            system("CLS");
            pLevel(lvl);
            return true;
        }
        else {
            return false;
        }
     }
      if (lvl == 4){
        if (lvl4[x][y] == '#'){
            cout << "\n\t\t\tCannot move! That is a wall.";
            Sleep(400);
            system("CLS");
            pLevel(lvl);
            return true;
        }
        else {
            return false;
        }
      }
    return true;
}

int getX(int lvl, int &y){
    int xCoord;
    if (lvl == 1){
        for (int i = 0; i != 5; ++i){
            for (int j = 0; j != 5; ++j){
                if (lvl1[i][j] == 'X'){
                    xCoord = i;
                    y = j;
                    return xCoord;
                }
            }
        }
    }
    if (lvl == 2){
        for (int i = 0; i != 10; ++i){
            for (int j = 0; j != 10; ++j){
                if (lvl2[i][j] == 'X'){
                    xCoord = i;
                    y = j;
                    return xCoord;
                }
            }
        }
    }
    if (lvl == 3){
        for (int i = 0; i != 15; ++i){
            for (int j = 0; j != 15; ++j){
                if (lvl3[i][j] == 'X'){
                    xCoord = i;
                    y = j;
                    return xCoord;
                }
            }
        }
    }
    if (lvl == 4){
        for (int i = 0; i != 20; ++i){
            for (int j = 0; j != 20; ++j){
                if (lvl4[i][j] == 'X'){
                    xCoord = i;
                    y = j;
                    return xCoord;
                }
            }
        }
    }
    return 0;
}
int getBlank(int lvl, int &y){
    int bCoord;
    if (lvl == 1){
        for (int i = 0; i != 5; ++i){
            for (int j = 0; j != 5; ++j){
                if (lvl1[i][j] == ' '){
                    bCoord = i;
                    y = j;
                    return bCoord;
                }
            }
        }
    }
}
void update(int lvl, int x, int y){
    if (lvl == 1){
        lvl1[x][y] = me;
        pLevel(lvl);
    }
    if (lvl == 2){
        lvl2[x][y] = me;
        pLevel(lvl);
    }
    if (lvl == 3){
        lvl3[x][y] = me;
        pLevel(lvl);
    }
    if (lvl == 4){
        lvl4[x][y] = me;
        pLevel(lvl);
    }
}

void makeSpace(int lvl, int x, int y){
    if (lvl == 1){
        lvl1[x][y] = space;
    }
    if (lvl == 2){
        lvl2[x][y] = space;
    }
    if (lvl == 3){
        lvl3[x][y] = space;
    }
    if (lvl == 4){
        lvl4[x][y] = space;
    }

}
