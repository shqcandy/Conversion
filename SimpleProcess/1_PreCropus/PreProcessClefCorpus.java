
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

//prepare the CLEF corpus for treetagger
public class PreProcessClefCorpus
{

	// load the raw CLEF corpus and process the content of the corpus
	// save the processed content to disk for the treetagger to process
	private boolean preProcessEn(String corpusName, String encode)
	{
		// only save all the pure text for the process of treetagger
		StringBuilder result = new StringBuilder();

		// load the corpus content
		String content = read(corpusName, encode);

		// process the content of the files
		int count = 1;
		// extract each document
		Matcher docMatcher = Pattern.compile("<DOC>[\\s\\S]+?</DOC>")
				.matcher(content);
		while (docMatcher.find())
		{
			System.out.println("Processing document: " + count);
			// process the current document content
			String docContent = content.substring(
					docMatcher.start(), docMatcher.end());

			// extract and process all the text blocks in the
			// document
			Matcher txtMatcher = Pattern.compile(
					"<TEXT>[\\s\\S]*?</TEXT>").matcher(
					docContent);
			while (txtMatcher.find())
			{

				String txtContent = docContent.substring(
						txtMatcher.start(),
						txtMatcher.end());

				// remove all the <...> from the text content
				txtContent = txtContent.replaceAll(
						"<[\\s\\S]+?>", "");
				// remove all \n with blank
				txtContent = txtContent.replaceAll("\n", " ");
				// delete duplicate blanks
				txtContent = txtContent.replaceAll("\\s{2,}",
						" ");
				// process special characters
				txtContent = txtContent.replace("&lt;", "<");
				txtContent = txtContent.replace("&gt;", ">");
				txtContent = txtContent.replace("&amp;", "&");
				txtContent = txtContent.replace("&plus;", "+");
				txtContent = txtContent
						.replace("&equals;", "=");
				txtContent = txtContent.replace("&lsqb;", "[");
				txtContent = txtContent.replace("&rsqb;", "]");

				// append to result
				result.append(txtContent);
				result.append("\n");
			}
			count++;
		}

		System.out.println("Finishing processing the documents in "
				+ corpusName + " corpus.");

		// save the processed CLEF content(English) to disk for the tool
		// treetagger to process
		if (!write(result.toString(), corpusName + "-utf8", "utf-8"))
			return false;

		return true;
	}

	// the french corpus has some different styles
	private boolean preProcessFrLemonde(String corpusName, String encode)
	{

		// only save all the pure text for the process of treetagger
		StringBuilder result = new StringBuilder();

		// load content of lemonde94, extract <TEXT>...</TEXT>
		String content = read(corpusName, encode);

		// process the content of the files
		int count = 1;
		// extract each document
		Matcher docMatcher = Pattern.compile("<DOC>[\\s\\S]+?</DOC>")
				.matcher(content);
		while (docMatcher.find())
		{
			System.out.println("Processing document: " + count);
			// process the current document content
			String docContent = content.substring(
					docMatcher.start(), docMatcher.end());

			// extract and process all the text blocks in the
			// document
			Matcher txtMatcher = Pattern.compile(
					"<TEXT>[\\s\\S]*?</TEXT>").matcher(
					docContent);
			while (txtMatcher.find())
			{
				String txtContent = docContent.substring(
						txtMatcher.start(),
						txtMatcher.end());

				// remove all the <...> from the text content
				txtContent = txtContent.replaceAll(
						"<[\\s\\S]+?>", "");
				// remove all \n with blank
				txtContent = txtContent.replaceAll("\n", " ");
				// delete duplicate blanks
				txtContent = txtContent.replaceAll("\\s{2,}",
						" ");
				// process special characters
				txtContent = txtContent.replace("&lt;", "<");
				txtContent = txtContent.replace("&gt;", ">");
				txtContent = txtContent.replace("&amp;", "&");
				txtContent = txtContent.replace("&plus;", "+");
				txtContent = txtContent
						.replace("&equals;", "=");
				txtContent = txtContent.replace("&lsqb;", "[");
				txtContent = txtContent.replace("&rsqb;", "]");

				// append to result
				txtContent = txtContent.replace("<", "");
				txtContent = txtContent.replace(">", "");

				result.append(txtContent);
				result.append("\n");

			}

			count++;

		}
		System.out.println("Finishing processing the documents in lemonde94(fr) corpus.");

		// save the processed CLEF content(English) to disk for the tool
		// treetagger to process
		if (!write(result.toString(), corpusName + "-utf8", "utf-8"))
			return false;

		return true;
	}

