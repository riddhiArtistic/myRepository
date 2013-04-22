#ifndef INCLUDED_com_velvetArts_v01_PixelPerfectCollision
#define INCLUDED_com_velvetArts_v01_PixelPerfectCollision

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(com,velvetArts,v01,PixelPerfectCollision)
HX_DECLARE_CLASS2(native,display,BitmapData)
HX_DECLARE_CLASS2(native,display,DisplayObject)
HX_DECLARE_CLASS2(native,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(native,display,IBitmapDrawable)
HX_DECLARE_CLASS2(native,display,InteractiveObject)
HX_DECLARE_CLASS2(native,events,EventDispatcher)
HX_DECLARE_CLASS2(native,events,IEventDispatcher)
HX_DECLARE_CLASS2(native,geom,Point)
HX_DECLARE_CLASS2(native,geom,Rectangle)
namespace com{
namespace velvetArts{
namespace v01{


class PixelPerfectCollision_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef PixelPerfectCollision_obj OBJ_;
		PixelPerfectCollision_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< PixelPerfectCollision_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~PixelPerfectCollision_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("PixelPerfectCollision"); }

		static bool IsColliding( ::native::display::DisplayObject target1,::native::display::DisplayObject target2,::native::display::DisplayObjectContainer uniqueParent,hx::Null< bool >  pixelPerfect,hx::Null< Float >  tolerance);
		static Dynamic IsColliding_dyn();

		static ::native::geom::Rectangle getCollisionArea( ::native::display::DisplayObject target1,::native::display::DisplayObject target2,::native::display::DisplayObjectContainer uniqueParent,hx::Null< bool >  pixelPerfect,hx::Null< Float >  tolerance);
		static Dynamic getCollisionArea_dyn();

		static ::native::geom::Point getCollisionPoint( ::native::display::DisplayObject target1,::native::display::DisplayObject target2,::native::display::DisplayObjectContainer uniqueParent,hx::Null< bool >  pixelPerfect,hx::Null< Float >  tolerance);
		static Dynamic getCollisionPoint_dyn();

		static ::native::display::BitmapData getAlphaMap( ::native::display::DisplayObject target,::native::geom::Rectangle rect,int channel,::native::display::DisplayObjectContainer commonParent);
		static Dynamic getAlphaMap_dyn();

		static ::native::geom::Rectangle getBoundRect( ::native::display::DisplayObject object);
		static Dynamic getBoundRect_dyn();

};

} // end namespace com
} // end namespace velvetArts
} // end namespace v01

#endif /* INCLUDED_com_velvetArts_v01_PixelPerfectCollision */ 
