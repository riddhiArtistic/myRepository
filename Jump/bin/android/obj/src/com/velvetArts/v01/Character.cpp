#include <hxcpp.h>

#ifndef INCLUDED_com_velvetArts_v01_Character
#include <com/velvetArts/v01/Character.h>
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
namespace com{
namespace velvetArts{
namespace v01{

Void Character_obj::__construct()
{
HX_STACK_PUSH("Character::new","com/velvetArts/v01/Character.hx",23);
{
	HX_STACK_LINE(24)
	super::__construct();
	HX_STACK_LINE(26)
	this->actor = ::native::display::Sprite_obj::__new();
	HX_STACK_LINE(27)
	this->matriX = ::native::geom::Matrix_obj::__new(null(),null(),null(),null(),null(),null());
	HX_STACK_LINE(28)
	this->matriX->identity();
	HX_STACK_LINE(32)
	this->actor->get_graphics()->beginFill((int)16764057,0.8);
	HX_STACK_LINE(33)
	this->actor->get_graphics()->drawCircle((int)0,(int)0,(int)30);
	HX_STACK_LINE(35)
	this->resize();
	HX_STACK_LINE(36)
	this->actor->set_x((Float(-(this->actor->get_width())) / Float(2.0)));
	HX_STACK_LINE(37)
	this->actor->set_y((Float(-(this->actor->get_height())) / Float(2.0)));
	HX_STACK_LINE(39)
	this->addChild(this->actor);
	HX_STACK_LINE(41)
	this->addEventListener(::native::events::Event_obj::RESIZE,this->resizeHandler_dyn(),null(),null(),null());
	HX_STACK_LINE(42)
	this->addEventListener(::native::events::Event_obj::ENTER_FRAME,this->update_dyn(),null(),null(),null());
}
;
	return null();
}

Character_obj::~Character_obj() { }

Dynamic Character_obj::__CreateEmpty() { return  new Character_obj; }
hx::ObjectPtr< Character_obj > Character_obj::__new()
{  hx::ObjectPtr< Character_obj > result = new Character_obj();
	result->__construct();
	return result;}

Dynamic Character_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Character_obj > result = new Character_obj();
	result->__construct();
	return result;}

Void Character_obj::stopDragging( ::native::events::TouchEvent e){
{
		HX_STACK_PUSH("Character::stopDragging","com/velvetArts/v01/Character.hx",92);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(93)
		::nme::Lib_obj::get_current()->get_stage()->removeEventListener(::native::events::TouchEvent_obj::TOUCH_END,this->stopDragging_dyn(),null());
		HX_STACK_LINE(94)
		::nme::Lib_obj::get_current()->get_stage()->removeEventListener(::native::events::TouchEvent_obj::TOUCH_MOVE,this->jump_dyn(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Character_obj,stopDragging,(void))

Void Character_obj::jump( ::native::events::TouchEvent e){
{
		HX_STACK_PUSH("Character::jump","com/velvetArts/v01/Character.hx",78);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(79)
		if (((e->touchPointID == (int)0))){
			HX_STACK_LINE(80)
			if (((bool(((int)30 < e->stageY)) && bool((e->stageY < (::nme::Lib_obj::get_current()->get_stage()->get_stageWidth() - (int)30)))))){
				HX_STACK_LINE(83)
				this->set_y(e->stageY);
			}
		}
		HX_STACK_LINE(88)
		e->updateAfterEvent();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Character_obj,jump,(void))

Void Character_obj::startDragging( ::native::events::TouchEvent e){
{
		HX_STACK_PUSH("Character::startDragging","com/velvetArts/v01/Character.hx",72);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(73)
		::nme::Lib_obj::get_current()->get_stage()->addEventListener(::native::events::TouchEvent_obj::TOUCH_END,this->stopDragging_dyn(),null(),null(),null());
		HX_STACK_LINE(74)
		::nme::Lib_obj::get_current()->get_stage()->addEventListener(::native::events::TouchEvent_obj::TOUCH_MOVE,this->jump_dyn(),null(),null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Character_obj,startDragging,(void))

Void Character_obj::update( ::native::events::Event e){
{
		HX_STACK_PUSH("Character::update","com/velvetArts/v01/Character.hx",59);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(60)
		::nme::Lib_obj::get_current()->get_stage()->addEventListener(::native::events::TouchEvent_obj::TOUCH_BEGIN,this->startDragging_dyn(),null(),null(),null());
		HX_STACK_LINE(62)
		if (((this->get_x() == ::nme::Lib_obj::get_current()->get_stage()->get_stageWidth()))){
			HX_STACK_LINE(63)
			this->set_x((int)10);
		}
		else{
			HX_STACK_LINE(67)
			::com::velvetArts::v01::Character _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(67)
			_g->set_x((_g->get_x() + 2.0));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Character_obj,update,(void))

Void Character_obj::resizeHandler( ::native::events::Event e){
{
		HX_STACK_PUSH("Character::resizeHandler","com/velvetArts/v01/Character.hx",54);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(54)
		this->resize();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Character_obj,resizeHandler,(void))

Void Character_obj::resize( ){
{
		HX_STACK_PUSH("Character::resize","com/velvetArts/v01/Character.hx",46);
		HX_STACK_THIS(this);
		HX_STACK_LINE(49)
		this->set_x((int)10);
		HX_STACK_LINE(50)
		this->set_y((Float(::nme::Lib_obj::get_current()->get_stage()->get_stageHeight()) / Float((int)2)));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Character_obj,resize,(void))


Character_obj::Character_obj()
{
}

void Character_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Character);
	HX_MARK_MEMBER_NAME(matriX,"matriX");
	HX_MARK_MEMBER_NAME(actor,"actor");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Character_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(matriX,"matriX");
	HX_VISIT_MEMBER_NAME(actor,"actor");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Character_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"jump") ) { return jump_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"actor") ) { return actor; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		if (HX_FIELD_EQ(inName,"resize") ) { return resize_dyn(); }
		if (HX_FIELD_EQ(inName,"matriX") ) { return matriX; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"stopDragging") ) { return stopDragging_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"startDragging") ) { return startDragging_dyn(); }
		if (HX_FIELD_EQ(inName,"resizeHandler") ) { return resizeHandler_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Character_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"actor") ) { actor=inValue.Cast< ::native::display::Sprite >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"matriX") ) { matriX=inValue.Cast< ::native::geom::Matrix >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Character_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("matriX"));
	outFields->push(HX_CSTRING("actor"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("stopDragging"),
	HX_CSTRING("jump"),
	HX_CSTRING("startDragging"),
	HX_CSTRING("update"),
	HX_CSTRING("resizeHandler"),
	HX_CSTRING("resize"),
	HX_CSTRING("matriX"),
	HX_CSTRING("actor"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Character_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Character_obj::__mClass,"__mClass");
};

Class Character_obj::__mClass;

void Character_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.velvetArts.v01.Character"), hx::TCanCast< Character_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Character_obj::__boot()
{
}

} // end namespace com
} // end namespace velvetArts
} // end namespace v01
