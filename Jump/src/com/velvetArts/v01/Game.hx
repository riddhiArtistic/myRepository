package com.velvetArts.v01;
import haxe.Timer;
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
	
	private var mScore: Int;
	private var topScore: Int;
	
	private static var fps_data:Dynamic = 1000/30;
	
	var timer:Timer;
	
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
		
		timer = new Timer(fps_data);
		
		timer.run = function() {
			graphics.clear();
			update();
		}
		
	    //addEventListener(Event.ENTER_FRAME, update);
	}
	
	private function update() : Void
	{
		var stgWidth = Lib.current.stage.stageWidth;
		var stgHeight = Lib.current.stage.stageHeight;
		bgImg.update();
		
		if (states.Active)
		{
			baby.IsActive = true;
			baby.update();
			for (i in 0...20)
				mClouds[i].update();
			for (i in 0...10)
				mCandies[i].update();
				
			if (baby.jumpFlag)
			{
				if (cloudHit)
				  cloudHit = false;
				if(baby.y > 0)
					baby.y -= 2;
				else
				    baby.y = 30;
				if (baby.jumpFWD)
					baby.x += 2;
				if (baby.jumpBKW)
					baby.x -= 1.5;
			}
			else
			{
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
					baby.y += 2;	
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
			    if (baby.hitTestObject(mClouds[i]))
			    {
					cloudHit = true;
					baby.x = mClouds[i].x;
					baby.y = mClouds[i].y - 25;
			        
				}
				
			}
		}
		
		for (i in 0...10)
		{
			if (mCandies[i].visible)
			{
				if(baby.hitTestObject(mCandies[i]))
			    {
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
		}
	}
	
	private function endTap(e:TouchEvent): Void
	{
        
	}
}