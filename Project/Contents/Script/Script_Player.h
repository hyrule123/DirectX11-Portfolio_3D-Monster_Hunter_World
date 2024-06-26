#pragma once
#include <Engine/Scene/Component/Script/iScript.h>

namespace ehw
{
    class Script_Player :
        public iScript
    {
    public:
        Script_Player() {};
        virtual ~Script_Player() {};

        virtual void Init() override;
        virtual void Awake() override;
        virtual void Update() override;

    private:
        void TestCallback();
    };

}

