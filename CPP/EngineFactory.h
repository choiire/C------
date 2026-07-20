#ifndef ENGINEFACTORY_H
#define ENGINEFACTORY_H

#include "EngineController.h"

// 추상 팩토리 클래스 (공장들의 공통 규칙)
class EngineFactory {
public:
  virtual ~EngineFactory() {}
  // 팩토리 메서드 (순수 가상 함수): 구체적인 생성은 자식 공장들에게 맡깁니다.
  virtual EngineController *createEngine() = 0;
};

// 가솔린 엔진(Engine_1) 전담 공장
class Engine_1Factory : public EngineFactory {
public:
  EngineController *createEngine() override;
};

// 전기 모터(Engine_2) 전담 공장
class Engine_2Factory : public EngineFactory {
public:
  EngineController *createEngine() override;
};

// 하이브리드 엔진(Engine_3) 전담 공장
class Engine_3Factory : public EngineFactory {
public:
  EngineController *createEngine() override;
};

#endif // ENGINEFACTORY_H
