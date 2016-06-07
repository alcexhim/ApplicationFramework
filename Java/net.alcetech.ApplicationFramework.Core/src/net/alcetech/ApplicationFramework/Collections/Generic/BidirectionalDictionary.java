package net.alcetech.ApplicationFramework.Collections.Generic;

public class BidirectionalDictionary<T1, T2> {

	private Dictionary<T1, T2> _forwardDictionary = new Dictionary<T1, T2>();
	private Dictionary<T2, T1> _backwardDictionary = new Dictionary<T2, T1>();
	
	void add(T1 value1, T2 value2) {
		_forwardDictionary.add(value1, value2);
		_backwardDictionary.add(value2, value1);
	}
	boolean removeByValue1(T1 value1) {
		T2 value2 = _forwardDictionary.get(value1);
		_forwardDictionary.remove(value1);
		_backwardDictionary.remove(value2);
		return true;
	}
	boolean removeByValue2(T2 value2) {
		T1 value1 = _backwardDictionary.get(value2);
		_forwardDictionary.remove(value1);
		_backwardDictionary.remove(value2);
		return true;
	}

	T1 getValue1(T2 value2) {
		T1 value1 = _backwardDictionary.get(value2);
		return value1;
	}
	T2 getValue2(T1 value1) {
		T2 value2 = _forwardDictionary.get(value1);
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

}
