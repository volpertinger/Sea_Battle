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
            switch (battle_field[coordinates]) {
                case 0:cout << ' ';break;
                case 1:cout << '*';break;
                case 2:cout << ' ';break;
                case 3:cout << ' ';break;
                case 4:cout << '#';break;
                default: cout<<'&';
            }
            cout<<" ";
            coordinates[0]++;
        }
        cout<<"|";
        cout<<endl;
        coordinates[1]++;
    }
    cout<<"-----------------------"<<endl;
}

//show battlefield with hiden codes
void show_battlefield_open (map <string, unsigned short> battle_field){
    int i=0, j=0;
    string coordinates="A0";
    cout<<"  A B C D E F G H I J"<<endl;
    cout<<"-----------------------"<<endl;
    for(i=0;i<10;i++){
        coordinates[0]='A';
        cout<<i<<"|";
        for(j=0;j<10;j++){
            switch (battle_field[coordinates]) {
                case 0:cout << 'O';break;
                case 1:cout << '*';break;
                case 2:cout << '-';break;
                case 3:cout << '+';break;
                case 4:cout << '#';break;
                default: cout<<'&';
            }
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
        --coordinates[0];
        if(battle_field[coordinates]==0)
           result=1;
    }
    return result;
}

//check right cell
bool check_right(map <string, unsigned short> battle_field, string coordinates){
    bool result=0;
    if (coordinates[0] != 'J') {
        ++coordinates[0];
        if(battle_field[coordinates]==0)
            result=1;
    }
    return result;
}

//check up cell
bool check_up(map <string, unsigned short> battle_field, string coordinates){
    bool result=0;
    if (coordinates[1] != '0') {
        --coordinates[1];
        if(battle_field[coordinates]==0)
            result=1;
    }
    return result;
}

//check down cell
bool check_down(map <string, unsigned short> battle_field, string coordinates){
    bool result=0;
    if (coordinates[1] != '9') {
        ++coordinates[1];
        if(battle_field[coordinates]==0)
            result=1;
    }
    return result;
}

//check left cell for set ship
bool check_left_set(map <string, unsigned short> battle_field, string coordinates){
    bool result=0;
    if (coordinates[0] != 'A') {
        --coordinates[0];
        if((battle_field[coordinates]==0) || (battle_field[coordinates]==3) || (battle_field[coordinates]==1))
            result=1;
    }
    return result;
}

//check right cell for set ship
bool check_right_set(map <string, unsigned short> battle_field, string coordinates){
    bool result=0;
    if (coordinates[0] != 'J') {
        ++coordinates[0];
        if((battle_field[coordinates]==0) || (battle_field[coordinates]==3) || (battle_field[coordinates]==1))
            result=1;
    }
    return result;
}

//check up cell for set ship
bool check_up_set(map <string, unsigned short> battle_field, string coordinates){
    bool result=0;
    if (coordinates[1] != '0') {
        --coordinates[1];
        if((battle_field[coordinates]==0) || (battle_field[coordinates]==3) || (battle_field[coordinates]==1))
            result=1;
    }
    return result;
}

//check down cell for set ship
bool check_down_set(map <string, unsigned short> battle_field, string coordinates){
    bool result=0;
    if (coordinates[1] != '9') {
        ++coordinates[1];
        if((battle_field[coordinates]==0) || (battle_field[coordinates]==3) || (battle_field[coordinates]==1))
            result=1;
    }
    return result;
}

//check left cell for ship part
bool check_left_ship(map <string, unsigned short> battle_field, string coordinates){
    bool result=0;
    if (coordinates[0] != 'A') {
        --coordinates[0];
        if((battle_field[coordinates]==2) || (battle_field[coordinates]==4))
            result=1;
    }
    return result;
}

//check right cell for ship part
bool check_right_ship(map <string, unsigned short> battle_field, string coordinates){
    bool result=0;
    if (coordinates[0] != 'J') {
        ++coordinates[0];
        if((battle_field[coordinates]==2) || (battle_field[coordinates]==4))
            result=1;
    }
    return result;
}

//check up cell for ship part
bool check_up_ship(map <string, unsigned short> battle_field, string coordinates){
    bool result=0;
    if (coordinates[1] != '0') {
        --coordinates[1];
        if((battle_field[coordinates]==2) || (battle_field[coordinates]==4))
            result=1;
    }
    return result;
}

//check down cell for ship part
bool check_down_ship(map <string, unsigned short> battle_field, string coordinates){
    bool result=0;
    if (coordinates[1] != '9') {
        ++coordinates[1];
        if((battle_field[coordinates]==2) || (battle_field[coordinates]==4))
            result=1;
    }
    return result;
}

//check left cell for shooting
bool check_left_shot(map <string, unsigned short> battle_field, string coordinates){
    bool result=0;
    if (coordinates[0] != 'A') {
        --coordinates[0];
        if((battle_field[coordinates]==1) || (battle_field[coordinates]==4))
            result=1;
    }
    return result;
}

//check right cell for shooting
bool check_right_shot(map <string, unsigned short> battle_field, string coordinates){
    bool result=0;
    if (coordinates[0] != 'J') {
        ++coordinates[0];
        if((battle_field[coordinates]==1) || (battle_field[coordinates]==4))
            result=1;
    }
    return result;
}

//check up cell for shooting
bool check_up_shot(map <string, unsigned short> battle_field, string coordinates){
    bool result=0;
    if (coordinates[1] != '0') {
        --coordinates[1];
        if((battle_field[coordinates]==1) || (battle_field[coordinates]==4))
            result=1;
    }
    return result;
}

//check down cell for shooting
bool check_down_shot(map <string, unsigned short> battle_field, string coordinates){
    bool result=0;
    if (coordinates[1] != '9') {
        ++coordinates[1];
        if((battle_field[coordinates]==1) || (battle_field[coordinates]==4))
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
             if (check_left_set(battle_field, sub_coordinates)) {
                --sub_coordinates[0];
                battle_field[sub_coordinates] = 3;
            if (check_up_set(battle_field, sub_coordinates)) {
                --sub_coordinates[1];
                battle_field[sub_coordinates] = 3;
                ++sub_coordinates[1];
            }
            if (check_down_set(battle_field, sub_coordinates))
            {
                ++sub_coordinates[1];
                battle_field[sub_coordinates] = 3;
            }
            }
        for (i = 0; i < decks; i++) {
            battle_field[coordinates] = 2;
            if (check_up_set(battle_field, coordinates)) {
                sub_coordinates = coordinates;
                --sub_coordinates[1];
                battle_field[sub_coordinates] = 3;
            }
            if (check_down_set(battle_field, coordinates)) {
                sub_coordinates = coordinates;
                 ++sub_coordinates[1];
                battle_field[sub_coordinates] = 3;
            }
            ++coordinates[0];
        }
        --coordinates[0];
        if (check_right_set(battle_field, coordinates)) {
            ++coordinates[0];
            battle_field[coordinates] = 3;
        }
        if (check_up_set(battle_field, coordinates)) {
            --coordinates[1];
            battle_field[coordinates] = 3;
            ++coordinates[1];
        }
        if (check_down_set(battle_field, coordinates))
        {
            ++coordinates[1];
            battle_field[coordinates] = 3;
            --coordinates[1];
        }
    }
    if (direction == "left") {
                if (check_right_set(battle_field, sub_coordinates)) {
                    ++sub_coordinates[0];
                    battle_field[sub_coordinates] = 3;
                if (check_up_set(battle_field, sub_coordinates)) {
                    --sub_coordinates[1];
                    battle_field[sub_coordinates] = 3;
                    ++sub_coordinates[1];
                }
                if (check_down_set(battle_field, sub_coordinates))
                {
                    ++sub_coordinates[1];
                    battle_field[sub_coordinates] = 3;
                }
            }
            for (i = 0; i < decks; i++) {
                battle_field[coordinates] = 2;
                if (check_up_set(battle_field, coordinates)) {
                    sub_coordinates = coordinates;
                    --sub_coordinates[1];
                    battle_field[sub_coordinates] = 3;
                }
                if (check_down_set(battle_field, coordinates)) {
                    sub_coordinates = coordinates;
                    ++sub_coordinates[1];
                    battle_field[sub_coordinates] = 3;
                }
                --coordinates[0];
            }
            ++coordinates[0];
            if (check_left_set(battle_field, coordinates)) {
                --coordinates[0];
                battle_field[coordinates] = 3;
            }
            if (check_up_set(battle_field, coordinates)) {
                --coordinates[1];
                battle_field[coordinates] = 3;
                ++coordinates[1];
            }
            if (check_down_set(battle_field, coordinates)){
                ++coordinates[1];
                battle_field[coordinates] = 3;
            }
        }
    if (direction == "up") {
                if (check_down_set(battle_field, sub_coordinates)) {
                    ++sub_coordinates[1];
                    battle_field[sub_coordinates] = 3;
                if (check_left_set(battle_field, sub_coordinates)) {
                    --sub_coordinates[0];
                    battle_field[sub_coordinates] = 3;
                    ++sub_coordinates[0];
                }
                if (check_right_set(battle_field, sub_coordinates))
                {
                    ++sub_coordinates[0];
                    battle_field[sub_coordinates] = 3;
                }
            }
            for (i = 0; i < decks; i++) {
                if (check_left_set(battle_field, coordinates)) {
                    sub_coordinates = coordinates;
                    --sub_coordinates[0];
                    battle_field[sub_coordinates] = 3;
                }
                if (check_right_set(battle_field, coordinates)) {
                    sub_coordinates = coordinates;
                    ++sub_coordinates[0];
                    battle_field[sub_coordinates] = 3;
                }
                battle_field[coordinates] = 2;
                --coordinates[1];
            }
            ++coordinates[1];
            if (check_up_set(battle_field, coordinates)) {
                --coordinates[1];
                battle_field[coordinates] = 3;
            }
            if (check_left_set(battle_field, coordinates)) {
                --coordinates[0];
                battle_field[coordinates] = 3;
                ++coordinates[0];
            }
            if (check_right_set(battle_field, coordinates)){
                ++coordinates[0];
                battle_field[coordinates] = 3;
            }
        }
    if (direction == "down") {
            if (check_up_set(battle_field, sub_coordinates)) {
                --sub_coordinates[1];
                battle_field[sub_coordinates] = 3;
                if (check_left_set(battle_field, sub_coordinates)) {
                    --sub_coordinates[0];
                    battle_field[sub_coordinates] = 3;
                    ++sub_coordinates[0];
                }
                if (check_right_set(battle_field, sub_coordinates))
                {
                    ++sub_coordinates[0];
                    battle_field[sub_coordinates] = 3;
                }
            }
            for (i = 0; i < decks; i++) {
                battle_field[coordinates] = 2;
                if (check_left_set(battle_field, coordinates)) {
                    sub_coordinates = coordinates;
                    --sub_coordinates[0];
                    battle_field[sub_coordinates] = 3;
                }
                if (check_right_set(battle_field, coordinates)) {
                    sub_coordinates = coordinates;
                    ++sub_coordinates[0];
                    battle_field[sub_coordinates] = 3;
                }
                battle_field[coordinates] = 2;
                ++coordinates[1];
            }
            --coordinates[1];
            if (check_down_set(battle_field, coordinates)) {
                ++coordinates[1];
                battle_field[coordinates] = 3;
            }
            if (check_left_set(battle_field, coordinates)) {
                --coordinates[0];
                battle_field[coordinates] = 3;
                ++coordinates[0];
            }
            if (check_right_set(battle_field, coordinates)){
                ++coordinates[0];
                battle_field[coordinates] = 3;
            }
        }

    if (direction=="here"){
        sub_coordinates = coordinates;
        battle_field[coordinates]=2;
        if(check_up_set(battle_field, sub_coordinates)) {
            --sub_coordinates[1];
            battle_field[sub_coordinates] = 3;
        }
        if (check_left_set(battle_field, sub_coordinates)) {
            --sub_coordinates[0];
            battle_field[sub_coordinates] = 3;
            ++sub_coordinates[0];
        }
        if (check_right_set(battle_field, sub_coordinates)) {
            ++sub_coordinates[0];
            battle_field[sub_coordinates] = 3;
            --sub_coordinates[0];
        }
        sub_coordinates = coordinates;
        if(check_left_set(battle_field, sub_coordinates)){
            --sub_coordinates[0];
            battle_field[sub_coordinates]=3;
            ++sub_coordinates[0];
        }
        if(check_right_set(battle_field, sub_coordinates)){
            ++sub_coordinates[0];
            battle_field[sub_coordinates]=3;
            --sub_coordinates[0];
        }
        if(check_down_set(battle_field, sub_coordinates)) {
            ++sub_coordinates[1];
            battle_field[sub_coordinates] = 3;
        }
        if(check_left_set(battle_field, sub_coordinates)){
            --sub_coordinates[0];
            battle_field[sub_coordinates]=3;
            ++sub_coordinates[0];
        }
        if(check_right_set(battle_field, sub_coordinates)){
            ++sub_coordinates[0];
            battle_field[sub_coordinates]=3;
            --sub_coordinates[0];
        }
    }
    }

//user sets ships
void user_set_ships(map <string, unsigned short> &my_battle_field){
    string direction,coordinates="A0";
    int ship_value=0;
    while (ship_value != 1){
        cout<<"deploying 4-decks ship"<<endl;
        cout<<"enter coordinates"<<endl;
        cin>>coordinates;
        if(!((coordinates[0]>='A' && coordinates[0]<='J') && (coordinates.size()==2)))
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
        if(!((coordinates[0]>='A' && coordinates[0]<='J') && (coordinates.size()==2)))
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
        if(!((coordinates[0]>='A' && coordinates[0]<='J') && (coordinates.size()==2)))
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
        if(!((coordinates[0]>='A' && coordinates[0]<='J') && (coordinates.size()==2)))
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

//generating bot direction
string gen_direction(){
    string direction="here";
    int int_direction=0;
    int_direction=rand() % 4;
    switch (int_direction){
        case 0: direction="right"; break;
        case 1: direction="left"; break;
        case 2: direction="up"; break;
        case 3: direction="down"; break;
    }
    return direction;
}

//bot sets ships
void bot_set_ships (map <string, unsigned short> &bot_battle_field){
    string direction="here",coordinates="A0";
    int ship_value=0;
    bool ship_is_set=0;

    while(ship_value !=1){
        coordinates=gen_coordinates();
        cout<<"coord"<<endl<<coordinates<<endl;
        ship_is_set=0;
        if (((check(bot_battle_field, coordinates, 4, "left" )) || (check(bot_battle_field, coordinates, 4, "right" ))) || ((check(bot_battle_field, coordinates, 4, "up" )) || (check(bot_battle_field, coordinates, 4, "down" ))))
        {
            while (! ship_is_set) {
            direction=gen_direction();
            cout<<"direct"<<endl<<direction<<endl;
            if(check(bot_battle_field, coordinates, 4, direction )) {
                set_ship(bot_battle_field, coordinates, 4, direction);
                ship_is_set=1;
                ++ship_value;
            }
            }
        }
    }
    while(ship_value !=3){
        ship_is_set=0;
        coordinates=gen_coordinates();
        if (((check(bot_battle_field, coordinates, 3, "left" )) || (check(bot_battle_field, coordinates, 3, "right" ))) || ((check(bot_battle_field, coordinates, 3, "up" )) || (check(bot_battle_field, coordinates, 3, "down" ))))
        {
            while (! ship_is_set) {
                direction=gen_direction();
                if(check(bot_battle_field, coordinates, 3, direction )) {
                    set_ship(bot_battle_field, coordinates, 3, direction);
                    ship_is_set=1;
                    ++ship_value;
                }
            }
        }
    }
    while(ship_value !=6){
        coordinates=gen_coordinates();
        ship_is_set=0;
        if (((check(bot_battle_field, coordinates, 2, "left" )) || (check(bot_battle_field, coordinates, 2, "right" ))) || ((check(bot_battle_field, coordinates, 2, "up" )) || (check(bot_battle_field, coordinates, 2, "down" ))))
        {
            while (! ship_is_set) {
                direction=gen_direction();
                if(check(bot_battle_field, coordinates, 2, direction )) {
                    set_ship(bot_battle_field, coordinates, 2, direction);
                    ship_is_set=1;
                    ++ship_value;
                }
            }
        }
    }
    while(ship_value !=10){
        coordinates=gen_coordinates();
        ship_is_set=0;
        if (check(bot_battle_field, coordinates, 1, "here" ))
        {
            while (! ship_is_set) {
                if(check(bot_battle_field, coordinates, 1, "here" )) {
                    set_ship(bot_battle_field, coordinates, 1, "here");
                    ship_is_set=1;
                    ++ship_value;
                }
            }
        }
    }
}

//shooting
void shoot (map <string, unsigned short> &battle_field, string coordinates){
    switch(battle_field[coordinates]){
        case 0 :battle_field[coordinates]=1;break;
        case 2 :battle_field[coordinates]=4;break;
        case 3 :battle_field[coordinates]=1;break;
        case 5 :battle_field[coordinates]=1;break;
    }
}

//check status of ship
bool ship_is_destroyed(map <string, unsigned short> battle_field, string coordinates){
    bool is_destroyed=1;
    string sub_coordinates=coordinates;
    if (battle_field[coordinates]==2)
        is_destroyed=0;
    coordinates=sub_coordinates;
    while(check_left_ship(battle_field, coordinates)){
        --coordinates[0];
        if (battle_field[coordinates]==2)
            is_destroyed=0;
    }
    coordinates=sub_coordinates;
    while(check_right_ship(battle_field, coordinates)){
        ++coordinates[0];
        if (battle_field[coordinates]==2)
            is_destroyed=0;
    }
    coordinates=sub_coordinates;
    while(check_up_ship(battle_field, coordinates)){
        --coordinates[1];
        if (battle_field[coordinates]==2)
            is_destroyed=0;
    }
    coordinates=sub_coordinates;
    while(check_down_ship(battle_field, coordinates)){
        ++coordinates[1];
        if (battle_field[coordinates]==2)
            is_destroyed=0;
    }
    return is_destroyed;
}

//shot around destroyed cell of ship
void shot_around_cell (map <string, unsigned short> &battle_field, string coordinates){
    string sub_coordinates=coordinates;
    if (check_left_set){
        --coordinates[0];
        if((battle_field[coordinates]!=2) && (battle_field[coordinates]!=4))
        battle_field[coordinates]=1;
            if(check_up_set){
                --coordinates[1];
                if((battle_field[coordinates]!=2) && (battle_field[coordinates]!=4))
                battle_field[coordinates]=1;
                ++coordinates[1];
            }
            if(check_down_set){
                ++coordinates[1];
                if((battle_field[coordinates]!=2) && (battle_field[coordinates]!=4))
                battle_field[coordinates]=1;
                --coordinates[1];
            }
    }
    coordinates=sub_coordinates;
    if (check_right_set){
        ++coordinates[0];
        if((battle_field[coordinates]!=2) && (battle_field[coordinates]!=4))
        battle_field[coordinates]=1;
        if(check_up_set){
            --coordinates[1];
            if((battle_field[coordinates]!=2) && (battle_field[coordinates]!=4))
            battle_field[coordinates]=1;
            ++coordinates[1];
        }
        if(check_down_set){
            ++coordinates[1];
            if((battle_field[coordinates]!=2) && (battle_field[coordinates]!=4))
            battle_field[coordinates]=1;
            --coordinates[1];
        }
    }
    coordinates=sub_coordinates;
    if (check_down_set){
        ++coordinates[1];
        if((battle_field[coordinates]!=2) && (battle_field[coordinates]!=4))
        battle_field[coordinates]=1;
        if(check_left_set){
            --coordinates[0];
            if((battle_field[coordinates]!=2) && (battle_field[coordinates]!=4))
            battle_field[coordinates]=1;
            ++coordinates[0];
        }
        if(check_right_set){
            ++coordinates[0];
            if((battle_field[coordinates]!=2) && (battle_field[coordinates]!=4))
            battle_field[coordinates]=1;
            --coordinates[0];
        }
    }
    coordinates=sub_coordinates;
    if (check_up_set){
        --coordinates[1];
        if((battle_field[coordinates]!=2) && (battle_field[coordinates]!=4))
        battle_field[coordinates]=1;
        if(check_left_set){
            --coordinates[0];
            if((battle_field[coordinates]!=2) && (battle_field[coordinates]!=4))
            battle_field[coordinates]=1;
            ++coordinates[0];
        }
        if(check_right_set){
            ++coordinates[0];
            if((battle_field[coordinates]!=2) && (battle_field[coordinates]!=4))
            battle_field[coordinates]=1;
            --coordinates[0];
        }
    }
}

//shot around destroyed ship
void shot_around_ship (map <string, unsigned short> &battle_field, string coordinates){
    string sub_coordinates=coordinates;
    shot_around_cell (battle_field, coordinates);
    while(check_left_ship(battle_field, coordinates)){
        --coordinates[0];
        shot_around_cell (battle_field, coordinates);
    }
    coordinates=sub_coordinates;
    while(check_right_ship(battle_field, coordinates)){
        ++coordinates[0];
        shot_around_cell (battle_field, coordinates);
    }
    coordinates=sub_coordinates;
    while(check_up_ship(battle_field, coordinates)){
        --coordinates[1];
        shot_around_cell (battle_field, coordinates);
    }
    coordinates=sub_coordinates;
    while(check_down_ship(battle_field, coordinates)){
        ++coordinates[1];
        shot_around_cell (battle_field, coordinates);
    }
}

//bot shoot before destroyed cell
string bot_shot (map <string, unsigned short> &battle_field){
    string coordinates="A0";
    bool is_need_move=1;
    while(is_need_move) {
        coordinates = gen_coordinates();
        if ((battle_field[coordinates] != 4) && (battle_field[coordinates] != 1)) {
            shoot(battle_field, coordinates);
            is_need_move=0;
        }
    }
    return coordinates;
}

//bot shooting before find 2 cells of ship near
string bot_shot_to_find_direction (map <string, unsigned short> &battle_field, string coordinates){
    string direction="here", sub_coordinates=coordinates;
    bool is_need_move=1;
        while(is_need_move){
            direction=gen_direction();
            sub_coordinates=coordinates;
            if(!(check_down_shot(battle_field, coordinates)) && (direction =="down")) {
                ++sub_coordinates[1];
                shoot(battle_field, sub_coordinates);
                is_need_move=0;
            }
            if(!(check_up_shot(battle_field, coordinates)) && (direction =="up")) {
                --sub_coordinates[1];
                shoot(battle_field, sub_coordinates);
                is_need_move=0;
            }
            if(!(check_right_shot(battle_field, coordinates)) && (direction =="right")) {
                ++sub_coordinates[0];
                shoot(battle_field, sub_coordinates);
                is_need_move=0;
            }
            if(!(check_left_shot(battle_field, coordinates)) && (direction =="left")) {
                --sub_coordinates[0];
                shoot(battle_field, sub_coordinates);
                is_need_move=0;
            }
        }
        return sub_coordinates;
}

//bot finding direction
string find_direction (map <string, unsigned short> &battle_field, string coordinates){
    string direction;
    if ((check_down_ship(battle_field, coordinates)) || (check_up_ship(battle_field, coordinates)))
    direction="upright";
    if ((check_left_ship(battle_field, coordinates)) || (check_right_ship(battle_field, coordinates)))
    direction="horizontally";
    return direction;
}

//bot shoooting when knows direction
string informed_shot (map <string, unsigned short> &battle_field, string direction, string coordinates){
    bool is_need_to_shoot=1;
    string sub_coordinates=coordinates;
    if (direction=="horizontally"){
        while ((battle_field[coordinates]==4) && (coordinates[0]>'A') && (battle_field[coordinates] != 1) && (is_need_to_shoot)) {
            --coordinates[0];
            if ((battle_field[coordinates] != 1) && (battle_field[coordinates] != 4)) {
                shoot(battle_field, coordinates);
                is_need_to_shoot = 0;
            }
        }
        coordinates=sub_coordinates;
        if (is_need_to_shoot){
            while ((battle_field[coordinates]==4) && (coordinates[1]<'J') && (battle_field[coordinates] != 1) && (is_need_to_shoot)) {
                ++coordinates[0];
                if ((battle_field[coordinates] != 1) && (battle_field[coordinates] != 4)) {
                    shoot(battle_field, coordinates);
                    is_need_to_shoot=0;
                }
            }
        }
    }
    if (direction=="upright"){
        while ((battle_field[coordinates]==4) && (coordinates[1]>'0') && (battle_field[coordinates] != 1) && (is_need_to_shoot)) {
            --coordinates[1];
            if ((battle_field[coordinates] != 1) && (battle_field[coordinates] != 4)) {
                shoot(battle_field, coordinates);
                is_need_to_shoot = 0;
            }
        }
        coordinates=sub_coordinates;
        if (is_need_to_shoot) {
            while ((battle_field[coordinates] == 4) && (coordinates[1] < '9') && (battle_field[coordinates] != 1) && (is_need_to_shoot)) {
                ++coordinates[1];
                if ((battle_field[coordinates] != 1) && (battle_field[coordinates] != 4)) {
                    shoot(battle_field, coordinates);
                    is_need_to_shoot=0;
                }
            }
        }
    }
    return coordinates;
}

    int main(){

    //O-empty, *-shoot, | - border, + - part of the ship, #-destroyed part of ship
    //0-empty, 1-shoot, 2-ship, 3-unable to set ship, 4-destroyed part of ship;

    string direction="here",coordinates="A0",bot_direction="here",bot_coordinates="A0", sub_bot_coordinates="A0";
    int i=0, my_ship_value=10, bot_ship_value=10;
    bool player_is_need_move=1, try_to_destroy=0, know_direction=0, bot_is_need_move=1;

    srand (time (NULL));

    cout<<"designations"<<"O-empty, *-shoot, | - border, + - part of the ship, #-destroyed part of ship"<<endl;

    map <string, unsigned short> my_battle_field;
    map <string, unsigned short> bot_battle_field;

    clear_battlefield (my_battle_field);
    clear_battlefield (bot_battle_field);

    show_battlefield (my_battle_field);
    show_battlefield (bot_battle_field);

    bot_set_ships(bot_battle_field);
    show_battlefield (bot_battle_field);

    user_set_ships(my_battle_field);
    show_battlefield (my_battle_field);

    cout<<"would you like to see BOT's battlefield?"<<endl<<"1-yes"<<endl<<"2-no"<<endl;
    cin>>i;
    if(i==1)
        show_battlefield_open(bot_battle_field);

    while ((my_ship_value>0) && (bot_ship_value>0)) {
        player_is_need_move = 1;
        while (player_is_need_move) {
            cout << "your turn" << endl;
            cout << "opponetn's battlefield" << endl;
            show_battlefield(bot_battle_field);
            cout << "enter coordinates for shot" << endl;
            cin >> coordinates;
            if (!(coordinates[0] >= 'A' && coordinates[0] <= 'J' && coordinates.size() == 2))
                cout << "wrong coordinates" << endl;
            else {
                if ((bot_battle_field[coordinates] != 4) && (bot_battle_field[coordinates] != 1)) {
                    shoot(bot_battle_field, coordinates);
                    if (bot_battle_field[coordinates] != 4)
                        player_is_need_move = 0;
                    if (ship_is_destroyed(bot_battle_field, coordinates)) {
                        shot_around_ship(bot_battle_field, coordinates);
                        --bot_ship_value;
                    }
                } else
                    cout << "wrong coordinates" << endl;
            }
        }
        cout << "opponetn's battlefield" << endl;
        show_battlefield(bot_battle_field);

        bot_is_need_move = 1;
        while (bot_is_need_move) {
            cout << "BOT turn" << endl;
            cout << "your battlefield" << endl;
            show_battlefield_open(my_battle_field);
            if ((!try_to_destroy) && (bot_is_need_move)) {
                bot_coordinates = bot_shot(my_battle_field);
                if (my_battle_field[bot_coordinates] != 4) {
                    bot_is_need_move = 0;
                    try_to_destroy = 0;
                    know_direction = 0;
                }
                if (my_battle_field[bot_coordinates] == 4) {
                    bot_is_need_move = 1;
                    try_to_destroy = 1;
                    know_direction = 0;
                    if (ship_is_destroyed(my_battle_field, bot_coordinates)) {
                        shot_around_ship(my_battle_field, bot_coordinates);
                        bot_is_need_move = 1;
                        know_direction = 0;
                        try_to_destroy = 0;
                        --my_ship_value;
                    }
                }
            }
            if ((try_to_destroy) && (!know_direction) && (bot_is_need_move)) {
                sub_bot_coordinates = bot_shot_to_find_direction(my_battle_field, bot_coordinates);
                if (my_battle_field[sub_bot_coordinates] != 4) {
                    bot_is_need_move = 0;
                    try_to_destroy = 1;
                    know_direction = 0;
                }
                if (my_battle_field[sub_bot_coordinates] == 4) {
                    know_direction = 1;
                    try_to_destroy = 1;
                    bot_is_need_move = 1;
                    bot_direction = find_direction(my_battle_field, bot_coordinates);
                    bot_coordinates = sub_bot_coordinates;
                    if (ship_is_destroyed(my_battle_field, bot_coordinates)) {
                        shot_around_ship(my_battle_field, bot_coordinates);
                        bot_is_need_move = 1;
                        know_direction = 0;
                        try_to_destroy = 0;
                        --my_ship_value;
                    }
                }
            }
            if ((try_to_destroy) && (know_direction) && (bot_is_need_move)) {
                sub_bot_coordinates = informed_shot(my_battle_field, bot_direction, bot_coordinates);
                if (my_battle_field[sub_bot_coordinates] != 4) {
                    bot_is_need_move = 0;
                    know_direction = 1;
                    try_to_destroy = 1;
                }
                if (my_battle_field[sub_bot_coordinates] == 4) {
                    know_direction = 1;
                    try_to_destroy = 1;
                    bot_is_need_move = 1;
                    bot_coordinates = sub_bot_coordinates;
                    if (ship_is_destroyed(my_battle_field, sub_bot_coordinates)) {
                        shot_around_ship(my_battle_field, bot_coordinates);
                        bot_is_need_move = 1;
                        know_direction = 0;
                        try_to_destroy = 0;
                        --my_ship_value;
                    }
                }
            }
            cout << "your battlefield" << endl;
            show_battlefield_open(my_battle_field);
        }
    }
    if (my_ship_value==0)
        cout<<"you LOST"<<endl;
    else
        cout<<"you WON"<<endl;


    return 0;
}