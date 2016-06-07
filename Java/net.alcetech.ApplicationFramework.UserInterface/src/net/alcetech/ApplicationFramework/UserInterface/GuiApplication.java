package net.alcetech.ApplicationFramework.UserInterface;

import java.util.ArrayList;

import javax.swing.UIManager;
import javax.swing.UnsupportedLookAndFeelException;

import net.alcetech.ApplicationFramework.Application;

public class GuiApplication extends Application {
	
	public static void initialize(String[] args) {
		
		Application.initialize(args);
		
		try {
			UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
		} catch (ClassNotFoundException | InstantiationException | IllegalAccessException
				| UnsupportedLookAndFeelException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}
	
	static ArrayList<MainWindow> _MainWindows = new ArrayList<MainWindow>();
	public static MainWindow[] getMainWindows() {
		MainWindow[] array = new MainWindow[_MainWindows.size()];
		_MainWindows.toArray(array);
		return array;
	}
	
	private static MainWindow _CurrentMainWindow = null;
	public static MainWindow getCurrentMainWindow() { return GuiApplication._CurrentMainWindow; }
	static void setCurrentMainWindow(MainWindow value) { GuiApplication._CurrentMainWindow = value; }

}
