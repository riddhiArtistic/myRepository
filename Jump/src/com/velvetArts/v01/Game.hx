package com.velvetArts.v01;

import nme.display.Tilesheet;
import nme.Assets;
import nme.display.Bitmap;
import nme.display.BitmapData;
import nme.display.Sprite;
import nme.events.Event;
import nme.events.MouseEvent;
import nme.geom.Point;
import nme.geom.Rectangle;
import nme.Lib;
import nme.text.TextField;
import nme.text.TextFormat;
import nme.text.TextFormatAlign;

/**
 * ...
 * @author Riddhi
 */

typedef ColIndx = Array<Float>;
 
class Game extends Sprite
{
	var baby:Character;
	var clouds1:Character;
	var clouds2:Character;
	var clouds3:Character;
	var rewards:Character;
	
	public var cloudID: Int; 
	public var moveX:Float;
	public var moveY:Float;
	
	var mClouds: Array<ColIndx>;
	var mRewards: Array<ColIndx>;
	
	public var renderList:Array<Float>;
	var tilesheet:Tilesheet;
	var cur_frame:Float;
	var last_frame: Float;
	
	var stg_ref_x:Float;
	var stg_ref_y:Float;

    public function new(inTiles:Tilesheet):Void
	{
		super();
		Lib.current.addChild(this);	
		
		renderList = new Array<Float>();
		var stgWidth = Lib.current.stage.stageWidth;
		var stgHeight = Lib.current.stage.stageHeight;
		
		tilesheet = inTiles;
		
		tilesheet.addTileRect(new Rectangle(5, 0, 805, 480), new Point(400, 240));    // The BG
		tilesheet.addTileRect(new Rectangle(806, 60, 70, 20), new Point(35, 10));    // The cloud 1
		tilesheet.addTileRect(new Rectangle(806, 80, 70, 20), new Point(35, 10));    // The cloud 2
		tilesheet.addTileRect(new Rectangle(806, 100, 70, 20), new Point(35, 10));    // The cloud 3
		tilesheet.addTileRect(new Rectangle(806, 0, 60, 60), new Point(30, 30));    // The baby
		tilesheet.addTileRect(new Rectangle(806, 120, 35, 35), new Point(17.5, 17.5));  // The rewards
		
		baby = new Character(4, this);
		clouds1 = new Character(1, this);
		clouds2 = new Character(2, this);
		clouds3 = new Character(3, this);
		rewards = new Character(5, this);
		
		mClouds = [];
		mClouds[stgWidth - 1] = null;
		
		mRewards = [];
		mRewards[stgWidth - 1] = null;
		
		for (i in 0...20)
		{
			var y = Std.int((Math.random() * 600)) - 60;
			var x = (Math.random() * (stgWidth - 30)); 
			
			if (mClouds[y] == null)
                mClouds[y] = [];
			mClouds[y].push(x);
		}
		
		for (i in 0...7)
		{
			var y = Std.int((Math.random() * 600)) - 60;
			var x = (Math.random() * (stgHeight - 30)); 
			
			if (mRewards[y] == null)
                mRewards[y] = [];
			mRewards[y].push(x);
		}
		
		moveX = Lib.current.stage.stageWidth / 2;
		moveY = 30;
		
		Lib.current.stage.addEventListener(Event.ENTER_FRAME, frameEnter);
	}
	
	public function Render():Void
	{
		var stg_x = Lib.current.stage.stageWidth;
		var stg_y = Lib.current.stage.stageHeight;
		
		renderList = [stg_x/2, stg_y/2, 0]; // The BG
	
		if(moveY < (stg_y - 30))
		    moveY += 3;
		else
		{    
			var mText = new TextField();
			mText.background = false;
			mText.x = 0;
			mText.y = stg_y/2;
			var format:TextFormat =  new TextFormat();
			
			format.font = "Arial";
			format.bold = true;
			format.color = 0x0000ff;
			format.size = 30;
			format.align = TextFormatAlign.CENTER;
			mText.defaultTextFormat = format;
			mText.text = "YOU DIED! :(";
			mText.width = 800;
			mText.height =  40;
			addChild(mText);
		}
		var scroll_x = moveX - 30;
		
		for (x in -10...(stg_x+10))
		{
			var feild_x = Std.int(scroll_x + x) % stg_x;
			var col = mClouds[feild_x];
			
			if (col != null)
			{
				for (y in col)
				{
					cloudID = Std.random(3) + 1;
		            if (cloudID == 1)
				        clouds1.update(x, y);
		            else 
			        {
				        if (cloudID == 2)
		                    clouds2.update(x, y);
				        else
		                    clouds3.update(x, y);
			        }
				}
			}
		}
		
		baby.update(moveX, moveY);
		
		for (x in 30...(stg_x-30))
		{
			var feild_x = Std.int(scroll_x + x) % stg_x;
			var col = mRewards[feild_x];
			
			if (col != null)
			{
				for (y in col)
				{
					rewards.update(x, y);
				}
			}
		}
		
		
	}
	
	private function frameEnter(e:Event):Void
	{
		//Lib.current.stage.addEventListener(TouchEvent.TOUCH_BEGIN, startDragging);
		Lib.current.stage.addEventListener(MouseEvent.MOUSE_DOWN, move);
		
		graphics.clear();
		renderList = [];
		Render();
		tilesheet.drawTiles(graphics, renderList);
	}
	
	/*private function startDragging(e:TouchEvent):Void 
	{
		Lib.current.stage.addEventListener(TouchEvent.TOUCH_END, stopDragging);
        Lib.current.stage.addEventListener(TouchEvent.TOUCH_MOVE, jump);
	}
	
	private function jump (e:TouchEvent):Void
	{
		if (e.touchPointID == 0)
		{
			
			    if ((30 < e.stageY) && (e.stageY < (Lib.current.stage.stageHeight - 30)))
		        {
			        y = e.stageY;
					x = e.stageX;
					
			    }
			
		}
		e.updateAfterEvent();
	}
	
	private function stopDragging(e:TouchEvent):Void
	{
        Lib.current.stage.removeEventListener(TouchEvent.TOUCH_END, stopDragging);
        Lib.current.stage.removeEventListener(TouchEvent.TOUCH_MOVE, jump);
    }*/
	
	private function move(e:MouseEvent)
	{
		Lib.current.stage.addEventListener(MouseEvent.MOUSE_MOVE, moveTile);
		Lib.current.stage.addEventListener(MouseEvent.MOUSE_UP, noMove);
		
		stg_ref_x = e.stageX;
		stg_ref_y = e.stageY;
		
		e.updateAfterEvent();
	}
	
	private function moveTile(e:MouseEvent):Void 
	{		
		if((moveX != stg_ref_x) || (moveY != stg_ref_y))
		{
			if(stg_ref_x > moveX)
			    moveX += 5;
		    if(stg_ref_x < moveX)
			    moveX -= 5;
				
			if (stg_ref_y > moveY)
			    moveY += 2;
			if (stg_ref_y < moveY)
			    moveY -= 2;	
		}
	}
	
	private function noMove(e:MouseEvent):Void
	{
		Lib.current.stage.removeEventListener(MouseEvent.MOUSE_MOVE, moveTile);
		Lib.current.stage.removeEventListener(MouseEvent.MOUSE_UP, move);
	}
}