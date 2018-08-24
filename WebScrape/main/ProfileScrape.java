package main;

import java.io.FileOutputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.logging.Level;

import org.apache.commons.logging.LogFactory;
import org.apache.poi.openxml4j.exceptions.InvalidFormatException;
import org.apache.poi.ss.usermodel.Cell;
import org.apache.poi.ss.usermodel.CellStyle;
import org.apache.poi.ss.usermodel.Font;
import org.apache.poi.ss.usermodel.IndexedColors;
import org.apache.poi.ss.usermodel.Row;
import org.apache.poi.ss.usermodel.Sheet;
import org.apache.poi.ss.usermodel.Workbook;
import org.apache.poi.xssf.usermodel.XSSFWorkbook;

import com.gargoylesoftware.htmlunit.BrowserVersion;
import com.gargoylesoftware.htmlunit.WebClient;
import com.gargoylesoftware.htmlunit.html.HtmlAnchor;
import com.gargoylesoftware.htmlunit.html.HtmlListItem;
import com.gargoylesoftware.htmlunit.html.HtmlPage;
/* This will scrape information from given website to get the each persons information
 * such as their name, phone, and email. This is done using HtmlUnit and afterwards the information
 * is written down on excel file using Apache POI
 * 
 */
public class ProfileScrape
{
	public static void main(String[] args)
	{
		String url = "https://www.floridabar.org/directories/find-mbr/?lName=&lNameSdx=N&fName=&fNameSdx=N&eligible=Y&deceased=Y&firm=&locValue=Miami-Dade&locType=T&pracAreas=C16&lawSchool=&services=&langs=&certValue=&pageNumber=1&pageSize=999";
		WebClient client; //= new WebClient();
		
		
		LogFactory.getFactory().setAttribute("org.apache.commons.logging.Log", "org.apache.commons.logging.impl.NoOpLog");

		java.util.logging.Logger.getLogger("com.gargoylesoftware").setLevel(Level.OFF); 
		java.util.logging.Logger.getLogger("org.apache.commons.httpclient").setLevel(Level.OFF);

		client = new WebClient(BrowserVersion.CHROME);
		client.getOptions().setJavaScriptEnabled(true);
		client.getOptions().setCssEnabled(false);
		client.getOptions().setThrowExceptionOnScriptError(false);
		client.getOptions().setThrowExceptionOnFailingStatusCode(false);
		client.getOptions().setTimeout(5000);
		
		List<Profile> prof = new ArrayList<Profile>();
		try {
			HtmlPage page = (HtmlPage) client.getPage(url);
			
			List<?> profiles = getProfile(page);
			
			
			for(int i = 0; i<profiles.size();i++)
			{
				HtmlListItem temp = (HtmlListItem) profiles.get(i);
				
				HtmlAnchor anch = temp.getFirstByXPath(".//p[@class='profile-name']/a");
				String[] name = anch.asText().split(" ");
				String firstName = name[0];
				String lastName;
				String office;
				String cell;
				String email;
				
				if(name.length==3)
					lastName = name[2];
				else
					lastName = name[1];
				
				
				
				List<?> ref = temp.getByXPath(".//div[@class = 'profile-contact']/p/a");
				
				HtmlAnchor tempR = (HtmlAnchor) ref.get(0);
				office = tempR.asText();
				
				
				if(ref.size()==3)
				{
					tempR = (HtmlAnchor) ref.get(1);
					cell = tempR.asText();
					
				
					tempR = (HtmlAnchor) ref.get(2);
					email = tempR.asText();
				   prof.add(new Profile(firstName,lastName,office,cell,email));
					
				}
				
				else
				{
					
					tempR = (HtmlAnchor) ref.get(1);
					email = tempR.asText();
					prof.add(new Profile(firstName,lastName,office,null,email));
					
					
				}
				
				
				
				
				
			}
			

			writeToExcel(prof);
			client.close();
			
		}
	
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}
	private static List<?> getProfile(HtmlPage page)
	{
		final List<?> li = page.getByXPath("//li[@class='profile-compact']");
		return li;
	}
	
	static void writeToExcel(List<Profile> profiles) throws IOException, InvalidFormatException
	{
		Workbook wrk = new XSSFWorkbook();
		Sheet sheet = wrk.createSheet("Profiles");
		
		Font headerFont = wrk.createFont();
		headerFont.setBold(true);
		headerFont.setFontHeightInPoints((short) 12);
        
        CellStyle headerStyle = wrk.createCellStyle();
        headerStyle.setFont(headerFont);
        
        String[] col = {"First Name", "Last Name", "Office Num","Cell Num", "Email"};
        
        Row headerRow = sheet.createRow(0);
        for(int i = 0; i<col.length;i++)
        {
        	Cell cell = headerRow.createCell(i);
        	cell.setCellValue(col[i]);
        	cell.setCellStyle(headerStyle);
        }
        int rowNum = 1;
        for(Profile prof: profiles)
        {
        	Row row = sheet.createRow(rowNum++);
        	
        	row.createCell(0).setCellValue(prof.getFName());
        	row.createCell(1).setCellValue(prof.getLName());
        	row.createCell(2).setCellValue(prof.getONum());
        	row.createCell(3).setCellValue(prof.getCellNum());
        	row.createCell(4).setCellValue(prof.getEmail());
        	
        }
		
        for(int i = 0; i < col.length; i++) {
            sheet.autoSizeColumn(i);
        }
        
        
     
        FileOutputStream fileOut = new FileOutputStream("profiles.xlsx");
        wrk.write(fileOut);
        fileOut.close();

        
        wrk.close();


		
	}
}




