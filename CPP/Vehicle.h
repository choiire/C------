#ifndef VEHICLE_H
#define VEHICLE_H

#include "EngineController.h"

class Vehicle {
private:
  // 다형성을 위해 부모 클래스 포인터를 사용합니다.
  EngineController *engine;

public:
  // 의존성 주입을 위한 생성자
  Vehicle(EngineController *initEngine);

  // 엔진 교체 기능
  void changeEngine(EngineController *newEngine);

  // 차량의 메서드들
  void startOperation();
  void stopOperation();
};

#endif // VEHICLE_H
