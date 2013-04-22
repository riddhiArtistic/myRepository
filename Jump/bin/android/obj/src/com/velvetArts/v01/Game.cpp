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
#ifndef INCLUDED_com_velvetArts_v01_Character
#include <com/velvetArts/v01/Character.h>
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
#ifndef INCLUDED_com_velvetArts_v01_PixelPerfectCollision
#include <com/velvetArts/v01/PixelPerfectCollision.h>
#endif
#ifndef INCLUDED_native_display_DisplayObject
#include <native/display/DisplayObject.h>
#endif
#ifndef INCLUDED_native_display_DisplayObjectContainer
#include <native/display/DisplayObjectContainer.h>
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
#ifndef INCLUDED_native_geom_Point
#include <native/geom/Point.h>
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
HX_STACK_PUSH("Game::new","com/velvetArts/v01/Game.hx",17);
{
	HX_STACK_LINE(27)
	this->cloudHit = false;
	HX_STACK_LINE(26)
	this->rewardHit = false;
	HX_STACK_LINE(37)
	super::__construct();
	HX_STACK_LINE(38)
	::nme::Lib_obj::get_current()->get_stage()->addChild(hx::ObjectPtr<OBJ_>(this));
	HX_STACK_LINE(40)
	this->stgWidth = ::nme::Lib_obj::get_current()->get_stage()->get_stageWidth();
	HX_STACK_LINE(41)
	this->stgHeight = ::nme::Lib_obj::get_current()->get_stage()->get_stageHeight();
	HX_STACK_LINE(43)
	this->bgImg = ::com::velvetArts::v01::MovingBG_obj::__new();
	HX_STACK_LINE(44)
	this->addChild(this->bgImg);
	HX_STACK_LINE(46)
	this->mCandies = Array_obj< ::com::velvetArts::v01::Candy >::__new();
	HX_STACK_LINE(47)
	{
		HX_STACK_LINE(47)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(47)
		while(((_g < (int)10))){
			HX_STACK_LINE(47)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(49)
			Float x_pos = (::Math_obj::random() * this->stgWidth);		HX_STACK_VAR(x_pos,"x_pos");
			HX_STACK_LINE(50)
			Float y_pos = (::Math_obj::random() * this->stgHeight);		HX_STACK_VAR(y_pos,"y_pos");
			HX_STACK_LINE(52)
			this->mCandies[i] = ::com::velvetArts::v01::Candy_obj::__new(x_pos,y_pos);
			HX_STACK_LINE(53)
			this->addChild(this->mCandies->__get(i));
		}
	}
	HX_STACK_LINE(56)
	this->mClouds = Array_obj< ::com::velvetArts::v01::Clouds >::__new();
	HX_STACK_LINE(57)
	{
		HX_STACK_LINE(57)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(57)
		while(((_g < (int)20))){
			HX_STACK_LINE(57)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(59)
			Float x_pos = (::Math_obj::random() * this->stgWidth);		HX_STACK_VAR(x_pos,"x_pos");
			HX_STACK_LINE(60)
			Float y_pos = (::Math_obj::random() * this->stgHeight);		HX_STACK_VAR(y_pos,"y_pos");
			HX_STACK_LINE(62)
			this->mClouds[i] = ::com::velvetArts::v01::Clouds_obj::__new(x_pos,y_pos);
			HX_STACK_LINE(63)
			this->addChild(this->mClouds->__get(i));
		}
	}
	HX_STACK_LINE(66)
	this->baby = ::com::velvetArts::v01::Actor_obj::__new();
	HX_STACK_LINE(67)
	this->addChild(this->baby);
	HX_STACK_LINE(68)
	this->mScore = (int)0;
	HX_STACK_LINE(69)
	this->topScore = (int)1000;
	HX_STACK_LINE(71)
	this->states = ::com::velvetArts::v01::GameStates_obj::__new();
	HX_STACK_LINE(73)
	this->addEventListener(::native::events::Event_obj::ENTER_FRAME,this->update_dyn(),null(),null(),null());
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
		HX_STACK_PUSH("Game::endTap","com/velvetArts/v01/Game.hx",280);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Game_obj,endTap,(void))

