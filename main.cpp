#include <iostream>
#include <string>
#include <map>

using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::map;
using std::pair;
using std::srand;

//making clear battlefield
void clear_battlefield (map <string, unsigned short> &battle_field) {
    int i=0, j=0;
    string coordinates="A0";
    for (i=0;i<10;i++){
        coordinates[1]='0';
        for(j=0;j<10;j++){
            battle_field.emplace(coordinates,0);
            coordinates[1]++;
        }
        coordinates[0]++;
    }
}

//show battlefield
void show_battlefield (map <string, unsigned short> battle_field){
    int i=0, j=0;
    string coordinates="A0";
    cout<<"  A B C D E F G H I J"<<endl;
    cout<<"-----------------------"<<endl;
    for(i=0;i<10;i++){
        coordinates[0]='A';
        cout<<i<<"|";
        for(j=0;j<10;j++){
            if (battle_field[coordinates]==0)
                cout<<"0";
            if (battle_field[coordinates]==1)
                cout<<"1";
            if (battle_field[coordinates]==2)
                cout<<"2";
            if (battle_field[coordinates]==3)
                cout<<"3";
            cout<<" ";
            coordinates[0]++;
        }
        cout<<"|";
        cout<<endl;
        coordinates[1]++;
    }
    cout<<"-----------------------"<<endl;
}

//check left cell
bool check_left(map <string, unsigned short> battle_field, string coordinates){
    bool result=0;
    if (coordinates[0] != 'A') {
        coordinates[0] = --coordinates[0];
        if(battle_field[coordinates]==0)
           result=1;
    }
    return result;
}

//check right cell
bool check_right(map <string, unsigned short> battle_field, string coordinates){
    bool result=0;
    if (coordinates[0] != 'j') {
        coordinates[0] = ++coordinates[0];
        if(battle_field[coordinates]==0)
            result=1;
    }
    return result;
}

//check up cell
bool check_up(map <string, unsigned short> battle_field, string coordinates){
    bool result=0;
    if (coordinates[1] != '0') {
        coordinates[1] = --coordinates[1];
        if(battle_field[coordinates]==0)
            result=1;
    }
    return result;
}

//check down cell
bool check_down(map <string, unsigned short> battle_field, string coordinates){
    bool result=0;
    if (coordinates[1] != '9') {
        coordinates[1] = ++coordinates[1];
        if(battle_field[coordinates]==0)
            result=1;
    }
    return result;
}

//check position for ship
bool check (map <string, unsigned short> battle_field, string coordinates, int decks, string direction){
    bool result=1;
    int i=0;
    if (battle_field[coordinates] != 0)
        result=0;
    if (direction=="here")
        if (battle_field[coordinates] != 0)
            result=0;
    if (direction=="right"){
        for (i=1;i<decks;i++){
            if (check_right(battle_field, coordinates) == 0)
                result=0;
            ++coordinates[0];
        }
    }
    if (direction=="left"){
        for (i=1;i<decks;i++){
            if (check_left(battle_field, coordinates) == 0)
                result=0;
         --coordinates[0];
        }
    }
    if (direction=="up"){
        for (i=1;i<decks;i++){
            if (check_up(battle_field, coordinates) == 0)
                result=0;
            --coordinates[1];
        }
    }
    if (direction=="down"){
        for (i=1;i<decks;i++){
            if (check_down(battle_field, coordinates) == 0)
                result=0;
            ++coordinates[1];
        }
    }
    return result;
}

