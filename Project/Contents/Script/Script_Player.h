#pragma once
#include <Engine/Game/Component/Script/Script.h>

namespace ehw
{
    class Script_Player :
        public Script
    {
        CLASS_NAME(Script_Player);
        REGISTER_INSTANCE_DEFAULT(Script_Player);
        
    public:
        Script_Player();
        virtual ~Script_Player();

        virtual void init() override;
        virtual void Awake() override;
        virtual void update() override;

    private:
        void TestCallback();
    };

}

