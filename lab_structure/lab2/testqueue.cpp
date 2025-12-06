#include "stack.h"
#include "dyn_arr.h"
#include "queue.h"
#include "stack.cpp"
#include "dyn_arr.cpp"
#include "queue.cpp"
#include <iostream>

int main(){
    Queue<double> q;
    double fib=0;
    double fac=1;
    q.enqueue(5);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(2);
    q.enqueue(7);
    std::cout<<"дикая очередь"<<std::endl;
    q.print();
    q%(0);
    std::cout<<"фибоначчизированная от "<< fib<< " очередь"<<std::endl;
    q.print();
    q^(1);
    std::cout<<"факторизированная по "<< fac<< " очередь (нет мне ее не жаль)"<<std::endl;
    q.print();
    std::cout<<q.dequeue()<<" вышел из очереди"<<std::endl;
    std::cout<<"вот такая стала очередь"<<std::endl;
    q.print();
    std::cout<<q.dequeue()<<" вышел из очереди"<<std::endl;
    std::cout<<q.dequeue()<<" вышел из очереди"<<std::endl;
    std::cout<<"вот такая стала очередь"<<std::endl;
    q.print();
    std::cout<<q.size()<<" - размер (длина, не последний индекс)"<<std::endl;
    std::cout<<q.isEmpty()<<" - пустота очереди"<<std::endl;
    std::cout<<q.dequeue()<<" покинул очередь"<<std::endl;
    std::cout<<q.dequeue()<<" покинул очередь"<<std::endl;
    std::cout<<q.dequeue()<<" покинул очередь"<<std::endl;
    std::cout<<q.isEmpty()<<" - пустота очереди"<<std::endl;

    return 0;
}
