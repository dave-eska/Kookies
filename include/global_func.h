#pragma once

#include<string>
#include<vector>
#include<functional>

#include<raylib.h>

#include"level.h"
#include"player.h"

std::string readFile(const std::string& filename);
std::vector<std::string> getAllFileNamesInDirectory(const std::string& path);
void clamp(int &val, int low, int high);
void runFunctionForSecond(int seconds, std::function<void()> func);
void printText(std::string label, std::string information, Vector2 pos, int fontSize);
bool IsAlphanumeric(char c);
bool isStringInVector(const std::vector<std::string>& vec, const std::string& str);
std::string getSecondWord(const std::string& input);
std::string getFirstWord(const std::string& input);
bool isEnglishAlphabet(char c);

void typeInChat(std::string text);
void typeInChat(std::string text, Color color);

int GetCharacterDistance(char* str, int char1Index, int char2Index);

void changeMainLevel(std::string levelName);

Player &getPlayer();
Level &getCurrentLevel();

bool AABBx(Rectangle rec1, Rectangle rec2);
bool AABBy(Rectangle rec1, Rectangle rec2);

bool isWalkableX(Rectangle newPos, Rectangle body);
bool isWalkableY(Rectangle newPos, Rectangle body);

std::string floatToTime(float value);
