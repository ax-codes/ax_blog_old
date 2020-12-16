---
title: 使用DotnetSpider爬取优酷数据
date: 2018/09/07 09:53:00
categories: 技术
toc: True
tags: [csharp,.net/.net core]
---

### 前言
使用DotnetSpider爬取优酷数据
.net core版本:.net core 2
dotnetspider版本:DotnetSpider2.Core(2.4.4):(可直接搜索DotnetSpider2.Core nuget包)


### demo 代码
```csharp
using DotnetSpider.Core;
using DotnetSpider.Core.Downloader;
using DotnetSpider.Core.Pipeline;
using DotnetSpider.Core.Processor;
using DotnetSpider.Core.Scheduler;
using DotnetSpider.Core.Selector;
using System;
using System.Collections.Generic;
using System.Text;

namespace DotnetSpiderTest
{
    public class YoukuVideo
    {
        public string Name { get; set; }
    }

    public class YoukuPageProcessor : BasePageProcessor
    {
        protected override void Handle(Page page)
        {
            // 利用 Selectable 查询并构造自己想要的数据对象
            var totalVideoElements = page.Selectable.SelectList(Selectors.XPath("//div[@class='yk-pack pack-film']")).Nodes();
            List<YoukuVideo> results = new List<YoukuVideo>();
            foreach (var videoElement in totalVideoElements)
            {
                var video = new YoukuVideo();
                video.Name = videoElement.Select(Selectors.XPath(".//img[@class='quic']/@alt")).GetValue();
                results.Add(video);
            }

            // Save data object by key. 以自定义KEY存入page对象中供Pipeline调用
            page.AddResultItem("VideoResult", results);
        }
    }

    public class YoukuPipeline : BasePipeline
    {
        private static long count = 0;
        public override void Process(IEnumerable<ResultItems> resultItems, ISpider spider)
        {
            
            foreach (var resultItem in resultItems)
            {
                Console.WriteLine();
                Console.WriteLine("=================================================");
                StringBuilder builder = new StringBuilder();
                foreach (YoukuVideo entry in resultItem.Results["VideoResult"])
                {
                    builder.Append($" [YoukuVideo {count}] {entry.Name}");
                }
                Console.WriteLine(builder);
                Console.WriteLine();
                Console.WriteLine("=================================================");
            }
            // Other actions like save data to DB. 可以自由实现插入数据库或保存到文件
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            // Config encoding, header, cookie, proxy etc... 定义采集的 Site 对象, 设置 Header、Cookie、代理等
            var site = new Site { EncodingName = "UTF-8", RemoveOutboundLinks = true };
            site.Domains = new[] { "list.youku.com" };//必须设置这个域名,因为启动爬虫的时候有个域名是否为空校验,不然会报错
            for (int i = 1; i < 5; ++i)
            {
                // Add start/feed urls. 添加初始采集链接
                site.AddStartUrl($"http://list.youku.com/category/show/c_96_s_1_d_1_p_{i}.html");
            }
            Spider spider = Spider.Create(site,
                // use memoery queue scheduler. 使用内存调度
                new QueueDuplicateRemovedScheduler(),
                // use custmize processor for youku 为优酷自定义的 Processor
                new YoukuPageProcessor())
                // use custmize pipeline for youku 为优酷自定义的 Pipeline
                .AddPipeline(new YoukuPipeline());
            spider.Downloader = new HttpClientDownloader();
            spider.ThreadNum = 1;
            spider.EmptySleepTime = 3000;
            // Start crawler 启动爬虫
            spider.Run();
        }


    }
}

```