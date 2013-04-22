#ifndef INCLUDED_com_velvetArts_v01_MovingBG
#define INCLUDED_com_velvetArts_v01_MovingBG

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <native/display/Sprite.h>
HX_DECLARE_CLASS3(com,velvetArts,v01,MovingBG)
HX_DECLARE_CLASS2(native,display,Bitmap)
HX_DECLARE_CLASS2(native,display,DisplayObject)
HX_DECLARE_CLASS2(native,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(native,display,IBitmapDrawable)
HX_DECLARE_CLASS2(native,display,InteractiveObject)
HX_DECLARE_CLASS2(native,display,Sprite)
HX_DECLARE_CLASS2(native,events,Event)
HX_DECLARE_CLASS2(native,events,EventDispatcher)
HX_DECLARE_CLASS2(native,events,IEventDispatcher)
HX_DECLARE_CLASS2(native,geom,Matrix)
namespace com{
namespace velvetArts{
namespace v01{


class MovingBG_obj : public ::native::display::Sprite_obj{
	public:
		typedef ::native::display::Sprite_obj super;
		typedef MovingBG_obj OBJ_;
		MovingBG_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< MovingBG_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~MovingBG_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("MovingBG"); }

		virtual Void scrollBG( ::native::events::Event e);
		Dynamic scrollBG_dyn();

		virtual Void resizeHandler( ::native::events::Event e);
		Dynamic resizeHandler_dyn();

		virtual Void resize( );
		Dynamic resize_dyn();

		::native::geom::Matrix matriX; /* REM */ 
		::native::display::Bitmap BG; /* REM */ 
};

} // end namespace com
} // end namespace velvetArts
} // end namespace v01

#endif /* INCLUDED_com_velvetArts_v01_MovingBG */ 
