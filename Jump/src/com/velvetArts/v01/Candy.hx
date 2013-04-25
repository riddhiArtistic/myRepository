package com.velvetArts.v01;

import nme.Assets;
import nme.display.Sprite;
import nme.Lib;
/**
 * ...
 * @author Riddhi
 */

class Candy extends Sprite
{
	private var framedelay:Int = 0;
	private var actor:Sprite;

	public function new(inX:Float, inY: Float) : Void
	{
		super();
		this.x = inX;
		this.y = inY;
		
		actor = new Sprite();
		
		actor.graphics.beginBitmapFill(Assets.getBitmapData("img/candy.png"));
		actor.graphics.drawRect(0, 0, 36, 36);
		
		actor.x = -(actor.width) / 2.0;
		actor.y = -(actor.height) / 2.0;
		
		this.addChild(actor);
		
		this.width = 36;
		this.height = 36;
	}
	
	public function update():Void
	{
		 if (this.x > Lib.current.stage.stageWidth)
		    this.x = 0;
		else
		    this.x += 1;
			
		if (!this.visible)
		{
			if (framedelay > 180)
			{
			    this.visible = true;
				framedelay = 0;
			}
			framedelay ++;
		} 
	}	
}