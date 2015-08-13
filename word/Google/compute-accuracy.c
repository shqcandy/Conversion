



<!DOCTYPE html>
<html>
<head>
 <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" >
 <meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1" >
 
 <meta name="ROBOTS" content="NOARCHIVE">
 
 <link rel="icon" type="image/vnd.microsoft.icon" href="https://ssl.gstatic.com/codesite/ph/images/phosting.ico">
 
 
 <script type="text/javascript">
 
 
 
 
 var codesite_token = null;
 
 
 var CS_env = {"token": null, "relativeBaseUrl": "", "assetVersionPath": "https://ssl.gstatic.com/codesite/ph/8599073060794244502", "domainName": null, "assetHostPath": "https://ssl.gstatic.com/codesite/ph", "projectName": "word2vec", "loggedInUserEmail": null, "projectHomeUrl": "/p/word2vec", "profileUrl": null};
 var _gaq = _gaq || [];
 _gaq.push(
 ['siteTracker._setAccount', 'UA-18071-1'],
 ['siteTracker._trackPageview']);
 
 (function() {
 var ga = document.createElement('script'); ga.type = 'text/javascript'; ga.async = true;
 ga.src = ('https:' == document.location.protocol ? 'https://ssl' : 'http://www') + '.google-analytics.com/ga.js';
 (document.getElementsByTagName('head')[0] || document.getElementsByTagName('body')[0]).appendChild(ga);
 })();
 
 </script>
 
 
 <title>compute-accuracy.c - 
 word2vec -
 
 
 Tool for computing continuous distributed representations of words. - Google Project Hosting
 </title>
 <link type="text/css" rel="stylesheet" href="https://ssl.gstatic.com/codesite/ph/8599073060794244502/css/core.css">
 
 <link type="text/css" rel="stylesheet" href="https://ssl.gstatic.com/codesite/ph/8599073060794244502/css/ph_detail.css" >
 
 
 <link type="text/css" rel="stylesheet" href="https://ssl.gstatic.com/codesite/ph/8599073060794244502/css/d_sb.css" >
 
 
 
<!--[if IE]>
 <link type="text/css" rel="stylesheet" href="https://ssl.gstatic.com/codesite/ph/8599073060794244502/css/d_ie.css" >
