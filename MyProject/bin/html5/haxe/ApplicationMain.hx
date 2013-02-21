#if (nme && !flambe)


import Jump;
import nme.display.Bitmap;
import nme.display.Loader;
import nme.events.Event;
import nme.media.Sound;
import nme.net.URLLoader;
import nme.net.URLRequest;
import nme.net.URLLoaderDataFormat;
import nme.Assets;
import nme.Lib;


class ApplicationMain {
	
	
	private static var completed:Int;
	private static var preloader:NMEPreloader;
	private static var total:Int;
	
	public static var loaders:Hash <Loader>;
	public static var urlLoaders:Hash <URLLoader>;
	
	
	public static function main () {
		
		completed = 0;
		loaders = new Hash <Loader> ();
		urlLoaders = new Hash <URLLoader> ();
		total = 0;
		
		
		
		
		preloader = new NMEPreloader ();
		
		Lib.current.addChild (preloader);
		preloader.onInit ();
		
		
		
		var loader:Loader = new Loader ();
		loaders.set ("assets/baby.png", loader);
		total ++;
		
		
		var loader:Loader = new Loader ();
		loaders.set ("assets/babyCry.png", loader);
		total ++;
		
		
		var loader:Loader = new Loader ();
		loaders.set ("assets/babyDance.png", loader);
		total ++;
		
		
		var loader:Loader = new Loader ();
		loaders.set ("assets/babyIdea.png", loader);
		total ++;
		
		
		var loader:Loader = new Loader ();
		loaders.set ("assets/babyWonder.png", loader);
		total ++;
		
		
		var loader:Loader = new Loader ();
		loaders.set ("assets/BackGround.png", loader);
		total ++;
		
		
		var loader:Loader = new Loader ();
		loaders.set ("assets/movingBG.png", loader);
		total ++;
		
		
		var loader:Loader = new Loader ();
		loaders.set ("assets/movingBG32.png", loader);
		total ++;
		
		
		if (total == 0) {
			
			begin ();
			
		} else {
			
			for (path in loaders.keys ()) {
				
				var loader:Loader = loaders.get (path);
				loader.contentLoaderInfo.addEventListener ("complete", loader_onComplete);
				loader.load (new URLRequest (path));
				
			}
			
			for (path in urlLoaders.keys ()) {
				
				var urlLoader:URLLoader = urlLoaders.get (path);
				urlLoader.addEventListener ("complete", loader_onComplete);
				urlLoader.load (new URLRequest (path));
				
			}
			
		}
		
	}
	
	
	private static function begin ():Void {
		
		preloader.addEventListener (Event.COMPLETE, preloader_onComplete);
		preloader.onLoaded ();
		
	}
	

   public static function getAsset(inName:String):Dynamic {
	   
		
		if (inName=="assets/baby.png") {
			
			return Assets.getBitmapData ("assets/baby.png");
			
		}
		
		if (inName=="assets/babyCry.png") {
			
			return Assets.getBitmapData ("assets/babyCry.png");
			
		}
		
		if (inName=="assets/babyDance.png") {
			
			return Assets.getBitmapData ("assets/babyDance.png");
			
		}
		
		if (inName=="assets/babyIdea.png") {
			
			return Assets.getBitmapData ("assets/babyIdea.png");
			
		}
		
		if (inName=="assets/babyWonder.png") {
			
			return Assets.getBitmapData ("assets/babyWonder.png");
			
		}
		
		if (inName=="assets/BackGround.png") {
			
			return Assets.getBitmapData ("assets/BackGround.png");
			
		}
		
		if (inName=="assets/movingBG.png") {
			
			return Assets.getBitmapData ("assets/movingBG.png");
			
		}
		
		if (inName=="assets/movingBG32.png") {
			
			return Assets.getBitmapData ("assets/movingBG32.png");
			
		}
		
		return null;
		
   }
   
   
   
   
   // Event Handlers
   
   
   
   
	private static function loader_onComplete (event:Event):Void {
		
		completed ++;
		
		preloader.onUpdate (completed, total);
		
		if (completed == total) {
			
			begin ();
			
		}
	   
	}
	
	
	private static function preloader_onComplete (event:Event):Void {
		
		preloader.removeEventListener (Event.COMPLETE, preloader_onComplete);
		
		Lib.current.removeChild(preloader);
		preloader = null;
		
		if (Reflect.field(Jump, "main") == null)
		{
			var mainDisplayObj = new Jump();
			if (Std.is(mainDisplayObj, browser.display.DisplayObject))
				nme.Lib.current.addChild(cast mainDisplayObj);
		}
		else
		{
			Reflect.callMethod (Jump, Reflect.field (Jump, "main"), []);
		}
		
	}
   
   
}



	

	

	

	

	

	

	

	



#else


import Jump;


class ApplicationMain {
	
	
	public static function main () {
		
		if (Reflect.field(Jump, "main") == null) {
			
			Type.createInstance (Jump, []);
			
		} else {
			
			Reflect.callMethod (Jump, Reflect.field (Jump, "main"), []);
			
		}
		
	}
	
	
}


#end