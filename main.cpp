#include<bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

string table[3][3][3]; // if table[i][j] == 1 =>X else (2) => O
string unUsed_list_player_B[6] = {"B1","B1","B2","B2","B3","B3"};
string unUsed_list_player_R[6] = {"R1","R1","R2","R2","R3","R3"};
string possible_list_player_B[6];
string possible_list_player_R[6];
string maxTable[3][3];

void printTable (bool clearScreen) {
   // if (clearScreen)
    //system("cls");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (maxTable[i][j] == "") { // khane khali ast
                cout << "|    |";
            }
            else if (maxTable[i][j] == "R1") { // X
                cout << "| R1 |";
            }
            else if (maxTable[i][j] == "R2") { // X
                cout << "| R2 |";
            }
            else if (maxTable[i][j] == "R3") { // X
                cout << "| R3 |";
            }
            else if (maxTable[i][j] == "B1") { // X
                cout << "| B1 |";
            }
            else if (maxTable[i][j] == "B2") { // X
                cout << "| B2 |";
            }
            else if (maxTable[i][j] == "B3") { // X
                cout << "| B3 |";
            }

        }
        cout << endl;
    }
}


int check () {
    /* check kon aya
     1. bazokini barande shode ast
     2. bazi mosavi shode ast
     3. harekati momken nabashad

        0 if nothing
        1 if X wins
        2 if O wins
        3 if draw
     */

    return 0;
    int cnt;
    for (int i = 0; i < 3; i++) {
        if (table[i][0][0] == table[i][1][0] &&
         table[i][1][0] == table[i][2][0] &&
          table[i][0][0] != "")
            return true;
    }

    // columns
    for (int i = 0; i < 3; i++) {
        if (table[0][i][0] == table[1][i][0] &&
        table[1][i][0] == table[2][i][0] &&
        table[0][i][0] != "")
            return true;
    }

    // diag
    if (table[0][0][0] == table[1][1][0] && // qotr asli
    table[1][1][0] == table[2][2][0] &&
    table[0][0] != 0)
        return true;

    if (table[0][2][0] == table[1][1][0] && // qotr farii
    table[1][1][0] == table[2][0][0] && table[1][1][0] != "")
        return true;

    if (cnt == 27) return 3; // mosavi shodan
    return 0;
}

bool mohreIsOnMaxTabel(string mohre_palyer){
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j ++)
            if (maxTable [i][j] == mohre_palyer){
                if (table [i][j][2] != "" && table [i][j][1] != "" && table [i][j][0] != "" && table [i][j][2] > table [i][j][1] && table [i][j][2] > table [i][j][0])
                    maxTable [i][j] = table [i][j][2];
                else if (table [i][j][1] != "" && table [i][j][0] != "" && table [i][j][1] > table [i][j][0])
                    maxTable [i][j] = table [i][j][1];
                else if (table [i][j][0] != "")
                    maxTable [i][j] = table [i][j][0];
                return true ;
            }
    return false;
}

bool checkMohreAvailable (char player,string mohre_palyer){
    cout << "start update_used_mohre "<< endl;
    char mohre_palyer_char = mohre_palyer[0];
    cout << mohre_palyer_char << endl;

    if (player == 'R') {
        if (mohre_palyer == "R1" && (unUsed_list_player_R [0] == "R1" || unUsed_list_player_R [1] == "R1"))
            return true;
        if (mohre_palyer == "R2" && (unUsed_list_player_R [2] == "R2" || unUsed_list_player_R [3] == "R2"))
            return true;
        if (mohre_palyer == "R3" && (unUsed_list_player_R [4] == "R3" || unUsed_list_player_R [5] == "R3"))
            return true;
    } else if (player == 'B') {
        if (mohre_palyer == "B1" && (unUsed_list_player_B [0] == "B1" || unUsed_list_player_B [1] == "B1"))
            return true;
        if (mohre_palyer == "B2" && (unUsed_list_player_B [2] == "B2" || unUsed_list_player_B [3] == "B2"))
            return true;
        if (mohre_palyer == "B3" && (unUsed_list_player_B [4] == "B3" || unUsed_list_player_B [5] == "B3"))
            return true;
    }
    if (mohreIsOnMaxTabel(mohre_palyer) )
        return true ;
    cout << "mohre is not available." << endl;
    return false;
}

bool is_possible (int x, int y, char player, string mohre_palyer) { // aya in khane khali ast ya kheir
    cout << "is_possible" << endl;
    cout << player << endl;
    char mohre_palyer_char = mohre_palyer[0];
    cout << mohre_palyer_char << endl;
    cout << (player == mohre_palyer_char) << endl;
    if (player == mohre_palyer_char) {
        if (checkMohreAvailable (player, mohre_palyer)){
            if (maxTable [x][y] == "")
                return true;
            else if (maxTable [x][y][1] < mohre_palyer[1])
                return true;
        }
    }
    return false;
}


void updateMax(int x, int y, string mohre_palyer){
    if (maxTable [x][y][1] < mohre_palyer [1])
        maxTable [x][y] = mohre_palyer;
}


