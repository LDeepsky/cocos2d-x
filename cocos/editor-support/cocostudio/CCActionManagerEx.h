/****************************************************************************
Copyright (c) 2013-2014 Chukong Technologies Inc.

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

#ifndef __ActionMANAGER_H__
#define __ActionMANAGER_H__

#include "cocostudio/CCActionObject.h"
#include "cocostudio/DictionaryHelper.h"

namespace cocostudio {
    
class ActionManagerEx;
    
class ActionWrap: public cocos2d::ActionInterval
{
public:
    ActionWrap():_node(nullptr){};
    static cocos2d::Action* createWrap(cocos2d::Ref* node);
    virtual ActionWrap* reverse() const {return nullptr;};
    virtual ActionWrap* clone() const {return nullptr;};
    
    virtual void update(float t) {};
    virtual ~ActionWrap();
private:
    cocos2d::Ref* _node;
};

class ActionManagerEx:public cocos2d::Ref
{
public:

	/**
	* Default constructor
	* @js ctor
	*/
	ActionManagerEx();

	/**
	* Default destructor
	* @js NA
	* @lua NA
	*/
	virtual ~ActionManagerEx();

	/**
	* Gets the static instance of ActionManager.
	* @js getInstance
	* @lua getInstance
	*/
	static ActionManagerEx* getInstance();

	/**
	* Purges ActionManager point.
	* @js purge
	* @lua destroyActionManager
	*/
	static void destroyInstance();

	/**
	* Gets an ActionObject with a name.
	*
	* @param jsonName  UI file name
	*
	* @param actionName  action name in the UI file.
	*
	* @return  ActionObject which named as the param name
	*/
	ActionObject* getActionByName(Ref* root,const char* actionName);

	/**
	* Play an Action with a name.
	*
	* @param jsonName  UI file name
	*
	* @param actionName  action name in teh UIfile.
	*
	* @return  ActionObject which named as the param name
	*/
	ActionObject* playActionByName(Ref* root,const char* actionName);

	/**
	* Play an Action with a name.
	*
	* @param jsonName  UI file name
	*
	* @param actionName  action name in teh UIfile.
	*
	* @param func ui action call back
	*/
	ActionObject* playActionByName(Ref* root,const char* actionName, cocos2d::CallFunc* func);

	/*init properties with json dictionay*/
	void initWithDictionary(const char* jsonName,const rapidjson::Value &dic, Ref* root);
    
    void releaseAction(Ref* root);
	/**
	* Release all actions.
	*
	*/
	void releaseActions();

protected:
	std::unordered_map<Ref*, cocos2d::Vector<ActionObject*>> _actionDic;
};

}

#endif
