package com.velvetArts.v01;

import nme.Assets;
import nme.display.Sprite;
import nme.events.Event;
import nme.events.TouchEvent;
import nme.events.MouseEvent;
import nme.Lib;

/**
 * ...
 * @author Riddhi
 */

class Actor extends Sprite
{
	public var IsActive: Bool = false;
	private var actor: Sprite;
	public var jumpFlag:Bool;
	public var jumpFWD:Bool;
	public var jumpBKW:Bool;
	var mouse_X:Float;

	public function new(): Void
	{
		super();
		actor = new Sprite();
		
		actor.graphics.beginBitmapFill(Assets.getBitmapData("img/baby.png"), null, false, true);
		//actor.graphics.beginFill(0xffcc99, 0.8);
		//actor.graphics.drawCircle(0, 0, 30);
		actor.graphics.drawRect(0, 0, 60, 60);
		
		actor.x = -(actor.width) / 2.0;
		actor.y = -(actor.height) / 2.0;
		
		this.x = Lib.current.stage.stageWidth / 2.0;
		this.y = Lib.current.stage.stageHeight / 2.0;
		
		this.addChild(actor);
		
		jumpFlag = false;
		jumpBKW = false;
		jumpFWD = false;
	}
	
	public function update():Void
	{
		if (IsActive)
		{
			Lib.current.stage.addEventListener(TouchEvent.TOUCH_BEGIN, startDragging);
			Lib.current.stage.addEventListener(MouseEvent.MOUSE_DOWN, en_Move);
		}
	}
	
	private function startDragging(e:TouchEvent):Void 
	{
		if (IsActive)
		{
			mouse_X = e.stageX;
			Lib.current.stage.addEventListener(TouchEvent.TOUCH_END, stopDragging);
			Lib.current.stage.addEventListener(TouchEvent.TOUCH_MOVE, jump);
		}
	}
	
	private function jump (e:TouchEvent):Void
	{
		if (IsActive)
		{
			if (e.touchPointID == 0)
			{
				if ((30 < e.stageY) && (e.stageY < (Lib.current.stage.stageWidth - 30)))
		        {
			        jumpFlag = true;
			    }
			}
		}
		//e.updateAfterEvent();
	}
	
	private function stopDragging(e:TouchEvent):Void
	{
		jumpFlag = false;
        Lib.current.stage.removeEventListener(TouchEvent.TOUCH_END, stopDragging);
        Lib.current.stage.removeEventListener(TouchEvent.TOUCH_MOVE, jump);
    }
	
	private function en_Move(e:MouseEvent):Void 
	{
		mouse_X = e.stageX;
		Lib.current.stage.addEventListener(MouseEvent.MOUSE_MOVE, Move);
		Lib.current.stage.addEventListener(MouseEvent.MOUSE_UP, stopMove);
		
		e.updateAfterEvent();
	}
	
	private function Move(e:MouseEvent):Void 
	{
		if ((30 < e.stageY) && (e.stageY < (Lib.current.stage.stageWidth - 30)))
		{
			jumpFlag = true;
			if (e.stageX - mouse_X > 0)
			{
				jumpFWD = true;
				jumpBKW = false;
			}
			else
			{
				jumpBKW = true;
				jumpFWD = false;
			}
		}
	}
	
	private function stopMove(e:MouseEvent):Void
	{
		jumpFlag = false;
		jumpBKW = false;
		jumpFWD = false;
		Lib.current.stage.removeEventListener(MouseEvent.MOUSE_MOVE, Move);
		Lib.current.stage.removeEventListener(MouseEvent.MOUSE_DOWN, en_Move);
	}
}