
// Compilar com -pthread
// Ex: g++ MultiThread.cpp -o a -pthread

#include <thread>
#include <iostream>

using namespace std;

void threadFunction(){
    cout << "Hello from Thread 1" << endl;
}

int main(){
    cout << "Strting Multithread processing..." << endl;

    thread mThread(threadFunction);

    mThread.join();

    cout << "Thread has finished." << endl;

    return 0;
}

