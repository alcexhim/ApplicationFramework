package net.alcetech.ApplicationFramework.Collections.Generic;

public class BidirectionalDictionary<T1, T2> {

	private Dictionary<T1, T2> _forwardDictionary = new Dictionary<T1, T2>();
	private Dictionary<T2, T1> _backwardDictionary = new Dictionary<T2, T1>();
	
	public void add(T1 value1, T2 value2) {
		_forwardDictionary.add(value1, value2);
		_backwardDictionary.add(value2, value1);
	}
	public boolean removeByValue1(T1 value1) {
		T2 value2 = _forwardDictionary.get(value1);
		_forwardDictionary.remove(value1);
		_backwardDictionary.remove(value2);
		return true;
	}
	public boolean removeByValue2(T2 value2) {
		T1 value1 = _backwardDictionary.get(value2);
		_forwardDictionary.remove(value1);
		_backwardDictionary.remove(value2);
		return true;
	}

	public T1 getValue1(T2 value2) {
		T1 value1 = _backwardDictionary.get(value2);
		return value1;
	}
	public T2 getValue2(T1 value1) {
		T2 value2 = _forwardDictionary.get(value1);
		return value2;
	}

	public T1 getValue1ByIndex(int index) {
		T1 value1 = _backwardDictionary.getByIndex(index);
		return value1;
	}
	public T2 getValue2ByIndex(int index) {
		T2 value2 = _forwardDictionary.getByIndex(index);
		return value2;
	}
	
	public int size() {

		if (_forwardDictionary.count() != _backwardDictionary.count())
		{
			// this should never happen
			// throw new InvalidOperationException("Count mismatch");
			return 0;
		}

		// they should be equal, so choose one at random to return and hardcode it ;)
		return _backwardDictionary.count();
		
	}
	
	public KeyValuePair<T1, T2>[] toArray() {
		KeyValuePair<T1, T2>[] items = new KeyValuePair[this.size()];
		for (int i = 0; i < this.size(); i++) {
			items[i] = new KeyValuePair<T1, T2>(this.getValue1ByIndex(i), this.getValue2ByIndex(i));
		}
		return items;
	}
	
}
