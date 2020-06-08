#include "DisplayMessageParamPlayerCards.h"
#include "Application.h"

void DisplayMessageParamPlayerCards::transformValue(Application* app)
{
    if (!this->isValueTransformed)
    {
        auto& displayHandler = app->getDisplayHandler();

        displayHandler.transformCardListEntities(this, this->cards, this->currentHand);

        this->isValueTransformed = true;
    }
}