	// the french corpus has some different styles
	// sda94, 95
	private boolean preProcessFrSda(String corpusName, String encode)
	{

		// only save all the pure text for the process of treetagger
		StringBuilder result = new StringBuilder();

		String allContent = read(corpusName, encode);

		int count = 1;

		// extract each document
		Matcher docMatcher = Pattern.compile("<DOC>[\\s\\S]+?</DOC>")
				.matcher(allContent);
		while (docMatcher.find())
		{
			System.out.println("Processing document: " + count);
			// process the current document content
			String docContent = allContent.substring(
					docMatcher.start(), docMatcher.end());

			// extract and process all the text blocks in the
			// document
			Matcher txtMatcher = Pattern
					.compile("(<LD>[\\s\\S]*?</LD>)|(<TX>[\\s\\S]*?</TX>)")
					.matcher(docContent);
			while (txtMatcher.find())
			{
				String txtContent = docContent.substring(
						txtMatcher.start(),
						txtMatcher.end());

				// remove all the <...> from the text content
				txtContent = txtContent.replaceAll(
						"<[\\s\\S]+?>", "");
				// remove all \n with blank
				txtContent = txtContent.replaceAll("\n", " ");
				// delete duplicate blanks
				txtContent = txtContent.replaceAll("\\s{2,}",
						" ");
				// process special characters
				txtContent = txtContent.replace("&lt;", "<");
				txtContent = txtContent.replace("&gt;", ">");
				txtContent = txtContent.replace("&amp;", "&");
				txtContent = txtContent.replace("&plus;", "+");
				txtContent = txtContent
						.replace("&equals;", "=");
				txtContent = txtContent.replace("&lsqb;", "[");
				txtContent = txtContent.replace("&rsqb;", "]");

				// append to result
				result.append(txtContent);
				result.append("\n");
			}

			count++;
		}

		System.out.println("Finishing processing the documents in sda(fr) corpus.");

		// save the processed CLEF content(English) to disk for the tool
		// treetagger to process
		if (!write(result.toString(), corpusName + "-utf8", "utf-8"))
			return false;

		return true;
	}
	public static void main(String [] args)
	{
		new PreProcessClefCorpus().process();
	}
	public boolean process()
	{
		if (!preProcessEn("E:/Word2Vec/corpus/en/GH95.all",
				"ISO-8859-1"))
			return false;

		if (!preProcessEn("E:/Word2Vec/corpus/en/LAT94.all",
				"ISO-8859-1"))
			return false;

		if (!preProcessFrSda("E:/Word2Vec/corpus/fr/sda94.all",
				"ISO-8859-1"))
			return false;

		if (!preProcessFrSda("E:/Word2Vec/corpus/fr/sda95.all",
				"ISO-8859-1"))
			return false;

		if (!preProcessFrLemonde("E:/Word2Vec/corpus/fr/lemonde94.all",
				"ISO-8859-1"))
			return false;

		return true;
	}

	public static boolean write(String contentToWrite, String filePath,
			String encoding)
	{

		try
		{

			System.out.println("Start to write file: "
					+ new File(filePath).getName());

			BufferedWriter bw = new BufferedWriter(
					new OutputStreamWriter(
							new FileOutputStream(
									filePath,
									false),
							encoding));
			bw.write(contentToWrite);
			bw.flush();
			bw.close();

			System.out.println("Finish writing file: "
					+ new File(filePath).getName());

			return true;

		}
		catch (Exception e)
		{
			System.out.println("Fail to write the file: "
					+ filePath + "\n" + e.toString());
			return false;
		}
	}

	public static String read(String filePath, String encoding)
	{

		try
		{

			System.out.println("Start to read file: "
					+ new File(filePath).getName());

			StringBuilder sb = new StringBuilder();

			BufferedReader br = new BufferedReader(
					new InputStreamReader(
							new FileInputStream(
									filePath),
							encoding));
			// int bufLen = 1000000000;
			int bufLen = 1000000;
			char[] buf = new char[bufLen];
			int len = 0;
			while ((len = br.read(buf, 0, bufLen)) != -1)
			{
				sb.append(buf, 0, len);
			}

			br.close();
			buf = null;

			System.out.println("Finish reading file: "
					+ new File(filePath).getName());

			return sb.toString();

		}
		catch (IOException e)
		{
			System.out.println("Fail to read the file: " + filePath
					+ "\n" + e.toString());
			return null;
		}
	}
}
