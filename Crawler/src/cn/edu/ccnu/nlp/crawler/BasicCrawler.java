package cn.edu.ccnu.nlp.crawler;

import java.io.BufferedWriter;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.regex.Pattern;

import edu.uci.ics.crawler4j.crawler.Page;
import edu.uci.ics.crawler4j.crawler.WebCrawler;
import edu.uci.ics.crawler4j.parser.HtmlParseData;
import edu.uci.ics.crawler4j.url.WebURL;

public class BasicCrawler extends WebCrawler
{
	private static final String resultPath = Util.workspace;
	private static final Pattern IMAGE_EXTENSIONS = Pattern
			.compile(".*\\.(bmp|gif|jpg|png)$");

	@Override
	public boolean shouldVisit(Page referringPage, WebURL url)
	{
		String href = url.getURL().toLowerCase();

		if (IMAGE_EXTENSIONS.matcher(href).matches())
		{
			return false;
		}

		return (href.contains("cn.chinadaily.com.cn") || href.contains("usa.chinadaily.com.cn")) && href.contains(".htm");
	}

	@Override
	public void visit(Page page)
	{
//		String href = page.getWebURL().getURL().toLowerCase();
		if (page.getParseData() instanceof HtmlParseData)
		{
//			if (href.startsWith("http://news.yahoo.com/")
//					&& href.endsWith(".html"))
			{
				HtmlParseData htmlParseData = (HtmlParseData) page
						.getParseData();
				String html = htmlParseData.getHtml();
				String addPath = "";
				if(page.getWebURL().getURL().contains("cn.chinadaily.com.cn"))
					addPath = "cn/";
				else if(page.getWebURL().getURL().contains("usa.chinadaily.com.cn"))
					addPath = "usa/";
				
				String filename = page.getWebURL().getURL()
						.replaceAll("[/:?=&]+", "@");
				try (BufferedWriter bw = new BufferedWriter(
						new OutputStreamWriter(new FileOutputStream(resultPath + addPath
								+ filename, false), "UTF-8"));)
				{
					bw.write(html);
					System.out.println(filename + "\n"
							+ "\t==========================");
				}
				catch (IOException e)
				{
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
		}

	}
}