Void Game_obj::startTouchGame( ::native::events::TouchEvent e){
{
		HX_STACK_PUSH("Game::startTouchGame","com/velvetArts/v01/Game.hx",270);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(270)
		if ((e->isPrimaryTouchPoint)){
			HX_STACK_LINE(273)
			this->states->Active = true;
			HX_STACK_LINE(274)
			this->states->Play = false;
			HX_STACK_LINE(275)
			this->states->Inactive = false;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Game_obj,startTouchGame,(void))

Void Game_obj::endClick( ::native::events::MouseEvent e){
{
		HX_STACK_PUSH("Game::endClick","com/velvetArts/v01/Game.hx",265);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Game_obj,endClick,(void))

Void Game_obj::startClickGame( ::native::events::MouseEvent e){
{
		HX_STACK_PUSH("Game::startClickGame","com/velvetArts/v01/Game.hx",258);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(259)
		this->states->Active = true;
		HX_STACK_LINE(260)
		this->states->Play = false;
		HX_STACK_LINE(261)
		this->states->Inactive = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Game_obj,startClickGame,(void))

Void Game_obj::check_Collision( ){
{
		HX_STACK_PUSH("Game::check_Collision","com/velvetArts/v01/Game.hx",226);
		HX_STACK_THIS(this);
		HX_STACK_LINE(227)
		{
			HX_STACK_LINE(227)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(227)
			while(((_g < (int)20))){
				HX_STACK_LINE(227)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(229)
				if ((!(this->cloudHit))){
					HX_STACK_LINE(230)
					if ((::com::velvetArts::v01::PixelPerfectCollision_obj::IsColliding(this->baby,this->mClouds->__get(i),hx::ObjectPtr<OBJ_>(this),false,(int)0))){
						HX_STACK_LINE(233)
						this->cloudHit = true;
						HX_STACK_LINE(234)
						this->baby->set_x(this->mClouds->__get(i)->get_x());
						HX_STACK_LINE(235)
						this->baby->set_y((this->mClouds->__get(i)->get_y() - (int)30));
						HX_STACK_LINE(236)
						this->hitPoint = ::com::velvetArts::v01::PixelPerfectCollision_obj::getCollisionPoint(this->baby,this->mClouds->__get(i),hx::ObjectPtr<OBJ_>(this),false,(int)0);
					}
				}
			}
		}
		HX_STACK_LINE(242)
		{
			HX_STACK_LINE(242)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(242)
			while(((_g < (int)10))){
				HX_STACK_LINE(242)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(244)
				if ((this->mCandies->__get(i)->get_visible())){
					HX_STACK_LINE(245)
					if ((::com::velvetArts::v01::PixelPerfectCollision_obj::IsColliding(this->baby,this->mCandies->__get(i),hx::ObjectPtr<OBJ_>(this),false,(int)0))){
						HX_STACK_LINE(249)
						hx::AddEq(this->mScore,(int)10);
						HX_STACK_LINE(250)
						this->mCandies->__get(i)->set_visible(false);
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Game_obj,check_Collision,(void))

Void Game_obj::update( ::native::events::Event e){
{
		HX_STACK_PUSH("Game::update","com/velvetArts/v01/Game.hx",77);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(78)
		int stgWidth = ::nme::Lib_obj::get_current()->get_stage()->get_stageWidth();		HX_STACK_VAR(stgWidth,"stgWidth");
		HX_STACK_LINE(79)
		int stgHeight = ::nme::Lib_obj::get_current()->get_stage()->get_stageHeight();		HX_STACK_VAR(stgHeight,"stgHeight");
		HX_STACK_LINE(81)
		if ((this->states->Active)){
			HX_STACK_LINE(83)
			this->baby->IsActive = true;
			HX_STACK_LINE(84)
			this->check_Collision();
			HX_STACK_LINE(86)
			if ((!(this->cloudHit))){
				HX_STACK_LINE(88)
				if (((this->baby->get_x() > stgWidth))){
					HX_STACK_LINE(89)
					this->baby->set_x((int)0);
				}
				else{
					HX_STACK_LINE(91)
					::com::velvetArts::v01::Actor _g = this->baby;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(91)
					_g->set_x((_g->get_x() + 0.5));
				}
				HX_STACK_LINE(93)
				if (((this->baby->get_y() > stgHeight))){
					HX_STACK_LINE(95)
					this->states->Inactive = true;
					HX_STACK_LINE(96)
					this->states->Active = false;
					HX_STACK_LINE(97)
					this->states->Play = false;
				}
				HX_STACK_LINE(99)
				{
					HX_STACK_LINE(99)
					::com::velvetArts::v01::Actor _g = this->baby;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(99)
					_g->set_y((_g->get_y() + 0.5));
				}
			}
			else{
				HX_STACK_LINE(103)
				if (((this->baby->get_x() > stgWidth))){
					HX_STACK_LINE(104)
					this->baby->set_x((int)0);
				}
				else{
					HX_STACK_LINE(106)
					::com::velvetArts::v01::Actor _g = this->baby;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(106)
					_g->set_x((_g->get_x() + (int)1));
				}
				HX_STACK_LINE(107)
				this->cloudHit = !(this->cloudHit);
			}
		}
		else{
			HX_STACK_LINE(111)
			if ((this->states->Inactive)){
				HX_STACK_LINE(114)
				this->baby->IsActive = false;
				HX_STACK_LINE(116)
				::native::text::TextFormat format = ::native::text::TextFormat_obj::__new(null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null());		HX_STACK_VAR(format,"format");
				HX_STACK_LINE(117)
				::native::text::TextField terminalText;		HX_STACK_VAR(terminalText,"terminalText");
				HX_STACK_LINE(118)
				terminalText = ::native::text::TextField_obj::__new();
				HX_STACK_LINE(119)
				format->font = HX_CSTRING("Arial");
				HX_STACK_LINE(120)
				format->bold = true;
				HX_STACK_LINE(121)
				format->color = (int)34850;
				HX_STACK_LINE(122)
				format->size = (int)40;
				HX_STACK_LINE(123)
				format->align = ::native::text::TextFormatAlign_obj::CENTER;
				HX_STACK_LINE(125)
				terminalText->set_background(false);
				HX_STACK_LINE(126)
				terminalText->set_defaultTextFormat(format);
				HX_STACK_LINE(127)
				terminalText->set_x((int)10);
				HX_STACK_LINE(128)
				terminalText->set_y(((Float(stgHeight) / Float((int)2)) - (int)25));
				HX_STACK_LINE(129)
				terminalText->set_width((stgWidth - (int)20));
				HX_STACK_LINE(130)
				terminalText->set_height((int)50);
				HX_STACK_LINE(131)
				terminalText->set_text(HX_CSTRING("YOU DIED! :("));
				HX_STACK_LINE(132)
				this->addChild(terminalText);
			}
		}
		HX_STACK_LINE(166)
		::native::text::TextFormat format = ::native::text::TextFormat_obj::__new(null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null());		HX_STACK_VAR(format,"format");
		HX_STACK_LINE(167)
		::native::text::TextField mScoreText;		HX_STACK_VAR(mScoreText,"mScoreText");
		HX_STACK_LINE(168)
		mScoreText = ::native::text::TextField_obj::__new();
		HX_STACK_LINE(169)
		format->font = HX_CSTRING("Arial");
		HX_STACK_LINE(170)
		format->bold = true;
		HX_STACK_LINE(171)
		format->color = (int)34850;
		HX_STACK_LINE(172)
		format->size = (int)20;
		HX_STACK_LINE(173)
		format->align = ::native::text::TextFormatAlign_obj::LEFT;
		HX_STACK_LINE(175)
		mScoreText->set_x((int)10);
		HX_STACK_LINE(176)
		mScoreText->set_y((int)20);
		HX_STACK_LINE(177)
		mScoreText->set_width((int)200);
		HX_STACK_LINE(178)
		mScoreText->set_height((int)30);
		HX_STACK_LINE(179)
		mScoreText->set_defaultTextFormat(format);
		HX_STACK_LINE(180)
		mScoreText->set_background(false);
		HX_STACK_LINE(181)
		if ((this->states->Active)){
			HX_STACK_LINE(182)
			mScoreText->set_text((HX_CSTRING("Score: ") + this->mScore));
		}
		else{
			HX_STACK_LINE(183)
			if ((this->states->Inactive)){
				HX_STACK_LINE(184)
				mScoreText->set_text((HX_CSTRING("Your Score: ") + this->mScore));
			}
			else{
				HX_STACK_LINE(185)
				if ((this->states->Play)){
					HX_STACK_LINE(187)
					mScoreText->set_text(HX_CSTRING("Click To Play!"));
					HX_STACK_LINE(188)
					mScoreText->addEventListener(::native::events::TouchEvent_obj::TOUCH_TAP,this->startTouchGame_dyn(),null(),null(),null());
					HX_STACK_LINE(189)
					mScoreText->addEventListener(::native::events::MouseEvent_obj::MOUSE_DOWN,this->startClickGame_dyn(),null(),null(),null());
				}
			}
		}
		HX_STACK_LINE(191)
		this->addChild(mScoreText);
		HX_STACK_LINE(193)
		::native::text::TextFormat format1 = ::native::text::TextFormat_obj::__new(null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null());		HX_STACK_VAR(format1,"format1");
		HX_STACK_LINE(194)
		::native::text::TextField mTopScoreText;		HX_STACK_VAR(mTopScoreText,"mTopScoreText");
		HX_STACK_LINE(195)
		mTopScoreText = ::native::text::TextField_obj::__new();
		HX_STACK_LINE(196)
		format1->font = HX_CSTRING("Arial");
		HX_STACK_LINE(197)
		format1->bold = true;
		HX_STACK_LINE(198)
		format1->color = (int)34850;
		HX_STACK_LINE(199)
		format1->size = (int)20;
		HX_STACK_LINE(200)
		format1->align = ::native::text::TextFormatAlign_obj::RIGHT;
		HX_STACK_LINE(202)
		mTopScoreText->set_x((stgWidth - (int)310));
		HX_STACK_LINE(203)
		mTopScoreText->set_y((int)20);
		HX_STACK_LINE(204)
		mTopScoreText->set_width((int)300);
		HX_STACK_LINE(205)
		mTopScoreText->set_height((int)30);
		HX_STACK_LINE(206)
		mTopScoreText->set_defaultTextFormat(format1);
		HX_STACK_LINE(207)
		mTopScoreText->set_background(false);
		HX_STACK_LINE(208)
		if (((this->topScore < this->mScore))){
			HX_STACK_LINE(209)
			if ((this->states->Active)){
				HX_STACK_LINE(211)
				mTopScoreText->set_text((HX_CSTRING("Top Score: ") + this->mScore));
			}
			else{
				HX_STACK_LINE(212)
				if ((this->states->Inactive)){
					HX_STACK_LINE(213)
					mTopScoreText->set_text((HX_CSTRING("Your Top Score: ") + this->mScore));
				}
			}
		}
		else{
			HX_STACK_LINE(216)
			if ((this->states->Active)){
				HX_STACK_LINE(218)
				mTopScoreText->set_text((HX_CSTRING("Top Score: ") + this->topScore));
			}
			else{
				HX_STACK_LINE(219)
				if ((this->states->Inactive)){
					HX_STACK_LINE(220)
					mTopScoreText->set_text((HX_CSTRING("Your Top Score: ") + this->topScore));
				}
			}
		}
		HX_STACK_LINE(222)
		this->addChild(mTopScoreText);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Game_obj,update,(void))


Game_obj::Game_obj()
{
}

void Game_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Game);
	HX_MARK_MEMBER_NAME(states,"states");
	HX_MARK_MEMBER_NAME(topScore,"topScore");
	HX_MARK_MEMBER_NAME(mScore,"mScore");
	HX_MARK_MEMBER_NAME(hitPoint,"hitPoint");
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
	HX_VISIT_MEMBER_NAME(topScore,"topScore");
	HX_VISIT_MEMBER_NAME(mScore,"mScore");
	HX_VISIT_MEMBER_NAME(hitPoint,"hitPoint");
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
		if (HX_FIELD_EQ(inName,"endClick") ) { return endClick_dyn(); }
		if (HX_FIELD_EQ(inName,"topScore") ) { return topScore; }
		if (HX_FIELD_EQ(inName,"hitPoint") ) { return hitPoint; }
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
		if (HX_FIELD_EQ(inName,"topScore") ) { topScore=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"hitPoint") ) { hitPoint=inValue.Cast< ::native::geom::Point >(); return inValue; }
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
	outFields->push(HX_CSTRING("topScore"));
	outFields->push(HX_CSTRING("mScore"));
	outFields->push(HX_CSTRING("hitPoint"));
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
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("endTap"),
	HX_CSTRING("startTouchGame"),
	HX_CSTRING("endClick"),
	HX_CSTRING("startClickGame"),
	HX_CSTRING("check_Collision"),
	HX_CSTRING("update"),
	HX_CSTRING("states"),
	HX_CSTRING("topScore"),
	HX_CSTRING("mScore"),
	HX_CSTRING("hitPoint"),
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
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Game_obj::__mClass,"__mClass");
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
}

} // end namespace com
} // end namespace velvetArts
} // end namespace v01
