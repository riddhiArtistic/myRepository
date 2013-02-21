#ifndef INCLUDED_Jump
#define INCLUDED_Jump

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <native/display/Sprite.h>
HX_DECLARE_CLASS0(BackGroundImg)
HX_DECLARE_CLASS0(Character)
HX_DECLARE_CLASS0(Jump)
HX_DECLARE_CLASS0(MovingBGImg)
HX_DECLARE_CLASS2(native,display,DisplayObject)
HX_DECLARE_CLASS2(native,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(native,display,IBitmapDrawable)
HX_DECLARE_CLASS2(native,display,InteractiveObject)
HX_DECLARE_CLASS2(native,display,Sprite)
HX_DECLARE_CLASS2(native,events,Event)
HX_DECLARE_CLASS2(native,events,EventDispatcher)
HX_DECLARE_CLASS2(native,events,IEventDispatcher)


class Jump_obj : public ::native::display::Sprite_obj{
	public:
		typedef ::native::display::Sprite_obj super;
		typedef Jump_obj OBJ_;
		Jump_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Jump_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Jump_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Jump"); }

		virtual Void renderScrollingBG( ::native::events::Event event);
		Dynamic renderScrollingBG_dyn();

		virtual Void init( Dynamic e);
		Dynamic init_dyn();

		bool jumpFlg; /* REM */ 
		bool moveFWD; /* REM */ 
		int scrollIndex; /* REM */ 
		::Character myCharacter; /* REM */ 
		::MovingBGImg movingBG; /* REM */ 
		::BackGroundImg myBGImg; /* REM */ 
		static Void main( );
		static Dynamic main_dyn();

};


#endif /* INCLUDED_Jump */ 
