#include <hxcpp.h>

#ifndef INCLUDED_com_eclecticdesignstudio_motion_easing_Bounce
#include <com/eclecticdesignstudio/motion/easing/Bounce.h>
#endif
#ifndef INCLUDED_com_eclecticdesignstudio_motion_easing_BounceEaseIn
#include <com/eclecticdesignstudio/motion/easing/BounceEaseIn.h>
#endif
#ifndef INCLUDED_com_eclecticdesignstudio_motion_easing_BounceEaseInOut
#include <com/eclecticdesignstudio/motion/easing/BounceEaseInOut.h>
#endif
#ifndef INCLUDED_com_eclecticdesignstudio_motion_easing_BounceEaseOut
#include <com/eclecticdesignstudio/motion/easing/BounceEaseOut.h>
#endif
#ifndef INCLUDED_com_eclecticdesignstudio_motion_easing_IEasing
#include <com/eclecticdesignstudio/motion/easing/IEasing.h>
#endif
namespace com{
namespace eclecticdesignstudio{
namespace motion{
namespace easing{

Void Bounce_obj::__construct()
{
	return null();
}

Bounce_obj::~Bounce_obj() { }

Dynamic Bounce_obj::__CreateEmpty() { return  new Bounce_obj; }
hx::ObjectPtr< Bounce_obj > Bounce_obj::__new()
{  hx::ObjectPtr< Bounce_obj > result = new Bounce_obj();
	result->__construct();
	return result;}

Dynamic Bounce_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Bounce_obj > result = new Bounce_obj();
	result->__construct();
	return result;}

::com::eclecticdesignstudio::motion::easing::IEasing Bounce_obj::easeIn;

::com::eclecticdesignstudio::motion::easing::IEasing Bounce_obj::easeInOut;

::com::eclecticdesignstudio::motion::easing::IEasing Bounce_obj::easeOut;

::com::eclecticdesignstudio::motion::easing::IEasing Bounce_obj::getEaseIn( ){
	HX_STACK_PUSH("Bounce::getEaseIn","com/eclecticdesignstudio/motion/easing/Bounce.hx",19);
	HX_STACK_LINE(19)
	return ::com::eclecticdesignstudio::motion::easing::BounceEaseIn_obj::__new();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Bounce_obj,getEaseIn,return )

::com::eclecticdesignstudio::motion::easing::IEasing Bounce_obj::getEaseInOut( ){
	HX_STACK_PUSH("Bounce::getEaseInOut","com/eclecticdesignstudio/motion/easing/Bounce.hx",26);
	HX_STACK_LINE(26)
	return ::com::eclecticdesignstudio::motion::easing::BounceEaseInOut_obj::__new();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Bounce_obj,getEaseInOut,return )

::com::eclecticdesignstudio::motion::easing::IEasing Bounce_obj::getEaseOut( ){
	HX_STACK_PUSH("Bounce::getEaseOut","com/eclecticdesignstudio/motion/easing/Bounce.hx",33);
	HX_STACK_LINE(33)
	return ::com::eclecticdesignstudio::motion::easing::BounceEaseOut_obj::__new();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Bounce_obj,getEaseOut,return )


Bounce_obj::Bounce_obj()
{
}

void Bounce_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Bounce);
	HX_MARK_END_CLASS();
}

void Bounce_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic Bounce_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"easeIn") ) { return inCallProp ? getEaseIn() : easeIn; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"easeOut") ) { return inCallProp ? getEaseOut() : easeOut; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"easeInOut") ) { return inCallProp ? getEaseInOut() : easeInOut; }
		if (HX_FIELD_EQ(inName,"getEaseIn") ) { return getEaseIn_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"getEaseOut") ) { return getEaseOut_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"getEaseInOut") ) { return getEaseInOut_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Bounce_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"easeIn") ) { easeIn=inValue.Cast< ::com::eclecticdesignstudio::motion::easing::IEasing >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"easeOut") ) { easeOut=inValue.Cast< ::com::eclecticdesignstudio::motion::easing::IEasing >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"easeInOut") ) { easeInOut=inValue.Cast< ::com::eclecticdesignstudio::motion::easing::IEasing >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Bounce_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("easeIn"),
	HX_CSTRING("easeInOut"),
	HX_CSTRING("easeOut"),
	HX_CSTRING("getEaseIn"),
	HX_CSTRING("getEaseInOut"),
	HX_CSTRING("getEaseOut"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Bounce_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Bounce_obj::easeIn,"easeIn");
	HX_MARK_MEMBER_NAME(Bounce_obj::easeInOut,"easeInOut");
	HX_MARK_MEMBER_NAME(Bounce_obj::easeOut,"easeOut");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Bounce_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Bounce_obj::easeIn,"easeIn");
	HX_VISIT_MEMBER_NAME(Bounce_obj::easeInOut,"easeInOut");
	HX_VISIT_MEMBER_NAME(Bounce_obj::easeOut,"easeOut");
};

Class Bounce_obj::__mClass;

void Bounce_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.eclecticdesignstudio.motion.easing.Bounce"), hx::TCanCast< Bounce_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Bounce_obj::__boot()
{
}

} // end namespace com
} // end namespace eclecticdesignstudio
} // end namespace motion
} // end namespace easing
