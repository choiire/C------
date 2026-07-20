#include "engine.h"
#include <stdio.h>
#include <stdlib.h>

// ==========================================
// [가솔린 엔진 전용 동작 함수들]
static void gasoline_start(void) {
    printf("[Engine_1] 부릉부릉! 가솔린 엔진 시동이 켜졌습니다.\n");
}
static void gasoline_stop(void) {
    printf("[Engine_1] 가솔린 엔진 시동이 꺼졌습니다.\n");
}

Engine* create_gasoline_engine(void) {
    Engine* engine = (Engine*)malloc(sizeof(Engine));
    if (engine) {
        engine->startEngine = gasoline_start; // 함수 포인터 바인딩
        engine->stopEngine = gasoline_stop;
    }
    return engine;
}

// ==========================================
// [전기 모터 전용 동작 함수들]
static void electric_start(void) {
    printf("[Engine_2] 위이잉! 전기 모터 구동을 시작합니다.\n");
}
static void electric_stop(void) {
    printf("[Engine_2] 전기 모터 구동을 정지합니다.\n");
}

Engine* create_electric_motor(void) {
    Engine* engine = (Engine*)malloc(sizeof(Engine));
    if (engine) {
        engine->startEngine = electric_start; // 함수 포인터 바인딩
        engine->stopEngine = electric_stop;
    }
    return engine;
}

// ==========================================
// [하이브리드 엔진 전용 동작 함수들]
static void hybrid_start(void) {
    printf("[Engine_3] 하이브리드 엔진 동작을 시작합니다.\n");
}
static void hybrid_stop(void) {
    printf("[Engine_3] 하이브리드 엔진 동작을 정지합니다.\n");
}

Engine* create_hybrid_engine(void) {
    Engine* engine = (Engine*)malloc(sizeof(Engine));
    if (engine) {
        engine->startEngine = hybrid_start;
        engine->stopEngine = hybrid_stop;
    }
    return engine;
}

// ==========================================
// 엔진 메모리 해제
void destroy_engine(Engine* engine) {
    if (engine) {
        free(engine);
    }
}
