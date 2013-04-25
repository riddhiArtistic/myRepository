#include <hxcpp.h>

#ifndef INCLUDED_com_velvetArts_v01_Actor
#include <com/velvetArts/v01/Actor.h>
#endif
#ifndef INCLUDED_native_display_BitmapData
#include <native/display/BitmapData.h>
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
#ifndef INCLUDED_native_geom_Matrix
#include <native/geom/Matrix.h>
#endif
#ifndef INCLUDED_nme_Lib
#include <nme/Lib.h>
#endif
#ifndef INCLUDED_nme_installer_Assets
#include <nme/installer/Assets.h>
#endif
namespace com{
namespace velvetArts{
namespace v01{

Void Actor_obj::__construct()
{
HX_STACK_PUSH("Actor::new","com/velvetArts/v01/Actor.hx",15);
{
	HX_STACK_LINE(17)
	this->IsActive = false;
	HX_STACK_LINE(26)
	super::__construct();
	HX_STACK_LINE(27)
	this->actor = ::native::display::Sprite_obj::__new();
	HX_STACK_LINE(29)
	this->actor->get_graphics()->beginBitmapFill(::nme::installer::Assets_obj::getBitmapData(HX_CSTRING("img/baby.png"),null()),null(),false,true);
	HX_STACK_LINE(32)
	this->actor->get_graphics()->drawRect((int)0,(int)0,(int)60,(int)60);
	HX_STACK_LINE(34)
	this->actor->set_x((Float(-(this->actor->get_width())) / Float(2.0)));
	HX_STACK_LINE(35)
	this->actor->set_y((Float(-(this->actor->get_height())) / Float(2.0)));
	HX_STACK_LINE(37)
	this->set_x((Float(::nme::Lib_obj::get_current()->get_stage()->get_stageWidth()) / Float(2.0)));
	HX_STACK_LINE(38)
	this->set_y((Float(::nme::Lib_obj::get_current()->get_stage()->get_stageHeight()) / Float(2.0)));
	HX_STACK_LINE(40)
	this->addChild(this->actor);
	HX_STACK_LINE(42)
	this->jumpFlag = false;
	HX_STACK_LINE(43)
	this->jumpBKW = false;
	HX_STACK_LINE(44)
	this->jumpFWD = false;
}
;
	return null();
}

Actor_obj::~Actor_obj() { }

Dynamic Actor_obj::__CreateEmpty() { return  new Actor_obj; }
hx::ObjectPtr< Actor_obj > Actor_obj::__new()
{  hx::ObjectPtr< Actor_obj > result = new Actor_obj();
	result->__construct();
	return result;}

Dynamic Actor_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Actor_obj > result = new Actor_obj();
	result->__construct();
	return result;}

Void Actor_obj::stopMove( ::native::events::MouseEvent e){
{
		HX_STACK_PUSH("Actor::stopMove","com/velvetArts/v01/Actor.hx",105);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(106)
		this->jumpFlag = false;
		HX_STACK_LINE(107)
		::nme::Lib_obj::get_current()->get_stage()->removeEventListener(::native::events::MouseEvent_obj::MOUSE_MOVE,this->Move_dyn(),null());
		HX_STACK_LINE(108)
		::nme::Lib_obj::get_current()->get_stage()->removeEventListener(::native::events::MouseEvent_obj::MOUSE_DOWN,this->en_Move_dyn(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Actor_obj,stopMove,(void))

Void Actor_obj::Move( ::native::events::MouseEvent e){
{
		HX_STACK_PUSH("Actor::Move","com/velvetArts/v01/Actor.hx",97);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(97)
		if (((bool(((int)30 < e->stageY)) && bool((e->stageY < (::nme::Lib_obj::get_current()->get_stage()->get_stageWidth() - (int)30)))))){
			HX_STACK_LINE(99)
			this->jumpFlag = true;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Actor_obj,Move,(void))

Void Actor_obj::en_Move( ::native::events::MouseEvent e){
{
		HX_STACK_PUSH("Actor::en_Move","com/velvetArts/v01/Actor.hx",89);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(90)
		::nme::Lib_obj::get_current()->get_stage()->addEventListener(::native::events::MouseEvent_obj::MOUSE_MOVE,this->Move_dyn(),null(),null(),null());
		HX_STACK_LINE(91)
		::nme::Lib_obj::get_current()->get_stage()->addEventListener(::native::events::MouseEvent_obj::MOUSE_UP,this->stopMove_dyn(),null(),null(),null());
		HX_STACK_LINE(93)
		e->updateAfterEvent();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Actor_obj,en_Move,(void))

Void Actor_obj::stopDragging( ::native::events::TouchEvent e){
{
		HX_STACK_PUSH("Actor::stopDragging","com/velvetArts/v01/Actor.hx",82);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(83)
		this->jumpFlag = false;
		HX_STACK_LINE(84)
		::nme::Lib_obj::get_current()->get_stage()->removeEventListener(::native::events::TouchEvent_obj::TOUCH_END,this->stopDragging_dyn(),null());
		HX_STACK_LINE(85)
		::nme::Lib_obj::get_current()->get_stage()->removeEventListener(::native::events::TouchEvent_obj::TOUCH_MOVE,this->jump_dyn(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Actor_obj,stopDragging,(void))

Void Actor_obj::jump( ::native::events::TouchEvent e){
{
		HX_STACK_PUSH("Actor::jump","com/velvetArts/v01/Actor.hx",67);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(67)
		if ((this->IsActive)){
			HX_STACK_LINE(69)
			if (((e->touchPointID == (int)0))){
				HX_STACK_LINE(71)
				if (((bool(((int)30 < e->stageY)) && bool((e->stageY < (::nme::Lib_obj::get_current()->get_stage()->get_stageWidth() - (int)30)))))){
					HX_STACK_LINE(73)
					this->jumpFlag = true;
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Actor_obj,jump,(void))

Void Actor_obj::startDragging( ::native::events::TouchEvent e){
{
		HX_STACK_PUSH("Actor::startDragging","com/velvetArts/v01/Actor.hx",57);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(57)
		if ((this->IsActive)){
			HX_STACK_LINE(60)
			this->mouse_X = e->stageX;
			HX_STACK_LINE(61)
			::nme::Lib_obj::get_current()->get_stage()->addEventListener(::native::events::TouchEvent_obj::TOUCH_END,this->stopDragging_dyn(),null(),null(),null());
			HX_STACK_LINE(62)
			::nme::Lib_obj::get_current()->get_stage()->addEventListener(::native::events::TouchEvent_obj::TOUCH_MOVE,this->jump_dyn(),null(),null(),null());
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Actor_obj,startDragging,(void))

Void Actor_obj::update( ){
{
		HX_STACK_PUSH("Actor::update","com/velvetArts/v01/Actor.hx",48);
		HX_STACK_THIS(this);
		HX_STACK_LINE(48)
		if ((this->IsActive)){
			HX_STACK_LINE(51)
			::nme::Lib_obj::get_current()->get_stage()->addEventListener(::native::events::TouchEvent_obj::TOUCH_BEGIN,this->startDragging_dyn(),null(),null(),null());
			HX_STACK_LINE(52)
			::nme::Lib_obj::get_current()->get_stage()->addEventListener(::native::events::MouseEvent_obj::MOUSE_DOWN,this->en_Move_dyn(),null(),null(),null());
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Actor_obj,update,(void))


Actor_obj::Actor_obj()
{
}

void Actor_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Actor);
	HX_MARK_MEMBER_NAME(mouse_X,"mouse_X");
	HX_MARK_MEMBER_NAME(jumpBKW,"jumpBKW");
	HX_MARK_MEMBER_NAME(jumpFWD,"jumpFWD");
	HX_MARK_MEMBER_NAME(jumpFlag,"jumpFlag");
	HX_MARK_MEMBER_NAME(actor,"actor");
	HX_MARK_MEMBER_NAME(IsActive,"IsActive");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Actor_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(mouse_X,"mouse_X");
	HX_VISIT_MEMBER_NAME(jumpBKW,"jumpBKW");
	HX_VISIT_MEMBER_NAME(jumpFWD,"jumpFWD");
	HX_VISIT_MEMBER_NAME(jumpFlag,"jumpFlag");
	HX_VISIT_MEMBER_NAME(actor,"actor");
	HX_VISIT_MEMBER_NAME(IsActive,"IsActive");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Actor_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"Move") ) { return Move_dyn(); }
		if (HX_FIELD_EQ(inName,"jump") ) { return jump_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"actor") ) { return actor; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"en_Move") ) { return en_Move_dyn(); }
		if (HX_FIELD_EQ(inName,"mouse_X") ) { return mouse_X; }
		if (HX_FIELD_EQ(inName,"jumpBKW") ) { return jumpBKW; }
		if (HX_FIELD_EQ(inName,"jumpFWD") ) { return jumpFWD; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"stopMove") ) { return stopMove_dyn(); }
		if (HX_FIELD_EQ(inName,"jumpFlag") ) { return jumpFlag; }
		if (HX_FIELD_EQ(inName,"IsActive") ) { return IsActive; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"stopDragging") ) { return stopDragging_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"startDragging") ) { return startDragging_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Actor_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"actor") ) { actor=inValue.Cast< ::native::display::Sprite >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"mouse_X") ) { mouse_X=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"jumpBKW") ) { jumpBKW=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"jumpFWD") ) { jumpFWD=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"jumpFlag") ) { jumpFlag=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"IsActive") ) { IsActive=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Actor_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("mouse_X"));
	outFields->push(HX_CSTRING("jumpBKW"));
	outFields->push(HX_CSTRING("jumpFWD"));
	outFields->push(HX_CSTRING("jumpFlag"));
	outFields->push(HX_CSTRING("actor"));
	outFields->push(HX_CSTRING("IsActive"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("stopMove"),
	HX_CSTRING("Move"),
	HX_CSTRING("en_Move"),
	HX_CSTRING("stopDragging"),
	HX_CSTRING("jump"),
	HX_CSTRING("startDragging"),
	HX_CSTRING("update"),
	HX_CSTRING("mouse_X"),
	HX_CSTRING("jumpBKW"),
	HX_CSTRING("jumpFWD"),
	HX_CSTRING("jumpFlag"),
	HX_CSTRING("actor"),
	HX_CSTRING("IsActive"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Actor_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Actor_obj::__mClass,"__mClass");
};

Class Actor_obj::__mClass;

void Actor_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.velvetArts.v01.Actor"), hx::TCanCast< Actor_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Actor_obj::__boot()
{
}

} // end namespace com
} // end namespace velvetArts
} // end namespace v01
