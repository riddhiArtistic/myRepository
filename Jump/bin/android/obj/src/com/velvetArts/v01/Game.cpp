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
#ifndef INCLUDED_nme_Lib
#include <nme/Lib.h>
#endif
namespace com{
namespace velvetArts{
namespace v01{

Void Game_obj::__construct()
{
HX_STACK_PUSH("Game::new","com/velvetArts/v01/Game.hx",12);
{
	HX_STACK_LINE(22)
	this->cloudHit = false;
	HX_STACK_LINE(21)
	this->rewardHit = false;
	HX_STACK_LINE(27)
	super::__construct();
	HX_STACK_LINE(28)
	::nme::Lib_obj::get_current()->get_stage()->addChild(hx::ObjectPtr<OBJ_>(this));
	HX_STACK_LINE(30)
	this->stgWidth = ::nme::Lib_obj::get_current()->get_stage()->get_stageWidth();
	HX_STACK_LINE(31)
	this->stgHeight = ::nme::Lib_obj::get_current()->get_stage()->get_stageHeight();
	HX_STACK_LINE(33)
	this->bgImg = ::com::velvetArts::v01::MovingBG_obj::__new();
	HX_STACK_LINE(34)
	this->addChild(this->bgImg);
	HX_STACK_LINE(36)
	this->mCandies = Array_obj< ::com::velvetArts::v01::Candy >::__new();
	HX_STACK_LINE(37)
	{
		HX_STACK_LINE(37)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(37)
		while(((_g < (int)7))){
			HX_STACK_LINE(37)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(39)
			Float x_pos = (::Math_obj::random() * this->stgWidth);		HX_STACK_VAR(x_pos,"x_pos");
			HX_STACK_LINE(40)
			Float y_pos = (::Math_obj::random() * this->stgHeight);		HX_STACK_VAR(y_pos,"y_pos");
			HX_STACK_LINE(42)
			this->mCandies[i] = ::com::velvetArts::v01::Candy_obj::__new(x_pos,y_pos);
			HX_STACK_LINE(43)
			this->addChild(this->mCandies->__get(i));
		}
	}
	HX_STACK_LINE(46)
	this->mClouds = Array_obj< ::com::velvetArts::v01::Clouds >::__new();
	HX_STACK_LINE(47)
	{
		HX_STACK_LINE(47)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(47)
		while(((_g < (int)20))){
			HX_STACK_LINE(47)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(49)
			Float x_pos = (::Math_obj::random() * this->stgWidth);		HX_STACK_VAR(x_pos,"x_pos");
			HX_STACK_LINE(50)
			Float y_pos = (::Math_obj::random() * this->stgHeight);		HX_STACK_VAR(y_pos,"y_pos");
			HX_STACK_LINE(52)
			this->mClouds[i] = ::com::velvetArts::v01::Clouds_obj::__new(x_pos,y_pos);
			HX_STACK_LINE(53)
			this->addChild(this->mClouds->__get(i));
		}
	}
	HX_STACK_LINE(56)
	this->baby = ::com::velvetArts::v01::Actor_obj::__new();
	HX_STACK_LINE(57)
	this->addChild(this->baby);
	HX_STACK_LINE(58)
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
		HX_STACK_PUSH("Game::check_Collision","com/velvetArts/v01/Game.hx",87);
		HX_STACK_THIS(this);
		HX_STACK_LINE(88)
		{
			HX_STACK_LINE(88)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(88)
			while(((_g < (int)20))){
				HX_STACK_LINE(88)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(90)
				if ((!(this->cloudHit))){
					HX_STACK_LINE(91)
					if ((::com::velvetArts::v01::PixelPerfectCollision_obj::IsColliding(this->baby,this->mClouds->__get(i),hx::ObjectPtr<OBJ_>(this),false,(int)0))){
						HX_STACK_LINE(94)
						this->cloudHit = true;
						HX_STACK_LINE(95)
						this->baby->set_x(this->mClouds->__get(i)->get_x());
						HX_STACK_LINE(96)
						this->baby->set_y((this->mClouds->__get(i)->get_y() - (int)30));
						HX_STACK_LINE(97)
						this->hitPoint = ::com::velvetArts::v01::PixelPerfectCollision_obj::getCollisionPoint(this->baby,this->mClouds->__get(i),hx::ObjectPtr<OBJ_>(this),false,(int)0);
					}
				}
			}
		}
		HX_STACK_LINE(103)
		{
			HX_STACK_LINE(103)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(103)
			while(((_g < (int)7))){
				HX_STACK_LINE(103)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(105)
				if ((!(this->rewardHit))){
					HX_STACK_LINE(106)
					if ((::com::velvetArts::v01::PixelPerfectCollision_obj::IsColliding(this->baby,this->mCandies->__get(i),hx::ObjectPtr<OBJ_>(this),false,(int)0))){
						HX_STACK_LINE(109)
						this->cloudHit = true;
						HX_STACK_LINE(110)
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
		HX_STACK_PUSH("Game::update","com/velvetArts/v01/Game.hx",62);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(63)
		int stgWidth = ::nme::Lib_obj::get_current()->get_stage()->get_stageWidth();		HX_STACK_VAR(stgWidth,"stgWidth");
		HX_STACK_LINE(64)
		int stgHeight = ::nme::Lib_obj::get_current()->get_stage()->get_stageHeight();		HX_STACK_VAR(stgHeight,"stgHeight");
		HX_STACK_LINE(66)
		this->check_Collision();
		HX_STACK_LINE(67)
		if ((!(this->cloudHit))){
			HX_STACK_LINE(69)
			if (((this->baby->get_x() > stgWidth))){
				HX_STACK_LINE(70)
				this->baby->set_x((int)0);
			}
			else{
				HX_STACK_LINE(72)
				::com::velvetArts::v01::Actor _g = this->baby;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(72)
				_g->set_x((_g->get_x() + 0.5));
			}
			HX_STACK_LINE(74)
			{
				HX_STACK_LINE(74)
				::com::velvetArts::v01::Actor _g = this->baby;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(74)
				_g->set_y((_g->get_y() + 0.5));
			}
		}
		else{
			HX_STACK_LINE(78)
			if (((this->baby->get_x() > stgWidth))){
				HX_STACK_LINE(79)
				this->baby->set_x((int)0);
			}
			else{
				HX_STACK_LINE(81)
				::com::velvetArts::v01::Actor _g = this->baby;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(81)
				_g->set_x((_g->get_x() + (int)1));
			}
			HX_STACK_LINE(82)
			this->cloudHit = !(this->cloudHit);
		}
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
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"mClouds") ) { return mClouds; }
		break;
	case 8:
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
	case 7:
		if (HX_FIELD_EQ(inName,"mClouds") ) { mClouds=inValue.Cast< Array< ::com::velvetArts::v01::Clouds > >(); return inValue; }
		break;
	case 8:
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
