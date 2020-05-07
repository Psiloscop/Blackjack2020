#ifndef __CONSOLE_DISPLAY_HANDLER_H_INCLUDED__
#define __CONSOLE_DISPLAY_HANDLER_H_INCLUDED__

#include <iostream>
#include <string>

#include "AbstractDisplayHandler.h"
#include "ConsoleDisplayEntity.h"

class ConsoleDisplayHandler: public AbstractDisplayHandler<ConsoleDisplayEntity>
{
public:
    void display(const ConsoleDisplayEntity&) const override;

//    void display(const AbstractDisplayEntity<std::string>& entity) const override;
//    void display(const ConsoleDisplayEntity& entity) const;
};

#endif // __CONSOLE_DISPLAY_HANDLER_H_INCLUDED__
