//
//  programming.h
//

#ifndef __programming__
#define __programming__

#include "cocos2d.h"

#include <time.h>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <queue>
#include <iostream>
#include <fstream>

#include "extensions/cocos-ext.h"
#include "picojson.h"

#define USING_NS_ALL \
    using namespace std; \
    using namespace cocos2d; \
    using namespace cocos2d::extension;

#define PE_FONT_NAME "fonts/rounded-x-mplus-1p-bold.ttf"

#define PE_LOGD(...) CCLOG(__VA_ARGS__)
#define PE_LOGI(...) CCLOG(__VA_ARGS__)
#define PE_LOGW(...) CCLOG(__VA_ARGS__)
#define PE_LOGE(...) CCLOG(__VA_ARGS__)

#endif
