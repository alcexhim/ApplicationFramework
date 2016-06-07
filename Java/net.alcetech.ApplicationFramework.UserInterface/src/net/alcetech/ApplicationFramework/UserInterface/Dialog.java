package net.alcetech.ApplicationFramework.UserInterface;

import javax.swing.*;

public class Dialog extends JDialog {
	
	/**
	 * 
	 */
	private static final long serialVersionUID = 1573378547369385898L;
	
	private DialogResult _DialogResult = DialogResult.NONE;
	public DialogResult getDialogResult() {
		return this._DialogResult;
	}
	public void setDialogResult(DialogResult value) {
		this._DialogResult = value;
	}
	
	public DialogResult showDialog() {
		return this.showDialog(ModalityType.APPLICATION_MODAL);
	}
	public DialogResult showDialog(ModalityType modalityType) {
		this.setModalityType(modalityType);
		this.setVisible(true);
		return this.getDialogResult();
	}

}
