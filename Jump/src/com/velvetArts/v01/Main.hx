package com.velvetArts.v01;

import nme.display.Sprite;
import nme.events.Event;
import nme.Lib;

/**
 * ...
 * @author Riddhi
 */

class Main extends Sprite 
{
	private var bgImg: MovingBG;
	private var Actor: Character;
	
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
		bgImg = new MovingBG();
		Actor = new Character();
		
		addChild(bgImg);
		addChild(Actor);
		// new to Haxe NME? please read *carefully* the readme.txt file!
	}
	
	static public function main() 
	{
		var stage = Lib.current.stage;
		stage.scaleMode = nme.display.StageScaleMode.NO_SCALE;
		stage.align = nme.display.StageAlign.TOP_LEFT;
		
		Lib.current.addChild(new Main());
	}
	
}
