---
marp: true
theme: dracula
paginate: true
header: '[![image](MSClogo_thumbnail.png)](https://cqu.microsoftstudent.club/)'
footer: '[![image](CQUlogo.png)](http://www.cqu.edu.cn/)'

---

<!-- _class: lead -->
[![height:6cm center](MSClogo.png)](https://cqu.microsoftstudent.club/)
# <center> Slide deck in Marpit Markdown
## <center> **Show python learning code**

<style>
img[alt~="center"] {
  display: block;
  margin: 0 auto;
}
</style>

---
# List列表

Python 内置的一种 sequence。虽然名为列表，但更类似于其他语言中的数组而非链接列表，因为访问元素的时间复杂度为 O(1)。

> 出门买菜，最好带上篮子（容器）。这个容器既可以装鸡蛋，也可以装西红柿或啤酒。人们很希望拥有这样一种容器，它可以装不同种类的对象，而且可以根据需要自动改变体积以适应需求。Python里的列表就是这样的容器
>
> -- 《Python编程基础及应用》编者

---

# 练习题

输入一个整数列表，找出整数列表中最大元素的下标，如果最大元素的个数超过1，那么请打印输出所有的下标。

```python
shuru = input()
liebiao = shuru.split(",")
liebiao = [int(n) for n in liebiao]  #一定把列表中字符串转换为数字再判断max
zuida = max(liebiao)
while liebiao.count(zuida) >=1 :
    ind = liebiao.index(zuida)
    print(ind)
    liebiao[ind] = None
```

---

# History of Python

| Year | Version | Features |
| ----------- | ----------- | ----------- |
| 1994 | Python 1.0 | lambda, map, filter |
| 2000 | Python 2.0 | list comprehensions|
| 2006 | Python 2.5 | the with statement|
| 2008 | Python 3.0 | reduce feature duplication|
| 2020 | Python 3.9 | new string methods|

---

# Languages influenced by Python

- [Swift](https://en.wikipedia.org/wiki/Swift_(programming_language))

- [Go](https://en.wikipedia.org/wiki/Go_(programming_language))

- [JavaScript](https://en.wikipedia.org/wiki/JavaScript)

- [Groovy](https://en.wikipedia.org/wiki/Groovy_(programming_language))

- [Ruby](https://en.wikipedia.org/wiki/Ruby_(programming_language))