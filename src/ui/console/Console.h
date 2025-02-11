#ifndef CONSOLE_H
#define CONSOLE_H
#include "raylib.h"
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <source_location>

#include "LogMessageStruct.h"
#include "MessageEnum.h"

class Console
{
    static inline std::vector<LogMessageStruct> messages;

    static inline int consoleHeight = 370;
    static inline int consoleWidth = 1000;

    static inline int topPadding = 15;
    static inline int rightPadding = 20;

    static inline int lineSpacing = 6;
    static inline int messageSpacing = 20;

    static inline int fontSize = 20;
    static inline int sourceFontSize = 10;

    static inline int scrollbarY = 0;
    static inline int scrollbarHeight = 0;

    static inline bool draggingConsole = false;
    static inline int consoleX = 0;
    static inline int consoleY = 0;
    static inline int lastMouseX = 0;
    static inline int lastMouseY = 0;
    static inline int scrollIndex = 0;

public:
    static void Log(const std::string &message, MessageEnum messageType = DEFAULT, const std::source_location loc = std::source_location::current())
    {
        time_t now = time(nullptr);
        char timestamp[20];
        strftime(timestamp, sizeof(timestamp), "%H:%M:%S", localtime(&now));

        std::string source = "On line " + std::to_string(loc.line()) + ", " + std::string(loc.function_name()) + " in " + std::string(loc.file_name());

        messages.push_back({message, messageType, timestamp, source});

        scrollIndex = messages.size() > GetMaxVisibleLines() ? messages.size() - GetMaxVisibleLines() : 0;
    }

    static void DrawConsole()
    {
        int screenHeight = GetScreenHeight();
        int screenWidth = GetScreenWidth();

        if (consoleY == 0)
            consoleY = screenHeight - consoleHeight;

        if (consoleY + consoleHeight > screenHeight)
            consoleY = screenHeight - consoleHeight;
        if (consoleX + consoleWidth > screenWidth)
            consoleX = screenWidth - consoleWidth;

        DrawRectangle(consoleX, consoleY, consoleWidth, consoleHeight, BLACK);

        int startY = consoleY + topPadding;
        int currentY = startY;

        int lineHeight = fontSize + lineSpacing + sourceFontSize + messageSpacing;
        int maxVisibleLines = GetMaxVisibleLines();

        for (int i = 0; i < maxVisibleLines && (i + scrollIndex) < messages.size(); i++)
        {
            LogMessageStruct &msg = messages[i + scrollIndex];

            std::pair<std::string, Color> logTypeAndColor = GetLogTypeAndColor(msg.type);

            if (currentY + lineHeight <= consoleY + consoleHeight)
            {
                DrawText((logTypeAndColor.first + " " + msg.timestamp + " " + msg.text).c_str(), consoleX + rightPadding, currentY, fontSize, logTypeAndColor.second);
                currentY += fontSize + lineSpacing;

                DrawText(msg.source.c_str(), consoleX + rightPadding, currentY, sourceFontSize, logTypeAndColor.second);
                currentY += sourceFontSize + messageSpacing;
            }
            else
            {
                break;
            }
        }

        HandleScrolling();
        DrawScrollbar(maxVisibleLines);
    }

    static void ExportLog()
    {
        std::string filename = "../consolelog.txt";
        std::ofstream file(filename);
        if (file.is_open())
        {
            for (const auto &msg : messages)
            {
                std::pair<std::string, Color> logTypeAndColor = GetLogTypeAndColor(msg.type);

                file <<  logTypeAndColor.first << msg.timestamp << " " << msg.text << "\n" << msg.source << "\n\n";
            }
            file.close();
        }
    }

private:
    static void HandleScrolling()
    {
        if (GetMouseX() >= consoleX && GetMouseX() <= consoleX + consoleWidth && GetMouseY() >= consoleY && GetMouseY() <= consoleY + consoleHeight)
        {
            float wheel = GetMouseWheelMove();
            if (wheel > 0)
                ScrollUp();
            else if (wheel < 0)
                ScrollDown();
        }

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            if (GetMouseX() >= consoleX && GetMouseX() <= consoleX + consoleWidth &&
                GetMouseY() >= consoleY && GetMouseY() <= consoleY + consoleHeight)
            {
                draggingConsole = true;
                lastMouseY = GetMouseY();
                lastMouseX = GetMouseX();
            }
        }

        if (draggingConsole)
        {
            int deltaX = GetMouseX() - lastMouseX;
            int deltaY = GetMouseY() - lastMouseY;

            consoleX += deltaX;
            consoleY += deltaY;

            if (consoleX < 0) consoleX = 0;
            if (consoleY < 0) consoleY = -10;
            if (consoleX + consoleWidth > GetScreenWidth()) consoleX = GetScreenWidth() - consoleWidth;
            if (consoleY + consoleHeight > GetScreenHeight()) consoleY = GetScreenHeight() - consoleHeight;

            lastMouseX = GetMouseX();
            lastMouseY = GetMouseY();
        }

        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
        {
            draggingConsole = false;
        }
    }

    static void ScrollUp()
    {
        if (scrollIndex > 0)
            scrollIndex--;
    }

    static void ScrollDown()
    {
        if (scrollIndex < messages.size() - GetMaxVisibleLines())
            scrollIndex++;
        else
            scrollIndex = messages.size() - GetMaxVisibleLines();
    }

    static void DrawScrollbar(int maxLines)
    {
        if (messages.size() <= maxLines)
            return;

        int scrollbarX = consoleX + consoleWidth - 12;
        int scrollableArea = consoleHeight;
        scrollbarHeight = maxLines * scrollableArea / messages.size();

        scrollbarY = consoleY + (scrollIndex * (scrollableArea - scrollbarHeight) / (messages.size() - maxLines));

        if (scrollbarY < consoleY )
            scrollbarY = consoleY;
        if (scrollbarY + scrollbarHeight > consoleY + scrollableArea)
            scrollbarY = consoleY + scrollableArea - scrollbarHeight;

        DrawRectangle(scrollbarX, consoleY, 12, consoleHeight, DARKGRAY);
        DrawRectangle(scrollbarX, scrollbarY, 12, scrollbarHeight, LIGHTGRAY);
    }

    static int GetMaxVisibleLines()
    {
        int lineHeight = fontSize + lineSpacing + sourceFontSize + messageSpacing;
        return (consoleHeight - topPadding) / lineHeight;
    }
};

#endif //CONSOLE_H
