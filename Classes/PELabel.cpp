//
//  PELabel.cpp
//
#include "programming.h"
USING_NS_ALL;

#include "PELabel.h"
#include "PEUtils.h"
#include "AppDelegate.h"

static inline Label* create_label(const string& text, int fontSize,
                                  const Size& boxSize, TextHAlignment hAlign, TextVAlignment vAlign)
{
    auto factor = AppDelegate::sharedObject()->getFontScaleFactor();
    auto pLabel = Label::createWithTTF(text, PE_FONT_NAME, fontSize*factor, boxSize*factor, hAlign, vAlign);
    pLabel->setScale(1.0/factor);
    return pLabel;
}

Label* PELabel::create(const string& text, int fontSize,
                       const Size& boxSize, TextHAlignment hAlign, TextVAlignment vAlign)
{
    int maxFontSize = fontSize;
    auto pLabel = create_label(text, fontSize, Size(boxSize.width, 0), hAlign, vAlign);
    if (!text.empty() && 0 < boxSize.height) {
        float height = PEUtils::getBoundingSize(pLabel).height;
        while (boxSize.height < height) {
            fontSize /= 2;
            pLabel = create_label(text, fontSize, Size(boxSize.width, 0), hAlign, vAlign);
            height = PEUtils::getBoundingSize(pLabel).height;
        }
        while (height < boxSize.height) {
            fontSize += 1;
            if (maxFontSize < fontSize) {
                break;
            }
            pLabel = create_label(text, fontSize, Size(boxSize.width, 0), hAlign, vAlign);
            height = PEUtils::getBoundingSize(pLabel).height;
        }
        pLabel = create_label(text, fontSize-1, Size(boxSize.width, 0), hAlign, vAlign);
    }
    return pLabel;
}

void PELabel::setFontSize(Label* pLabel, float fontSize, bool round)
{
    auto config = pLabel->getTTFConfig();
    if (round) {
        config.fontSize = roundf(fontSize * AppDelegate::sharedObject()->getFontScaleFactor());
    } else {
        config.fontSize = fontSize * AppDelegate::sharedObject()->getFontScaleFactor();
    }
    pLabel->setTTFConfig(config);
}

float PELabel::getFontSize(Label* pLabel, bool round)
{
    auto fontSize = pLabel->getTTFConfig().fontSize / AppDelegate::sharedObject()->getFontScaleFactor();
    return round ? roundf(fontSize) : fontSize;
}

void PELabel::setScale(Label* pLabel, float scaleX, float scaleY)
{
    auto factor = AppDelegate::sharedObject()->getFontScaleFactor();
    pLabel->setScale(scaleX/factor, scaleY/factor);
}

void PELabel::setScaleX(Label* pLabel, float scaleX)
{
    auto factor = AppDelegate::sharedObject()->getFontScaleFactor();
    pLabel->setScaleX(scaleX/factor);
}

void PELabel::setScaleY(Label* pLabel, float scaleY)
{
    auto factor = AppDelegate::sharedObject()->getFontScaleFactor();
    pLabel->setScaleY(scaleY/factor);
}

float PELabel::getScale(Label* pLabel)
{
    return pLabel->getScale() * AppDelegate::sharedObject()->getFontScaleFactor();
}

float PELabel::getScaleX(Label* pLabel)
{
    return pLabel->getScaleX() * AppDelegate::sharedObject()->getFontScaleFactor();
}

float PELabel::getScaleY(Label* pLabel)
{
    return pLabel->getScaleY() * AppDelegate::sharedObject()->getFontScaleFactor();
}

Size PELabel::getBoundingSize(Label* pLabel)
{
    if (0 < pLabel->getStringLength()) {
        return PEUtils::getBoundingSize(pLabel);
    }
    pLabel->setString(" ");
    auto result = PEUtils::getBoundingSize(pLabel);
    result.width = 0;
    pLabel->setString("");
    return result;
}
