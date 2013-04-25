#include <hxcpp.h>

#ifndef INCLUDED_com_velvetArts_v01_Clouds
#include <com/velvetArts/v01/Clouds.h>
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

Void Clouds_obj::__construct(Float inX,Float inY)
{
HX_STACK_PUSH("Clouds::new","com/velvetArts/v01/Clouds.hx",21);
{
	HX_STACK_LINE(22)
	super::__construct();
	HX_STACK_LINE(23)
	this->set_x(inX);
	HX_STACK_LINE(24)
	this->set_y(inY);
	HX_STACK_LINE(26)
	this->frames = (int)1;
	HX_STACK_LINE(28)
	this->cloud1 = ::native::display::Sprite_obj::__new();
	HX_STACK_LINE(29)
	this->cloud2 = ::native::display::Sprite_obj::__new();
	HX_STACK_LINE(30)
	this->cloud3 = ::native::display::Sprite_obj::__new();
	HX_STACK_LINE(31)
	this->actor = ::native::display::Sprite_obj::__new();
	HX_STACK_LINE(33)
	this->cloud1->get_graphics()->beginBitmapFill(::nme::installer::Assets_obj::getBitmapData(HX_CSTRING("img/clouds1.png"),null()),null(),false,true);
	HX_STACK_LINE(34)
	this->cloud1->get_graphics()->drawRect((int)0,(int)0,(int)70,(int)20);
	HX_STACK_LINE(36)
	this->cloud2->get_graphics()->beginBitmapFill(::nme::installer::Assets_obj::getBitmapData(HX_CSTRING("img/clouds2.png"),null()),null(),false,true);
	HX_STACK_LINE(37)
	this->cloud2->get_graphics()->drawRect((int)0,(int)0,(int)70,(int)20);
	HX_STACK_LINE(39)
	this->cloud3->get_graphics()->beginBitmapFill(::nme::installer::Assets_obj::getBitmapData(HX_CSTRING("img/clouds3.png"),null()),null(),false,true);
	HX_STACK_LINE(40)
	this->cloud3->get_graphics()->drawRect((int)0,(int)0,(int)70,(int)20);
	HX_STACK_LINE(42)
	this->actor = this->cloud1;
	HX_STACK_LINE(44)
	this->actor->set_x((Float(-(this->actor->get_width())) / Float(2.0)));
	HX_STACK_LINE(45)
	this->actor->set_y((Float(-(this->actor->get_height())) / Float(2.0)));
	HX_STACK_LINE(47)
	this->addChild(this->actor);
}
;
	return null();
}

Clouds_obj::~Clouds_obj() { }

Dynamic Clouds_obj::__CreateEmpty() { return  new Clouds_obj; }
hx::ObjectPtr< Clouds_obj > Clouds_obj::__new(Float inX,Float inY)
{  hx::ObjectPtr< Clouds_obj > result = new Clouds_obj();
	result->__construct(inX,inY);
	return result;}

Dynamic Clouds_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Clouds_obj > result = new Clouds_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void Clouds_obj::update( ){
{
		HX_STACK_PUSH("Clouds::update","com/velvetArts/v01/Clouds.hx",51);
		HX_STACK_THIS(this);
		HX_STACK_LINE(52)
		this->get_graphics()->clear();
		HX_STACK_LINE(56)
		if (((bool((this->frames > (int)60)) && bool((this->frames <= (int)120))))){
			HX_STACK_LINE(58)
			this->actor = this->cloud2;
			HX_STACK_LINE(59)
			this->addChild(this->actor);
		}
		else{
			HX_STACK_LINE(62)
			if (((bool((this->frames > (int)120)) && bool((this->frames <= (int)180))))){
				HX_STACK_LINE(65)
				this->actor = this->cloud3;
				HX_STACK_LINE(66)
				this->addChild(this->actor);
			}
			else{
				HX_STACK_LINE(70)
				if (((this->frames > (int)180))){
					HX_STACK_LINE(70)
					this->frames = (int)0;
				}
				HX_STACK_LINE(71)
				this->actor = this->cloud1;
				HX_STACK_LINE(72)
				this->addChild(this->actor);
			}
		}
		HX_STACK_LINE(76)
		this->actor->set_x((Float(-(this->actor->get_width())) / Float(2.0)));
		HX_STACK_LINE(77)
		this->actor->set_y((Float(-(this->actor->get_height())) / Float(2.0)));
		HX_STACK_LINE(79)
		this->set_width((int)70);
		HX_STACK_LINE(80)
		this->set_height((int)20);
		HX_STACK_LINE(82)
		if (((this->get_x() > ::nme::Lib_obj::get_current()->get_stage()->get_stageWidth()))){
			HX_STACK_LINE(83)
			this->set_x((int)0);
		}
		else{
			HX_STACK_LINE(85)
			::com::velvetArts::v01::Clouds _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(85)
			_g->set_x((_g->get_x() + (int)1));
		}
		HX_STACK_LINE(86)
		(this->frames)++;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Clouds_obj,update,(void))


Clouds_obj::Clouds_obj()
{
}

void Clouds_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Clouds);
	HX_MARK_MEMBER_NAME(actor,"actor");
	HX_MARK_MEMBER_NAME(cloud3,"cloud3");
	HX_MARK_MEMBER_NAME(cloud2,"cloud2");
	HX_MARK_MEMBER_NAME(cloud1,"cloud1");
	HX_MARK_MEMBER_NAME(frames,"frames");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Clouds_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(actor,"actor");
	HX_VISIT_MEMBER_NAME(cloud3,"cloud3");
	HX_VISIT_MEMBER_NAME(cloud2,"cloud2");
	HX_VISIT_MEMBER_NAME(cloud1,"cloud1");
	HX_VISIT_MEMBER_NAME(frames,"frames");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Clouds_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"actor") ) { return actor; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		if (HX_FIELD_EQ(inName,"cloud3") ) { return cloud3; }
		if (HX_FIELD_EQ(inName,"cloud2") ) { return cloud2; }
		if (HX_FIELD_EQ(inName,"cloud1") ) { return cloud1; }
		if (HX_FIELD_EQ(inName,"frames") ) { return frames; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Clouds_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"actor") ) { actor=inValue.Cast< ::native::display::Sprite >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"cloud3") ) { cloud3=inValue.Cast< ::native::display::Sprite >(); return inValue; }
		if (HX_FIELD_EQ(inName,"cloud2") ) { cloud2=inValue.Cast< ::native::display::Sprite >(); return inValue; }
		if (HX_FIELD_EQ(inName,"cloud1") ) { cloud1=inValue.Cast< ::native::display::Sprite >(); return inValue; }
		if (HX_FIELD_EQ(inName,"frames") ) { frames=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Clouds_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("actor"));
	outFields->push(HX_CSTRING("cloud3"));
	outFields->push(HX_CSTRING("cloud2"));
	outFields->push(HX_CSTRING("cloud1"));
	outFields->push(HX_CSTRING("frames"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("update"),
	HX_CSTRING("actor"),
	HX_CSTRING("cloud3"),
	HX_CSTRING("cloud2"),
	HX_CSTRING("cloud1"),
	HX_CSTRING("frames"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Clouds_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Clouds_obj::__mClass,"__mClass");
};

Class Clouds_obj::__mClass;

void Clouds_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.velvetArts.v01.Clouds"), hx::TCanCast< Clouds_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Clouds_obj::__boot()
{
}

} // end namespace com
} // end namespace velvetArts
} // end namespace v01
