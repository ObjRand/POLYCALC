#include <iostream>
#include <conio.h>
#include <iomanip>
#include <time.h>
#include <string>
#include <stdlib.h>


using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_X 120
#define KEY_e 101
#define KEY_E 69
#define KEY_b 98
#define KEY_B 66
#define KEY_a 97
#define KEY_A 65

//Variables:

//MENU VARS

int choicecalcmenu = 0;

bool nomainmenuloop = false;

string curtime;

//CALC VARS

int nos = 3;

int extangle;

int intangle;

int noscalc;

int sumextangle = 360;

int sumintangle;

int noslimitnum;

//DEBUG (ERROR) VARS

string isentererrordebug = "n";

bool debugmode = false;

bool errordebug = false;

//UTIL VARS

string textcolorvar;

string titlevar;

//MINIGAME VARS
int randomint = rand() % 10 + 1;

char key;
int value;
int code;
bool epressed = false;
int loopmini = 0;
int randomextlist[7] = { 10,20,30,40,60,90,120 };
int randomext;
int randomnoslist[20] = { 2,3,4,5,6,8,9,10,12,15,18,20,24,30,36,40,45,60,72,90 };
int randomnos;
int minisum1;
int minisum2;
int minisum3;
bool minigame1win;
bool minigame2win;
bool minigame3win;
int minigameguessone;
int minigameguesstwo;
int minigameguessthree;

// Declairing Functions:

// calculation running function.
void calculation();

// clear screen.
void cls();

// pause screen.
void pause(string ispausenull);

// ERROR MESSAGE.
void error(int errorcode);

// TITLE FUNC.
void title(string currenttitle);

//Sleep Func
void sleep(int sleeptime);

// Get A random element from an int array.
int RandomIntElement(int* array, int size);

// Main Menu For PolyCalc
void mainmenu();

// Entering Error Debugger.
void entererrordebug();

//Colored Text Func.
void textcolor(string currenttextcolor);

//Calc Funcs Declairs
void sumofextangle();

void sumofintangle();

void calcofextangle();

void calcofintangle();

void calcofnos();

//Minigame Funcs

void konamicode();

void minigames();

void minigame1();

void minigame2();

void minigame3();

void randomextangle();

void randomnumos();

void gameresult();


// Function Content.


// MAIN FUNC
int main() {
    title("PolyCalc");
    cls();
    //DEBUG = TRUE check
    if (debugmode == true) {
        entererrordebug();
    }
    else {
        mainmenu();
    }
}

void entererrordebug() {
    cls();
    //Error Debug Choice Menu
    cout << "enter error debug? (y/n) \n"
        << "> ";
    cin >> isentererrordebug;
    //IF isentererrordebug == Y/N THEN TRUE/FALSE
    if (isentererrordebug == "y") {
        errordebug = true;
    }
    if (isentererrordebug == "n") {
        errordebug = false;
    }
    if (errordebug == true) {
        error(404);
    }
    if (errordebug == false) {
        mainmenu();
    }
}

void mainmenu() {
    cls();
    //RESETTING THE MENU CHOICE
    choicecalcmenu = 0;
    //MAIN MENU

    cout << "Welcome To PolyCalc!\n";
    cout << "\nWhat Calculation Do You Want To Use?\n\n";
    cout << "1) Sum Of External Angles Of A Regular. (Angles Must Be All Equal!) EQ: 360.\n";
    cout << "2) Sum Of Internal Angles Of A Regular. (Angles Must Be All Equal!) EQ: 180 * (number of sides - 2).\n";
    cout << "3) One External Angle From Your Polygon.(Number Of Sides: Needed!)  EQ: 360 / number of sides.\n";
    cout << "4) One Internal Angle From Your Polygon.(External Angle: Needed!)   EQ: 180 - external angle.\n";
    cout << "5) Number Of Sides From Your Polygon.   (External Angle: Needed!)   EQ: 360 / external angle.\n";
    cout << "-> ";
    cin >> choicecalcmenu;
    cls();
    //Go To The Calcs (if you want to add more options on the menu, also make sure to make the if statement to "choicecalcmenu < number of menu items + 1".
    if (choicecalcmenu < 6) {
        nomainmenuloop = true;
        calculation();
    }
    else if (choicecalcmenu > 6) {
        //THATS NOT A CHOICE ERROR
        error(1403);
    }
    //Checks for no loop
    if (choicecalcmenu == 0 && nomainmenuloop == false) {
        choicecalcmenu = 0;
        mainmenu();
    }
    //Checks For NUM 6 in input
    if (choicecalcmenu == 6) {
        konamicode();
    }
}

