#if nme

import Jump;
import nme.Assets;
import nme.events.Event;


class ApplicationMain {
	
	static var mPreloader:NMEPreloader;

	public static function main () {
		
		var call_real = true;
		
		
		var loaded:Int = nme.Lib.current.loaderInfo.bytesLoaded;
		var total:Int = nme.Lib.current.loaderInfo.bytesTotal;
		
		nme.Lib.current.stage.align = nme.display.StageAlign.TOP_LEFT;
		nme.Lib.current.stage.scaleMode = nme.display.StageScaleMode.NO_SCALE;
		
		if (loaded < total || true) /* Always wait for event */ {
			
			call_real = false;
			mPreloader = new NMEPreloader();
			nme.Lib.current.addChild(mPreloader);
			mPreloader.onInit();
			mPreloader.onUpdate(loaded,total);
			nme.Lib.current.addEventListener (nme.events.Event.ENTER_FRAME, onEnter);
			
		}
		
		
		#if !fdb
		haxe.Log.trace = flashTrace;
		#end
		
		if (call_real)
			begin ();
	}

	#if !fdb
	private static function flashTrace( v : Dynamic, ?pos : haxe.PosInfos ) {
		var className = pos.className.substr(pos.className.lastIndexOf('.') + 1);
		var message = className+"::"+pos.methodName+":"+pos.lineNumber+": " + v;
		
        if (flash.external.ExternalInterface.available)
			flash.external.ExternalInterface.call("console.log", message);
		else untyped flash.Boot.__trace(v, pos);
    }
	#end
	
	private static function begin () {
		
		var hasMain = false;
		
		for (methodName in Type.getClassFields(Jump))
		{
			if (methodName == "main")
			{
				hasMain = true;
				break;
			}
		}
		
		if (hasMain)
		{
			Reflect.callMethod (Jump, Reflect.field (Jump, "main"), []);
		}
		else
		{
			var instance = Type.createInstance(Jump, []);
			if (Std.is (instance, nme.display.DisplayObject)) {
				nme.Lib.current.addChild(cast instance);
			}	
		}
		
	}

	static function onEnter (_) {
		
		var loaded = nme.Lib.current.loaderInfo.bytesLoaded;
		var total = nme.Lib.current.loaderInfo.bytesTotal;
		mPreloader.onUpdate(loaded,total);
		
		if (loaded >= total) {
			
			nme.Lib.current.removeEventListener(nme.events.Event.ENTER_FRAME, onEnter);
			mPreloader.addEventListener (Event.COMPLETE, preloader_onComplete);
			mPreloader.onLoaded();
			
		}
		
	}

	public static function getAsset (inName:String):Dynamic {
		
		
		if (inName=="assets/baby.png")
			 
            return Assets.getBitmapData ("assets/baby.png");
         
		
		if (inName=="assets/babyCry.png")
			 
            return Assets.getBitmapData ("assets/babyCry.png");
         
		
		if (inName=="assets/babyDance.png")
			 
            return Assets.getBitmapData ("assets/babyDance.png");
         
		
		if (inName=="assets/babyIdea.png")
			 
            return Assets.getBitmapData ("assets/babyIdea.png");
         
		
		if (inName=="assets/babyWonder.png")
			 
            return Assets.getBitmapData ("assets/babyWonder.png");
         
		
		if (inName=="assets/BackGround.png")
			 
            return Assets.getBitmapData ("assets/BackGround.png");
         
		
		if (inName=="assets/movingBG.png")
			 
            return Assets.getBitmapData ("assets/movingBG.png");
         
		
		if (inName=="assets/movingBG32.png")
			 
            return Assets.getBitmapData ("assets/movingBG32.png");
         
		
		
		return null;
		
	}
	
	
	private static function preloader_onComplete (event:Event):Void {
		
		mPreloader.removeEventListener (Event.COMPLETE, preloader_onComplete);
		
		nme.Lib.current.removeChild(mPreloader);
		mPreloader = null;
		
		begin ();
		
	}
	
}

class NME_assets_baby_png extends nme.display.BitmapData { public function new () { super (0, 0); } }
class NME_assets_babycry_png extends nme.display.BitmapData { public function new () { super (0, 0); } }
class NME_assets_babydance_png extends nme.display.BitmapData { public function new () { super (0, 0); } }
class NME_assets_babyidea_png extends nme.display.BitmapData { public function new () { super (0, 0); } }
class NME_assets_babywonder_png extends nme.display.BitmapData { public function new () { super (0, 0); } }
class NME_assets_background_png extends nme.display.BitmapData { public function new () { super (0, 0); } }
class NME_assets_movingbg_png extends nme.display.BitmapData { public function new () { super (0, 0); } }
class NME_assets_movingbg32_png extends nme.display.BitmapData { public function new () { super (0, 0); } }


#else

import Jump;

class ApplicationMain {
	
	public static function main () {
		
		var hasMain = false;
		
		for (methodName in Type.getClassFields(Jump))
		{
			if (methodName == "main")
			{
				hasMain = true;
				break;
			}
		}
		
		if (hasMain)
		{
			Reflect.callMethod (Jump, Reflect.field (Jump, "main"), []);
		}
		else
		{
			var instance = Type.createInstance(Jump, []);
			if (Std.is (instance, flash.display.DisplayObject)) {
				flash.Lib.current.addChild(cast instance);
			}
		}
		
	}

}

#end
