#include "DisplayMessageParamDealerCards.h"
#include "Application.h"

void DisplayMessageParamDealerCards::transformValue(Application* app)
{
    if (!this->isValueTransformed)
    {
        auto& displayHandler = app->getDisplayHandler();

        displayHandler.transformCardListEntity(this, this->cards);

        this->isValueTransformed = true;
    }
}
