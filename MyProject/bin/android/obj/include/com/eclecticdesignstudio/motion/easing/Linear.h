#ifndef INCLUDED_com_eclecticdesignstudio_motion_easing_Linear
#define INCLUDED_com_eclecticdesignstudio_motion_easing_Linear

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS4(com,eclecticdesignstudio,motion,easing,IEasing)
HX_DECLARE_CLASS4(com,eclecticdesignstudio,motion,easing,Linear)
namespace com{
namespace eclecticdesignstudio{
namespace motion{
namespace easing{


class Linear_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Linear_obj OBJ_;
		Linear_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Linear_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Linear_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Linear"); }

		static ::com::eclecticdesignstudio::motion::easing::IEasing easeNone; /* REM */ 
		static ::com::eclecticdesignstudio::motion::easing::IEasing get_easeNone( );
		static Dynamic get_easeNone_dyn();

};

} // end namespace com
} // end namespace eclecticdesignstudio
} // end namespace motion
} // end namespace easing

#endif /* INCLUDED_com_eclecticdesignstudio_motion_easing_Linear */ 
