#ifndef INCLUDED_com_velvetArts_v01_Game
#define INCLUDED_com_velvetArts_v01_Game

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <native/display/Sprite.h>
HX_DECLARE_CLASS3(com,velvetArts,v01,Actor)
HX_DECLARE_CLASS3(com,velvetArts,v01,Candy)
HX_DECLARE_CLASS3(com,velvetArts,v01,Clouds)
HX_DECLARE_CLASS3(com,velvetArts,v01,Game)
HX_DECLARE_CLASS3(com,velvetArts,v01,GameStates)
HX_DECLARE_CLASS3(com,velvetArts,v01,MovingBG)
HX_DECLARE_CLASS1(haxe,Timer)
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


class Game_obj : public ::native::display::Sprite_obj{
	public:
		typedef ::native::display::Sprite_obj super;
		typedef Game_obj OBJ_;
		Game_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Game_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Game_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Game"); }

		virtual Void endTap( ::native::events::TouchEvent e);
		Dynamic endTap_dyn();

		virtual Void startTouchGame( ::native::events::TouchEvent e);
		Dynamic startTouchGame_dyn();

		virtual Void endClick( ::native::events::MouseEvent e);
		Dynamic endClick_dyn();

		virtual Void startClickGame( ::native::events::MouseEvent e);
		Dynamic startClickGame_dyn();

		virtual Void check_Collision( );
		Dynamic check_Collision_dyn();

		virtual Void update( );
		Dynamic update_dyn();

		::com::velvetArts::v01::GameStates states; /* REM */ 
		::haxe::Timer timer; /* REM */ 
		int topScore; /* REM */ 
		int mScore; /* REM */ 
		bool cloudHit; /* REM */ 
		bool rewardHit; /* REM */ 
		Float stgHeight; /* REM */ 
		Float stgWidth; /* REM */ 
		Array< ::com::velvetArts::v01::Candy > mCandies; /* REM */ 
		Array< ::com::velvetArts::v01::Clouds > mClouds; /* REM */ 
		::com::velvetArts::v01::Actor baby; /* REM */ 
		::com::velvetArts::v01::MovingBG bgImg; /* REM */ 
		static Dynamic fps_data; /* REM */ 
};

} // end namespace com
} // end namespace velvetArts
} // end namespace v01

#endif /* INCLUDED_com_velvetArts_v01_Game */ 
