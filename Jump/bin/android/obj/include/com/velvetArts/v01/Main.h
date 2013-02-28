#ifndef INCLUDED_com_velvetArts_v01_Main
#define INCLUDED_com_velvetArts_v01_Main

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <native/display/Sprite.h>
HX_DECLARE_CLASS3(com,velvetArts,v01,Character)
HX_DECLARE_CLASS3(com,velvetArts,v01,Main)
HX_DECLARE_CLASS3(com,velvetArts,v01,MovingBG)
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


class Main_obj : public ::native::display::Sprite_obj{
	public:
		typedef ::native::display::Sprite_obj super;
		typedef Main_obj OBJ_;
		Main_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Main_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Main_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Main"); }

		virtual Void init( Dynamic e);
		Dynamic init_dyn();

		::com::velvetArts::v01::Character Actor; /* REM */ 
		::com::velvetArts::v01::MovingBG bgImg; /* REM */ 
		static Void main( );
		static Dynamic main_dyn();

};

} // end namespace com
} // end namespace velvetArts
} // end namespace v01

#endif /* INCLUDED_com_velvetArts_v01_Main */ 