//set ships
void set_ship (map <string, unsigned short> &battle_field, string coordinates, int decks, string direction) {
    int i = 0;
    string sub_coordinates = coordinates;
    if (direction == "right") {
             if (check_left(battle_field, sub_coordinates)) {
                --sub_coordinates[0];
                battle_field[sub_coordinates] = 3;
            if (check_up(battle_field, sub_coordinates)) {
                --sub_coordinates[1];
                battle_field[sub_coordinates] = 3;
                ++sub_coordinates[1];
            }
            if (check_down(battle_field, sub_coordinates))
            {
                ++sub_coordinates[1];
                battle_field[sub_coordinates] = 3;
            }
            }
        for (i = 0; i < decks; i++) {
            battle_field[coordinates] = 2;
            if (check_up(battle_field, coordinates)) {
                sub_coordinates = coordinates;
                --sub_coordinates[1];
                battle_field[sub_coordinates] = 3;
            }
            if (check_down(battle_field, coordinates)) {
                sub_coordinates = coordinates;
                 ++sub_coordinates[1];
                battle_field[sub_coordinates] = 3;
            }
            ++coordinates[0];
        }
        --coordinates[0];
        if (check_right(battle_field, coordinates)) {
            ++coordinates[0];
            battle_field[coordinates] = 3;
        }
        if (check_up(battle_field, coordinates)) {
            --coordinates[1];
            battle_field[coordinates] = 3;
            ++coordinates[1];
        }
        if (check_down(battle_field, coordinates))
        {
            ++coordinates[1];
            battle_field[coordinates] = 3;
            --coordinates[1];
        }
    }
    if (direction == "left") {
                if (check_right(battle_field, sub_coordinates)) {
                    ++sub_coordinates[0];
                    battle_field[sub_coordinates] = 3;
                if (check_up(battle_field, sub_coordinates)) {
                    --sub_coordinates[1];
                    battle_field[sub_coordinates] = 3;
                    ++sub_coordinates[1];
                }
                if (check_down(battle_field, sub_coordinates))
                {
                    ++sub_coordinates[1];
                    battle_field[sub_coordinates] = 3;
                }
            }
            for (i = 0; i < decks; i++) {
                battle_field[coordinates] = 2;
                if (check_up(battle_field, coordinates)) {
                    sub_coordinates = coordinates;
                    --sub_coordinates[1];
                    battle_field[sub_coordinates] = 3;
                }
                if (check_down(battle_field, coordinates)) {
                    sub_coordinates = coordinates;
                    ++sub_coordinates[1];
                    battle_field[sub_coordinates] = 3;
                }
                --coordinates[0];
            }
            ++coordinates[0];
            if (check_left(battle_field, coordinates)) {
                --coordinates[0];
                battle_field[coordinates] = 3;
            }
            if (check_up(battle_field, coordinates)) {
                --coordinates[1];
                battle_field[coordinates] = 3;
                ++coordinates[1];
            }
            if (check_down(battle_field, coordinates)){
                ++coordinates[1];
                battle_field[coordinates] = 3;
            }
        }
    if (direction == "up") {
                if (check_down(battle_field, sub_coordinates)) {
                    ++sub_coordinates[1];
                    battle_field[sub_coordinates] = 3;
                if (check_left(battle_field, sub_coordinates)) {
                    --sub_coordinates[0];
                    battle_field[sub_coordinates] = 3;
                    ++sub_coordinates[0];
                }
                if (check_right(battle_field, sub_coordinates))
                {
                    ++sub_coordinates[0];
                    battle_field[sub_coordinates] = 3;
                }
            }
            for (i = 0; i < decks; i++) {
                if (check_left(battle_field, coordinates)) {
                    sub_coordinates = coordinates;
                    --sub_coordinates[0];
                    battle_field[sub_coordinates] = 3;
                }
                if (check_right(battle_field, coordinates)) {
                    sub_coordinates = coordinates;
                    ++sub_coordinates[0];
                    battle_field[sub_coordinates] = 3;
                }
                battle_field[coordinates] = 2;
                --coordinates[1];
            }
            ++coordinates[1];
            if (check_up(battle_field, coordinates)) {
                --coordinates[1];
                battle_field[coordinates] = 3;
            }
            if (check_left(battle_field, coordinates)) {
                --coordinates[0];
                battle_field[coordinates] = 3;
                ++coordinates[0];
            }
            if (check_right(battle_field, coordinates)){
                ++coordinates[0];
                battle_field[coordinates] = 3;
            }
        }
    if (direction == "down") {
            if (check_up(battle_field, sub_coordinates)) {
                --sub_coordinates[1];
                battle_field[sub_coordinates] = 3;
                if (check_left(battle_field, sub_coordinates)) {
                    --sub_coordinates[0];
                    battle_field[sub_coordinates] = 3;
                    ++sub_coordinates[0];
                }
                if (check_right(battle_field, sub_coordinates))
                {
                    ++sub_coordinates[0];
                    battle_field[sub_coordinates] = 3;
                }
            }
            for (i = 0; i < decks; i++) {
                battle_field[coordinates] = 2;
                if (check_left(battle_field, coordinates)) {
                    sub_coordinates = coordinates;
                    --sub_coordinates[0];
                    battle_field[sub_coordinates] = 3;
                }
                if (check_right(battle_field, coordinates)) {
                    sub_coordinates = coordinates;
                    ++sub_coordinates[0];
                    battle_field[sub_coordinates] = 3;
                }
                battle_field[coordinates] = 2;
                ++coordinates[1];
            }
            --coordinates[1];
            if (check_down(battle_field, coordinates)) {
                ++coordinates[1];
                battle_field[coordinates] = 3;
            }
            if (check_left(battle_field, coordinates)) {
                --coordinates[0];
                battle_field[coordinates] = 3;
                ++coordinates[0];
            }
            if (check_right(battle_field, coordinates)){
                ++coordinates[0];
                battle_field[coordinates] = 3;
            }
        }

    if (direction=="here"){
        sub_coordinates = coordinates;
        battle_field[coordinates]=2;
        if(check_up(battle_field, sub_coordinates)) {
            --sub_coordinates[1];
            battle_field[sub_coordinates] = 3;
        }
        if (check_left(battle_field, sub_coordinates)) {
            --sub_coordinates[0];
            battle_field[sub_coordinates] = 3;
            ++sub_coordinates[0];
        }
        if (check_right(battle_field, sub_coordinates)) {
            ++sub_coordinates[0];
            battle_field[sub_coordinates] = 3;
            --sub_coordinates[0];
        }
        sub_coordinates = coordinates;
        if(check_left(battle_field, sub_coordinates)){
            --sub_coordinates[0];
            battle_field[sub_coordinates]=3;
            ++sub_coordinates[0];
        }
        if(check_right(battle_field, sub_coordinates)){
            ++sub_coordinates[0];
            battle_field[sub_coordinates]=3;
            --sub_coordinates[0];
        }
        if(check_down(battle_field, sub_coordinates)) {
            ++sub_coordinates[1];
            battle_field[sub_coordinates] = 3;
        }
        if(check_left(battle_field, sub_coordinates)){
            --sub_coordinates[0];
            battle_field[sub_coordinates]=3;
            ++sub_coordinates[0];
        }
        if(check_right(battle_field, sub_coordinates)){
            ++sub_coordinates[0];
            battle_field[sub_coordinates]=3;
            --sub_coordinates[0];
        }
    }
    }

