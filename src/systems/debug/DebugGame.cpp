#include "DebugGame.h"
#include <raylib.h>
#include <string>

DebugGame::DebugGame()
{
    RegisterLoggable(this);
}

void DebugGame::RegisterLoggable(ILoggable *loggable)
{
    logMessages[loggable] = loggable->Log();
}

void DebugGame::ShowDebugInfo() const
{
    if (!isDebugEnabled) return;

    int xPos = 10;
    int yPos = 80;
    int lineSpacing = 20;
    int fontSize = 30;

    DrawText("Debug: ", xPos, yPos, 40, DARKGRAY);
    yPos += 40 + lineSpacing;

    for (const auto& entry : logMessages)
    {
        DrawText(entry.second.c_str(), xPos, yPos, fontSize, WHITE);
        yPos += fontSize + lineSpacing;
    }
}

void DebugGame::CaptureLogs()
{
    for (auto& entry : logMessages)
    {
        entry.second = entry.first->Log();
    }
}

std::string DebugGame::Log() const
{
    return "FPS: " + std::to_string(GetFPS());
}
