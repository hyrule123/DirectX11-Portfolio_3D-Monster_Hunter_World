#pragma once
#include <Base/Engine/Game/iScene.h>

namespace ehw
{
	class Scene_Title : public iScene
	{
	public:
		Scene_Title();
		virtual ~Scene_Title();

		virtual void OnEnter() override;

	private:
	};
}
