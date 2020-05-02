#ifndef __CONSOLE_DISPLAY_HANDLER_H_INCLUDED__
#define __CONSOLE_DISPLAY_HANDLER_H_INCLUDED__

#include <iostream>
#include <string>

#include "AbstractDisplayHandler.h"
#include "ConsoleDisplayEntity.h"

class ConsoleDisplayHandler: public AbstractDisplayHandler<std::string>
{
public:
    void display(const AbstractDisplayEntity<std::string>& entity) const override;
//    void display(const ConsoleDisplayEntity& entity) const override;
};

#endif // __CONSOLE_DISPLAY_HANDLER_H_INCLUDED__
