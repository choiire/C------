#ifndef ENGINEFACTORY_H
#define ENGINEFACTORY_H

#include "EngineController.h"

// 엔진 생성을 전담하는 팩토리 클래스
class EngineFactory {
public:
    enum EngineType {
        GASOLINE,
        ELECTRIC,
        HYBRID
    };

    // 팩토리 메서드: 타입에 맞는 엔진 객체를 생성하여 반환합니다.
    static EngineController* createEngine(EngineType type);
};

#endif // ENGINEFACTORY_H
