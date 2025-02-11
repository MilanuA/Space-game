#ifndef MESSAGEENUM_H
#define MESSAGEENUM_H

enum MessageEnum
{
    DEFAULT,
    WARNING,
    ERROR
};

inline std::pair<std::string, Color> GetLogTypeAndColor(MessageEnum type)
{
    switch (type)
    {
        case WARNING:
            return { "[WARNING]", ORANGE };
        case ERROR:
            return { "[ERROR]", RED };
        case DEFAULT:
            default:
                return { "[INFO]", WHITE };
    }
}

#endif //MESSAGEENUM_H
