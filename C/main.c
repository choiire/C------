#include "factory.h"
#include "vehicle.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Windows 콘솔 인코딩을 UTF-8로 변경 (필요한 경우)
  system("chcp 65001 > nul");

  // 팩토리 메서드 패턴 적용 (C언어 스타일 객체지향)

  // 1. 가솔린 엔진 전담 공장을 세웁니다.
  EngineFactory *factory = create_gasoline_factory();

  // 전담 공장에게 엔진 생성을 요청합니다.
  Engine *engineCtrl = factory->createEngine();

  // 자동차 객체를 생성하고 엔진을 장착합니다.
  Vehicle *myCar = create_vehicle(engineCtrl);
  vehicle_start_operation(myCar);
  vehicle_stop_operation(myCar);

  // 기존 가솔린 엔진과 공장은 철거 (C언어는 수동 메모리 관리!)
  destroy_engine(engineCtrl);
  destroy_factory(factory);

  printf("\n");

  // 2. 새 엔진 장착을 위해 전기 모터 전담 공장을 세웁니다.
  factory = create_electric_factory();
  engineCtrl = factory->createEngine();

  vehicle_change_engine(myCar, engineCtrl);
  vehicle_start_operation(myCar);
  vehicle_stop_operation(myCar);

  // 3. 프로그램 끝나기 전에 남아있는 객체들 메모리 해제
  destroy_vehicle(myCar);
  destroy_engine(engineCtrl);
  destroy_factory(factory);

  return 0;
}
