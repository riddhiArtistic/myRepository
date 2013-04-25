package com.velvetArts.v01;

import nme.display.Bitmap;
import nme.Assets;
import nme.display.Sprite;
import nme.events.Event;
import nme.geom.Matrix;
import nme.Lib;

/**
 * ...
 * @author Riddhi
 */

class MovingBG extends Sprite
{

	private var BG:Bitmap;
	var matriX: Matrix;
	
	public function new() : Void
	{
		super();
		BG = new Bitmap(Assets.getBitmapData("img/movingBG.png"));
		matriX = new Matrix();
		
		resize();
		Lib.current.stage.addChild(this);
		
		addEventListener(Event.RESIZE, resizeHandler);
	}
	
	private function resize():Void 
	{
	    this.x = 0; 
		this.y = 0; 
	}
	
	private function resizeHandler(e:Event):Void
	{
		resize();
	}
	
	public function update(): Void
	{
		matriX.translate( -1, 0);
		
		this.graphics.clear();
		this.graphics.beginBitmapFill(BG.bitmapData, matriX, true);
		this.graphics.drawRect(0, 0, Lib.current.stage.stageWidth, Lib.current.stage.stageHeight);
	}
	
}