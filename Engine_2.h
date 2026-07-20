#ifndef ENGINE_2_H
#define ENGINE_2_H

#include "EngineController.h"

class Engine_2 : public EngineController {
public:
    void startEngine() override;
    void stopEngine() override;
};

#endif // ENGINE_2_H
