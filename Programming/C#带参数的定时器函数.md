## C#里要写个定时器函数，要带参数，却发现Invoke不行，lambda表达式也不行。。。



一般都用**Invoke**:

```c#
Invoke("MethodName", 3.0f); // 3s后调用该类的MethodName方法
```



但这样只指定方法名，带不了参数。



---

按道理应该可以用**lambda**解决的：

```c#
Invoke(() => MethodName(param), delay);
```



不知道为什么现在VSCode的环境这样会报错：

> 无法将lambda转为string

似乎Invoke只接受字符串方法名。ChatGPT说可能Unity版本较旧，呵呵，2021LTS扯淡的。



---

这里有一个**delegate**的方法，没试。（印象里也是说只接受字符串）

```c#
Invoke(delegate() { CancelAlert(myParam); }, 5);
```



---

最后用的**协程Coroutine解决**。为数不多开线程的机会，Unity全程一个主线程管所有对象，这里开了个协程放到后台计时，避免主线程阻塞。

```c#
StartCoroutine(CancelAlertCoroutine(id));

private IEnumerator CancelAlertCoroutine(int id)
{
    yield return new WaitForSeconds(5f); // 延迟 5 秒

    CancelAlert(id); 
}

```





Created On : 2023-05-07
Last Modified : 2023-05-07