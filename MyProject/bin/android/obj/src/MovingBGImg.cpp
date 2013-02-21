#include <hxcpp.h>

#ifndef INCLUDED_MovingBGImg
#include <MovingBGImg.h>
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
#ifndef INCLUDED_nme_installer_Assets
#include <nme/installer/Assets.h>
#endif

Void MovingBGImg_obj::__construct()
{
HX_STACK_PUSH("MovingBGImg::new","MovingBGImg.hx",23);
{
	HX_STACK_LINE(24)
	super::__construct();
	HX_STACK_LINE(28)
	this->addEventListener(::native::events::Event_obj::ADDED_TO_STAGE,this->init_dyn(),null(),null(),null());
}
;
	return null();
}

MovingBGImg_obj::~MovingBGImg_obj() { }

Dynamic MovingBGImg_obj::__CreateEmpty() { return  new MovingBGImg_obj; }
hx::ObjectPtr< MovingBGImg_obj > MovingBGImg_obj::__new()
{  hx::ObjectPtr< MovingBGImg_obj > result = new MovingBGImg_obj();
	result->__construct();
	return result;}

Dynamic MovingBGImg_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< MovingBGImg_obj > result = new MovingBGImg_obj();
	result->__construct();
	return result;}

Void MovingBGImg_obj::init( Dynamic e){
{
		HX_STACK_PUSH("MovingBGImg::init","MovingBGImg.hx",33);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(35)
		this->myBG = ::native::display::Bitmap_obj::__new(::nme::installer::Assets_obj::getBitmapData(HX_CSTRING("assets/movingBG.png"),null()),null(),null());
		HX_STACK_LINE(36)
		this->myBG->set_alpha((int)1);
		HX_STACK_LINE(38)
		this->myBG->set_x((Float(((this->get_stage()->get_stageWidth() - this->myBG->get_width()))) / Float((int)2)));
		HX_STACK_LINE(39)
		this->myBG->set_y((Float(((this->get_stage()->get_stageHeight() - this->myBG->get_height()))) / Float((int)2)));
		HX_STACK_LINE(41)
		this->addChild(this->myBG);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MovingBGImg_obj,init,(void))


MovingBGImg_obj::MovingBGImg_obj()
{
}

void MovingBGImg_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(MovingBGImg);
	HX_MARK_MEMBER_NAME(myBG,"myBG");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void MovingBGImg_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(myBG,"myBG");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic MovingBGImg_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"init") ) { return init_dyn(); }
		if (HX_FIELD_EQ(inName,"myBG") ) { return myBG; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic MovingBGImg_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"myBG") ) { myBG=inValue.Cast< ::native::display::Bitmap >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void MovingBGImg_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("myBG"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("init"),
	HX_CSTRING("myBG"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(MovingBGImg_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(MovingBGImg_obj::__mClass,"__mClass");
};

Class MovingBGImg_obj::__mClass;

void MovingBGImg_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("MovingBGImg"), hx::TCanCast< MovingBGImg_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void MovingBGImg_obj::__boot()
{
}

