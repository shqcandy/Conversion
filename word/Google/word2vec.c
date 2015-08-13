



<!DOCTYPE html>
<html>
<head>
 <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" >
 <meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1" >
 
 <meta name="ROBOTS" content="NOARCHIVE">
 
 <link rel="icon" type="image/vnd.microsoft.icon" href="https://ssl.gstatic.com/codesite/ph/images/phosting.ico">
 
 
 <script type="text/javascript">
 
 (function(){(function(){function c(a){this.t={};this.tick=function(a,b,c){b=void 0!=c?c:(new Date).getTime();this.t[a]=b;if(void 0==c)try{window.console.timeStamp("CSI/"+a)}catch(d){}};this.tick("start",null,a)}var a;window.performance&&(a=window.performance.timing);var b=a?new c(a.responseStart):new c;window.jstiming={Timer:c,load:b};a&&(b=a.navigationStart,a=a.responseStart,0<b&&a>=b&&(window.jstiming.srt=a-b));try{a=null,window.chrome&&window.chrome.csi&&(a=Math.floor(window.chrome.csi().pageT)),null==a&&
window.gtbExternal&&(a=window.gtbExternal.pageT()),null==a&&window.external&&(a=window.external.pageT),a&&(window.jstiming.pt=a)}catch(d){}})();})();

 
 
 
 
 var codesite_token = null;
 
 
 var CS_env = {"projectHomeUrl": "/p/word2vec", "relativeBaseUrl": "", "assetHostPath": "https://ssl.gstatic.com/codesite/ph", "loggedInUserEmail": null, "profileUrl": null, "assetVersionPath": "https://ssl.gstatic.com/codesite/ph/8599073060794244502", "domainName": null, "projectName": "word2vec", "token": null};
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
 
 
 <title>word2vec.c - 
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
 | <a href="https://www.google.com/accounts/ServiceLogin?service=code&amp;ltmpl=phosting&amp;continue=https%3A%2F%2Fcode.google.com%2Fp%2Fword2vec%2Fsource%2Fbrowse%2Ftrunk%2Fword2vec.c&amp;followup=https%3A%2F%2Fcode.google.com%2Fp%2Fword2vec%2Fsource%2Fbrowse%2Ftrunk%2Fword2vec.c" onclick="_CS_click('/gb/ph/signin');"><u>Sign in</u></a>
 
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
 <span id="crumb_links" class="ifClosed"><a href="/p/word2vec/source/browse/trunk/">trunk</a><span class="sp">/&nbsp;</span>word2vec.c</span>
 
 


 </td>
 
 
 <td nowrap="nowrap" width="33%" align="right">
 <table cellpadding="0" cellspacing="0" style="font-size: 100%"><tr>
 
 
 <td class="flipper">
 <ul class="leftside">
 
 <li><a href="/p/word2vec/source/browse/trunk/word2vec.c?r=39" title="Previous">&lsaquo;r39</a></li>
 
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
><tr id="gr_svn42_144"

><td id="144"><a href="#144">144</a></td></tr
><tr id="gr_svn42_145"

><td id="145"><a href="#145">145</a></td></tr
><tr id="gr_svn42_146"

><td id="146"><a href="#146">146</a></td></tr
><tr id="gr_svn42_147"

><td id="147"><a href="#147">147</a></td></tr
><tr id="gr_svn42_148"

><td id="148"><a href="#148">148</a></td></tr
><tr id="gr_svn42_149"

><td id="149"><a href="#149">149</a></td></tr
><tr id="gr_svn42_150"

><td id="150"><a href="#150">150</a></td></tr
><tr id="gr_svn42_151"

><td id="151"><a href="#151">151</a></td></tr
><tr id="gr_svn42_152"

><td id="152"><a href="#152">152</a></td></tr
><tr id="gr_svn42_153"

><td id="153"><a href="#153">153</a></td></tr
><tr id="gr_svn42_154"

><td id="154"><a href="#154">154</a></td></tr
><tr id="gr_svn42_155"

><td id="155"><a href="#155">155</a></td></tr
><tr id="gr_svn42_156"

><td id="156"><a href="#156">156</a></td></tr
><tr id="gr_svn42_157"

><td id="157"><a href="#157">157</a></td></tr
><tr id="gr_svn42_158"

><td id="158"><a href="#158">158</a></td></tr
><tr id="gr_svn42_159"

><td id="159"><a href="#159">159</a></td></tr
><tr id="gr_svn42_160"

><td id="160"><a href="#160">160</a></td></tr
><tr id="gr_svn42_161"

><td id="161"><a href="#161">161</a></td></tr
><tr id="gr_svn42_162"

><td id="162"><a href="#162">162</a></td></tr
><tr id="gr_svn42_163"

><td id="163"><a href="#163">163</a></td></tr
><tr id="gr_svn42_164"

><td id="164"><a href="#164">164</a></td></tr
><tr id="gr_svn42_165"

><td id="165"><a href="#165">165</a></td></tr
><tr id="gr_svn42_166"

><td id="166"><a href="#166">166</a></td></tr
><tr id="gr_svn42_167"

><td id="167"><a href="#167">167</a></td></tr
><tr id="gr_svn42_168"

><td id="168"><a href="#168">168</a></td></tr
><tr id="gr_svn42_169"

><td id="169"><a href="#169">169</a></td></tr
><tr id="gr_svn42_170"

><td id="170"><a href="#170">170</a></td></tr
><tr id="gr_svn42_171"

><td id="171"><a href="#171">171</a></td></tr
><tr id="gr_svn42_172"

><td id="172"><a href="#172">172</a></td></tr
><tr id="gr_svn42_173"

><td id="173"><a href="#173">173</a></td></tr
><tr id="gr_svn42_174"

><td id="174"><a href="#174">174</a></td></tr
><tr id="gr_svn42_175"

><td id="175"><a href="#175">175</a></td></tr
><tr id="gr_svn42_176"

><td id="176"><a href="#176">176</a></td></tr
><tr id="gr_svn42_177"

><td id="177"><a href="#177">177</a></td></tr
><tr id="gr_svn42_178"

><td id="178"><a href="#178">178</a></td></tr
><tr id="gr_svn42_179"

><td id="179"><a href="#179">179</a></td></tr
><tr id="gr_svn42_180"

><td id="180"><a href="#180">180</a></td></tr
><tr id="gr_svn42_181"

><td id="181"><a href="#181">181</a></td></tr
><tr id="gr_svn42_182"

><td id="182"><a href="#182">182</a></td></tr
><tr id="gr_svn42_183"

><td id="183"><a href="#183">183</a></td></tr
><tr id="gr_svn42_184"

><td id="184"><a href="#184">184</a></td></tr
><tr id="gr_svn42_185"

><td id="185"><a href="#185">185</a></td></tr
><tr id="gr_svn42_186"

><td id="186"><a href="#186">186</a></td></tr
><tr id="gr_svn42_187"

><td id="187"><a href="#187">187</a></td></tr
><tr id="gr_svn42_188"

><td id="188"><a href="#188">188</a></td></tr
><tr id="gr_svn42_189"

><td id="189"><a href="#189">189</a></td></tr
><tr id="gr_svn42_190"

><td id="190"><a href="#190">190</a></td></tr
><tr id="gr_svn42_191"

><td id="191"><a href="#191">191</a></td></tr
><tr id="gr_svn42_192"

><td id="192"><a href="#192">192</a></td></tr
><tr id="gr_svn42_193"

><td id="193"><a href="#193">193</a></td></tr
><tr id="gr_svn42_194"

><td id="194"><a href="#194">194</a></td></tr
><tr id="gr_svn42_195"

><td id="195"><a href="#195">195</a></td></tr
><tr id="gr_svn42_196"

><td id="196"><a href="#196">196</a></td></tr
><tr id="gr_svn42_197"

><td id="197"><a href="#197">197</a></td></tr
><tr id="gr_svn42_198"

><td id="198"><a href="#198">198</a></td></tr
><tr id="gr_svn42_199"

><td id="199"><a href="#199">199</a></td></tr
><tr id="gr_svn42_200"

><td id="200"><a href="#200">200</a></td></tr
><tr id="gr_svn42_201"

><td id="201"><a href="#201">201</a></td></tr
><tr id="gr_svn42_202"

><td id="202"><a href="#202">202</a></td></tr
><tr id="gr_svn42_203"

><td id="203"><a href="#203">203</a></td></tr
><tr id="gr_svn42_204"

><td id="204"><a href="#204">204</a></td></tr
><tr id="gr_svn42_205"

><td id="205"><a href="#205">205</a></td></tr
><tr id="gr_svn42_206"

><td id="206"><a href="#206">206</a></td></tr
><tr id="gr_svn42_207"

><td id="207"><a href="#207">207</a></td></tr
><tr id="gr_svn42_208"

><td id="208"><a href="#208">208</a></td></tr
><tr id="gr_svn42_209"

><td id="209"><a href="#209">209</a></td></tr
><tr id="gr_svn42_210"

><td id="210"><a href="#210">210</a></td></tr
><tr id="gr_svn42_211"

><td id="211"><a href="#211">211</a></td></tr
><tr id="gr_svn42_212"

><td id="212"><a href="#212">212</a></td></tr
><tr id="gr_svn42_213"

><td id="213"><a href="#213">213</a></td></tr
><tr id="gr_svn42_214"

><td id="214"><a href="#214">214</a></td></tr
><tr id="gr_svn42_215"

><td id="215"><a href="#215">215</a></td></tr
><tr id="gr_svn42_216"

><td id="216"><a href="#216">216</a></td></tr
><tr id="gr_svn42_217"

><td id="217"><a href="#217">217</a></td></tr
><tr id="gr_svn42_218"

><td id="218"><a href="#218">218</a></td></tr
><tr id="gr_svn42_219"

><td id="219"><a href="#219">219</a></td></tr
><tr id="gr_svn42_220"

><td id="220"><a href="#220">220</a></td></tr
><tr id="gr_svn42_221"

><td id="221"><a href="#221">221</a></td></tr
><tr id="gr_svn42_222"

><td id="222"><a href="#222">222</a></td></tr
><tr id="gr_svn42_223"

><td id="223"><a href="#223">223</a></td></tr
><tr id="gr_svn42_224"

><td id="224"><a href="#224">224</a></td></tr
><tr id="gr_svn42_225"

><td id="225"><a href="#225">225</a></td></tr
><tr id="gr_svn42_226"

><td id="226"><a href="#226">226</a></td></tr
><tr id="gr_svn42_227"

><td id="227"><a href="#227">227</a></td></tr
><tr id="gr_svn42_228"

><td id="228"><a href="#228">228</a></td></tr
><tr id="gr_svn42_229"

><td id="229"><a href="#229">229</a></td></tr
><tr id="gr_svn42_230"

><td id="230"><a href="#230">230</a></td></tr
><tr id="gr_svn42_231"

><td id="231"><a href="#231">231</a></td></tr
><tr id="gr_svn42_232"

><td id="232"><a href="#232">232</a></td></tr
><tr id="gr_svn42_233"

><td id="233"><a href="#233">233</a></td></tr
><tr id="gr_svn42_234"

><td id="234"><a href="#234">234</a></td></tr
><tr id="gr_svn42_235"

><td id="235"><a href="#235">235</a></td></tr
><tr id="gr_svn42_236"

><td id="236"><a href="#236">236</a></td></tr
><tr id="gr_svn42_237"

><td id="237"><a href="#237">237</a></td></tr
><tr id="gr_svn42_238"

><td id="238"><a href="#238">238</a></td></tr
><tr id="gr_svn42_239"

><td id="239"><a href="#239">239</a></td></tr
><tr id="gr_svn42_240"

><td id="240"><a href="#240">240</a></td></tr
><tr id="gr_svn42_241"

><td id="241"><a href="#241">241</a></td></tr
><tr id="gr_svn42_242"

><td id="242"><a href="#242">242</a></td></tr
><tr id="gr_svn42_243"

><td id="243"><a href="#243">243</a></td></tr
><tr id="gr_svn42_244"

><td id="244"><a href="#244">244</a></td></tr
><tr id="gr_svn42_245"

><td id="245"><a href="#245">245</a></td></tr
><tr id="gr_svn42_246"

><td id="246"><a href="#246">246</a></td></tr
><tr id="gr_svn42_247"

><td id="247"><a href="#247">247</a></td></tr
><tr id="gr_svn42_248"

><td id="248"><a href="#248">248</a></td></tr
><tr id="gr_svn42_249"

><td id="249"><a href="#249">249</a></td></tr
><tr id="gr_svn42_250"

><td id="250"><a href="#250">250</a></td></tr
><tr id="gr_svn42_251"

><td id="251"><a href="#251">251</a></td></tr
><tr id="gr_svn42_252"

><td id="252"><a href="#252">252</a></td></tr
><tr id="gr_svn42_253"

><td id="253"><a href="#253">253</a></td></tr
><tr id="gr_svn42_254"

><td id="254"><a href="#254">254</a></td></tr
><tr id="gr_svn42_255"

><td id="255"><a href="#255">255</a></td></tr
><tr id="gr_svn42_256"

><td id="256"><a href="#256">256</a></td></tr
><tr id="gr_svn42_257"

><td id="257"><a href="#257">257</a></td></tr
><tr id="gr_svn42_258"

><td id="258"><a href="#258">258</a></td></tr
><tr id="gr_svn42_259"

><td id="259"><a href="#259">259</a></td></tr
><tr id="gr_svn42_260"

><td id="260"><a href="#260">260</a></td></tr
><tr id="gr_svn42_261"

><td id="261"><a href="#261">261</a></td></tr
><tr id="gr_svn42_262"

><td id="262"><a href="#262">262</a></td></tr
><tr id="gr_svn42_263"

><td id="263"><a href="#263">263</a></td></tr
><tr id="gr_svn42_264"

><td id="264"><a href="#264">264</a></td></tr
><tr id="gr_svn42_265"

><td id="265"><a href="#265">265</a></td></tr
><tr id="gr_svn42_266"

><td id="266"><a href="#266">266</a></td></tr
><tr id="gr_svn42_267"

><td id="267"><a href="#267">267</a></td></tr
><tr id="gr_svn42_268"

><td id="268"><a href="#268">268</a></td></tr
><tr id="gr_svn42_269"

><td id="269"><a href="#269">269</a></td></tr
><tr id="gr_svn42_270"

><td id="270"><a href="#270">270</a></td></tr
><tr id="gr_svn42_271"

><td id="271"><a href="#271">271</a></td></tr
><tr id="gr_svn42_272"

><td id="272"><a href="#272">272</a></td></tr
><tr id="gr_svn42_273"

><td id="273"><a href="#273">273</a></td></tr
><tr id="gr_svn42_274"

><td id="274"><a href="#274">274</a></td></tr
><tr id="gr_svn42_275"

><td id="275"><a href="#275">275</a></td></tr
><tr id="gr_svn42_276"

><td id="276"><a href="#276">276</a></td></tr
><tr id="gr_svn42_277"

><td id="277"><a href="#277">277</a></td></tr
><tr id="gr_svn42_278"

><td id="278"><a href="#278">278</a></td></tr
><tr id="gr_svn42_279"

><td id="279"><a href="#279">279</a></td></tr
><tr id="gr_svn42_280"

><td id="280"><a href="#280">280</a></td></tr
><tr id="gr_svn42_281"

><td id="281"><a href="#281">281</a></td></tr
><tr id="gr_svn42_282"

><td id="282"><a href="#282">282</a></td></tr
><tr id="gr_svn42_283"

><td id="283"><a href="#283">283</a></td></tr
><tr id="gr_svn42_284"

><td id="284"><a href="#284">284</a></td></tr
><tr id="gr_svn42_285"

><td id="285"><a href="#285">285</a></td></tr
><tr id="gr_svn42_286"

><td id="286"><a href="#286">286</a></td></tr
><tr id="gr_svn42_287"

><td id="287"><a href="#287">287</a></td></tr
><tr id="gr_svn42_288"

><td id="288"><a href="#288">288</a></td></tr
><tr id="gr_svn42_289"

><td id="289"><a href="#289">289</a></td></tr
><tr id="gr_svn42_290"

><td id="290"><a href="#290">290</a></td></tr
><tr id="gr_svn42_291"

><td id="291"><a href="#291">291</a></td></tr
><tr id="gr_svn42_292"

><td id="292"><a href="#292">292</a></td></tr
><tr id="gr_svn42_293"

><td id="293"><a href="#293">293</a></td></tr
><tr id="gr_svn42_294"

><td id="294"><a href="#294">294</a></td></tr
><tr id="gr_svn42_295"

><td id="295"><a href="#295">295</a></td></tr
><tr id="gr_svn42_296"

><td id="296"><a href="#296">296</a></td></tr
><tr id="gr_svn42_297"

><td id="297"><a href="#297">297</a></td></tr
><tr id="gr_svn42_298"

><td id="298"><a href="#298">298</a></td></tr
><tr id="gr_svn42_299"

><td id="299"><a href="#299">299</a></td></tr
><tr id="gr_svn42_300"

><td id="300"><a href="#300">300</a></td></tr
><tr id="gr_svn42_301"

><td id="301"><a href="#301">301</a></td></tr
><tr id="gr_svn42_302"

><td id="302"><a href="#302">302</a></td></tr
><tr id="gr_svn42_303"

