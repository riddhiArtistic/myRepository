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
HX_STACK_PUSH("Game::new","com/velvetArts/v01/Game.hx",15);
{
	HX_STACK_LINE(25)
	this->cloudHit = false;
	HX_STACK_LINE(24)
	this->rewardHit = false;
	HX_STACK_LINE(33)
	super::__construct();
	HX_STACK_LINE(34)
	::nme::Lib_obj::get_current()->get_stage()->addChild(hx::ObjectPtr<OBJ_>(this));
	HX_STACK_LINE(36)
	this->stgWidth = ::nme::Lib_obj::get_current()->get_stage()->get_stageWidth();
	HX_STACK_LINE(37)
	this->stgHeight = ::nme::Lib_obj::get_current()->get_stage()->get_stageHeight();
	HX_STACK_LINE(39)
	this->bgImg = ::com::velvetArts::v01::MovingBG_obj::__new();
	HX_STACK_LINE(40)
	this->addChild(this->bgImg);
	HX_STACK_LINE(42)
	this->mCandies = Array_obj< ::com::velvetArts::v01::Candy >::__new();
	HX_STACK_LINE(43)
	{
		HX_STACK_LINE(43)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(43)
		while(((_g < (int)10))){
			HX_STACK_LINE(43)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(45)
			Float x_pos = (::Math_obj::random() * this->stgWidth);		HX_STACK_VAR(x_pos,"x_pos");
			HX_STACK_LINE(46)
			Float y_pos = (::Math_obj::random() * this->stgHeight);		HX_STACK_VAR(y_pos,"y_pos");
			HX_STACK_LINE(48)
			this->mCandies[i] = ::com::velvetArts::v01::Candy_obj::__new(x_pos,y_pos);
			HX_STACK_LINE(49)
			this->addChild(this->mCandies->__get(i));
		}
	}
	HX_STACK_LINE(52)
	this->mClouds = Array_obj< ::com::velvetArts::v01::Clouds >::__new();
	HX_STACK_LINE(53)
	{
		HX_STACK_LINE(53)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(53)
		while(((_g < (int)20))){
			HX_STACK_LINE(53)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(55)
			Float x_pos = (::Math_obj::random() * this->stgWidth);		HX_STACK_VAR(x_pos,"x_pos");
			HX_STACK_LINE(56)
			Float y_pos = (::Math_obj::random() * this->stgHeight);		HX_STACK_VAR(y_pos,"y_pos");
			HX_STACK_LINE(58)
			this->mClouds[i] = ::com::velvetArts::v01::Clouds_obj::__new(x_pos,y_pos);
			HX_STACK_LINE(59)
			this->addChild(this->mClouds->__get(i));
		}
	}
	HX_STACK_LINE(62)
	this->baby = ::com::velvetArts::v01::Actor_obj::__new();
	HX_STACK_LINE(63)
	this->addChild(this->baby);
	HX_STACK_LINE(64)
	this->mScore = (int)0;
	HX_STACK_LINE(65)
	this->topScore = (int)1000;
	HX_STACK_LINE(66)
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

Void Game_obj::check_Collision( ){
{
		HX_STACK_PUSH("Game::check_Collision","com/velvetArts/v01/Game.hx",154);
		HX_STACK_THIS(this);
		HX_STACK_LINE(155)
		{
			HX_STACK_LINE(155)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(155)
			while(((_g < (int)20))){
				HX_STACK_LINE(155)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(157)
				if ((!(this->cloudHit))){
					HX_STACK_LINE(158)
					if ((::com::velvetArts::v01::PixelPerfectCollision_obj::IsColliding(this->baby,this->mClouds->__get(i),hx::ObjectPtr<OBJ_>(this),false,(int)0))){
						HX_STACK_LINE(161)
						this->cloudHit = true;
						HX_STACK_LINE(162)
						this->baby->set_x(this->mClouds->__get(i)->get_x());
						HX_STACK_LINE(163)
						this->baby->set_y((this->mClouds->__get(i)->get_y() - (int)30));
						HX_STACK_LINE(164)
						this->hitPoint = ::com::velvetArts::v01::PixelPerfectCollision_obj::getCollisionPoint(this->baby,this->mClouds->__get(i),hx::ObjectPtr<OBJ_>(this),false,(int)0);
					}
				}
			}
		}
		HX_STACK_LINE(170)
		{
			HX_STACK_LINE(170)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(170)
			while(((_g < (int)10))){
				HX_STACK_LINE(170)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(172)
				if ((this->mCandies->__get(i)->get_visible())){
					HX_STACK_LINE(173)
					if ((::com::velvetArts::v01::PixelPerfectCollision_obj::IsColliding(this->baby,this->mCandies->__get(i),hx::ObjectPtr<OBJ_>(this),false,(int)0))){
						HX_STACK_LINE(177)
						hx::AddEq(this->mScore,(int)10);
						HX_STACK_LINE(178)
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
		HX_STACK_PUSH("Game::update","com/velvetArts/v01/Game.hx",70);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(71)
		int stgWidth = ::nme::Lib_obj::get_current()->get_stage()->get_stageWidth();		HX_STACK_VAR(stgWidth,"stgWidth");
		HX_STACK_LINE(72)
		int stgHeight = ::nme::Lib_obj::get_current()->get_stage()->get_stageHeight();		HX_STACK_VAR(stgHeight,"stgHeight");
		HX_STACK_LINE(74)
		this->check_Collision();
		HX_STACK_LINE(76)
		if ((!(this->cloudHit))){
			HX_STACK_LINE(78)
			if (((this->baby->get_x() > stgWidth))){
				HX_STACK_LINE(79)
				this->baby->set_x((int)0);
			}
			else{
				HX_STACK_LINE(81)
				::com::velvetArts::v01::Actor _g = this->baby;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(81)
				_g->set_x((_g->get_x() + 0.5));
			}
			HX_STACK_LINE(83)
			if (((this->baby->get_y() > stgHeight))){
				HX_STACK_LINE(85)
				::native::text::TextField mText = ::native::text::TextField_obj::__new();		HX_STACK_VAR(mText,"mText");
				HX_STACK_LINE(86)
				mText->set_x((int)0);
				HX_STACK_LINE(87)
				mText->set_y((Float(stgHeight) / Float((int)2)));
				HX_STACK_LINE(88)
				::native::text::TextFormat format = ::native::text::TextFormat_obj::__new(null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null());		HX_STACK_VAR(format,"format");
				HX_STACK_LINE(90)
				format->font = HX_CSTRING("Arial");
				HX_STACK_LINE(91)
				format->bold = true;
				HX_STACK_LINE(92)
				format->color = (int)255;
				HX_STACK_LINE(93)
				format->size = (int)30;
				HX_STACK_LINE(94)
				format->align = ::native::text::TextFormatAlign_obj::CENTER;
				HX_STACK_LINE(95)
				mText->set_defaultTextFormat(format);
				HX_STACK_LINE(96)
				mText->set_background(false);
				HX_STACK_LINE(97)
				mText->set_text(HX_CSTRING("YOU DIED! :("));
				HX_STACK_LINE(98)
				mText->set_width((int)800);
				HX_STACK_LINE(99)
				mText->set_height((int)40);
				HX_STACK_LINE(100)
				this->addChild(mText);
			}
			HX_STACK_LINE(102)
			{
				HX_STACK_LINE(102)
				::com::velvetArts::v01::Actor _g = this->baby;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(102)
				_g->set_y((_g->get_y() + 0.5));
			}
		}
		else{
			HX_STACK_LINE(106)
			if (((this->baby->get_x() > stgWidth))){
				HX_STACK_LINE(107)
				this->baby->set_x((int)0);
			}
			else{
				HX_STACK_LINE(109)
				::com::velvetArts::v01::Actor _g = this->baby;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(109)
				_g->set_x((_g->get_x() + (int)1));
			}
			HX_STACK_LINE(110)
			this->cloudHit = !(this->cloudHit);
		}
		HX_STACK_LINE(113)
		::native::text::TextField mScoreText = ::native::text::TextField_obj::__new();		HX_STACK_VAR(mScoreText,"mScoreText");
		HX_STACK_LINE(114)
		::native::text::TextFormat format = ::native::text::TextFormat_obj::__new(null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null());		HX_STACK_VAR(format,"format");
		HX_STACK_LINE(116)
		format->font = HX_CSTRING("Arial");
		HX_STACK_LINE(117)
		format->bold = true;
		HX_STACK_LINE(118)
		format->color = (int)34850;
		HX_STACK_LINE(119)
		format->size = (int)20;
		HX_STACK_LINE(120)
		format->align = ::native::text::TextFormatAlign_obj::LEFT;
		HX_STACK_LINE(122)
		mScoreText->set_x((int)10);
		HX_STACK_LINE(123)
		mScoreText->set_y((int)20);
		HX_STACK_LINE(124)
		mScoreText->set_width((int)200);
		HX_STACK_LINE(125)
		mScoreText->set_height((int)30);
		HX_STACK_LINE(126)
		mScoreText->set_defaultTextFormat(format);
		HX_STACK_LINE(127)
		mScoreText->set_background(false);
		HX_STACK_LINE(128)
		mScoreText->set_text((HX_CSTRING("Score: ") + this->mScore));
		HX_STACK_LINE(129)
		this->addChild(mScoreText);
		HX_STACK_LINE(131)
		::native::text::TextField mTopScoreText = ::native::text::TextField_obj::__new();		HX_STACK_VAR(mTopScoreText,"mTopScoreText");
		HX_STACK_LINE(132)
		::native::text::TextFormat format1 = ::native::text::TextFormat_obj::__new(null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null());		HX_STACK_VAR(format1,"format1");
		HX_STACK_LINE(134)
		format1->font = HX_CSTRING("Arial");
		HX_STACK_LINE(135)
		format1->bold = true;
		HX_STACK_LINE(136)
		format1->color = (int)34850;
		HX_STACK_LINE(137)
		format1->size = (int)20;
		HX_STACK_LINE(138)
		format1->align = ::native::text::TextFormatAlign_obj::RIGHT;
		HX_STACK_LINE(140)
		mTopScoreText->set_x((stgWidth - (int)210));
		HX_STACK_LINE(141)
		mTopScoreText->set_y((int)20);
		HX_STACK_LINE(142)
		mTopScoreText->set_width((int)200);
		HX_STACK_LINE(143)
		mTopScoreText->set_height((int)30);
		HX_STACK_LINE(144)
		mTopScoreText->set_defaultTextFormat(format1);
		HX_STACK_LINE(145)
		mTopScoreText->set_background(false);
		HX_STACK_LINE(146)
		if (((this->topScore < this->mScore))){
			HX_STACK_LINE(147)
			mTopScoreText->set_text((HX_CSTRING("Top Score = ") + this->mScore));
		}
		else{
			HX_STACK_LINE(149)
			mTopScoreText->set_text((HX_CSTRING("Score: ") + this->topScore));
		}
		HX_STACK_LINE(150)
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
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		if (HX_FIELD_EQ(inName,"mScore") ) { return mScore; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"mClouds") ) { return mClouds; }
		break;
	case 8:
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
	HX_CSTRING("check_Collision"),
	HX_CSTRING("update"),
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
