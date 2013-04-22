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
HX_STACK_PUSH("Character::new","com/velvetArts/v01/Character.hx",24);
{
	HX_STACK_LINE(25)
	super::__construct();
	HX_STACK_LINE(27)
	this->resize();
	HX_STACK_LINE(29)
	this->addEventListener(::native::events::Event_obj::RESIZE,this->resizeHandler_dyn(),null(),null(),null());
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

Void Character_obj::resizeHandler( ::native::events::Event e){
{
		HX_STACK_PUSH("Character::resizeHandler","com/velvetArts/v01/Character.hx",40);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(40)
		this->resize();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Character_obj,resizeHandler,(void))

Void Character_obj::resize( ){
{
		HX_STACK_PUSH("Character::resize","com/velvetArts/v01/Character.hx",33);
		HX_STACK_THIS(this);
		HX_STACK_LINE(35)
		this->set_x((Float(::nme::Lib_obj::get_current()->get_stage()->get_stageWidth()) / Float((int)2)));
		HX_STACK_LINE(36)
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
	case 5:
		if (HX_FIELD_EQ(inName,"actor") ) { return actor; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"resize") ) { return resize_dyn(); }
		if (HX_FIELD_EQ(inName,"matriX") ) { return matriX; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"mouseMove") ) { return mouseMove; }
		break;
	case 13:
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
