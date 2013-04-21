#ifndef INCLUDED_com_velvetArts_v01_Game
#define INCLUDED_com_velvetArts_v01_Game

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <native/display/Sprite.h>
HX_DECLARE_CLASS3(com,velvetArts,v01,Character)
HX_DECLARE_CLASS3(com,velvetArts,v01,Game)
HX_DECLARE_CLASS2(native,display,DisplayObject)
HX_DECLARE_CLASS2(native,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(native,display,IBitmapDrawable)
HX_DECLARE_CLASS2(native,display,InteractiveObject)
HX_DECLARE_CLASS2(native,display,Sprite)
HX_DECLARE_CLASS2(native,display,Tilesheet)
HX_DECLARE_CLASS2(native,events,Event)
HX_DECLARE_CLASS2(native,events,EventDispatcher)
HX_DECLARE_CLASS2(native,events,IEventDispatcher)
namespace com{
namespace velvetArts{
namespace v01{


class Game_obj : public ::native::display::Sprite_obj{
	public:
		typedef ::native::display::Sprite_obj super;
		typedef Game_obj OBJ_;
		Game_obj();
		Void __construct(::native::display::Tilesheet inTiles);

	public:
		static hx::ObjectPtr< Game_obj > __new(::native::display::Tilesheet inTiles);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Game_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Game"); }

		virtual Void frameEnter( ::native::events::Event e);
		Dynamic frameEnter_dyn();

		virtual Void Render( );
		Dynamic Render_dyn();

		::native::display::Tilesheet tilesheet; /* REM */ 
		Array< ::com::velvetArts::v01::Character > characterList; /* REM */ 
		Array< Float > renderList; /* REM */ 
};

} // end namespace com
} // end namespace velvetArts
} // end namespace v01

#endif /* INCLUDED_com_velvetArts_v01_Game */ 
