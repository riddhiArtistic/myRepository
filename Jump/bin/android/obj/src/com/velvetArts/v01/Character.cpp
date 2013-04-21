#include <hxcpp.h>

#ifndef INCLUDED_com_velvetArts_v01_Character
#include <com/velvetArts/v01/Character.h>
#endif
#ifndef INCLUDED_native_display_BitmapData
#include <native/display/BitmapData.h>
#endif
#ifndef INCLUDED_native_display_IBitmapDrawable
#include <native/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_native_geom_Point
#include <native/geom/Point.h>
#endif
#ifndef INCLUDED_native_geom_Rectangle
#include <native/geom/Rectangle.h>
#endif
namespace com{
namespace velvetArts{
namespace v01{

Void Character_obj::__construct()
{
HX_STACK_PUSH("Character::new","com/velvetArts/v01/Character.hx",32);
{
	HX_STACK_LINE(32)
	this->mPoint = ::native::geom::Point_obj::__new((int)0,(int)0);
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

Void Character_obj::draw( Float inX,Float inY){
{
		HX_STACK_PUSH("Character::draw","com/velvetArts/v01/Character.hx",43);
		HX_STACK_THIS(this);
		HX_STACK_ARG(inX,"inX");
		HX_STACK_ARG(inY,"inY");
		HX_STACK_LINE(44)
		this->mPoint->x = (inX - this->mOffX);
		HX_STACK_LINE(45)
		this->mPoint->y = (inY - this->mOffY);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Character_obj,draw,(void))


Character_obj::Character_obj()
{
}

void Character_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Character);
	HX_MARK_MEMBER_NAME(mOffY,"mOffY");
	HX_MARK_MEMBER_NAME(mOffX,"mOffX");
	HX_MARK_MEMBER_NAME(mPoint,"mPoint");
	HX_MARK_MEMBER_NAME(mRect,"mRect");
	HX_MARK_MEMBER_NAME(mBits,"mBits");
	HX_MARK_MEMBER_NAME(mGame,"mGame");
	HX_MARK_END_CLASS();
}

void Character_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(mOffY,"mOffY");
	HX_VISIT_MEMBER_NAME(mOffX,"mOffX");
	HX_VISIT_MEMBER_NAME(mPoint,"mPoint");
	HX_VISIT_MEMBER_NAME(mRect,"mRect");
	HX_VISIT_MEMBER_NAME(mBits,"mBits");
	HX_VISIT_MEMBER_NAME(mGame,"mGame");
}

Dynamic Character_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"draw") ) { return draw_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"mOffY") ) { return mOffY; }
		if (HX_FIELD_EQ(inName,"mOffX") ) { return mOffX; }
		if (HX_FIELD_EQ(inName,"mRect") ) { return mRect; }
		if (HX_FIELD_EQ(inName,"mBits") ) { return mBits; }
		if (HX_FIELD_EQ(inName,"mGame") ) { return mGame; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"mPoint") ) { return mPoint; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Character_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"mOffY") ) { mOffY=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mOffX") ) { mOffX=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mRect") ) { mRect=inValue.Cast< ::native::geom::Rectangle >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mBits") ) { mBits=inValue.Cast< ::native::display::BitmapData >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mGame") ) { mGame=inValue.Cast< ::native::display::BitmapData >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"mPoint") ) { mPoint=inValue.Cast< ::native::geom::Point >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Character_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("mOffY"));
	outFields->push(HX_CSTRING("mOffX"));
	outFields->push(HX_CSTRING("mPoint"));
	outFields->push(HX_CSTRING("mRect"));
	outFields->push(HX_CSTRING("mBits"));
	outFields->push(HX_CSTRING("mGame"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("draw"),
	HX_CSTRING("mOffY"),
	HX_CSTRING("mOffX"),
	HX_CSTRING("mPoint"),
	HX_CSTRING("mRect"),
	HX_CSTRING("mBits"),
	HX_CSTRING("mGame"),
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
