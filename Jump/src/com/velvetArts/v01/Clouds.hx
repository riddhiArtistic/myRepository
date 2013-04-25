package com.velvetArts.v01;

import nme.Assets;
import nme.display.Sprite;
import nme.Lib;

/**
 * ...
 * @author Riddhi
 */

class Clouds extends Sprite
{
	var frames:Int;
	var cloud1:Sprite;
	var cloud2:Sprite;
	var cloud3:Sprite;
	var actor: Sprite;

	public function new(inX:Float, inY: Float) : Void
	{
		super();
		this.x = inX;
		this.y = inY;
		
		frames = 1;
		
		cloud1 = new Sprite();
		cloud2 = new Sprite();
		cloud3 = new Sprite();
	    actor = new Sprite();
		
		cloud1.graphics.beginBitmapFill(Assets.getBitmapData("img/clouds1.png"), null, false, true);
		cloud1.graphics.drawRect(0, 0, 70, 20);
		
		cloud2.graphics.beginBitmapFill(Assets.getBitmapData("img/clouds2.png"), null, false, true);
		cloud2.graphics.drawRect(0, 0, 70, 20);
		
		cloud3.graphics.beginBitmapFill(Assets.getBitmapData("img/clouds3.png"), null, false, true);
		cloud3.graphics.drawRect(0, 0, 70, 20);
		
		actor = cloud1;
		
		actor.x = -(actor.width) / 2.0;
		actor.y = -(actor.height) / 2.0;
		
		this.addChild(actor);
	}
	
	public function update():Void
	{
		this.graphics.clear();
		
		//matriX.translate( 1, 0);
		
		if ((frames > 60) && (frames <= 120))
		{
			actor = cloud2;
			this.addChild(actor);
		}
		else
		{
			if ((frames > 120) && (frames <= 180))
			{
				actor = cloud3;
			    this.addChild(actor);
			}
			else
			{
				if (frames > 180) frames = 0;
				actor = cloud1;
			    this.addChild(actor);
			}
		}
		
		actor.x = -(actor.width) / 2.0;
		actor.y = -(actor.height) / 2.0;
		
		this.width = 70;
		this.height = 20;
		
        if (this.x > Lib.current.stage.stageWidth)
		    this.x = 0;
		else
		    this.x += 1;
		frames++;
	}
	
}