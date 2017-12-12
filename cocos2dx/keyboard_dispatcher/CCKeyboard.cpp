/****************************************************************************
 Copyright (c) 2010 cocos2d-x.org
 
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

#include "CCKeyboard.h"

NS_CC_BEGIN

void CCKeyboard::setKeyboardInfo(unsigned int keyCode, const char* charSequence, unsigned int modifiers, bool shiftKeyPressed, bool controlKeyPressed, bool altKeyPressed, bool commandKeyPressed)
{
    m_unKeyCode = keyCode;
    m_ccCharSequence = charSequence;
    m_unModifiers = modifiers;
    m_bShiftKeyPressed = shiftKeyPressed;
    m_bControlKeyPressed = controlKeyPressed;
    m_bAltKeyPressed = altKeyPressed;
    m_bCommandKeyPressed = commandKeyPressed;
}

unsigned int CCKeyboard::getKey()
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
    if(m_unKeyCode == 27) return 53;
    if(m_unKeyCode == 38) return 126;
    if(m_unKeyCode == 87) return 13;
    if(m_unKeyCode == 40) return 125;
    if(m_unKeyCode == 83) return 1;
    if(m_unKeyCode == 37) return 123;
    if(m_unKeyCode == 65) return 0;
    if(m_unKeyCode == 39) return 124;
    if(m_unKeyCode == 68) return 2;
    if(m_unKeyCode == 13) return 36;
    if(m_unKeyCode == 32) return 49;
    if(m_unKeyCode == 20) return 49;
#endif
    return m_unKeyCode;
}

const char CCKeyboard::getFirstKey() const
{
    return m_ccCharSequence[0];
}

const char* CCKeyboard::getKeySequence() const
{
    return m_ccCharSequence;
}

unsigned int CCKeyboard::getModifiers()
{
    return m_unModifiers;
}

bool CCKeyboard::isShiftKeyPressed()
{
    return m_bShiftKeyPressed;
}

bool CCKeyboard::isControlKeyPressed()
{
    return m_bControlKeyPressed;
}

bool CCKeyboard::isAltKeyPressed()
{
    return m_bAltKeyPressed;
}

bool CCKeyboard::isCommandKeyPressed()
{
    return m_bCommandKeyPressed;
}

NS_CC_END