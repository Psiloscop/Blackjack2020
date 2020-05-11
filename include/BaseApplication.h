#ifndef __BASE_APPLICATION_H_INCLUDED__
#define __BASE_APPLICATION_H_INCLUDED__

#include <string>
#include <vector>
#include <iostream>

class BaseApplication
{
public:
    virtual void displayMessage(std::string messageId) const = 0;
    virtual void displayMessages(std::vector<std::string> messageIds) const = 0;

    template <typename TType, typename TInputValidator>
    TType requestInput()
    {
        std::cout << "!!!";
    }
};

#endif // __BASE_APPLICATION_H_INCLUDED__