//user sets ships
void user_set_ship(map <string, unsigned short> &my_battle_field){
    string direction,coordinates="A0";
    int ship_value=0;
    while (ship_value != 1){
        cout<<"deploying 4-decks ship"<<endl;
        cout<<"enter coordinates"<<endl;
        cin>>coordinates;
        if(!(coordinates[0]>='A' && coordinates[0]<='j' && coordinates[1]>=0 && coordinates[1]<=9))
            cout<<"wrong coordinates"<<endl;
        else
        {
            cout << "enter direction" << endl;
            cin >> direction;
            if (!(direction=="right" || direction=="left" || direction=="up" || direction=="down"))
                cout<<"wrong direction"<<endl;
            else {
                if (check(my_battle_field, coordinates, 4, direction)) {
                    set_ship(my_battle_field, coordinates, 4, direction);
                    show_battlefield(my_battle_field);
                    ship_value++;
                }
                else
                    cout<<"cant place here"<<endl;
            }
        }
    }
    while (ship_value != 3){
        cout<<"deploying 3-decks ship"<<endl;
        cout<<"enter coordinates"<<endl;
        cin>>coordinates;
        if(!(coordinates[0]>='A' && coordinates[0]<='j' && coordinates[1]>=0 && coordinates[1]<=9))
            cout<<"wrong coordinates"<<endl;
        else
        {
            cout << "enter direction" << endl;
            cin >> direction;
            if (!(direction=="right" || direction=="left" || direction=="up" || direction=="down"))
                cout<<"wrong direction"<<endl;
            else {
                if (check(my_battle_field, coordinates, 3, direction)) {
                    set_ship(my_battle_field, coordinates, 3, direction);
                    show_battlefield(my_battle_field);
                    ship_value++;
                }
                else
                    cout<<"cant place here"<<endl;
            }
        }
    }
    while (ship_value != 6){
        cout<<"deploying 2-decks ship"<<endl;
        cout<<"enter coordinates"<<endl;
        cin>>coordinates;
        if(!(coordinates[0]>='A' && coordinates[0]<='j' && coordinates[1]>=0 && coordinates[1]<=9))
            cout<<"wrong coordinates"<<endl;
        else
        {
            cout << "enter direction" << endl;
            cin >> direction;
            if (!(direction=="right" || direction=="left" || direction=="up" || direction=="down"))
                cout<<"wrong direction"<<endl;
            else {
                if (check(my_battle_field, coordinates, 2, direction)) {
                    set_ship(my_battle_field, coordinates, 2, direction);
                    show_battlefield(my_battle_field);
                    ship_value++;
                }
                else
                    cout<<"cant place here"<<endl;
            }
        }
    }
    while (ship_value != 10){
        cout<<"deploying 1-deck ship"<<endl;
        cout<<"enter coordinates"<<endl;
        cin>>coordinates;
        if(!(coordinates[0]>='A' && coordinates[0]<='j' && coordinates[1]>=0 && coordinates[1]<=9))
            cout<<"wrong coordinates"<<endl;
        else
        {
            if (check(my_battle_field, coordinates, 1, "here")) {
                set_ship(my_battle_field, coordinates, 1, "here");
                show_battlefield(my_battle_field);
                ship_value++;
            }
            else
                cout<<"cant place here"<<endl;
        }
    }
}

