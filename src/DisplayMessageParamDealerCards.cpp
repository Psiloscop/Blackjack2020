#include "DisplayMessageParamDealerCards.h"
#include "Application.h"

void DisplayMessageParamDealerCards::transformValue(Application* app)
{
    if (!this->isValueTransformed)
    {
        if (this->hideSecondDealerCard && this->cards.size() == 2)
        {
            this->cards.pop_back();
            this->cards.push_back(&this->hiddenCard);
        }

        auto& displayHandler = app->getDisplayHandler();

        displayHandler.transformCardListEntity(this, this->cards);

        this->isValueTransformed = true;
    }
}
