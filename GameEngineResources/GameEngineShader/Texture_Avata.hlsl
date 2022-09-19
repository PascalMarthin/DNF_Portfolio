
// #include "myshader.hlsli"

// SV_POSITION �ø�ƽ
// �׷���ī�忡�� �̳༮�� �̷� �η��ϱ� �ϰ� �ڵ����� ó���ϴ� �༮�� ������ �ϰ�.

#include "TransformHeader.fx"
#include "RenderOption.fx"

// 0                                                                                                1 
// 0�������������������������������������������������������������������������������������������������1

struct Input
{
    float4 Pos : POSITION;
    float4 Tex : TEXCOORD;
    
    // �ν��Ͻ� ������
    uint Index : ROWINDEX;
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

    Output NewOutPut = (Output) 0;
    _Input.Pos += float4(0.0f, 0.5f, 0.0f, 0.0f);

    NewOutPut.Pos = mul(_Input.Pos, WorldViewProjection);
    NewOutPut.PosLocal = _Input.Pos;
    
    
    NewOutPut.Tex = _Input.Tex;
    
    return NewOutPut;
}


Output TextureAtlas_VSINST(Input _Input)
{
    Output NewOutPut = (Output) 0;
    _Input.Pos += float4(0.0f, 0.5f, 0.0f, 0.0f);

    NewOutPut.Pos = mul(_Input.Pos, WorldViewProjection);
    NewOutPut.PosLocal = _Input.Pos;
    
    
    NewOutPut.Tex = _Input.Tex;
    
    return NewOutPut;
}

cbuffer PixelData : register(b0)
{
    float4 MulColor;
    float4 PlusColor;
    float4 Slice;
}

Texture2D Tex : register(t0);
SamplerState Smp : register(s0);
float4 TextureAtlas_PS(Output _Input) : SV_Target0
{

    
    float4 TexColor = Tex.Sample(Smp, _Input.Tex.xy);
    
    if (TexColor.a == 0)
    {
        clip(-1);
    }
    
    return (Tex.Sample(Smp, _Input.Tex.xy) * MulColor) + PlusColor;
}
