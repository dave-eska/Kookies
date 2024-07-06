#include "tile.h"

#include <fstream>

#include <raylib.h>

#include <json/json.h>
#include <string>

bool Tile::hasAnimation(){
    return texture.width / 32 > 1;
}

void Tile::Update(){
}

void Tile::Draw(){
    if(animationOnDefault){
        DrawSpriteAnimationPro(animation, {body.x, body.y, TILE_SIZE, TILE_SIZE}, {0, 0}, 0, WHITE);
    }
    else if(isRunningAnimation) {
        DrawSpriteAnimationPro(animation, {body.x, body.y, TILE_SIZE, TILE_SIZE}, {0, 0}, 0, WHITE, isRunningAnimation);
    }
}

Tile::Tile(){
}

Tile::Tile(int id, Vector2 pos, int z_level) : id{id}, body{pos.x, pos.y, TILE_SIZE, TILE_SIZE}, z_level{z_level}{
    int fps;

    Json::Reader jsonreader;

    std::ifstream file("res/items.json");
    Json::Value jsonvalue;
    jsonreader.parse(file, jsonvalue);

    if(!jsonvalue.isArray()) return;
    if(id <= jsonvalue.size() && id >= 0){
        auto jsonTile = jsonvalue[id];

        name = jsonTile["name"].asString();
        type = jsonTile["type"].asString();

        if(jsonTile.isMember("animationOnDefault")) animationOnDefault = jsonTile["animationOnDefault"].asBool();

        if(jsonTile["fps"].isArray()){
            int probabulity = GetRandomValue(0, jsonTile["fps"].size()-1);
            fps = jsonTile["fps"][probabulity].asInt();
        }else{
            fps = jsonTile["fps"].asInt();
        }

        if(jsonTile["texture"].isArray()){
            int probabulity = GetRandomValue(0, jsonTile["texture"].size()-1);
            texture = LoadTexture(jsonTile["texture"][probabulity].asString().c_str());
        }else{
            texture = LoadTexture(jsonTile["texture"].asString().c_str());
        }
    }

    int totalFrame = texture.width/32;

    Rectangle animRect[totalFrame];
    for(int i=0;i<totalFrame;i++){
        animRect[i] = {(float)32*i, 0, 32, 32};
    }

    animation = CreateSpriteAnimation(texture, fps, animRect, totalFrame);

}
