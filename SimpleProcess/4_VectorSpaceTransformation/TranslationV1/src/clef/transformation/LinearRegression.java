package clef.transformation;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Set;

import org.apache.commons.math3.stat.regression.OLSMultipleLinearRegression;

import clef.transformation.Word2VEC.WordEntry;

import com.aliasi.util.Files;

public class LinearRegression
{
	public static void main(String[] args) throws IOException
	{
		int [] enlang = {50 , 100 , 200 , 400 , 800};
		int [] frlang = {50 , 100 , 200 , 400 , 800};
		
		for (int i : enlang)
		{
			for (int j : frlang)
			{
				getIRParameter(i , j);
				test(i , j);
			}
		}
	}

	private static void test(int in , int out) throws IOException
	{
		String [] words = Files.readFromFile(new File(Util.corpus + "test.txt"), "UTF-8").split("\n");
		@SuppressWarnings("unchecked")
		ArrayList<double[]> lrParameter = (ArrayList<double[]>) ObjectRW.read(Util.corpusPath + "lrParameter_" + in + "_" + out);
		
		Word2VEC vecEn = new Word2VEC();
		vecEn.loadModel(Util.corpus + "en.corpus_" + in + ".bin");
		Word2VEC vecFr = new Word2VEC();
		vecFr.loadModel(Util.corpus + "fr.corpus_" + out + ".bin");
		
		StringBuilder sb = new StringBuilder();
		for (String string : words)
		{
			float [] en = vecEn.getWordVector(string.trim());
			float [] fr = new float[lrParameter.size()];
			for (int i = 0; i < lrParameter.size(); i++)
			{
				double [] para = lrParameter.get(i);
				fr[i] = (float) para[0];
				for (int j = 0; j < en.length; j++)
				{
					fr[i] += en[j] * para[j + 1];
				}
			}
			Set<WordEntry> temp = vecFr.distance(fr);
			int i = 1;
			for (WordEntry word : temp)
			{
				sb.append(string + "\tX\t" + word.name + "\t" + i++ + "\t" + word.score + "\tbaseline\n");
			}
		}
		
		Files.writeStringToFile(sb.toString(), new File(Util.corpusPath + "test_" + in + "_" + out + ".result"), "UTF-8");
	}
	
	private static void getIRParameter(int in , int out)
	{
		// OLSMultipleLinearRegression lr = new
		// OLSMultipleLinearRegression();
		/*
		 * lr.estimateRegressionParameters() 得到的结果中第一个表示的是截距。后面的依次为x1 ~
		 * xn的权重
		 */

		ArrayList<double[]> lrParameter = new ArrayList<double[]>();

		double[][] input = (double[][]) ObjectRW.read(Util.corpusPath
				+ "trainInput_" + in + ".dat");
		@SuppressWarnings("unchecked")
		ArrayList<double[]> output = (ArrayList<double[]>) ObjectRW
				.read(Util.corpusPath + "trainOutput_" + out + ".dat");
		for (int i = 0; i < output.size(); i++)
		{
			OLSMultipleLinearRegression lr = new OLSMultipleLinearRegression();
			lr.newSampleData(output.get(i), input);
			lrParameter.add(lr.estimateRegressionParameters());
			System.out.println(lr.calculateAdjustedRSquared());
		}

		ObjectRW.write(Util.corpusPath + "lrParameter_" + in + "_" + out , lrParameter);
	}

}
