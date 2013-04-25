#ifndef INCLUDED_com_velvetArts_v01_Actor
#define INCLUDED_com_velvetArts_v01_Actor

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <native/display/Sprite.h>
HX_DECLARE_CLASS3(com,velvetArts,v01,Actor)
HX_DECLARE_CLASS2(native,display,DisplayObject)
HX_DECLARE_CLASS2(native,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(native,display,IBitmapDrawable)
HX_DECLARE_CLASS2(native,display,InteractiveObject)
HX_DECLARE_CLASS2(native,display,Sprite)
HX_DECLARE_CLASS2(native,events,Event)
HX_DECLARE_CLASS2(native,events,EventDispatcher)
HX_DECLARE_CLASS2(native,events,IEventDispatcher)
HX_DECLARE_CLASS2(native,events,MouseEvent)
HX_DECLARE_CLASS2(native,events,TouchEvent)
namespace com{
namespace velvetArts{
namespace v01{


class Actor_obj : public ::native::display::Sprite_obj{
	public:
		typedef ::native::display::Sprite_obj super;
		typedef Actor_obj OBJ_;
		Actor_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Actor_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Actor_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Actor"); }

		virtual Void stopMove( ::native::events::MouseEvent e);
		Dynamic stopMove_dyn();

		virtual Void Move( ::native::events::MouseEvent e);
		Dynamic Move_dyn();

		virtual Void en_Move( ::native::events::MouseEvent e);
		Dynamic en_Move_dyn();

		virtual Void stopDragging( ::native::events::TouchEvent e);
		Dynamic stopDragging_dyn();

		virtual Void jump( ::native::events::TouchEvent e);
		Dynamic jump_dyn();

		virtual Void startDragging( ::native::events::TouchEvent e);
		Dynamic startDragging_dyn();

		virtual Void update( );
		Dynamic update_dyn();

		Float mouse_X; /* REM */ 
		bool jumpBKW; /* REM */ 
		bool jumpFWD; /* REM */ 
		bool jumpFlag; /* REM */ 
		::native::display::Sprite actor; /* REM */ 
		bool IsActive; /* REM */ 
};

} // end namespace com
} // end namespace velvetArts
} // end namespace v01

#endif /* INCLUDED_com_velvetArts_v01_Actor */ 
