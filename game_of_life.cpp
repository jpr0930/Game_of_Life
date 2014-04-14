/*Author: Jason Robel
*Created: 4/11/14
*Modified: 4/13/14
*assign1.cpp
*
*Overview
*   Command line reproduction of Conway's Game of Life in C++. User defines
*number of generations(life-cycles) as well as up to 12 starting positions.
*
*Input
*   User selects up to 12 starting positions and the number of generations desired.
*User may abort at any time, or press any key to continue through generations.
*Output
*   World is first displayed revealing user defined starting configuration. Subsequent
*displays account for new generations after the rules are applied to LIVE and DEAD cells.
*/

#include <iostream>
#include <cstdlib>

//Function prototypes
int getCell(int x);
int userRow(int x);
int userCol(int x);

int main(int argc, char* argv[]){

//Constant int variables for row and column number.
const int row = 22;
const int col = 80;

//Additional rows and columns to stop life forms leaving the edges from wrapping.
int ghostRow = 34;
int ghostCol = 90;

//Constant char variables to represent live and dead cells.
const char LIVE = '*';
const char DEAD = ' ';

/*Declare world and temporary world array. Temp array will aid in updating
*display with each generation.
*/
char world[ghostRow][ghostCol];
char tempWorld[ghostRow][ghostCol];

//Initialize all cells in world array to DEAD.
for(int r = 0; r < ghostRow; r++){
    for (int c = 0; c < ghostCol; c++){
        world[r][c] = DEAD;
    }
}

int startConfig[10][2]; //Declare starting configuration to hold user input.
int cellNum; //Holds user input for number of cells to enter; limited to 12.

//Row and column choices by user.
int rowChoice;
int colChoice;

//User selects number of starting cells desired.
std::cout << "How many cells would you like to enter?: " << std::endl;
std::cin >> cellNum;
cellNum = getCell(cellNum);

//User chooses individual cells by row and column.
for(int i = 0; i < cellNum; i++){
    std::cout << "Please enter a row number for cell " << i + 1 << ": " << std::endl;
    std::cin >> rowChoice;
    rowChoice = userRow(rowChoice); //Check user input.
    startConfig[i][0] = rowChoice; //set user input.

    std::cout << "Please enter a column number for cell " << i + 1 << ": " << std::endl;
    std::cin >> colChoice;
    colChoice = userCol(colChoice); //Check user input.
    startConfig[i][1] = colChoice; //Set user input.
}

//Initialize world with user chosen positions.
for(int i = 0; i < cellNum; i++){
    world[startConfig[i][0]][startConfig[i][1]] = LIVE;
}

//Initial print of world using const ints for row and col to keep within range of screen.
std::cout << "Here is your beginning configuration: " << std::endl;
for(int r = 0; r < row; r++){
    for (int c = 0; c < col; c++){
        std::cout << world[r][c];
    }
}

//Main loop for parameter and rule checking, printing modified world, cycling generations.
char nextGen;
do{
    //Loop to check neighbor and rules conditions.
    for(int r = 0; r < ghostRow; r++){
        for (int c = 0; c < ghostCol; c++){

            int neighbors = 0; //Tracks neighbor conditions for application of rules.

            //Apply neighbor conditions.
            if(world[r][c-1] == LIVE){
                neighbors++;
            }
            if(world[r][c+1] == LIVE){
                neighbors++;
            }
            if(world[r-1][c-1] == LIVE){
                neighbors++;
            }
            if(world[r-1][c+1] == LIVE){
                neighbors++;
            }
            if(world[r-1][c] == LIVE){
                neighbors++;
            }
            if(world[r+1][c] == LIVE){
                neighbors++;
            }
            if(world[r+1][c-1] == LIVE){
                neighbors++;
            }
            if(world[r+1][c+1] == LIVE){
                neighbors++;
            }

            tempWorld[r][c]= DEAD; //Initialize tempWorld array to all DEAD.

            //Apply rules accounting for neighbor count.
            if(world[r][c] == LIVE && neighbors < 2){
                tempWorld[r][c] = DEAD;
            }
            else if(world[r][c] == LIVE && neighbors > 3){
                tempWorld[r][c] = DEAD;
            }
            else if(world[r][c] == LIVE && (neighbors >= 2 && neighbors <= 3)){
                tempWorld[r][c] = LIVE;
            }
            else if(world[r][c] == DEAD && neighbors == 3){
                tempWorld[r][c] = LIVE;
            }
        }
    }

    //Loop to align world and tempWorld values.
    for(int r = 0; r < ghostRow; r++){
        for (int c = 0; c < ghostCol; c++){
        world[r][c] = tempWorld[r][c];
        }
    }

    //Print updated world.
    for(int r = 0; r < row; r++){
        for (int c = 0; c < col; c++){
        std::cout << world[r][c];
        }
    }

std::cout << "Press 'y' to cycle next generation or any other key to exit." << std::endl;
std::cin >> nextGen;
std::cout << std::endl;

}while(nextGen == 'y');

std::cout << "Goodbye. Thanks for playing God..." << std::endl;

return 0;
}

//Function to error-handle user input for number of cells.
int getCell(int x){

while(!(x) || x < 1 || x > 12){
    std::cout << "Invalid choice. Please choose a number 1-12." << std::endl;
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    std::cin >> x;
}
std::cin.clear();
std::cin.ignore(1000, '\n');
return x;
}

//Function to error-handle user input for row selections in starting configuration.
int userRow(int x){

while(!(x) || x < 0 || x > 22){
    std::cout << "Invalid choice. Please choose a number 0-21." << std::endl;
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    std::cin >> x;
}
std::cin.clear();
std::cin.ignore(1000, '\n');
return x;
}

//Function to error-handle user input in column selection for starting configuration.
int userCol(int x){

while(!(x) || x < 0 || x > 80){
    std::cout << "Invalid choice. Please choose a number 0-21." << std::endl;
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    std::cin >> x;
}
std::cin.clear();
std::cin.ignore(1000, '\n');
return x;
}

/*
Test patterns.

blinker
world[5][20] = LIVE;
world[5][21] = LIVE;
world[5][19] = LIVE;

beacon
world[10][40] = LIVE;
world[10][41] = LIVE;
world[9][40] = LIVE;
world[9][41] = LIVE;
world[11][42] = LIVE;
world[11][43] = LIVE;
world[12][42] = LIVE;
world[12][43] = LIVE;

glider
world[3][70] = LIVE;
world[4][70] = LIVE;
world[5][70] = LIVE;
world[5][69] = LIVE;
world[4][68] = LIVE;
*/