<![endif]-->
 <style type="text/css">
 .menuIcon.off { background: no-repeat url(https://ssl.gstatic.com/codesite/ph/images/dropdown_sprite.gif) 0 -42px }
 .menuIcon.on { background: no-repeat url(https://ssl.gstatic.com/codesite/ph/images/dropdown_sprite.gif) 0 -28px }
 .menuIcon.down { background: no-repeat url(https://ssl.gstatic.com/codesite/ph/images/dropdown_sprite.gif) 0 0; }
 
 
 
  tr.inline_comment {
 background: #fff;
 vertical-align: top;
 }
 div.draft, div.published {
 padding: .3em;
 border: 1px solid #999; 
 margin-bottom: .1em;
 font-family: arial, sans-serif;
 max-width: 60em;
 }
 div.draft {
 background: #ffa;
 } 
 div.published {
 background: #e5ecf9;
 }
 div.published .body, div.draft .body {
 padding: .5em .1em .1em .1em;
 max-width: 60em;
 white-space: pre-wrap;
 white-space: -moz-pre-wrap;
 white-space: -pre-wrap;
 white-space: -o-pre-wrap;
 word-wrap: break-word;
 font-size: 1em;
 }
 div.draft .actions {
 margin-left: 1em;
 font-size: 90%;
 }
 div.draft form {
 padding: .5em .5em .5em 0;
 }
 div.draft textarea, div.published textarea {
 width: 95%;
 height: 10em;
 font-family: arial, sans-serif;
 margin-bottom: .5em;
 }

 
 .nocursor, .nocursor td, .cursor_hidden, .cursor_hidden td {
 background-color: white;
 height: 2px;
 }
 .cursor, .cursor td {
 background-color: darkblue;
 height: 2px;
 display: '';
 }
 
 
.list {
 border: 1px solid white;
 border-bottom: 0;
}

 
 </style>
</head>
<body class="t4">
<script type="text/javascript">
 window.___gcfg = {lang: 'en'};
 (function() 
 {var po = document.createElement("script");
 po.type = "text/javascript"; po.async = true;po.src = "https://apis.google.com/js/plusone.js";
 var s = document.getElementsByTagName("script")[0];
 s.parentNode.insertBefore(po, s);
 })();
</script>
<div class="headbg">

 <div id="gaia">
 

 <span>
 
 
 <a href="#" id="projects-dropdown" onclick="return false;"><u>My favorites</u> <small>&#9660;</small></a>
 | <a href="https://www.google.com/accounts/ServiceLogin?service=code&amp;ltmpl=phosting&amp;continue=https%3A%2F%2Fcode.google.com%2Fp%2Fword2vec%2Fsource%2Fbrowse%2Ftrunk%2Fcompute-accuracy.c&amp;followup=https%3A%2F%2Fcode.google.com%2Fp%2Fword2vec%2Fsource%2Fbrowse%2Ftrunk%2Fcompute-accuracy.c" onclick="_CS_click('/gb/ph/signin');"><u>Sign in</u></a>
 
 </span>

 </div>

 <div class="gbh" style="left: 0pt;"></div>
 <div class="gbh" style="right: 0pt;"></div>
 
 
 <div style="height: 1px"></div>
<!--[if lte IE 7]>
<div style="text-align:center;">
Your version of Internet Explorer is not supported. Try a browser that
contributes to open source, such as <a href="http://www.firefox.com">Firefox</a>,
<a href="http://www.google.com/chrome">Google Chrome</a>, or
<a href="http://code.google.com/chrome/chromeframe/">Google Chrome Frame</a>.
</div>
<![endif]-->



 <table style="padding:0px; margin: 0px 0px 10px 0px; width:100%" cellpadding="0" cellspacing="0"
 itemscope itemtype="http://schema.org/CreativeWork">
 <tr style="height: 58px;">
 
 
 
 <td id="plogo">
 <link itemprop="url" href="/p/word2vec">
 <a href="/p/word2vec/">
 
 <img src="https://ssl.gstatic.com/codesite/ph/images/search-48.gif" alt="Logo" itemprop="image">
 
 </a>
 </td>
 
 <td style="padding-left: 0.5em">
 
 <div id="pname">
 <a href="/p/word2vec/"><span itemprop="name">word2vec</span></a>
 </div>
 
 <div id="psum">
 <a id="project_summary_link"
 href="/p/word2vec/"><span itemprop="description">Tool for computing continuous distributed representations of words.</span></a>
 
 </div>
 
 
 </td>
 <td style="white-space:nowrap;text-align:right; vertical-align:bottom;">
 
 <form action="/hosting/search">
 <input size="30" name="q" value="" type="text">
 
 <input type="submit" name="projectsearch" value="Search projects" >
 </form>
 
 </tr>
 </table>

</div>

 
<div id="mt" class="gtb"> 
 <a href="/p/word2vec/" class="tab ">Project&nbsp;Home</a>
 
 
 
 
 
 
 
 
 <a href="/p/word2vec/issues/list"
 class="tab ">Issues</a>
 
 
 
 
 
 <a href="/p/word2vec/source/checkout"
 class="tab active">Source</a>
 
 
 
 
 
 
 
 
 <a href="https://code.google.com/export-to-github/export?project=word2vec">
 <button>Export to GitHub</button>
 
 </a>
 
 
 
 
 
 <div class=gtbc></div>
</div>
<table cellspacing="0" cellpadding="0" width="100%" align="center" border="0" class="st">
 <tr>
 
 
 
 
 
 
 <td class="subt">
 <div class="st2">
 <div class="isf">
 
 


 <span class="inst1"><a href="/p/word2vec/source/checkout">Checkout</a></span> &nbsp;
 <span class="inst2"><a href="/p/word2vec/source/browse/">Browse</a></span> &nbsp;
 <span class="inst3"><a href="/p/word2vec/source/list">Changes</a></span> &nbsp;
 
 
 
 
 
 
 
 </form>
 <script type="text/javascript">
 
 function codesearchQuery(form) {
 var query = document.getElementById('q').value;
 if (query) { form.action += '%20' + query; }
 }
 </script>
 </div>
</div>

 </td>
 
 
 
 <td align="right" valign="top" class="bevel-right"></td>
 </tr>
</table>


<script type="text/javascript">
 var cancelBubble = false;
 function _go(url) { document.location = url; }
</script>
<div id="maincol"
 
>

 




<div class="expand">
<div id="colcontrol">
<style type="text/css">
 #file_flipper { white-space: nowrap; padding-right: 2em; }
 #file_flipper.hidden { display: none; }
 #file_flipper .pagelink { color: #0000CC; text-decoration: underline; }
 #file_flipper #visiblefiles { padding-left: 0.5em; padding-right: 0.5em; }
</style>
<table id="nav_and_rev" class="list"
 cellpadding="0" cellspacing="0" width="100%">
 <tr>
 
 <td nowrap="nowrap" class="src_crumbs src_nav" width="33%">
 <strong class="src_nav">Source path:&nbsp;</strong>
 <span id="crumb_root">
 
 <a href="/p/word2vec/source/browse/">svn</a>/&nbsp;</span>
 <span id="crumb_links" class="ifClosed"><a href="/p/word2vec/source/browse/trunk/">trunk</a><span class="sp">/&nbsp;</span>compute-accuracy.c</span>
 
 


 </td>
 
 
 <td nowrap="nowrap" width="33%" align="right">
 <table cellpadding="0" cellspacing="0" style="font-size: 100%"><tr>
 
 
 <td class="flipper">
 <ul class="leftside">
 
 <li><a href="/p/word2vec/source/browse/trunk/compute-accuracy.c?r=33" title="Previous">&lsaquo;r33</a></li>
 
 </ul>
 </td>
 
 <td class="flipper"><b>r42</b></td>
 
 </tr></table>
 </td> 
 </tr>
</table>

<div class="fc">
 
 
 
<style type="text/css">
.undermouse span {
 background-image: url(https://ssl.gstatic.com/codesite/ph/images/comments.gif); }
</style>
<table class="opened" id="review_comment_area"
><tr>
<td id="nums">
<pre><table width="100%"><tr class="nocursor"><td></td></tr></table></pre>
<pre><table width="100%" id="nums_table_0"><tr id="gr_svn42_1"

><td id="1"><a href="#1">1</a></td></tr
><tr id="gr_svn42_2"

><td id="2"><a href="#2">2</a></td></tr
><tr id="gr_svn42_3"

><td id="3"><a href="#3">3</a></td></tr
><tr id="gr_svn42_4"

><td id="4"><a href="#4">4</a></td></tr
><tr id="gr_svn42_5"

><td id="5"><a href="#5">5</a></td></tr
><tr id="gr_svn42_6"

><td id="6"><a href="#6">6</a></td></tr
><tr id="gr_svn42_7"

><td id="7"><a href="#7">7</a></td></tr
><tr id="gr_svn42_8"

><td id="8"><a href="#8">8</a></td></tr
><tr id="gr_svn42_9"

><td id="9"><a href="#9">9</a></td></tr
><tr id="gr_svn42_10"

><td id="10"><a href="#10">10</a></td></tr
><tr id="gr_svn42_11"

><td id="11"><a href="#11">11</a></td></tr
><tr id="gr_svn42_12"

><td id="12"><a href="#12">12</a></td></tr
><tr id="gr_svn42_13"

><td id="13"><a href="#13">13</a></td></tr
><tr id="gr_svn42_14"

><td id="14"><a href="#14">14</a></td></tr
><tr id="gr_svn42_15"

><td id="15"><a href="#15">15</a></td></tr
><tr id="gr_svn42_16"

><td id="16"><a href="#16">16</a></td></tr
><tr id="gr_svn42_17"

><td id="17"><a href="#17">17</a></td></tr
><tr id="gr_svn42_18"

><td id="18"><a href="#18">18</a></td></tr
><tr id="gr_svn42_19"

><td id="19"><a href="#19">19</a></td></tr
><tr id="gr_svn42_20"

><td id="20"><a href="#20">20</a></td></tr
><tr id="gr_svn42_21"

><td id="21"><a href="#21">21</a></td></tr
><tr id="gr_svn42_22"

><td id="22"><a href="#22">22</a></td></tr
><tr id="gr_svn42_23"

><td id="23"><a href="#23">23</a></td></tr
><tr id="gr_svn42_24"

><td id="24"><a href="#24">24</a></td></tr
><tr id="gr_svn42_25"

><td id="25"><a href="#25">25</a></td></tr
><tr id="gr_svn42_26"

><td id="26"><a href="#26">26</a></td></tr
><tr id="gr_svn42_27"

><td id="27"><a href="#27">27</a></td></tr
><tr id="gr_svn42_28"

><td id="28"><a href="#28">28</a></td></tr
><tr id="gr_svn42_29"

><td id="29"><a href="#29">29</a></td></tr
><tr id="gr_svn42_30"

><td id="30"><a href="#30">30</a></td></tr
><tr id="gr_svn42_31"

><td id="31"><a href="#31">31</a></td></tr
><tr id="gr_svn42_32"

><td id="32"><a href="#32">32</a></td></tr
><tr id="gr_svn42_33"

><td id="33"><a href="#33">33</a></td></tr
><tr id="gr_svn42_34"

><td id="34"><a href="#34">34</a></td></tr
><tr id="gr_svn42_35"

><td id="35"><a href="#35">35</a></td></tr
><tr id="gr_svn42_36"

><td id="36"><a href="#36">36</a></td></tr
><tr id="gr_svn42_37"

><td id="37"><a href="#37">37</a></td></tr
><tr id="gr_svn42_38"

><td id="38"><a href="#38">38</a></td></tr
><tr id="gr_svn42_39"

><td id="39"><a href="#39">39</a></td></tr
><tr id="gr_svn42_40"

><td id="40"><a href="#40">40</a></td></tr
><tr id="gr_svn42_41"

><td id="41"><a href="#41">41</a></td></tr
><tr id="gr_svn42_42"

><td id="42"><a href="#42">42</a></td></tr
><tr id="gr_svn42_43"

><td id="43"><a href="#43">43</a></td></tr
><tr id="gr_svn42_44"

><td id="44"><a href="#44">44</a></td></tr
><tr id="gr_svn42_45"

><td id="45"><a href="#45">45</a></td></tr
><tr id="gr_svn42_46"

><td id="46"><a href="#46">46</a></td></tr
><tr id="gr_svn42_47"

><td id="47"><a href="#47">47</a></td></tr
><tr id="gr_svn42_48"

><td id="48"><a href="#48">48</a></td></tr
><tr id="gr_svn42_49"

><td id="49"><a href="#49">49</a></td></tr
><tr id="gr_svn42_50"

><td id="50"><a href="#50">50</a></td></tr
><tr id="gr_svn42_51"

><td id="51"><a href="#51">51</a></td></tr
><tr id="gr_svn42_52"

><td id="52"><a href="#52">52</a></td></tr
><tr id="gr_svn42_53"

><td id="53"><a href="#53">53</a></td></tr
><tr id="gr_svn42_54"

><td id="54"><a href="#54">54</a></td></tr
><tr id="gr_svn42_55"

><td id="55"><a href="#55">55</a></td></tr
><tr id="gr_svn42_56"

><td id="56"><a href="#56">56</a></td></tr
><tr id="gr_svn42_57"

><td id="57"><a href="#57">57</a></td></tr
><tr id="gr_svn42_58"

><td id="58"><a href="#58">58</a></td></tr
><tr id="gr_svn42_59"

><td id="59"><a href="#59">59</a></td></tr
><tr id="gr_svn42_60"

><td id="60"><a href="#60">60</a></td></tr
><tr id="gr_svn42_61"

><td id="61"><a href="#61">61</a></td></tr
><tr id="gr_svn42_62"

><td id="62"><a href="#62">62</a></td></tr
><tr id="gr_svn42_63"

><td id="63"><a href="#63">63</a></td></tr
><tr id="gr_svn42_64"

><td id="64"><a href="#64">64</a></td></tr
><tr id="gr_svn42_65"

><td id="65"><a href="#65">65</a></td></tr
><tr id="gr_svn42_66"

><td id="66"><a href="#66">66</a></td></tr
><tr id="gr_svn42_67"

><td id="67"><a href="#67">67</a></td></tr
><tr id="gr_svn42_68"

><td id="68"><a href="#68">68</a></td></tr
><tr id="gr_svn42_69"

><td id="69"><a href="#69">69</a></td></tr
><tr id="gr_svn42_70"

><td id="70"><a href="#70">70</a></td></tr
><tr id="gr_svn42_71"

><td id="71"><a href="#71">71</a></td></tr
><tr id="gr_svn42_72"

><td id="72"><a href="#72">72</a></td></tr
><tr id="gr_svn42_73"

><td id="73"><a href="#73">73</a></td></tr
><tr id="gr_svn42_74"

><td id="74"><a href="#74">74</a></td></tr
><tr id="gr_svn42_75"

><td id="75"><a href="#75">75</a></td></tr
><tr id="gr_svn42_76"

><td id="76"><a href="#76">76</a></td></tr
><tr id="gr_svn42_77"

><td id="77"><a href="#77">77</a></td></tr
><tr id="gr_svn42_78"

><td id="78"><a href="#78">78</a></td></tr
><tr id="gr_svn42_79"

><td id="79"><a href="#79">79</a></td></tr
><tr id="gr_svn42_80"

><td id="80"><a href="#80">80</a></td></tr
><tr id="gr_svn42_81"

><td id="81"><a href="#81">81</a></td></tr
><tr id="gr_svn42_82"

><td id="82"><a href="#82">82</a></td></tr
><tr id="gr_svn42_83"

><td id="83"><a href="#83">83</a></td></tr
><tr id="gr_svn42_84"

><td id="84"><a href="#84">84</a></td></tr
><tr id="gr_svn42_85"

><td id="85"><a href="#85">85</a></td></tr
><tr id="gr_svn42_86"

><td id="86"><a href="#86">86</a></td></tr
><tr id="gr_svn42_87"

><td id="87"><a href="#87">87</a></td></tr
><tr id="gr_svn42_88"

><td id="88"><a href="#88">88</a></td></tr
><tr id="gr_svn42_89"

><td id="89"><a href="#89">89</a></td></tr
><tr id="gr_svn42_90"

><td id="90"><a href="#90">90</a></td></tr
><tr id="gr_svn42_91"

><td id="91"><a href="#91">91</a></td></tr
><tr id="gr_svn42_92"

><td id="92"><a href="#92">92</a></td></tr
><tr id="gr_svn42_93"

><td id="93"><a href="#93">93</a></td></tr
><tr id="gr_svn42_94"

><td id="94"><a href="#94">94</a></td></tr
><tr id="gr_svn42_95"

><td id="95"><a href="#95">95</a></td></tr
><tr id="gr_svn42_96"

><td id="96"><a href="#96">96</a></td></tr
><tr id="gr_svn42_97"

><td id="97"><a href="#97">97</a></td></tr
><tr id="gr_svn42_98"

><td id="98"><a href="#98">98</a></td></tr
><tr id="gr_svn42_99"

><td id="99"><a href="#99">99</a></td></tr
><tr id="gr_svn42_100"

><td id="100"><a href="#100">100</a></td></tr
><tr id="gr_svn42_101"

><td id="101"><a href="#101">101</a></td></tr
><tr id="gr_svn42_102"

><td id="102"><a href="#102">102</a></td></tr
><tr id="gr_svn42_103"

><td id="103"><a href="#103">103</a></td></tr
><tr id="gr_svn42_104"

><td id="104"><a href="#104">104</a></td></tr
><tr id="gr_svn42_105"

><td id="105"><a href="#105">105</a></td></tr
><tr id="gr_svn42_106"

><td id="106"><a href="#106">106</a></td></tr
><tr id="gr_svn42_107"

><td id="107"><a href="#107">107</a></td></tr
><tr id="gr_svn42_108"

><td id="108"><a href="#108">108</a></td></tr
><tr id="gr_svn42_109"

><td id="109"><a href="#109">109</a></td></tr
><tr id="gr_svn42_110"

><td id="110"><a href="#110">110</a></td></tr
><tr id="gr_svn42_111"

><td id="111"><a href="#111">111</a></td></tr
><tr id="gr_svn42_112"

><td id="112"><a href="#112">112</a></td></tr
><tr id="gr_svn42_113"

><td id="113"><a href="#113">113</a></td></tr
><tr id="gr_svn42_114"

><td id="114"><a href="#114">114</a></td></tr
><tr id="gr_svn42_115"

><td id="115"><a href="#115">115</a></td></tr
><tr id="gr_svn42_116"

><td id="116"><a href="#116">116</a></td></tr
><tr id="gr_svn42_117"

><td id="117"><a href="#117">117</a></td></tr
><tr id="gr_svn42_118"

><td id="118"><a href="#118">118</a></td></tr
><tr id="gr_svn42_119"

><td id="119"><a href="#119">119</a></td></tr
><tr id="gr_svn42_120"

><td id="120"><a href="#120">120</a></td></tr
><tr id="gr_svn42_121"

><td id="121"><a href="#121">121</a></td></tr
><tr id="gr_svn42_122"

><td id="122"><a href="#122">122</a></td></tr
><tr id="gr_svn42_123"

><td id="123"><a href="#123">123</a></td></tr
><tr id="gr_svn42_124"

><td id="124"><a href="#124">124</a></td></tr
><tr id="gr_svn42_125"

><td id="125"><a href="#125">125</a></td></tr
><tr id="gr_svn42_126"

><td id="126"><a href="#126">126</a></td></tr
><tr id="gr_svn42_127"

><td id="127"><a href="#127">127</a></td></tr
><tr id="gr_svn42_128"

><td id="128"><a href="#128">128</a></td></tr
><tr id="gr_svn42_129"

><td id="129"><a href="#129">129</a></td></tr
><tr id="gr_svn42_130"

><td id="130"><a href="#130">130</a></td></tr
><tr id="gr_svn42_131"

><td id="131"><a href="#131">131</a></td></tr
><tr id="gr_svn42_132"

><td id="132"><a href="#132">132</a></td></tr
><tr id="gr_svn42_133"

><td id="133"><a href="#133">133</a></td></tr
><tr id="gr_svn42_134"

><td id="134"><a href="#134">134</a></td></tr
><tr id="gr_svn42_135"

><td id="135"><a href="#135">135</a></td></tr
><tr id="gr_svn42_136"

><td id="136"><a href="#136">136</a></td></tr
><tr id="gr_svn42_137"

><td id="137"><a href="#137">137</a></td></tr
><tr id="gr_svn42_138"

><td id="138"><a href="#138">138</a></td></tr
><tr id="gr_svn42_139"

><td id="139"><a href="#139">139</a></td></tr
><tr id="gr_svn42_140"

><td id="140"><a href="#140">140</a></td></tr
><tr id="gr_svn42_141"

><td id="141"><a href="#141">141</a></td></tr
><tr id="gr_svn42_142"

><td id="142"><a href="#142">142</a></td></tr
><tr id="gr_svn42_143"

><td id="143"><a href="#143">143</a></td></tr
></table></pre>
<pre><table width="100%"><tr class="nocursor"><td></td></tr></table></pre>
</td>
<td id="lines">
<pre><table width="100%"><tr class="cursor_stop cursor_hidden"><td></td></tr></table></pre>
<pre class="prettyprint lang-c"><table id="src_table_0"><tr
id=sl_svn42_1

><td class="source">//  Copyright 2013 Google Inc. All Rights Reserved.<br></td></tr
><tr
id=sl_svn42_2

><td class="source">//<br></td></tr
><tr
id=sl_svn42_3

><td class="source">//  Licensed under the Apache License, Version 2.0 (the &quot;License&quot;);<br></td></tr
><tr
id=sl_svn42_4

><td class="source">//  you may not use this file except in compliance with the License.<br></td></tr
><tr
id=sl_svn42_5

><td class="source">//  You may obtain a copy of the License at<br></td></tr
><tr
id=sl_svn42_6

><td class="source">//<br></td></tr
><tr
id=sl_svn42_7

><td class="source">//      http://www.apache.org/licenses/LICENSE-2.0<br></td></tr
><tr
id=sl_svn42_8

><td class="source">//<br></td></tr
><tr
id=sl_svn42_9

><td class="source">//  Unless required by applicable law or agreed to in writing, software<br></td></tr
><tr
id=sl_svn42_10

><td class="source">//  distributed under the License is distributed on an &quot;AS IS&quot; BASIS,<br></td></tr
><tr
id=sl_svn42_11

><td class="source">//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.<br></td></tr
><tr
id=sl_svn42_12

><td class="source">//  See the License for the specific language governing permissions and<br></td></tr
><tr
id=sl_svn42_13

><td class="source">//  limitations under the License.<br></td></tr
><tr
id=sl_svn42_14

><td class="source"><br></td></tr
><tr
id=sl_svn42_15

><td class="source">#include &lt;stdio.h&gt;<br></td></tr
><tr
id=sl_svn42_16

><td class="source">#include &lt;stdlib.h&gt;<br></td></tr
><tr
id=sl_svn42_17

><td class="source">#include &lt;string.h&gt;<br></td></tr
><tr
id=sl_svn42_18

><td class="source">#include &lt;math.h&gt;<br></td></tr
><tr
id=sl_svn42_19

><td class="source">#include &lt;malloc.h&gt;<br></td></tr
><tr
id=sl_svn42_20

><td class="source">#include &lt;ctype.h&gt;<br></td></tr
><tr
id=sl_svn42_21

><td class="source"><br></td></tr
><tr
id=sl_svn42_22

><td class="source">const long long max_size = 2000;         // max length of strings<br></td></tr
><tr
id=sl_svn42_23

><td class="source">const long long N = 1;                   // number of closest words<br></td></tr
><tr
id=sl_svn42_24

><td class="source">const long long max_w = 50;              // max length of vocabulary entries<br></td></tr
><tr
id=sl_svn42_25

><td class="source"><br></td></tr
><tr
id=sl_svn42_26

><td class="source">int main(int argc, char **argv)<br></td></tr
><tr
id=sl_svn42_27

><td class="source">{<br></td></tr
><tr
id=sl_svn42_28

><td class="source">  FILE *f;<br></td></tr
><tr
id=sl_svn42_29

><td class="source">  char st1[max_size], st2[max_size], st3[max_size], st4[max_size], bestw[N][max_size], file_name[max_size], ch;<br></td></tr
><tr
id=sl_svn42_30

><td class="source">  float dist, len, bestd[N], vec[max_size];<br></td></tr
><tr
id=sl_svn42_31

><td class="source">  long long words, size, a, b, c, d, b1, b2, b3, threshold = 0;<br></td></tr
><tr
id=sl_svn42_32

><td class="source">  float *M;<br></td></tr
><tr
id=sl_svn42_33

><td class="source">  char *vocab;<br></td></tr
><tr
id=sl_svn42_34

><td class="source">  int TCN, CCN = 0, TACN = 0, CACN = 0, SECN = 0, SYCN = 0, SEAC = 0, SYAC = 0, QID = 0, TQ = 0, TQS = 0;<br></td></tr
><tr
id=sl_svn42_35

><td class="source">  if (argc &lt; 2) {<br></td></tr
><tr
id=sl_svn42_36

><td class="source">    printf(&quot;Usage: ./compute-accuracy &lt;FILE&gt; &lt;threshold&gt;\nwhere FILE contains word projections, and threshold is used to reduce vocabulary of the model for fast approximate evaluation (0 = off, otherwise typical value is 30000)\n&quot;);<br></td></tr
><tr
id=sl_svn42_37

><td class="source">    return 0;<br></td></tr
><tr
id=sl_svn42_38

><td class="source">  }<br></td></tr
><tr
id=sl_svn42_39

><td class="source">  strcpy(file_name, argv[1]);<br></td></tr
><tr
id=sl_svn42_40

><td class="source">  if (argc &gt; 2) threshold = atoi(argv[2]);<br></td></tr
><tr
id=sl_svn42_41

><td class="source">  f = fopen(file_name, &quot;rb&quot;);<br></td></tr
><tr
id=sl_svn42_42

><td class="source">  if (f == NULL) {<br></td></tr
><tr
id=sl_svn42_43

><td class="source">    printf(&quot;Input file not found\n&quot;);<br></td></tr
><tr
id=sl_svn42_44

><td class="source">    return -1;<br></td></tr
><tr
id=sl_svn42_45

><td class="source">  }<br></td></tr
><tr
id=sl_svn42_46

><td class="source">  fscanf(f, &quot;%lld&quot;, &amp;words);<br></td></tr
><tr
id=sl_svn42_47

><td class="source">  if (threshold) if (words &gt; threshold) words = threshold;<br></td></tr
><tr
id=sl_svn42_48

><td class="source">  fscanf(f, &quot;%lld&quot;, &amp;size);<br></td></tr
><tr
id=sl_svn42_49

><td class="source">  vocab = (char *)malloc(words * max_w * sizeof(char));<br></td></tr
><tr
id=sl_svn42_50

><td class="source">  M = (float *)malloc(words * size * sizeof(float));<br></td></tr
><tr
id=sl_svn42_51

><td class="source">  if (M == NULL) {<br></td></tr
><tr
id=sl_svn42_52

><td class="source">    printf(&quot;Cannot allocate memory: %lld MB\n&quot;, words * size * sizeof(float) / 1048576);<br></td></tr
><tr
id=sl_svn42_53

><td class="source">    return -1;<br></td></tr
><tr
id=sl_svn42_54

><td class="source">  }<br></td></tr
><tr
id=sl_svn42_55

><td class="source">  for (b = 0; b &lt; words; b++) {<br></td></tr
><tr
id=sl_svn42_56

><td class="source">    a = 0;<br></td></tr
><tr
id=sl_svn42_57

><td class="source">    while (1) {<br></td></tr
><tr
id=sl_svn42_58

><td class="source">      vocab[b * max_w + a] = fgetc(f);<br></td></tr
><tr
id=sl_svn42_59

><td class="source">      if (feof(f) || (vocab[b * max_w + a] == &#39; &#39;)) break;<br></td></tr
><tr
id=sl_svn42_60

><td class="source">      if ((a &lt; max_w) &amp;&amp; (vocab[b * max_w + a] != &#39;\n&#39;)) a++;<br></td></tr
><tr
id=sl_svn42_61

><td class="source">    }<br></td></tr
><tr
id=sl_svn42_62

><td class="source">    vocab[b * max_w + a] = 0;<br></td></tr
><tr
id=sl_svn42_63

><td class="source">    for (a = 0; a &lt; max_w; a++) vocab[b * max_w + a] = toupper(vocab[b * max_w + a]);<br></td></tr
><tr
id=sl_svn42_64

><td class="source">    for (a = 0; a &lt; size; a++) fread(&amp;M[a + b * size], sizeof(float), 1, f);<br></td></tr
><tr
id=sl_svn42_65

><td class="source">    len = 0;<br></td></tr
><tr
id=sl_svn42_66

><td class="source">    for (a = 0; a &lt; size; a++) len += M[a + b * size] * M[a + b * size];<br></td></tr
><tr
id=sl_svn42_67

><td class="source">    len = sqrt(len);<br></td></tr
><tr
id=sl_svn42_68

><td class="source">    for (a = 0; a &lt; size; a++) M[a + b * size] /= len;<br></td></tr
><tr
id=sl_svn42_69

><td class="source">  }<br></td></tr
><tr
id=sl_svn42_70

><td class="source">  fclose(f);<br></td></tr
><tr
id=sl_svn42_71

><td class="source">  TCN = 0;<br></td></tr
><tr
id=sl_svn42_72

><td class="source">  while (1) {<br></td></tr
><tr
id=sl_svn42_73

><td class="source">    for (a = 0; a &lt; N; a++) bestd[a] = 0;<br></td></tr
><tr
id=sl_svn42_74

><td class="source">    for (a = 0; a &lt; N; a++) bestw[a][0] = 0;<br></td></tr
><tr
id=sl_svn42_75

><td class="source">    scanf(&quot;%s&quot;, st1);<br></td></tr
><tr
id=sl_svn42_76

><td class="source">    for (a = 0; a &lt; strlen(st1); a++) st1[a] = toupper(st1[a]);<br></td></tr
><tr
id=sl_svn42_77

><td class="source">    if ((!strcmp(st1, &quot;:&quot;)) || (!strcmp(st1, &quot;EXIT&quot;)) || feof(stdin)) {<br></td></tr
><tr
id=sl_svn42_78

><td class="source">      if (TCN == 0) TCN = 1;<br></td></tr
><tr
id=sl_svn42_79

><td class="source">      if (QID != 0) {<br></td></tr
><tr
id=sl_svn42_80

><td class="source">        printf(&quot;ACCURACY TOP1: %.2f %%  (%d / %d)\n&quot;, CCN / (float)TCN * 100, CCN, TCN);<br></td></tr
><tr
id=sl_svn42_81

><td class="source">        printf(&quot;Total accuracy: %.2f %%   Semantic accuracy: %.2f %%   Syntactic accuracy: %.2f %% \n&quot;, CACN / (float)TACN * 100, SEAC / (float)SECN * 100, SYAC / (float)SYCN * 100);<br></td></tr
><tr
id=sl_svn42_82

><td class="source">      }<br></td></tr
><tr
id=sl_svn42_83

><td class="source">      QID++;<br></td></tr
><tr
id=sl_svn42_84

><td class="source">      scanf(&quot;%s&quot;, st1);<br></td></tr
><tr
id=sl_svn42_85

><td class="source">      if (feof(stdin)) break;<br></td></tr
><tr
id=sl_svn42_86

><td class="source">      printf(&quot;%s:\n&quot;, st1);<br></td></tr
><tr
id=sl_svn42_87

><td class="source">      TCN = 0;<br></td></tr
><tr
id=sl_svn42_88

><td class="source">      CCN = 0;<br></td></tr
><tr
id=sl_svn42_89

><td class="source">      continue;<br></td></tr
><tr
id=sl_svn42_90

><td class="source">    }<br></td></tr
><tr
id=sl_svn42_91

><td class="source">    if (!strcmp(st1, &quot;EXIT&quot;)) break;<br></td></tr
><tr
id=sl_svn42_92

><td class="source">    scanf(&quot;%s&quot;, st2);<br></td></tr
><tr
id=sl_svn42_93

><td class="source">    for (a = 0; a &lt; strlen(st2); a++) st2[a] = toupper(st2[a]);<br></td></tr
><tr
id=sl_svn42_94

><td class="source">    scanf(&quot;%s&quot;, st3);<br></td></tr
><tr
id=sl_svn42_95

><td class="source">    for (a = 0; a&lt;strlen(st3); a++) st3[a] = toupper(st3[a]);<br></td></tr
><tr
id=sl_svn42_96

><td class="source">    scanf(&quot;%s&quot;, st4);<br></td></tr
><tr
id=sl_svn42_97

><td class="source">    for (a = 0; a &lt; strlen(st4); a++) st4[a] = toupper(st4[a]);<br></td></tr
><tr
id=sl_svn42_98

><td class="source">    for (b = 0; b &lt; words; b++) if (!strcmp(&amp;vocab[b * max_w], st1)) break;<br></td></tr
><tr
id=sl_svn42_99

><td class="source">    b1 = b;<br></td></tr
><tr
id=sl_svn42_100

><td class="source">    for (b = 0; b &lt; words; b++) if (!strcmp(&amp;vocab[b * max_w], st2)) break;<br></td></tr
><tr
id=sl_svn42_101

><td class="source">    b2 = b;<br></td></tr
><tr
id=sl_svn42_102

><td class="source">    for (b = 0; b &lt; words; b++) if (!strcmp(&amp;vocab[b * max_w], st3)) break;<br></td></tr
><tr
id=sl_svn42_103

><td class="source">    b3 = b;<br></td></tr
><tr
id=sl_svn42_104

><td class="source">    for (a = 0; a &lt; N; a++) bestd[a] = 0;<br></td></tr
><tr
id=sl_svn42_105

><td class="source">    for (a = 0; a &lt; N; a++) bestw[a][0] = 0;<br></td></tr
><tr
id=sl_svn42_106

><td class="source">    TQ++;<br></td></tr
><tr
id=sl_svn42_107

><td class="source">    if (b1 == words) continue;<br></td></tr
><tr
id=sl_svn42_108

><td class="source">    if (b2 == words) continue;<br></td></tr
><tr
id=sl_svn42_109

><td class="source">    if (b3 == words) continue;<br></td></tr
><tr
id=sl_svn42_110

><td class="source">    for (b = 0; b &lt; words; b++) if (!strcmp(&amp;vocab[b * max_w], st4)) break;<br></td></tr
><tr
id=sl_svn42_111

><td class="source">    if (b == words) continue;<br></td></tr
><tr
id=sl_svn42_112

><td class="source">    for (a = 0; a &lt; size; a++) vec[a] = (M[a + b2 * size] - M[a + b1 * size]) + M[a + b3 * size];<br></td></tr
><tr
id=sl_svn42_113

><td class="source">    TQS++;<br></td></tr
><tr
id=sl_svn42_114

><td class="source">    for (c = 0; c &lt; words; c++) {<br></td></tr
><tr
id=sl_svn42_115

><td class="source">      if (c == b1) continue;<br></td></tr
><tr
id=sl_svn42_116

><td class="source">      if (c == b2) continue;<br></td></tr
><tr
id=sl_svn42_117

><td class="source">      if (c == b3) continue;<br></td></tr
><tr
id=sl_svn42_118

><td class="source">      dist = 0;<br></td></tr
><tr
id=sl_svn42_119

><td class="source">      for (a = 0; a &lt; size; a++) dist += vec[a] * M[a + c * size];<br></td></tr
><tr
id=sl_svn42_120

><td class="source">      for (a = 0; a &lt; N; a++) {<br></td></tr
><tr
id=sl_svn42_121

><td class="source">        if (dist &gt; bestd[a]) {<br></td></tr
><tr
id=sl_svn42_122

><td class="source">          for (d = N - 1; d &gt; a; d--) {<br></td></tr
><tr
id=sl_svn42_123

><td class="source">            bestd[d] = bestd[d - 1];<br></td></tr
><tr
id=sl_svn42_124

><td class="source">            strcpy(bestw[d], bestw[d - 1]);<br></td></tr
><tr
id=sl_svn42_125

><td class="source">          }<br></td></tr
><tr
id=sl_svn42_126

><td class="source">          bestd[a] = dist;<br></td></tr
><tr
id=sl_svn42_127

><td class="source">          strcpy(bestw[a], &amp;vocab[c * max_w]);<br></td></tr
><tr
id=sl_svn42_128

><td class="source">          break;<br></td></tr
><tr
id=sl_svn42_129

><td class="source">        }<br></td></tr
><tr
id=sl_svn42_130

><td class="source">      }<br></td></tr
><tr
id=sl_svn42_131

><td class="source">    }<br></td></tr
><tr
id=sl_svn42_132

><td class="source">    if (!strcmp(st4, bestw[0])) {<br></td></tr
><tr
id=sl_svn42_133

><td class="source">      CCN++;<br></td></tr
><tr
id=sl_svn42_134

><td class="source">      CACN++;<br></td></tr
><tr
id=sl_svn42_135

><td class="source">      if (QID &lt;= 5) SEAC++; else SYAC++;<br></td></tr
><tr
id=sl_svn42_136

><td class="source">    }<br></td></tr
><tr
id=sl_svn42_137

><td class="source">    if (QID &lt;= 5) SECN++; else SYCN++;<br></td></tr
><tr
id=sl_svn42_138

><td class="source">    TCN++;<br></td></tr
><tr
id=sl_svn42_139

><td class="source">    TACN++;<br></td></tr
><tr
id=sl_svn42_140

><td class="source">  }<br></td></tr
><tr
id=sl_svn42_141

><td class="source">  printf(&quot;Questions seen / total: %d %d   %.2f %% \n&quot;, TQS, TQ, TQS/(float)TQ*100);<br></td></tr
><tr
id=sl_svn42_142

><td class="source">  return 0;<br></td></tr
><tr
id=sl_svn42_143

><td class="source">}<br></td></tr
></table></pre>
<pre><table width="100%"><tr class="cursor_stop cursor_hidden"><td></td></tr></table></pre>
</td>
</tr></table>

 
<script type="text/javascript">
 var lineNumUnderMouse = -1;
 
 function gutterOver(num) {
 gutterOut();
 var newTR = document.getElementById('gr_svn42_' + num);
 if (newTR) {
 newTR.className = 'undermouse';
 }
 lineNumUnderMouse = num;
 }
 function gutterOut() {
 if (lineNumUnderMouse != -1) {
 var oldTR = document.getElementById(
 'gr_svn42_' + lineNumUnderMouse);
 if (oldTR) {
 oldTR.className = '';
 }
 lineNumUnderMouse = -1;
 }
 }
 var numsGenState = {table_base_id: 'nums_table_'};
 var srcGenState = {table_base_id: 'src_table_'};
 var alignerRunning = false;
 var startOver = false;
 function setLineNumberHeights() {
 if (alignerRunning) {
 startOver = true;
 return;
 }
 numsGenState.chunk_id = 0;
 numsGenState.table = document.getElementById('nums_table_0');
 numsGenState.row_num = 0;
 if (!numsGenState.table) {
 return; // Silently exit if no file is present.
 }
 srcGenState.chunk_id = 0;
 srcGenState.table = document.getElementById('src_table_0');
 srcGenState.row_num = 0;
 alignerRunning = true;
 continueToSetLineNumberHeights();
 }
 function rowGenerator(genState) {
 if (genState.row_num < genState.table.rows.length) {
 var currentRow = genState.table.rows[genState.row_num];
 genState.row_num++;
 return currentRow;
 }
 var newTable = document.getElementById(
 genState.table_base_id + (genState.chunk_id + 1));
 if (newTable) {
 genState.chunk_id++;
 genState.row_num = 0;
 genState.table = newTable;
 return genState.table.rows[0];
 }
 return null;
 }
 var MAX_ROWS_PER_PASS = 1000;
 function continueToSetLineNumberHeights() {
 var rowsInThisPass = 0;
 var numRow = 1;
 var srcRow = 1;
 while (numRow && srcRow && rowsInThisPass < MAX_ROWS_PER_PASS) {
 numRow = rowGenerator(numsGenState);
 srcRow = rowGenerator(srcGenState);
 rowsInThisPass++;
 if (numRow && srcRow) {
 if (numRow.offsetHeight != srcRow.offsetHeight) {
 numRow.firstChild.style.height = srcRow.offsetHeight + 'px';
 }
 }
 }
 if (rowsInThisPass >= MAX_ROWS_PER_PASS) {
 setTimeout(continueToSetLineNumberHeights, 10);
 } else {
 alignerRunning = false;
 if (startOver) {
 startOver = false;
 setTimeout(setLineNumberHeights, 500);
 }
 }
 }
 function initLineNumberHeights() {
 // Do 2 complete passes, because there can be races
 // between this code and prettify.
 startOver = true;
 setTimeout(setLineNumberHeights, 250);
 window.onresize = setLineNumberHeights;
 }
 initLineNumberHeights();
</script>

 
 
 <div id="log">
 <div style="text-align:right">
 <a class="ifCollapse" href="#" onclick="_toggleMeta(this); return false">Show details</a>
 <a class="ifExpand" href="#" onclick="_toggleMeta(this); return false">Hide details</a>
 </div>
 <div class="ifExpand">
 
 
 <div class="pmeta_bubble_bg" style="border:1px solid white">
 <div class="round4"></div>
 <div class="round2"></div>
 <div class="round1"></div>
 <div class="box-inner">
 <div id="changelog">
 <p>Change log</p>
 <div>
 <a href="/p/word2vec/source/detail?spec=svn42&amp;r=39">r39</a>
 by tmikolov
 on Sep 8, 2014
 &nbsp; <a href="/p/word2vec/source/diff?spec=svn42&r=39&amp;format=side&amp;path=/trunk/compute-accuracy.c&amp;old_path=/trunk/compute-accuracy.c&amp;old=33">Diff</a>
 </div>
 <pre>fixed minor bugs</pre>
 </div>
 
 
 
 
 
 
 <script type="text/javascript">
 var detail_url = '/p/word2vec/source/detail?r=39&spec=svn42';
 var publish_url = '/p/word2vec/source/detail?r=39&spec=svn42#publish';
 // describe the paths of this revision in javascript.
 var changed_paths = [];
 var changed_urls = [];
 
 changed_paths.push('/trunk/compute-accuracy.c');
 changed_urls.push('/p/word2vec/source/browse/trunk/compute-accuracy.c?r\x3d39\x26spec\x3dsvn42');
 
 var selected_path = '/trunk/compute-accuracy.c';
 
 
 changed_paths.push('/trunk/distance.c');
 changed_urls.push('/p/word2vec/source/browse/trunk/distance.c?r\x3d39\x26spec\x3dsvn42');
 
 
 changed_paths.push('/trunk/word-analogy.c');
 changed_urls.push('/p/word2vec/source/browse/trunk/word-analogy.c?r\x3d39\x26spec\x3dsvn42');
 
 
 changed_paths.push('/trunk/word2vec.c');
 changed_urls.push('/p/word2vec/source/browse/trunk/word2vec.c?r\x3d39\x26spec\x3dsvn42');
 
 
 function getCurrentPageIndex() {
 for (var i = 0; i < changed_paths.length; i++) {
 if (selected_path == changed_paths[i]) {
 return i;
 }
 }
 }
 function getNextPage() {
 var i = getCurrentPageIndex();
 if (i < changed_paths.length - 1) {
 return changed_urls[i + 1];
 }
 return null;
 }
 function getPreviousPage() {
 var i = getCurrentPageIndex();
 if (i > 0) {
 return changed_urls[i - 1];
 }
 return null;
 }
 function gotoNextPage() {
 var page = getNextPage();
 if (!page) {
 page = detail_url;
 }
 window.location = page;
 }
 function gotoPreviousPage() {
 var page = getPreviousPage();
 if (!page) {
 page = detail_url;
 }
 window.location = page;
 }
 function gotoDetailPage() {
 window.location = detail_url;
 }
 function gotoPublishPage() {
 window.location = publish_url;
 }
</script>

 
 <style type="text/css">
 #review_nav {
 border-top: 3px solid white;
 padding-top: 6px;
 margin-top: 1em;
 }
 #review_nav td {
 vertical-align: middle;
 }
 #review_nav select {
 margin: .5em 0;
 }
 </style>
 <div id="review_nav">
 <table><tr><td>Go to:&nbsp;</td><td>
 <select name="files_in_rev" onchange="window.location=this.value">
 
 <option value="/p/word2vec/source/browse/trunk/compute-accuracy.c?r=39&amp;spec=svn42"
 selected="selected"
 >/trunk/compute-accuracy.c</option>
 
 <option value="/p/word2vec/source/browse/trunk/distance.c?r=39&amp;spec=svn42"
 
 >/trunk/distance.c</option>
 
 <option value="/p/word2vec/source/browse/trunk/word-analogy.c?r=39&amp;spec=svn42"
 
 >/trunk/word-analogy.c</option>
 
 <option value="/p/word2vec/source/browse/trunk/word2vec.c?r=39&amp;spec=svn42"
 
 >/trunk/word2vec.c</option>
 
 </select>
 </td></tr></table>
 
 
 



 <div style="white-space:nowrap">
 Project members,
 <a href="https://www.google.com/accounts/ServiceLogin?service=code&amp;ltmpl=phosting&amp;continue=https%3A%2F%2Fcode.google.com%2Fp%2Fword2vec%2Fsource%2Fbrowse%2Ftrunk%2Fcompute-accuracy.c&amp;followup=https%3A%2F%2Fcode.google.com%2Fp%2Fword2vec%2Fsource%2Fbrowse%2Ftrunk%2Fcompute-accuracy.c"
 >sign in</a> to write a code review</div>


 
 </div>
 
 
 </div>
 <div class="round1"></div>
 <div class="round2"></div>
 <div class="round4"></div>
 </div>
 <div class="pmeta_bubble_bg" style="border:1px solid white">
 <div class="round4"></div>
 <div class="round2"></div>
 <div class="round1"></div>
 <div class="box-inner">
 <div id="older_bubble">
 <p>Older revisions</p>
 
 
 <div class="closed" style="margin-bottom:3px;" >
 <a class="ifClosed" onclick="return _toggleHidden(this)"><img src="https://ssl.gstatic.com/codesite/ph/images/plus.gif" ></a>
 <a class="ifOpened" onclick="return _toggleHidden(this)"><img src="https://ssl.gstatic.com/codesite/ph/images/minus.gif" ></a>
 <a href="/p/word2vec/source/detail?spec=svn42&r=33">r33</a>
 by tmiko...@google.com
 on Aug 22, 2013
 &nbsp; <a href="/p/word2vec/source/diff?spec=svn42&r=33&amp;format=side&amp;path=/trunk/compute-accuracy.c&amp;old_path=/trunk/compute-accuracy.c&amp;old=27">Diff</a>
 <br>
 <pre class="ifOpened">bugfix - the vector computation was
done before check for out-of-
vocabulary words was performed, which
resulted in accessing memory outside
of the allocated block
</pre>
 </div>
 
 <div class="closed" style="margin-bottom:3px;" >
 <a class="ifClosed" onclick="return _toggleHidden(this)"><img src="https://ssl.gstatic.com/codesite/ph/images/plus.gif" ></a>
 <a class="ifOpened" onclick="return _toggleHidden(this)"><img src="https://ssl.gstatic.com/codesite/ph/images/minus.gif" ></a>
 <a href="/p/word2vec/source/detail?spec=svn42&r=27">r27</a>
 by tmiko...@google.com
 on Aug 1, 2013
 &nbsp; <a href="/p/word2vec/source/diff?spec=svn42&r=27&amp;format=side&amp;path=/trunk/compute-accuracy.c&amp;old_path=/trunk/compute-accuracy.c&amp;old=">Diff</a>
 <br>
 <pre class="ifOpened">aa</pre>
 </div>
 
 
 <a href="/p/word2vec/source/list?path=/trunk/compute-accuracy.c&start=39">All revisions of this file</a>
 </div>
 </div>
 <div class="round1"></div>
 <div class="round2"></div>
 <div class="round4"></div>
 </div>
 
 <div class="pmeta_bubble_bg" style="border:1px solid white">
 <div class="round4"></div>
 <div class="round2"></div>
 <div class="round1"></div>
 <div class="box-inner">
 <div id="fileinfo_bubble">
 <p>File info</p>
 
 <div>Size: 5241 bytes,
 143 lines</div>
 
 <div><a href="//word2vec.googlecode.com/svn/trunk/compute-accuracy.c">View raw file</a></div>
 </div>
 
 </div>
 <div class="round1"></div>
 <div class="round2"></div>
 <div class="round4"></div>
 </div>
 </div>
 </div>


</div>

</div>
</div>

<script src="https://ssl.gstatic.com/codesite/ph/8599073060794244502/js/prettify/prettify.js"></script>
<script type="text/javascript">prettyPrint();</script>


<script src="https://ssl.gstatic.com/codesite/ph/8599073060794244502/js/source_file_scripts.js"></script>

 <script type="text/javascript" src="https://ssl.gstatic.com/codesite/ph/8599073060794244502/js/kibbles.js"></script>
 <script type="text/javascript">
 var lastStop = null;
 var initialized = false;
 
 function updateCursor(next, prev) {
 if (prev && prev.element) {
 prev.element.className = 'cursor_stop cursor_hidden';
 }
 if (next && next.element) {
 next.element.className = 'cursor_stop cursor';
 lastStop = next.index;
 }
 }
 
 function pubRevealed(data) {
 updateCursorForCell(data.cellId, 'cursor_stop cursor_hidden');
 if (initialized) {
 reloadCursors();
 }
 }
 
 function draftRevealed(data) {
 updateCursorForCell(data.cellId, 'cursor_stop cursor_hidden');
 if (initialized) {
 reloadCursors();
 }
 }
 
 function draftDestroyed(data) {
 updateCursorForCell(data.cellId, 'nocursor');
 if (initialized) {
 reloadCursors();
 }
 }
 function reloadCursors() {
 kibbles.skipper.reset();
 loadCursors();
 if (lastStop != null) {
 kibbles.skipper.setCurrentStop(lastStop);
 }
 }
 // possibly the simplest way to insert any newly added comments
 // is to update the class of the corresponding cursor row,
 // then refresh the entire list of rows.
 function updateCursorForCell(cellId, className) {
 var cell = document.getElementById(cellId);
 // we have to go two rows back to find the cursor location
 var row = getPreviousElement(cell.parentNode);
 row.className = className;
 }
 // returns the previous element, ignores text nodes.
 function getPreviousElement(e) {
 var element = e.previousSibling;
 if (element.nodeType == 3) {
 element = element.previousSibling;
 }
 if (element && element.tagName) {
 return element;
 }
 }
 function loadCursors() {
 // register our elements with skipper
 var elements = CR_getElements('*', 'cursor_stop');
 var len = elements.length;
 for (var i = 0; i < len; i++) {
 var element = elements[i]; 
 element.className = 'cursor_stop cursor_hidden';
 kibbles.skipper.append(element);
 }
 }
 function toggleComments() {
 CR_toggleCommentDisplay();
 reloadCursors();
 }
 function keysOnLoadHandler() {
 // setup skipper
 kibbles.skipper.addStopListener(
 kibbles.skipper.LISTENER_TYPE.PRE, updateCursor);
 // Set the 'offset' option to return the middle of the client area
 // an option can be a static value, or a callback
 kibbles.skipper.setOption('padding_top', 50);
 // Set the 'offset' option to return the middle of the client area
 // an option can be a static value, or a callback
 kibbles.skipper.setOption('padding_bottom', 100);
 // Register our keys
 kibbles.skipper.addFwdKey("n");
 kibbles.skipper.addRevKey("p");
 kibbles.keys.addKeyPressListener(
 'u', function() { window.location = detail_url; });
 kibbles.keys.addKeyPressListener(
 'r', function() { window.location = detail_url + '#publish'; });
 
 kibbles.keys.addKeyPressListener('j', gotoNextPage);
 kibbles.keys.addKeyPressListener('k', gotoPreviousPage);
 
 
 }
 </script>
<script src="https://ssl.gstatic.com/codesite/ph/8599073060794244502/js/code_review_scripts.js"></script>
<script type="text/javascript">
 function showPublishInstructions() {
 var element = document.getElementById('review_instr');
 if (element) {
 element.className = 'opened';
 }
 }
 var codereviews;
 function revsOnLoadHandler() {
 // register our source container with the commenting code
 var paths = {'svn42': '/trunk/compute-accuracy.c'}
 codereviews = CR_controller.setup(
 {"token": null, "relativeBaseUrl": "", "assetVersionPath": "https://ssl.gstatic.com/codesite/ph/8599073060794244502", "domainName": null, "assetHostPath": "https://ssl.gstatic.com/codesite/ph", "projectName": "word2vec", "loggedInUserEmail": null, "projectHomeUrl": "/p/word2vec", "profileUrl": null}, '', 'svn42', paths,
 CR_BrowseIntegrationFactory);
 
 codereviews.registerActivityListener(CR_ActivityType.REVEAL_DRAFT_PLATE, showPublishInstructions);
 
 codereviews.registerActivityListener(CR_ActivityType.REVEAL_PUB_PLATE, pubRevealed);
 codereviews.registerActivityListener(CR_ActivityType.REVEAL_DRAFT_PLATE, draftRevealed);
 codereviews.registerActivityListener(CR_ActivityType.DISCARD_DRAFT_COMMENT, draftDestroyed);
 
 
 
 
 
 
 
 var initialized = true;
 reloadCursors();
 }
 window.onload = function() {keysOnLoadHandler(); revsOnLoadHandler();};

</script>
<script type="text/javascript" src="https://ssl.gstatic.com/codesite/ph/8599073060794244502/js/dit_scripts.js"></script>

 
 
 
 <script type="text/javascript" src="https://ssl.gstatic.com/codesite/ph/8599073060794244502/js/ph_core.js"></script>
 
 
 
 
</div> 

<div id="footer" dir="ltr">
 <div class="text">
 <a href="/projecthosting/terms.html">Terms</a> -
 <a href="http://www.google.com/privacy.html">Privacy</a> -
 <a href="/p/support/">Project Hosting Help</a>
 </div>
</div>
 <div class="hostedBy" style="margin-top: -20px;">
 <span style="vertical-align: top;">Powered by <a href="http://code.google.com/projecthosting/">Google Project Hosting</a></span>
 </div>

 
 


 
 </body>
</html>

