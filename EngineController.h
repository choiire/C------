#ifndef ENGINECONTROLLER_H
#define ENGINECONTROLLER_H

// 추상 클래스 (인터페이스 역할)
class EngineController {
public:
    virtual ~EngineController() {} // 가상 소멸자 필수
    
    // 순수 가상 함수
    virtual void startEngine() = 0;
    virtual void stopEngine() = 0;
};

#endif // ENGINECONTROLLER_H