><td id="303"><a href="#303">303</a></td></tr
><tr id="gr_svn42_304"

><td id="304"><a href="#304">304</a></td></tr
><tr id="gr_svn42_305"

><td id="305"><a href="#305">305</a></td></tr
><tr id="gr_svn42_306"

><td id="306"><a href="#306">306</a></td></tr
><tr id="gr_svn42_307"

><td id="307"><a href="#307">307</a></td></tr
><tr id="gr_svn42_308"

><td id="308"><a href="#308">308</a></td></tr
><tr id="gr_svn42_309"

><td id="309"><a href="#309">309</a></td></tr
><tr id="gr_svn42_310"

><td id="310"><a href="#310">310</a></td></tr
><tr id="gr_svn42_311"

><td id="311"><a href="#311">311</a></td></tr
><tr id="gr_svn42_312"

><td id="312"><a href="#312">312</a></td></tr
><tr id="gr_svn42_313"

><td id="313"><a href="#313">313</a></td></tr
><tr id="gr_svn42_314"

><td id="314"><a href="#314">314</a></td></tr
><tr id="gr_svn42_315"

><td id="315"><a href="#315">315</a></td></tr
><tr id="gr_svn42_316"

><td id="316"><a href="#316">316</a></td></tr
><tr id="gr_svn42_317"

><td id="317"><a href="#317">317</a></td></tr
><tr id="gr_svn42_318"

><td id="318"><a href="#318">318</a></td></tr
><tr id="gr_svn42_319"

><td id="319"><a href="#319">319</a></td></tr
><tr id="gr_svn42_320"

><td id="320"><a href="#320">320</a></td></tr
><tr id="gr_svn42_321"

><td id="321"><a href="#321">321</a></td></tr
><tr id="gr_svn42_322"

><td id="322"><a href="#322">322</a></td></tr
><tr id="gr_svn42_323"

><td id="323"><a href="#323">323</a></td></tr
><tr id="gr_svn42_324"

><td id="324"><a href="#324">324</a></td></tr
><tr id="gr_svn42_325"

><td id="325"><a href="#325">325</a></td></tr
><tr id="gr_svn42_326"

><td id="326"><a href="#326">326</a></td></tr
><tr id="gr_svn42_327"

><td id="327"><a href="#327">327</a></td></tr
><tr id="gr_svn42_328"

><td id="328"><a href="#328">328</a></td></tr
><tr id="gr_svn42_329"

><td id="329"><a href="#329">329</a></td></tr
><tr id="gr_svn42_330"

><td id="330"><a href="#330">330</a></td></tr
><tr id="gr_svn42_331"

><td id="331"><a href="#331">331</a></td></tr
><tr id="gr_svn42_332"

><td id="332"><a href="#332">332</a></td></tr
><tr id="gr_svn42_333"

><td id="333"><a href="#333">333</a></td></tr
><tr id="gr_svn42_334"

><td id="334"><a href="#334">334</a></td></tr
><tr id="gr_svn42_335"

><td id="335"><a href="#335">335</a></td></tr
><tr id="gr_svn42_336"

><td id="336"><a href="#336">336</a></td></tr
><tr id="gr_svn42_337"

><td id="337"><a href="#337">337</a></td></tr
><tr id="gr_svn42_338"

><td id="338"><a href="#338">338</a></td></tr
><tr id="gr_svn42_339"

><td id="339"><a href="#339">339</a></td></tr
><tr id="gr_svn42_340"

><td id="340"><a href="#340">340</a></td></tr
><tr id="gr_svn42_341"

><td id="341"><a href="#341">341</a></td></tr
><tr id="gr_svn42_342"

><td id="342"><a href="#342">342</a></td></tr
><tr id="gr_svn42_343"

><td id="343"><a href="#343">343</a></td></tr
><tr id="gr_svn42_344"

><td id="344"><a href="#344">344</a></td></tr
><tr id="gr_svn42_345"

><td id="345"><a href="#345">345</a></td></tr
><tr id="gr_svn42_346"

><td id="346"><a href="#346">346</a></td></tr
><tr id="gr_svn42_347"

><td id="347"><a href="#347">347</a></td></tr
><tr id="gr_svn42_348"

><td id="348"><a href="#348">348</a></td></tr
><tr id="gr_svn42_349"

><td id="349"><a href="#349">349</a></td></tr
><tr id="gr_svn42_350"

><td id="350"><a href="#350">350</a></td></tr
><tr id="gr_svn42_351"

><td id="351"><a href="#351">351</a></td></tr
><tr id="gr_svn42_352"

><td id="352"><a href="#352">352</a></td></tr
><tr id="gr_svn42_353"

><td id="353"><a href="#353">353</a></td></tr
><tr id="gr_svn42_354"

><td id="354"><a href="#354">354</a></td></tr
><tr id="gr_svn42_355"

><td id="355"><a href="#355">355</a></td></tr
><tr id="gr_svn42_356"

><td id="356"><a href="#356">356</a></td></tr
><tr id="gr_svn42_357"

><td id="357"><a href="#357">357</a></td></tr
><tr id="gr_svn42_358"

><td id="358"><a href="#358">358</a></td></tr
><tr id="gr_svn42_359"

><td id="359"><a href="#359">359</a></td></tr
><tr id="gr_svn42_360"

><td id="360"><a href="#360">360</a></td></tr
><tr id="gr_svn42_361"

><td id="361"><a href="#361">361</a></td></tr
><tr id="gr_svn42_362"

><td id="362"><a href="#362">362</a></td></tr
><tr id="gr_svn42_363"

><td id="363"><a href="#363">363</a></td></tr
><tr id="gr_svn42_364"

><td id="364"><a href="#364">364</a></td></tr
><tr id="gr_svn42_365"

><td id="365"><a href="#365">365</a></td></tr
><tr id="gr_svn42_366"

><td id="366"><a href="#366">366</a></td></tr
><tr id="gr_svn42_367"

><td id="367"><a href="#367">367</a></td></tr
><tr id="gr_svn42_368"

><td id="368"><a href="#368">368</a></td></tr
><tr id="gr_svn42_369"

><td id="369"><a href="#369">369</a></td></tr
><tr id="gr_svn42_370"

><td id="370"><a href="#370">370</a></td></tr
><tr id="gr_svn42_371"

><td id="371"><a href="#371">371</a></td></tr
><tr id="gr_svn42_372"

><td id="372"><a href="#372">372</a></td></tr
><tr id="gr_svn42_373"

><td id="373"><a href="#373">373</a></td></tr
><tr id="gr_svn42_374"

><td id="374"><a href="#374">374</a></td></tr
><tr id="gr_svn42_375"

><td id="375"><a href="#375">375</a></td></tr
><tr id="gr_svn42_376"

><td id="376"><a href="#376">376</a></td></tr
><tr id="gr_svn42_377"

><td id="377"><a href="#377">377</a></td></tr
><tr id="gr_svn42_378"

><td id="378"><a href="#378">378</a></td></tr
><tr id="gr_svn42_379"

><td id="379"><a href="#379">379</a></td></tr
><tr id="gr_svn42_380"

><td id="380"><a href="#380">380</a></td></tr
><tr id="gr_svn42_381"

><td id="381"><a href="#381">381</a></td></tr
><tr id="gr_svn42_382"

><td id="382"><a href="#382">382</a></td></tr
><tr id="gr_svn42_383"

><td id="383"><a href="#383">383</a></td></tr
><tr id="gr_svn42_384"

><td id="384"><a href="#384">384</a></td></tr
><tr id="gr_svn42_385"

><td id="385"><a href="#385">385</a></td></tr
><tr id="gr_svn42_386"

><td id="386"><a href="#386">386</a></td></tr
><tr id="gr_svn42_387"

><td id="387"><a href="#387">387</a></td></tr
><tr id="gr_svn42_388"

><td id="388"><a href="#388">388</a></td></tr
><tr id="gr_svn42_389"

><td id="389"><a href="#389">389</a></td></tr
><tr id="gr_svn42_390"

><td id="390"><a href="#390">390</a></td></tr
><tr id="gr_svn42_391"

><td id="391"><a href="#391">391</a></td></tr
><tr id="gr_svn42_392"

><td id="392"><a href="#392">392</a></td></tr
><tr id="gr_svn42_393"

><td id="393"><a href="#393">393</a></td></tr
><tr id="gr_svn42_394"

><td id="394"><a href="#394">394</a></td></tr
><tr id="gr_svn42_395"

><td id="395"><a href="#395">395</a></td></tr
><tr id="gr_svn42_396"

><td id="396"><a href="#396">396</a></td></tr
><tr id="gr_svn42_397"

><td id="397"><a href="#397">397</a></td></tr
><tr id="gr_svn42_398"

><td id="398"><a href="#398">398</a></td></tr
><tr id="gr_svn42_399"

><td id="399"><a href="#399">399</a></td></tr
><tr id="gr_svn42_400"

><td id="400"><a href="#400">400</a></td></tr
><tr id="gr_svn42_401"

><td id="401"><a href="#401">401</a></td></tr
><tr id="gr_svn42_402"

><td id="402"><a href="#402">402</a></td></tr
><tr id="gr_svn42_403"

><td id="403"><a href="#403">403</a></td></tr
><tr id="gr_svn42_404"

><td id="404"><a href="#404">404</a></td></tr
><tr id="gr_svn42_405"

><td id="405"><a href="#405">405</a></td></tr
><tr id="gr_svn42_406"

><td id="406"><a href="#406">406</a></td></tr
><tr id="gr_svn42_407"

><td id="407"><a href="#407">407</a></td></tr
><tr id="gr_svn42_408"

><td id="408"><a href="#408">408</a></td></tr
><tr id="gr_svn42_409"

><td id="409"><a href="#409">409</a></td></tr
><tr id="gr_svn42_410"

><td id="410"><a href="#410">410</a></td></tr
><tr id="gr_svn42_411"

><td id="411"><a href="#411">411</a></td></tr
><tr id="gr_svn42_412"

><td id="412"><a href="#412">412</a></td></tr
><tr id="gr_svn42_413"

><td id="413"><a href="#413">413</a></td></tr
><tr id="gr_svn42_414"

><td id="414"><a href="#414">414</a></td></tr
><tr id="gr_svn42_415"

><td id="415"><a href="#415">415</a></td></tr
><tr id="gr_svn42_416"

><td id="416"><a href="#416">416</a></td></tr
><tr id="gr_svn42_417"

><td id="417"><a href="#417">417</a></td></tr
><tr id="gr_svn42_418"

><td id="418"><a href="#418">418</a></td></tr
><tr id="gr_svn42_419"

><td id="419"><a href="#419">419</a></td></tr
><tr id="gr_svn42_420"

><td id="420"><a href="#420">420</a></td></tr
><tr id="gr_svn42_421"

><td id="421"><a href="#421">421</a></td></tr
><tr id="gr_svn42_422"

><td id="422"><a href="#422">422</a></td></tr
><tr id="gr_svn42_423"

><td id="423"><a href="#423">423</a></td></tr
><tr id="gr_svn42_424"

><td id="424"><a href="#424">424</a></td></tr
><tr id="gr_svn42_425"

><td id="425"><a href="#425">425</a></td></tr
><tr id="gr_svn42_426"

><td id="426"><a href="#426">426</a></td></tr
><tr id="gr_svn42_427"

><td id="427"><a href="#427">427</a></td></tr
><tr id="gr_svn42_428"

><td id="428"><a href="#428">428</a></td></tr
><tr id="gr_svn42_429"

><td id="429"><a href="#429">429</a></td></tr
><tr id="gr_svn42_430"

><td id="430"><a href="#430">430</a></td></tr
><tr id="gr_svn42_431"

><td id="431"><a href="#431">431</a></td></tr
><tr id="gr_svn42_432"

><td id="432"><a href="#432">432</a></td></tr
><tr id="gr_svn42_433"

><td id="433"><a href="#433">433</a></td></tr
><tr id="gr_svn42_434"

><td id="434"><a href="#434">434</a></td></tr
><tr id="gr_svn42_435"

><td id="435"><a href="#435">435</a></td></tr
><tr id="gr_svn42_436"

><td id="436"><a href="#436">436</a></td></tr
><tr id="gr_svn42_437"

><td id="437"><a href="#437">437</a></td></tr
><tr id="gr_svn42_438"

><td id="438"><a href="#438">438</a></td></tr
><tr id="gr_svn42_439"

><td id="439"><a href="#439">439</a></td></tr
><tr id="gr_svn42_440"

><td id="440"><a href="#440">440</a></td></tr
><tr id="gr_svn42_441"

><td id="441"><a href="#441">441</a></td></tr
><tr id="gr_svn42_442"

><td id="442"><a href="#442">442</a></td></tr
><tr id="gr_svn42_443"

><td id="443"><a href="#443">443</a></td></tr
><tr id="gr_svn42_444"

><td id="444"><a href="#444">444</a></td></tr
><tr id="gr_svn42_445"

><td id="445"><a href="#445">445</a></td></tr
><tr id="gr_svn42_446"

><td id="446"><a href="#446">446</a></td></tr
><tr id="gr_svn42_447"

><td id="447"><a href="#447">447</a></td></tr
><tr id="gr_svn42_448"

><td id="448"><a href="#448">448</a></td></tr
><tr id="gr_svn42_449"

><td id="449"><a href="#449">449</a></td></tr
><tr id="gr_svn42_450"

><td id="450"><a href="#450">450</a></td></tr
><tr id="gr_svn42_451"

><td id="451"><a href="#451">451</a></td></tr
><tr id="gr_svn42_452"

><td id="452"><a href="#452">452</a></td></tr
><tr id="gr_svn42_453"

><td id="453"><a href="#453">453</a></td></tr
><tr id="gr_svn42_454"

><td id="454"><a href="#454">454</a></td></tr
><tr id="gr_svn42_455"

><td id="455"><a href="#455">455</a></td></tr
><tr id="gr_svn42_456"

><td id="456"><a href="#456">456</a></td></tr
><tr id="gr_svn42_457"

><td id="457"><a href="#457">457</a></td></tr
><tr id="gr_svn42_458"

><td id="458"><a href="#458">458</a></td></tr
><tr id="gr_svn42_459"

><td id="459"><a href="#459">459</a></td></tr
><tr id="gr_svn42_460"

><td id="460"><a href="#460">460</a></td></tr
><tr id="gr_svn42_461"

><td id="461"><a href="#461">461</a></td></tr
><tr id="gr_svn42_462"

><td id="462"><a href="#462">462</a></td></tr
><tr id="gr_svn42_463"

><td id="463"><a href="#463">463</a></td></tr
><tr id="gr_svn42_464"

><td id="464"><a href="#464">464</a></td></tr
><tr id="gr_svn42_465"

><td id="465"><a href="#465">465</a></td></tr
><tr id="gr_svn42_466"

><td id="466"><a href="#466">466</a></td></tr
><tr id="gr_svn42_467"

><td id="467"><a href="#467">467</a></td></tr
><tr id="gr_svn42_468"

><td id="468"><a href="#468">468</a></td></tr
><tr id="gr_svn42_469"

><td id="469"><a href="#469">469</a></td></tr
><tr id="gr_svn42_470"

><td id="470"><a href="#470">470</a></td></tr
><tr id="gr_svn42_471"

><td id="471"><a href="#471">471</a></td></tr
><tr id="gr_svn42_472"

><td id="472"><a href="#472">472</a></td></tr
><tr id="gr_svn42_473"

><td id="473"><a href="#473">473</a></td></tr
><tr id="gr_svn42_474"

><td id="474"><a href="#474">474</a></td></tr
><tr id="gr_svn42_475"

><td id="475"><a href="#475">475</a></td></tr
><tr id="gr_svn42_476"

><td id="476"><a href="#476">476</a></td></tr
><tr id="gr_svn42_477"

><td id="477"><a href="#477">477</a></td></tr
><tr id="gr_svn42_478"

><td id="478"><a href="#478">478</a></td></tr
><tr id="gr_svn42_479"

><td id="479"><a href="#479">479</a></td></tr
><tr id="gr_svn42_480"

><td id="480"><a href="#480">480</a></td></tr
><tr id="gr_svn42_481"

><td id="481"><a href="#481">481</a></td></tr
><tr id="gr_svn42_482"

><td id="482"><a href="#482">482</a></td></tr
><tr id="gr_svn42_483"

><td id="483"><a href="#483">483</a></td></tr
><tr id="gr_svn42_484"

><td id="484"><a href="#484">484</a></td></tr
><tr id="gr_svn42_485"

><td id="485"><a href="#485">485</a></td></tr
><tr id="gr_svn42_486"

><td id="486"><a href="#486">486</a></td></tr
><tr id="gr_svn42_487"

><td id="487"><a href="#487">487</a></td></tr
><tr id="gr_svn42_488"

><td id="488"><a href="#488">488</a></td></tr
><tr id="gr_svn42_489"

><td id="489"><a href="#489">489</a></td></tr
><tr id="gr_svn42_490"

><td id="490"><a href="#490">490</a></td></tr
><tr id="gr_svn42_491"

><td id="491"><a href="#491">491</a></td></tr
><tr id="gr_svn42_492"

><td id="492"><a href="#492">492</a></td></tr
><tr id="gr_svn42_493"

><td id="493"><a href="#493">493</a></td></tr
><tr id="gr_svn42_494"

