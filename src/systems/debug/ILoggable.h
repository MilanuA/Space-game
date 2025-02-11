#ifndef ILOGGABLE_H
#define ILOGGABLE_H
#include <string>

class ILoggable
{
public:
    [[nodiscard]] virtual std::string Log() const = 0;
    virtual ~ILoggable() = default;
};
#endif //ILOGGABLE_H
