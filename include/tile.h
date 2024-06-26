#pragma once

#include<string>
#include<string>

#include<raylib.h>

#include<json/value.h>

#include"item.h"
#include"animation.h"

#define TILE_SIZE 96

class Tile{
    protected:
        Rectangle body;

        Texture2D texture;
        Texture2D debugbox;

        int rotation;

        std::string name;
        std::string type;
        int id;

        int z_level;

        std::string filename;

        //(temp ;)BagOFSeeds code
        int fruitID;

        //Collision
        bool collision;

        //animations
        int totalFrame;
        int fps;
        bool hasAnimation;
        bool isRunningAnimation;
        bool runningAnimationOnDefault;
        SpriteAnimation animation;

        //Debug var
        bool isTouchingMouse;
        bool isTouchingPlayer;
        bool isTouchingSelectAreaPlayer;
        int slot;
    public:
        //Getters
        std::string getName(){return name;}
        std::string getType(){return type;}

        float getX(){return body.x;}
        float getY(){return body.y;}

        int getZ(){return z_level;}
        int getID(){return id;}

        int getRotation(){return rotation;}

        int getSlot(){return slot;}

        int getFruitID(){return fruitID;};

        bool HasAnimFrame(){return hasAnimation;}
        bool HasCollision(){return collision;}

        bool getIsRunningAnimation(){return isRunningAnimation;}

        bool getIsTouchingMouse(){return isTouchingMouse;}
        bool getIsTouchingPlayer(){return isTouchingPlayer;}
        bool getIsTouchinSelectAreaPlayer(){return isTouchingSelectAreaPlayer;}

        InventoryItem asItem(int total_count); //Will set idx/slot to 0

        Rectangle getBody(){return body;}
        Texture2D getTexture(){return texture;}
        Vector2 getPos(){return {body.x, body.y};}

        //Seters
        void setBod(Rectangle bod){body=bod;}
        void setX(float x){body.x=x;}
        void setY(float y){body.y=y;}
        void setSlot(int vec_slot){slot = vec_slot;}
        void setIsTouchingMouse(bool val){isTouchingMouse = val;}
        void setIsTouchingPlayer(bool val){isTouchingPlayer = val;}
        void setIsTouchingSelectAreaPlayer(bool val){isTouchingSelectAreaPlayer = val;}
        void setTexture(Texture2D new_texture){texture = new_texture;}
        void setRotation(int val){rotation=val;}

        void runAnimation(){isRunningAnimation=true;}

        virtual void Update();
        virtual std::string Interact();
        virtual void Draw(bool is_debugging);

        //Constructors
        Tile();
        Tile(int id, Vector2 pos, int z_level);
        Tile(int id);

        virtual ~Tile() = default;
};

enum TileID {
    Air_Tile = 0,

    Grass_Tile = 1,
    Farmland_Tile,
    Brickwall_Tile,
    Floor_Tile,

    Doorup_Tile = 5,
    Doordown_Tile,

    Chest_Tile = 7,
    Craftingtable_Tile,

    Transition_Tile = 9,
    Itemarea_Tile,
    PlaceArea_Tile,

    Chocolate_Tile = 12,
    Chocolatecake_Tile,
    Cherry_Tile,
    Milk_Tile,
    Cookie_Tile,
    Cocoabeans_Tile,

    Emptybag_Tile = 18,
    Bagofcherry_Tile,
    Bagofcocoabeans_Tile,

    Cherryseeds_Tile = 21,
    Cocoabeansseed_Tile,

    Effectbook_Tile = 23,

    Forgebench_Tile = 24,
    Woodenstick_Tile,
    Water_Tile,
    RawFish_Tile,

    MaxTileID
};
