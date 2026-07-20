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

  // 팩토리 패턴을 사용하여 엔진 생성 (main에서는 구체적인 Engine_1의 존재를 몰라도 됩니다!)
  EngineController *engineCtrl = EngineFactory::createEngine(EngineFactory::GASOLINE);

  Vehicle *myCar = new Vehicle(engineCtrl);
  myCar->startOperation();

  // 1. 기존에 들어있던 Engine_1 다 썼으니 지워주기
  delete engineCtrl;

  // 2. 새 엔진 장착 (마찬가지로 팩토리에 주문만 넣습니다)
  engineCtrl = EngineFactory::createEngine(EngineFactory::ELECTRIC);
  myCar->changeEngine(engineCtrl);
  myCar->startOperation();

  // 3. 프로그램 끝나기 전에 남아있는 myCar와 Engine_2 지워주기
  delete myCar;
  delete engineCtrl;

  return 0;
}
