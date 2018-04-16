/*
 @Date    : 2018-04-16 13:12:30
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
http://www.cnblogs.com/haippy/p/3301408.html
 */

#include <iostream>       // std::cout
#include <atomic>         // std::atomic, std::memory_order_relaxed
#include <thread>         // std::thread

std::atomic<int> foo(0); // 全局的原子对象 foo

void set_foo(int x)
{
    foo.store(x, std::memory_order_relaxed); // 设置(store) 原子对象 foo 的值
    return;
}

void print_foo()
{
    int x;
    do
    {
        x = foo.load(std::memory_order_relaxed); // 读取(load) 原子对象 foo 的值
    } while (x == 0);
    std::cout << "foo: " << x << '\n';
    return;
}

int main ()
{
    std::thread first(print_foo); // 线程 first 打印 foo 的值
    std::thread second(set_foo, 10); // 线程 second 设置 foo 的值
    first.join();
    second.join();
    return 0;
}
