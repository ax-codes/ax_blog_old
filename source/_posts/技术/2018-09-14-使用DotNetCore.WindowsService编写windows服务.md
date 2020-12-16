---
title: 使用DotNetCore.WindowsService编写windows服务
date: 2018/09/14 09:53:00
categories: 技术
toc: True
tags: [windows,.net/.net core]
---

### 前言
使用DotNetCore.WindowsService 安装windows服务
DotNetCore.WindowsService github地址:https://github.com/PeterKottas/DotNetCore.WindowsService

### Nuget包安装命令
```shell
Install-Package PeterKottas.DotNetCore.WindowsService
```

### 备注
DotNetCore.WindowsService 命令格式
eg:安装命令,比如我们需要安装JobSchedule.exe,则在生成路径里执行
```shell
JobSchedule.exe action:install
```
这样我就能在windows服务里找到JobSchedule服务了

### 操作
Create .NETCore console app.

Create your first service, something like this:
```csharp
public class ExampleService : IMicroService
{
	public void Start()
	{
		Console.WriteLine("I started");
	}
	
	public void Stop()
	{
		Console.WriteLine("I stopped");
	}
}
You can also inherit MicroService base class and take advantage of built in timers:

public class ExampleService : MicroService, IMicroService
{
	public void Start()
	{
		this.StartBase();
		Timers.Start("Poller", 1000, () =>
		{
			Console.WriteLine("Polling at {0}\n", DateTime.Now.ToString("o"));
		},
		(e) =>
		{
			Console.WriteLine("Exception while polling: {0}\n", e.ToString());
		});
		Console.WriteLine("I started");
	}
	
	public void Stop()
	{
		this.StopBase();
		Console.WriteLine("I stopped");
	}
}
```
Api for services (and yeah, it's simmilar to Topshelf, thanks for inspiration, I just couldn't wait for you guys to implement this):
```csharp
ServiceRunner<ExampleService>.Run(config =>
{
	var name = config.GetDefaultName();
	config.Service(serviceConfig =>
		{
			serviceConfig.ServiceFactory((extraArguments, microServiceController) =>
		{
			return new ExampleService();
		});
		serviceConfig.OnStart((service, extraArguments) =>
		{
			Console.WriteLine("Service {0} started", name);
			service.Start();
		});

		serviceConfig.OnStop(service =>
		{
			Console.WriteLine("Service {0} stopped", name);
			service.Stop();
		});
		
		serviceConfig.OnInstall(service =>
		{
			Console.WriteLine("Service {0} installed", name);
		});
		
		serviceConfig.OnUnInstall(service =>
		{
			Console.WriteLine("Service {0} uninstalled", name);
		});
		
		serviceConfig.OnPause(service =>
		{
			Console.WriteLine("Service {0} paused", name);
		});
		
		serviceConfig.OnContinue(service =>
		{
			Console.WriteLine("Service {0} continued", name);
		});
		
		serviceConfig.OnShutdown(service =>
		{
			Console.WriteLine("Service {0} shutdown", name);
		});

		serviceConfig.OnError(e =>
		{
			Console.WriteLine("Service {0} errored with exception : {1}", name, e.Message);
		});
	});
});
```
Optionally set the name of the service like this:
```csharp
ServiceRunner<ExampleService>.Run(config =>
{
	config.SetName("MyTestService");
});
```
Run the service without arguments and it runs like console app. 

Run the service with action:install and it will install the service.

Run the service with action:uninstall and it will uninstall the service.

Run the service with action:start and it will start the service.

Run the service with action:stop and it will stop the service.

Run the service with action:pause and it will pause the service.

Run the service with action:continue and it will continue the service.

Run the service with username:YOUR_USERNAME, password:YOUR_PASSWORD and action:install which installs it for the given account.

Run the service with built-in-account:(NetworkService|LocalService|LocalSystem) and action:install which installs it for the given built in account. Defaults to LocalSystem.

Run the service with description:YOUR_DESCRIPTION and it setup description for the service.

Run the service with display-name:YOUR_DISPLAY_NAME and it setup Display name for the service.

Run the service with name:YOUR_NAME and it setup name for the service.

Run the service with start-immediately:(true|false) to start service immediately after install. Defaults to true.

You can find the complete example in PeterKottas.DotNetCore.Example project.

Install the service using powershell: dotnet.exe $serviceDllPath action:install