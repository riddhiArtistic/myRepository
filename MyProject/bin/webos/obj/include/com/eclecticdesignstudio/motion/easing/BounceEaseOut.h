#ifndef INCLUDED_com_eclecticdesignstudio_motion_easing_BounceEaseOut
#define INCLUDED_com_eclecticdesignstudio_motion_easing_BounceEaseOut

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <com/eclecticdesignstudio/motion/easing/IEasing.h>
HX_DECLARE_CLASS4(com,eclecticdesignstudio,motion,easing,BounceEaseOut)
HX_DECLARE_CLASS4(com,eclecticdesignstudio,motion,easing,IEasing)
namespace com{
namespace eclecticdesignstudio{
namespace motion{
namespace easing{


class BounceEaseOut_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef BounceEaseOut_obj OBJ_;
		BounceEaseOut_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< BounceEaseOut_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~BounceEaseOut_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::com::eclecticdesignstudio::motion::easing::IEasing_obj *()
			{ return new ::com::eclecticdesignstudio::motion::easing::IEasing_delegate_< BounceEaseOut_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_CSTRING("BounceEaseOut"); }

		virtual Float ease( Float t,Float b,Float c,Float d);
		Dynamic ease_dyn();

		virtual Float calculate( Float k);
		Dynamic calculate_dyn();

		static Float _ease( Float t,Float b,Float c,Float d);
		static Dynamic _ease_dyn();

};

} // end namespace com
} // end namespace eclecticdesignstudio
} // end namespace motion
} // end namespace easing

#endif /* INCLUDED_com_eclecticdesignstudio_motion_easing_BounceEaseOut */ 
