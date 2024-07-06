#pragma once

#include "raylib.h"
#include <string>

class Scene{
protected:
    std::string title;
    bool is_debugging;
    bool is_typing;

    Camera2D camera;

    int returnCode;

public:
    std::string getTitle(){return title;}
    int getReturnCode(){return returnCode;}

    void resetReturnCode();

    virtual void Update(float dt)=0;
    virtual void Draw()=0;

    virtual void Unload()=0;

    Scene();
    Scene(std::string title, int cameraZoom);

};

enum class Scenes{
    MainMenu,
    GamePlay,
    LevelEditor,
    Option
};
