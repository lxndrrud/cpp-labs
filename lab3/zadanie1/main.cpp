#include "zadanie1.cpp"

int main() {
    auto ballon = new BallonOfGas(1, 1, 1);
    auto calculationInterface = new BallonInterfaceAdapter(ballon);

    std::cout << "Баллон " << std::endl;
    std::cout << "Количество вещества: " << ballon->AmountOfMatter() << std::endl;
    std::cout << "Давление: " << ballon->GetPressure(2) << std::endl;
    std::cout << "Информация: " << ballon->ToString() << std::endl << std::endl;

    std::cout << "Интерфейс расчета" << std::endl;
    std::cout << "Паспорт: " << calculationInterface->Passport() << std::endl;
    std::cout << "Изменение(1) от Т0 до Т1:" << calculationInterface->GetDp(2, 1) << std::endl;
    calculationInterface->ModifyVolume(2);
    std::cout << "Изменение(2) от Т0 до Т1:" << calculationInterface->GetDp(2, 1) << std::endl;

    delete calculationInterface;
    delete ballon;
    return 0;
}