#include <hxcpp.h>

#ifndef INCLUDED_BackGroundImg
#include <BackGroundImg.h>
#endif
#ifndef INCLUDED_Character
#include <Character.h>
#endif
#ifndef INCLUDED_Jump
#include <Jump.h>
#endif
#ifndef INCLUDED_MovingBGImg
#include <MovingBGImg.h>
#endif
#ifndef INCLUDED_native_display_DisplayObject
#include <native/display/DisplayObject.h>
#endif
#ifndef INCLUDED_native_display_DisplayObjectContainer
#include <native/display/DisplayObjectContainer.h>
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
#ifndef INCLUDED_native_display_StageAlign
#include <native/display/StageAlign.h>
#endif
#ifndef INCLUDED_native_display_StageScaleMode
#include <native/display/StageScaleMode.h>
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
#ifndef INCLUDED_native_geom_Rectangle
#include <native/geom/Rectangle.h>
#endif
#ifndef INCLUDED_nme_Lib
#include <nme/Lib.h>
#endif

Void Jump_obj::__construct()
{
HX_STACK_PUSH("Jump::new","Jump.hx",33);
{
	HX_STACK_LINE(34)
	super::__construct();
	HX_STACK_LINE(38)
	this->addEventListener(::native::events::Event_obj::ADDED_TO_STAGE,this->init_dyn(),null(),null(),null());
}
;
	return null();
}

Jump_obj::~Jump_obj() { }

Dynamic Jump_obj::__CreateEmpty() { return  new Jump_obj; }
hx::ObjectPtr< Jump_obj > Jump_obj::__new()
{  hx::ObjectPtr< Jump_obj > result = new Jump_obj();
	result->__construct();
	return result;}

Dynamic Jump_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Jump_obj > result = new Jump_obj();
	result->__construct();
	return result;}

Void Jump_obj::renderScrollingBG( ::native::events::Event event){
{
		HX_STACK_PUSH("Jump::renderScrollingBG","Jump.hx",60);
		HX_STACK_THIS(this);
		HX_STACK_ARG(event,"event");
		HX_STACK_LINE(61)
		this->movingBG->set_scrollRect(::native::geom::Rectangle_obj::__new(this->scrollIndex,(int)0,((int)640 + this->scrollIndex),(int)480));
		HX_STACK_LINE(63)
		if (((this->scrollIndex > (int)640))){
			HX_STACK_LINE(64)
			this->scrollIndex = (int)0;
		}
		else{
			HX_STACK_LINE(66)
			(this->scrollIndex)++;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Jump_obj,renderScrollingBG,(void))

Void Jump_obj::init( Dynamic e){
{
		HX_STACK_PUSH("Jump::init","Jump.hx",43);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(45)
		this->myBGImg = ::BackGroundImg_obj::__new();
		HX_STACK_LINE(46)
		this->movingBG = ::MovingBGImg_obj::__new();
		HX_STACK_LINE(47)
		this->myCharacter = ::Character_obj::__new();
		HX_STACK_LINE(49)
		this->addChild(this->myBGImg);
		HX_STACK_LINE(51)
		this->scrollIndex = (int)0;
		HX_STACK_LINE(52)
		this->addEventListener(::native::events::Event_obj::ENTER_FRAME,this->renderScrollingBG_dyn(),null(),null(),null());
		HX_STACK_LINE(54)
		this->addChild(this->movingBG);
		HX_STACK_LINE(55)
		this->addChild(this->myCharacter);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Jump_obj,init,(void))

Void Jump_obj::main( ){
{
		HX_STACK_PUSH("Jump::main","Jump.hx",73);
		HX_STACK_LINE(74)
		::native::display::Stage stage = ::nme::Lib_obj::get_current()->get_stage();		HX_STACK_VAR(stage,"stage");
		HX_STACK_LINE(76)
		stage->set_scaleMode(::native::display::StageScaleMode_obj::NO_SCALE_dyn());
		HX_STACK_LINE(77)
		stage->set_align(::native::display::StageAlign_obj::TOP_LEFT_dyn());
		HX_STACK_LINE(79)
		::nme::Lib_obj::get_current()->addChild(::Jump_obj::__new());
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Jump_obj,main,(void))


Jump_obj::Jump_obj()
{
}

void Jump_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Jump);
	HX_MARK_MEMBER_NAME(jumpFlg,"jumpFlg");
	HX_MARK_MEMBER_NAME(moveFWD,"moveFWD");
	HX_MARK_MEMBER_NAME(scrollIndex,"scrollIndex");
	HX_MARK_MEMBER_NAME(myCharacter,"myCharacter");
	HX_MARK_MEMBER_NAME(movingBG,"movingBG");
	HX_MARK_MEMBER_NAME(myBGImg,"myBGImg");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Jump_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(jumpFlg,"jumpFlg");
	HX_VISIT_MEMBER_NAME(moveFWD,"moveFWD");
	HX_VISIT_MEMBER_NAME(scrollIndex,"scrollIndex");
	HX_VISIT_MEMBER_NAME(myCharacter,"myCharacter");
	HX_VISIT_MEMBER_NAME(movingBG,"movingBG");
	HX_VISIT_MEMBER_NAME(myBGImg,"myBGImg");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Jump_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"main") ) { return main_dyn(); }
		if (HX_FIELD_EQ(inName,"init") ) { return init_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"jumpFlg") ) { return jumpFlg; }
		if (HX_FIELD_EQ(inName,"moveFWD") ) { return moveFWD; }
		if (HX_FIELD_EQ(inName,"myBGImg") ) { return myBGImg; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"movingBG") ) { return movingBG; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"scrollIndex") ) { return scrollIndex; }
		if (HX_FIELD_EQ(inName,"myCharacter") ) { return myCharacter; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"renderScrollingBG") ) { return renderScrollingBG_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Jump_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"jumpFlg") ) { jumpFlg=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"moveFWD") ) { moveFWD=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"myBGImg") ) { myBGImg=inValue.Cast< ::BackGroundImg >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"movingBG") ) { movingBG=inValue.Cast< ::MovingBGImg >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"scrollIndex") ) { scrollIndex=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"myCharacter") ) { myCharacter=inValue.Cast< ::Character >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Jump_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("jumpFlg"));
	outFields->push(HX_CSTRING("moveFWD"));
	outFields->push(HX_CSTRING("scrollIndex"));
	outFields->push(HX_CSTRING("myCharacter"));
	outFields->push(HX_CSTRING("movingBG"));
	outFields->push(HX_CSTRING("myBGImg"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("main"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("renderScrollingBG"),
	HX_CSTRING("init"),
	HX_CSTRING("jumpFlg"),
	HX_CSTRING("moveFWD"),
	HX_CSTRING("scrollIndex"),
	HX_CSTRING("myCharacter"),
	HX_CSTRING("movingBG"),
	HX_CSTRING("myBGImg"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Jump_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Jump_obj::__mClass,"__mClass");
};

Class Jump_obj::__mClass;

void Jump_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("Jump"), hx::TCanCast< Jump_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Jump_obj::__boot()
{
}

