#include <hxcpp.h>

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

Void BounceEaseOut_obj::__construct()
{
HX_STACK_PUSH("BounceEaseOut::new","com/eclecticdesignstudio/motion/easing/Bounce.hx",110);
{
}
;
	return null();
}

BounceEaseOut_obj::~BounceEaseOut_obj() { }

Dynamic BounceEaseOut_obj::__CreateEmpty() { return  new BounceEaseOut_obj; }
hx::ObjectPtr< BounceEaseOut_obj > BounceEaseOut_obj::__new()
{  hx::ObjectPtr< BounceEaseOut_obj > result = new BounceEaseOut_obj();
	result->__construct();
	return result;}

Dynamic BounceEaseOut_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BounceEaseOut_obj > result = new BounceEaseOut_obj();
	result->__construct();
	return result;}

hx::Object *BounceEaseOut_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::com::eclecticdesignstudio::motion::easing::IEasing_obj)) return operator ::com::eclecticdesignstudio::motion::easing::IEasing_obj *();
	return super::__ToInterface(inType);
}

Float BounceEaseOut_obj::ease( Float t,Float b,Float c,Float d){
	HX_STACK_PUSH("BounceEaseOut::ease","com/eclecticdesignstudio/motion/easing/Bounce.hx",123);
	HX_STACK_THIS(this);
	HX_STACK_ARG(t,"t");
	HX_STACK_ARG(b,"b");
	HX_STACK_ARG(c,"c");
	HX_STACK_ARG(d,"d");
	struct _Function_1_1{
		inline static Float Block( Float &t,Float &b,Float &d,Float &c){
			HX_STACK_PUSH("*::closure","com/eclecticdesignstudio/motion/easing/Bounce.hx",125);
			{
				HX_STACK_LINE(125)
				Float t1 = t;		HX_STACK_VAR(t1,"t1");
				HX_STACK_LINE(125)
				return (  ((((hx::DivEq(t1,d)) < (Float((int)1) / Float(2.75))))) ? Float(((c * (((7.5625 * t1) * t1))) + b)) : Float((  (((t1 < (Float((int)2) / Float(2.75))))) ? Float(((c * ((((7.5625 * (hx::SubEq(t1,(Float(1.5) / Float(2.75))))) * t1) + .75))) + b)) : Float((  (((t1 < (Float(2.5) / Float(2.75))))) ? Float(((c * ((((7.5625 * (hx::SubEq(t1,(Float(2.25) / Float(2.75))))) * t1) + .9375))) + b)) : Float(((c * ((((7.5625 * (hx::SubEq(t1,(Float(2.625) / Float(2.75))))) * t1) + .984375))) + b)) )) )) );
			}
			return null();
		}
	};
	HX_STACK_LINE(123)
	return _Function_1_1::Block(t,b,d,c);
}


HX_DEFINE_DYNAMIC_FUNC4(BounceEaseOut_obj,ease,return )

Float BounceEaseOut_obj::calculate( Float k){
	HX_STACK_PUSH("BounceEaseOut::calculate","com/eclecticdesignstudio/motion/easing/Bounce.hx",116);
	HX_STACK_THIS(this);
	HX_STACK_ARG(k,"k");
	struct _Function_1_1{
		inline static Float Block( Float &k){
			HX_STACK_PUSH("*::closure","com/eclecticdesignstudio/motion/easing/Bounce.hx",118);
			{
				HX_STACK_LINE(118)
				Float t = k;		HX_STACK_VAR(t,"t");
				HX_STACK_LINE(118)
				return (  ((((hx::DivEq(t,(int)1)) < (Float((int)1) / Float(2.75))))) ? Float(((7.5625 * t) * t)) : Float((  (((t < (Float((int)2) / Float(2.75))))) ? Float((((7.5625 * (hx::SubEq(t,(Float(1.5) / Float(2.75))))) * t) + .75)) : Float((  (((t < (Float(2.5) / Float(2.75))))) ? Float((((7.5625 * (hx::SubEq(t,(Float(2.25) / Float(2.75))))) * t) + .9375)) : Float((((7.5625 * (hx::SubEq(t,(Float(2.625) / Float(2.75))))) * t) + .984375)) )) )) );
			}
			return null();
		}
	};
	HX_STACK_LINE(116)
	return _Function_1_1::Block(k);
}


HX_DEFINE_DYNAMIC_FUNC1(BounceEaseOut_obj,calculate,return )

Float BounceEaseOut_obj::_ease( Float t,Float b,Float c,Float d){
	HX_STACK_PUSH("BounceEaseOut::_ease","com/eclecticdesignstudio/motion/easing/Bounce.hx",129);
	HX_STACK_ARG(t,"t");
	HX_STACK_ARG(b,"b");
	HX_STACK_ARG(c,"c");
	HX_STACK_ARG(d,"d");
	HX_STACK_LINE(129)
	if ((((hx::DivEq(t,d)) < (Float((int)1) / Float(2.75))))){
		HX_STACK_LINE(130)
		return ((c * (((7.5625 * t) * t))) + b);
	}
	else{
		HX_STACK_LINE(132)
		if (((t < (Float((int)2) / Float(2.75))))){
			HX_STACK_LINE(132)
			return ((c * ((((7.5625 * (hx::SubEq(t,(Float(1.5) / Float(2.75))))) * t) + .75))) + b);
		}
		else{
			HX_STACK_LINE(134)
			if (((t < (Float(2.5) / Float(2.75))))){
				HX_STACK_LINE(134)
				return ((c * ((((7.5625 * (hx::SubEq(t,(Float(2.25) / Float(2.75))))) * t) + .9375))) + b);
			}
			else{
				HX_STACK_LINE(136)
				return ((c * ((((7.5625 * (hx::SubEq(t,(Float(2.625) / Float(2.75))))) * t) + .984375))) + b);
			}
		}
	}
	HX_STACK_LINE(129)
	return 0.;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(BounceEaseOut_obj,_ease,return )


BounceEaseOut_obj::BounceEaseOut_obj()
{
}

void BounceEaseOut_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BounceEaseOut);
	HX_MARK_END_CLASS();
}

void BounceEaseOut_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic BounceEaseOut_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"ease") ) { return ease_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_ease") ) { return _ease_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"calculate") ) { return calculate_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic BounceEaseOut_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void BounceEaseOut_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("_ease"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("ease"),
	HX_CSTRING("calculate"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BounceEaseOut_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BounceEaseOut_obj::__mClass,"__mClass");
};

Class BounceEaseOut_obj::__mClass;

void BounceEaseOut_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.eclecticdesignstudio.motion.easing.BounceEaseOut"), hx::TCanCast< BounceEaseOut_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void BounceEaseOut_obj::__boot()
{
}

} // end namespace com
} // end namespace eclecticdesignstudio
} // end namespace motion
} // end namespace easing
