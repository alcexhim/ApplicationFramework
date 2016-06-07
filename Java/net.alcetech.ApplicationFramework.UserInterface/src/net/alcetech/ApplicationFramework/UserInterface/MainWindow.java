package net.alcetech.ApplicationFramework.UserInterface;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;
import java.util.HashMap;

import javax.swing.*;

import net.alcetech.ApplicationFramework.Application;
import net.alcetech.ApplicationFramework.Command;
import net.alcetech.ApplicationFramework.CommandItem;
import net.alcetech.ApplicationFramework.CommandItems.*;

public class MainWindow extends JFrame implements ActionListener, WindowListener {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1192968564347709403L;
	
	public MainWindow() {
		this.initializeComponent();
		this.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		this.setTitle(GuiApplication.getTitle());
		
		GuiApplication._MainWindows.add(this);
	}
	
	private JComponent initializeMenuItemForCommandItem(CommandItem item) {
		if (item.getClass() == CommandReferenceCommandItem.class) {
			CommandReferenceCommandItem crci = (CommandReferenceCommandItem)item;
			String commandID = crci.getCommandID();
			
			Command cmd = Application.getCommand(commandID);
			if (cmd != null) {
				
				CommandItem[] childItems = cmd.getItems();

				String title = cmd.getTitle();
				int mnemonicIndex = title.indexOf("_");
				if (mnemonicIndex > -1) {
					String before = title.substring(0, mnemonicIndex);
					String after = title.substring(mnemonicIndex + 1);
					title = before + after;
				}
				
				JMenuItem menuItem = null;
				
				if (childItems.length > 0) {
					menuItem = new JMenu();
					for (int i = 0; i < childItems.length; i++) {
						JComponent childItemComponent = initializeMenuItemForCommandItem(childItems[i]);
						menuItem.add(childItemComponent);
					}
				}
				else {
					menuItem = new JMenuItem();
				}
				
				menuItem.addActionListener(this);
				menuItem.setText(title);
				menuItem.setMnemonic(title.charAt(mnemonicIndex));
				menuItem.setDisplayedMnemonicIndex(mnemonicIndex);
				commandsForJMenuItem.put(menuItem, cmd);
				return menuItem;
			}
		}
		else if (item.getClass() == SeparatorCommandItem.class) {
			return new JSeparator();
		}
		return null;
	}
	
	private HashMap<JMenuItem, Command> commandsForJMenuItem = new HashMap<JMenuItem, Command>(); 
	
	private void initializeComponent() {
		
		JMenuBar menuBar = new JMenuBar();
		this.setJMenuBar(menuBar);
		
		CommandItem[] mainMenuCommandItems = GuiApplication.getMainMenuCommandItems();
		for (int i = 0; i < mainMenuCommandItems.length; i++) {
			JComponent menuItem = initializeMenuItemForCommandItem(mainMenuCommandItems[i]);
			if (menuItem != null) menuBar.add(menuItem);
		}
		
		this.addWindowListener(this);
		
	}

	@Override
	public void windowOpened(WindowEvent e) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void windowClosing(WindowEvent e) {
		// TODO Auto-generated method stub
	}

	@Override
	public void windowClosed(WindowEvent e) {
		// TODO Auto-generated method stub
		GuiApplication._MainWindows.remove(this);
		
		if (GuiApplication.getMainWindows().length == 0)
		{
			GuiApplication.stop();
		}
	}

	@Override
	public void windowIconified(WindowEvent e) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void windowDeiconified(WindowEvent e) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void windowActivated(WindowEvent e) {
		GuiApplication.setCurrentMainWindow(this);
	}

	@Override
	public void windowDeactivated(WindowEvent e) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		if (e.getSource().getClass() == JMenuItem.class) {
			JMenuItem menuItem = (JMenuItem)(e.getSource());
			if (menuItem != null) {
				Command cmd = commandsForJMenuItem.get(menuItem);
				if (cmd != null) {
					GuiApplication.executeCommand(cmd);
				}
			}
		}
	}

}
