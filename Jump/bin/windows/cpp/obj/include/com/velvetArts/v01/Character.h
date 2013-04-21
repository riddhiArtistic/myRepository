#ifndef INCLUDED_com_velvetArts_v01_Character
#define INCLUDED_com_velvetArts_v01_Character

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(com,velvetArts,v01,Character)
HX_DECLARE_CLASS2(native,display,BitmapData)
HX_DECLARE_CLASS2(native,display,IBitmapDrawable)
HX_DECLARE_CLASS2(native,geom,Point)
HX_DECLARE_CLASS2(native,geom,Rectangle)
namespace com{
namespace velvetArts{
namespace v01{


class Character_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Character_obj OBJ_;
		Character_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Character_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Character_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Character"); }

		virtual Void draw( Float inX,Float inY);
		Dynamic draw_dyn();

		Float mOffY; /* REM */ 
		Float mOffX; /* REM */ 
		::native::geom::Point mPoint; /* REM */ 
		::native::geom::Rectangle mRect; /* REM */ 
		::native::display::BitmapData mBits; /* REM */ 
		::native::display::BitmapData mGame; /* REM */ 
};

} // end namespace com
} // end namespace velvetArts
} // end namespace v01

#endif /* INCLUDED_com_velvetArts_v01_Character */ 
