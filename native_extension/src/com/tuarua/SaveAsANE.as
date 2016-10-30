package com.tuarua {
	import flash.events.EventDispatcher;
	import flash.external.ExtensionContext;
	public class SaveAsANE extends EventDispatcher {
		private var extensionContext:ExtensionContext;
		public function SaveAsANE() {
			initiate();
		}
		protected function initiate():void {
			trace("[SaveAsANE] Initalizing ANE...");
			try {
				extensionContext = ExtensionContext.createExtensionContext("com.tuarua.SaveAsANE", null);
			} catch (e:Error) {
				trace("[SaveAsANE] ANE Not loaded properly.  Future calls will fail.");
			}
		}
		public function saveAs(fileType:String=null,defaultPath:String=null):String {
			var ret:String = extensionContext.call("saveAs",fileType,defaultPath) as String;
			if(ret != "" && ret.lastIndexOf("."+fileType) == -1)
				ret = ret + "." + fileType;
			return ret;
		}
	}
}