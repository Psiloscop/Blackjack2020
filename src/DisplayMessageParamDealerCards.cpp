#include "DisplayMessageParamDealerCards.h"
#include "Application.h"

void DisplayMessageParamDealerCards::transformValue(Application* app)
{
    auto& displayHandler = app->getDisplayHandler();

    displayHandler.transformCardListEntity(this, this->cards);
}
