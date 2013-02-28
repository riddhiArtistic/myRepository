package com.velvetArts.v01;

import nme.display.Bitmap;
import nme.Assets;
import nme.display.Sprite;
import nme.events.Event;
import nme.Lib;

/**
 * ...
 * @author Riddhi
 */

class MovingBG extends Sprite
{

	private var BG:Bitmap;
	
	public function new() 
	{
		super();
		BG = new Bitmap(Assets.getBitmapData("img/movingBG.png"));
		
		resize();
		addChild(BG);
		
		addEventListener(Event.RESIZE, resizeHandler);
	}
	
	private function resize():Void 
	{
	    BG.x = (Lib.current.stage.stageWidth - BG.width) / 2;
		BG.y = (Lib.current.stage.stageHeight - BG.height) / 2;	
	}
	
	private function resizeHandler(e:Event):Void
	{
		resize();
	}
	
}