#include "zadanie2.cpp"

int main() {
    auto calculationFacade = new CalculationFacade();
    calculationFacade->process(1, 23, 2, 2013, 0.1, nullptr);
    delete calculationFacade;

    return 0;
}
