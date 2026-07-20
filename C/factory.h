#ifndef FACTORY_H
#define FACTORY_H

#include "engine.h"

// 팩토리 인터페이스 (구조체)
// 공통된 생성 방식(createEngine)을 함수 포인터로 가집니다.
typedef struct EngineFactory {
    Engine* (*createEngine)(void);
} EngineFactory;

// 구체 팩토리(전담 공장) 생성 함수들
EngineFactory* create_gasoline_factory(void);
EngineFactory* create_electric_factory(void);
EngineFactory* create_hybrid_factory(void);

// 팩토리 메모리 해제
void destroy_factory(EngineFactory* factory);

#endif // FACTORY_H
