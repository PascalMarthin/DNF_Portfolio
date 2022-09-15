// #include "myshader.hlsli"

// SV_POSITION �ø�ƽ
// �׷���ī�忡�� �̳༮�� �̷� �η��ϱ� �ϰ� �ڵ����� ó���ϴ� �༮�� ������ �ϰ�.

#include "TransformHeader1.fx"
#include "RenderOption1.fx"

// 0                                                                                                1 
// 0�������������������������������������������������������������������������������������������������1

struct Input
{
    float4 Pos : POSITION;
    float4 Tex : TEXCOORD;
};

struct Output
{
    float4 Pos : SV_POSITION;
    float4 PosLocal : POSITION;
    float4 Tex : TEXCOORD;
};

// 1000
// 0100
// 2010
// 0301

// 1020
// 0103
// 0010
// 0001

Output TextureAtlas_VS(Input _Input)
{
    // -0.5, 0.5,     0.5 0.5
    // 0.5, 0.5,     0.5 0.5
    
    Output NewOutPut = (Output)0;
    NewOutPut.Pos = mul(_Input.Pos, WorldViewProjection);
    NewOutPut.PosLocal = _Input.Pos;
    NewOutPut.Tex.xy = _Input.Tex.xy;
    
    // ���ؽ��� ���° ���ؽ� ���� �˼��� ����.
    // NewOutPut.Tex
    // 00    10
    
    //// 10    11
    
    //TextureFrameSize.x -= 0.5f;
    //TextureFrameSize.y -= 0.5f;
    //TextureFramePos.x -= 0.5f;
    //TextureFramePos.y -= 0.5f;
    
    return NewOutPut;
}

cbuffer HPScaleData : register(b0)
{
    float4 HPRatio;
}

Texture2D Tex : register(t0);
SamplerState Smp : register(s0);
float4 TextureAtlas_PS(Output _Input) : SV_Target0
{
    if (_Input.Tex.y > HPRatio.x)
    {
        clip(-1);
    }
    
    float4 TexColor = Tex.Sample(Smp, _Input.Tex.xy);
    
    if (TexColor.a == 0)
    {
        clip(-1);
    }

    
    return TexColor;
}


//Texture2D Tex : register(t0);
//SamplerState Smp : register(s0);
//float4 TextureAtlas_PS(Output _Input) : SV_Target0
//{
//    //if ((_Input.PosLocal.y + 1.f) * 0.5f < HPRatio.x)
//    //{
//    //    clip(-1);
//    //}

    
//    float4 TexColor = Tex.Sample(Smp, _Input.Tex.xy);
    
//    //if (TexColor.a == 0)
//    //{
//    //    clip(-1);
//    //}

    
//    return Tex.Sample(Smp, _Input.Tex.xy);
//}