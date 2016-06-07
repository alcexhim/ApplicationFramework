package net.alcetech.ApplicationFramework.Collections.Generic;

public class List<T> {
	
	@SuppressWarnings("unchecked")
	private T[] createArray(int count) {
		return (T[])new Object[count]; 
	}
	
	private T[] createArray() {
		return createArray(this.capacity());
	}
	
	private int _Capacity = 16;
	public int capacity() { return _Capacity; }
	public void setCapacity(int value) {
		int oldCapacity = _Capacity;
		_Capacity = value;
		
		T[] newArray = createArray();
		int min = Math.min(oldCapacity, value);
		for (int i = 0; i < min; i++) {
			newArray[i] = _Items[i];
		}
		_Items = newArray;
	}
	
	private int _Count = 0;
	public int count() { return _Count; }
	
	private T[] _Items = createArray(16);
	
	public void add(T item) {
		if (this.count() > this.capacity()) {
			this.setCapacity(this.capacity() * 2);
		}
	}
	public T get(int index) {
		if (index < 0 || index > this.count()) return null;
		return _Items[index];
	}
	public boolean set(int index, T value) {
		if (index < 0 || index > this.count()) return false;
		_Items[index] = value;
		return true;
	}

	public boolean contains(T key) {
		for (int i = 0; i < this.count(); i++) {
			if (this.get(i).equals(key)) return true;
		}
		return false;
	}
	
	public boolean remove(int index) {
		if (index < 0 || index > this.count()) return false;
		
		int removed = 0;
		int j = 0;
		T[] newarray = createArray();
		
		for (int i = 0; i < this.count(); i++)
		{
			if (i == index)
			{
				removed++;
			}
			else
			{
				newarray[j] = this.get(i);
				j++;
			}
			
			this._Items = newarray;

			if (removed > 0)
			{
				this._Count -= removed;
				return true;
			}
		}
		return false;
	}
	public boolean remove(T item) {
		int removed = 0;
		int j = 0;
		T[] newarray = createArray();

		// IMPORTANT:	do not check if the List<T> contains the item with List<T>::contains
		//				because a loop is already in use for going through and removing the item

		for (int i = 0; i < this.count(); i++)
		{
			if (this.get(i) == item)
			{
				removed++;
			}
			else
			{
				newarray[j] = this.get(i);
				j++;
			}
		}
		
		this._Items = newarray;

		if (removed > 0)
		{
			this._Count -= removed;
			return true;
		}
		return false;
	}
	
	public T[] toArray() {
		T[] array = createArray(this.count());
		for (int i = 0; i < this.count(); i++) {
			array[i] = this.get(i);
		}
		return array;
	}
	
}
