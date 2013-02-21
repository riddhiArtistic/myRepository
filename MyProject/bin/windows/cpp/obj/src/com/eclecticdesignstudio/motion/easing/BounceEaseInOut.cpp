#include <hxcpp.h>

#ifndef INCLUDED_com_eclecticdesignstudio_motion_easing_BounceEaseInOut
#include <com/eclecticdesignstudio/motion/easing/BounceEaseInOut.h>
#endif
#ifndef INCLUDED_com_eclecticdesignstudio_motion_easing_IEasing
#include <com/eclecticdesignstudio/motion/easing/IEasing.h>
#endif
namespace com{
namespace eclecticdesignstudio{
namespace motion{
namespace easing{

Void BounceEaseInOut_obj::__construct()
{
HX_STACK_PUSH("BounceEaseInOut::new","com/eclecticdesignstudio/motion/easing/Bounce.hx",76);
{
}
;
	return null();
}

BounceEaseInOut_obj::~BounceEaseInOut_obj() { }

Dynamic BounceEaseInOut_obj::__CreateEmpty() { return  new BounceEaseInOut_obj; }
hx::ObjectPtr< BounceEaseInOut_obj > BounceEaseInOut_obj::__new()
{  hx::ObjectPtr< BounceEaseInOut_obj > result = new BounceEaseInOut_obj();
	result->__construct();
	return result;}

Dynamic BounceEaseInOut_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BounceEaseInOut_obj > result = new BounceEaseInOut_obj();
	result->__construct();
	return result;}

hx::Object *BounceEaseInOut_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::com::eclecticdesignstudio::motion::easing::IEasing_obj)) return operator ::com::eclecticdesignstudio::motion::easing::IEasing_obj *();
	return super::__ToInterface(inType);
}

Float BounceEaseInOut_obj::ease( Float t,Float b,Float c,Float d){
	HX_STACK_PUSH("BounceEaseInOut::ease","com/eclecticdesignstudio/motion/easing/Bounce.hx",92);
	HX_STACK_THIS(this);
	HX_STACK_ARG(t,"t");
	HX_STACK_ARG(b,"b");
	HX_STACK_ARG(c,"c");
	HX_STACK_ARG(d,"d");
	HX_STACK_LINE(92)
	if (((t < (Float(d) / Float((int)2))))){
		struct _Function_2_1{
			inline static Float Block( Float &t,Float &d,Float &c){
				HX_STACK_PUSH("*::closure","com/eclecticdesignstudio/motion/easing/Bounce.hx",95);
				{
					HX_STACK_LINE(95)
					Float t1 = (d - (t * (int)2));		HX_STACK_VAR(t1,"t1");
					HX_STACK_LINE(95)
					return (  ((((hx::DivEq(t1,d)) < (Float((int)1) / Float(2.75))))) ? Float((c * (((7.5625 * t1) * t1)))) : Float((  (((t1 < (Float((int)2) / Float(2.75))))) ? Float((c * ((((7.5625 * (hx::SubEq(t1,(Float(1.5) / Float(2.75))))) * t1) + .75)))) : Float((  (((t1 < (Float(2.5) / Float(2.75))))) ? Float((c * ((((7.5625 * (hx::SubEq(t1,(Float(2.25) / Float(2.75))))) * t1) + .9375)))) : Float((c * ((((7.5625 * (hx::SubEq(t1,(Float(2.625) / Float(2.75))))) * t1) + .984375)))) )) )) );
				}
				return null();
			}
		};
		HX_STACK_LINE(94)
		return ((((c - _Function_2_1::Block(t,d,c))) * .5) + b);
	}
	else{
		struct _Function_2_1{
			inline static Float Block( Float &t,Float &d,Float &c){
				HX_STACK_PUSH("*::closure","com/eclecticdesignstudio/motion/easing/Bounce.hx",97);
				{
					HX_STACK_LINE(97)
					Float t1 = ((t * (int)2) - d);		HX_STACK_VAR(t1,"t1");
					HX_STACK_LINE(97)
					return (  ((((hx::DivEq(t1,d)) < (Float((int)1) / Float(2.75))))) ? Float((c * (((7.5625 * t1) * t1)))) : Float((  (((t1 < (Float((int)2) / Float(2.75))))) ? Float((c * ((((7.5625 * (hx::SubEq(t1,(Float(1.5) / Float(2.75))))) * t1) + .75)))) : Float((  (((t1 < (Float(2.5) / Float(2.75))))) ? Float((c * ((((7.5625 * (hx::SubEq(t1,(Float(2.25) / Float(2.75))))) * t1) + .9375)))) : Float((c * ((((7.5625 * (hx::SubEq(t1,(Float(2.625) / Float(2.75))))) * t1) + .984375)))) )) )) );
				}
				return null();
			}
		};
		HX_STACK_LINE(96)
		return (((_Function_2_1::Block(t,d,c) * .5) + (c * .5)) + b);
	}
	HX_STACK_LINE(92)
	return 0.;
}


