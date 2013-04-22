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
	
	private var mScore: Int;
	private var topScore: Int;

	public function new() : Void
	{
		super();
		Lib.current.stage.addChild(this);
		
		stgWidth = Lib.current.stage.stageWidth;
		stgHeight = Lib.current.stage.stageHeight;
		
		bgImg = new MovingBG();
		addChild(bgImg);
		
		mCandies = [];
		for (i in 0...10)
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
		mScore = 0;
		topScore = 1000;
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
		
		var mScoreText: TextField = new TextField();
		var format:TextFormat =  new TextFormat();
			
	    format.font = "Arial";
		format.bold = true;
		format.color = 0x008822;
		format.size = 20;
		format.align = TextFormatAlign.LEFT;
		
		mScoreText.x = 10;
		mScoreText.y = 20;
		mScoreText.width = 200;
		mScoreText.height = 30;
		mScoreText.defaultTextFormat = format;
		mScoreText.background = false;
		mScoreText.text = "Score: " + mScore;
		addChild(mScoreText);
		
		var mTopScoreText: TextField = new TextField();
		var format:TextFormat =  new TextFormat();
			
	    format.font = "Arial";
		format.bold = true;
		format.color = 0x008822;
		format.size = 20;
		format.align = TextFormatAlign.RIGHT;
		
		mTopScoreText.x = stgWidth - 210;
		mTopScoreText.y = 20;
		mTopScoreText.width = 200;
		mTopScoreText.height = 30;
		mTopScoreText.defaultTextFormat = format;
		mTopScoreText.background = false;
		if (topScore < mScore)
		    mTopScoreText.text = "Top Score: " + mScore;
		else
		    mTopScoreText.text = "Top Score: " + topScore;
		addChild(mTopScoreText);
	}
	
	private function check_Collision(): Void 
	{
		for (i in 0...20)
		{
			if (!cloudHit)
			{
			    if (PixelPerfectCollision.IsColliding(baby, mClouds[i], this, false, 0))
			    {
					cloudHit = true;
					baby.x = mClouds[i].x;
					baby.y = mClouds[i].y - 30;
					hitPoint = PixelPerfectCollision.getCollisionPoint(baby, mClouds[i], this, false, 0);			        
				}
				
			}
		}
		
		for (i in 0...10)
		{
			if (mCandies[i].visible)
			{
			    if (PixelPerfectCollision.IsColliding(baby, mCandies[i], this, false, 0))
			    {
					//rewardHit = true;
					mScore += 10;
					mCandies[i].visible = false;			        
				}
				
			}
		}
	}
}