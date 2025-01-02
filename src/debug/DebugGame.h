#ifndef DEBUGGAME_H
#define DEBUGGAME_H

class DebugGame
{
    DebugGame() = default;
    bool isDebugEnabled = false;

    void ShowFps();

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

    /// <summary> Shows the debug info </summary>
    void ShowDebugInfo();

    /// <summary> Enables the debug </summary>
    void EnableDebug();

    /// <summary> Disables the debug </summary>
    void DisableDebug();
};



#endif //DEBUGGAME_H