void calculation()
{
    cls();
    switch (choicecalcmenu) {
        case 1:
            sumofextangle();
            break;
        case 2:
            sumofintangle();
            break;
        case 3:
            calcofextangle();
            break;
        case 4:
            calcofintangle();
            break;
        case 5:
            calcofnos();
            break;
    }
}


// Calc Funcs
void sumofextangle() {
    // The Equation.
    sumextangle = 360;
    cout << "External angle sum (of a regular polygon) is always:\n" << sumextangle << endl;
    _getch();
    main();
}

void sumofintangle() {
    cout << "What Is The Number Of Sides In Your Polygon?\n";
    cin >> nos;
    cls();

    //Check for errors
    if (nos <= 2)
        error(2450);
    else if (nos > 180)
        error(2450);

    // The Equation.
    sumintangle = 180 * (nos - 2);
    cout << "Internal angle sum (of a regular polygon) is:\n" << sumintangle << endl;
    _getch();
    main();
}

void calcofextangle() {
    cout << "What Is The Number Of Sides In Your Polygon?\n";
    cin >> nos;
    cls();

    //Check for errors
    if (nos <= 2)
        error(2450);
    else if (nos > 180)
        error(2450);

    // The Equation.
    extangle = 360 / nos;
    cout << "One external angle of your regular polygon is:\n" << extangle << endl;
    _getch();
    main();
}

void calcofintangle() {
    cout << "What Is The External Angle In Your Polygon?\n";
    cin >> extangle;
    cls();

    //Check for errors
    if (extangle == 0)
        error(2450);
    else if (extangle > 180)
        error(2450);

    // The Equation.
    intangle = 180 - extangle;
    cout << "One internal angle of your regular polygon is:\n" << intangle << endl;
    _getch();
    main();
}

void calcofnos() {
    cout << "What Is The External Angle In Your Polygon?\n";
    cin >> extangle;
    cls();

    //Check for errors
    if (extangle == 0)
        error(2450);
    else if (extangle > 180)
        error(2450);

    // The Equation.
    noscalc = 360 / extangle;
    cout << "The Number Of Sides of your polygon is:\n" << noscalc << endl;
    _getch();
    main();
}


//Minigame Funcs
void minigames() {
    string minigamename = "default";
    loopmini = 0;
    while (loopmini < 5) {
        loopmini++;
        /* initialize random seed: */
        srand(time(NULL));
        randomint = rand() % 3 + 1;
        cls();
        switch (randomint) {
        case 1:
            minigamename = "Guess The Number Of Sides!";
            break;
        case 2:
            minigamename = "Guess The External Angle!";
            break;
        case 3:
            minigamename = "Guess The Internal Angle!";
            break;
        }
        switch (loopmini) {
        case 0:
            cls();
            cout << "Randomly choosing minigames:\n\n" << "loading in";
            break;
        case 1:
            cls();
            cout << "Randomly choosing minigames:\n\n" << "loading in.";
            break;
        case 2:
            cls();
            cout << "Randomly choosing minigames:\n\n" << "loading in..";
            break;
        case 3:
            cls();
            cout << "Randomly choosing minigames:\n\n" << "loading in...";
            break;
        case 4:
            cls();
            cout << "Randomly choosing minigames:\n\n" << "loading in";
            break;
        case 5:
            cls();
            cout << "Your Minigame is: " << minigamename;
            pause("null");
            if (randomint == 1)
                minigame1();
            else if (randomint == 2)
                minigame2();
            else if (randomint == 3)
                minigame3();
            else if (randomint <= 4)
                break;
        }
        sleep(1);
    }
}

//guess the nos of the polygon with the ext angle
void minigame1() {
    cls();
    randomextangle();

    cout << "Guess the nos of this polygon with the external angle. \n\nExternal angle: " << randomext << "\n\n";
    cout << "->";
    cin >> minigameguessone;
    minisum1 = 360 / randomext;
    if (minigameguessone == minisum1) {
        minigame1win = true;
        gameresult();
    }
    else {
        minigame1win = false;
        gameresult();
    }
}

//guess the nos of the polygon with the ext angle
void minigame2() {
    cls();
    randomnumos();

    cout << "Guess the external angle of this polygon with the number of sides. \n\nNumber of sides: " << randomnos << "\n\n";
    cout << "->";
    cin >> minigameguesstwo;
    minisum2 = 360 / randomnos;
    if (minigameguesstwo == minisum2) {
        minigame2win = true;
        gameresult();
    }
    else {
        minigame2win = false;
        gameresult();
    }
}

