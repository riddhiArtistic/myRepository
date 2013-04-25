#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_com_velvetArts_v01_Actor
#include <com/velvetArts/v01/Actor.h>
#endif
#ifndef INCLUDED_com_velvetArts_v01_Candy
#include <com/velvetArts/v01/Candy.h>
#endif
#ifndef INCLUDED_com_velvetArts_v01_Clouds
#include <com/velvetArts/v01/Clouds.h>
#endif
#ifndef INCLUDED_com_velvetArts_v01_Game
#include <com/velvetArts/v01/Game.h>
#endif
#ifndef INCLUDED_com_velvetArts_v01_GameStates
#include <com/velvetArts/v01/GameStates.h>
#endif
#ifndef INCLUDED_com_velvetArts_v01_MovingBG
#include <com/velvetArts/v01/MovingBG.h>
#endif
#ifndef INCLUDED_haxe_Timer
#include <haxe/Timer.h>
#endif
#ifndef INCLUDED_native_display_DisplayObject
#include <native/display/DisplayObject.h>
#endif
#ifndef INCLUDED_native_display_DisplayObjectContainer
#include <native/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_native_display_Graphics
#include <native/display/Graphics.h>
#endif
#ifndef INCLUDED_native_display_IBitmapDrawable
#include <native/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_native_display_InteractiveObject
#include <native/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_native_display_MovieClip
#include <native/display/MovieClip.h>
#endif
#ifndef INCLUDED_native_display_Sprite
#include <native/display/Sprite.h>
#endif
#ifndef INCLUDED_native_display_Stage
#include <native/display/Stage.h>
#endif
#ifndef INCLUDED_native_events_Event
#include <native/events/Event.h>
#endif
#ifndef INCLUDED_native_events_EventDispatcher
#include <native/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_native_events_IEventDispatcher
#include <native/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_native_events_MouseEvent
#include <native/events/MouseEvent.h>
#endif
#ifndef INCLUDED_native_events_TouchEvent
#include <native/events/TouchEvent.h>
#endif
#ifndef INCLUDED_native_text_TextField
#include <native/text/TextField.h>
#endif
#ifndef INCLUDED_native_text_TextFormat
#include <native/text/TextFormat.h>
#endif
#ifndef INCLUDED_native_text_TextFormatAlign
#include <native/text/TextFormatAlign.h>
#endif
#ifndef INCLUDED_nme_Lib
#include <nme/Lib.h>
#endif
namespace com{
namespace velvetArts{
namespace v01{

Void Game_obj::__construct()
{
HX_STACK_PUSH("Game::new","com/velvetArts/v01/Game.hx",18);
{
	HX_STACK_LINE(28)
	this->cloudHit = false;
	HX_STACK_LINE(27)
	this->rewardHit = false;
	HX_STACK_LINE(39)
	Array< ::com::velvetArts::v01::Game > _g = Array_obj< ::com::velvetArts::v01::Game >::__new().Add(hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(41)
	super::__construct();
	HX_STACK_LINE(42)
	::nme::Lib_obj::get_current()->get_stage()->addChild(hx::ObjectPtr<OBJ_>(this));
	HX_STACK_LINE(44)
	this->stgWidth = ::nme::Lib_obj::get_current()->get_stage()->get_stageWidth();
	HX_STACK_LINE(45)
	this->stgHeight = ::nme::Lib_obj::get_current()->get_stage()->get_stageHeight();
	HX_STACK_LINE(47)
	this->bgImg = ::com::velvetArts::v01::MovingBG_obj::__new();
	HX_STACK_LINE(48)
	this->addChild(this->bgImg);
	HX_STACK_LINE(50)
	this->mCandies = Array_obj< ::com::velvetArts::v01::Candy >::__new();
	HX_STACK_LINE(51)
	{
		HX_STACK_LINE(51)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(51)
		while(((_g1 < (int)10))){
			HX_STACK_LINE(51)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(53)
			Float x_pos = (::Math_obj::random() * this->stgWidth);		HX_STACK_VAR(x_pos,"x_pos");
			HX_STACK_LINE(54)
			Float y_pos = (::Math_obj::random() * this->stgHeight);		HX_STACK_VAR(y_pos,"y_pos");
			HX_STACK_LINE(56)
			this->mCandies[i] = ::com::velvetArts::v01::Candy_obj::__new(x_pos,y_pos);
			HX_STACK_LINE(57)
			this->addChild(this->mCandies->__get(i));
		}
	}
	HX_STACK_LINE(60)
	this->mClouds = Array_obj< ::com::velvetArts::v01::Clouds >::__new();
	HX_STACK_LINE(61)
	{
		HX_STACK_LINE(61)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(61)
		while(((_g1 < (int)20))){
			HX_STACK_LINE(61)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(63)
			Float x_pos = (::Math_obj::random() * this->stgWidth);		HX_STACK_VAR(x_pos,"x_pos");
			HX_STACK_LINE(64)
			Float y_pos = (::Math_obj::random() * this->stgHeight);		HX_STACK_VAR(y_pos,"y_pos");
			HX_STACK_LINE(66)
			this->mClouds[i] = ::com::velvetArts::v01::Clouds_obj::__new(x_pos,y_pos);
			HX_STACK_LINE(67)
			this->addChild(this->mClouds->__get(i));
		}
	}
	HX_STACK_LINE(70)
	this->baby = ::com::velvetArts::v01::Actor_obj::__new();
	HX_STACK_LINE(71)
	this->addChild(this->baby);
	HX_STACK_LINE(72)
	this->mScore = (int)0;
	HX_STACK_LINE(73)
	this->topScore = (int)1000;
	HX_STACK_LINE(75)
	this->states = ::com::velvetArts::v01::GameStates_obj::__new();
	HX_STACK_LINE(77)
	this->timer = ::haxe::Timer_obj::__new(::com::velvetArts::v01::Game_obj::fps_data);

	HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_1,Array< ::com::velvetArts::v01::Game >,_g)
	Void run(){
		HX_STACK_PUSH("*::_Function_1_1","com/velvetArts/v01/Game.hx",79);
		{
			HX_STACK_LINE(80)
			_g->__get((int)0)->get_graphics()->clear();
			HX_STACK_LINE(81)
			_g->__get((int)0)->update();
		}
		return null();
	}
	HX_END_LOCAL_FUNC0((void))

	HX_STACK_LINE(79)
	this->timer->run =  Dynamic(new _Function_1_1(_g));
}
;
	return null();
}

Game_obj::~Game_obj() { }

Dynamic Game_obj::__CreateEmpty() { return  new Game_obj; }
hx::ObjectPtr< Game_obj > Game_obj::__new()
{  hx::ObjectPtr< Game_obj > result = new Game_obj();
	result->__construct();
	return result;}

Dynamic Game_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Game_obj > result = new Game_obj();
	result->__construct();
	return result;}

Void Game_obj::endTap( ::native::events::TouchEvent e){
{
		HX_STACK_PUSH("Game::endTap","com/velvetArts/v01/Game.hx",277);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Game_obj,endTap,(void))

Void Game_obj::startTouchGame( ::native::events::TouchEvent e){
{
		HX_STACK_PUSH("Game::startTouchGame","com/velvetArts/v01/Game.hx",267);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(267)
		if ((e->isPrimaryTouchPoint)){
			HX_STACK_LINE(270)
			this->states->Active = true;
			HX_STACK_LINE(271)
			this->states->Play = false;
			HX_STACK_LINE(272)
			this->states->Inactive = false;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Game_obj,startTouchGame,(void))

Void Game_obj::endClick( ::native::events::MouseEvent e){
{
		HX_STACK_PUSH("Game::endClick","com/velvetArts/v01/Game.hx",262);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Game_obj,endClick,(void))

Void Game_obj::startClickGame( ::native::events::MouseEvent e){
{
		HX_STACK_PUSH("Game::startClickGame","com/velvetArts/v01/Game.hx",255);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(256)
		this->states->Active = true;
		HX_STACK_LINE(257)
		this->states->Play = false;
		HX_STACK_LINE(258)
		this->states->Inactive = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Game_obj,startClickGame,(void))

Void Game_obj::check_Collision( ){
{
		HX_STACK_PUSH("Game::check_Collision","com/velvetArts/v01/Game.hx",224);
		HX_STACK_THIS(this);
		HX_STACK_LINE(225)
		{
			HX_STACK_LINE(225)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(225)
			while(((_g < (int)20))){
				HX_STACK_LINE(225)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(227)
				if ((!(this->cloudHit))){
					HX_STACK_LINE(228)
					if ((this->baby->hitTestObject(this->mClouds->__get(i)))){
						HX_STACK_LINE(231)
						this->cloudHit = true;
						HX_STACK_LINE(232)
						this->baby->set_x(this->mClouds->__get(i)->get_x());
						HX_STACK_LINE(233)
						this->baby->set_y((this->mClouds->__get(i)->get_y() - (int)25));
					}
				}
			}
		}
		HX_STACK_LINE(240)
		{
			HX_STACK_LINE(240)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(240)
			while(((_g < (int)10))){
				HX_STACK_LINE(240)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(242)
				if ((this->mCandies->__get(i)->get_visible())){
					HX_STACK_LINE(243)
					if ((this->baby->hitTestObject(this->mCandies->__get(i)))){
						HX_STACK_LINE(246)
						hx::AddEq(this->mScore,(int)10);
						HX_STACK_LINE(247)
						this->mCandies->__get(i)->set_visible(false);
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Game_obj,check_Collision,(void))

Void Game_obj::update( ){
{
		HX_STACK_PUSH("Game::update","com/velvetArts/v01/Game.hx",88);
		HX_STACK_THIS(this);
		HX_STACK_LINE(89)
		int stgWidth = ::nme::Lib_obj::get_current()->get_stage()->get_stageWidth();		HX_STACK_VAR(stgWidth,"stgWidth");
		HX_STACK_LINE(90)
		int stgHeight = ::nme::Lib_obj::get_current()->get_stage()->get_stageHeight();		HX_STACK_VAR(stgHeight,"stgHeight");
		HX_STACK_LINE(91)
		this->bgImg->update();
		HX_STACK_LINE(93)
		if ((this->states->Active)){
			HX_STACK_LINE(95)
			this->baby->IsActive = true;
			HX_STACK_LINE(96)
			this->baby->update();
			HX_STACK_LINE(97)
			{
				HX_STACK_LINE(97)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(97)
				while(((_g < (int)20))){
					HX_STACK_LINE(97)
					int i = (_g)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(98)
					this->mClouds->__get(i)->update();
				}
			}
			HX_STACK_LINE(99)
			{
				HX_STACK_LINE(99)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(99)
				while(((_g < (int)10))){
					HX_STACK_LINE(99)
					int i = (_g)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(100)
					this->mCandies->__get(i)->update();
				}
			}
			HX_STACK_LINE(102)
			if ((this->baby->jumpFlag)){
				HX_STACK_LINE(104)
				if ((this->cloudHit)){
					HX_STACK_LINE(105)
					this->cloudHit = false;
				}
				HX_STACK_LINE(106)
				if (((this->baby->get_y() > (int)0))){
					HX_STACK_LINE(107)
					::com::velvetArts::v01::Actor _g = this->baby;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(107)
					_g->set_y((_g->get_y() - (int)2));
				}
			}
			else{
				HX_STACK_LINE(111)
				this->check_Collision();
				HX_STACK_LINE(113)
				if ((!(this->cloudHit))){
					HX_STACK_LINE(115)
					if (((this->baby->get_x() > stgWidth))){
						HX_STACK_LINE(116)
						this->baby->set_x((int)0);
					}
					else{
						HX_STACK_LINE(118)
						::com::velvetArts::v01::Actor _g = this->baby;		HX_STACK_VAR(_g,"_g");
						HX_STACK_LINE(118)
						_g->set_x((_g->get_x() + 0.5));
					}
					HX_STACK_LINE(120)
					if (((this->baby->get_y() > stgHeight))){
						HX_STACK_LINE(122)
						this->states->Inactive = true;
						HX_STACK_LINE(123)
						this->states->Active = false;
						HX_STACK_LINE(124)
						this->states->Play = false;
					}
					HX_STACK_LINE(126)
					{
						HX_STACK_LINE(126)
						::com::velvetArts::v01::Actor _g = this->baby;		HX_STACK_VAR(_g,"_g");
						HX_STACK_LINE(126)
						_g->set_y((_g->get_y() + (int)2));
					}
				}
				else{
					HX_STACK_LINE(130)
					if (((this->baby->get_x() > stgWidth))){
						HX_STACK_LINE(131)
						this->baby->set_x((int)0);
					}
					else{
						HX_STACK_LINE(133)
						::com::velvetArts::v01::Actor _g = this->baby;		HX_STACK_VAR(_g,"_g");
						HX_STACK_LINE(133)
						_g->set_x((_g->get_x() + (int)1));
					}
					HX_STACK_LINE(134)
					this->cloudHit = !(this->cloudHit);
				}
			}
		}
		else{
			HX_STACK_LINE(139)
			if ((this->states->Inactive)){
				HX_STACK_LINE(142)
				this->baby->IsActive = false;
				HX_STACK_LINE(144)
				::native::text::TextFormat format = ::native::text::TextFormat_obj::__new(null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null());		HX_STACK_VAR(format,"format");
				HX_STACK_LINE(145)
				::native::text::TextField terminalText;		HX_STACK_VAR(terminalText,"terminalText");
				HX_STACK_LINE(146)
				terminalText = ::native::text::TextField_obj::__new();
				HX_STACK_LINE(147)
				format->font = HX_CSTRING("Arial");
				HX_STACK_LINE(148)
				format->bold = true;
				HX_STACK_LINE(149)
				format->color = (int)34850;
				HX_STACK_LINE(150)
				format->size = (int)40;
				HX_STACK_LINE(151)
				format->align = ::native::text::TextFormatAlign_obj::CENTER;
				HX_STACK_LINE(153)
				terminalText->set_background(false);
				HX_STACK_LINE(154)
				terminalText->set_defaultTextFormat(format);
				HX_STACK_LINE(155)
				terminalText->set_x((int)10);
				HX_STACK_LINE(156)
				terminalText->set_y(((Float(stgHeight) / Float((int)2)) - (int)25));
				HX_STACK_LINE(157)
				terminalText->set_width((stgWidth - (int)20));
				HX_STACK_LINE(158)
				terminalText->set_height((int)50);
				HX_STACK_LINE(159)
				terminalText->set_text(HX_CSTRING("YOU DIED! :("));
				HX_STACK_LINE(160)
				this->addChild(terminalText);
			}
		}
		HX_STACK_LINE(164)
		::native::text::TextFormat format = ::native::text::TextFormat_obj::__new(null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null());		HX_STACK_VAR(format,"format");
		HX_STACK_LINE(165)
		::native::text::TextField mScoreText;		HX_STACK_VAR(mScoreText,"mScoreText");
		HX_STACK_LINE(166)
		mScoreText = ::native::text::TextField_obj::__new();
		HX_STACK_LINE(167)
		format->font = HX_CSTRING("Arial");
		HX_STACK_LINE(168)
		format->bold = true;
		HX_STACK_LINE(169)
		format->color = (int)34850;
		HX_STACK_LINE(170)
		format->size = (int)20;
		HX_STACK_LINE(171)
		format->align = ::native::text::TextFormatAlign_obj::LEFT;
		HX_STACK_LINE(173)
		mScoreText->set_x((int)10);
		HX_STACK_LINE(174)
		mScoreText->set_y((int)20);
		HX_STACK_LINE(175)
		mScoreText->set_width((int)200);
		HX_STACK_LINE(176)
		mScoreText->set_height((int)30);
		HX_STACK_LINE(177)
		mScoreText->set_defaultTextFormat(format);
		HX_STACK_LINE(178)
		mScoreText->set_background(false);
		HX_STACK_LINE(179)
		if ((this->states->Active)){
			HX_STACK_LINE(180)
			mScoreText->set_text((HX_CSTRING("Score: ") + this->mScore));
		}
		else{
			HX_STACK_LINE(181)
			if ((this->states->Inactive)){
				HX_STACK_LINE(182)
				mScoreText->set_text((HX_CSTRING("Your Score: ") + this->mScore));
			}
			else{
				HX_STACK_LINE(183)
				if ((this->states->Play)){
					HX_STACK_LINE(185)
					mScoreText->set_text(HX_CSTRING("Click To Play!"));
					HX_STACK_LINE(186)
					mScoreText->addEventListener(::native::events::TouchEvent_obj::TOUCH_TAP,this->startTouchGame_dyn(),null(),null(),null());
					HX_STACK_LINE(187)
					mScoreText->addEventListener(::native::events::MouseEvent_obj::MOUSE_DOWN,this->startClickGame_dyn(),null(),null(),null());
				}
			}
		}
		HX_STACK_LINE(189)
		this->addChild(mScoreText);
		HX_STACK_LINE(191)
		::native::text::TextFormat format1 = ::native::text::TextFormat_obj::__new(null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null());		HX_STACK_VAR(format1,"format1");
		HX_STACK_LINE(192)
		::native::text::TextField mTopScoreText;		HX_STACK_VAR(mTopScoreText,"mTopScoreText");
		HX_STACK_LINE(193)
		mTopScoreText = ::native::text::TextField_obj::__new();
		HX_STACK_LINE(194)
		format1->font = HX_CSTRING("Arial");
		HX_STACK_LINE(195)
		format1->bold = true;
		HX_STACK_LINE(196)
		format1->color = (int)34850;
		HX_STACK_LINE(197)
		format1->size = (int)20;
		HX_STACK_LINE(198)
		format1->align = ::native::text::TextFormatAlign_obj::RIGHT;
		HX_STACK_LINE(200)
		mTopScoreText->set_x((stgWidth - (int)310));
		HX_STACK_LINE(201)
		mTopScoreText->set_y((int)20);
		HX_STACK_LINE(202)
		mTopScoreText->set_width((int)300);
		HX_STACK_LINE(203)
		mTopScoreText->set_height((int)30);
		HX_STACK_LINE(204)
		mTopScoreText->set_defaultTextFormat(format1);
		HX_STACK_LINE(205)
		mTopScoreText->set_background(false);
		HX_STACK_LINE(206)
		if (((this->topScore < this->mScore))){
			HX_STACK_LINE(207)
			if ((this->states->Active)){
				HX_STACK_LINE(209)
				mTopScoreText->set_text((HX_CSTRING("Top Score: ") + this->mScore));
			}
			else{
				HX_STACK_LINE(210)
				if ((this->states->Inactive)){
					HX_STACK_LINE(211)
					mTopScoreText->set_text((HX_CSTRING("Your Top Score: ") + this->mScore));
				}
			}
		}
		else{
			HX_STACK_LINE(214)
			if ((this->states->Active)){
				HX_STACK_LINE(216)
				mTopScoreText->set_text((HX_CSTRING("Top Score: ") + this->topScore));
			}
			else{
				HX_STACK_LINE(217)
				if ((this->states->Inactive)){
					HX_STACK_LINE(218)
					mTopScoreText->set_text((HX_CSTRING("Your Top Score: ") + this->topScore));
				}
			}
		}
		HX_STACK_LINE(220)
		this->addChild(mTopScoreText);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Game_obj,update,(void))

Dynamic Game_obj::fps_data;


Game_obj::Game_obj()
{
}

void Game_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Game);
	HX_MARK_MEMBER_NAME(states,"states");
	HX_MARK_MEMBER_NAME(timer,"timer");
	HX_MARK_MEMBER_NAME(topScore,"topScore");
	HX_MARK_MEMBER_NAME(mScore,"mScore");
	HX_MARK_MEMBER_NAME(cloudHit,"cloudHit");
	HX_MARK_MEMBER_NAME(rewardHit,"rewardHit");
	HX_MARK_MEMBER_NAME(stgHeight,"stgHeight");
	HX_MARK_MEMBER_NAME(stgWidth,"stgWidth");
	HX_MARK_MEMBER_NAME(mCandies,"mCandies");
	HX_MARK_MEMBER_NAME(mClouds,"mClouds");
	HX_MARK_MEMBER_NAME(baby,"baby");
	HX_MARK_MEMBER_NAME(bgImg,"bgImg");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Game_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(states,"states");
	HX_VISIT_MEMBER_NAME(timer,"timer");
	HX_VISIT_MEMBER_NAME(topScore,"topScore");
	HX_VISIT_MEMBER_NAME(mScore,"mScore");
	HX_VISIT_MEMBER_NAME(cloudHit,"cloudHit");
	HX_VISIT_MEMBER_NAME(rewardHit,"rewardHit");
	HX_VISIT_MEMBER_NAME(stgHeight,"stgHeight");
	HX_VISIT_MEMBER_NAME(stgWidth,"stgWidth");
	HX_VISIT_MEMBER_NAME(mCandies,"mCandies");
	HX_VISIT_MEMBER_NAME(mClouds,"mClouds");
	HX_VISIT_MEMBER_NAME(baby,"baby");
	HX_VISIT_MEMBER_NAME(bgImg,"bgImg");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Game_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"baby") ) { return baby; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"timer") ) { return timer; }
		if (HX_FIELD_EQ(inName,"bgImg") ) { return bgImg; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"endTap") ) { return endTap_dyn(); }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		if (HX_FIELD_EQ(inName,"states") ) { return states; }
		if (HX_FIELD_EQ(inName,"mScore") ) { return mScore; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"mClouds") ) { return mClouds; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"fps_data") ) { return fps_data; }
		if (HX_FIELD_EQ(inName,"endClick") ) { return endClick_dyn(); }
		if (HX_FIELD_EQ(inName,"topScore") ) { return topScore; }
		if (HX_FIELD_EQ(inName,"cloudHit") ) { return cloudHit; }
		if (HX_FIELD_EQ(inName,"stgWidth") ) { return stgWidth; }
		if (HX_FIELD_EQ(inName,"mCandies") ) { return mCandies; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"rewardHit") ) { return rewardHit; }
		if (HX_FIELD_EQ(inName,"stgHeight") ) { return stgHeight; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"startTouchGame") ) { return startTouchGame_dyn(); }
		if (HX_FIELD_EQ(inName,"startClickGame") ) { return startClickGame_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"check_Collision") ) { return check_Collision_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Game_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"baby") ) { baby=inValue.Cast< ::com::velvetArts::v01::Actor >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"timer") ) { timer=inValue.Cast< ::haxe::Timer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"bgImg") ) { bgImg=inValue.Cast< ::com::velvetArts::v01::MovingBG >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"states") ) { states=inValue.Cast< ::com::velvetArts::v01::GameStates >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mScore") ) { mScore=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"mClouds") ) { mClouds=inValue.Cast< Array< ::com::velvetArts::v01::Clouds > >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"fps_data") ) { fps_data=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"topScore") ) { topScore=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"cloudHit") ) { cloudHit=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"stgWidth") ) { stgWidth=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mCandies") ) { mCandies=inValue.Cast< Array< ::com::velvetArts::v01::Candy > >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"rewardHit") ) { rewardHit=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"stgHeight") ) { stgHeight=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Game_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("states"));
	outFields->push(HX_CSTRING("timer"));
	outFields->push(HX_CSTRING("topScore"));
	outFields->push(HX_CSTRING("mScore"));
	outFields->push(HX_CSTRING("cloudHit"));
	outFields->push(HX_CSTRING("rewardHit"));
	outFields->push(HX_CSTRING("stgHeight"));
	outFields->push(HX_CSTRING("stgWidth"));
	outFields->push(HX_CSTRING("mCandies"));
	outFields->push(HX_CSTRING("mClouds"));
	outFields->push(HX_CSTRING("baby"));
	outFields->push(HX_CSTRING("bgImg"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("fps_data"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("endTap"),
	HX_CSTRING("startTouchGame"),
	HX_CSTRING("endClick"),
	HX_CSTRING("startClickGame"),
	HX_CSTRING("check_Collision"),
	HX_CSTRING("update"),
	HX_CSTRING("states"),
	HX_CSTRING("timer"),
	HX_CSTRING("topScore"),
	HX_CSTRING("mScore"),
	HX_CSTRING("cloudHit"),
	HX_CSTRING("rewardHit"),
	HX_CSTRING("stgHeight"),
	HX_CSTRING("stgWidth"),
	HX_CSTRING("mCandies"),
	HX_CSTRING("mClouds"),
	HX_CSTRING("baby"),
	HX_CSTRING("bgImg"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Game_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Game_obj::fps_data,"fps_data");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Game_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Game_obj::fps_data,"fps_data");
};

Class Game_obj::__mClass;

void Game_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.velvetArts.v01.Game"), hx::TCanCast< Game_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Game_obj::__boot()
{
	fps_data= (Float((int)1000) / Float((int)30));
}

} // end namespace com
} // end namespace velvetArts
} // end namespace v01
