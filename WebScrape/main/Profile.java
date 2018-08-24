package main;

public class Profile {
	
	private String FirstName;
	private String LastName;
	private String OfficeNum;
	private String CellNum;
	private String email;
	
	public Profile(String fname, String lname, String oNum, String cNum,String email)
	{
		this.FirstName = fname;
		this.LastName = lname;
		this.OfficeNum = oNum;
		this.CellNum = cNum;
		this.email = email;
	}
	
	
	public String getFName()
	{
		return FirstName;
	}
	
	public String getLName()
	{
		return LastName;
	}
	
	public String getONum()
	{
		return OfficeNum;
	}
	
	public String getCellNum()
	{
		return CellNum;
	}
	
	public String getEmail()
	{
		return email;
	}
	
	
	

}
