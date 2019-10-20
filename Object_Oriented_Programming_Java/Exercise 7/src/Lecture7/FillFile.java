package Lecture7;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class FillFile
{
	static String parent = System.getProperty("user.dir");
	static String testfileName = "testinput.dat";

	public static void main(String[] args)
	{
		try
		{
			fill();
		}
		catch(IOException e)
		{
			e.printStackTrace();
			System.out.println(e.getMessage());
		}
	}
	
	public static void fill() throws IOException
	{
		File fillFile = new File(parent, testfileName);
		if (fillFile.exists())
		{
			if (!fillFile.canWrite())
			{
				abort("new file is unwriteable: "+ parent +"te");
				throw new IOException ("FileFill not possible");
			}
			else
			{
				fillFile.createNewFile();
				if(!fillFile.canWrite())
				{
					throw new IOException ("FileFill not possible");
				}
			}
			FileWriter fOS = null;
			try
			{
				fOS = new FileWriter(fillFile);
				StringBuffer buff = new StringBuffer();
				buff.append("This is ");
				buff.append("a ");
				buff.append("test !!!   \n");
				fOS.write(buff.toString());
				System.out.println(parent);
			}
			catch(IOException e) {;}
			finally
			{
					if(fOS != null) try {fOS.close();}
					catch(IOException e) {;}
			}
		}
	}
	
	private static void abort(String msg) throws IOException
	{
		throw new IOException("FileCopy: " + msg);
	}
}