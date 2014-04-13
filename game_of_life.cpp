#include <iostream>


int main(){

char LIVE = '*';
char DEAD = ' ';

char world[22][80];
char tempWorld[22][80];

for(int row = 0; row < 22; row++){
    for (int col = 0; col < 80; col++){
        world[row][col] = DEAD;
    }
}

//blinker
world[5][20] = LIVE;
world[5][21] = LIVE;
world[5][19] = LIVE;

//beacon
world[10][40] = LIVE;
world[10][41] = LIVE;
world[9][40] = LIVE;
world[9][41] = LIVE;
world[11][42] = LIVE;
world[11][43] = LIVE;
world[12][42] = LIVE;
world[12][43] = LIVE;

//glider
world[3][70] = LIVE;
world[4][70] = LIVE;
world[5][70] = LIVE;
world[5][69] = LIVE;
world[4][68] = LIVE;

for(int row = 0; row < 22; row++){
    for (int col = 0; col < 80; col++){
        std::cout << world[row][col];
    }
}

for(int g = 0; g < 30; g++){

//neighbors
for(int row = 0; row < 22; row++){
    for (int col = 0; col < 80; col++){
        int neighbors = 0;
        if(world[row][col-1] == LIVE){
            neighbors++;
        }
        if(world[row][col+1] == LIVE){
            neighbors++;
        }
        if(world[row-1][col-1] == LIVE){
            neighbors++;
        }
        if(world[row-1][col+1] == LIVE){
            neighbors++;
        }
        if(world[row-1][col] == LIVE){
            neighbors++;
        }
        if(world[row+1][col] == LIVE){
            neighbors++;
        }
        if(world[row+1][col-1] == LIVE){
            neighbors++;
        }
        if(world[row+1][col+1] == LIVE){
            neighbors++;
        }

        tempWorld[row][col]= DEAD;

        if(world[row][col] == LIVE && neighbors < 2){
            tempWorld[row][col] = DEAD;
        }
        else if(world[row][col] == LIVE && neighbors > 3){
            tempWorld[row][col] = DEAD;
        }
        else if(world[row][col] == LIVE && (neighbors >= 2 && neighbors <= 3)){
            tempWorld[row][col] = LIVE;
        }
        else if(world[row][col] == DEAD && neighbors == 3){
            tempWorld[row][col] = LIVE;
        }
}

}

for(int row = 0; row < 22; row++){
    for (int col = 0; col < 80; col++){
        world[row][col] = tempWorld[row][col];
    }
}

for(int row = 0; row < 22; row++){
    for (int col = 0; col < 80; col++){
        std::cout << world[row][col];
    }
}

}

return 0;
}
