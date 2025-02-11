#ifndef DEBUGGAME_H
#define DEBUGGAME_H
#include <map>
#include <string>
#include <vector>

#include "ILoggable.h"

class DebugGame : public ILoggable
{
    bool isDebugEnabled = false;
    std::vector<ILoggable*> loggableObjects;
    std::map<ILoggable*, std::string> logMessages;

    DebugGame();

    [[nodiscard]] std::string Log() const override;

public:
    /// <summary> Gets the instance of the debug game </summary>
    static DebugGame& GetInstance()
    {
        static DebugGame instance;
        return instance;
    }

    DebugGame(DebugGame const&) = delete;
    void operator=(DebugGame const&) = delete;

    /// <summary> Checks if the debug is enabled </summary>
    bool IsDebugEnabled() const { return isDebugEnabled; }

    void ToggleDebug() { isDebugEnabled = !isDebugEnabled; }
    /// <summary> Register a loggable object </summary>
    void RegisterLoggable(ILoggable* loggable);

    /// <summary> Displays the logs in Raylib </summary>
    void ShowDebugInfo() const;

    /// <summary> Captures logs from all loggable objects </summary>
    void CaptureLogs();
};



#endif //DEBUGGAME_H