><td id="494"><a href="#494">494</a></td></tr
><tr id="gr_svn42_495"

><td id="495"><a href="#495">495</a></td></tr
><tr id="gr_svn42_496"

><td id="496"><a href="#496">496</a></td></tr
><tr id="gr_svn42_497"

><td id="497"><a href="#497">497</a></td></tr
><tr id="gr_svn42_498"

><td id="498"><a href="#498">498</a></td></tr
><tr id="gr_svn42_499"

><td id="499"><a href="#499">499</a></td></tr
><tr id="gr_svn42_500"

><td id="500"><a href="#500">500</a></td></tr
><tr id="gr_svn42_501"

><td id="501"><a href="#501">501</a></td></tr
><tr id="gr_svn42_502"

><td id="502"><a href="#502">502</a></td></tr
><tr id="gr_svn42_503"

><td id="503"><a href="#503">503</a></td></tr
><tr id="gr_svn42_504"

><td id="504"><a href="#504">504</a></td></tr
><tr id="gr_svn42_505"

><td id="505"><a href="#505">505</a></td></tr
><tr id="gr_svn42_506"

><td id="506"><a href="#506">506</a></td></tr
><tr id="gr_svn42_507"

><td id="507"><a href="#507">507</a></td></tr
><tr id="gr_svn42_508"

><td id="508"><a href="#508">508</a></td></tr
><tr id="gr_svn42_509"

><td id="509"><a href="#509">509</a></td></tr
><tr id="gr_svn42_510"

><td id="510"><a href="#510">510</a></td></tr
><tr id="gr_svn42_511"

><td id="511"><a href="#511">511</a></td></tr
><tr id="gr_svn42_512"

><td id="512"><a href="#512">512</a></td></tr
><tr id="gr_svn42_513"

><td id="513"><a href="#513">513</a></td></tr
><tr id="gr_svn42_514"

><td id="514"><a href="#514">514</a></td></tr
><tr id="gr_svn42_515"

><td id="515"><a href="#515">515</a></td></tr
><tr id="gr_svn42_516"

><td id="516"><a href="#516">516</a></td></tr
><tr id="gr_svn42_517"

><td id="517"><a href="#517">517</a></td></tr
><tr id="gr_svn42_518"

><td id="518"><a href="#518">518</a></td></tr
><tr id="gr_svn42_519"

><td id="519"><a href="#519">519</a></td></tr
><tr id="gr_svn42_520"

><td id="520"><a href="#520">520</a></td></tr
><tr id="gr_svn42_521"

><td id="521"><a href="#521">521</a></td></tr
><tr id="gr_svn42_522"

><td id="522"><a href="#522">522</a></td></tr
><tr id="gr_svn42_523"

><td id="523"><a href="#523">523</a></td></tr
><tr id="gr_svn42_524"

><td id="524"><a href="#524">524</a></td></tr
><tr id="gr_svn42_525"

><td id="525"><a href="#525">525</a></td></tr
><tr id="gr_svn42_526"

><td id="526"><a href="#526">526</a></td></tr
><tr id="gr_svn42_527"

><td id="527"><a href="#527">527</a></td></tr
><tr id="gr_svn42_528"

><td id="528"><a href="#528">528</a></td></tr
><tr id="gr_svn42_529"

><td id="529"><a href="#529">529</a></td></tr
><tr id="gr_svn42_530"

><td id="530"><a href="#530">530</a></td></tr
><tr id="gr_svn42_531"

><td id="531"><a href="#531">531</a></td></tr
><tr id="gr_svn42_532"

><td id="532"><a href="#532">532</a></td></tr
><tr id="gr_svn42_533"

><td id="533"><a href="#533">533</a></td></tr
><tr id="gr_svn42_534"

><td id="534"><a href="#534">534</a></td></tr
><tr id="gr_svn42_535"

><td id="535"><a href="#535">535</a></td></tr
><tr id="gr_svn42_536"

><td id="536"><a href="#536">536</a></td></tr
><tr id="gr_svn42_537"

><td id="537"><a href="#537">537</a></td></tr
><tr id="gr_svn42_538"

><td id="538"><a href="#538">538</a></td></tr
><tr id="gr_svn42_539"

><td id="539"><a href="#539">539</a></td></tr
><tr id="gr_svn42_540"

><td id="540"><a href="#540">540</a></td></tr
><tr id="gr_svn42_541"

><td id="541"><a href="#541">541</a></td></tr
><tr id="gr_svn42_542"

><td id="542"><a href="#542">542</a></td></tr
><tr id="gr_svn42_543"

><td id="543"><a href="#543">543</a></td></tr
><tr id="gr_svn42_544"

><td id="544"><a href="#544">544</a></td></tr
><tr id="gr_svn42_545"

><td id="545"><a href="#545">545</a></td></tr
><tr id="gr_svn42_546"

><td id="546"><a href="#546">546</a></td></tr
><tr id="gr_svn42_547"

><td id="547"><a href="#547">547</a></td></tr
><tr id="gr_svn42_548"

><td id="548"><a href="#548">548</a></td></tr
><tr id="gr_svn42_549"

><td id="549"><a href="#549">549</a></td></tr
><tr id="gr_svn42_550"

><td id="550"><a href="#550">550</a></td></tr
><tr id="gr_svn42_551"

><td id="551"><a href="#551">551</a></td></tr
><tr id="gr_svn42_552"

><td id="552"><a href="#552">552</a></td></tr
><tr id="gr_svn42_553"

><td id="553"><a href="#553">553</a></td></tr
><tr id="gr_svn42_554"

><td id="554"><a href="#554">554</a></td></tr
><tr id="gr_svn42_555"

><td id="555"><a href="#555">555</a></td></tr
><tr id="gr_svn42_556"

><td id="556"><a href="#556">556</a></td></tr
><tr id="gr_svn42_557"

><td id="557"><a href="#557">557</a></td></tr
><tr id="gr_svn42_558"

><td id="558"><a href="#558">558</a></td></tr
><tr id="gr_svn42_559"

><td id="559"><a href="#559">559</a></td></tr
><tr id="gr_svn42_560"

><td id="560"><a href="#560">560</a></td></tr
><tr id="gr_svn42_561"

><td id="561"><a href="#561">561</a></td></tr
><tr id="gr_svn42_562"

><td id="562"><a href="#562">562</a></td></tr
><tr id="gr_svn42_563"

><td id="563"><a href="#563">563</a></td></tr
><tr id="gr_svn42_564"

><td id="564"><a href="#564">564</a></td></tr
><tr id="gr_svn42_565"

><td id="565"><a href="#565">565</a></td></tr
><tr id="gr_svn42_566"

><td id="566"><a href="#566">566</a></td></tr
><tr id="gr_svn42_567"

><td id="567"><a href="#567">567</a></td></tr
><tr id="gr_svn42_568"

><td id="568"><a href="#568">568</a></td></tr
><tr id="gr_svn42_569"

><td id="569"><a href="#569">569</a></td></tr
><tr id="gr_svn42_570"

><td id="570"><a href="#570">570</a></td></tr
><tr id="gr_svn42_571"

><td id="571"><a href="#571">571</a></td></tr
><tr id="gr_svn42_572"

><td id="572"><a href="#572">572</a></td></tr
><tr id="gr_svn42_573"

><td id="573"><a href="#573">573</a></td></tr
><tr id="gr_svn42_574"

><td id="574"><a href="#574">574</a></td></tr
><tr id="gr_svn42_575"

><td id="575"><a href="#575">575</a></td></tr
><tr id="gr_svn42_576"

><td id="576"><a href="#576">576</a></td></tr
><tr id="gr_svn42_577"

><td id="577"><a href="#577">577</a></td></tr
><tr id="gr_svn42_578"

><td id="578"><a href="#578">578</a></td></tr
><tr id="gr_svn42_579"

><td id="579"><a href="#579">579</a></td></tr
><tr id="gr_svn42_580"

><td id="580"><a href="#580">580</a></td></tr
><tr id="gr_svn42_581"

><td id="581"><a href="#581">581</a></td></tr
><tr id="gr_svn42_582"

><td id="582"><a href="#582">582</a></td></tr
><tr id="gr_svn42_583"

><td id="583"><a href="#583">583</a></td></tr
><tr id="gr_svn42_584"

><td id="584"><a href="#584">584</a></td></tr
><tr id="gr_svn42_585"

><td id="585"><a href="#585">585</a></td></tr
><tr id="gr_svn42_586"

><td id="586"><a href="#586">586</a></td></tr
><tr id="gr_svn42_587"

><td id="587"><a href="#587">587</a></td></tr
><tr id="gr_svn42_588"

><td id="588"><a href="#588">588</a></td></tr
><tr id="gr_svn42_589"

><td id="589"><a href="#589">589</a></td></tr
><tr id="gr_svn42_590"

><td id="590"><a href="#590">590</a></td></tr
><tr id="gr_svn42_591"

><td id="591"><a href="#591">591</a></td></tr
><tr id="gr_svn42_592"

><td id="592"><a href="#592">592</a></td></tr
><tr id="gr_svn42_593"

><td id="593"><a href="#593">593</a></td></tr
><tr id="gr_svn42_594"

><td id="594"><a href="#594">594</a></td></tr
><tr id="gr_svn42_595"

><td id="595"><a href="#595">595</a></td></tr
><tr id="gr_svn42_596"

><td id="596"><a href="#596">596</a></td></tr
><tr id="gr_svn42_597"

><td id="597"><a href="#597">597</a></td></tr
><tr id="gr_svn42_598"

><td id="598"><a href="#598">598</a></td></tr
><tr id="gr_svn42_599"

><td id="599"><a href="#599">599</a></td></tr
><tr id="gr_svn42_600"

><td id="600"><a href="#600">600</a></td></tr
><tr id="gr_svn42_601"

><td id="601"><a href="#601">601</a></td></tr
><tr id="gr_svn42_602"

><td id="602"><a href="#602">602</a></td></tr
><tr id="gr_svn42_603"

><td id="603"><a href="#603">603</a></td></tr
><tr id="gr_svn42_604"

><td id="604"><a href="#604">604</a></td></tr
><tr id="gr_svn42_605"

><td id="605"><a href="#605">605</a></td></tr
><tr id="gr_svn42_606"

><td id="606"><a href="#606">606</a></td></tr
><tr id="gr_svn42_607"

><td id="607"><a href="#607">607</a></td></tr
><tr id="gr_svn42_608"

><td id="608"><a href="#608">608</a></td></tr
><tr id="gr_svn42_609"

><td id="609"><a href="#609">609</a></td></tr
><tr id="gr_svn42_610"

><td id="610"><a href="#610">610</a></td></tr
><tr id="gr_svn42_611"

><td id="611"><a href="#611">611</a></td></tr
><tr id="gr_svn42_612"

><td id="612"><a href="#612">612</a></td></tr
><tr id="gr_svn42_613"

><td id="613"><a href="#613">613</a></td></tr
><tr id="gr_svn42_614"

><td id="614"><a href="#614">614</a></td></tr
><tr id="gr_svn42_615"

><td id="615"><a href="#615">615</a></td></tr
><tr id="gr_svn42_616"

><td id="616"><a href="#616">616</a></td></tr
><tr id="gr_svn42_617"

><td id="617"><a href="#617">617</a></td></tr
><tr id="gr_svn42_618"

><td id="618"><a href="#618">618</a></td></tr
><tr id="gr_svn42_619"

><td id="619"><a href="#619">619</a></td></tr
><tr id="gr_svn42_620"

><td id="620"><a href="#620">620</a></td></tr
><tr id="gr_svn42_621"

><td id="621"><a href="#621">621</a></td></tr
><tr id="gr_svn42_622"

><td id="622"><a href="#622">622</a></td></tr
><tr id="gr_svn42_623"

><td id="623"><a href="#623">623</a></td></tr
><tr id="gr_svn42_624"

><td id="624"><a href="#624">624</a></td></tr
><tr id="gr_svn42_625"

><td id="625"><a href="#625">625</a></td></tr
><tr id="gr_svn42_626"

><td id="626"><a href="#626">626</a></td></tr
><tr id="gr_svn42_627"

><td id="627"><a href="#627">627</a></td></tr
><tr id="gr_svn42_628"

><td id="628"><a href="#628">628</a></td></tr
><tr id="gr_svn42_629"

><td id="629"><a href="#629">629</a></td></tr
><tr id="gr_svn42_630"

><td id="630"><a href="#630">630</a></td></tr
><tr id="gr_svn42_631"

><td id="631"><a href="#631">631</a></td></tr
><tr id="gr_svn42_632"

><td id="632"><a href="#632">632</a></td></tr
><tr id="gr_svn42_633"

><td id="633"><a href="#633">633</a></td></tr
><tr id="gr_svn42_634"

><td id="634"><a href="#634">634</a></td></tr
><tr id="gr_svn42_635"

><td id="635"><a href="#635">635</a></td></tr
><tr id="gr_svn42_636"

><td id="636"><a href="#636">636</a></td></tr
><tr id="gr_svn42_637"

><td id="637"><a href="#637">637</a></td></tr
><tr id="gr_svn42_638"

><td id="638"><a href="#638">638</a></td></tr
><tr id="gr_svn42_639"

><td id="639"><a href="#639">639</a></td></tr
><tr id="gr_svn42_640"

><td id="640"><a href="#640">640</a></td></tr
><tr id="gr_svn42_641"

><td id="641"><a href="#641">641</a></td></tr
><tr id="gr_svn42_642"

><td id="642"><a href="#642">642</a></td></tr
><tr id="gr_svn42_643"

><td id="643"><a href="#643">643</a></td></tr
><tr id="gr_svn42_644"

><td id="644"><a href="#644">644</a></td></tr
><tr id="gr_svn42_645"

><td id="645"><a href="#645">645</a></td></tr
><tr id="gr_svn42_646"

><td id="646"><a href="#646">646</a></td></tr
><tr id="gr_svn42_647"

><td id="647"><a href="#647">647</a></td></tr
><tr id="gr_svn42_648"

><td id="648"><a href="#648">648</a></td></tr
><tr id="gr_svn42_649"

><td id="649"><a href="#649">649</a></td></tr
><tr id="gr_svn42_650"

><td id="650"><a href="#650">650</a></td></tr
><tr id="gr_svn42_651"

><td id="651"><a href="#651">651</a></td></tr
><tr id="gr_svn42_652"

><td id="652"><a href="#652">652</a></td></tr
><tr id="gr_svn42_653"

><td id="653"><a href="#653">653</a></td></tr
><tr id="gr_svn42_654"

><td id="654"><a href="#654">654</a></td></tr
><tr id="gr_svn42_655"

><td id="655"><a href="#655">655</a></td></tr
><tr id="gr_svn42_656"

><td id="656"><a href="#656">656</a></td></tr
><tr id="gr_svn42_657"

><td id="657"><a href="#657">657</a></td></tr
><tr id="gr_svn42_658"

><td id="658"><a href="#658">658</a></td></tr
><tr id="gr_svn42_659"

><td id="659"><a href="#659">659</a></td></tr
><tr id="gr_svn42_660"

><td id="660"><a href="#660">660</a></td></tr
><tr id="gr_svn42_661"

><td id="661"><a href="#661">661</a></td></tr
><tr id="gr_svn42_662"

><td id="662"><a href="#662">662</a></td></tr
><tr id="gr_svn42_663"

><td id="663"><a href="#663">663</a></td></tr
><tr id="gr_svn42_664"

><td id="664"><a href="#664">664</a></td></tr
><tr id="gr_svn42_665"

><td id="665"><a href="#665">665</a></td></tr
><tr id="gr_svn42_666"

><td id="666"><a href="#666">666</a></td></tr
><tr id="gr_svn42_667"

><td id="667"><a href="#667">667</a></td></tr
><tr id="gr_svn42_668"

><td id="668"><a href="#668">668</a></td></tr
><tr id="gr_svn42_669"

><td id="669"><a href="#669">669</a></td></tr
><tr id="gr_svn42_670"

><td id="670"><a href="#670">670</a></td></tr
><tr id="gr_svn42_671"

><td id="671"><a href="#671">671</a></td></tr
><tr id="gr_svn42_672"

><td id="672"><a href="#672">672</a></td></tr
><tr id="gr_svn42_673"

><td id="673"><a href="#673">673</a></td></tr
><tr id="gr_svn42_674"

><td id="674"><a href="#674">674</a></td></tr
><tr id="gr_svn42_675"

><td id="675"><a href="#675">675</a></td></tr
><tr id="gr_svn42_676"

><td id="676"><a href="#676">676</a></td></tr
><tr id="gr_svn42_677"

><td id="677"><a href="#677">677</a></td></tr
><tr id="gr_svn42_678"

><td id="678"><a href="#678">678</a></td></tr
><tr id="gr_svn42_679"

><td id="679"><a href="#679">679</a></td></tr
><tr id="gr_svn42_680"

><td id="680"><a href="#680">680</a></td></tr
><tr id="gr_svn42_681"

><td id="681"><a href="#681">681</a></td></tr
><tr id="gr_svn42_682"

><td id="682"><a href="#682">682</a></td></tr
><tr id="gr_svn42_683"

><td id="683"><a href="#683">683</a></td></tr
><tr id="gr_svn42_684"

><td id="684"><a href="#684">684</a></td></tr
><tr id="gr_svn42_685"

