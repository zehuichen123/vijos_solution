## Vijos Solutions and Crawler

### Intro

This repo collects my solutions to 111 problems in Vijos(<a href="https://www.vijos.org">https://www.vijos.org</a>).

###  Vijos Crawler

####  Uage

1. clone this repo `git clone `
2. cd into this directory `cd vijos_solution/`
3. run script and input your vijos username and password `python run.py`

#### Parameters

- verbose: if True, it will output all information when crawling. (Default: False)
- save_all:if True, it will save all your submissions including those you didn't get full grade. (Default: False)

#### Others

大一的时候在施神的引导下刷了些vijos 今天统计了一下 一共做了121道题 AC了111道 剩下10道要么TTL要么WA 懒得管了 那时候写的时候还把每道题的代码都保存下来了 结果之后换了电脑 之前的代码都不见了= = 看到别人都把自己写的OJ solution建个仓库感觉挺羡慕的 所以一直想写个爬虫从vijos上把自己的代码给爬下来 拖到今天才做 花了2个小时时间 算是温故了一下之前学的皮毛爬虫代码 仅供个人娱乐使用 如果你也有幸做过vijos而且也恰巧忘记把代码保存下来 也可以跑一下`run.py`，输入用户名和密码，就可以啦～ 不过由于不知道vijos获取AC list的接口 所以把vijos整个题库遍历了一遍 orz 如果有人发现了获得自己submission的api可以跟我说 至少不用那么蠢的方法了 感激不尽 嘻嘻～