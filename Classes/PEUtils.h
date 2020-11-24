//
//  PEUtils.h
//

#ifndef __PEUtils__
#define __PEUtils__

#include "programming.h"

class PEUtils
{
public:
    static inline float getAspectRatio(const cocos2d::Size& sz) {
        if (sz.width < sz.height) {
            return sz.height / sz.width;
        } else {
            return sz.width / sz.height;
        }
    };
    inline static cocos2d::Size getBoundingSize(cocos2d::Node* pNode) {
        auto sz = pNode->getContentSize();
        return cocos2d::Size(sz.width * pNode->getScaleX(), sz.height * pNode->getScaleY());
    };
};

#endif /* defined(__PEUtils__) */
