#ifndef ENGINE_H
#define ENGINE_H

// Engine 구조체 (인터페이스 역할)
// C언어에서는 객체의 상태(멤버 변수)와 행위(함수 포인터)를 묶어 다형성을 흉내냅니다.
typedef struct Engine {
    void (*startEngine)(void);
    void (*stopEngine)(void);
} Engine;

// 구체 엔진 생성 함수들
Engine* create_gasoline_engine(void);
Engine* create_electric_motor(void);
Engine* create_hybrid_engine(void);

// 엔진 메모리 해제
void destroy_engine(Engine* engine);

#endif // ENGINE_H
