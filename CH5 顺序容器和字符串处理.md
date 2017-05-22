# 第 5 章：顺序容器和字符串处理


> 列表的排序和向量排序不同

算法标准库提供的sort函数是针对可随机访问类型的容器，比如sort(vector.begin(), vector.end(), pattern)；
而列表list不能随机访问，所以不能使用sort函数而使用该容器的排序方法list.sort(pattern)，pattern代表排序规则

> 向量和的列表迭代器不同(也是由随机访问和顺序访问区别造成的)

对于向量，删除元素后，后面的元素的迭代器就失效了；列表的话，只是被删除的失效，后面的没有失效。


>  标准库是一个具有一致性的体系结构，了解了一种容器的行为特性就能轻松掌握全部容器的用法。

> 顺序容器和string类型支持如下操作：＜/br＞
container<T>::iterator   
container<T>::const_iterator
container<T>::size_type 保存该容器实例的长度
c.begin() c.end() 指向前闭后开区间的迭代器
c.rbegin() c.rend() 指向逆序前开后闭区间的迭代器
c.size() 返回c的元素个数，返回值类型size_type
c.empty() 指示是否没有元素
c.insert(d, b, e) 复制位于区间[b, e)迭代器所指元素到c中d位置之前处(因为d是开区间)
c.erase(it)
c.erase(b, e) 删除it位置或者[b, e)指示的元素
c.push_back(t)

> 迭代器操作：  
*it 间接引用迭代器得到it位置指向的值
it->x 等效于 (*it).x
++it 或者 it++ 指向容器的下一个元素
b == e
b != e 判断两个迭代器是否相等

> string类型操作：
s.substr(i, j) 复制s在区间[i, i+j)索引中内容，以新字符串返回
getline(is, s) 从is读一行输入并将它存储在s中

