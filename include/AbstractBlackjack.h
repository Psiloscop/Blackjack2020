#pragma once

#include <vector>
#include <ctime>

#include "AppTypes.h"
#include "AbstractBlackjackAction.h"
#include "Box.h"
#include "Card.h"
#include "Dealer.h"
#include "Player.h"
#include "PlayerBetInputValidator.h"

enum RoundResult
{
    win,
    lose,
    tie
};

class Application;
class AbstractBlackjackAction;

class AbstractBlackjack
{
protected:
    Application* app;

    std::vector<AbstractBlackjackAction*> actions;

    std::vector<Box> boxes;

    std::vector<Card> shoe;

    Dealer dealer;

    Box* dealerBox;

    u16 shoeIndex = 0;

    u8 boxIndex = 0;

    u8 allowedMaxValueForPlayer = 21;

    u8 allowedMaxValueForDealer= 17;

    std::vector<u8> insuredBoxIndexes;

public:
    virtual void prepareGame() = 0;

    virtual void playGame() = 0;

    virtual void finishGame() = 0;

    void assignApp(Application*);

    std::vector<u8> getAvailableActionIndexes(); // new

    std::vector<std::string> getActionNames(const std::vector<u8>&); // new

    std::vector<Box>& getBoxes();

    u8 getCurrentBoxIndex() const; // new

    Box& getCurrentBox(); // new

    Box& getDealerBox();

    virtual std::vector<Card>& createShoe(u8 deckCount);

    std::vector<Card>& shuffleShoe();

    Card* getNextCard(); // new

    virtual std::vector<Box>& createBoxes(std::vector<Player>& players, u8 boxCount);

    virtual void requestBets();

    virtual void dealCardsToBoxes(u8 cardPerBox);

    virtual void dealCardsToDealer(u8 cardToDealer);

    std::vector<Card*>& getDealerCards();

    virtual BoxStatus getBoxStatus();

    virtual RoundResult getRoundResult();

    virtual u32 payToPlayerForBlackjack(); // new

    virtual u32 payToPlayerForCommonWin(); // new

    virtual u32 returnToPlayerItsBet(); // new

    void addInsuredBoxIndex(u8); // new

    bool hasInsuredBoxIndex(u8) const; // new

    std::vector<u8>& getInsuredBoxList(); // new

    void clearInsuredBoxList(); // new

    static void clearMessageParamList(std::vector<std::vector<ADisplayMessageParam*>>& messageParamList); // new
};