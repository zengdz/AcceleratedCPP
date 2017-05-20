# 第 5 章：顺序容器和字符串处理
>  

> 

> 

> 列表的排序和向量排序不同

算法标准库提供的sort函数是针对可随机访问类型的容器，比如sort(vector.begin(), vector.end(), pattern)；
而列表list不能随机访问，所以不能使用sort函数而使用该容器的排序方法list.sort(pattern)，pattern代表排序规则



