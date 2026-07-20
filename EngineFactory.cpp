#include "EngineFactory.h"
#include "Engine_1.h"
#include "Engine_2.h"
#include "Engine_3.h"
#include <iostream>

EngineController* EngineFactory::createEngine(EngineType type) {
    // 요리사(Factory)가 주문(type)에 맞춰 적절한 요리(엔진 객체)를 만들어 내보냅니다.
    switch (type) {
        case GASOLINE: 
            std::cout << "[Factory] 가솔린 엔진(Engine_1)을 생성합니다." << std::endl;
            return new Engine_1();
        case ELECTRIC: 
            std::cout << "[Factory] 전기 모터(Engine_2)를 생성합니다." << std::endl;
            return new Engine_2();
        case HYBRID:   
            std::cout << "[Factory] 하이브리드 엔진(Engine_3)을 생성합니다." << std::endl;
            return new Engine_3();
        default:       
            std::cout << "[Factory] 알 수 없는 엔진 타입입니다." << std::endl;
            return nullptr;
    }
}
