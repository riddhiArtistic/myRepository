#include <hxcpp.h>

#ifndef INCLUDED_BackGroundImg
#include <BackGroundImg.h>
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

Void BackGroundImg_obj::__construct()
{
HX_STACK_PUSH("BackGroundImg::new","BackGroundImg.hx",21);
{
	HX_STACK_LINE(22)
	super::__construct();
	HX_STACK_LINE(26)
	this->addEventListener(::native::events::Event_obj::ADDED_TO_STAGE,this->init_dyn(),null(),null(),null());
}
;
	return null();
}

BackGroundImg_obj::~BackGroundImg_obj() { }

Dynamic BackGroundImg_obj::__CreateEmpty() { return  new BackGroundImg_obj; }
hx::ObjectPtr< BackGroundImg_obj > BackGroundImg_obj::__new()
{  hx::ObjectPtr< BackGroundImg_obj > result = new BackGroundImg_obj();
	result->__construct();
	return result;}

Dynamic BackGroundImg_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BackGroundImg_obj > result = new BackGroundImg_obj();
	result->__construct();
	return result;}

Void BackGroundImg_obj::init( Dynamic e){
{
		HX_STACK_PUSH("BackGroundImg::init","BackGroundImg.hx",31);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(33)
		this->myBG = ::native::display::Bitmap_obj::__new(::nme::installer::Assets_obj::getBitmapData(HX_CSTRING("assets/BackGround.png"),null()),null(),null());
		HX_STACK_LINE(34)
		this->myBG->set_alpha((int)1);
		HX_STACK_LINE(36)
		this->myBG->set_x((Float(((this->get_stage()->get_stageWidth() - this->myBG->get_width()))) / Float((int)2)));
		HX_STACK_LINE(37)
		this->myBG->set_y((Float(((this->get_stage()->get_stageHeight() - this->myBG->get_height()))) / Float((int)2)));
		HX_STACK_LINE(39)
		this->addChild(this->myBG);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BackGroundImg_obj,init,(void))


BackGroundImg_obj::BackGroundImg_obj()
{
}

void BackGroundImg_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BackGroundImg);
	HX_MARK_MEMBER_NAME(myBG,"myBG");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void BackGroundImg_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(myBG,"myBG");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic BackGroundImg_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"init") ) { return init_dyn(); }
		if (HX_FIELD_EQ(inName,"myBG") ) { return myBG; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic BackGroundImg_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"myBG") ) { myBG=inValue.Cast< ::native::display::Bitmap >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void BackGroundImg_obj::__GetFields(Array< ::String> &outFields)
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
	HX_MARK_MEMBER_NAME(BackGroundImg_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BackGroundImg_obj::__mClass,"__mClass");
};

Class BackGroundImg_obj::__mClass;

void BackGroundImg_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("BackGroundImg"), hx::TCanCast< BackGroundImg_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void BackGroundImg_obj::__boot()
{
}

