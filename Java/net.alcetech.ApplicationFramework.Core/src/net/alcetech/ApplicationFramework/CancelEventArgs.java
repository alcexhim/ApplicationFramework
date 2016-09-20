package net.alcetech.ApplicationFramework;

public class CancelEventArgs extends EventArgs {
	
	private boolean _canceled = false;
	public boolean isCanceled() {
		return _canceled;
	}
	
	public void cancel() {
		_canceled = true;
	}

}
