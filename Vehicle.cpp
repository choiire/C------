#include "Vehicle.h"
#include <iostream>

Vehicle::Vehicle(EngineController* initEngine) : engine(initEngine) {
}

void Vehicle::changeEngine(EngineController* newEngine) {
    engine = newEngine;
    std::cout << "차량: 새로운 엔진으로 교체되었습니다." << std::endl;
}

void Vehicle::startOperation() {
    std::cout << ">> 차량 운행 시작 명령 하달" << std::endl;
    if (engine != nullptr) {
        engine->startEngine(); // 다형성(Polymorphism) 동작
    }
}

void Vehicle::stopOperation() {
    std::cout << ">> 차량 운행 정지 명령 하달" << std::endl;
    if (engine != nullptr) {
        engine->stopEngine();
    }
}
