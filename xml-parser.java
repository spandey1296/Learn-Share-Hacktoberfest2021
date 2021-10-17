import java.io.File;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;

import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

public class XmlParse
{
	public static void main(String args[])   
	{  
		try   
		{  
		  
		File file = new File("C:\\Users\\user\\Desktop\\xmlfile.xml");  
		
		//an instance of factory that gives a document builder  
		DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance(); 
		
		//an instance of builder to parse the specified xml file  
		DocumentBuilder db = dbf.newDocumentBuilder();  
		Document doc = db.parse(file);  
		doc.getDocumentElement().normalize();  
		System.out.println("Root element: " + doc.getDocumentElement().getNodeName());  
		NodeList nodeList = doc.getElementsByTagName("course");  
		// nodeList is not iterable, so we are using for loop  
		
		System.out.println("Course Details");
		System.out.println("Course Code\tCourse Name\t\tCourse Fee");
		
		for (int itr = 0; itr < nodeList.getLength(); itr++)   
		{  
		Node node = nodeList.item(itr);  
		
			if (node.getNodeType() == Node.ELEMENT_NODE)   
			{  
				Element eElement = (Element) node;  
				System.out.print( eElement.getElementsByTagName("coursecode").item(0).getTextContent()+"\t\t");  
				System.out.print( eElement.getElementsByTagName("coursename").item(0).getTextContent()+"\t\t");  
				System.out.print( eElement.getElementsByTagName("fees").item(0).getTextContent()+"\t\t");  
			}  
			System.out.println();
		}  
		}   
		catch (Exception e)   
		{  
		e.printStackTrace();  
		}  
	}}

	
