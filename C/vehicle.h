#ifndef VEHICLE_H
#define VEHICLE_H

#include "engine.h"

// Vehicle 구조체 (클라이언트 역할)
typedef struct Vehicle {
    Engine* engine; // 다형성을 위한 부모(인터페이스) 포인터 소유
} Vehicle;

// 자동차 생성 및 소멸
Vehicle* create_vehicle(Engine* initEngine);
void destroy_vehicle(Vehicle* vehicle);

// 자동차 동작 메서드 (C언어 스타일 객체지향)
// C++의 멤버 함수(this 포인터)처럼 첫 번째 인자로 객체 포인터를 받습니다.
void vehicle_change_engine(Vehicle* vehicle, Engine* newEngine);
void vehicle_start_operation(Vehicle* vehicle);
void vehicle_stop_operation(Vehicle* vehicle);

#endif // VEHICLE_H
