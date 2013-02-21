#include <hxcpp.h>

#ifndef INCLUDED_Character
#include <Character.h>
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

Void Character_obj::__construct()
{
HX_STACK_PUSH("Character::new","Character.hx",24);
{
	HX_STACK_LINE(25)
	super::__construct();
	HX_STACK_LINE(29)
	this->addEventListener(::native::events::Event_obj::ADDED_TO_STAGE,this->init_dyn(),null(),null(),null());
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

Void Character_obj::updateImg( ::native::events::Event eve){
{
		HX_STACK_PUSH("Character::updateImg","Character.hx",55);
		HX_STACK_THIS(this);
		HX_STACK_ARG(eve,"eve");
		HX_STACK_LINE(56)
		this->myBitmap->set_alpha((int)1);
		HX_STACK_LINE(57)
		{
			HX_STACK_LINE(57)
			::native::display::Sprite _g = this->container;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(57)
			_g->set_rotation((_g->get_rotation() + 5.0));
		}
		HX_STACK_LINE(58)
		if (((this->container->get_x() >= (this->get_stage()->get_stageWidth() - (int)20)))){
			HX_STACK_LINE(59)
			this->container->set_x((int)20);
		}
		else{
			HX_STACK_LINE(62)
			::native::display::Sprite _g = this->container;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(62)
			_g->set_x((_g->get_x() + (int)1));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Character_obj,updateImg,(void))

Void Character_obj::init( Dynamic e){
{
		HX_STACK_PUSH("Character::init","Character.hx",34);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(36)
		this->myBitmap = ::native::display::Bitmap_obj::__new(::nme::installer::Assets_obj::getBitmapData(HX_CSTRING("assets/baby.png"),null()),null(),null());
		HX_STACK_LINE(37)
		this->container = ::native::display::Sprite_obj::__new();
		HX_STACK_LINE(38)
		this->container->addChild(this->myBitmap);
		HX_STACK_LINE(40)
		this->container->set_x((int)20);
		HX_STACK_LINE(41)
		this->container->set_y((Float(this->get_stage()->get_stageHeight()) / Float((int)2)));
		HX_STACK_LINE(42)
		this->myBitmap->set_alpha((int)0);
		HX_STACK_LINE(44)
		this->myBitmap->set_x((Float(-(this->myBitmap->get_width())) / Float((int)2)));
		HX_STACK_LINE(45)
		this->myBitmap->set_y((Float(-(this->myBitmap->get_height())) / Float((int)2)));
		HX_STACK_LINE(47)
		this->container->buttonMode = true;
		HX_STACK_LINE(49)
		this->addChild(this->container);
		HX_STACK_LINE(50)
		this->addEventListener(::native::events::Event_obj::ENTER_FRAME,this->updateImg_dyn(),null(),null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Character_obj,init,(void))


Character_obj::Character_obj()
{
}

void Character_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Character);
	HX_MARK_MEMBER_NAME(container,"container");
	HX_MARK_MEMBER_NAME(myBitmap,"myBitmap");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Character_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(container,"container");
	HX_VISIT_MEMBER_NAME(myBitmap,"myBitmap");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Character_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"init") ) { return init_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"myBitmap") ) { return myBitmap; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"updateImg") ) { return updateImg_dyn(); }
		if (HX_FIELD_EQ(inName,"container") ) { return container; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Character_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"myBitmap") ) { myBitmap=inValue.Cast< ::native::display::Bitmap >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"container") ) { container=inValue.Cast< ::native::display::Sprite >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Character_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("container"));
	outFields->push(HX_CSTRING("myBitmap"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("updateImg"),
	HX_CSTRING("init"),
	HX_CSTRING("container"),
	HX_CSTRING("myBitmap"),
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
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("Character"), hx::TCanCast< Character_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Character_obj::__boot()
{
}

