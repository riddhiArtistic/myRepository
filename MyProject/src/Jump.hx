package ;

import nme.display.Bitmap;
import nme.display.BitmapData;
import nme.geom.Rectangle;
import nme.display.Sprite;

import nme.events.Event;
import nme.events.KeyboardEvent;
import nme.ui.Keyboard;

import nme.Assets;
import nme.Lib;


/**
 * ...
 * @author Riddhi
 */

class Jump extends Sprite 
{
	private var myBGImg:BackGroundImg;
	private var movingBG:MovingBGImg;
	private var myCharacter:Character;
	
	private var scrollIndex:Int;
		
	private var moveFWD: Bool;
	private var jumpFlg: Bool;
	
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
        myBGImg = new BackGroundImg();
		movingBG = new MovingBGImg();
		myCharacter = new Character();
		
		addChild(myBGImg);
		
		scrollIndex = 0;
		addEventListener(Event.ENTER_FRAME, renderScrollingBG);
		
		addChild(movingBG);
		addChild(myCharacter);
		// new to Haxe NME? please read *carefully* the readme.txt file!
	}
	
	public function renderScrollingBG(event:Event):Void
	{
		movingBG.scrollRect = new Rectangle(scrollIndex, 0, 640 + scrollIndex, 480);
		
		if (scrollIndex > 640)
		{
			scrollIndex = 0;
		} else {
			scrollIndex++;
		}
		
	}	
	
	static public function main() 
	{
		var stage = Lib.current.stage;
		
		stage.scaleMode = nme.display.StageScaleMode.NO_SCALE;
		stage.align = nme.display.StageAlign.TOP_LEFT;
		
		Lib.current.addChild(new Jump());
	}
}
