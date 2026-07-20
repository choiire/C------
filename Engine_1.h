#ifndef ENGINE_1_H
#define ENGINE_1_H

#include "EngineController.h"

class Engine_1 : public EngineController {
public:
    void startEngine() override;
    void stopEngine() override;
};

#endif // ENGINE_1_H
