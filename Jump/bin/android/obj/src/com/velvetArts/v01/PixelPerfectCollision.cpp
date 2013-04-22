#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_com_velvetArts_v01_PixelPerfectCollision
#include <com/velvetArts/v01/PixelPerfectCollision.h>
#endif
#ifndef INCLUDED_native_display_BitmapData
#include <native/display/BitmapData.h>
#endif
#ifndef INCLUDED_native_display_BlendMode
#include <native/display/BlendMode.h>
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
#ifndef INCLUDED_native_events_EventDispatcher
#include <native/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_native_events_IEventDispatcher
#include <native/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_native_geom_ColorTransform
#include <native/geom/ColorTransform.h>
#endif
#ifndef INCLUDED_native_geom_Matrix
#include <native/geom/Matrix.h>
#endif
#ifndef INCLUDED_native_geom_Point
#include <native/geom/Point.h>
#endif
#ifndef INCLUDED_native_geom_Rectangle
#include <native/geom/Rectangle.h>
#endif
#ifndef INCLUDED_native_geom_Transform
#include <native/geom/Transform.h>
#endif
namespace com{
namespace velvetArts{
namespace v01{

Void PixelPerfectCollision_obj::__construct()
{
HX_STACK_PUSH("PixelPerfectCollision::new","com/velvetArts/v01/PixelPerfectCollision.hx",20);
{
}
;
	return null();
}

PixelPerfectCollision_obj::~PixelPerfectCollision_obj() { }

Dynamic PixelPerfectCollision_obj::__CreateEmpty() { return  new PixelPerfectCollision_obj; }
hx::ObjectPtr< PixelPerfectCollision_obj > PixelPerfectCollision_obj::__new()
{  hx::ObjectPtr< PixelPerfectCollision_obj > result = new PixelPerfectCollision_obj();
	result->__construct();
	return result;}

Dynamic PixelPerfectCollision_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< PixelPerfectCollision_obj > result = new PixelPerfectCollision_obj();
	result->__construct();
	return result;}

bool PixelPerfectCollision_obj::IsColliding( ::native::display::DisplayObject target1,::native::display::DisplayObject target2,::native::display::DisplayObjectContainer uniqueParent,hx::Null< bool >  __o_pixelPerfect,hx::Null< Float >  __o_tolerance){
bool pixelPerfect = __o_pixelPerfect.Default(false);
Float tolerance = __o_tolerance.Default(0);
	HX_STACK_PUSH("PixelPerfectCollision::IsColliding","com/velvetArts/v01/PixelPerfectCollision.hx",25);
	HX_STACK_ARG(target1,"target1");
	HX_STACK_ARG(target2,"target2");
	HX_STACK_ARG(uniqueParent,"uniqueParent");
	HX_STACK_ARG(pixelPerfect,"pixelPerfect");
	HX_STACK_ARG(tolerance,"tolerance");
{
		HX_STACK_LINE(26)
		::native::geom::Rectangle collisionRect = ::com::velvetArts::v01::PixelPerfectCollision_obj::getCollisionArea(target1,target2,uniqueParent,pixelPerfect,tolerance);		HX_STACK_VAR(collisionRect,"collisionRect");
		HX_STACK_LINE(27)
		if (((bool((collisionRect != null())) && bool((collisionRect->get_size()->get_length() > (int)0))))){
			HX_STACK_LINE(28)
			return true;
		}
		else{
			HX_STACK_LINE(30)
			return false;
		}
		HX_STACK_LINE(27)
		return false;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(PixelPerfectCollision_obj,IsColliding,return )

::native::geom::Rectangle PixelPerfectCollision_obj::getCollisionArea( ::native::display::DisplayObject target1,::native::display::DisplayObject target2,::native::display::DisplayObjectContainer uniqueParent,hx::Null< bool >  __o_pixelPerfect,hx::Null< Float >  __o_tolerance){
bool pixelPerfect = __o_pixelPerfect.Default(false);
Float tolerance = __o_tolerance.Default(0);
	HX_STACK_PUSH("PixelPerfectCollision::getCollisionArea","com/velvetArts/v01/PixelPerfectCollision.hx",34);
	HX_STACK_ARG(target1,"target1");
	HX_STACK_ARG(target2,"target2");
	HX_STACK_ARG(uniqueParent,"uniqueParent");
	HX_STACK_ARG(pixelPerfect,"pixelPerfect");
	HX_STACK_ARG(tolerance,"tolerance");
{
		HX_STACK_LINE(35)
		::native::geom::Rectangle rect1 = ::com::velvetArts::v01::PixelPerfectCollision_obj::getBoundRect(target1);		HX_STACK_VAR(rect1,"rect1");
		HX_STACK_LINE(36)
		::native::geom::Rectangle rect2 = ::com::velvetArts::v01::PixelPerfectCollision_obj::getBoundRect(target2);		HX_STACK_VAR(rect2,"rect2");
		HX_STACK_LINE(38)
		::native::geom::Rectangle intersectionArea = rect1->intersection(rect2);		HX_STACK_VAR(intersectionArea,"intersectionArea");
		HX_STACK_LINE(40)
		if (((intersectionArea->get_size()->get_length() > (int)0))){
			HX_STACK_LINE(41)
			if ((pixelPerfect)){
				HX_STACK_LINE(44)
				intersectionArea->width = ::Math_obj::ceil(intersectionArea->width);
				HX_STACK_LINE(45)
				intersectionArea->height = ::Math_obj::ceil(intersectionArea->height);
				HX_STACK_LINE(47)
				::native::display::BitmapData alpha1 = ::com::velvetArts::v01::PixelPerfectCollision_obj::getAlphaMap(target1,intersectionArea,(int)1,uniqueParent);		HX_STACK_VAR(alpha1,"alpha1");
				HX_STACK_LINE(48)
				::native::display::BitmapData alpha2 = ::com::velvetArts::v01::PixelPerfectCollision_obj::getAlphaMap(target2,intersectionArea,(int)2,uniqueParent);		HX_STACK_VAR(alpha2,"alpha2");
				HX_STACK_LINE(53)
				alpha1->draw(alpha2,null(),null(),::native::display::BlendMode_obj::LIGHTEN_dyn(),null(),null());
				HX_STACK_LINE(56)
				int searchColor;		HX_STACK_VAR(searchColor,"searchColor");
				HX_STACK_LINE(57)
				if (((tolerance <= (int)0))){
					HX_STACK_LINE(58)
					searchColor = (int)65792;
				}
				else{
					HX_STACK_LINE(61)
					if (((tolerance > (int)1))){
						HX_STACK_LINE(61)
						tolerance = (int)1;
					}
					HX_STACK_LINE(62)
					int byte = ::Math_obj::round((tolerance * (int)255));		HX_STACK_VAR(byte,"byte");
					HX_STACK_LINE(63)
					searchColor = (int((int((int(byte) << int((int)16))) | int((int(byte) << int((int)8))))) | int((int)0));
				}
				HX_STACK_LINE(66)
				::native::geom::Rectangle collisionRect = alpha1->getColorBoundsRect(searchColor,searchColor,null());		HX_STACK_VAR(collisionRect,"collisionRect");
				HX_STACK_LINE(67)
				hx::AddEq(collisionRect->x,intersectionArea->x);
				HX_STACK_LINE(68)
				hx::AddEq(collisionRect->y,intersectionArea->y);
				HX_STACK_LINE(69)
				return collisionRect;
			}
			else{
				HX_STACK_LINE(72)
				return intersectionArea;
			}
		}
		else{
			HX_STACK_LINE(77)
			return null();
		}
		HX_STACK_LINE(40)
		return null();
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(PixelPerfectCollision_obj,getCollisionArea,return )

::native::geom::Point PixelPerfectCollision_obj::getCollisionPoint( ::native::display::DisplayObject target1,::native::display::DisplayObject target2,::native::display::DisplayObjectContainer uniqueParent,hx::Null< bool >  __o_pixelPerfect,hx::Null< Float >  __o_tolerance){
bool pixelPerfect = __o_pixelPerfect.Default(false);
Float tolerance = __o_tolerance.Default(0);
	HX_STACK_PUSH("PixelPerfectCollision::getCollisionPoint","com/velvetArts/v01/PixelPerfectCollision.hx",83);
	HX_STACK_ARG(target1,"target1");
	HX_STACK_ARG(target2,"target2");
	HX_STACK_ARG(uniqueParent,"uniqueParent");
	HX_STACK_ARG(pixelPerfect,"pixelPerfect");
	HX_STACK_ARG(tolerance,"tolerance");
{
		HX_STACK_LINE(84)
		::native::geom::Rectangle collisionRect = ::com::velvetArts::v01::PixelPerfectCollision_obj::getCollisionArea(target1,target2,uniqueParent,pixelPerfect,tolerance);		HX_STACK_VAR(collisionRect,"collisionRect");
		HX_STACK_LINE(86)
		if (((bool((collisionRect != null())) && bool((collisionRect->get_size()->get_length() > (int)0))))){
			HX_STACK_LINE(88)
			Float x = (Float(((collisionRect->get_left() + collisionRect->get_right()))) / Float((int)2));		HX_STACK_VAR(x,"x");
			HX_STACK_LINE(89)
			Float y = (Float(((collisionRect->get_top() + collisionRect->get_bottom()))) / Float((int)2));		HX_STACK_VAR(y,"y");
			HX_STACK_LINE(90)
			return ::native::geom::Point_obj::__new(x,y);
		}
		HX_STACK_LINE(93)
		return null();
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(PixelPerfectCollision_obj,getCollisionPoint,return )

::native::display::BitmapData PixelPerfectCollision_obj::getAlphaMap( ::native::display::DisplayObject target,::native::geom::Rectangle rect,int channel,::native::display::DisplayObjectContainer commonParent){
	HX_STACK_PUSH("PixelPerfectCollision::getAlphaMap","com/velvetArts/v01/PixelPerfectCollision.hx",97);
	HX_STACK_ARG(target,"target");
	HX_STACK_ARG(rect,"rect");
	HX_STACK_ARG(channel,"channel");
	HX_STACK_ARG(commonParent,"commonParent");
	HX_STACK_LINE(99)
	::native::geom::Matrix parentXformInvert = commonParent->get_transform()->get_concatenatedMatrix()->clone();		HX_STACK_VAR(parentXformInvert,"parentXformInvert");
	HX_STACK_LINE(100)
	parentXformInvert->invert();
	HX_STACK_LINE(101)
	::native::geom::Matrix targetXform = target->get_transform()->get_concatenatedMatrix()->clone();		HX_STACK_VAR(targetXform,"targetXform");
	HX_STACK_LINE(102)
	targetXform->concat(parentXformInvert);
	HX_STACK_LINE(104)
	targetXform->translate(-(rect->x),-(rect->y));
	HX_STACK_LINE(106)
	::native::display::BitmapData bitmapData = ::native::display::BitmapData_obj::__new(rect->width,rect->height,true,(int)0,null());		HX_STACK_VAR(bitmapData,"bitmapData");
	HX_STACK_LINE(107)
	bitmapData->draw(target,targetXform,null(),null(),null(),null());
	HX_STACK_LINE(108)
	::native::display::BitmapData alphaChannel = ::native::display::BitmapData_obj::__new(rect->width,rect->height,false,(int)0,null());		HX_STACK_VAR(alphaChannel,"alphaChannel");
	HX_STACK_LINE(109)
	alphaChannel->copyChannel(bitmapData,bitmapData->get_rect(),::native::geom::Point_obj::__new((int)0,(int)0),(int)8,channel);
	HX_STACK_LINE(110)
	return alphaChannel;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(PixelPerfectCollision_obj,getAlphaMap,return )

::native::geom::Rectangle PixelPerfectCollision_obj::getBoundRect( ::native::display::DisplayObject object){
	HX_STACK_PUSH("PixelPerfectCollision::getBoundRect","com/velvetArts/v01/PixelPerfectCollision.hx",114);
	HX_STACK_ARG(object,"object");
	HX_STACK_LINE(115)
	Float rotation = object->get_rotation();		HX_STACK_VAR(rotation,"rotation");
	HX_STACK_LINE(117)
	if (((rotation < (int)0))){
		HX_STACK_LINE(118)
		rotation = ((int)360 + rotation);
	}
	HX_STACK_LINE(120)
	::native::geom::Point position = ::native::geom::Point_obj::__new(object->get_x(),object->get_y());		HX_STACK_VAR(position,"position");
	HX_STACK_LINE(122)
	if (((bool((rotation > (int)0)) && bool((rotation < (int)360))))){
		HX_STACK_LINE(123)
		if (((rotation < (int)90))){
			HX_STACK_LINE(125)
			hx::SubEq(position->x,(object->get_height() * ::Math_obj::sin(rotation)));
		}
		else{
			HX_STACK_LINE(129)
			if (((rotation == (int)90))){
				HX_STACK_LINE(130)
				hx::SubEq(position->x,object->get_width());
			}
			else{
				HX_STACK_LINE(134)
				if (((rotation < (int)180))){
					HX_STACK_LINE(136)
					hx::SubEq(position->x,object->get_width());
					HX_STACK_LINE(137)
					hx::SubEq(position->y,(object->get_width() * ::Math_obj::sin(rotation)));
				}
				else{
					HX_STACK_LINE(140)
					if (((rotation == (int)180))){
						HX_STACK_LINE(142)
						hx::SubEq(position->x,object->get_width());
						HX_STACK_LINE(143)
						hx::SubEq(position->y,object->get_height());
					}
					else{
						HX_STACK_LINE(146)
						if (((rotation < (int)270))){
							HX_STACK_LINE(148)
							hx::SubEq(position->x,(object->get_height() * ::Math_obj::sin(rotation)));
							HX_STACK_LINE(149)
							hx::SubEq(position->y,object->get_height());
						}
						else{
							HX_STACK_LINE(152)
							if (((rotation == (int)270))){
								HX_STACK_LINE(153)
								hx::SubEq(position->y,object->get_height());
							}
							else{
								HX_STACK_LINE(158)
								hx::SubEq(position->y,(object->get_width() * ::Math_obj::sin(rotation)));
							}
						}
					}
				}
			}
		}
	}
	HX_STACK_LINE(164)
	return ::native::geom::Rectangle_obj::__new(position->x,position->y,object->get_width(),object->get_height());
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(PixelPerfectCollision_obj,getBoundRect,return )


PixelPerfectCollision_obj::PixelPerfectCollision_obj()
{
}

void PixelPerfectCollision_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(PixelPerfectCollision);
	HX_MARK_END_CLASS();
}

void PixelPerfectCollision_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic PixelPerfectCollision_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 11:
		if (HX_FIELD_EQ(inName,"IsColliding") ) { return IsColliding_dyn(); }
		if (HX_FIELD_EQ(inName,"getAlphaMap") ) { return getAlphaMap_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"getBoundRect") ) { return getBoundRect_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"getCollisionArea") ) { return getCollisionArea_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"getCollisionPoint") ) { return getCollisionPoint_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic PixelPerfectCollision_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void PixelPerfectCollision_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("IsColliding"),
	HX_CSTRING("getCollisionArea"),
	HX_CSTRING("getCollisionPoint"),
	HX_CSTRING("getAlphaMap"),
	HX_CSTRING("getBoundRect"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(PixelPerfectCollision_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(PixelPerfectCollision_obj::__mClass,"__mClass");
};

Class PixelPerfectCollision_obj::__mClass;

void PixelPerfectCollision_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.velvetArts.v01.PixelPerfectCollision"), hx::TCanCast< PixelPerfectCollision_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void PixelPerfectCollision_obj::__boot()
{
}

} // end namespace com
} // end namespace velvetArts
} // end namespace v01
