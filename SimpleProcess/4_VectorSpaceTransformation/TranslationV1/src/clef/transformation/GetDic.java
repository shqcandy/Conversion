package clef.transformation;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;

import com.aliasi.util.Files;

public class GetDic
{
	public static void main(String[] args) throws IOException
	{
		int [] enlang = {50 , 100 , 200 , 400 , 800};
		
		for (int i : enlang)
		{
			mulDic(i);
		}
		
//		String lang = "fr";
//		dic(lang);
//		lang = "en";
//		dic(lang);
	}

	private static void mulDic(int lang) throws IOException
	{
		HashMap<String, HashSet<String>> DIC = fullDic();
		
		ArrayList<String> tempEn = new ArrayList<String>();
		tempEn.addAll(DIC.keySet());
		
		Word2VEC vecEn = new Word2VEC();
		vecEn.loadModel(Util.corpus + "en.corpus_" + lang + ".bin");
		Word2VEC vecFr = new Word2VEC();
		vecFr.loadModel(Util.corpus + "fr.corpus_" + lang + ".bin");
//		float[] vector = vec.getWordVector("I love you.");
		
		ArrayList<float[]> enVec = new ArrayList<float[]>();
		ArrayList<float[]> frVec = new ArrayList<float[]>();
		for (int i = 0; i < tempEn.size() ; i++)
		{
			if(DIC.get(tempEn.get(i)).size() > 1)
				continue;
			
			float[] enWord = vecEn.getWordVector(tempEn.get(i));
			if(enWord == null)
				continue;
			for (String string : DIC.get(tempEn.get(i)))
			{
				float[] frWord = vecFr.getWordVector(string);
				if(frWord == null)
					continue;
				enVec.add(enWord);
				frVec.add(frWord);
			}
		}
		
		double[][] en = new double[enVec.size()][];
		for (int i = 0; i < enVec.size(); i++)
		{
			en[i] = new double[enVec.get(i).length];
			for (int j = 0; j < enVec.get(i).length; j++)
			{
				en[i][j] = enVec.get(i)[j];
			}
		}
		ObjectRW.write(Util.corpusPath + "trainInput_" + lang + ".dat", en);
		
		ArrayList<double[]> fr = new ArrayList<double[]>(frVec.get(0).length);
		for (int i = 0; i < frVec.get(0).length; i++)
		{
			double[] f = new double[frVec.size()];
			for (int j = 0; j < frVec.size(); j++)
			{
				f[j] = frVec.get(j)[i];
			}
			fr.add(f);
		}
		ObjectRW.write(Util.corpusPath + "trainOutput_" + lang + ".dat", fr);
		
		StringBuilder sbEn = new StringBuilder();
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < tempEn.size() ; i++)
		{
			if(DIC.get(tempEn.get(i)).size() == 1)
				continue;
			
			float[] enWord = vecEn.getWordVector(tempEn.get(i));
			if(enWord == null)
				continue;
			sbEn.append(tempEn.get(i) + "\n");
			for (String string : DIC.get(tempEn.get(i)))
			{
				float[] frWord = vecFr.getWordVector(string);
				if(frWord == null)
					continue;
				sb.append(tempEn.get(i) + "\t0\t" + string + "\t1\n");
			}
		}
		
		Files.writeStringToFile(sbEn.toString(), new File(Util.corpus + "test.txt"), "UTF-8");
		Files.writeStringToFile(sb.toString(), new File(Util.corpus + "test.gold"), "UTF-8");
	}
	
	private static HashMap<String, HashSet<String>> fullDic() throws IOException
	{
		HashMap<String, HashSet<String>> re = new HashMap<String, HashSet<String>>();
		String [] words = Files.readFromFile(new File(Util.corpus + "fullDicText"), "UTF-8").split("\n");
		for (String string : words)
		{
			if(!string.contains("\t"))
				continue;
			String en = string.split("\t")[0].trim().toLowerCase();
			String fr = string.split("\t")[1].trim().toLowerCase();
			if(re.containsKey(en))
			{
				HashSet<String> temp = re.get(en);
				temp.add(fr);
				re.put(en, temp);
			}
			else
			{
				HashSet<String> temp = new HashSet<String>();
				temp.add(fr);
				re.put(en, temp);
			}
		}
		return re;
	}

	private static void dic(String lang) throws FileNotFoundException,
			IOException
	{
		BufferedReader br = new BufferedReader(new FileReader(Util.corpusPath + lang + ".corpus.txt"));
		br.readLine();
		br.readLine();
		String line = "";
		StringBuilder sb = new StringBuilder();
		while((line = br.readLine()) != null)
		{
			String word = line.split("\\s+")[0].trim();
			sb.append(word + "\n");
		}
		br.close();
		Files.writeStringToFile(sb.toString(), new File(Util.corpusPath + lang + "Dic.txt"), "UTF-8");
	}
}
