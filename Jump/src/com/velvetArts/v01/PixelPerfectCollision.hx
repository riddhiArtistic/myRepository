package com.velvetArts.v01;
import nme.display.BitmapData;
import nme.display.BitmapDataChannel;
import nme.display.BlendMode;
import nme.display.DisplayObject;
import nme.display.DisplayObjectContainer;
import nme.geom.Matrix;
import nme.geom.Point;
import nme.geom.Rectangle;

/**
 * ...
 * @author Riddhi
 */

class PixelPerfectCollision 
{

	public function new() 
	{
		// Empty 
	}
	
	public static function IsColliding(target1:DisplayObject, target2:DisplayObject, uniqueParent:DisplayObjectContainer, pixelPerfect:Bool = false, tolerance:Float = 0):Bool
	{
		var collisionRect:Rectangle = getCollisionArea(target1, target2, uniqueParent, pixelPerfect, tolerance);
		if (collisionRect != null && collisionRect.size.length > 0) 
		    return true;
		else 
		    return false;
	}
	
	public static function getCollisionArea(target1:DisplayObject, target2:DisplayObject, uniqueParent: DisplayObjectContainer, pixelPerfect:Bool = false, tolerance:Float = 0):Rectangle
	{
		var rect1:Rectangle = getBoundRect(target1);
		var rect2:Rectangle = getBoundRect(target2);
		
		var intersectionArea:Rectangle = rect1.intersection(rect2);
		
		if (intersectionArea.size.length > 0)
		{
			if (pixelPerfect)
			{
				intersectionArea.width = Math.ceil(intersectionArea.width);
				intersectionArea.height = Math.ceil(intersectionArea.height);
				
			    var alpha1:BitmapData = getAlphaMap(target1, intersectionArea, BitmapDataChannel.RED, uniqueParent);
				var alpha2:BitmapData = getAlphaMap(target2, intersectionArea, BitmapDataChannel.GREEN, uniqueParent);
				
				#if flash
				alpha1.draw(alpha2, null, null, BlendMode.LIGHTEN);
				#else
				alpha1.draw(alpha2, null, null, BlendMode.LIGHTEN);
				#end
				
				var searchColor:Int;
				if (tolerance <= 0)
					searchColor = 0x010100;
				else
				{
					if (tolerance> 1) tolerance = 1;
					var byte:Int = Math.round(tolerance * 255);
					searchColor = (byte <<16) | (byte <<8) | 0;
				}
				
				var collisionRect:Rectangle = alpha1.getColorBoundsRect(searchColor, searchColor);
				collisionRect.x += intersectionArea.x;
				collisionRect.y += intersectionArea.y;
				return collisionRect;
			}
			else
			{
				return intersectionArea;
			}
		}
		else
		{
			return null;
		}
	}
	
	public static function getCollisionPoint(target1:DisplayObject, target2:DisplayObject, uniqueParent:DisplayObjectContainer, pixelPerfect:Bool = false, tolerance:Float = 0):Point
	{
		var collisionRect:Rectangle = getCollisionArea(target1, target2, uniqueParent, pixelPerfect, tolerance);
		
		if (collisionRect != null && collisionRect.size.length> 0)
		{
			var x:Float = (collisionRect.left + collisionRect.right) / 2;
			var y:Float = (collisionRect.top + collisionRect.bottom) / 2;
			return new Point(x, y);
		}
		
		return null;
	}
	
	private static function getAlphaMap(target:DisplayObject, rect:Rectangle, channel:Int, commonParent:DisplayObjectContainer):BitmapData
	{
		// calculate the transform for the display object relative to the common parent
		var parentXformInvert:Matrix = commonParent.transform.concatenatedMatrix.clone();
		parentXformInvert.invert();
		var targetXform:Matrix = target.transform.concatenatedMatrix.clone();
		targetXform.concat(parentXformInvert);
		// translate the target into the rect's space
		targetXform.translate(-rect.x, -rect.y);
		// draw the target and extract its alpha channel into a color channel
		var bitmapData:BitmapData = new BitmapData(cast(rect.width), cast(rect.height), true, 0);
		bitmapData.draw(target, targetXform);
		var alphaChannel:BitmapData = new BitmapData(cast(rect.width), cast(rect.height), false, 0);
		alphaChannel.copyChannel(bitmapData, bitmapData.rect, new Point(0, 0), BitmapDataChannel.ALPHA, channel);
		return alphaChannel;
	}
	
	public static function getBoundRect(object:DisplayObject):Rectangle
	{
		var rotation = object.rotation;
		
		if (rotation < 0) 
			rotation = 360 + rotation;
			
		var position = new Point(object.x, object.y);
		
		if ((rotation > 0) && (rotation < 360)) 
		{
			if (rotation < 90) 
			{
				position.x -= object.height * Math.sin(rotation);
			}
			
			else if (rotation == 90) 
			{
				position.x -= object.width;
			}
			
			else if (rotation < 180) 
			{
				position.x -= object.width;
				position.y -= object.width * Math.sin(rotation);
			}
			
			else if (rotation == 180) 
			{
				position.x -= object.width;
				position.y -= object.height;
			}
			
			else if (rotation < 270) 
			{
				position.x -= object.height * Math.sin(rotation);
				position.y -= object.height;
			}
			
			else if (rotation == 270) 
			{
				position.y -= object.height;
			}
			
			else 
			{
				position.y -= object.width * Math.sin(rotation);
			}
			
		}
		
		return (new Rectangle(position.x, position.y, object.width, object.height));
	}
}