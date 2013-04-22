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

class Actor extends Character
{
	public var IsActive: Bool = false;

	public function new(): Void
	{
		super();
		
		actor = new Sprite();
		matriX = new Matrix();
		
		
		actor.graphics.beginBitmapFill(Assets.getBitmapData("img/baby.png"), matriX, false, true);
		//actor.graphics.beginFill(0xffcc99, 0.8);
		//actor.graphics.drawCircle(0, 0, 30);
		actor.graphics.drawRect(0, 0, 60, 60);
		
		actor.x = -(actor.width) / 2.0;
		actor.y = -(actor.height) / 2.0;
		
		this.addChild(actor);
		
		this.width = 60;
		this.height = 60;
		
		addEventListener(Event.ENTER_FRAME, update);
	}
	
	private function update(e:Event):Void
	{
		if (IsActive)
		{
			Lib.current.stage.addEventListener(TouchEvent.TOUCH_BEGIN, startDragging);
			Lib.current.stage.addEventListener(MouseEvent.MOUSE_DOWN, en_Move);
		}
		
		/*if (this.x == Lib.current.stage.stageWidth)
		{
			this.x = 10;
		}else
		{
		    this.x += 2.0;
		}*/
	}
	
	private function startDragging(e:TouchEvent):Void 
	{
		if (IsActive)
		{
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
			        this.y = e.stageY;
					this.x = e.stageX;
			    }
			}
			
		}
		//e.updateAfterEvent();
	}
	
	private function stopDragging(e:TouchEvent):Void
	{
        Lib.current.stage.removeEventListener(TouchEvent.TOUCH_END, stopDragging);
        Lib.current.stage.removeEventListener(TouchEvent.TOUCH_MOVE, jump);
    }
	
	private function en_Move(e:MouseEvent):Void 
	{
		Lib.current.stage.addEventListener(MouseEvent.MOUSE_MOVE, Move);
		Lib.current.stage.addEventListener(MouseEvent.MOUSE_UP, stopMove);
		
		e.updateAfterEvent();
	}
	
	private function Move(e:MouseEvent):Void 
	{
		if ((30 < e.stageY) && (e.stageY < (Lib.current.stage.stageWidth - 30)))
		{
		    this.y = e.stageY;
			this.x = e.stageX;
		}
	}
	
	private function stopMove(e:MouseEvent):Void
	{
		Lib.current.stage.removeEventListener(MouseEvent.MOUSE_MOVE, Move);
		Lib.current.stage.removeEventListener(MouseEvent.MOUSE_DOWN, en_Move);
	}
}