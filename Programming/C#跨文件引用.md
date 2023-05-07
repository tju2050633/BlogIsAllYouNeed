## C#如何调用另一个C#文件定义的类？



把需要被调用的类放在自定义**命名空间**里：

```c#
using System;

namespace MyNamespace
{
    public class MyClass
    {
        public void MyMethod()
        {
            Console.WriteLine("Hello, World!");
        }
    }
}
```

调用该类的文件，需要引入该命名空间：`using MyNamespace;`

```c#
using System;
using MyNamespace;

class Program
{
    static void Main()
    {
        MyClass myObject = new MyClass();
        myObject.MyMethod();
    }
}
```

如果两个类位于不同的命名空间中，则必须使用**完整的命名空间限定符**来引用另一个类。例如，如果我们想要在 `MyNamespace` 命名空间中调用 `MyOtherClass` 类，而 `MyOtherClass` 类位于 `MyOtherNamespace` 命名空间中，则可以使用以下代码：

```c#
MyOtherNamespace.MyOtherClass myOtherObject = new MyOtherNamespace.MyOtherClass();
myOtherObject.MyOtherMethod();
```



Created On : 2023-05-07
Last Modified : 2023-05-07