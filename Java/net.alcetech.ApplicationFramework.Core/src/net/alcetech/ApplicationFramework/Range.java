package net.alcetech.ApplicationFramework;

public class Range {
	
	private double _MinimumValue = 0.0;
	public double getMinimumValue() {
		return _MinimumValue;
	}
	public void setMinimumValue(double value) {
		_MinimumValue = value;
	}
	
	private double _MaximumValue = Double.MAX_VALUE;
	public double getMaximumValue() {
		return _MaximumValue;
	}
	public void setMaximumValue(double value) {
		_MaximumValue = value;
	}
	
	public Range() {
		
	}
	public Range(double minimumValue, double maximumValue) {
		this.setMinimumValue(minimumValue);
		this.setMaximumValue(maximumValue);
	}

}
