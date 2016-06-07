package net.alcetech.ApplicationFramework;

public class Console {
	
	public static void write(String value) {
		System.out.print(value);
	}
	public static void writeLine(String value) {
		Console.write(value + "\n");
	}

}
