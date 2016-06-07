package net.alcetech.ApplicationFramework.IO;

public abstract class FileSystemObject {
	
	private java.io.File _File = null;
	/**
	 * Gets the underlying java.io.File object corresponding to this FileSystemObject.
	 * @return java.io.File corresponding to this FileSystemObject.
	 */
	public java.io.File getUnderlyingFile() { return _File; }
	
	public boolean exists() {
		if (_File == null) return false;
		return _File.exists();
	}

	private Directory _ParentDirectory = null;
	public Directory getParentDirectory() { return _ParentDirectory; }
	public void setParentDirectory(Directory value) {
		_ParentDirectory = value;
		_File = new java.io.File(this.getFullPath());
	}

	private String _Name = "";
	public String getName() { return _Name; }
	public void setName(String value) {
		_Name = value;
		_File = new java.io.File(this.getFullPath());
	}
	
	public String getFullPath() {
		String path = "";
		if (this._ParentDirectory != null) {
			path += this._ParentDirectory.getFullPath() + "/";
		}
		path += this.getName();
		return path;
	}
	public void setFullPath(String path) {
		String[] pathParts = path.split("/");
		
		Directory parentDirectory = null;
		Directory lastParentDirectory = null;
		
		for (int i = 0; i < pathParts.length - 1; i++) {
			
			parentDirectory = new Directory(pathParts[i]);
			parentDirectory.setParentDirectory(lastParentDirectory);
			
			lastParentDirectory = parentDirectory;
		}
		
		this.setParentDirectory(parentDirectory);
		this.setName(pathParts[pathParts.length - 1]);
	}
	
}
