#include <hxcpp.h>

#ifndef INCLUDED_com_velvetArts_v01_Candy
#include <com/velvetArts/v01/Candy.h>
#endif
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

Void Candy_obj::__construct(Float inX,Float inY)
{
HX_STACK_PUSH("Candy::new","com/velvetArts/v01/Candy.hx",15);
{
	HX_STACK_LINE(17)
	this->framedelay = (int)0;
	HX_STACK_LINE(21)
	super::__construct();
	HX_STACK_LINE(22)
	this->set_x(inX);
	HX_STACK_LINE(23)
	this->set_y(inY);
	HX_STACK_LINE(25)
	this->actor = ::native::display::Sprite_obj::__new();
	HX_STACK_LINE(26)
	this->matriX = ::native::geom::Matrix_obj::__new(null(),null(),null(),null(),null(),null());
	HX_STACK_LINE(28)
	this->actor->get_graphics()->beginBitmapFill(::nme::installer::Assets_obj::getBitmapData(HX_CSTRING("img/candy.png"),null()),null(),null(),null());
	HX_STACK_LINE(29)
	this->actor->get_graphics()->drawRect((int)0,(int)0,(int)36,(int)36);
	HX_STACK_LINE(31)
	this->actor->set_x((Float(-(this->actor->get_width())) / Float(2.0)));
	HX_STACK_LINE(32)
	this->actor->set_y((Float(-(this->actor->get_height())) / Float(2.0)));
	HX_STACK_LINE(34)
	this->addChild(this->actor);
	HX_STACK_LINE(36)
	this->set_width((int)36);
	HX_STACK_LINE(37)
	this->set_height((int)36);
	HX_STACK_LINE(39)
	this->addEventListener(::native::events::Event_obj::ENTER_FRAME,this->update_dyn(),null(),null(),null());
}
;
	return null();
}

Candy_obj::~Candy_obj() { }

Dynamic Candy_obj::__CreateEmpty() { return  new Candy_obj; }
hx::ObjectPtr< Candy_obj > Candy_obj::__new(Float inX,Float inY)
{  hx::ObjectPtr< Candy_obj > result = new Candy_obj();
	result->__construct(inX,inY);
	return result;}

Dynamic Candy_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Candy_obj > result = new Candy_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void Candy_obj::update( ::native::events::Event e){
{
		HX_STACK_PUSH("Candy::update","com/velvetArts/v01/Candy.hx",43);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(44)
		if (((this->get_x() > ::nme::Lib_obj::get_current()->get_stage()->get_stageWidth()))){
			HX_STACK_LINE(45)
			this->set_x((int)0);
		}
		else{
			HX_STACK_LINE(47)
			::com::velvetArts::v01::Candy _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(47)
			_g->set_x((_g->get_x() + (int)1));
		}
		HX_STACK_LINE(56)
		if ((!(this->get_visible()))){
			HX_STACK_LINE(58)
			if (((this->framedelay > (int)300))){
				HX_STACK_LINE(60)
				this->set_visible(true);
				HX_STACK_LINE(61)
				this->framedelay = (int)0;
			}
			HX_STACK_LINE(63)
			(this->framedelay)++;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Candy_obj,update,(void))


Candy_obj::Candy_obj()
{
}

void Candy_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Candy);
	HX_MARK_MEMBER_NAME(framedelay,"framedelay");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Candy_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(framedelay,"framedelay");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Candy_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"framedelay") ) { return framedelay; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Candy_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"framedelay") ) { framedelay=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Candy_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("framedelay"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("update"),
	HX_CSTRING("framedelay"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Candy_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Candy_obj::__mClass,"__mClass");
};

Class Candy_obj::__mClass;

void Candy_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.velvetArts.v01.Candy"), hx::TCanCast< Candy_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Candy_obj::__boot()
{
}

} // end namespace com
} // end namespace velvetArts
} // end namespace v01
