//
//  PELabel.h
//

#ifndef __PELabel__
#define __PELabel__

#include "programming.h"

class PELabel : public cocos2d::Label
{
public:
    static cocos2d::Label* create(const std::string& text, int maxFontSize,
                                  const cocos2d::Size& boxSize = Size::ZERO,
                                  cocos2d::TextHAlignment hAlign = cocos2d::TextHAlignment::LEFT,
                                  cocos2d::TextVAlignment vAlign = cocos2d::TextVAlignment::TOP);
    static float getFontSize(cocos2d::Label* pLabel, bool round = true);
    static void setFontSize(cocos2d::Label* pLabel, float fontSize, bool round = true);
    static inline void setScale(cocos2d::Label* pLabel, float scale) { setScale(pLabel, scale, scale); };
    static void setScale(cocos2d::Label* pLabel, float scaleX, float scaleY);
    static void setScaleX(cocos2d::Label* pLabel, float scaleX);
    static void setScaleY(cocos2d::Label* pLabel, float scaleX);
    static float getScale(cocos2d::Label* pLabel);
    static float getScaleX(cocos2d::Label* pLabel);
    static float getScaleY(cocos2d::Label* pLabel);
    static cocos2d::Size getBoundingSize(cocos2d::Label* pLabel);
};
#endif /* defined(__PELabel__) */
