#include "EngineController.h"
#include "EngineFactory.h"
#include "Vehicle.h"
#include <iostream>

using namespace std;

int main() {
  system("chcp 65001 > nul"); // Windows 콘솔 인코딩을 UTF-8로 변경
  /*
  // 엔진 객체 생성
  Engine_1 gasolineEngine;
  Engine_2 electricMotor;
  Engine_3 hybridEngine;

  cout << "========== [테스트 1: Engine_1 장착] ==========" << endl;
  Vehicle myCar(&gasolineEngine);
  myCar.startOperation();
  myCar.stopOperation();
  cout << endl;

  cout << "========== [테스트 2: Engine_2로 교체] ==========" << endl;
  myCar.changeEngine(&electricMotor);
  myCar.startOperation();
  myCar.stopOperation();
  cout << endl;

  cout << "========== [테스트 3: 또 다른 자동차에 Engine_3 장착] ==========" <<
  endl; Vehicle yourCar(&hybridEngine); yourCar.startOperation();
  yourCar.stopOperation();
  cout << endl;
  */

  // 팩토리 메서드 패턴: 가솔린 엔진 전담 공장을 세웁니다.
  EngineFactory *factory = new Engine_1Factory();
  // 전담 공장에게 엔진 생성을 요청합니다.
  EngineController *engineCtrl = factory->createEngine();

  Vehicle *myCar = new Vehicle(engineCtrl);
  myCar->startOperation();

  // 1. 기존에 들어있던 Engine_1 다 썼으니 지워주기
  delete engineCtrl;
  delete factory; // 가솔린 공장 철거

  // 2. 새 엔진 장착을 위해 전기 모터 전담 공장을 세웁니다.
  factory = new Engine_2Factory();
  engineCtrl = factory->createEngine();
  
  myCar->changeEngine(engineCtrl);
  myCar->startOperation();

  // 3. 프로그램 끝나기 전에 남아있는 객체들 정리
  delete myCar;
  delete engineCtrl;
  delete factory;

  return 0;
}
