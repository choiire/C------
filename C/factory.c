#include "factory.h"
#include <stdio.h>
#include <stdlib.h>

// ==========================================
// 가솔린 전담 공장 로직
static Engine* gasoline_factory_create(void) {
    printf("[Engine_1Factory] 가솔린 엔진을 위한 부품을 조립합니다...\n");
    return create_gasoline_engine();
}

EngineFactory* create_gasoline_factory(void) {
    EngineFactory* factory = (EngineFactory*)malloc(sizeof(EngineFactory));
    if (factory) {
        factory->createEngine = gasoline_factory_create;
    }
    return factory;
}

// ==========================================
// 전기 모터 전담 공장 로직
static Engine* electric_factory_create(void) {
    printf("[Engine_2Factory] 전기 모터를 위한 배터리를 연결합니다...\n");
    return create_electric_motor();
}

EngineFactory* create_electric_factory(void) {
    EngineFactory* factory = (EngineFactory*)malloc(sizeof(EngineFactory));
    if (factory) {
        factory->createEngine = electric_factory_create;
    }
    return factory;
}

// ==========================================
// 하이브리드 전담 공장 로직
static Engine* hybrid_factory_create(void) {
    printf("[Engine_3Factory] 하이브리드용 가솔린과 전기 시스템을 연동합니다...\n");
    return create_hybrid_engine();
}

EngineFactory* create_hybrid_factory(void) {
    EngineFactory* factory = (EngineFactory*)malloc(sizeof(EngineFactory));
    if (factory) {
        factory->createEngine = hybrid_factory_create;
    }
    return factory;
}

// ==========================================
// 팩토리 메모리 해제
void destroy_factory(EngineFactory* factory) {
    if (factory) {
        free(factory);
    }
}
