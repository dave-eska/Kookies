#pragma once

#include<vector>
#include<string>

#include<raylib.h>

#include "animation.h"
#include "enchant.h"
#include "inventory.h"

#define DIRECTION_UP 1
#define DIRECTION_DOWN 2
#define DIRECTION_LEFT 3
#define DIRECTION_RIGHT 4

class Player{
    private:
        Rectangle body;
        Rectangle selectArea;
        Rectangle collisionArea;
        Rectangle newPos;

        int speed;
        int default_speed;

        //Animation
        Texture2D texture;
        std::vector<SpriteAnimation> animations;

        int current_animation;
        int direction;

        Inventory inv;

        std::string display_name;

        int toolRotation;

        //Debug variable
        bool isToucingItem;
    public:
        //Getter
        Rectangle getBody(){return body;}
        Rectangle getSelectArea(){return selectArea;}

        int getSpeed(){return speed;}
        bool getIsToucingItem(){return isToucingItem;}
        std::string getDisplayName(){return display_name;}
        Inventory getInv(){return inv;}

        bool isFishing();

        //Setters
        void setTouchingBool(bool value){isToucingItem=value;}
        void setPos(Vector2 pos){body.x=pos.x; body.y=pos.y;}

        //Inventoy functions
        void addItemInv(InventoryItem item);
        void decreaseItemInv(int slot);
        void toggleInvenCrafting();
        void setInvIsCrafting(bool value);
        void updateCraftableItem();
        void enchantInvItem(int slot, Enchant enchantmen);

        int getCurrentInvIDSlot();
        int getCurrentInvSlot();
        int getCurrentInvCraftAbleID();

        void decreaseItemCount(TileID id){inv.decreaseItemCount((TileID)id);}

        void setMoney(int val){inv.setMoney(val);}
        void AddMoney(int val){inv.AddMoney(val);}
        void decreaseMoney(int val){inv.decreaseMoney(val);}

        bool invHas(int id);
        bool invHas(RecipeItem criteria);

        //Public Functions
        void move(float dt);
        void attack(int &health, int& gDammage);

        void UpdateVariables();
        void UpdateTools(Camera2D& camera);
        void animate();

        void UpdateInventory();

        void Draw(bool isDebuggin, Camera2D& camera);
        void Draw_UI(Camera2D& camera);

        Player();

        //Constructor
        Player(Rectangle body, int speed, const char* texture_path, Rectangle selectArea, Rectangle collisionBody,
                /*inv*/
                int slots, Vector2 inventory_pos,
                std::string inventory_texture, std::string inventory_selecting_texture, std::string extra_inv_texture,
                std::string crafting_menu_texture,
                /*customization*/
                std::string display_name);
};
