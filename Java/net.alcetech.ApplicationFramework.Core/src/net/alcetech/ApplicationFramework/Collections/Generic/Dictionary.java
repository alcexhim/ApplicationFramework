package net.alcetech.ApplicationFramework.Collections.Generic;

public class Dictionary<T1, T2> {
	
	private List<T1> _keys = new List<T1>();
	private List<T2> _values = new List<T2>();
	
	public void add(T1 key, T2 value) {
		_keys.add(key);
		_values.add(value);
	}
	
	public void set(T1 key, T2 value) {
		boolean found = false;
		for (int i = 0; i < _keys.count(); i++)
		{
			if (_keys.get(i).equals(key))
			{
				_values.set(i, value);
				found = true;
				break;
			}
		}
		if (!found) add(key, value);
	}
	public T2 get(T1 key) {
		for (int i = 0; i < _keys.count(); i++)
		{
			if (_keys.get(i).equals(key)) return _values.get(i);
		}
		return null;
	}
	public boolean remove(T1 key) {
		boolean found = false;
		for (int i = 0; i < _keys.count(); i++) {
			if (_keys.get(i) == key) {
				_values.remove(i);
				found = true;
				break;
			}
		}
		if (found) _keys.remove(key);
		return found;
	}
	
	public int count() {
		return _keys.count();
	}

	public boolean containsKey(T1 key) {
		return _keys.contains(key);
	}
	public boolean containsValue(T2 value) {
		return _values.contains(value);
	}

	public T2 getByIndex(int index) {
		return _values.get(index);
	}
}
