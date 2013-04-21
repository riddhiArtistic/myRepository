package com.velvetArts.v01;

import nme.Assets;
import nme.display.Bitmap;
import nme.display.Sprite;
import nme.display.Tilesheet;
import nme.events.Event;
import nme.Lib;

/**
 * ...
 * @author Riddhi
 */

class Main extends Sprite 
{
	var game:Game;
	var tilesheet:Tilesheet;
	
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
		
		tilesheet = new Tilesheet(Assets.getBitmapData("img/nTILES.png"));
		game = new Game(tilesheet);
		
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
