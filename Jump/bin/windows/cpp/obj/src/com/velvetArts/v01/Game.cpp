#include <hxcpp.h>

#ifndef INCLUDED_com_velvetArts_v01_Character
#include <com/velvetArts/v01/Character.h>
#endif
#ifndef INCLUDED_com_velvetArts_v01_Game
#include <com/velvetArts/v01/Game.h>
#endif
#ifndef INCLUDED_native_display_DisplayObject
#include <native/display/DisplayObject.h>
#endif
#ifndef INCLUDED_native_display_DisplayObjectContainer
#include <native/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_native_display_Graphics
#include <native/display/Graphics.h>
#endif
#ifndef INCLUDED_native_display_IBitmapDrawable
#include <native/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_native_display_InteractiveObject
#include <native/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_native_display_MovieClip
#include <native/display/MovieClip.h>
#endif
#ifndef INCLUDED_native_display_Sprite
#include <native/display/Sprite.h>
#endif
#ifndef INCLUDED_native_display_Stage
#include <native/display/Stage.h>
#endif
#ifndef INCLUDED_native_display_Tilesheet
#include <native/display/Tilesheet.h>
#endif
#ifndef INCLUDED_native_events_Event
#include <native/events/Event.h>
#endif
#ifndef INCLUDED_native_events_EventDispatcher
#include <native/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_native_events_IEventDispatcher
#include <native/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_native_geom_Point
#include <native/geom/Point.h>
#endif
#ifndef INCLUDED_native_geom_Rectangle
#include <native/geom/Rectangle.h>
#endif
#ifndef INCLUDED_nme_Lib
#include <nme/Lib.h>
#endif
namespace com{
namespace velvetArts{
namespace v01{

Void Game_obj::__construct(::native::display::Tilesheet inTiles)
{
HX_STACK_PUSH("Game::new","com/velvetArts/v01/Game.hx",30);
{
	HX_STACK_LINE(31)
	super::__construct();
	HX_STACK_LINE(32)
	::nme::Lib_obj::get_current()->addChild(hx::ObjectPtr<OBJ_>(this));
	HX_STACK_LINE(40)
	this->renderList = Array_obj< Float >::__new();
	HX_STACK_LINE(41)
	this->characterList = Array_obj< ::com::velvetArts::v01::Character >::__new();
	HX_STACK_LINE(43)
	this->tilesheet = inTiles;
	HX_STACK_LINE(45)
	this->tilesheet->addTileRect(::native::geom::Rectangle_obj::__new((int)5,(int)0,(int)640,(int)480),::native::geom::Point_obj::__new((int)320,(int)240));
	HX_STACK_LINE(46)
	this->tilesheet->addTileRect(::native::geom::Rectangle_obj::__new((int)645,(int)0,(int)70,(int)20),::native::geom::Point_obj::__new((int)35,(int)10));
	HX_STACK_LINE(47)
	this->tilesheet->addTileRect(::native::geom::Rectangle_obj::__new((int)715,(int)0,(int)70,(int)20),::native::geom::Point_obj::__new((int)35,(int)10));
	HX_STACK_LINE(48)
	this->tilesheet->addTileRect(::native::geom::Rectangle_obj::__new((int)785,(int)0,(int)70,(int)20),::native::geom::Point_obj::__new((int)35,(int)10));
	HX_STACK_LINE(49)
	this->tilesheet->addTileRect(::native::geom::Rectangle_obj::__new((int)855,(int)0,(int)60,(int)60),::native::geom::Point_obj::__new((int)30,(int)30));
	HX_STACK_LINE(51)
	::nme::Lib_obj::get_current()->get_stage()->addEventListener(::native::events::Event_obj::ENTER_FRAME,this->frameEnter_dyn(),null(),null(),null());
}
;
	return null();
}

Game_obj::~Game_obj() { }

Dynamic Game_obj::__CreateEmpty() { return  new Game_obj; }
hx::ObjectPtr< Game_obj > Game_obj::__new(::native::display::Tilesheet inTiles)
{  hx::ObjectPtr< Game_obj > result = new Game_obj();
	result->__construct(inTiles);
	return result;}

Dynamic Game_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Game_obj > result = new Game_obj();
	result->__construct(inArgs[0]);
	return result;}

Void Game_obj::frameEnter( ::native::events::Event e){
{
		HX_STACK_PUSH("Game::frameEnter","com/velvetArts/v01/Game.hx",67);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(69)
		this->renderList = Array_obj< Float >::__new();
		HX_STACK_LINE(70)
		this->Render();
		HX_STACK_LINE(71)
		this->tilesheet->drawTiles(this->get_graphics(),this->renderList,null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Game_obj,frameEnter,(void))

Void Game_obj::Render( ){
{
		HX_STACK_PUSH("Game::Render","com/velvetArts/v01/Game.hx",55);
		HX_STACK_THIS(this);
		HX_STACK_LINE(56)
		Float stg_x = (Float(::nme::Lib_obj::get_current()->get_stage()->get_stageWidth()) / Float((int)2));		HX_STACK_VAR(stg_x,"stg_x");
		HX_STACK_LINE(57)
		Float stg_y = (Float(::nme::Lib_obj::get_current()->get_stage()->get_stageHeight()) / Float((int)2));		HX_STACK_VAR(stg_y,"stg_y");
		HX_STACK_LINE(59)
		this->renderList = Array_obj< Float >::__new().Add(stg_x).Add(stg_y).Add((int)0).Add(stg_x).Add(stg_y).Add((int)4).Add((stg_x - (int)10)).Add((stg_y - (int)30)).Add((int)2).Add((stg_x - (int)50)).Add((stg_y - (int)60)).Add((int)3).Add((stg_x - (int)90)).Add((stg_y - (int)40)).Add((int)1);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Game_obj,Render,(void))


Game_obj::Game_obj()
{
}

void Game_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Game);
	HX_MARK_MEMBER_NAME(tilesheet,"tilesheet");
	HX_MARK_MEMBER_NAME(characterList,"characterList");
	HX_MARK_MEMBER_NAME(renderList,"renderList");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Game_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(tilesheet,"tilesheet");
	HX_VISIT_MEMBER_NAME(characterList,"characterList");
	HX_VISIT_MEMBER_NAME(renderList,"renderList");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Game_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"Render") ) { return Render_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"tilesheet") ) { return tilesheet; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"frameEnter") ) { return frameEnter_dyn(); }
		if (HX_FIELD_EQ(inName,"renderList") ) { return renderList; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"characterList") ) { return characterList; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Game_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"tilesheet") ) { tilesheet=inValue.Cast< ::native::display::Tilesheet >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"renderList") ) { renderList=inValue.Cast< Array< Float > >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"characterList") ) { characterList=inValue.Cast< Array< ::com::velvetArts::v01::Character > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Game_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("tilesheet"));
	outFields->push(HX_CSTRING("characterList"));
	outFields->push(HX_CSTRING("renderList"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("frameEnter"),
	HX_CSTRING("Render"),
	HX_CSTRING("tilesheet"),
	HX_CSTRING("characterList"),
	HX_CSTRING("renderList"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Game_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Game_obj::__mClass,"__mClass");
};

Class Game_obj::__mClass;

void Game_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.velvetArts.v01.Game"), hx::TCanCast< Game_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Game_obj::__boot()
{
}

} // end namespace com
} // end namespace velvetArts
} // end namespace v01
