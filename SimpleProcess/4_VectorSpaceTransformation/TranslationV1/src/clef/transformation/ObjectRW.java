package clef.transformation;

import java.io.*;
import java.util.zip.*;

// the class for writing object to file and load object from file
public class ObjectRW {

	public static boolean write(String path, Object object) {
		File file = new File(path);
		String fileName = file.getName();

		if (file.exists())
			file.delete();

		System.out.println("Start to write Object to file: " + fileName);

		try {
			ObjectOutputStream oos = new ObjectOutputStream(new GZIPOutputStream(new FileOutputStream(path)));
			oos.writeObject(object);
			oos.flush();
			oos.close();
		} catch (IOException e) {
			System.out.println("Failed to write Object to file: " + fileName + "\n" + e.toString());
			return false;
		}

		System.out.println("Finish writing the Object to file: " + fileName);

		return true;
	}

	public static Object read(String path) {
		String fileName = new File(path).getName();
		System.out.println("Start to load Object from file: " + fileName);

		Object result;
		try {
			ObjectInputStream ois = new ObjectInputStream(new GZIPInputStream(new FileInputStream(path)));
			result = ois.readObject();
			ois.close();
		} catch (Exception e) {
			System.out.println("Failed to load Object from file: " + fileName + "\n" + e.toString());
			return null;
		}

		System.out.println("Finish loading the Object from file: " + fileName);

		return result;
	}
}
