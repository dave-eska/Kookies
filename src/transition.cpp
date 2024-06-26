#include"transition.h"

#include<fstream>

#include<json/json.h>
#include<json/value.h>

#include"global_func.h"
#include"raylib.h"

void TransitionTile::attachLevel(std::string levelName){
    dest = levelName + ".json";
}

void TransitionTile::Update(){
}

std::string TransitionTile::Interact(){
    return dest;
}

void TransitionTile::Draw(bool is_debugging){
    Tile::Draw(is_debugging);

    if(is_debugging){
        DrawRectangleRec(body, {RED.r, RED.g, RED.b, 255/2});
        DrawText(dest.c_str(), body.x+TILE_SIZE, body.y, 20, BLACK);
    }
}

TransitionTile::TransitionTile(){
}

TransitionTile::TransitionTile(int id, Vector2 pos, int z_level){
    //Debug Variables
    isTouchingMouse=false;
    isRunningAnimation=true;

    debugbox=LoadTexture("res/img/debugbox.png");

    std::vector<std::string> file_names=getAllFileNamesInDirectory("res/items/");
    Json::Reader jsonreader;

    for(auto &e:file_names){
        std::ifstream file("res/items/"+e);
        Json::Value jsonvalue;
        jsonreader.parse(file, jsonvalue);

        //Cheecking if id is the same
        if(jsonvalue["id"].asInt()==id){
            body = {
                pos.x,
                pos.y,
                TILE_SIZE,
                TILE_SIZE
            };
            this->z_level=z_level;
            this->name = jsonvalue["name"].asString();
            this->id = jsonvalue["id"].asInt();
            this->type = jsonvalue["type"].asString();
            this->collision = false;

            this->filename = "res/items/"+e;

            this->texture = LoadTexture(jsonvalue["texture"].asString().c_str());
        }
    }

    Rectangle animRect[1]={
        {0,0,32,32},
    };

    animation = CreateSpriteAnimation(texture, 8, animRect, 4);
}
