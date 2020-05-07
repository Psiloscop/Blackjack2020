#include <iostream>
#include <string>
#include <ConsoleInputAdapter.h>

#include "Card.h"
#include "ConsoleDisplayEntity.h"
#include "AbstractDisplayHandler.h"
#include "ConsoleDisplayHandler.h"
#include "ConsoleInputAdapter.h"
#include "InputHandler.h"
#include "CoreApplication.h"

//class A
//{
//public:
//    template <typename T>
//    void print(T var)
//    {
//        std::cout << var << " -";
//    }
//};
//
//class AA: public A
//{
//public:
//    template <typename T>
//    void print(T var)
//    {
//        std::cout << var << " +";
//    }
//};
//
//template<typename T>
//class B
//{
//public:
//    B()
//    {
//        // Compile-time check
//        static_assert(std::is_base_of<A, T>::value, "type parameter of this class must derive from BaseClass");
//
//        T t;
//
//        t.template print<std::string>("1");
//    }
//};

int main()
{
//    B<AA> b;

//    Card* cardEx1 = new Card(2, CardSuit(1));
//    Card* cardEx2 = new Card(3, CardSuit(1));
//    *cardEx1 == *cardEx2;

//    std::string tmp = "Entity string";
//    ConsoleDisplayEntity entity(tmp);
//    ConsoleDisplayHandler handler;
//    handler.display(entity);

//    auto* app = new CoreApplication<InputHandler, ConsoleInputAdapter, ConsoleDisplayHandler, std::string>();
    auto* app = new CoreApplication<InputHandler, ConsoleInputAdapter, ConsoleDisplayHandler, std::string>();
    app->createPlayer();

//    int val;
//    std::cout << "Enter value";
//    std::cin >> val;
//    std::cout << "Value: " << val;

    return 0;
}
