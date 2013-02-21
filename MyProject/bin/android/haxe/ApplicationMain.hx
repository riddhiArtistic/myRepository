class ApplicationMain
{

	#if waxe
	static public var frame : wx.Frame;
	static public var autoShowFrame : Bool = true;
	#if nme
	static public var nmeStage : wx.NMEStage;
	#end
	#end
	
	public static function main()
	{
		#if nme
		nme.Lib.setPackage("Riddhi", "MyProject", "com.velVetArts.MyProject", "1.0.0");
		
		#end
		
		#if waxe
		wx.App.boot(function()
		{
			
			frame = wx.Frame.create(null, null, "MyProject", null, { width: 640, height: 480 });
			
			#if nme
			var stage = wx.NMEStage.create(frame, null, null, { width: 640, height: 480 });
			#end
			
			Jump.main();
			
			if (autoShowFrame)
			{
				wx.App.setTopWindow(frame);
				frame.shown = true;
			}
		});
		#else
		
		nme.Lib.create(function()
			{ 
				//if ((640 == 0 && 480 == 0) || true)
				//{
					nme.Lib.current.stage.align = nme.display.StageAlign.TOP_LEFT;
					nme.Lib.current.stage.scaleMode = nme.display.StageScaleMode.NO_SCALE;
				//}
				
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
					#if nme
					if (Std.is (instance, nme.display.DisplayObject)) {
						nme.Lib.current.addChild(cast instance);
					}
					#end
				}
			},
			640, 480, 
			60, 
			10092492,
			(true ? nme.Lib.HARDWARE : 0) |
			(false ? nme.Lib.ALLOW_SHADERS : 0) |
			(false ? nme.Lib.REQUIRE_SHADERS : 0) |
			(false ? nme.Lib.DEPTH_BUFFER : 0) |
			(false ? nme.Lib.STENCIL_BUFFER : 0) |
			(false ? nme.Lib.RESIZABLE : 0) |
			(false ? nme.Lib.BORDERLESS : 0) |
			(false ? nme.Lib.VSYNC : 0) |
			(true ? nme.Lib.FULLSCREEN : 0) |
			(0 == 4 ? nme.Lib.HW_AA_HIRES : 0) |
			(0 == 2 ? nme.Lib.HW_AA : 0),
			"MyProject"
			
		);
		#end
		
	}
	
	
	#if neko
	public static function __init__ () {
		
		untyped $loader.path = $array ("@executable_path/", $loader.path);
		
	}
	#end
	
	
	public static function getAsset(inName:String):Dynamic
	{
		#if nme
		
		if (inName == "assets/baby.png")
		{
			
			return nme.Assets.getBitmapData ("assets/baby.png");
			
		}
		
		if (inName == "assets/babyCry.png")
		{
			
			return nme.Assets.getBitmapData ("assets/babyCry.png");
			
		}
		
		if (inName == "assets/babyDance.png")
		{
			
			return nme.Assets.getBitmapData ("assets/babyDance.png");
			
		}
		
		if (inName == "assets/babyIdea.png")
		{
			
			return nme.Assets.getBitmapData ("assets/babyIdea.png");
			
		}
		
		if (inName == "assets/babyWonder.png")
		{
			
			return nme.Assets.getBitmapData ("assets/babyWonder.png");
			
		}
		
		if (inName == "assets/BackGround.png")
		{
			
			return nme.Assets.getBitmapData ("assets/BackGround.png");
			
		}
		
		if (inName == "assets/movingBG.png")
		{
			
			return nme.Assets.getBitmapData ("assets/movingBG.png");
			
		}
		
		if (inName == "assets/movingBG32.png")
		{
			
			return nme.Assets.getBitmapData ("assets/movingBG32.png");
			
		}
		
		#end
		return null;
	}
	
	
}
