
#include "DebugGame.h"

#include <raylib.h>
#include <string>


void DebugGame::ShowDebugInfo()
{
    ShowFps();
}

void DebugGame::ShowFps()
{
    std::string fpsText = "FPS: " + std::to_string(GetFPS());
    DrawText(fpsText.c_str(), 10, 60, 45, WHITE);
}


void DebugGame::EnableDebug()
{
    isDebugEnabled = true;
}

void DebugGame::DisableDebug()
{
    isDebugEnabled = false;
}