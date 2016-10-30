package {
	import com.tuarua.SaveAsANE;
	
	import flash.display.Sprite;
	import flash.events.MouseEvent;
	
	public class SaveAsANEExample extends Sprite {
		private var btn:Sprite = new Sprite();
		private var saveAsANE:SaveAsANE = new SaveAsANE();
		public function SaveAsANEExample() {
			btn.graphics.beginFill(0x000000);
			btn.graphics.drawRect(50,50,100,100);
			btn.graphics.endFill();
			btn.addEventListener(MouseEvent.CLICK,onClick);
			addChild(btn);
		}
		
		protected function onClick(event:MouseEvent):void {
			var fileName:String = saveAsANE.saveAs("mp4");
			trace("fileName chosen",fileName);
		}
	}
}