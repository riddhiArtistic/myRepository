#ifndef INCLUDED_com_velvetArts_v01_Candy
#define INCLUDED_com_velvetArts_v01_Candy

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <native/display/Sprite.h>
HX_DECLARE_CLASS3(com,velvetArts,v01,Candy)
HX_DECLARE_CLASS2(native,display,DisplayObject)
HX_DECLARE_CLASS2(native,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(native,display,IBitmapDrawable)
HX_DECLARE_CLASS2(native,display,InteractiveObject)
HX_DECLARE_CLASS2(native,display,Sprite)
HX_DECLARE_CLASS2(native,events,EventDispatcher)
HX_DECLARE_CLASS2(native,events,IEventDispatcher)
namespace com{
namespace velvetArts{
namespace v01{


class Candy_obj : public ::native::display::Sprite_obj{
	public:
		typedef ::native::display::Sprite_obj super;
		typedef Candy_obj OBJ_;
		Candy_obj();
		Void __construct(Float inX,Float inY);

	public:
		static hx::ObjectPtr< Candy_obj > __new(Float inX,Float inY);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Candy_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Candy"); }

		virtual Void update( );
		Dynamic update_dyn();

		::native::display::Sprite actor; /* REM */ 
		int framedelay; /* REM */ 
};

} // end namespace com
} // end namespace velvetArts
} // end namespace v01

#endif /* INCLUDED_com_velvetArts_v01_Candy */ 
