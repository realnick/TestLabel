/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "programming.h"
USING_NS_ALL;

#include "HelloWorldScene.h"
#include "PEUtils.h"
#include "PELabel.h"

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

bool HelloWorld::init()
{
    if ( !Scene::init() )
    {
        return false;
    }

    auto jsonText = FileUtils::getInstance()->getStringFromFile("json/test.json");
    auto jsonArray = PEUtils::parseJson(jsonText).get<picojson::array>();
    float baseX = 30, baseY = 400, margin = 10, fontSize = 32;
    float y = baseY;
    for (auto& row : jsonArray) {
        if (!row.is<picojson::array>()) {
            continue;
        }
        float x = baseX;
        for (auto& column : row.get<picojson::array>()) {
            if (!column.is<string>()) {
                continue;
            }
            auto text = column.get<string>();
            auto pLabel = PELabel::create(text, fontSize);
            pLabel->setPosition(Vec2(x, y));
            this->addChild(pLabel);
            x += fontSize + margin;
        }
        y -= (fontSize + margin);
    }
    return true;
}
