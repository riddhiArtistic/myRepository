package com.velvetArts.v01;
import nme.Assets;
import nme.display.Bitmap;
import nme.display.BitmapData;
import nme.display.Sprite;
import nme.events.Event;
import nme.events.MouseEvent;
import nme.events.TouchEvent;
import nme.geom.Matrix;
import nme.geom.Point;
import nme.geom.Rectangle;
import nme.Lib;
import nme.ui.Multitouch;

/**
 * ...
 * @author Riddhi
 */

class Character
{
    var tile_ID:Int;
    var mPoint:Point;
    var curr_Game: Game;
	var x:Float;
	var y:Float;
		
    public function new(tileID:Int, game:Game): Void
    {		
		mPoint = new Point(0, 0);
		
		tile_ID = tileID;
		x = Lib.current.stage.stageWidth / 2;
		y = 30;
		curr_Game = game;
	}
	
	/*private function resize():Void 
	{
		//this.width = 60;
		//this.height = 60;
		x = 10;
		y = (Lib.current.stage.stageHeight) / 2;
	}
	
	private function resizeHandler(e:Event):Void
	{
		resize();
	}*/
		
	public function update(pos_X: Float, pos_Y: Float): Void
	{
		x = pos_X;
		y = pos_Y;
		/*if (tile_ID != 4)
		{
			x = Std.random(740) + 30;
			y = Std.random(405) + 15;
		}
		else
		{
			x = Lib.current.stage.stageWidth / 2;
			y = Lib.current.stage.stageHeight / 2;
			
			Lib.current.stage.addEventListener(TouchEvent.TOUCH_BEGIN, startDragging);
		    Lib.current.stage.addEventListener(MouseEvent.MOUSE_DOWN, en_Move);
		}*/
		curr_Game.renderList.push(x);
		curr_Game.renderList.push(y);
		curr_Game.renderList.push(tile_ID);
	}
}