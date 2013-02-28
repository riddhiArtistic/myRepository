#include <hxcpp.h>

#ifndef INCLUDED_com_velvetArts_v01_MovingBG
#include <com/velvetArts/v01/MovingBG.h>
#endif
#ifndef INCLUDED_native_display_Bitmap
#include <native/display/Bitmap.h>
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
#ifndef INCLUDED_native_display_IBitmapDrawable
#include <native/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_native_display_InteractiveObject
#include <native/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_native_display_MovieClip
#include <native/display/MovieClip.h>
#endif
#ifndef INCLUDED_native_display_PixelSnapping
#include <native/display/PixelSnapping.h>
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
#ifndef INCLUDED_nme_Lib
#include <nme/Lib.h>
#endif
#ifndef INCLUDED_nme_installer_Assets
#include <nme/installer/Assets.h>
#endif
namespace com{
namespace velvetArts{
namespace v01{

Void MovingBG_obj::__construct()
{
HX_STACK_PUSH("MovingBG::new","com/velvetArts/v01/MovingBG.hx",20);
{
	HX_STACK_LINE(21)
	super::__construct();
	HX_STACK_LINE(22)
	this->BG = ::native::display::Bitmap_obj::__new(::nme::installer::Assets_obj::getBitmapData(HX_CSTRING("img/movingBG.png"),null()),null(),null());
	HX_STACK_LINE(24)
	this->resize();
	HX_STACK_LINE(25)
	this->addChild(this->BG);
	HX_STACK_LINE(27)
	this->addEventListener(::native::events::Event_obj::RESIZE,this->resizeHandler_dyn(),null(),null(),null());
}
;
	return null();
}

MovingBG_obj::~MovingBG_obj() { }

Dynamic MovingBG_obj::__CreateEmpty() { return  new MovingBG_obj; }
hx::ObjectPtr< MovingBG_obj > MovingBG_obj::__new()
{  hx::ObjectPtr< MovingBG_obj > result = new MovingBG_obj();
	result->__construct();
	return result;}

Dynamic MovingBG_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< MovingBG_obj > result = new MovingBG_obj();
	result->__construct();
	return result;}

Void MovingBG_obj::resizeHandler( ::native::events::Event e){
{
		HX_STACK_PUSH("MovingBG::resizeHandler","com/velvetArts/v01/MovingBG.hx",37);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(37)
		this->resize();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MovingBG_obj,resizeHandler,(void))

Void MovingBG_obj::resize( ){
{
		HX_STACK_PUSH("MovingBG::resize","com/velvetArts/v01/MovingBG.hx",31);
		HX_STACK_THIS(this);
		HX_STACK_LINE(32)
		this->BG->set_x((Float(((::nme::Lib_obj::get_current()->get_stage()->get_stageWidth() - this->BG->get_width()))) / Float((int)2)));
		HX_STACK_LINE(33)
		this->BG->set_y((Float(((::nme::Lib_obj::get_current()->get_stage()->get_stageHeight() - this->BG->get_height()))) / Float((int)2)));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(MovingBG_obj,resize,(void))


MovingBG_obj::MovingBG_obj()
{
}

void MovingBG_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(MovingBG);
	HX_MARK_MEMBER_NAME(BG,"BG");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void MovingBG_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(BG,"BG");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic MovingBG_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"BG") ) { return BG; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"resize") ) { return resize_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"resizeHandler") ) { return resizeHandler_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic MovingBG_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"BG") ) { BG=inValue.Cast< ::native::display::Bitmap >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void MovingBG_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("BG"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("resizeHandler"),
	HX_CSTRING("resize"),
	HX_CSTRING("BG"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(MovingBG_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(MovingBG_obj::__mClass,"__mClass");
};

Class MovingBG_obj::__mClass;

void MovingBG_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.velvetArts.v01.MovingBG"), hx::TCanCast< MovingBG_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void MovingBG_obj::__boot()
{
}

} // end namespace com
} // end namespace velvetArts
} // end namespace v01