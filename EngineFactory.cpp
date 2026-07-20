#include "EngineFactory.h"
#include "Engine_1.h"
#include "Engine_2.h"
#include "Engine_3.h"
#include <iostream>

// 각 전담 공장들이 자신의 특기에 맞는 엔진을 직접 조립하여 반환합니다.

EngineController *Engine_1Factory::createEngine() {
  std::cout << "[Engine_1Factory] 가솔린 엔진을 위한 부품을 조립합니다..."
            << std::endl;
  return new Engine_1();
}

EngineController *Engine_2Factory::createEngine() {
  std::cout << "[Engine_2Factory] 전기 모터를 위한 배터리를 연결합니다..."
            << std::endl;
  return new Engine_2();
}

EngineController *Engine_3Factory::createEngine() {
  std::cout
      << "[Engine_3Factory] 하이브리드용 가솔린과 전기 시스템을 연동합니다..."
      << std::endl;
  return new Engine_3();
}
