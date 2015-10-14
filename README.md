
http://blog.scaperow.com/133
以下转自 风景侠的技术博客

改造 ionic 更新插件

介绍

本文只介绍如何为 ionic 项目做更新的功能，对于 ionic 很陌生的人可以先到官网上了解下。
对于 ionic 很了解的人也许知道，在ionic 1.1中包含的诸多新特性，包括 应用统计、推送集成、部署与更新、等。但是所有的功能都依赖于ionic的后端，国内的网络环境你懂得，可以说这些功能都不能用。本文将简单介绍，怎么改造属于自己的更新功能。
最终实现的效果是，通过前台的 js 来控制更新流程，通过原生代码来下载、应用更新，最重要的一点，不需要将更新包放在ionic后端，而是自己的服务器。

配置

ionic 的更新功能依赖于三者：1. 插件，2.更新服务，3.核心服务，三者已寄存在 git 上，建议将这三个仓库都 fork 到自己仓库中，以后好做维护。
插件地址：
https://github.com/driftyco/ionic-plugins-deploy
更新服务地址：
https://github.com/driftyco/ionic-service-deploy
核心服务地址：
https://github.com/driftyco/ionic-service-core

将 cli 定位到你的 ionic 工程下，使用以下命令来安装插件、更新服务、核心服务
ionic add ionic-service-core
ionic add ionic-service-deploy
ionic plugin add ionic-plugin-deploy

改造

由于要修改的地方较多，本文就不一一列举，我已将代码托管到 git 上，供读者参考，这里只说我改造逻辑。

打开 platforms 下的原生代码，找到向服务器发送更新请求的代码。
发现服务器的路径被硬编码，将路径指到一个变量上，并修改请求的路径结构。之前的路径太长了，不利于测试
修改 js 代码，扩展相应的方法，使其支持路径参数，并能够正常的传入到原生代码中。
更新端与服务器交互的数据如下
检查更新的请求代码
update/check/{appid}
appid 是你的应用标示，可以在 www/app.js中指定。
服务器返回数据结构
    {
      'compatible_binary': true,
      'update_available': true,
      'update': 
      {
        'uuid': "2.0.1",
        'url': "/eoapp/www.zip"
      }
    }
compatible_binary 代表是否兼容
update_available 是否有更新
uuid 最新版本
url 更新包的下载地址
准备一个更新包，将 ionic 项目下的 www 目录直接压缩，命名为 www.zip。这就是一个更新包。
搭建 nodejs 服务器环境，为检查更新的POST请求 update/check/:appid 定义路由器，请求参数，编写逻辑代码。上传更新包进行测试。
为了方便读者参考，列出修改过的文件
platforms/ios/{你的ios项目名字}/Plugins/ionic-plugin-deploy/IonicDeploy.m
platforms/android/src/com/ionic/deploy/IonicDeploy.java plugins/ionic-plugin-deploy/www/ionicdeploy.js
www/lib/ionic-service-deploy/ionic-deploy.js

代码地址

测试app
https://github.com/scaperow/ionic-deploy-starter
测试 server
https://github.com/scaperow/ionic-deploy-server
改造后的插件代码
https://github.com/scaperow/scaperow-plugins-deploy
改造后的更新服务代码
https://github.com/scaperow/scaperow-service-deploy
改造后的核心服务代码
https://github.com/scaperow/scaperow-service-core