//guess the int angle of the polygon with the ext angle
void minigame3() {
    cls();
    randomnumos();

    cout << "Guess the internal angle of this polygon with the number of sides. \n\nExternal angle: " << randomext << "\n\n";
    cout << "->";
    cin >> minigameguessthree;
    minisum3 = 180 - randomnos;
    if (minigameguessthree == minisum3) {
        minigame3win = true;
        gameresult();
    }
    else {
        minigame3win = false;
        gameresult();
    }
}


// Gives Irregular Values (MUST FIX)
void randomextangle() {
    loopmini = 0;
    srand(time(NULL));
    while (loopmini < 10) {
        loopmini++;
        randomext = RandomIntElement(randomextlist, 7);
    }
}

void randomnumos() {
    loopmini = 0;
    srand(time(NULL));
    while (loopmini < 10) {
        loopmini++;
        randomnos = RandomIntElement(randomnoslist, 7);
    }
}

void gameresult() {
    cls();
    if (minigame1win || minigame2win || minigame3win){
        cout << "You WON!!!";
        pause("null");
    }
    else{
        cout << "You Lost...";
        pause("null");
    }
    mainmenu();
}

void konamicode() {
    code = 0;
    string codestring = "";
    while (code != 10) {
        cls();
        cout << codestring << "\n\n";
        switch (_getch()) {
        case KEY_UP:
            if (code == 1)
                code = 2;
            if (code == 0)
                code = 1;
            if (code == 3)
                code = 0;
            break;
        case KEY_DOWN:
            if (code == 3)
                code = 4;
            if (code == 2)
                code = 3;
            if (code == 5)
                code = 0;
            break;
        case KEY_LEFT:
            if (code == 6)
                code = 7;
            if (code == 4)
                code = 5;
            if (code == 8)
                code = 0;
            break;
        case KEY_RIGHT:
            if (code == 7)
                code = 8;
            if (code == 5)
                code = 6;
            if (code == 9)
                code = 0;
            break;
        case KEY_b:
            if (code == 8)
                code = 9;
            if (code == 10)
                code = 0;
            break;
        case KEY_a:
            if (code == 9)
                code = 10;
            if (code == 10)
                break;
        case KEY_B:
            if (code == 8)
                code = 9;
            if (code == 10)
                code = 0;
            break;
        case KEY_A:
            if (code == 9)
                code = 10;
            if (code == 10)
                break;
        }
        switch (code) {
        case 0:
            codestring = "";
            break;
        case 1:
            codestring = "*";
            break;
        case 2:
            codestring = "**";
            break;
        case 3:
            codestring = "***";
            break;
        case 4:
            codestring = "****";
            break;
        case 5:
            codestring = "*****";
            break;
        case 6:
            codestring = "******";
            break;
        case 7:
            codestring = "*******";
            break;
        case 8:
            codestring = "********";
            break;
        case 9:
            codestring = "*********";
            break;
        case 10:
            codestring = "**********";
            break;
        }
    }

    if (code == 10) {
        cls();
        minigames();
    }
}

// Util Functions
void cls() {
    system("cls");
}

void pause(string ispausenull) {
    if (ispausenull == "null") {
        system("pause >nul");
    }
    else if (ispausenull == "") {
        system("pause");
    }
}

int RandomIntElement(int* array, int size)
{
    return array[rand() % size];
}

void error(int errorcode) {
    //TESTING ERRORS IN POLYCALC
    cls();
    switch (errorcode) {
        case 404:
            cout << "ERROR CODE: DEBUG FOR ERRORS\n";
            break;
        case 1403:
            cout << "ERROR CODE 1403: Thats Not A Choice\n";
            break;
        case 2450:
            cout << "ERROR CODE 2450: The Input Number Cant Be Used For The Operation\n";
            break;
    }
    errorcode = 0;
    pause("null");
    main();
}

void title(string currenttitle) {
    titlevar = "title " + currenttitle;
    const char* titlevarconst = titlevar.c_str();

    system(titlevarconst);
}

void textcolor(string currenttextcolor) {
    textcolorvar = "Color " + currenttextcolor;
    const char* textcolorconst = textcolorvar.c_str();
    system(textcolorconst);
}

void sleep(int sleeptime) {
    string sleeptimevar;
    string sleeptimestring = to_string(sleeptime);
    sleeptimevar = "timeout /t " + sleeptimestring + " /nobreak > NUL";
    const char* sleeptimeconst = sleeptimevar.c_str();
    system(sleeptimeconst);
}