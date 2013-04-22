package com.velvetArts.v01;

import nme.Assets;
import nme.display.Sprite;
import nme.geom.Matrix;
import nme.events.Event;
import nme.events.TouchEvent;
import nme.events.MouseEvent;
import nme.Lib;
/**
 * ...
 * @author Riddhi
 */

class Candy extends Character
{
	private var framedelay:Int = 0;

	public function new(inX:Float, inY: Float) : Void
	{
		super();
		this.x = inX;
		this.y = inY;
		
		actor = new Sprite();
		matriX = new Matrix();
		
		actor.graphics.beginBitmapFill(Assets.getBitmapData("img/candy.png"));
		actor.graphics.drawRect(0, 0, 36, 36);
		
		actor.x = -(actor.width) / 2.0;
		actor.y = -(actor.height) / 2.0;
		
		this.addChild(actor);
		
		this.width = 36;
		this.height = 36;
		
		addEventListener(Event.ENTER_FRAME, update);
	}
	
	private function update(e:Event):Void
	{
		 if (this.x > Lib.current.stage.stageWidth)
		    this.x = 0;
		else
		    this.x += 1;
		/*if (this.x == Lib.current.stage.stageWidth)
		{
			this.x = 10;
		}else
		{
		    this.x += 2.0;
		}*/
		
		if (!this.visible)
		{
			if (framedelay > 300)
			{
			    this.visible = true;
				framedelay = 0;
			}
			framedelay ++;
		} 
	}	
}