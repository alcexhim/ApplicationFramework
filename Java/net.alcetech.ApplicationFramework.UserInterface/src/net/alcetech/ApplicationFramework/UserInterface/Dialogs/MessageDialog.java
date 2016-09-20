package net.alcetech.ApplicationFramework.UserInterface.Dialogs;

import java.awt.Window;

import net.alcetech.ApplicationFramework.UserInterface.*;

public class MessageDialog extends Dialog {
	
	/**
	 * 
	 */
	private static final long serialVersionUID = 4896861194511981677L;

	public static DialogResult ShowDialog(Window parent, String content, String title)
	{
		return ShowDialog(parent, content, title, StockButtonType.OK);
	}
	public static DialogResult ShowDialog(Window parent, String content, String title, StockButtonType buttons)
	{
		return DialogResult.NONE;
	}
	
}
