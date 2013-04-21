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
		nme.Lib.setPackage("Riddhi", "playJump", "com.velvetArts.v01.playJump", "1.0.0");
		
		#end
		
		#if waxe
		wx.App.boot(function()
		{
			
			frame = wx.Frame.create(null, null, "playJump", null, { width: 0, height: 0 });
			
			#if nme
			var stage = wx.NMEStage.create(frame, null, null, { width: 0, height: 0 });
			#end
			
			com.velvetArts.v01.Main.main();
			
			if (autoShowFrame)
			{
				wx.App.setTopWindow(frame);
				frame.shown = true;
			}
		});
		#else
		
		nme.Lib.create(function()
			{ 
				//if ((0 == 0 && 0 == 0) || true)
				//{
					nme.Lib.current.stage.align = nme.display.StageAlign.TOP_LEFT;
					nme.Lib.current.stage.scaleMode = nme.display.StageScaleMode.NO_SCALE;
				//}
				
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
					#if nme
					if (Std.is (instance, nme.display.DisplayObject)) {
						nme.Lib.current.addChild(cast instance);
					}
					#end
				}
			},
			0, 0, 
			60, 
			16777215,
			(true ? nme.Lib.HARDWARE : 0) |
			(false ? nme.Lib.ALLOW_SHADERS : 0) |
			(false ? nme.Lib.REQUIRE_SHADERS : 0) |
			(false ? nme.Lib.DEPTH_BUFFER : 0) |
			(false ? nme.Lib.STENCIL_BUFFER : 0) |
			(true ? nme.Lib.RESIZABLE : 0) |
			(false ? nme.Lib.BORDERLESS : 0) |
			(false ? nme.Lib.VSYNC : 0) |
			(true ? nme.Lib.FULLSCREEN : 0) |
			(0 == 4 ? nme.Lib.HW_AA_HIRES : 0) |
			(0 == 2 ? nme.Lib.HW_AA : 0),
			"playJump"
			
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
		
		if (inName == "img/baby.png")
		{
			
			return nme.Assets.getBitmapData ("img/baby.png");
			
		}
		
		if (inName == "img/movingBG.png")
		{
			
			return nme.Assets.getBitmapData ("img/movingBG.png");
			
		}
		
		#end
		return null;
	}
	
	
}
