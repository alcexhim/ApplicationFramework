package net.alcetech.ApplicationFramework.Collections.Generic;

public class KeyValuePair<T1, T2> {
	
	private T1 _Key;
	public T1 getKey() { return _Key; }
	public void setKey(T1 key) { _Key = key; }
	
	private T2 _Value;
	public T2 getValue() { return _Value; }
	public void setValue(T2 value) { _Value = value; }
	
	public KeyValuePair(T1 key, T2 value) {
		_Key = key;
		_Value = value;
	}

}