HX_DEFINE_DYNAMIC_FUNC4(BounceEaseInOut_obj,ease,return )

Float BounceEaseInOut_obj::calculate( Float k){
	HX_STACK_PUSH("BounceEaseInOut::calculate","com/eclecticdesignstudio/motion/easing/Bounce.hx",82);
	HX_STACK_THIS(this);
	HX_STACK_ARG(k,"k");
	HX_STACK_LINE(82)
	if (((k < .5))){
		struct _Function_2_1{
			inline static Float Block( Float &k){
				HX_STACK_PUSH("*::closure","com/eclecticdesignstudio/motion/easing/Bounce.hx",85);
				{
					HX_STACK_LINE(85)
					Float t = ((int)1 - (k * (int)2));		HX_STACK_VAR(t,"t");
					HX_STACK_LINE(85)
					return (  ((((hx::DivEq(t,(int)1)) < (Float((int)1) / Float(2.75))))) ? Float(((7.5625 * t) * t)) : Float((  (((t < (Float((int)2) / Float(2.75))))) ? Float((((7.5625 * (hx::SubEq(t,(Float(1.5) / Float(2.75))))) * t) + .75)) : Float((  (((t < (Float(2.5) / Float(2.75))))) ? Float((((7.5625 * (hx::SubEq(t,(Float(2.25) / Float(2.75))))) * t) + .9375)) : Float((((7.5625 * (hx::SubEq(t,(Float(2.625) / Float(2.75))))) * t) + .984375)) )) )) );
				}
				return null();
			}
		};
		HX_STACK_LINE(84)
		return ((((int)1 - _Function_2_1::Block(k))) * .5);
	}
	else{
		struct _Function_2_1{
			inline static Float Block( Float &k){
				HX_STACK_PUSH("*::closure","com/eclecticdesignstudio/motion/easing/Bounce.hx",87);
				{
					HX_STACK_LINE(87)
					Float t = ((k * (int)2) - (int)1);		HX_STACK_VAR(t,"t");
					HX_STACK_LINE(87)
					return (  ((((hx::DivEq(t,(int)1)) < (Float((int)1) / Float(2.75))))) ? Float(((7.5625 * t) * t)) : Float((  (((t < (Float((int)2) / Float(2.75))))) ? Float((((7.5625 * (hx::SubEq(t,(Float(1.5) / Float(2.75))))) * t) + .75)) : Float((  (((t < (Float(2.5) / Float(2.75))))) ? Float((((7.5625 * (hx::SubEq(t,(Float(2.25) / Float(2.75))))) * t) + .9375)) : Float((((7.5625 * (hx::SubEq(t,(Float(2.625) / Float(2.75))))) * t) + .984375)) )) )) );
				}
				return null();
			}
		};
		HX_STACK_LINE(86)
		return ((_Function_2_1::Block(k) * .5) + .5);
	}
	HX_STACK_LINE(82)
	return 0.;
}


HX_DEFINE_DYNAMIC_FUNC1(BounceEaseInOut_obj,calculate,return )


BounceEaseInOut_obj::BounceEaseInOut_obj()
{
}

void BounceEaseInOut_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BounceEaseInOut);
	HX_MARK_END_CLASS();
}

void BounceEaseInOut_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic BounceEaseInOut_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"ease") ) { return ease_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"calculate") ) { return calculate_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic BounceEaseInOut_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void BounceEaseInOut_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("ease"),
	HX_CSTRING("calculate"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BounceEaseInOut_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BounceEaseInOut_obj::__mClass,"__mClass");
};

Class BounceEaseInOut_obj::__mClass;

void BounceEaseInOut_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.eclecticdesignstudio.motion.easing.BounceEaseInOut"), hx::TCanCast< BounceEaseInOut_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void BounceEaseInOut_obj::__boot()
{
}

} // end namespace com
} // end namespace eclecticdesignstudio
} // end namespace motion
} // end namespace easing
