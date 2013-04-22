package com.velvetArts.v01;
import nme.display.Sprite;
import nme.events.Event;
import nme.geom.Point;
import nme.Lib;
import nme.text.TextField;
import nme.text.TextFormat;
import nme.text.TextFormatAlign;

/**
 * ...
 * @author Riddhi
 */

class Game extends Sprite
{
	private var bgImg: MovingBG;
	private var baby: Actor;
	private var mClouds: Array<Clouds>;
	private var mCandies: Array<Candy>;
	private var stgWidth: Float;
	private var stgHeight: Float;
	
	private var rewardHit: Bool = false;
	private var cloudHit:Bool = false;
	private var hitPoint:Point;

	public function new() : Void
	{
		super();
		Lib.current.stage.addChild(this);
		
		stgWidth = Lib.current.stage.stageWidth;
		stgHeight = Lib.current.stage.stageHeight;
		
		bgImg = new MovingBG();
		addChild(bgImg);
		
		mCandies = [];
		for (i in 0...7)
		{
			var x_pos:Float = Math.random() * stgWidth;
			var y_pos:Float = Math.random() * stgHeight;
			
			mCandies[i] = new Candy(x_pos, y_pos);
			addChild(mCandies[i]);
		}
		
		mClouds = [];
		for (i in 0...20)
		{
			var x_pos:Float = Math.random() * stgWidth;
			var y_pos:Float = Math.random() * stgHeight;
			
			mClouds[i] = new Clouds(x_pos, y_pos);
			addChild(mClouds[i]);
		}
		
		baby = new Actor();
		addChild(baby);
		addEventListener(Event.ENTER_FRAME, update);
	}
	
	private function update(e:Event) : Void
	{
		var stgWidth = Lib.current.stage.stageWidth;
		var stgHeight = Lib.current.stage.stageHeight;
		
		check_Collision();
		
		if (!cloudHit)
		{
		    if (baby.x > stgWidth)
		        baby.x = 0;
		    else
		        baby.x += 0.5;
				
			if (baby.y > stgHeight)
			{
				var mText = new TextField();
			    mText.x = 0;
			    mText.y = stgHeight/2;
			    var format:TextFormat =  new TextFormat();
			
			    format.font = "Arial";
			    format.bold = true;
			    format.color = 0x0000ff;
			    format.size = 30;
			    format.align = TextFormatAlign.CENTER;
			    mText.defaultTextFormat = format;
				mText.background = false;
			    mText.text = "YOU DIED! :(";
			    mText.width = 800;
			    mText.height =  40;
			    addChild(mText);
			}
			baby.y += 0.5;
			
			
		}
		else
		{
			if (baby.x > stgWidth)
		        baby.x = 0;
		    else
		        baby.x += 1;
			cloudHit = !cloudHit; 
		}
		
	}
	
	private function check_Collision(): Void 
	{
		for (i in 0...20)
		{
			if (!cloudHit)
			{
			    if (PixelPerfectCollision.IsColliding(baby, mClouds[i], this, true, 0))
			    {
					cloudHit = true;
					baby.x = mClouds[i].x;
					baby.y = mClouds[i].y - 30;
					hitPoint = PixelPerfectCollision.getCollisionPoint(baby, mClouds[i], this, true, 0);			        
				}
				
			}
		}
		
		for (i in 0...7)
		{
			if (mCandies[i].visible)
			{
			    if (PixelPerfectCollision.IsColliding(baby, mCandies[i], this, true, 0))
			    {
					//rewardHit = true;
					mCandies[i].visible = false;			        
				}
				
			}
		}
	}
	
}