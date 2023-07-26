#include "EnginePCH.h"

#include "Material.h"

namespace mh::GPU
{
    using namespace mh::math;

    Material::Material()
        : GameResource(eResourceType::Material)
        , mMode(eRenderingMode::Opaque)
    {

    }

    Material::~Material()
    {

    }

    HRESULT Material::Load(const std::filesystem::path& _path)
    {
        return E_NOTIMPL;
    }

    void Material::SetData(eGPUParam _param, void* _data)
    {
        /*switch (_param)
        {
        case mh::GPU::eGPUParam::Int:
            mCB.iData = *static_cast<int*>(_data);
            break;
        case mh::GPU::eGPUParam::Float:
            mCB.fData = *static_cast<float*>(_data);
            break;
        case mh::GPU::eGPUParam::Vector2:
            mCB.XY = *static_cast<Vector2*>(_data);
            break;
        case mh::GPU::eGPUParam::Vector3:
            mCB.XYZ = *static_cast<Vector3*>(_data);
            break;
        case mh::GPU::eGPUParam::Vector4:
            mCB.XYZW = *static_cast<Vector4*>(_data);
            break;
        case mh::GPU::eGPUParam::Matrix:
            mCB.Matrix = *static_cast<Matrix*>(_data);
            break;
        default:
            break;
        }*/

    }

    void Material::Bind()
    {
        for (size_t slotIndex = 0; slotIndex < (UINT)eTextureSlot::End; slotIndex++)
        {
            if (mTexture[slotIndex] == nullptr)
            {
				continue;
            }

            mTexture[slotIndex]->BindShaderResource(eShaderStage::VS, static_cast<UINT>(slotIndex));
            mTexture[slotIndex]->BindShaderResource(eShaderStage::HS, static_cast<UINT>(slotIndex));
            mTexture[slotIndex]->BindShaderResource(eShaderStage::DS, static_cast<UINT>(slotIndex));
            mTexture[slotIndex]->BindShaderResource(eShaderStage::GS, static_cast<UINT>(slotIndex));
            mTexture[slotIndex]->BindShaderResource(eShaderStage::PS, static_cast<UINT>(slotIndex));
            mTexture[slotIndex]->BindShaderResource(eShaderStage::CS, static_cast<UINT>(slotIndex));
        }

        if (mTexture[(UINT)eTextureSlot::Albedo])
        {
            mCB.UsedAlbedo = 1;
        }

        if (mTexture[(UINT)eTextureSlot::Normal])
        {
            mCB.UsedNormal = 1;
        }

        ConstantBuffer* CB = renderer::constantBuffers[(UINT)eCBType::Material];
        CB->SetData(&mCB);
        CB->Bind(eShaderStage::VS);
        CB->Bind(eShaderStage::GS);
        CB->Bind(eShaderStage::PS);

        mShader->Binds();
    }

    void Material::Clear()
    {
        for (size_t slotIndex = 0; slotIndex < (UINT)eTextureSlot::End; slotIndex++)
        {
            if (mTexture[slotIndex] == nullptr)
			{
				continue;
			}

            mTexture[slotIndex]->Clear();
        }
    }
}