><td id="685"><a href="#685">685</a></td></tr
><tr id="gr_svn42_686"

><td id="686"><a href="#686">686</a></td></tr
><tr id="gr_svn42_687"

><td id="687"><a href="#687">687</a></td></tr
><tr id="gr_svn42_688"

><td id="688"><a href="#688">688</a></td></tr
><tr id="gr_svn42_689"

><td id="689"><a href="#689">689</a></td></tr
><tr id="gr_svn42_690"

><td id="690"><a href="#690">690</a></td></tr
><tr id="gr_svn42_691"

><td id="691"><a href="#691">691</a></td></tr
><tr id="gr_svn42_692"

><td id="692"><a href="#692">692</a></td></tr
><tr id="gr_svn42_693"

><td id="693"><a href="#693">693</a></td></tr
><tr id="gr_svn42_694"

><td id="694"><a href="#694">694</a></td></tr
><tr id="gr_svn42_695"

><td id="695"><a href="#695">695</a></td></tr
><tr id="gr_svn42_696"

><td id="696"><a href="#696">696</a></td></tr
><tr id="gr_svn42_697"

><td id="697"><a href="#697">697</a></td></tr
><tr id="gr_svn42_698"

><td id="698"><a href="#698">698</a></td></tr
><tr id="gr_svn42_699"

><td id="699"><a href="#699">699</a></td></tr
><tr id="gr_svn42_700"

><td id="700"><a href="#700">700</a></td></tr
><tr id="gr_svn42_701"

><td id="701"><a href="#701">701</a></td></tr
><tr id="gr_svn42_702"

><td id="702"><a href="#702">702</a></td></tr
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

><td class="source">#include &lt;pthread.h&gt;<br></td></tr
><tr
id=sl_svn42_20

><td class="source"><br></td></tr
><tr
id=sl_svn42_21

><td class="source">#define MAX_STRING 100<br></td></tr
><tr
id=sl_svn42_22

><td class="source">#define EXP_TABLE_SIZE 1000<br></td></tr
><tr
id=sl_svn42_23

><td class="source">#define MAX_EXP 6<br></td></tr
><tr
id=sl_svn42_24

><td class="source">#define MAX_SENTENCE_LENGTH 1000<br></td></tr
><tr
id=sl_svn42_25

><td class="source">#define MAX_CODE_LENGTH 40<br></td></tr
><tr
id=sl_svn42_26

><td class="source"><br></td></tr
><tr
id=sl_svn42_27

><td class="source">const int vocab_hash_size = 30000000;  // Maximum 30 * 0.7 = 21M words in the vocabulary<br></td></tr
><tr
id=sl_svn42_28

><td class="source"><br></td></tr
><tr
id=sl_svn42_29

><td class="source">typedef float real;                    // Precision of float numbers<br></td></tr
><tr
id=sl_svn42_30

><td class="source"><br></td></tr
><tr
id=sl_svn42_31

><td class="source">struct vocab_word {<br></td></tr
><tr
id=sl_svn42_32

><td class="source">  long long cn;<br></td></tr
><tr
id=sl_svn42_33

><td class="source">  int *point;<br></td></tr
><tr
id=sl_svn42_34

><td class="source">  char *word, *code, codelen;<br></td></tr
><tr
id=sl_svn42_35

><td class="source">};<br></td></tr
><tr
id=sl_svn42_36

><td class="source"><br></td></tr
><tr
id=sl_svn42_37

><td class="source">char train_file[MAX_STRING], output_file[MAX_STRING];<br></td></tr
><tr
id=sl_svn42_38

><td class="source">char save_vocab_file[MAX_STRING], read_vocab_file[MAX_STRING];<br></td></tr
><tr
id=sl_svn42_39

><td class="source">struct vocab_word *vocab;<br></td></tr
><tr
id=sl_svn42_40

><td class="source">int binary = 0, cbow = 1, debug_mode = 2, window = 5, min_count = 5, num_threads = 12, min_reduce = 1;<br></td></tr
><tr
id=sl_svn42_41

><td class="source">int *vocab_hash;<br></td></tr
><tr
id=sl_svn42_42

><td class="source">long long vocab_max_size = 1000, vocab_size = 0, layer1_size = 100;<br></td></tr
><tr
id=sl_svn42_43

><td class="source">long long train_words = 0, word_count_actual = 0, iter = 5, file_size = 0, classes = 0;<br></td></tr
><tr
id=sl_svn42_44

><td class="source">real alpha = 0.025, starting_alpha, sample = 1e-3;<br></td></tr
><tr
id=sl_svn42_45

><td class="source">real *syn0, *syn1, *syn1neg, *expTable;<br></td></tr
><tr
id=sl_svn42_46

><td class="source">clock_t start;<br></td></tr
><tr
id=sl_svn42_47

><td class="source"><br></td></tr
><tr
id=sl_svn42_48

><td class="source">int hs = 0, negative = 5;<br></td></tr
><tr
id=sl_svn42_49

><td class="source">const int table_size = 1e8;<br></td></tr
><tr
id=sl_svn42_50

><td class="source">int *table;<br></td></tr
><tr
id=sl_svn42_51

><td class="source"><br></td></tr
><tr
id=sl_svn42_52

><td class="source">void InitUnigramTable() {<br></td></tr
><tr
id=sl_svn42_53

><td class="source">  int a, i;<br></td></tr
><tr
id=sl_svn42_54

><td class="source">  double train_words_pow = 0;<br></td></tr
><tr
id=sl_svn42_55

><td class="source">  double d1, power = 0.75;<br></td></tr
><tr
id=sl_svn42_56

><td class="source">  table = (int *)malloc(table_size * sizeof(int));<br></td></tr
><tr
id=sl_svn42_57

><td class="source">  for (a = 0; a &lt; vocab_size; a++) train_words_pow += pow(vocab[a].cn, power);<br></td></tr
><tr
id=sl_svn42_58

><td class="source">  i = 0;<br></td></tr
><tr
id=sl_svn42_59

><td class="source">  d1 = pow(vocab[i].cn, power) / train_words_pow;<br></td></tr
><tr
id=sl_svn42_60

><td class="source">  for (a = 0; a &lt; table_size; a++) {<br></td></tr
><tr
id=sl_svn42_61

><td class="source">    table[a] = i;<br></td></tr
><tr
id=sl_svn42_62

><td class="source">    if (a / (double)table_size &gt; d1) {<br></td></tr
><tr
id=sl_svn42_63

><td class="source">      i++;<br></td></tr
><tr
id=sl_svn42_64

><td class="source">      d1 += pow(vocab[i].cn, power) / train_words_pow;<br></td></tr
><tr
id=sl_svn42_65

><td class="source">    }<br></td></tr
><tr
id=sl_svn42_66

><td class="source">    if (i &gt;= vocab_size) i = vocab_size - 1;<br></td></tr
><tr
id=sl_svn42_67

><td class="source">  }<br></td></tr
><tr
id=sl_svn42_68

><td class="source">}<br></td></tr
><tr
id=sl_svn42_69

><td class="source"><br></td></tr
><tr
id=sl_svn42_70

><td class="source">// Reads a single word from a file, assuming space + tab + EOL to be word boundaries<br></td></tr
><tr
id=sl_svn42_71

