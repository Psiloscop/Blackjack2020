#ifndef __CONSOLE_DISPLAY_HANDLER_H_INCLUDED__
#define __CONSOLE_DISPLAY_HANDLER_H_INCLUDED__

#include <iostream>
#include <string>

#include "AbstractDisplayHandler.h"
#include "ConsoleDisplayEntity.h"

class ConsoleDisplayHandler: public AbstractDisplayHandler<ConsoleDisplayEntity>
{
protected:
    void clearConsole() const;

public:
    void display(ConsoleDisplayEntity*) const override;
    void displayBatch(std::vector<ConsoleDisplayEntity*>) const override;
};

#endif // __CONSOLE_DISPLAY_HANDLER_H_INCLUDED__
