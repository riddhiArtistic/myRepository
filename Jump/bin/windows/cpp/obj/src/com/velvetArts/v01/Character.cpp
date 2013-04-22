#include <hxcpp.h>

#ifndef INCLUDED_com_velvetArts_v01_Character
#include <com/velvetArts/v01/Character.h>
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

Void Character_obj::__construct()
{
HX_STACK_PUSH("Character::new","com/velvetArts/v01/Character.hx",24);
{
	HX_STACK_LINE(25)
	super::__construct();
	HX_STACK_LINE(27)
	this->actor = ::native::display::Sprite_obj::__new();
	HX_STACK_LINE(28)
	this->matriX = ::native::geom::Matrix_obj::__new(null(),null(),null(),null(),null(),null());
	HX_STACK_LINE(30)
	this->matriX->translate((int)-30,(int)-30);
	HX_STACK_LINE(32)
	this->actor->get_graphics()->beginBitmapFill(::nme::installer::Assets_obj::getBitmapData(HX_CSTRING("img/baby.png"),null()),null(),false,true);
	HX_STACK_LINE(35)
	this->actor->get_graphics()->drawRect((int)0,(int)0,(int)60,(int)60);
	HX_STACK_LINE(37)
	this->resize();
	HX_STACK_LINE(39)
	this->actor->set_x((Float(-(this->actor->get_width())) / Float(2.0)));
	HX_STACK_LINE(40)
	this->actor->set_y((Float(-(this->actor->get_height())) / Float(2.0)));
	HX_STACK_LINE(42)
	this->addChild(this->actor);
	HX_STACK_LINE(44)
	this->addEventListener(::native::events::Event_obj::RESIZE,this->resizeHandler_dyn(),null(),null(),null());
	HX_STACK_LINE(45)
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

Void Character_obj::stopMove( ::native::events::MouseEvent e){
{
		HX_STACK_PUSH("Character::stopMove","com/velvetArts/v01/Character.hx",120);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(121)
		::nme::Lib_obj::get_current()->get_stage()->removeEventListener(::native::events::MouseEvent_obj::MOUSE_MOVE,this->Move_dyn(),null());
		HX_STACK_LINE(122)
		::nme::Lib_obj::get_current()->get_stage()->removeEventListener(::native::events::MouseEvent_obj::MOUSE_DOWN,this->en_Move_dyn(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Character_obj,stopMove,(void))

Void Character_obj::Move( ::native::events::MouseEvent e){
{
		HX_STACK_PUSH("Character::Move","com/velvetArts/v01/Character.hx",111);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(111)
		if (((bool(((int)30 < e->stageY)) && bool((e->stageY < (::nme::Lib_obj::get_current()->get_stage()->get_stageWidth() - (int)30)))))){
			HX_STACK_LINE(114)
			this->set_y(e->stageY);
			HX_STACK_LINE(115)
			this->set_x(e->stageX);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Character_obj,Move,(void))

Void Character_obj::en_Move( ::native::events::MouseEvent e){
{
		HX_STACK_PUSH("Character::en_Move","com/velvetArts/v01/Character.hx",103);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(104)
		::nme::Lib_obj::get_current()->get_stage()->addEventListener(::native::events::MouseEvent_obj::MOUSE_MOVE,this->Move_dyn(),null(),null(),null());
		HX_STACK_LINE(105)
		::nme::Lib_obj::get_current()->get_stage()->addEventListener(::native::events::MouseEvent_obj::MOUSE_UP,this->stopMove_dyn(),null(),null(),null());
		HX_STACK_LINE(107)
		e->updateAfterEvent();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Character_obj,en_Move,(void))

Void Character_obj::stopDragging( ::native::events::TouchEvent e){
{
		HX_STACK_PUSH("Character::stopDragging","com/velvetArts/v01/Character.hx",97);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(98)
		::nme::Lib_obj::get_current()->get_stage()->removeEventListener(::native::events::TouchEvent_obj::TOUCH_END,this->stopDragging_dyn(),null());
		HX_STACK_LINE(99)
		::nme::Lib_obj::get_current()->get_stage()->removeEventListener(::native::events::TouchEvent_obj::TOUCH_MOVE,this->jump_dyn(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Character_obj,stopDragging,(void))

Void Character_obj::jump( ::native::events::TouchEvent e){
{
		HX_STACK_PUSH("Character::jump","com/velvetArts/v01/Character.hx",82);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(83)
		if (((e->touchPointID == (int)0))){
			HX_STACK_LINE(84)
			if (((bool(((int)30 < e->stageY)) && bool((e->stageY < (::nme::Lib_obj::get_current()->get_stage()->get_stageWidth() - (int)30)))))){
				HX_STACK_LINE(88)
				this->set_y(e->stageY);
				HX_STACK_LINE(89)
				this->set_x(e->stageX);
			}
		}
		HX_STACK_LINE(93)
		e->updateAfterEvent();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Character_obj,jump,(void))

Void Character_obj::startDragging( ::native::events::TouchEvent e){
{
		HX_STACK_PUSH("Character::startDragging","com/velvetArts/v01/Character.hx",76);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(77)
		::nme::Lib_obj::get_current()->get_stage()->addEventListener(::native::events::TouchEvent_obj::TOUCH_END,this->stopDragging_dyn(),null(),null(),null());
		HX_STACK_LINE(78)
		::nme::Lib_obj::get_current()->get_stage()->addEventListener(::native::events::TouchEvent_obj::TOUCH_MOVE,this->jump_dyn(),null(),null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Character_obj,startDragging,(void))

Void Character_obj::update( ::native::events::Event e){
{
		HX_STACK_PUSH("Character::update","com/velvetArts/v01/Character.hx",62);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(63)
		::nme::Lib_obj::get_current()->get_stage()->addEventListener(::native::events::TouchEvent_obj::TOUCH_BEGIN,this->startDragging_dyn(),null(),null(),null());
		HX_STACK_LINE(64)
		::nme::Lib_obj::get_current()->get_stage()->addEventListener(::native::events::MouseEvent_obj::MOUSE_DOWN,this->en_Move_dyn(),null(),null(),null());
		HX_STACK_LINE(66)
		if (((this->get_x() == ::nme::Lib_obj::get_current()->get_stage()->get_stageWidth()))){
			HX_STACK_LINE(67)
			this->set_x((int)10);
		}
		else{
			HX_STACK_LINE(71)
			::com::velvetArts::v01::Character _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(71)
			_g->set_x((_g->get_x() + 2.0));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Character_obj,update,(void))

Void Character_obj::resizeHandler( ::native::events::Event e){
{
		HX_STACK_PUSH("Character::resizeHandler","com/velvetArts/v01/Character.hx",57);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(57)
		this->resize();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Character_obj,resizeHandler,(void))

Void Character_obj::resize( ){
{
		HX_STACK_PUSH("Character::resize","com/velvetArts/v01/Character.hx",49);
		HX_STACK_THIS(this);
		HX_STACK_LINE(52)
		this->set_x((int)10);
		HX_STACK_LINE(53)
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
	HX_MARK_MEMBER_NAME(mouseMove,"mouseMove");
	HX_MARK_MEMBER_NAME(matriX,"matriX");
	HX_MARK_MEMBER_NAME(actor,"actor");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Character_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(mouseMove,"mouseMove");
	HX_VISIT_MEMBER_NAME(matriX,"matriX");
	HX_VISIT_MEMBER_NAME(actor,"actor");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Character_obj::__Field(const ::String &inName,bool inCallProp)
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
		if (HX_FIELD_EQ(inName,"resize") ) { return resize_dyn(); }
		if (HX_FIELD_EQ(inName,"matriX") ) { return matriX; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"en_Move") ) { return en_Move_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"stopMove") ) { return stopMove_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"mouseMove") ) { return mouseMove; }
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
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"mouseMove") ) { mouseMove=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Character_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("mouseMove"));
	outFields->push(HX_CSTRING("matriX"));
	outFields->push(HX_CSTRING("actor"));
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
	HX_CSTRING("resizeHandler"),
	HX_CSTRING("resize"),
	HX_CSTRING("mouseMove"),
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
