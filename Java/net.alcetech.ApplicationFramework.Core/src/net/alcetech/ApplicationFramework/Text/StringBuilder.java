package net.alcetech.ApplicationFramework.Text;

public class StringBuilder {
	
	private java.lang.StringBuilder _underlyingStringBuilder = new java.lang.StringBuilder();

	public void appendLine(String value) {
		_underlyingStringBuilder.append(value);
		_underlyingStringBuilder.append(System.lineSeparator());
	}
	public void append(String value) {
		_underlyingStringBuilder.append(value);
	}
	public void append(char value) {
		_underlyingStringBuilder.append(value);
	}
	
	public void clear() {
		_underlyingStringBuilder = new java.lang.StringBuilder();
	}
	public int length() {
		return _underlyingStringBuilder.length();
	}
	public boolean isEmpty() {
		return this.length() == 0;
	}
	public void set(String value) {
		_underlyingStringBuilder = new java.lang.StringBuilder();
		_underlyingStringBuilder.append(value);
	}
	
}
