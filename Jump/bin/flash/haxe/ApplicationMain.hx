#if nme

import com.velvetArts.v01.Main;
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
		
		for (methodName in Type.getClassFields(com.velvetArts.v01.Main))
		{
			if (methodName == "main")
			{
				hasMain = true;
				break;
			}
		}
		
		if (hasMain)
		{
			Reflect.callMethod (com.velvetArts.v01.Main, Reflect.field (com.velvetArts.v01.Main, "main"), []);
		}
		else
		{
			var instance = Type.createInstance(com.velvetArts.v01.Main, []);
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
		
		
		if (inName=="img/baby.png")
			 
            return Assets.getBitmapData ("img/baby.png");
         
		
		if (inName=="img/candy.png")
			 
            return Assets.getBitmapData ("img/candy.png");
         
		
		if (inName=="img/clouds1.png")
			 
            return Assets.getBitmapData ("img/clouds1.png");
         
		
		if (inName=="img/clouds2.png")
			 
            return Assets.getBitmapData ("img/clouds2.png");
         
		
		if (inName=="img/clouds3.png")
			 
            return Assets.getBitmapData ("img/clouds3.png");
         
		
		if (inName=="img/movingBG.png")
			 
            return Assets.getBitmapData ("img/movingBG.png");
         
		
		
		return null;
		
	}
	
	
	private static function preloader_onComplete (event:Event):Void {
		
		mPreloader.removeEventListener (Event.COMPLETE, preloader_onComplete);
		
		nme.Lib.current.removeChild(mPreloader);
		mPreloader = null;
		
		begin ();
		
	}
	
}

class NME_img_baby_png extends nme.display.BitmapData { public function new () { super (0, 0); } }
class NME_img_candy_png extends nme.display.BitmapData { public function new () { super (0, 0); } }
class NME_img_clouds1_png extends nme.display.BitmapData { public function new () { super (0, 0); } }
class NME_img_clouds2_png extends nme.display.BitmapData { public function new () { super (0, 0); } }
class NME_img_clouds3_png extends nme.display.BitmapData { public function new () { super (0, 0); } }
class NME_img_movingbg_png extends nme.display.BitmapData { public function new () { super (0, 0); } }


#else

import com.velvetArts.v01.Main;

class ApplicationMain {
	
	public static function main () {
		
		var hasMain = false;
		
		for (methodName in Type.getClassFields(com.velvetArts.v01.Main))
		{
			if (methodName == "main")
			{
				hasMain = true;
				break;
			}
		}
		
		if (hasMain)
		{
			Reflect.callMethod (com.velvetArts.v01.Main, Reflect.field (com.velvetArts.v01.Main, "main"), []);
		}
		else
		{
			var instance = Type.createInstance(com.velvetArts.v01.Main, []);
			if (Std.is (instance, flash.display.DisplayObject)) {
				flash.Lib.current.addChild(cast instance);
			}
		}
		
	}

}

#end
