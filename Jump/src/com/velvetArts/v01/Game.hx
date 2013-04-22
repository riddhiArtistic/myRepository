package com.velvetArts.v01;
import nme.display.Sprite;
import nme.events.Event;
import nme.events.MouseEvent;
import nme.events.TouchEvent;
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
	
	var states:GameStates;

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
		
		states = new GameStates();
		
	    addEventListener(Event.ENTER_FRAME, update);
	}
	
	private function update(e:Event) : Void
	{
		var stgWidth = Lib.current.stage.stageWidth;
		var stgHeight = Lib.current.stage.stageHeight;
		
		if (states.Active)
		{
			baby.IsActive = true;
			check_Collision();
		
			if (!cloudHit)
			{
				if (baby.x > stgWidth)
					baby.x = 0;
				else
					baby.x += 0.5;
				
				if (baby.y > stgHeight)
				{
					states.Inactive = true;     //Scope for pausing, not yet implemented
					states.Active = false;
					states.Play = false;
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
		else
		{
			if (states.Inactive)
			{
				baby.IsActive = false;
				
				var format:TextFormat =  new TextFormat();
				var terminalText:TextField;
				terminalText = new TextField();
				format.font = "Arial";
				format.bold = true;
				format.color = 0x008822;
				format.size = 40;
				format.align = TextFormatAlign.CENTER;
		
				terminalText.background = false;
				terminalText.defaultTextFormat = format;
				terminalText.x = 10;
				terminalText.y = (stgHeight / 2) - 25;
				terminalText.width = (stgWidth - 20);
				terminalText.height = 50;
				terminalText.text = "YOU DIED! :(";
				addChild(terminalText);
			}
		}
		
		
		/*var format:TextFormat =  new TextFormat();
	    clickToPLay = new TextField();
		format.font = "Arial";
		format.bold = true;
		format.color = 0x008822;
		format.size = 40;
		format.align = TextFormatAlign.CENTER;
		
		clickToPLay.background = false;
		clickToPLay.defaultTextFormat = format;
		clickToPLay.x = 10;
		clickToPLay.y = (stgHeight / 2) - 25;
		clickToPLay.width = (stgWidth - 20);
		clickToPLay.height = 50;
		
		if (states.Play)
		{
			clickToPLay.text = "Touch to Play";
			clickToPLay.text = "Click to Play!";
			clickToPLay.addEventListener(TouchEvent.TOUCH_TAP, startTouchGame);
			clickToPLay.addEventListener(MouseEvent.MOUSE_DOWN, startClickGame);
			clickToPLay.visible = true;
		}
		else
		{
			clickToPLay.visible = false;
		}
		addChild(clickToPLay);*/
		
		var format:TextFormat =  new TextFormat();
		var mScoreText:TextField;
		mScoreText = new TextField();
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
		if(states.Active)
			mScoreText.text = "Score: " + mScore;
		else if (states.Inactive)
		    mScoreText.text = "Your Score: " + mScore;
		else if (states.Play)
		{
		    mScoreText.text = "Click To Play!";
			mScoreText.addEventListener(TouchEvent.TOUCH_TAP, startTouchGame);
			mScoreText.addEventListener(MouseEvent.MOUSE_DOWN, startClickGame);
		}
		addChild(mScoreText);
		
		var format:TextFormat =  new TextFormat();
		var mTopScoreText:TextField;
		mTopScoreText = new TextField();
		format.font = "Arial";
		format.bold = true;
		format.color = 0x008822;
		format.size = 20;
		format.align = TextFormatAlign.RIGHT;
	
		mTopScoreText.x = stgWidth - 310;
		mTopScoreText.y = 20;
		mTopScoreText.width = 300;
		mTopScoreText.height = 30;
		mTopScoreText.defaultTextFormat = format;
		mTopScoreText.background = false;
		if (topScore < mScore)
		{
			if(states.Active)
				mTopScoreText.text = "Top Score: " + mScore;
			else if(states.Inactive)
			    mTopScoreText.text = "Your Top Score: " + mScore;
		}
		else
		{
			if(states.Active)
				mTopScoreText.text = "Top Score: " + topScore;
			else if(states.Inactive)
			    mTopScoreText.text = "Your Top Score: " + topScore;
		}
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
	
	private function startClickGame(e: MouseEvent): Void
	{
		states.Active = true;
		states.Play = false;
		states.Inactive = false;
		
		//mScoreText.removeEventListener(MouseEvent.MOUSE_DOWN, endClick);
	}
	
	private function endClick(e:MouseEvent): Void
	{
		
	}
	
	private function startTouchGame(e:TouchEvent) : Void
	{
		if (e.isPrimaryTouchPoint)
		{
			states.Active = true;
			states.Play = false;
			states.Inactive = false;
			
			//mScoreText.removeEventListener(TouchEvent.TOUCH_TAP, endTap);
		}
	}
	
	private function endTap(e:TouchEvent): Void
	{
        
	}
}