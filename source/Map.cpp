#include <SDL_image.h>
#include "headers/Map.h"
#include "headers/game.h"
#include <array>
int testMap[32][18]={0};


Map::Map() {
    dirt =  Game::loadTexture("../../media/sprites/dirt.png");
    grass = Game::loadTexture("../../media/sprites/grass.png");
    water = Game::loadTexture("../../media/sprites/water.png");

    //test
    for(int i=7; i<32; i++) {
        for(int j=4; j<11; j++){
            testMap[i][j]=1;
        }
        for(int j=13; j<18; j++){
            testMap[i][j]=2;
        }
    }//test

    loadMap(testMap);

    src.x = 0;
    src.y = 0;
    src.w = 20;
    src.h = 20;

    dest.w = src.w*2;
    dest.h = src.h*2;
    dest.x=0;
    dest.y=0;
}

Map::~Map() = default;

void Map::loadMap(int arr[32][18]) {
    for( int row=0; row< 32; row++){
        for( int col=0; col< 18; col++){
            matrix[row][col]=arr[row][col];
        }
    }
}

void Map::drawMap() {
    int type = 0;

    for( int row=0; row< 32; row++){
        for( int col=0; col< 18; col++){
            type=matrix[row][col];
            dest.x=row*40;
            dest.y=col*40;
            switch (type){
                case 0:
                    Game::simpleDraw(water, src, dest);
                    break;
                case 1:
                    Game::simpleDraw(grass, src, dest);
                    break;
                case 2:
                    Game::simpleDraw(dirt, src, dest);
                    break;
            }
        }
    }
}
