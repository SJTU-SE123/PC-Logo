# PCLogo

这是本项目进行开发过程中的主要分支，如需新增功能，请在本分支基础上新建分支进行修改，完成后通过
Pull Request合并进本分支。目前本分支已被保护，无法直接push.


## 运行

通过QtCreator打开`PCLogo-demo/PCLogo-demp.pro`文件可打开本项目，之后可在QtCreator中直接运行。

注意：**在开发过程中，请不要将`*.pro.user`这样的与用户配置相关的文件上传至本分支——这类文件由用户本地的QtCreator创建并配置，各用户配置不同**。如果你使用git，这些用户配置文件在版本控制系统中会被自动忽略。

## 测试

通过QtCreator打开`PCLogo-demo/PCLogo-test/PCLogo-test.pro`文件可打开测试项目，之后可在QtCreator中运行所有测试。

测试中提供了两个十分简单的demo，即TestLineInterpreter类和TestStartWindow类，分别代表普通类和GUI类的测试，以供参考。

注意：**测试方法必须声明为`private slots`**.

新建测试类后，需要在测试项目`main.cpp`中调用`tr.addTest(Your_new_test_class)`方法以加载你的新测试类。