><td class="source">void ReadWord(char *word, FILE *fin) {<br></td></tr
><tr
id=sl_svn42_72

><td class="source">  int a = 0, ch;<br></td></tr
><tr
id=sl_svn42_73

><td class="source">  while (!feof(fin)) {<br></td></tr
><tr
id=sl_svn42_74

><td class="source">    ch = fgetc(fin);<br></td></tr
><tr
id=sl_svn42_75

><td class="source">    if (ch == 13) continue;<br></td></tr
><tr
id=sl_svn42_76

><td class="source">    if ((ch == &#39; &#39;) || (ch == &#39;\t&#39;) || (ch == &#39;\n&#39;)) {<br></td></tr
><tr
id=sl_svn42_77

><td class="source">      if (a &gt; 0) {<br></td></tr
><tr
id=sl_svn42_78

><td class="source">        if (ch == &#39;\n&#39;) ungetc(ch, fin);<br></td></tr
><tr
id=sl_svn42_79

><td class="source">        break;<br></td></tr
><tr
id=sl_svn42_80

><td class="source">      }<br></td></tr
><tr
id=sl_svn42_81

><td class="source">      if (ch == &#39;\n&#39;) {<br></td></tr
><tr
id=sl_svn42_82

><td class="source">        strcpy(word, (char *)&quot;&lt;/s&gt;&quot;);<br></td></tr
><tr
id=sl_svn42_83

><td class="source">        return;<br></td></tr
><tr
id=sl_svn42_84

><td class="source">      } else continue;<br></td></tr
><tr
id=sl_svn42_85

><td class="source">    }<br></td></tr
><tr
id=sl_svn42_86

><td class="source">    word[a] = ch;<br></td></tr
><tr
id=sl_svn42_87

><td class="source">    a++;<br></td></tr
><tr
id=sl_svn42_88

><td class="source">    if (a &gt;= MAX_STRING - 1) a--;   // Truncate too long words<br></td></tr
><tr
id=sl_svn42_89

><td class="source">  }<br></td></tr
><tr
id=sl_svn42_90

><td class="source">  word[a] = 0;<br></td></tr
><tr
id=sl_svn42_91

><td class="source">}<br></td></tr
><tr
id=sl_svn42_92

><td class="source"><br></td></tr
><tr
id=sl_svn42_93

><td class="source">// Returns hash value of a word<br></td></tr
><tr
id=sl_svn42_94

><td class="source">int GetWordHash(char *word) {<br></td></tr
><tr
id=sl_svn42_95

><td class="source">  unsigned long long a, hash = 0;<br></td></tr
><tr
id=sl_svn42_96

><td class="source">  for (a = 0; a &lt; strlen(word); a++) hash = hash * 257 + word[a];<br></td></tr
><tr
id=sl_svn42_97

><td class="source">  hash = hash % vocab_hash_size;<br></td></tr
><tr
id=sl_svn42_98

><td class="source">  return hash;<br></td></tr
><tr
id=sl_svn42_99

><td class="source">}<br></td></tr
><tr
id=sl_svn42_100

><td class="source"><br></td></tr
><tr
id=sl_svn42_101

><td class="source">// Returns position of a word in the vocabulary; if the word is not found, returns -1<br></td></tr
><tr
id=sl_svn42_102

><td class="source">int SearchVocab(char *word) {<br></td></tr
><tr
id=sl_svn42_103

><td class="source">  unsigned int hash = GetWordHash(word);<br></td></tr
><tr
id=sl_svn42_104

><td class="source">  while (1) {<br></td></tr
><tr
id=sl_svn42_105

><td class="source">    if (vocab_hash[hash] == -1) return -1;<br></td></tr
><tr
id=sl_svn42_106

><td class="source">    if (!strcmp(word, vocab[vocab_hash[hash]].word)) return vocab_hash[hash];<br></td></tr
><tr
id=sl_svn42_107

><td class="source">    hash = (hash + 1) % vocab_hash_size;<br></td></tr
><tr
id=sl_svn42_108

><td class="source">  }<br></td></tr
><tr
id=sl_svn42_109

><td class="source">  return -1;<br></td></tr
><tr
id=sl_svn42_110

><td class="source">}<br></td></tr
><tr
id=sl_svn42_111

><td class="source"><br></td></tr
><tr
id=sl_svn42_112

><td class="source">// Reads a word and returns its index in the vocabulary<br></td></tr
><tr
id=sl_svn42_113

><td class="source">int ReadWordIndex(FILE *fin) {<br></td></tr
><tr
id=sl_svn42_114

><td class="source">  char word[MAX_STRING];<br></td></tr
><tr
id=sl_svn42_115

><td class="source">  ReadWord(word, fin);<br></td></tr
><tr
id=sl_svn42_116

><td class="source">  if (feof(fin)) return -1;<br></td></tr
><tr
id=sl_svn42_117

><td class="source">  return SearchVocab(word);<br></td></tr
><tr
id=sl_svn42_118

><td class="source">}<br></td></tr
><tr
id=sl_svn42_119

><td class="source"><br></td></tr
><tr
id=sl_svn42_120

><td class="source">// Adds a word to the vocabulary<br></td></tr
><tr
id=sl_svn42_121

><td class="source">int AddWordToVocab(char *word) {<br></td></tr
><tr
id=sl_svn42_122

><td class="source">  unsigned int hash, length = strlen(word) + 1;<br></td></tr
><tr
id=sl_svn42_123

><td class="source">  if (length &gt; MAX_STRING) length = MAX_STRING;<br></td></tr
><tr
id=sl_svn42_124

><td class="source">  vocab[vocab_size].word = (char *)calloc(length, sizeof(char));<br></td></tr
><tr
id=sl_svn42_125

><td class="source">  strcpy(vocab[vocab_size].word, word);<br></td></tr
><tr
id=sl_svn42_126

><td class="source">  vocab[vocab_size].cn = 0;<br></td></tr
><tr
id=sl_svn42_127

><td class="source">  vocab_size++;<br></td></tr
><tr
id=sl_svn42_128

><td class="source">  // Reallocate memory if needed<br></td></tr
><tr
id=sl_svn42_129

><td class="source">  if (vocab_size + 2 &gt;= vocab_max_size) {<br></td></tr
><tr
id=sl_svn42_130

><td class="source">    vocab_max_size += 1000;<br></td></tr
><tr
id=sl_svn42_131

><td class="source">    vocab = (struct vocab_word *)realloc(vocab, vocab_max_size * sizeof(struct vocab_word));<br></td></tr
><tr
id=sl_svn42_132

><td class="source">  }<br></td></tr
><tr
id=sl_svn42_133

><td class="source">  hash = GetWordHash(word);<br></td></tr
><tr
id=sl_svn42_134

><td class="source">  while (vocab_hash[hash] != -1) hash = (hash + 1) % vocab_hash_size;<br></td></tr
><tr
id=sl_svn42_135

><td class="source">  vocab_hash[hash] = vocab_size - 1;<br></td></tr
><tr
id=sl_svn42_136

><td class="source">  return vocab_size - 1;<br></td></tr
><tr
id=sl_svn42_137

><td class="source">}<br></td></tr
><tr
id=sl_svn42_138

><td class="source"><br></td></tr
><tr
id=sl_svn42_139

><td class="source">// Used later for sorting by word counts<br></td></tr
><tr
id=sl_svn42_140

><td class="source">int VocabCompare(const void *a, const void *b) {<br></td></tr
><tr
id=sl_svn42_141

><td class="source">    return ((struct vocab_word *)b)-&gt;cn - ((struct vocab_word *)a)-&gt;cn;<br></td></tr
><tr
id=sl_svn42_142

><td class="source">}<br></td></tr
><tr
id=sl_svn42_143

><td class="source"><br></td></tr
><tr
id=sl_svn42_144

><td class="source">// Sorts the vocabulary by frequency using word counts<br></td></tr
><tr
id=sl_svn42_145

><td class="source">void SortVocab() {<br></td></tr
><tr
id=sl_svn42_146

><td class="source">  int a, size;<br></td></tr
><tr
id=sl_svn42_147

><td class="source">  unsigned int hash;<br></td></tr
><tr
id=sl_svn42_148

><td class="source">  // Sort the vocabulary and keep &lt;/s&gt; at the first position<br></td></tr
><tr
id=sl_svn42_149

><td class="source">  qsort(&amp;vocab[1], vocab_size - 1, sizeof(struct vocab_word), VocabCompare);<br></td></tr
><tr
id=sl_svn42_150

><td class="source">  for (a = 0; a &lt; vocab_hash_size; a++) vocab_hash[a] = -1;<br></td></tr
><tr
id=sl_svn42_151

><td class="source">  size = vocab_size;<br></td></tr
><tr
id=sl_svn42_152

><td class="source">  train_words = 0;<br></td></tr
><tr
id=sl_svn42_153

><td class="source">  for (a = 0; a &lt; size; a++) {<br></td></tr
><tr
id=sl_svn42_154

><td class="source">    // Words occuring less than min_count times will be discarded from the vocab<br></td></tr
><tr
id=sl_svn42_155

><td class="source">    if ((vocab[a].cn &lt; min_count) &amp;&amp; (a != 0)) {<br></td></tr
><tr
id=sl_svn42_156

><td class="source">      vocab_size--;<br></td></tr
><tr
id=sl_svn42_157

><td class="source">      free(vocab[a].word);<br></td></tr
><tr
id=sl_svn42_158

><td class="source">    } else {<br></td></tr
><tr
id=sl_svn42_159

><td class="source">      // Hash will be re-computed, as after the sorting it is not actual<br></td></tr
><tr
id=sl_svn42_160

><td class="source">      hash=GetWordHash(vocab[a].word);<br></td></tr
><tr
id=sl_svn42_161

><td class="source">      while (vocab_hash[hash] != -1) hash = (hash + 1) % vocab_hash_size;<br></td></tr
><tr
id=sl_svn42_162

><td class="source">      vocab_hash[hash] = a;<br></td></tr
><tr
id=sl_svn42_163

><td class="source">      train_words += vocab[a].cn;<br></td></tr
><tr
id=sl_svn42_164

><td class="source">    }<br></td></tr
><tr
id=sl_svn42_165

><td class="source">  }<br></td></tr
><tr
id=sl_svn42_166

><td class="source">  vocab = (struct vocab_word *)realloc(vocab, (vocab_size + 1) * sizeof(struct vocab_word));<br></td></tr
><tr
id=sl_svn42_167

><td class="source">  // Allocate memory for the binary tree construction<br></td></tr
><tr
id=sl_svn42_168

><td class="source">  for (a = 0; a &lt; vocab_size; a++) {<br></td></tr
><tr
id=sl_svn42_169

><td class="source">    vocab[a].code = (char *)calloc(MAX_CODE_LENGTH, sizeof(char));<br></td></tr
><tr
id=sl_svn42_170

><td class="source">    vocab[a].point = (int *)calloc(MAX_CODE_LENGTH, sizeof(int));<br></td></tr
><tr
id=sl_svn42_171

><td class="source">  }<br></td></tr
><tr
id=sl_svn42_172

><td class="source">}<br></td></tr
><tr
id=sl_svn42_173

><td class="source"><br></td></tr
><tr
id=sl_svn42_174

><td class="source">// Reduces the vocabulary by removing infrequent tokens<br></td></tr
><tr
id=sl_svn42_175

><td class="source">void ReduceVocab() {<br></td></tr
><tr
id=sl_svn42_176

><td class="source">  int a, b = 0;<br></td></tr
><tr
id=sl_svn42_177

><td class="source">  unsigned int hash;<br></td></tr
><tr
id=sl_svn42_178

><td class="source">  for (a = 0; a &lt; vocab_size; a++) if (vocab[a].cn &gt; min_reduce) {<br></td></tr
><tr
id=sl_svn42_179

><td class="source">    vocab[b].cn = vocab[a].cn;<br></td></tr
><tr
id=sl_svn42_180

><td class="source">    vocab[b].word = vocab[a].word;<br></td></tr
><tr
id=sl_svn42_181

><td class="source">    b++;<br></td></tr
><tr
id=sl_svn42_182

><td class="source">  } else free(vocab[a].word);<br></td></tr
><tr
id=sl_svn42_183

><td class="source">  vocab_size = b;<br></td></tr
><tr
id=sl_svn42_184

><td class="source">  for (a = 0; a &lt; vocab_hash_size; a++) vocab_hash[a] = -1;<br></td></tr
><tr
id=sl_svn42_185

><td class="source">  for (a = 0; a &lt; vocab_size; a++) {<br></td></tr
><tr
id=sl_svn42_186

><td class="source">    // Hash will be re-computed, as it is not actual<br></td></tr
><tr
id=sl_svn42_187

><td class="source">    hash = GetWordHash(vocab[a].word);<br></td></tr
><tr
id=sl_svn42_188

><td class="source">    while (vocab_hash[hash] != -1) hash = (hash + 1) % vocab_hash_size;<br></td></tr
><tr
id=sl_svn42_189

><td class="source">    vocab_hash[hash] = a;<br></td></tr
><tr
id=sl_svn42_190

><td class="source">  }<br></td></tr
><tr
id=sl_svn42_191

><td class="source">  fflush(stdout);<br></td></tr
><tr
id=sl_svn42_192

><td class="source">  min_reduce++;<br></td></tr
><tr
id=sl_svn42_193

><td class="source">}<br></td></tr
><tr
id=sl_svn42_194

><td class="source"><br></td></tr
><tr
id=sl_svn42_195

><td class="source">// Create binary Huffman tree using the word counts<br></td></tr
><tr
id=sl_svn42_196

><td class="source">// Frequent words will have short uniqe binary codes<br></td></tr
><tr
id=sl_svn42_197

><td class="source">void CreateBinaryTree() {<br></td></tr
><tr
id=sl_svn42_198

><td class="source">  long long a, b, i, min1i, min2i, pos1, pos2, point[MAX_CODE_LENGTH];<br></td></tr
><tr
id=sl_svn42_199

><td class="source">  char code[MAX_CODE_LENGTH];<br></td></tr
><tr
id=sl_svn42_200

><td class="source">  long long *count = (long long *)calloc(vocab_size * 2 + 1, sizeof(long long));<br></td></tr
><tr
id=sl_svn42_201

><td class="source">  long long *binary = (long long *)calloc(vocab_size * 2 + 1, sizeof(long long));<br></td></tr
><tr
id=sl_svn42_202

><td class="source">  long long *parent_node = (long long *)calloc(vocab_size * 2 + 1, sizeof(long long));<br></td></tr
><tr
id=sl_svn42_203

><td class="source">  for (a = 0; a &lt; vocab_size; a++) count[a] = vocab[a].cn;<br></td></tr
><tr
id=sl_svn42_204

><td class="source">  for (a = vocab_size; a &lt; vocab_size * 2; a++) count[a] = 1e15;<br></td></tr
><tr
id=sl_svn42_205

><td class="source">  pos1 = vocab_size - 1;<br></td></tr
><tr
id=sl_svn42_206

><td class="source">  pos2 = vocab_size;<br></td></tr
><tr
id=sl_svn42_207

><td class="source">  // Following algorithm constructs the Huffman tree by adding one node at a time<br></td></tr
><tr
id=sl_svn42_208

><td class="source">  for (a = 0; a &lt; vocab_size - 1; a++) {<br></td></tr
><tr
id=sl_svn42_209

><td class="source">    // First, find two smallest nodes &#39;min1, min2&#39;<br></td></tr
><tr
id=sl_svn42_210

><td class="source">    if (pos1 &gt;= 0) {<br></td></tr
><tr
id=sl_svn42_211

><td class="source">      if (count[pos1] &lt; count[pos2]) {<br></td></tr
><tr
id=sl_svn42_212

><td class="source">        min1i = pos1;<br></td></tr
><tr
id=sl_svn42_213

><td class="source">        pos1--;<br></td></tr
><tr
id=sl_svn42_214

><td class="source">      } else {<br></td></tr
><tr
id=sl_svn42_215

><td class="source">        min1i = pos2;<br></td></tr
><tr
id=sl_svn42_216

><td class="source">        pos2++;<br></td></tr
><tr
id=sl_svn42_217

><td class="source">      }<br></td></tr
><tr
id=sl_svn42_218

><td class="source">    } else {<br></td></tr
><tr
id=sl_svn42_219

><td class="source">      min1i = pos2;<br></td></tr
><tr
id=sl_svn42_220

><td class="source">      pos2++;<br></td></tr
><tr
id=sl_svn42_221

><td class="source">    }<br></td></tr
><tr
id=sl_svn42_222

><td class="source">    if (pos1 &gt;= 0) {<br></td></tr
><tr
id=sl_svn42_223

><td class="source">      if (count[pos1] &lt; count[pos2]) {<br></td></tr
><tr
id=sl_svn42_224

><td class="source">        min2i = pos1;<br></td></tr
><tr
id=sl_svn42_225

><td class="source">        pos1--;<br></td></tr
><tr
id=sl_svn42_226

><td class="source">      } else {<br></td></tr
><tr
id=sl_svn42_227

><td class="source">        min2i = pos2;<br></td></tr
><tr
id=sl_svn42_228

><td class="source">        pos2++;<br></td></tr
><tr
id=sl_svn42_229

><td class="source">      }<br></td></tr
><tr
id=sl_svn42_230

><td class="source">    } else {<br></td></tr
><tr
id=sl_svn42_231

><td class="source">      min2i = pos2;<br></td></tr
><tr
id=sl_svn42_232

><td class="source">      pos2++;<br></td></tr
><tr
id=sl_svn42_233

><td class="source">    }<br></td></tr
><tr
id=sl_svn42_234

><td class="source">    count[vocab_size + a] = count[min1i] + count[min2i];<br></td></tr
><tr
id=sl_svn42_235

><td class="source">    parent_node[min1i] = vocab_size + a;<br></td></tr
><tr
id=sl_svn42_236

><td class="source">    parent_node[min2i] = vocab_size + a;<br></td></tr
><tr
id=sl_svn42_237

><td class="source">    binary[min2i] = 1;<br></td></tr
><tr
id=sl_svn42_238

><td class="source">  }<br></td></tr
><tr
id=sl_svn42_239

><td class="source">  // Now assign binary code to each vocabulary word<br></td></tr
><tr
id=sl_svn42_240

><td class="source">  for (a = 0; a &lt; vocab_size; a++) {<br></td></tr
><tr
id=sl_svn42_241

><td class="source">    b = a;<br></td></tr
><tr
id=sl_svn42_242

><td class="source">    i = 0;<br></td></tr
><tr
id=sl_svn42_243

><td class="source">    while (1) {<br></td></tr
><tr
id=sl_svn42_244

><td class="source">      code[i] = binary[b];<br></td></tr
><tr
id=sl_svn42_245

><td class="source">      point[i] = b;<br></td></tr
><tr
id=sl_svn42_246

><td class="source">      i++;<br></td></tr
><tr
id=sl_svn42_247

><td class="source">      b = parent_node[b];<br></td></tr
><tr
id=sl_svn42_248

><td class="source">      if (b == vocab_size * 2 - 2) break;<br></td></tr
><tr
id=sl_svn42_249

><td class="source">    }<br></td></tr
><tr
id=sl_svn42_250

><td class="source">    vocab[a].codelen = i;<br></td></tr
><tr
id=sl_svn42_251

><td class="source">    vocab[a].point[0] = vocab_size - 2;<br></td></tr
><tr
id=sl_svn42_252

><td class="source">    for (b = 0; b &lt; i; b++) {<br></td></tr
><tr
id=sl_svn42_253

><td class="source">      vocab[a].code[i - b - 1] = code[b];<br></td></tr
><tr
id=sl_svn42_254

><td class="source">      vocab[a].point[i - b] = point[b] - vocab_size;<br></td></tr
><tr
id=sl_svn42_255

><td class="source">    }<br></td></tr
><tr
id=sl_svn42_256

><td class="source">  }<br></td></tr
><tr
id=sl_svn42_257

><td class="source">  free(count);<br></td></tr
><tr
id=sl_svn42_258

><td class="source">  free(binary);<br></td></tr
><tr
id=sl_svn42_259

><td class="source">  free(parent_node);<br></td></tr
><tr
id=sl_svn42_260

><td class="source">}<br></td></tr
><tr
id=sl_svn42_261

><td class="source"><br></td></tr
><tr
id=sl_svn42_262

><td class="source">void LearnVocabFromTrainFile() {<br></td></tr
><tr
id=sl_svn42_263

><td class="source">  char word[MAX_STRING];<br></td></tr
><tr
id=sl_svn42_264

><td class="source">  FILE *fin;<br></td></tr
><tr
id=sl_svn42_265

><td class="source">  long long a, i;<br></td></tr
><tr
id=sl_svn42_266

><td class="source">  for (a = 0; a &lt; vocab_hash_size; a++) vocab_hash[a] = -1;<br></td></tr
><tr
id=sl_svn42_267

><td class="source">  fin = fopen(train_file, &quot;rb&quot;);<br></td></tr
><tr
id=sl_svn42_268

><td class="source">  if (fin == NULL) {<br></td></tr
><tr
id=sl_svn42_269

><td class="source">    printf(&quot;ERROR: training data file not found!\n&quot;);<br></td></tr
><tr
id=sl_svn42_270

><td class="source">    exit(1);<br></td></tr
><tr
id=sl_svn42_271

><td class="source">  }<br></td></tr
><tr
id=sl_svn42_272

><td class="source">  vocab_size = 0;<br></td></tr
><tr
id=sl_svn42_273

><td class="source">  AddWordToVocab((char *)&quot;&lt;/s&gt;&quot;);<br></td></tr
><tr
id=sl_svn42_274

><td class="source">  while (1) {<br></td></tr
><tr
id=sl_svn42_275

><td class="source">    ReadWord(word, fin);<br></td></tr
><tr
id=sl_svn42_276

><td class="source">    if (feof(fin)) break;<br></td></tr
><tr
id=sl_svn42_277

><td class="source">    train_words++;<br></td></tr
><tr
id=sl_svn42_278

><td class="source">    if ((debug_mode &gt; 1) &amp;&amp; (train_words % 100000 == 0)) {<br></td></tr
><tr
id=sl_svn42_279

><td class="source">      printf(&quot;%lldK%c&quot;, train_words / 1000, 13);<br></td></tr
><tr
id=sl_svn42_280

><td class="source">      fflush(stdout);<br></td></tr
><tr
id=sl_svn42_281

><td class="source">    }<br></td></tr
><tr
id=sl_svn42_282

><td class="source">    i = SearchVocab(word);<br></td></tr
><tr
id=sl_svn42_283

><td class="source">    if (i == -1) {<br></td></tr
><tr
id=sl_svn42_284

><td class="source">      a = AddWordToVocab(word);<br></td></tr
><tr
id=sl_svn42_285

><td class="source">      vocab[a].cn = 1;<br></td></tr
><tr
id=sl_svn42_286

><td class="source">    } else vocab[i].cn++;<br></td></tr
><tr
id=sl_svn42_287

><td class="source">    if (vocab_size &gt; vocab_hash_size * 0.7) ReduceVocab();<br></td></tr
><tr
id=sl_svn42_288

><td class="source">  }<br></td></tr
><tr
id=sl_svn42_289

><td class="source">  SortVocab();<br></td></tr
><tr
id=sl_svn42_290

><td class="source">  if (debug_mode &gt; 0) {<br></td></tr
><tr
id=sl_svn42_291

><td class="source">    printf(&quot;Vocab size: %lld\n&quot;, vocab_size);<br></td></tr
><tr
id=sl_svn42_292

><td class="source">    printf(&quot;Words in train file: %lld\n&quot;, train_words);<br></td></tr
><tr
id=sl_svn42_293

><td class="source">  }<br></td></tr
><tr
id=sl_svn42_294

><td class="source">  file_size = ftell(fin);<br></td></tr
><tr
id=sl_svn42_295

><td class="source">  fclose(fin);<br></td></tr
><tr
id=sl_svn42_296

><td class="source">}<br></td></tr
><tr
id=sl_svn42_297

><td class="source"><br></td></tr
><tr
id=sl_svn42_298

><td class="source">void SaveVocab() {<br></td></tr
><tr
id=sl_svn42_299

><td class="source">  long long i;<br></td></tr
><tr
id=sl_svn42_300

><td class="source">  FILE *fo = fopen(save_vocab_file, &quot;wb&quot;);<br></td></tr
><tr
id=sl_svn42_301

><td class="source">  for (i = 0; i &lt; vocab_size; i++) fprintf(fo, &quot;%s %lld\n&quot;, vocab[i].word, vocab[i].cn);<br></td></tr
><tr
id=sl_svn42_302

><td class="source">  fclose(fo);<br></td></tr
><tr
id=sl_svn42_303

><td class="source">}<br></td></tr
><tr
id=sl_svn42_304

><td class="source"><br></td></tr
><tr
id=sl_svn42_305

><td class="source">void ReadVocab() {<br></td></tr
><tr
id=sl_svn42_306

><td class="source">  long long a, i = 0;<br></td></tr
><tr
id=sl_svn42_307

><td class="source">  char c;<br></td></tr
><tr
id=sl_svn42_308

><td class="source">  char word[MAX_STRING];<br></td></tr
><tr
id=sl_svn42_309

><td class="source">  FILE *fin = fopen(read_vocab_file, &quot;rb&quot;);<br></td></tr
><tr
id=sl_svn42_310

><td class="source">  if (fin == NULL) {<br></td></tr
><tr
id=sl_svn42_311

><td class="source">    printf(&quot;Vocabulary file not found\n&quot;);<br></td></tr
><tr
id=sl_svn42_312

><td class="source">    exit(1);<br></td></tr
><tr
id=sl_svn42_313

><td class="source">  }<br></td></tr
><tr
id=sl_svn42_314

><td class="source">  for (a = 0; a &lt; vocab_hash_size; a++) vocab_hash[a] = -1;<br></td></tr
><tr
id=sl_svn42_315

><td class="source">  vocab_size = 0;<br></td></tr
><tr
id=sl_svn42_316

><td class="source">  while (1) {<br></td></tr
><tr
id=sl_svn42_317

><td class="source">    ReadWord(word, fin);<br></td></tr
><tr
id=sl_svn42_318

><td class="source">    if (feof(fin)) break;<br></td></tr
><tr
id=sl_svn42_319

><td class="source">    a = AddWordToVocab(word);<br></td></tr
><tr
id=sl_svn42_320

><td class="source">    fscanf(fin, &quot;%lld%c&quot;, &amp;vocab[a].cn, &amp;c);<br></td></tr
><tr
id=sl_svn42_321

><td class="source">    i++;<br></td></tr
><tr
id=sl_svn42_322

><td class="source">  }<br></td></tr
><tr
id=sl_svn42_323

><td class="source">  SortVocab();<br></td></tr
><tr
id=sl_svn42_324

><td class="source">  if (debug_mode &gt; 0) {<br></td></tr
><tr
id=sl_svn42_325

><td class="source">    printf(&quot;Vocab size: %lld\n&quot;, vocab_size);<br></td></tr
><tr
id=sl_svn42_326

><td class="source">    printf(&quot;Words in train file: %lld\n&quot;, train_words);<br></td></tr
><tr
id=sl_svn42_327

><td class="source">  }<br></td></tr
><tr
id=sl_svn42_328

><td class="source">  fin = fopen(train_file, &quot;rb&quot;);<br></td></tr
><tr
id=sl_svn42_329

><td class="source">  if (fin == NULL) {<br></td></tr
><tr
id=sl_svn42_330

><td class="source">    printf(&quot;ERROR: training data file not found!\n&quot;);<br></td></tr
><tr
id=sl_svn42_331

><td class="source">    exit(1);<br></td></tr
><tr
id=sl_svn42_332

><td class="source">  }<br></td></tr
><tr
id=sl_svn42_333

><td class="source">  fseek(fin, 0, SEEK_END);<br></td></tr
><tr
id=sl_svn42_334

><td class="source">  file_size = ftell(fin);<br></td></tr
><tr
id=sl_svn42_335

><td class="source">  fclose(fin);<br></td></tr
><tr
id=sl_svn42_336

><td class="source">}<br></td></tr
><tr
id=sl_svn42_337

><td class="source"><br></td></tr
><tr
id=sl_svn42_338

><td class="source">void InitNet() {<br></td></tr
><tr
id=sl_svn42_339

><td class="source">  long long a, b;<br></td></tr
><tr
id=sl_svn42_340

><td class="source">  unsigned long long next_random = 1;<br></td></tr
><tr
id=sl_svn42_341

><td class="source">  a = posix_memalign((void **)&amp;syn0, 128, (long long)vocab_size * layer1_size * sizeof(real));<br></td></tr
><tr
id=sl_svn42_342

><td class="source">  if (syn0 == NULL) {printf(&quot;Memory allocation failed\n&quot;); exit(1);}<br></td></tr
><tr
id=sl_svn42_343

><td class="source">  if (hs) {<br></td></tr
><tr
id=sl_svn42_344

><td class="source">    a = posix_memalign((void **)&amp;syn1, 128, (long long)vocab_size * layer1_size * sizeof(real));<br></td></tr
><tr
id=sl_svn42_345

><td class="source">    if (syn1 == NULL) {printf(&quot;Memory allocation failed\n&quot;); exit(1);}<br></td></tr
><tr
id=sl_svn42_346

><td class="source">    for (a = 0; a &lt; vocab_size; a++) for (b = 0; b &lt; layer1_size; b++)<br></td></tr
><tr
id=sl_svn42_347

><td class="source">     syn1[a * layer1_size + b] = 0;<br></td></tr
><tr
id=sl_svn42_348

><td class="source">  }<br></td></tr
><tr
id=sl_svn42_349

><td class="source">  if (negative&gt;0) {<br></td></tr
><tr
id=sl_svn42_350

><td class="source">    a = posix_memalign((void **)&amp;syn1neg, 128, (long long)vocab_size * layer1_size * sizeof(real));<br></td></tr
><tr
id=sl_svn42_351

><td class="source">    if (syn1neg == NULL) {printf(&quot;Memory allocation failed\n&quot;); exit(1);}<br></td></tr
><tr
id=sl_svn42_352

><td class="source">    for (a = 0; a &lt; vocab_size; a++) for (b = 0; b &lt; layer1_size; b++)<br></td></tr
><tr
id=sl_svn42_353

><td class="source">     syn1neg[a * layer1_size + b] = 0;<br></td></tr
><tr
id=sl_svn42_354

><td class="source">  }<br></td></tr
><tr
id=sl_svn42_355

><td class="source">  for (a = 0; a &lt; vocab_size; a++) for (b = 0; b &lt; layer1_size; b++) {<br></td></tr
><tr
id=sl_svn42_356

><td class="source">    next_random = next_random * (unsigned long long)25214903917 + 11;<br></td></tr
><tr
id=sl_svn42_357

><td class="source">    syn0[a * layer1_size + b] = (((next_random &amp; 0xFFFF) / (real)65536) - 0.5) / layer1_size;<br></td></tr
><tr
id=sl_svn42_358

><td class="source">  }<br></td></tr
><tr
id=sl_svn42_359

><td class="source">  CreateBinaryTree();<br></td></tr
><tr
id=sl_svn42_360

><td class="source">}<br></td></tr
><tr
id=sl_svn42_361

><td class="source"><br></td></tr
><tr
id=sl_svn42_362

><td class="source">void *TrainModelThread(void *id) {<br></td></tr
><tr
id=sl_svn42_363

><td class="source">  long long a, b, d, cw, word, last_word, sentence_length = 0, sentence_position = 0;<br></td></tr
><tr
id=sl_svn42_364

><td class="source">  long long word_count = 0, last_word_count = 0, sen[MAX_SENTENCE_LENGTH + 1];<br></td></tr
><tr
id=sl_svn42_365

><td class="source">  long long l1, l2, c, target, label, local_iter = iter;<br></td></tr
><tr
id=sl_svn42_366

><td class="source">  unsigned long long next_random = (long long)id;<br></td></tr
><tr
id=sl_svn42_367

><td class="source">  real f, g;<br></td></tr
><tr
id=sl_svn42_368

><td class="source">  clock_t now;<br></td></tr
><tr
id=sl_svn42_369

><td class="source">  real *neu1 = (real *)calloc(layer1_size, sizeof(real));<br></td></tr
><tr
id=sl_svn42_370

><td class="source">  real *neu1e = (real *)calloc(layer1_size, sizeof(real));<br></td></tr
><tr
id=sl_svn42_371

><td class="source">  FILE *fi = fopen(train_file, &quot;rb&quot;);<br></td></tr
><tr
id=sl_svn42_372

><td class="source">  fseek(fi, file_size / (long long)num_threads * (long long)id, SEEK_SET);<br></td></tr
><tr
id=sl_svn42_373

><td class="source">  while (1) {<br></td></tr
><tr
id=sl_svn42_374

><td class="source">    if (word_count - last_word_count &gt; 10000) {<br></td></tr
><tr
id=sl_svn42_375

><td class="source">      word_count_actual += word_count - last_word_count;<br></td></tr
><tr
id=sl_svn42_376

><td class="source">      last_word_count = word_count;<br></td></tr
><tr
id=sl_svn42_377

><td class="source">      if ((debug_mode &gt; 1)) {<br></td></tr
><tr
id=sl_svn42_378

><td class="source">        now=clock();<br></td></tr
><tr
id=sl_svn42_379

><td class="source">        printf(&quot;%cAlpha: %f  Progress: %.2f%%  Words/thread/sec: %.2fk  &quot;, 13, alpha,<br></td></tr
><tr
id=sl_svn42_380

><td class="source">         word_count_actual / (real)(iter * train_words + 1) * 100,<br></td></tr
><tr
id=sl_svn42_381

><td class="source">         word_count_actual / ((real)(now - start + 1) / (real)CLOCKS_PER_SEC * 1000));<br></td></tr
><tr
id=sl_svn42_382

><td class="source">        fflush(stdout);<br></td></tr
><tr
id=sl_svn42_383

><td class="source">      }<br></td></tr
><tr
id=sl_svn42_384

><td class="source">      alpha = starting_alpha * (1 - word_count_actual / (real)(iter * train_words + 1));<br></td></tr
><tr
id=sl_svn42_385

><td class="source">      if (alpha &lt; starting_alpha * 0.0001) alpha = starting_alpha * 0.0001;<br></td></tr
><tr
id=sl_svn42_386

><td class="source">    }<br></td></tr
><tr
id=sl_svn42_387

><td class="source">    if (sentence_length == 0) {<br></td></tr
><tr
id=sl_svn42_388

><td class="source">      while (1) {<br></td></tr
><tr
id=sl_svn42_389

><td class="source">        word = ReadWordIndex(fi);<br></td></tr
><tr
id=sl_svn42_390

><td class="source">        if (feof(fi)) break;<br></td></tr
><tr
id=sl_svn42_391

><td class="source">        if (word == -1) continue;<br></td></tr
><tr
id=sl_svn42_392

><td class="source">        word_count++;<br></td></tr
><tr
id=sl_svn42_393

><td class="source">        if (word == 0) break;<br></td></tr
><tr
id=sl_svn42_394

><td class="source">        // The subsampling randomly discards frequent words while keeping the ranking same<br></td></tr
><tr
id=sl_svn42_395

><td class="source">        if (sample &gt; 0) {<br></td></tr
><tr
id=sl_svn42_396

><td class="source">          real ran = (sqrt(vocab[word].cn / (sample * train_words)) + 1) * (sample * train_words) / vocab[word].cn;<br></td></tr
><tr
id=sl_svn42_397

><td class="source">          next_random = next_random * (unsigned long long)25214903917 + 11;<br></td></tr
><tr
id=sl_svn42_398

><td class="source">          if (ran &lt; (next_random &amp; 0xFFFF) / (real)65536) continue;<br></td></tr
><tr
id=sl_svn42_399

><td class="source">        }<br></td></tr
><tr
id=sl_svn42_400

><td class="source">        sen[sentence_length] = word;<br></td></tr
><tr
id=sl_svn42_401

><td class="source">        sentence_length++;<br></td></tr
><tr
id=sl_svn42_402

><td class="source">        if (sentence_length &gt;= MAX_SENTENCE_LENGTH) break;<br></td></tr
><tr
id=sl_svn42_403

><td class="source">      }<br></td></tr
><tr
id=sl_svn42_404

><td class="source">      sentence_position = 0;<br></td></tr
><tr
id=sl_svn42_405

><td class="source">    }<br></td></tr
><tr
id=sl_svn42_406

><td class="source">    if (feof(fi) || (word_count &gt; train_words / num_threads)) {<br></td></tr
><tr
id=sl_svn42_407

><td class="source">      word_count_actual += word_count - last_word_count;<br></td></tr
><tr
id=sl_svn42_408

><td class="source">      local_iter--;<br></td></tr
><tr
id=sl_svn42_409

><td class="source">      if (local_iter == 0) break;<br></td></tr
><tr
id=sl_svn42_410

><td class="source">      word_count = 0;<br></td></tr
><tr
id=sl_svn42_411

><td class="source">      last_word_count = 0;<br></td></tr
><tr
id=sl_svn42_412

><td class="source">      sentence_length = 0;<br></td></tr
><tr
id=sl_svn42_413

><td class="source">      fseek(fi, file_size / (long long)num_threads * (long long)id, SEEK_SET);<br></td></tr
><tr
id=sl_svn42_414

><td class="source">      continue;<br></td></tr
><tr
id=sl_svn42_415

><td class="source">    }<br></td></tr
><tr
id=sl_svn42_416

><td class="source">    word = sen[sentence_position];<br></td></tr
><tr
id=sl_svn42_417

><td class="source">    if (word == -1) continue;<br></td></tr
><tr
id=sl_svn42_418

><td class="source">    for (c = 0; c &lt; layer1_size; c++) neu1[c] = 0;<br></td></tr
><tr
id=sl_svn42_419

><td class="source">    for (c = 0; c &lt; layer1_size; c++) neu1e[c] = 0;<br></td></tr
><tr
id=sl_svn42_420

><td class="source">    next_random = next_random * (unsigned long long)25214903917 + 11;<br></td></tr
><tr
id=sl_svn42_421

><td class="source">    b = next_random % window;<br></td></tr
><tr
id=sl_svn42_422

><td class="source">    if (cbow) {  //train the cbow architecture<br></td></tr
><tr
id=sl_svn42_423

><td class="source">      // in -&gt; hidden<br></td></tr
><tr
id=sl_svn42_424

><td class="source">      cw = 0;<br></td></tr
><tr
id=sl_svn42_425

><td class="source">      for (a = b; a &lt; window * 2 + 1 - b; a++) if (a != window) {<br></td></tr
><tr
id=sl_svn42_426

><td class="source">        c = sentence_position - window + a;<br></td></tr
><tr
id=sl_svn42_427

><td class="source">        if (c &lt; 0) continue;<br></td></tr
><tr
id=sl_svn42_428

><td class="source">        if (c &gt;= sentence_length) continue;<br></td></tr
><tr
id=sl_svn42_429

><td class="source">        last_word = sen[c];<br></td></tr
><tr
id=sl_svn42_430

><td class="source">        if (last_word == -1) continue;<br></td></tr
><tr
id=sl_svn42_431

><td class="source">        for (c = 0; c &lt; layer1_size; c++) neu1[c] += syn0[c + last_word * layer1_size];<br></td></tr
><tr
id=sl_svn42_432

><td class="source">        cw++;<br></td></tr
><tr
id=sl_svn42_433

><td class="source">      }<br></td></tr
><tr
id=sl_svn42_434

><td class="source">      if (cw) {<br></td></tr
><tr
id=sl_svn42_435

><td class="source">        for (c = 0; c &lt; layer1_size; c++) neu1[c] /= cw;<br></td></tr
><tr
id=sl_svn42_436

><td class="source">        if (hs) for (d = 0; d &lt; vocab[word].codelen; d++) {<br></td></tr
><tr
id=sl_svn42_437

><td class="source">          f = 0;<br></td></tr
><tr
id=sl_svn42_438

><td class="source">          l2 = vocab[word].point[d] * layer1_size;<br></td></tr
><tr
id=sl_svn42_439

><td class="source">          // Propagate hidden -&gt; output<br></td></tr
><tr
id=sl_svn42_440

><td class="source">          for (c = 0; c &lt; layer1_size; c++) f += neu1[c] * syn1[c + l2];<br></td></tr
><tr
id=sl_svn42_441

><td class="source">          if (f &lt;= -MAX_EXP) continue;<br></td></tr
><tr
id=sl_svn42_442

><td class="source">          else if (f &gt;= MAX_EXP) continue;<br></td></tr
><tr
id=sl_svn42_443

><td class="source">          else f = expTable[(int)((f + MAX_EXP) * (EXP_TABLE_SIZE / MAX_EXP / 2))];<br></td></tr
><tr
id=sl_svn42_444

><td class="source">          // &#39;g&#39; is the gradient multiplied by the learning rate<br></td></tr
><tr
id=sl_svn42_445

><td class="source">          g = (1 - vocab[word].code[d] - f) * alpha;<br></td></tr
><tr
id=sl_svn42_446

><td class="source">          // Propagate errors output -&gt; hidden<br></td></tr
><tr
id=sl_svn42_447

><td class="source">          for (c = 0; c &lt; layer1_size; c++) neu1e[c] += g * syn1[c + l2];<br></td></tr
><tr
id=sl_svn42_448

><td class="source">          // Learn weights hidden -&gt; output<br></td></tr
><tr
id=sl_svn42_449

><td class="source">          for (c = 0; c &lt; layer1_size; c++) syn1[c + l2] += g * neu1[c];<br></td></tr
><tr
id=sl_svn42_450

><td class="source">        }<br></td></tr
><tr
id=sl_svn42_451

><td class="source">        // NEGATIVE SAMPLING<br></td></tr
><tr
id=sl_svn42_452

><td class="source">        if (negative &gt; 0) for (d = 0; d &lt; negative + 1; d++) {<br></td></tr
><tr
id=sl_svn42_453

><td class="source">          if (d == 0) {<br></td></tr
><tr
id=sl_svn42_454

><td class="source">            target = word;<br></td></tr
><tr
id=sl_svn42_455

><td class="source">            label = 1;<br></td></tr
><tr
id=sl_svn42_456

><td class="source">          } else {<br></td></tr
><tr
id=sl_svn42_457

><td class="source">            next_random = next_random * (unsigned long long)25214903917 + 11;<br></td></tr
><tr
id=sl_svn42_458

><td class="source">            target = table[(next_random &gt;&gt; 16) % table_size];<br></td></tr
><tr
id=sl_svn42_459

><td class="source">            if (target == 0) target = next_random % (vocab_size - 1) + 1;<br></td></tr
><tr
id=sl_svn42_460

><td class="source">            if (target == word) continue;<br></td></tr
><tr
id=sl_svn42_461

><td class="source">            label = 0;<br></td></tr
><tr
id=sl_svn42_462

><td class="source">          }<br></td></tr
><tr
id=sl_svn42_463

><td class="source">          l2 = target * layer1_size;<br></td></tr
><tr
id=sl_svn42_464

><td class="source">          f = 0;<br></td></tr
><tr
id=sl_svn42_465

><td class="source">          for (c = 0; c &lt; layer1_size; c++) f += neu1[c] * syn1neg[c + l2];<br></td></tr
><tr
id=sl_svn42_466

><td class="source">          if (f &gt; MAX_EXP) g = (label - 1) * alpha;<br></td></tr
><tr
id=sl_svn42_467

><td class="source">          else if (f &lt; -MAX_EXP) g = (label - 0) * alpha;<br></td></tr
><tr
id=sl_svn42_468

><td class="source">          else g = (label - expTable[(int)((f + MAX_EXP) * (EXP_TABLE_SIZE / MAX_EXP / 2))]) * alpha;<br></td></tr
><tr
id=sl_svn42_469

><td class="source">          for (c = 0; c &lt; layer1_size; c++) neu1e[c] += g * syn1neg[c + l2];<br></td></tr
><tr
id=sl_svn42_470

><td class="source">          for (c = 0; c &lt; layer1_size; c++) syn1neg[c + l2] += g * neu1[c];<br></td></tr
><tr
id=sl_svn42_471

><td class="source">        }<br></td></tr
><tr
id=sl_svn42_472

><td class="source">        // hidden -&gt; in<br></td></tr
><tr
id=sl_svn42_473

><td class="source">        for (a = b; a &lt; window * 2 + 1 - b; a++) if (a != window) {<br></td></tr
><tr
id=sl_svn42_474

><td class="source">          c = sentence_position - window + a;<br></td></tr
><tr
id=sl_svn42_475

><td class="source">          if (c &lt; 0) continue;<br></td></tr
><tr
id=sl_svn42_476

><td class="source">          if (c &gt;= sentence_length) continue;<br></td></tr
><tr
id=sl_svn42_477

><td class="source">          last_word = sen[c];<br></td></tr
><tr
id=sl_svn42_478

><td class="source">          if (last_word == -1) continue;<br></td></tr
><tr
id=sl_svn42_479

><td class="source">          for (c = 0; c &lt; layer1_size; c++) syn0[c + last_word * layer1_size] += neu1e[c];<br></td></tr
><tr
id=sl_svn42_480

><td class="source">        }<br></td></tr
><tr
id=sl_svn42_481

><td class="source">      }<br></td></tr
><tr
id=sl_svn42_482

><td class="source">    } else {  //train skip-gram<br></td></tr
><tr
id=sl_svn42_483

><td class="source">      for (a = b; a &lt; window * 2 + 1 - b; a++) if (a != window) {<br></td></tr
><tr
id=sl_svn42_484

><td class="source">        c = sentence_position - window + a;<br></td></tr
><tr
id=sl_svn42_485

><td class="source">        if (c &lt; 0) continue;<br></td></tr
><tr
id=sl_svn42_486

><td class="source">        if (c &gt;= sentence_length) continue;<br></td></tr
><tr
id=sl_svn42_487

><td class="source">        last_word = sen[c];<br></td></tr
><tr
id=sl_svn42_488

><td class="source">        if (last_word == -1) continue;<br></td></tr
><tr
id=sl_svn42_489

><td class="source">        l1 = last_word * layer1_size;<br></td></tr
><tr
id=sl_svn42_490

><td class="source">        for (c = 0; c &lt; layer1_size; c++) neu1e[c] = 0;<br></td></tr
><tr
id=sl_svn42_491

><td class="source">        // HIERARCHICAL SOFTMAX<br></td></tr
><tr
id=sl_svn42_492

><td class="source">        if (hs) for (d = 0; d &lt; vocab[word].codelen; d++) {<br></td></tr
><tr
id=sl_svn42_493

><td class="source">          f = 0;<br></td></tr
><tr
id=sl_svn42_494

><td class="source">          l2 = vocab[word].point[d] * layer1_size;<br></td></tr
><tr
id=sl_svn42_495

><td class="source">          // Propagate hidden -&gt; output<br></td></tr
><tr
id=sl_svn42_496

><td class="source">          for (c = 0; c &lt; layer1_size; c++) f += syn0[c + l1] * syn1[c + l2];<br></td></tr
><tr
id=sl_svn42_497

><td class="source">          if (f &lt;= -MAX_EXP) continue;<br></td></tr
><tr
id=sl_svn42_498

><td class="source">          else if (f &gt;= MAX_EXP) continue;<br></td></tr
><tr
id=sl_svn42_499

><td class="source">          else f = expTable[(int)((f + MAX_EXP) * (EXP_TABLE_SIZE / MAX_EXP / 2))];<br></td></tr
><tr
id=sl_svn42_500

><td class="source">          // &#39;g&#39; is the gradient multiplied by the learning rate<br></td></tr
><tr
id=sl_svn42_501

><td class="source">          g = (1 - vocab[word].code[d] - f) * alpha;<br></td></tr
><tr
id=sl_svn42_502

><td class="source">          // Propagate errors output -&gt; hidden<br></td></tr
><tr
id=sl_svn42_503

><td class="source">          for (c = 0; c &lt; layer1_size; c++) neu1e[c] += g * syn1[c + l2];<br></td></tr
><tr
id=sl_svn42_504

><td class="source">          // Learn weights hidden -&gt; output<br></td></tr
><tr
id=sl_svn42_505

><td class="source">          for (c = 0; c &lt; layer1_size; c++) syn1[c + l2] += g * syn0[c + l1];<br></td></tr
><tr
id=sl_svn42_506

><td class="source">        }<br></td></tr
><tr
id=sl_svn42_507

><td class="source">        // NEGATIVE SAMPLING<br></td></tr
><tr
id=sl_svn42_508

><td class="source">        if (negative &gt; 0) for (d = 0; d &lt; negative + 1; d++) {<br></td></tr
><tr
id=sl_svn42_509

><td class="source">          if (d == 0) {<br></td></tr
><tr
id=sl_svn42_510

><td class="source">            target = word;<br></td></tr
><tr
id=sl_svn42_511

><td class="source">            label = 1;<br></td></tr
><tr
id=sl_svn42_512

><td class="source">          } else {<br></td></tr
><tr
id=sl_svn42_513

><td class="source">            next_random = next_random * (unsigned long long)25214903917 + 11;<br></td></tr
><tr
id=sl_svn42_514

><td class="source">            target = table[(next_random &gt;&gt; 16) % table_size];<br></td></tr
><tr
id=sl_svn42_515

><td class="source">            if (target == 0) target = next_random % (vocab_size - 1) + 1;<br></td></tr
><tr
id=sl_svn42_516

><td class="source">            if (target == word) continue;<br></td></tr
><tr
id=sl_svn42_517

><td class="source">            label = 0;<br></td></tr
><tr
id=sl_svn42_518

><td class="source">          }<br></td></tr
><tr
id=sl_svn42_519

><td class="source">          l2 = target * layer1_size;<br></td></tr
><tr
id=sl_svn42_520

><td class="source">          f = 0;<br></td></tr
><tr
id=sl_svn42_521

><td class="source">          for (c = 0; c &lt; layer1_size; c++) f += syn0[c + l1] * syn1neg[c + l2];<br></td></tr
><tr
id=sl_svn42_522

><td class="source">          if (f &gt; MAX_EXP) g = (label - 1) * alpha;<br></td></tr
><tr
id=sl_svn42_523

><td class="source">          else if (f &lt; -MAX_EXP) g = (label - 0) * alpha;<br></td></tr
><tr
id=sl_svn42_524

><td class="source">          else g = (label - expTable[(int)((f + MAX_EXP) * (EXP_TABLE_SIZE / MAX_EXP / 2))]) * alpha;<br></td></tr
><tr
id=sl_svn42_525

><td class="source">          for (c = 0; c &lt; layer1_size; c++) neu1e[c] += g * syn1neg[c + l2];<br></td></tr
><tr
id=sl_svn42_526

><td class="source">          for (c = 0; c &lt; layer1_size; c++) syn1neg[c + l2] += g * syn0[c + l1];<br></td></tr
><tr
id=sl_svn42_527

><td class="source">        }<br></td></tr
><tr
id=sl_svn42_528

><td class="source">        // Learn weights input -&gt; hidden<br></td></tr
><tr
id=sl_svn42_529

><td class="source">        for (c = 0; c &lt; layer1_size; c++) syn0[c + l1] += neu1e[c];<br></td></tr
><tr
id=sl_svn42_530

><td class="source">      }<br></td></tr
><tr
id=sl_svn42_531

><td class="source">    }<br></td></tr
><tr
id=sl_svn42_532

><td class="source">    sentence_position++;<br></td></tr
><tr
id=sl_svn42_533

><td class="source">    if (sentence_position &gt;= sentence_length) {<br></td></tr
><tr
id=sl_svn42_534

><td class="source">      sentence_length = 0;<br></td></tr
><tr
id=sl_svn42_535

><td class="source">      continue;<br></td></tr
><tr
id=sl_svn42_536

><td class="source">    }<br></td></tr
><tr
id=sl_svn42_537

><td class="source">  }<br></td></tr
><tr
id=sl_svn42_538

><td class="source">  fclose(fi);<br></td></tr
><tr
id=sl_svn42_539

><td class="source">  free(neu1);<br></td></tr
><tr
id=sl_svn42_540

><td class="source">  free(neu1e);<br></td></tr
><tr
id=sl_svn42_541

><td class="source">  pthread_exit(NULL);<br></td></tr
><tr
id=sl_svn42_542

><td class="source">}<br></td></tr
><tr
id=sl_svn42_543

><td class="source"><br></td></tr
><tr
id=sl_svn42_544

><td class="source">void TrainModel() {<br></td></tr
><tr
id=sl_svn42_545

><td class="source">  long a, b, c, d;<br></td></tr
><tr
id=sl_svn42_546

><td class="source">  FILE *fo;<br></td></tr
><tr
id=sl_svn42_547

><td class="source">  pthread_t *pt = (pthread_t *)malloc(num_threads * sizeof(pthread_t));<br></td></tr
><tr
id=sl_svn42_548

><td class="source">  printf(&quot;Starting training using file %s\n&quot;, train_file);<br></td></tr
><tr
id=sl_svn42_549

><td class="source">  starting_alpha = alpha;<br></td></tr
><tr
id=sl_svn42_550

><td class="source">  if (read_vocab_file[0] != 0) ReadVocab(); else LearnVocabFromTrainFile();<br></td></tr
><tr
id=sl_svn42_551

><td class="source">  if (save_vocab_file[0] != 0) SaveVocab();<br></td></tr
><tr
id=sl_svn42_552

><td class="source">  if (output_file[0] == 0) return;<br></td></tr
><tr
id=sl_svn42_553

><td class="source">  InitNet();<br></td></tr
><tr
id=sl_svn42_554

><td class="source">  if (negative &gt; 0) InitUnigramTable();<br></td></tr
><tr
id=sl_svn42_555

><td class="source">  start = clock();<br></td></tr
><tr
id=sl_svn42_556

><td class="source">  for (a = 0; a &lt; num_threads; a++) pthread_create(&amp;pt[a], NULL, TrainModelThread, (void *)a);<br></td></tr
><tr
id=sl_svn42_557

><td class="source">  for (a = 0; a &lt; num_threads; a++) pthread_join(pt[a], NULL);<br></td></tr
><tr
id=sl_svn42_558

><td class="source">  fo = fopen(output_file, &quot;wb&quot;);<br></td></tr
><tr
id=sl_svn42_559

><td class="source">  if (classes == 0) {<br></td></tr
><tr
id=sl_svn42_560

><td class="source">    // Save the word vectors<br></td></tr
><tr
id=sl_svn42_561

><td class="source">    fprintf(fo, &quot;%lld %lld\n&quot;, vocab_size, layer1_size);<br></td></tr
><tr
id=sl_svn42_562

><td class="source">    for (a = 0; a &lt; vocab_size; a++) {<br></td></tr
><tr
id=sl_svn42_563

><td class="source">      fprintf(fo, &quot;%s &quot;, vocab[a].word);<br></td></tr
><tr
id=sl_svn42_564

><td class="source">      if (binary) for (b = 0; b &lt; layer1_size; b++) fwrite(&amp;syn0[a * layer1_size + b], sizeof(real), 1, fo);<br></td></tr
><tr
id=sl_svn42_565

><td class="source">      else for (b = 0; b &lt; layer1_size; b++) fprintf(fo, &quot;%lf &quot;, syn0[a * layer1_size + b]);<br></td></tr
><tr
id=sl_svn42_566

><td class="source">      fprintf(fo, &quot;\n&quot;);<br></td></tr
><tr
id=sl_svn42_567

><td class="source">    }<br></td></tr
><tr
id=sl_svn42_568

><td class="source">  } else {<br></td></tr
><tr
id=sl_svn42_569

><td class="source">    // Run K-means on the word vectors<br></td></tr
><tr
id=sl_svn42_570

><td class="source">    int clcn = classes, iter = 10, closeid;<br></td></tr
><tr
id=sl_svn42_571

><td class="source">    int *centcn = (int *)malloc(classes * sizeof(int));<br></td></tr
><tr
id=sl_svn42_572

><td class="source">    int *cl = (int *)calloc(vocab_size, sizeof(int));<br></td></tr
><tr
id=sl_svn42_573

><td class="source">    real closev, x;<br></td></tr
><tr
id=sl_svn42_574

><td class="source">    real *cent = (real *)calloc(classes * layer1_size, sizeof(real));<br></td></tr
><tr
id=sl_svn42_575

><td class="source">    for (a = 0; a &lt; vocab_size; a++) cl[a] = a % clcn;<br></td></tr
><tr
id=sl_svn42_576

><td class="source">    for (a = 0; a &lt; iter; a++) {<br></td></tr
><tr
id=sl_svn42_577

><td class="source">      for (b = 0; b &lt; clcn * layer1_size; b++) cent[b] = 0;<br></td></tr
><tr
id=sl_svn42_578

><td class="source">      for (b = 0; b &lt; clcn; b++) centcn[b] = 1;<br></td></tr
><tr
id=sl_svn42_579

><td class="source">      for (c = 0; c &lt; vocab_size; c++) {<br></td></tr
><tr
id=sl_svn42_580

><td class="source">        for (d = 0; d &lt; layer1_size; d++) cent[layer1_size * cl[c] + d] += syn0[c * layer1_size + d];<br></td></tr
><tr
id=sl_svn42_581

><td class="source">        centcn[cl[c]]++;<br></td></tr
><tr
id=sl_svn42_582

><td class="source">      }<br></td></tr
><tr
id=sl_svn42_583

><td class="source">      for (b = 0; b &lt; clcn; b++) {<br></td></tr
><tr
id=sl_svn42_584

><td class="source">        closev = 0;<br></td></tr
><tr
id=sl_svn42_585

><td class="source">        for (c = 0; c &lt; layer1_size; c++) {<br></td></tr
><tr
id=sl_svn42_586

><td class="source">          cent[layer1_size * b + c] /= centcn[b];<br></td></tr
><tr
id=sl_svn42_587

><td class="source">          closev += cent[layer1_size * b + c] * cent[layer1_size * b + c];<br></td></tr
><tr
id=sl_svn42_588

><td class="source">        }<br></td></tr
><tr
id=sl_svn42_589

><td class="source">        closev = sqrt(closev);<br></td></tr
><tr
id=sl_svn42_590

><td class="source">        for (c = 0; c &lt; layer1_size; c++) cent[layer1_size * b + c] /= closev;<br></td></tr
><tr
id=sl_svn42_591

><td class="source">      }<br></td></tr
><tr
id=sl_svn42_592

><td class="source">      for (c = 0; c &lt; vocab_size; c++) {<br></td></tr
><tr
id=sl_svn42_593

><td class="source">        closev = -10;<br></td></tr
><tr
id=sl_svn42_594

><td class="source">        closeid = 0;<br></td></tr
><tr
id=sl_svn42_595

><td class="source">        for (d = 0; d &lt; clcn; d++) {<br></td></tr
><tr
id=sl_svn42_596

><td class="source">          x = 0;<br></td></tr
><tr
id=sl_svn42_597

><td class="source">          for (b = 0; b &lt; layer1_size; b++) x += cent[layer1_size * d + b] * syn0[c * layer1_size + b];<br></td></tr
><tr
id=sl_svn42_598

><td class="source">          if (x &gt; closev) {<br></td></tr
><tr
id=sl_svn42_599

><td class="source">            closev = x;<br></td></tr
><tr
id=sl_svn42_600

><td class="source">            closeid = d;<br></td></tr
><tr
id=sl_svn42_601

><td class="source">          }<br></td></tr
><tr
id=sl_svn42_602

><td class="source">        }<br></td></tr
><tr
id=sl_svn42_603

><td class="source">        cl[c] = closeid;<br></td></tr
><tr
id=sl_svn42_604

><td class="source">      }<br></td></tr
><tr
id=sl_svn42_605

><td class="source">    }<br></td></tr
><tr
id=sl_svn42_606

><td class="source">    // Save the K-means classes<br></td></tr
><tr
id=sl_svn42_607

><td class="source">    for (a = 0; a &lt; vocab_size; a++) fprintf(fo, &quot;%s %d\n&quot;, vocab[a].word, cl[a]);<br></td></tr
><tr
id=sl_svn42_608

><td class="source">    free(centcn);<br></td></tr
><tr
id=sl_svn42_609

><td class="source">    free(cent);<br></td></tr
><tr
id=sl_svn42_610

><td class="source">    free(cl);<br></td></tr
><tr
id=sl_svn42_611

><td class="source">  }<br></td></tr
><tr
id=sl_svn42_612

><td class="source">  fclose(fo);<br></td></tr
><tr
id=sl_svn42_613

><td class="source">}<br></td></tr
><tr
id=sl_svn42_614

><td class="source"><br></td></tr
><tr
id=sl_svn42_615

><td class="source">int ArgPos(char *str, int argc, char **argv) {<br></td></tr
><tr
id=sl_svn42_616

><td class="source">  int a;<br></td></tr
><tr
id=sl_svn42_617

><td class="source">  for (a = 1; a &lt; argc; a++) if (!strcmp(str, argv[a])) {<br></td></tr
><tr
id=sl_svn42_618

><td class="source">    if (a == argc - 1) {<br></td></tr
><tr
id=sl_svn42_619

><td class="source">      printf(&quot;Argument missing for %s\n&quot;, str);<br></td></tr
><tr
id=sl_svn42_620

><td class="source">      exit(1);<br></td></tr
><tr
id=sl_svn42_621

><td class="source">    }<br></td></tr
><tr
id=sl_svn42_622

><td class="source">    return a;<br></td></tr
><tr
id=sl_svn42_623

><td class="source">  }<br></td></tr
><tr
id=sl_svn42_624

><td class="source">  return -1;<br></td></tr
><tr
id=sl_svn42_625

><td class="source">}<br></td></tr
><tr
id=sl_svn42_626

><td class="source"><br></td></tr
><tr
id=sl_svn42_627

><td class="source">int main(int argc, char **argv) {<br></td></tr
><tr
id=sl_svn42_628

><td class="source">  int i;<br></td></tr
><tr
id=sl_svn42_629

><td class="source">  if (argc == 1) {<br></td></tr
><tr
id=sl_svn42_630

><td class="source">    printf(&quot;WORD VECTOR estimation toolkit v 0.1c\n\n&quot;);<br></td></tr
><tr
id=sl_svn42_631

><td class="source">    printf(&quot;Options:\n&quot;);<br></td></tr
><tr
id=sl_svn42_632

><td class="source">    printf(&quot;Parameters for training:\n&quot;);<br></td></tr
><tr
id=sl_svn42_633

><td class="source">    printf(&quot;\t-train &lt;file&gt;\n&quot;);<br></td></tr
><tr
id=sl_svn42_634

><td class="source">    printf(&quot;\t\tUse text data from &lt;file&gt; to train the model\n&quot;);<br></td></tr
><tr
id=sl_svn42_635

><td class="source">    printf(&quot;\t-output &lt;file&gt;\n&quot;);<br></td></tr
><tr
id=sl_svn42_636

><td class="source">    printf(&quot;\t\tUse &lt;file&gt; to save the resulting word vectors / word clusters\n&quot;);<br></td></tr
><tr
id=sl_svn42_637

><td class="source">    printf(&quot;\t-size &lt;int&gt;\n&quot;);<br></td></tr
><tr
id=sl_svn42_638

><td class="source">    printf(&quot;\t\tSet size of word vectors; default is 100\n&quot;);<br></td></tr
><tr
id=sl_svn42_639

><td class="source">    printf(&quot;\t-window &lt;int&gt;\n&quot;);<br></td></tr
><tr
id=sl_svn42_640

><td class="source">    printf(&quot;\t\tSet max skip length between words; default is 5\n&quot;);<br></td></tr
><tr
id=sl_svn42_641

><td class="source">    printf(&quot;\t-sample &lt;float&gt;\n&quot;);<br></td></tr
><tr
id=sl_svn42_642

><td class="source">    printf(&quot;\t\tSet threshold for occurrence of words. Those that appear with higher frequency in the training data\n&quot;);<br></td></tr
><tr
id=sl_svn42_643

><td class="source">    printf(&quot;\t\twill be randomly down-sampled; default is 1e-3, useful range is (0, 1e-5)\n&quot;);<br></td></tr
><tr
id=sl_svn42_644

><td class="source">    printf(&quot;\t-hs &lt;int&gt;\n&quot;);<br></td></tr
><tr
id=sl_svn42_645

><td class="source">    printf(&quot;\t\tUse Hierarchical Softmax; default is 0 (not used)\n&quot;);<br></td></tr
><tr
id=sl_svn42_646

><td class="source">    printf(&quot;\t-negative &lt;int&gt;\n&quot;);<br></td></tr
><tr
id=sl_svn42_647

><td class="source">    printf(&quot;\t\tNumber of negative examples; default is 5, common values are 3 - 10 (0 = not used)\n&quot;);<br></td></tr
><tr
id=sl_svn42_648

><td class="source">    printf(&quot;\t-threads &lt;int&gt;\n&quot;);<br></td></tr
><tr
id=sl_svn42_649

><td class="source">    printf(&quot;\t\tUse &lt;int&gt; threads (default 12)\n&quot;);<br></td></tr
><tr
id=sl_svn42_650

><td class="source">    printf(&quot;\t-iter &lt;int&gt;\n&quot;);<br></td></tr
><tr
id=sl_svn42_651

><td class="source">    printf(&quot;\t\tRun more training iterations (default 5)\n&quot;);<br></td></tr
><tr
id=sl_svn42_652

><td class="source">    printf(&quot;\t-min-count &lt;int&gt;\n&quot;);<br></td></tr
><tr
id=sl_svn42_653

><td class="source">    printf(&quot;\t\tThis will discard words that appear less than &lt;int&gt; times; default is 5\n&quot;);<br></td></tr
><tr
id=sl_svn42_654

><td class="source">    printf(&quot;\t-alpha &lt;float&gt;\n&quot;);<br></td></tr
><tr
id=sl_svn42_655

><td class="source">    printf(&quot;\t\tSet the starting learning rate; default is 0.025 for skip-gram and 0.05 for CBOW\n&quot;);<br></td></tr
><tr
id=sl_svn42_656

><td class="source">    printf(&quot;\t-classes &lt;int&gt;\n&quot;);<br></td></tr
><tr
id=sl_svn42_657

><td class="source">    printf(&quot;\t\tOutput word classes rather than word vectors; default number of classes is 0 (vectors are written)\n&quot;);<br></td></tr
><tr
id=sl_svn42_658

><td class="source">    printf(&quot;\t-debug &lt;int&gt;\n&quot;);<br></td></tr
><tr
id=sl_svn42_659

><td class="source">    printf(&quot;\t\tSet the debug mode (default = 2 = more info during training)\n&quot;);<br></td></tr
><tr
id=sl_svn42_660

><td class="source">    printf(&quot;\t-binary &lt;int&gt;\n&quot;);<br></td></tr
><tr
id=sl_svn42_661

><td class="source">    printf(&quot;\t\tSave the resulting vectors in binary moded; default is 0 (off)\n&quot;);<br></td></tr
><tr
id=sl_svn42_662

><td class="source">    printf(&quot;\t-save-vocab &lt;file&gt;\n&quot;);<br></td></tr
><tr
id=sl_svn42_663

><td class="source">    printf(&quot;\t\tThe vocabulary will be saved to &lt;file&gt;\n&quot;);<br></td></tr
><tr
id=sl_svn42_664

><td class="source">    printf(&quot;\t-read-vocab &lt;file&gt;\n&quot;);<br></td></tr
><tr
id=sl_svn42_665

><td class="source">    printf(&quot;\t\tThe vocabulary will be read from &lt;file&gt;, not constructed from the training data\n&quot;);<br></td></tr
><tr
id=sl_svn42_666

><td class="source">    printf(&quot;\t-cbow &lt;int&gt;\n&quot;);<br></td></tr
><tr
id=sl_svn42_667

><td class="source">    printf(&quot;\t\tUse the continuous bag of words model; default is 1 (use 0 for skip-gram model)\n&quot;);<br></td></tr
><tr
id=sl_svn42_668

><td class="source">    printf(&quot;\nExamples:\n&quot;);<br></td></tr
><tr
id=sl_svn42_669

><td class="source">    printf(&quot;./word2vec -train data.txt -output vec.txt -size 200 -window 5 -sample 1e-4 -negative 5 -hs 0 -binary 0 -cbow 1 -iter 3\n\n&quot;);<br></td></tr
><tr
id=sl_svn42_670

><td class="source">    return 0;<br></td></tr
><tr
id=sl_svn42_671

><td class="source">  }<br></td></tr
><tr
id=sl_svn42_672

><td class="source">  output_file[0] = 0;<br></td></tr
><tr
id=sl_svn42_673

><td class="source">  save_vocab_file[0] = 0;<br></td></tr
><tr
id=sl_svn42_674

><td class="source">  read_vocab_file[0] = 0;<br></td></tr
><tr
id=sl_svn42_675

><td class="source">  if ((i = ArgPos((char *)&quot;-size&quot;, argc, argv)) &gt; 0) layer1_size = atoi(argv[i + 1]);<br></td></tr
><tr
id=sl_svn42_676

><td class="source">  if ((i = ArgPos((char *)&quot;-train&quot;, argc, argv)) &gt; 0) strcpy(train_file, argv[i + 1]);<br></td></tr
><tr
id=sl_svn42_677

><td class="source">  if ((i = ArgPos((char *)&quot;-save-vocab&quot;, argc, argv)) &gt; 0) strcpy(save_vocab_file, argv[i + 1]);<br></td></tr
><tr
id=sl_svn42_678

><td class="source">  if ((i = ArgPos((char *)&quot;-read-vocab&quot;, argc, argv)) &gt; 0) strcpy(read_vocab_file, argv[i + 1]);<br></td></tr
><tr
id=sl_svn42_679

><td class="source">  if ((i = ArgPos((char *)&quot;-debug&quot;, argc, argv)) &gt; 0) debug_mode = atoi(argv[i + 1]);<br></td></tr
><tr
id=sl_svn42_680

><td class="source">  if ((i = ArgPos((char *)&quot;-binary&quot;, argc, argv)) &gt; 0) binary = atoi(argv[i + 1]);<br></td></tr
><tr
id=sl_svn42_681

><td class="source">  if ((i = ArgPos((char *)&quot;-cbow&quot;, argc, argv)) &gt; 0) cbow = atoi(argv[i + 1]);<br></td></tr
><tr
id=sl_svn42_682

><td class="source">  if (cbow) alpha = 0.05;<br></td></tr
><tr
id=sl_svn42_683

><td class="source">  if ((i = ArgPos((char *)&quot;-alpha&quot;, argc, argv)) &gt; 0) alpha = atof(argv[i + 1]);<br></td></tr
><tr
id=sl_svn42_684

><td class="source">  if ((i = ArgPos((char *)&quot;-output&quot;, argc, argv)) &gt; 0) strcpy(output_file, argv[i + 1]);<br></td></tr
><tr
id=sl_svn42_685

><td class="source">  if ((i = ArgPos((char *)&quot;-window&quot;, argc, argv)) &gt; 0) window = atoi(argv[i + 1]);<br></td></tr
><tr
id=sl_svn42_686

><td class="source">  if ((i = ArgPos((char *)&quot;-sample&quot;, argc, argv)) &gt; 0) sample = atof(argv[i + 1]);<br></td></tr
><tr
id=sl_svn42_687

><td class="source">  if ((i = ArgPos((char *)&quot;-hs&quot;, argc, argv)) &gt; 0) hs = atoi(argv[i + 1]);<br></td></tr
><tr
id=sl_svn42_688

><td class="source">  if ((i = ArgPos((char *)&quot;-negative&quot;, argc, argv)) &gt; 0) negative = atoi(argv[i + 1]);<br></td></tr
><tr
id=sl_svn42_689

><td class="source">  if ((i = ArgPos((char *)&quot;-threads&quot;, argc, argv)) &gt; 0) num_threads = atoi(argv[i + 1]);<br></td></tr
><tr
id=sl_svn42_690

><td class="source">  if ((i = ArgPos((char *)&quot;-iter&quot;, argc, argv)) &gt; 0) iter = atoi(argv[i + 1]);<br></td></tr
><tr
id=sl_svn42_691

><td class="source">  if ((i = ArgPos((char *)&quot;-min-count&quot;, argc, argv)) &gt; 0) min_count = atoi(argv[i + 1]);<br></td></tr
><tr
id=sl_svn42_692

><td class="source">  if ((i = ArgPos((char *)&quot;-classes&quot;, argc, argv)) &gt; 0) classes = atoi(argv[i + 1]);<br></td></tr
><tr
id=sl_svn42_693

><td class="source">  vocab = (struct vocab_word *)calloc(vocab_max_size, sizeof(struct vocab_word));<br></td></tr
><tr
id=sl_svn42_694

><td class="source">  vocab_hash = (int *)calloc(vocab_hash_size, sizeof(int));<br></td></tr
><tr
id=sl_svn42_695

><td class="source">  expTable = (real *)malloc((EXP_TABLE_SIZE + 1) * sizeof(real));<br></td></tr
><tr
id=sl_svn42_696

><td class="source">  for (i = 0; i &lt; EXP_TABLE_SIZE; i++) {<br></td></tr
><tr
id=sl_svn42_697

><td class="source">    expTable[i] = exp((i / (real)EXP_TABLE_SIZE * 2 - 1) * MAX_EXP); // Precompute the exp() table<br></td></tr
><tr
id=sl_svn42_698

><td class="source">    expTable[i] = expTable[i] / (expTable[i] + 1);                   // Precompute f(x) = x / (x + 1)<br></td></tr
><tr
id=sl_svn42_699

><td class="source">  }<br></td></tr
><tr
id=sl_svn42_700

><td class="source">  TrainModel();<br></td></tr
><tr
id=sl_svn42_701

><td class="source">  return 0;<br></td></tr
><tr
id=sl_svn42_702

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
 <a href="/p/word2vec/source/detail?spec=svn42&amp;r=42">r42</a>
 by tmikolov
 on Jan 30, 2015
 &nbsp; <a href="/p/word2vec/source/diff?spec=svn42&r=42&amp;format=side&amp;path=/trunk/word2vec.c&amp;old_path=/trunk/word2vec.c&amp;old=39">Diff</a>
 </div>
 <pre>bugfix in InitUnigramTable() - some words
could not have been sampled as negative
examples</pre>
 </div>
 
 
 
 
 
 
 <script type="text/javascript">
 var detail_url = '/p/word2vec/source/detail?r=42&spec=svn42';
 var publish_url = '/p/word2vec/source/detail?r=42&spec=svn42#publish';
 // describe the paths of this revision in javascript.
 var changed_paths = [];
 var changed_urls = [];
 
 changed_paths.push('/trunk/word2vec.c');
 changed_urls.push('/p/word2vec/source/browse/trunk/word2vec.c?r\x3d42\x26spec\x3dsvn42');
 
 var selected_path = '/trunk/word2vec.c';
 
 
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
 
 <option value="/p/word2vec/source/browse/trunk/word2vec.c?r=42&amp;spec=svn42"
 selected="selected"
 >/trunk/word2vec.c</option>
 
 </select>
 </td></tr></table>
 
 
 



 <div style="white-space:nowrap">
 Project members,
 <a href="https://www.google.com/accounts/ServiceLogin?service=code&amp;ltmpl=phosting&amp;continue=https%3A%2F%2Fcode.google.com%2Fp%2Fword2vec%2Fsource%2Fbrowse%2Ftrunk%2Fword2vec.c&amp;followup=https%3A%2F%2Fcode.google.com%2Fp%2Fword2vec%2Fsource%2Fbrowse%2Ftrunk%2Fword2vec.c"
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
 <a href="/p/word2vec/source/detail?spec=svn42&r=39">r39</a>
 by tmikolov
 on Sep 8, 2014
 &nbsp; <a href="/p/word2vec/source/diff?spec=svn42&r=39&amp;format=side&amp;path=/trunk/word2vec.c&amp;old_path=/trunk/word2vec.c&amp;old=38">Diff</a>
 <br>
 <pre class="ifOpened">fixed minor bugs</pre>
 </div>
 
 <div class="closed" style="margin-bottom:3px;" >
 <a class="ifClosed" onclick="return _toggleHidden(this)"><img src="https://ssl.gstatic.com/codesite/ph/images/plus.gif" ></a>
 <a class="ifOpened" onclick="return _toggleHidden(this)"><img src="https://ssl.gstatic.com/codesite/ph/images/minus.gif" ></a>
 <a href="/p/word2vec/source/detail?spec=svn42&r=38">r38</a>
 by tmikolov
 on Sep 6, 2014
 &nbsp; <a href="/p/word2vec/source/diff?spec=svn42&r=38&amp;format=side&amp;path=/trunk/word2vec.c&amp;old_path=/trunk/word2vec.c&amp;old=35">Diff</a>
 <br>
 <pre class="ifOpened">update to 0.1c version</pre>
 </div>
 
 <div class="closed" style="margin-bottom:3px;" >
 <a class="ifClosed" onclick="return _toggleHidden(this)"><img src="https://ssl.gstatic.com/codesite/ph/images/plus.gif" ></a>
 <a class="ifOpened" onclick="return _toggleHidden(this)"><img src="https://ssl.gstatic.com/codesite/ph/images/minus.gif" ></a>
 <a href="/p/word2vec/source/detail?spec=svn42&r=35">r35</a>
 by tmiko...@google.com
 on Nov 27, 2013
 &nbsp; <a href="/p/word2vec/source/diff?spec=svn42&r=35&amp;format=side&amp;path=/trunk/word2vec.c&amp;old_path=/trunk/word2vec.c&amp;old=34">Diff</a>
 <br>
 <pre class="ifOpened">fixed bug: the counter in K-means was
updated too frequently</pre>
 </div>
 
 
 <a href="/p/word2vec/source/list?path=/trunk/word2vec.c&start=42">All revisions of this file</a>
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
 
 <div>Size: 26184 bytes,
 702 lines</div>
 
 <div><a href="//word2vec.googlecode.com/svn/trunk/word2vec.c">View raw file</a></div>
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
 var paths = {'svn42': '/trunk/word2vec.c'}
 codereviews = CR_controller.setup(
 {"projectHomeUrl": "/p/word2vec", "relativeBaseUrl": "", "assetHostPath": "https://ssl.gstatic.com/codesite/ph", "loggedInUserEmail": null, "profileUrl": null, "assetVersionPath": "https://ssl.gstatic.com/codesite/ph/8599073060794244502", "domainName": null, "projectName": "word2vec", "token": null}, '', 'svn42', paths,
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

 
 


 
 
 <script type="text/javascript">_CS_reportToCsi();</script>
 
 </body>
</html>

