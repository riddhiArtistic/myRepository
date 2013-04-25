#include <hxcpp.h>

#ifndef INCLUDED_com_velvetArts_v01_GameStates
#include <com/velvetArts/v01/GameStates.h>
#endif
namespace com{
namespace velvetArts{
namespace v01{

Void GameStates_obj::__construct()
{
HX_STACK_PUSH("GameStates::new","com/velvetArts/v01/GameStates.hx",15);
{
	HX_STACK_LINE(16)
	this->Active = false;
	HX_STACK_LINE(17)
	this->Play = true;
	HX_STACK_LINE(18)
	this->Inactive = false;
}
;
	return null();
}

GameStates_obj::~GameStates_obj() { }

Dynamic GameStates_obj::__CreateEmpty() { return  new GameStates_obj; }
hx::ObjectPtr< GameStates_obj > GameStates_obj::__new()
{  hx::ObjectPtr< GameStates_obj > result = new GameStates_obj();
	result->__construct();
	return result;}

Dynamic GameStates_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< GameStates_obj > result = new GameStates_obj();
	result->__construct();
	return result;}


GameStates_obj::GameStates_obj()
{
}

void GameStates_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(GameStates);
	HX_MARK_MEMBER_NAME(Inactive,"Inactive");
	HX_MARK_MEMBER_NAME(Play,"Play");
	HX_MARK_MEMBER_NAME(Active,"Active");
	HX_MARK_END_CLASS();
}

void GameStates_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(Inactive,"Inactive");
	HX_VISIT_MEMBER_NAME(Play,"Play");
	HX_VISIT_MEMBER_NAME(Active,"Active");
}

Dynamic GameStates_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"Play") ) { return Play; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"Active") ) { return Active; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"Inactive") ) { return Inactive; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic GameStates_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"Play") ) { Play=inValue.Cast< bool >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"Active") ) { Active=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"Inactive") ) { Inactive=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void GameStates_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("Inactive"));
	outFields->push(HX_CSTRING("Play"));
	outFields->push(HX_CSTRING("Active"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("Inactive"),
	HX_CSTRING("Play"),
	HX_CSTRING("Active"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(GameStates_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(GameStates_obj::__mClass,"__mClass");
};

Class GameStates_obj::__mClass;

void GameStates_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.velvetArts.v01.GameStates"), hx::TCanCast< GameStates_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void GameStates_obj::__boot()
{
}

} // end namespace com
} // end namespace velvetArts
} // end namespace v01
