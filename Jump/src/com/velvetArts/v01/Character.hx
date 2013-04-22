package com.velvetArts.v01;
import nme.Assets;
import nme.display.Bitmap;
import nme.display.Sprite;
import nme.events.Event;
import nme.events.MouseEvent;
import nme.events.TouchEvent;
import nme.geom.Matrix;
import nme.Lib;
import nme.ui.Multitouch;

/**
 * ...
 * @author Riddhi
 */

class Character extends Sprite
{
	private var actor:Sprite;
	private var matriX:Matrix;
	private var mouseMove:Bool;

	public function new() : Void
	{
		super();
		
		resize();
		
		addEventListener(Event.RESIZE, resizeHandler);
	}
	
	private function resize():Void 
	{
		
		this.x = (Lib.current.stage.stageWidth) / 2;
		this.y = (Lib.current.stage.stageHeight) / 2;
	}
	
	private function resizeHandler(e:Event):Void
	{
		resize();
	}
}