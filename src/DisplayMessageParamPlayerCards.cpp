#include "DisplayMessageParamPlayerCards.h"
#include "Application.h"

void DisplayMessageParamPlayerCards::transformValue(Application* app)
{
    auto& displayHandler = app->getDisplayHandler();

    displayHandler.transformCardListEntity(this, this->cards);
}
