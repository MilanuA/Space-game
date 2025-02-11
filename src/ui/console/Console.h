#ifndef CONSOLE_H
#define CONSOLE_H
#include "raylib.h"
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <source_location>

enum MessageEnum
{
    DEFAULT,
    WARNING,
    ERROR
};

struct LogMessage
{
    std::string text;
    MessageEnum type;
    std::string timestamp;
    std::string source;
};

class Console
{
    static inline std::vector<LogMessage> messages;
    static inline int maxLines = 10;
    static inline int scrollIndex = 0;
    static inline int consoleHeight = 400;
    static inline int consoleWidth = 1000;
    static inline int padding = 10;
    static inline int lineSpacing = 6;
    static inline int fontSize = 20;
    static inline bool draggingScrollbar = false;
    static inline int scrollbarY = 0;
    static inline int scrollbarHeight = 0;
    static inline int lastMouseY = 0;

public:
    static void Log(const std::string &message, MessageEnum messageType = DEFAULT,
           const std::source_location loc = std::source_location::current())
    {
        time_t now = time(nullptr);
        char timestamp[20];
        strftime(timestamp, sizeof(timestamp), "%H:%M:%S", localtime(&now));
        std::string source = "On line " + std::to_string(loc.line()) + ", " + std::string(loc.function_name()) + " in " + std::string(loc.file_name());
        messages.push_back({message, messageType, timestamp, source});

        if (messages.size() > maxLines)
            scrollIndex = messages.size() - maxLines;
    }

    static void DrawConsole()
    {
        int screenHeight = GetScreenHeight();
        int consoleY = screenHeight - consoleHeight;
        DrawRectangle(0, consoleY, consoleWidth, consoleHeight, BLACK);

        int startY = consoleY + padding;

        for (int i = 0; i < maxLines && (i + scrollIndex) < messages.size(); i++)
        {
            LogMessage &msg = messages[i + scrollIndex];

            auto textColor = WHITE;
            std::string logType = "[INFO] ";

            if (msg.type == WARNING)
            {
                textColor = ORANGE;
                logType = "[WARNING] ";
            }
            else if (msg.type == ERROR)
            {
                textColor = RED;
                logType = "[ERROR] ";
            }

            DrawText((logType + msg.timestamp + " " + msg.text).c_str(), 15, startY + i * (fontSize + lineSpacing), fontSize, textColor);

            DrawText(msg.source.c_str(), 15, startY + (i + 1) * (fontSize + lineSpacing), fontSize - 5, textColor);

            startY += fontSize + lineSpacing + fontSize - 2 + lineSpacing;
        }

        HandleScrolling(consoleY);
        DrawScrollbar(consoleY);
    }


    static void ExportLog()
    {
        std::string filename = "../consolelog.txt";
        std::ofstream file(filename);
        if (file.is_open())
        {
            for (const auto &msg : messages)
            {
                std::string logType = "[INFO] ";

                if (msg.type == WARNING)
                    logType = "[WARNING] ";
                else if (msg.type == ERROR)
                    logType = "[ERROR] ";

                file << logType << msg.timestamp << " " << msg.text << "\n" <<msg.source << "\n\n";
            }
            file.close();
        }
    }

private:
    static void HandleScrolling(int consoleY)
    {
        if (GetMouseX() < consoleWidth && GetMouseY() > consoleY)
        {
            float wheel = GetMouseWheelMove();
            if (wheel > 0)
                ScrollUp();
            else if (wheel < 0)
                ScrollDown();
        }
    }

    static void ScrollUp()
    {
        if (scrollIndex > 0)
            scrollIndex--;
    }

    static void ScrollDown()
    {
        if (scrollIndex < messages.size() - maxLines)
            scrollIndex++;
    }

    static void DrawScrollbar(int consoleY)
    {
        if (messages.size() <= maxLines)
            return;

        int scrollbarX = consoleWidth - 12;
        int scrollableArea = consoleHeight - 20;
        scrollbarHeight = scrollableArea * maxLines / messages.size();

        if (scrollbarHeight < 20)
            scrollbarHeight = 20;

        scrollbarY = consoleY + 5 + (scrollIndex * (scrollableArea - scrollbarHeight) / (messages.size() - maxLines));

        if (scrollbarY < consoleY + 5)
            scrollbarY = consoleY + 5;
        if (scrollbarY + scrollbarHeight > consoleY + scrollableArea)
            scrollbarY = consoleY + scrollableArea - scrollbarHeight;

        // background
        DrawRectangle(scrollbarX, consoleY, 12, consoleHeight, DARKGRAY);
        // handle
        DrawRectangle(scrollbarX, scrollbarY, 12, scrollbarHeight, LIGHTGRAY);

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            if (GetMouseX() >= scrollbarX && GetMouseX() <= scrollbarX + 12 &&
                GetMouseY() >= scrollbarY && GetMouseY() <= scrollbarY + scrollbarHeight)
            {
                draggingScrollbar = true;
                lastMouseY = GetMouseY();
            }
        }

        if (draggingScrollbar)
        {
            int mouseDelta = GetMouseY() - lastMouseY;
            lastMouseY = GetMouseY();

            float scrollRatio = static_cast<float>(messages.size() - maxLines) / (consoleHeight - scrollbarHeight - 20);
            scrollIndex += static_cast<int>(mouseDelta * scrollRatio);

            if (scrollIndex < 0)
                scrollIndex = 0;

            if (scrollIndex > messages.size() - maxLines)
                scrollIndex = messages.size() - maxLines;
        }

        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
        {
            draggingScrollbar = false;
        }
    }
};

#endif //CONSOLE_H
