#include <iostream>
#include <chrono>

#define N 5

int QUEUE[N];
int FRONT = 0; // Initialize FRONT and REAR to 0 when empty
int REAR = 0;

void ENQUEUE(int x)
{
    if ((REAR + 1) % N == FRONT)
    {
        std::cout << "Queue is full" << std::endl;
        return;
    }
    QUEUE[REAR] = x;
    REAR = (REAR + 1) % N;
}

void DEQUEUE()
{
    if (FRONT == REAR)
    {
        std::cout << "Queue is empty" << std::endl;
        return;
    }
    std::cout << "Element to be deleted: " << QUEUE[FRONT] << std::endl;
    FRONT = (FRONT + 1) % N;
}

std::string DISPLAY()
{
    if (FRONT == REAR)
    {
        return "Queue is empty";
    }
    std::string result;
    int i = FRONT;
    while (i != REAR)
    {
        result += std::to_string(QUEUE[i]) + " ";
        i = (i + 1) % N;
    }
    result += std::to_string(QUEUE[REAR]);
    return result;
}

void PEEK()
{
    if (FRONT == REAR)
    {
        std::cout << "Queue is empty" << std::endl;
        return;
    }
    std::cout << "Front element: " << QUEUE[FRONT] << std::endl;
}

void solve()
{
    PEEK();
    ENQUEUE(9);
    ENQUEUE(5);
    ENQUEUE(6);
    ENQUEUE(7);
    ENQUEUE(8);
    std::cout << "Queue elements: " << DISPLAY() << std::endl;
    PEEK();
}

int main()
{
    auto t1 = std::chrono::high_resolution_clock::now();
    solve();
    auto t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
    std::cerr << "Time: " << duration.count() << " ms" << std::endl;
    return 0;
}
