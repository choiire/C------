#include "vehicle.h"
#include <stdio.h>
#include <stdlib.h>

Vehicle* create_vehicle(Engine* initEngine) {
    Vehicle* vehicle = (Vehicle*)malloc(sizeof(Vehicle));
    if (vehicle) {
        vehicle->engine = initEngine;
    }
    return vehicle;
}

void destroy_vehicle(Vehicle* vehicle) {
    if (vehicle) {
        free(vehicle);
    }
}

void vehicle_change_engine(Vehicle* vehicle, Engine* newEngine) {
    if (vehicle) {
        vehicle->engine = newEngine;
        printf("차량: 새로운 엔진으로 교체되었습니다.\n");
    }
}

void vehicle_start_operation(Vehicle* vehicle) {
    printf(">> 차량 운행 시작 명령 하달\n");
    // 다형성 동작: 객체가 가진 함수 포인터를 안전하게 호출
    if (vehicle && vehicle->engine && vehicle->engine->startEngine) {
        vehicle->engine->startEngine(); 
    }
}

void vehicle_stop_operation(Vehicle* vehicle) {
    printf(">> 차량 운행 정지 명령 하달\n");
    if (vehicle && vehicle->engine && vehicle->engine->stopEngine) {
        vehicle->engine->stopEngine();
    }
}
