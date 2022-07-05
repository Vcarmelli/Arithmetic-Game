//ARITHMETIC GAME IN C++ BY VASHTI KARMELLI V. CAMU - 7022022

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <windows.h>
using namespace std;

typedef struct RECORD{
    string username;
    string password;
    int Sadd;
    int Ssub;
    int Smul;
    int Sdiv;
    float average;
    struct RECORD *next;
} MPRAC;


class Player {
private:
    MPRAC *head;
    string user;
    int ctr=0, items, level;
    int GetItems();
    int game();
    int menu2();
    int locate(string un);
    int checker(int uans, int answer);
    int upass(string un, string pw);
    bool isEmpty();
    void Score();
    void adjLevel();
    void sortList();
    void leaderboard();
    void account(string un, string pw);
    void log(string un, string pw);
    void points(int a, int s, int m, int d);
    float average(int a, int s, int m, int d);
public:
    void initial();
    void Addition();
    void Subtraction();
    void Multiplication();
    void Division();
    void sign();
    void entry();
    void retrieve();
    void save();

};

void gotoxy(int x,int y)
{
    COORD coord = {0,0};
    coord.X=x; coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void border(){
    int j;
    gotoxy(5,0);
    gotoxy(1,1);         //Top border line
    for(j=0; j<118; j++)
        printf("%c", 223);
    gotoxy(1,29);        //Bottom border line
    for(j=0; j<=117; j++)
        printf("%c", 223);
    for(j=0; j<28; j++){ //Left and Right border line
        gotoxy(1,1+j);
        printf("%c",219);
        gotoxy(118,1+j);
        printf("%c",219);
    }
        printf("\n");
}

//*********************************************************************************PRIVATE METHODS
int Player::GetItems(){
    system("cls");
    border();
    gotoxy(30,2);cout << "========================================================";
    gotoxy(30,3);cout << "|                  ARITHMETIC PRACTICE                 |";
    gotoxy(30,4);cout << "========================================================";
    gotoxy(40,6);cout << "How many items would you like to answer? ";
    cin >> items;
    return items;
}


int Player::game(){
    int select;
    system("cls");
    border();
    gotoxy(30,4);cout<<"        ______";
    gotoxy(30,5);cout<<"       |      |";
    gotoxy(30,6);cout<<"       |      |";
    gotoxy(30,7);cout<<" ______|      |_______";
    gotoxy(30,8);cout<<"|                     | ";
    gotoxy(30,9);cout<<"|______        _______|";
    gotoxy(30,10);cout<<"       |      |";
    gotoxy(30,11);cout<<"       |      |";
    gotoxy(30,12);cout<<"       |______|";

    gotoxy(48,4);cout<<" __________________ ";
    gotoxy(48,5);cout<<"|                  |";
    gotoxy(48,6);cout<<"|__________________|";

    gotoxy(53,7);cout<<" _____     _____";
    gotoxy(53,8);cout<<"|     |   |     |";
    gotoxy(53,9);cout<<"|     \\___/     |";
    gotoxy(53,10);cout<<" \\             /";
    gotoxy(53,11);cout<<" /     ___     \\";
    gotoxy(53,12);cout<<"|     /   \\     |";
    gotoxy(53,13);cout<<"|_____|   |_____|";

    gotoxy(70,5);cout<<"       _______";
    gotoxy(70,6);cout<<"      /      /";
    gotoxy(70,7);cout<<"     /      /";
    gotoxy(70,8);cout<<"    /      /";
    gotoxy(70,9);cout<<"   /      /";
    gotoxy(70,10);cout<<"  /      /";
    gotoxy(70,11);cout<<" /      /";
    gotoxy(70,12);cout<<"/______/";

    gotoxy(30,15); cout <<"========================================================";
    gotoxy(30,16); cout <<"|                  ARITHMETIC PRACTICE                 |";
    gotoxy(30,17); cout <<"========================================================";
    gotoxy(30,18); cout <<"|                1.) Addition                          |";
    gotoxy(30,19); cout <<"|                2.) Subtraction                       |";
    gotoxy(30,20); cout <<"|                3.) Multiplication                    |";
    gotoxy(30,21); cout <<"|                4.) Division                          |";
    gotoxy(30,22); cout <<"|                5.) LEADERBOARD                       |";
    gotoxy(30,23); cout <<"|                6.) Save & EXIT                       |";
    gotoxy(30,24); cout <<"========================================================";
    gotoxy(45,25); cout <<"Select (1-6): "; cin >> select;
    return select;
}


int Player::menu2(){
    system("cls");
    border();
    int op;
    gotoxy(30,4);cout <<"=====================================================";
    gotoxy(30,5);cout <<"|           Press 1: Change Difficulty              |";
    gotoxy(30,6);cout <<"|           Press 2: Back to Same Operation         |";
    gotoxy(30,7);cout <<"|           Press 3: View Leaderboard               |";
    gotoxy(30,8);cout <<"|           Press 4: Go to Main Menu                |";
    gotoxy(30,9);cout <<"=====================================================";
    gotoxy(40,10);cout <<"Enter your choice: "; cin >> op;
    switch(op){
        case 1: adjLevel(); break;
        case 2: break;
        case 3: leaderboard(); return 1;
        case 4: return 1;
        default: return 1;
    }
    return 0;
}


int Player::locate(string un){
    MPRAC *cur;
    cur = head;
    int i=0;
    while (cur!=NULL){
        if (cur->username==un){
            return i;
        }
        i++; cur = cur->next;
    }
    return -1;
}


int Player::checker(int uans, int answer){
    if (uans == answer){
        gotoxy(40, 12); cout <<"You're CORRECT!";
        ctr++; Score();
        gotoxy(35, 14); system("pause"); return ctr;
    } else {
        gotoxy(40, 12); cout <<"Try Again. The correct answer is "<<answer;
        gotoxy(35, 14); system("pause"); return ctr;
    }
}


int Player::upass(string un, string pw){
    MPRAC *cur;
    cur = head;
    int i=0;
    while(cur!=NULL){
        if(cur->username==un && cur->password==pw){
            return i;
        }
        i++; cur = cur->next;
    }
    return -1;
}


bool Player::isEmpty(){
    return (head==NULL);
}


void Player::Score(){
    gotoxy(90,2);cout <<"Score: "<<ctr<<"/"<<items<<" || ";
    cout <<fixed<<setw(6)<<setprecision(2)<< ((float)ctr/items*100);
}


void Player::adjLevel(){
    system("cls");
    border();
    int op;
    gotoxy(30,2);cout <<"=====================================================";
    gotoxy(30,3);cout <<"|                  DIFFICULTY LEVEL                 |";
    gotoxy(30,4);cout <<"=====================================================";
    gotoxy(30,5);cout <<"|                   Press 1: Easy                   |";
    gotoxy(30,6);cout <<"|                  Press 2: Average                 |";
    gotoxy(30,7);cout <<"|                 Press 3: Difficulty               |";
    gotoxy(30,8);cout <<"=====================================================";
    gotoxy(40,9);cout <<"Enter your choice: "; cin >> op;
    switch(op){
        case 1: level = 1; break;
        case 2: level = 3; break;
        case 3: level = 6; break;
        default: level = 1; break;
    }
}


void Player::sortList(){
    MPRAC *pre,*cur;
    pre=head;
    cur=head->next;
    while (cur!=NULL){
        cur->average = average(cur->Sadd, cur->Ssub, cur->Smul, cur->Sdiv);
        if (cur->average > pre->average){
            pre->next = cur->next;
            cur->next = head;
            head = cur;
            cur = pre;
        } else {
            pre = cur;
        }
        cur = cur->next;
    }
}


void Player::leaderboard(){
    int i=1;
    system("cls");
    border(); sortList();
    MPRAC *cur;
    cur = head;

    gotoxy(3,2);cout<<"___________________";
    gotoxy(3,3);cout<<"|                 |";
    gotoxy(3,4);cout<<"|    ________|    | ";
    gotoxy(3,5);cout<<"|    |       |____| ";
    gotoxy(3,6);cout<<"|    |____________";
    gotoxy(3,7);cout<<"|                |";
    gotoxy(3,8);cout<<"|____________    |";
    gotoxy(3,9);cout<<"            |    |";
    gotoxy(3,10);cout<<"|----|______|    |";
    gotoxy(3,11);cout<<"|                |";
    gotoxy(3,12);cout<<"|________________|";

    gotoxy(23,2);cout<<" _________________";
    gotoxy(23,3);cout<<"|                 |";
    gotoxy(23,4);cout<<"|  ____________|  |";
    gotoxy(23,5);cout<<"|  |           |__|";
    gotoxy(23,6);cout<<"|  |";
    gotoxy(23,7);cout<<"|  |";
    gotoxy(23,8);cout<<"|  |";
    gotoxy(23,9);cout<<"|  |           ____";
    gotoxy(23,10);cout<<"|  |___________|  |";
    gotoxy(23,11);cout<<"|                 |";
    gotoxy(23,12);cout<<"|_________________|";

    gotoxy(43,2);cout<<" ________________";
    gotoxy(43,3);cout<<"|                |";
    gotoxy(43,4);cout<<"|                |";
    gotoxy(43,5);cout<<"|   __________   |";
    gotoxy(43,6);cout<<"|  |          |  |";
    gotoxy(43,7);cout<<"|  |          |  |";
    gotoxy(43,8);cout<<"|  |          |  |";
    gotoxy(43,9);cout<<"|  |__________|  |";
    gotoxy(43,10);cout<<"|                |";
    gotoxy(43,11);cout<<"|                |";
    gotoxy(43,12);cout<<"|________________|";

    gotoxy(62,2);cout<<" _________________";
    gotoxy(62,3);cout<<"|     _________   |";
    gotoxy(62,4);cout<<"|     |       |   |";
    gotoxy(62,5);cout<<"|     |_______|   |";
    gotoxy(62,6);cout<<"|           ______|";
    gotoxy(62,7);cout<<"|           \\";
    gotoxy(62,8);cout<<"|     |\\     \\";
    gotoxy(62,9);cout<<"|     | \\     \\";
    gotoxy(62,10);cout<<"|     |  \\     \\";
    gotoxy(62,11);cout<<"|     |   \\     \\";
    gotoxy(62,12);cout<<"|_____|    \\_____\\";

    gotoxy(82,2);cout<<" _______________";
    gotoxy(82,3);cout<<"|               |";
    gotoxy(82,4);cout<<"|               |";
    gotoxy(82,5);cout<<"|     __________|";
    gotoxy(82,6);cout<<"|    |_______";
    gotoxy(82,7);cout<<"|            |";
    gotoxy(82,8);cout<<"|     _______|";
    gotoxy(82,9);cout<<"|    |__________";
    gotoxy(82,10);cout<<"|               |";
    gotoxy(82,11);cout<<"|               |";
    gotoxy(82,12);cout<<"|_______________|";

    gotoxy(99,2);cout<<" _________________";
    gotoxy(99,3);cout<<"|                |";
    gotoxy(99,4);cout<<"|  _________|    |";
    gotoxy(99,5);cout<<"|  |        |____|";
    gotoxy(99,6);cout<<"|  |_____________";
    gotoxy(99,7);cout<<"|               |";
    gotoxy(99,8);cout<<"|___________    |";
    gotoxy(99,9);cout<<"           |    |";
    gotoxy(99,10);cout<<"|-----|____|    |";
    gotoxy(99,11);cout<<"|               |";
    gotoxy(99,12);cout<<"|_______________|";

    gotoxy(17,15); cout << "TOP PLAYERS";
    gotoxy(40,15); cout << "ADDITION";
    gotoxy(52,15); cout << "SUBTRACTION";
    gotoxy(67,15); cout << "MULTIPLICATION";
    gotoxy(86,15); cout << "DIVISION";
    gotoxy(100,15); cout << "AVERAGE";
    while (cur!=NULL){
        cur->average = average(cur->Sadd, cur->Ssub, cur->Smul, cur->Sdiv);
            gotoxy(15,16+i); cout << i << ".)";
            gotoxy(20,16+i); cout << cur->username;
            gotoxy(43,16+i); cout << cur->Sadd;
            gotoxy(56,16+i); cout << cur->Ssub;
            gotoxy(73,16+i); cout << cur->Smul;
            gotoxy(89,16+i); cout << cur->Sdiv;
            gotoxy(100,16+i); cout <<fixed<<setw(6)<<setprecision(2)<< cur->average <<"%";
        cur = cur->next; i++;
    }
    gotoxy(30, 28); system("pause");
}


void Player::account(string un, string pw){
    border();
    int loc = locate(un);
    MPRAC  *pre, *cur, *newNode;
    cur=pre=head;
    newNode = new MPRAC;
    newNode->username = un;
    newNode->password = pw;
    newNode->Sadd = 0;
    newNode->Ssub = 0;
    newNode->Smul = 0;
    newNode->Sdiv = 0;
    newNode->average = 0.0;
    newNode->next = NULL;
    user = un;
    if (loc>=0){
        gotoxy(40,15); cout <<"THIS ACCOUNT ALREADY EXIST.";
        gotoxy(40,20); system("pause");
    } else {
        while (cur!=NULL && cur->username<un){
            pre = cur;
            cur = cur->next;
        }
        if (head==cur){
            head = newNode;
        } else {
            pre->next = newNode;
            newNode->next = cur;
        }
    }
}


void Player::log(string un, string pw){
    border();
    int select, up;
    MPRAC  *pre, *cur;
    cur=pre=head;
    up = upass(un, pw);
    while (cur!=NULL){
        pre = cur;
        if (up>=0){
            gotoxy(40,15); cout <<"USERNAME AND PASSWORD IS CORRECT.";
            gotoxy(40,17); system("pause");
            while(true){
                select = game();
                switch(select){
                    case 1: level=1; Addition(); break;
                    case 2: level=1; Subtraction(); break;
                    case 3: level=1; Multiplication(); break;
                    case 4: level=1; Division(); break;
                    case 5: leaderboard(); break;
                    case 6: save(); exit(0); break;
                    default: gotoxy(40,15); cout <<"Choose between 1 to 6 ONLY.";
                             gotoxy(40,16); system("pause"); break;
                }
            }
        } else {
            cur = cur->next;
        }
    }
    if (isEmpty()){
        gotoxy(40,15); cout <<"ACCOUNT DOES NOT EXIST.";
        gotoxy(40,17); system("pause");
    } else {
        gotoxy(40,15); cout <<"MISMATCHED CREDENTIALS. TRY AGAIN.";
        gotoxy(40,17); system("pause");
    }

}


void Player::points(int a, int s, int m, int d){
    MPRAC *cur;
    cur = head;
    int i=0;
    int pos = locate(user);
    if (pos!=0){
        while (cur!=NULL && i!=pos){
            i++; cur = cur->next;
        }
    }
    cur->Sadd = a;
    cur->Ssub = s;
    cur->Smul = m;
    cur->Sdiv = d;
}


float Player::average(int a, int s, int m, int d){
    return ((a+s+m+d)/4.0);
}


//***********************************************************************************PUBLIC METHODS
void Player::initial(){
    head = NULL;
}


void Player::Addition(){
    border();
    MPRAC *cur;
    cur = head;
    int i, a, b, c, ans, pos;
    int j=0, total=0;
    float ave;
    do{
        items = GetItems();
        ctr = 0;
        for (i=0; i<items; i++){
            system("cls");
            border();
            gotoxy(30,2);cout <<"========================================================";
            gotoxy(30,3);cout <<"|                  Welcome to ADDITION                 |";
            gotoxy(30,4);cout <<"========================================================";
            gotoxy(30,5);cout <<"|                                                      |";
            gotoxy(30,6);cout <<"|       Math operation in which we add the numbers     |";
            gotoxy(30,7);cout <<"|               together to get their sum.             |";
            gotoxy(30,8);cout <<"========================================================";
            a = rand()% (level*10)+1;
            b = rand()% (level*10)+1;
            ans = a+b;
            Score();
            gotoxy(40,10); cout <<i+1<<".) What is "<<a<<" + "<<b<<" ? ";
            cin >> c;
            total = checker(c,ans);
        }
        ave = (float)total/items*100;
        pos = locate(user);
        if (pos!=0){
            while (cur!=NULL && j!=pos){
                j++; cur = cur->next;
            }
        }
        cur->Sadd = (int)ave;
        gotoxy(35, 17); cout <<">>> Final Average Score: "<<fixed<<setw(6)<<setprecision(2)<<ave<<"% <<<"<<endl;
        gotoxy(35, 28); system("pause");
    } while (menu2()!=1);
}


void Player::Subtraction(){
    border();
    MPRAC *cur;
    cur = head;
    int i, a, b, c, ans, pos;
    int j=0, total=0;
    float ave;
    do {
        items = GetItems();
        ctr = 0;
        for (i=0; i<items; i++){
            system("cls");
            border();
            gotoxy(30,2);cout <<"========================================================";
            gotoxy(30,3);cout <<"|                 Welcome to SUBTRACTION               |";
            gotoxy(30,4);cout <<"========================================================";
            gotoxy(30,5);cout <<"|                                                      |";
            gotoxy(30,6);cout <<"|      an arithmetic operation that represents the     |";
            gotoxy(30,7);cout <<"|    operation of removing objects from a collection.  |";
            gotoxy(30,8);cout <<"========================================================";
            a = rand()% (level*10)+1;
            b = rand()% (level*10)+1;
            while(a < b){
                srand(time(NULL));
                a = rand()% (level*10)+1;
                b = rand()% (level*10)+1;
            }
            ans = a-b;
            Score();
            gotoxy(40,10); cout <<i+1<<".) What is "<<a<<" - "<<b<<" ? ";
            cin >> c;
            total = checker(c,ans);
        }
        ave = (float)total/items*100;
        pos = locate(user);
        if (pos!=0){
            while (cur!=NULL && j!=pos){
                j++; cur = cur->next;
            }
        }
        cur->Ssub = (int)ave;
        gotoxy(35, 17); cout <<">>> Final Average Score: "<<fixed<<setw(6)<<setprecision(2)<<ave<<"% <<<"<<endl;
        gotoxy(35, 28); system("pause");
    } while (menu2()!=1);
}


void Player::Multiplication(){
    border();
    MPRAC *cur;
    cur = head;
    int i, a, b, c, ans, pos;
    int j=0, total=0;
    float ave;
    do {
        items = GetItems();
        ctr = 0;
        for (i=0; i<items; i++){
            system("cls");
            border();
            gotoxy(30,2);cout <<"========================================================";
            gotoxy(30,3);cout <<"|               Welcome to MULTIPLICATION              |";
            gotoxy(30,4);cout <<"========================================================";
            gotoxy(30,5);cout <<"|                                                      |";
            gotoxy(30,6);cout <<"|            when you take one number and add          |";
            gotoxy(30,7);cout <<"|             it together a number of time             |";
            gotoxy(30,8);cout <<"========================================================";
            a = rand() % (level*5) + 1;
            b = rand() % (level*5) + 1;
            ans = a*b;
            Score();
            gotoxy(40,10); cout <<i+1<<".) What is "<<a<<" x "<<b<<" ? ";
            cin >> c;
            total = checker(c,ans);
        }
        ave = (float)total/items*100;
        pos = locate(user);
        if (pos!=0){
            while (cur!=NULL && j!=pos){
                j++; cur = cur->next;
            }
        }
        cur->Smul = (int)ave;
        gotoxy(35, 17); cout <<">>> Final Average Score: "<<fixed<<setw(6)<<setprecision(2)<<ave<<"% <<<"<<endl;
        gotoxy(35, 28); system("pause");
    } while (menu2()!=1);
}


void Player::Division(){
    border();
    MPRAC *cur;
    cur = head;
    int i, a, b, c, ans, rem,opA, pos;
    int j=0, total=0;
    float ave;
    do{
        items = GetItems();
        ctr = 0;
        for (i=0; i<items; i++){
            system("cls");
            border();
            gotoxy(30,2);cout <<"========================================================";
            gotoxy(30,3);cout <<"|                 Welcome to DIVISION                  |";
            gotoxy(30,4);cout <<"========================================================";
            gotoxy(30,5);cout <<"|                                                      |";
            gotoxy(30,6);cout <<"| the action of separating something into parts or the |";
            gotoxy(30,7);cout <<"|                 process of being separated.          |";
            gotoxy(30,8);cout <<"========================================================";
            a = rand() % (level*25) + 1;
            b = rand() % (level*10) + 1;
            rem=a%b;
            opA=a-rem;
            ans = opA/b;
            Score();
            gotoxy(40,10); cout <<i+1<<".) What is "<<opA<<" / "<<b<<" ? ";
            cin >> c;
            total = checker(c,ans);
        }
        ave = (float)total/items*100;
        pos = locate(user);
        if (pos!=0){
            while (cur!=NULL && j!=pos){
                j++; cur = cur->next;
            }
        }
        cur->Sdiv = (int)ave;
        gotoxy(35, 17); cout <<">>> Final Average Score: "<<fixed<<setw(6)<<setprecision(2)<<ave<<"% <<<"<<endl;
        gotoxy(35, 28); system("pause");
    } while (menu2()!=1);
}


void Player::sign(){
    system("cls");
    border();
    string username, password;
    gotoxy(30,2); cout <<"========================================================";
    gotoxy(30,3); cout <<"|                        SIGN UP                       |";
    gotoxy(30,4); cout <<"========================================================";
    gotoxy(40,6); cout <<"ENTER USERNAME: "; cin.ignore(); getline(cin, username);
    gotoxy(40,7); cout <<"ENTER PASSWORD: "; cin >> password;
    account(username, password);
}


void Player::entry(){
    system("cls");
    border();
    string username, password;
    gotoxy(30,2);cout <<"========================================================";
    gotoxy(30,3);cout <<"|                        LOG IN                        |";
    gotoxy(30,4);cout <<"========================================================";
    gotoxy(45,6);cout <<"USERNAME: "; cin.ignore(); getline(cin, username);
    gotoxy(45,7);cout <<"PASSWORD: "; cin >> password;
    user = username;
    log(username, password);
}


void Player::retrieve(){
    fstream fp;
    fp.open("LinkedList_PlayerScores.dbf", ios::in);
    if (!fp){
        gotoxy(50, 14); printf("CREATING USER LOG FILE");
        for(int i = 0; i<67; i++){
            Sleep(10);
            gotoxy(26+i, 13); printf("%c", 254);
        }
        gotoxy(46, 14); system("pause");
    } else {
        string un, pw;
        int add, sub, mul, div;
        while(true){
            getline(fp, un);
            getline(fp, pw);
            fp >> add;
            fp >> sub;
            fp >> mul;
            fp >> div;
            fp.ignore();
            if (!fp.eof()){
                account(un, pw);
                points(add, sub, mul, div);
            } else
                break;
        }
    }
    fp.close();
}


void Player::save(){
    fstream fp;
    MPRAC *x;
    x = head;
    fp.open("LinkedList_PlayerScores.dbf", ios::out);
    if (!fp){
        gotoxy(40, 10); cout << "FILE ERROR.";
        gotoxy(40, 12); system("pause");
    } else {
        while (x!=NULL){
            fp << x->username << endl;
            fp << x->password << endl;
            fp << x->Sadd << endl << x->Ssub << endl << x->Smul << endl << x->Sdiv << endl;
            x = x->next;
        }
    }
    fp.close();
    system("cls");
    gotoxy(35, 15); cout << "File successfully saved as LinkedList_PlayerScores.dbf" << endl;
    gotoxy(35, 16); cout << "======================================================" << endl;
}



//*****************************************************************************************FUNCTIONS
int menu(){
    int i, select;
    system("cls");
    border();

    gotoxy(30,4);cout<<"        ______";
    gotoxy(30,5);cout<<"       |      |";
    gotoxy(30,6);cout<<"       |      |";
    gotoxy(30,7);cout<<" ______|      |_______";
    gotoxy(30,8);cout<<"|                     | ";
    gotoxy(30,9);cout<<"|______        _______|";
    gotoxy(30,10);cout<<"       |      |";
    gotoxy(30,11);cout<<"       |      |";
    gotoxy(30,12);cout<<"       |______|";

    gotoxy(48,4);cout<<" __________________ ";
    gotoxy(48,5);cout<<"|                  |";
    gotoxy(48,6);cout<<"|__________________|";

    gotoxy(53,7);cout<<" _____     _____";
    gotoxy(53,8);cout<<"|     |   |     |";
    gotoxy(53,9);cout<<"|     \\___/     |";
    gotoxy(53,10);cout<<" \\             /";
    gotoxy(53,11);cout<<" /     ___     \\";
    gotoxy(53,12);cout<<"|     /   \\     |";
    gotoxy(53,13);cout<<"|_____|   |_____|";

    gotoxy(70,5);cout<<"       _______";
    gotoxy(70,6);cout<<"      /      /";
    gotoxy(70,7);cout<<"     /      /";
    gotoxy(70,8);cout<<"    /      /";
    gotoxy(70,9);cout<<"   /      /";
    gotoxy(70,10);cout<<"  /      /";
    gotoxy(70,11);cout<<" /      /";
    gotoxy(70,12);cout<<"/______/";

    string opt[] = {"Sign Up","Log In","EXIT"};
    gotoxy(30,15);cout <<"========================================================";
    gotoxy(30,16);cout <<"|            WELCOME TO ARITHMETIC PRACTICE            |";
    gotoxy(30,17);cout <<"|  where you could test your Math Skills in Addition,  |";
    gotoxy(30,18);cout <<"|        Subtraction, Multiplication, Division         |";
    gotoxy(30,19);cout <<"========================================================";
    for (i=0;i<3;i++){
        gotoxy(45, 21+i); cout <<i+1<<".) "<<opt[i];
    }
    gotoxy(50, 22+i); cout <<"Select (1-3): "; cin >> select;
    return select;
}


int main()
{
    int select;
    system("COLOR 0B");
    Player stud;
    stud.initial();
    stud.retrieve();
    srand(time(NULL));
    while(true){
        select = menu();
        switch(select){
            case 1: stud.sign(); break;
            case 2: stud.entry(); break;
            case 3: exit(0);
            default: gotoxy(40,18); cout <<"Choose between 1 to 3 ONLY.";
                     gotoxy(40,19); system("pause");
        }
    }
    return 0;
}
