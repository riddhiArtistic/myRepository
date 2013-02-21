package ;

import nme.display.Bitmap;

import nme.events.KeyboardEvent;
import nme.ui.Keyboard;

import nme.display.Sprite;
import nme.events.Event;
import nme.Assets;
import nme.Lib;

/**
 * ...
 * @author Riddhi
 */

class Character extends Sprite 
{
	private var myBitmap:Bitmap;
	var container:Sprite;
	
	public function new() 
	{
		super();
		#if iphone
		Lib.current.stage.addEventListener(Event.RESIZE, init);
		#else
		addEventListener(Event.ADDED_TO_STAGE, init);
		#end
	}

	private function init(e) 
	{
		// entry point
		myBitmap = new Bitmap (Assets.getBitmapData("assets/baby.png"));
		container = new Sprite();
		container.addChild(myBitmap);
		
		container.x = 20;
		container.y = (stage.stageHeight) / 2;
		myBitmap.alpha = 0;
		
		myBitmap.x = -(myBitmap.width) / 2;
		myBitmap.y = -(myBitmap.height) / 2;
		
		container.buttonMode = true;
		
		addChild(container);
		addEventListener(Event.ENTER_FRAME, updateImg);
		// new to Haxe NME? please read *carefully* the readme.txt file!
	}
	
	private function updateImg(eve:Event):Void
	{
		myBitmap.alpha = 1;
		container.rotation += 5.0;
		if (container.x >= (stage.stageWidth- 20))
		{
			container.x = 20;
		} else {
		    container.x += 1;
		}
	}
}