void  play (int x, int y, string mohre_palyer) { // dar khane (x, y) mohre symbol ra bazi kon
    if (table[x][y][0] == "")
        table[x][y][0] = mohre_palyer;
    else if (table[x][y][1] == "")
        table[x][y][1] = mohre_palyer;
    else if (table[x][y][2] == "")
        table[x][y][2] = mohre_palyer;
    updateMax(x, y, mohre_palyer);
}

void update_used_mohre(string mohre_palyer){
    cout << "start update_used_mohre "<< endl;
    char mohre_palyer_char = mohre_palyer[0];
    cout << mohre_palyer_char << endl;

    if (mohre_palyer_char == 'R') {
        if (mohre_palyer == "R1" && unUsed_list_player_R [0] != "") {
            unUsed_list_player_R [0] = "";
        } else if (mohre_palyer == "R1" && unUsed_list_player_R [1] != ""){
            unUsed_list_player_R [1] = "";
        } else if (mohre_palyer == "R2" && unUsed_list_player_R [2] != ""){
            unUsed_list_player_R [2] = "";
        } else if (mohre_palyer == "R2" && unUsed_list_player_R [3] != ""){
            unUsed_list_player_R [3] = "";
        } else if (mohre_palyer == "R3" && unUsed_list_player_R [4] != ""){
            unUsed_list_player_R [4] = "";
        } else if (mohre_palyer == "R3" && unUsed_list_player_R [5] != ""){
            unUsed_list_player_R [5] = "";
        }
        for (int j = 0; j<6 ; j++){
        cout << "unUsed_list_player_R : " << unUsed_list_player_R[j];
        cout << endl;
        }

    } else if (mohre_palyer_char == 'B') {
        if (mohre_palyer == "B1" && unUsed_list_player_B [0] != ""){
            unUsed_list_player_B [0] = "";
        } else if (mohre_palyer == "B1" && unUsed_list_player_B [1] != ""){
            unUsed_list_player_B [1] = "";
        } else if (mohre_palyer == "B2" && unUsed_list_player_B [2] != ""){
            unUsed_list_player_B [2] = "";
        } else if (mohre_palyer == "B2" && unUsed_list_player_B [3] != ""){
            unUsed_list_player_B [3] = "";
        } else if (mohre_palyer == "B3" && unUsed_list_player_B [4] != ""){
            unUsed_list_player_B [4] = "";
        } else if (mohre_palyer == "B3" && unUsed_list_player_B [5] != ""){
            unUsed_list_player_R [5] = "";
        }

        for (int i = 0; i<6 ; i++){
        cout << "unUsed_list_player_B : " << unUsed_list_player_B[i];
        cout << endl;
        }

    }
}


void checkGameOver (){
    printTable(true);
    switch (check()) {
        case 1: {
            cout << "X won!!" << endl; // TODO check Red or Blue
            break;
        }
        case 2: {
            cout << "O win!!" << endl;
            break;
        }
        case 3: {
            cout << "DRAW!" << endl;
            break;
        }
    }
}

/*char* print_playable_mohre (char player){
    string playableMohre [1][6];
    int k = 0;
    if (player == 'R'){

        for (int i = 0; i < 6; i ++)
            if (unUsed_list_player_R [i] != ''){
                playableMohre [k] = unUsed_list_player_R [i]
                k ++
            }
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j ++)
                if (maxTable [i][j] != 0 && maxTable [i][j][0] == 'R'){
                    playableMohre [k] = maxTable [i][j]
                    k ++
                }
    }
    else if (palyer == "B"){

        for (int i = 0; i < 6; i ++)
            if (unUsed_list_player_B [0][i] != ""){
                playableMohre [k] = unUsed_list_player_B [i]
                k ++
            }
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j ++)
                if (maxTable [i][j] != 0 && maxTable [i][j][0] == 'B'){
                    playableMohre [k] = maxTable [i][j]
                    k ++
                }
    }
    return playableMohre;
}
*/
void execute () {
    char player = 'B'; // {1, 2}
    string symbol = "Blue";
    string mohre_palyer;
    int x, y;
    bool clearScreen = true;

    while (true) {//cnt < 27 &&
        printTable(clearScreen);
        clearScreen = true;
        if (player == 'R')
            symbol= "Red";
        else
            symbol= "Blue";
        cout << "player : " << symbol << endl;
        cout << "x ro vared konid: ";
        cin >> x;
        cout << "y ro vared konid: ";
        cin >> y;
        cout << "mohrera vared konid: " ;
        cin >> mohre_palyer;
        if (is_possible(x, y , player, mohre_palyer)) {
            play (x, y, mohre_palyer);
            update_used_mohre(mohre_palyer);
            if (player == 'B') // bazikon avaz mishavad
                player = 'R';
            else
                player = 'B';
            checkGameOver ();
        } else {
            cout << "it is not possible action chose another one, press key to continue" << endl;
            clearScreen = false;
            //int stop;
            //cin >> stop;
            continue;
        }
    }
}

int main () {
    execute();
    return 0;
}
