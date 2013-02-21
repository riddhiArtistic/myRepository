package ;

import nme.display.Bitmap;
import com.eclecticdesignstudio.motion.Actuate;
import com.eclecticdesignstudio.motion.easing.Bounce;
import nme.display.Sprite;

import nme.events.Event;

import nme.Assets;
import nme.Lib;

/**
 * ...
 * @author Riddhi
 */

class MovingBGImg extends Sprite 
{
	private var myBG:Bitmap;
	
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
		myBG = new Bitmap (Assets.getBitmapData("assets/movingBG.png"));
		myBG.alpha = 1;
		
		myBG.x = (stage.stageWidth - myBG.width) / 2;
		myBG.y = (stage.stageHeight - myBG.height) / 2;
		
		addChild(myBG);
		
		// new to Haxe NME? please read *carefully* the readme.txt file!
	}
		
}
