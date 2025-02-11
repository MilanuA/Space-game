#ifndef LOGMESSAGESTRUCT_H
#define LOGMESSAGESTRUCT_H
#include <string>

#include "MessageEnum.h"

struct LogMessageStruct
{
    std::string text;
    MessageEnum type;
    std::string timestamp;
    std::string source;
};
#endif //LOGMESSAGESTRUCT_H