//generating bot coordinates
string gen_coordinates (){
    unsigned int intword, intvalue;
    string coordinates="A0";
    char  word, value;
    srand (time (NULL));
    intword=rand() % 10;
    intvalue=rand() % 10;
    switch (intword) {
        case 0: word='A'; break;
        case 1: word='B'; break;
        case 2: word='C'; break;
        case 3: word='D'; break;
        case 4: word='E'; break;
        case 5: word='F'; break;
        case 6: word='G'; break;
        case 7: word='H'; break;
        case 8: word='I'; break;
        case 9: word='J'; break;
    }
    switch (intvalue) {
        case 0: value='0'; break;
        case 1: value='1'; break;
        case 2: value='2'; break;
        case 3: value='3'; break;
        case 4: value='4'; break;
        case 5: value='5'; break;
        case 6: value='6'; break;
        case 7: value='7'; break;
        case 8: value='8'; break;
        case 9: value='9'; break;
    }
    coordinates[0]=word;
    coordinates[1]=value;
    return coordinates;
}

//bot sets ships
void bot_set_ships (map <string, unsigned short> &bot_battle_field){
    string direction,coordinates="A0", word;
    int ship_value=0;

    while(ship_value !=10){

    }
}
    int main(){

    //O-empty, *-shoot, | - border, + - part of the ship
    //0-empty, 1-shoot, 2-sheep, 3-unable to set ship, 4-after destroy will be shoot;
    //длделать сет шипс

    string direction,coordinates="A0";
    int i=0, decks, ship_value=0;

    map <string, unsigned short> my_battle_field;
    map <string, unsigned short> bot_battle_field;
    map <string, unsigned short> my_battle_field_open;
    map <string, unsigned short> bot_battle_field_open;

    clear_battlefield (my_battle_field);
    clear_battlefield (bot_battle_field);

    show_battlefield (my_battle_field);
    show_battlefield (bot_battle_field);

    user_set_ship(my_battle_field);

    return 0;
}