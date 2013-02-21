#include <hxcpp.h>

#ifndef INCLUDED_com_eclecticdesignstudio_motion_easing_BounceEaseIn
#include <com/eclecticdesignstudio/motion/easing/BounceEaseIn.h>
#endif
#ifndef INCLUDED_com_eclecticdesignstudio_motion_easing_IEasing
#include <com/eclecticdesignstudio/motion/easing/IEasing.h>
#endif
namespace com{
namespace eclecticdesignstudio{
namespace motion{
namespace easing{

Void BounceEaseIn_obj::__construct()
{
HX_STACK_PUSH("BounceEaseIn::new","com/eclecticdesignstudio/motion/easing/Bounce.hx",51);
{
}
;
	return null();
}

BounceEaseIn_obj::~BounceEaseIn_obj() { }

Dynamic BounceEaseIn_obj::__CreateEmpty() { return  new BounceEaseIn_obj; }
hx::ObjectPtr< BounceEaseIn_obj > BounceEaseIn_obj::__new()
{  hx::ObjectPtr< BounceEaseIn_obj > result = new BounceEaseIn_obj();
	result->__construct();
	return result;}

Dynamic BounceEaseIn_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BounceEaseIn_obj > result = new BounceEaseIn_obj();
	result->__construct();
	return result;}

hx::Object *BounceEaseIn_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::com::eclecticdesignstudio::motion::easing::IEasing_obj)) return operator ::com::eclecticdesignstudio::motion::easing::IEasing_obj *();
	return super::__ToInterface(inType);
}

Float BounceEaseIn_obj::ease( Float t,Float b,Float c,Float d){
	HX_STACK_PUSH("BounceEaseIn::ease","com/eclecticdesignstudio/motion/easing/Bounce.hx",62);
	HX_STACK_THIS(this);
	HX_STACK_ARG(t,"t");
	HX_STACK_ARG(b,"b");
	HX_STACK_ARG(c,"c");
	HX_STACK_ARG(d,"d");
	struct _Function_1_1{
		inline static Float Block( Float &t,Float &d,Float &c){
			HX_STACK_PUSH("*::closure","com/eclecticdesignstudio/motion/easing/Bounce.hx",63);
			{
				HX_STACK_LINE(63)
				Float t1 = (d - t);		HX_STACK_VAR(t1,"t1");
				HX_STACK_LINE(63)
				return (  ((((hx::DivEq(t1,d)) < (Float((int)1) / Float(2.75))))) ? Float((c * (((7.5625 * t1) * t1)))) : Float((  (((t1 < (Float((int)2) / Float(2.75))))) ? Float((c * ((((7.5625 * (hx::SubEq(t1,(Float(1.5) / Float(2.75))))) * t1) + .75)))) : Float((  (((t1 < (Float(2.5) / Float(2.75))))) ? Float((c * ((((7.5625 * (hx::SubEq(t1,(Float(2.25) / Float(2.75))))) * t1) + .9375)))) : Float((c * ((((7.5625 * (hx::SubEq(t1,(Float(2.625) / Float(2.75))))) * t1) + .984375)))) )) )) );
			}
			return null();
		}
	};
	HX_STACK_LINE(62)
	return ((c - _Function_1_1::Block(t,d,c)) + b);
}


HX_DEFINE_DYNAMIC_FUNC4(BounceEaseIn_obj,ease,return )

Float BounceEaseIn_obj::calculate( Float k){
	HX_STACK_PUSH("BounceEaseIn::calculate","com/eclecticdesignstudio/motion/easing/Bounce.hx",57);
	HX_STACK_THIS(this);
	HX_STACK_ARG(k,"k");
	struct _Function_1_1{
		inline static Float Block( Float &k){
			HX_STACK_PUSH("*::closure","com/eclecticdesignstudio/motion/easing/Bounce.hx",58);
			{
				HX_STACK_LINE(58)
				Float t = ((int)1 - k);		HX_STACK_VAR(t,"t");
				HX_STACK_LINE(58)
				return (  ((((hx::DivEq(t,(int)1)) < (Float((int)1) / Float(2.75))))) ? Float(((7.5625 * t) * t)) : Float((  (((t < (Float((int)2) / Float(2.75))))) ? Float((((7.5625 * (hx::SubEq(t,(Float(1.5) / Float(2.75))))) * t) + .75)) : Float((  (((t < (Float(2.5) / Float(2.75))))) ? Float((((7.5625 * (hx::SubEq(t,(Float(2.25) / Float(2.75))))) * t) + .9375)) : Float((((7.5625 * (hx::SubEq(t,(Float(2.625) / Float(2.75))))) * t) + .984375)) )) )) );
			}
			return null();
		}
	};
	HX_STACK_LINE(57)
	return ((int)1 - _Function_1_1::Block(k));
}


HX_DEFINE_DYNAMIC_FUNC1(BounceEaseIn_obj,calculate,return )

Float BounceEaseIn_obj::_ease( Float t,Float b,Float c,Float d){
	HX_STACK_PUSH("BounceEaseIn::_ease","com/eclecticdesignstudio/motion/easing/Bounce.hx",66);
	HX_STACK_ARG(t,"t");
	HX_STACK_ARG(b,"b");
	HX_STACK_ARG(c,"c");
	HX_STACK_ARG(d,"d");
	struct _Function_1_1{
		inline static Float Block( Float &t,Float &d,Float &c){
			HX_STACK_PUSH("*::closure","com/eclecticdesignstudio/motion/easing/Bounce.hx",67);
			{
				HX_STACK_LINE(67)
				Float t1 = (d - t);		HX_STACK_VAR(t1,"t1");
				HX_STACK_LINE(67)
				return (  ((((hx::DivEq(t1,d)) < (Float((int)1) / Float(2.75))))) ? Float((c * (((7.5625 * t1) * t1)))) : Float((  (((t1 < (Float((int)2) / Float(2.75))))) ? Float((c * ((((7.5625 * (hx::SubEq(t1,(Float(1.5) / Float(2.75))))) * t1) + .75)))) : Float((  (((t1 < (Float(2.5) / Float(2.75))))) ? Float((c * ((((7.5625 * (hx::SubEq(t1,(Float(2.25) / Float(2.75))))) * t1) + .9375)))) : Float((c * ((((7.5625 * (hx::SubEq(t1,(Float(2.625) / Float(2.75))))) * t1) + .984375)))) )) )) );
			}
			return null();
		}
	};
	HX_STACK_LINE(66)
	return ((c - _Function_1_1::Block(t,d,c)) + b);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(BounceEaseIn_obj,_ease,return )


BounceEaseIn_obj::BounceEaseIn_obj()
{
}

void BounceEaseIn_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BounceEaseIn);
	HX_MARK_END_CLASS();
}

void BounceEaseIn_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic BounceEaseIn_obj::__Field(const ::String &inName,bool inCallProp)
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

Dynamic BounceEaseIn_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void BounceEaseIn_obj::__GetFields(Array< ::String> &outFields)
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
	HX_MARK_MEMBER_NAME(BounceEaseIn_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BounceEaseIn_obj::__mClass,"__mClass");
};

Class BounceEaseIn_obj::__mClass;

void BounceEaseIn_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.eclecticdesignstudio.motion.easing.BounceEaseIn"), hx::TCanCast< BounceEaseIn_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void BounceEaseIn_obj::__boot()
{
}

} // end namespace com
} // end namespace eclecticdesignstudio
} // end namespace motion
} // end namespace easing
