#include "zadanie3.cpp"

int main() {
    auto appFactory = new MyApplicationFactory();
    appFactory->launchProcess();
    delete appFactory;

    return 0;
}
