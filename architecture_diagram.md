# 팩토리 메서드 패턴 아키텍처 다이어그램

회원님께서 요청하신 **User(사용자) ➡️ Interface(추상화) ⬇️ Class(구현체)** 형태의 `ㄱ`자 모형 다이어그램입니다.

> [!NOTE]
> 좌측 상단의 **User(main, Vehicle)**는 구체적인 하위 클래스들(우측 하단)의 존재를 전혀 모릅니다. 오직 우측 상단의 **Interface**들을 통해서만 소통하며, 이 형태가 객체 지향의 이상적인 `ㄱ`자형 의존성 흐름을 만들어냅니다.

```mermaid
classDiagram
    %% [1] User (Client) 영역 - 좌측 상단 배치
    namespace User {
        class main {
            <<Client>>
            +엔진 공장 선택()
            +차량 생성 및 운행()
        }
        
        class Vehicle {
            -EngineController* engine
            +Vehicle(EngineController* initEngine)
            +changeEngine(EngineController* newEngine)
            +startOperation()
            +stopOperation()
        }
    }

    %% [2] Interface 영역 - 우측 상단 배치
    namespace Interface {
        class EngineFactory {
            <<Interface / Abstract>>
            +createEngine()* EngineController*
        }

        class EngineController {
            <<Interface / Abstract>>
            +startEngine()* void
            +stopEngine()* void
        }
    }

    %% [3] Concrete Class 영역 - 우측 하단 배치 (Interface를 상속받아 내려옴)
    namespace Class {
        class Engine_1Factory {
            +createEngine() EngineController*
        }
        class Engine_2Factory {
            +createEngine() EngineController*
        }
        class Engine_3Factory {
            +createEngine() EngineController*
        }

        class Engine_1 {
            <<Gasoline>>
            +startEngine() void
            +stopEngine() void
        }
        class Engine_2 {
            <<Electric>>
            +startEngine() void
            +stopEngine() void
        }
        class Engine_3 {
            <<Hybrid>>
            +startEngine() void
            +stopEngine() void
        }
    }

    %% User -> Interface 관계 (수평 방향 이동)
    main --> EngineFactory : 1. 공장 객체 생성 요청
    main --> Vehicle : 2. Vehicle 객체 생성
    Vehicle o-- EngineController : 포함 (Aggregation)

    %% Interface -> Class 관계 (수직 방향 하강 - 상속)
    EngineFactory <|-- Engine_1Factory : 상속 (구현)
    EngineFactory <|-- Engine_2Factory : 상속 (구현)
    EngineFactory <|-- Engine_3Factory : 상속 (구현)

    EngineController <|-- Engine_1 : 상속 (구현)
    EngineController <|-- Engine_2 : 상속 (구현)
    EngineController <|-- Engine_3 : 상속 (구현)

    %% Class 내부 관계 (생성)
    Engine_1Factory ..> Engine_1 : Creates (생성)
    Engine_2Factory ..> Engine_2 : Creates (생성)
    Engine_3Factory ..> Engine_3 : Creates (생성)
```

### 💡 다이어그램 읽는 법
*   **실선 화살표 (`-->`)**: 사용(Uses) 또는 참조를 의미합니다. `main`과 `Vehicle`은 인터페이스만 참조합니다.
*   **빈 화살표 (`<|--`)**: 상속(Inheritance)을 의미합니다. 구체적인 클래스들이 인터페이스의 규칙을 따르고 있습니다.
*   **점선 화살표 (`..>`)**: 객체의 생성(Creates)을 의미합니다. 각각의 전담 공장이 자신에게 맞는 엔진을 생성합니다.
*   **다이아몬드 (`o--`)**: 집합(Aggregation) 관계로, 자동차(Vehicle)가 엔진(EngineController)을 부품으로 가지고 있음을 뜻합니다.
