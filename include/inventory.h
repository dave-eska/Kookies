#pragma once

#include<vector>

#include<raylib.h>

#include "enchant.h"
#include"item.h"
#include "tile.h"
#include"timer.h"

class Inventory{
    private:
        std::vector<InventoryItem> items;

        std::vector<int> craftableTileID;
        std::vector<int> canCraftTileID;

        int current_craftableTileId;

        Texture2D Outline_texture;
        Texture2D Extra_Inv_Texture;
        Texture2D SelectOutline_texture;
        Texture2D CraftingMenu_texture;
        Texture2D MoneySquare;

        Vector2 pos;
        int current_slot;

        Timer drawingNameTimer;

        int money;

        InventoryItem crafting_item;

        unsigned char outline_transparancy;

        bool isDrawingUI;
        bool isCrafting;

        void readCraftAbleFile();

    public:
        //Getters;
        InventoryItem getItemIdFromSlot(int slot);
        InventoryItem getItemFromCurrentSlot();

        int getSlotWithItem(int id);
        int getCurrentSlot(){return current_slot;}
        int getFirstEmptySlot();
        int getCurrent_craftableTileId(){return current_craftableTileId;}

        bool getIsCrafting(){return isCrafting;}

        void printItems();

        bool hasType(std::string type);

        bool has(int id);
        bool has(RecipeItem item_data);

        //Setters;
        void setPos(Vector2 newPos){pos=newPos;}
        void setItems(std::vector<InventoryItem> newItems){items=newItems;}
        void setItemInSlot(int slot, InventoryItem item){items[slot]=item;}
        void deleteItem(int slot);
        void setIsCrafting(bool value){isCrafting=value;}

        //Function;
        void addItem(InventoryItem item);
        void decreaseItemCount(int slot, int count);
        void decreaseItemCount(int slot);
        void decreaseItemCount(TileID id);

        int getMoney(){return money;}
        void setMoney(int val){money = val;}
        void AddMoney(int val){money += val;}
        void decreaseMoney(int val){money -= val;}

        void toggleDrawUI();
        void toggleCrafting();

        void UpdateCraftableTileID();

        void changeCurrentSlot();
        void moveItemToSlot(int slot1, int slot2);

        void craft(InventoryItem item);
        bool canCraft(InventoryItem item);

        void addEnchant(int slot, Enchant enchantment);

        void Draw(Camera2D& camera);
        void DrawItemName();

        //Constructors
        Inventory();

        Inventory(Vector2 pos, int slots, Texture2D Outline_texture,
                Texture2D SelectOutline_texture, Texture2D Extra_Inv_Texture, Texture2D CraftingMenu_texture);
};
