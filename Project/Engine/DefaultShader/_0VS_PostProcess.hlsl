#include "SH_PostProcess.hlsli"


VSOut main(VSIn _in)
{
    VSOut output = (VSOut) 0.f;
    
    //output.Pos = mul(float4(_in.Pos.xyz, 1.0f), world);
    
    float4 pos = mul(float4(_in.Pos), world);
    float4 viewPos = mul(float4(pos), view);
    float4 projPos = mul(float4(viewPos), projection);
    
    output.Pos = projPos;
    output.UV = _in.UV;
    
    return output;
}