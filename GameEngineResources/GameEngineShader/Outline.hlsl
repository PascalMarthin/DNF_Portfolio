// #include "myshader.hlsli"

// SV_POSITION 시맨틱
// 그래픽카드에게 이녀석은 이런 부류니까 니가 자동으로 처리하는 녀석이 있으면 하고.

#include "TransformHeader.fx"
#include "RenderOption.fx"

// 0                                                                                                1 
// 0□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□1

struct Input
{
    float4 Pos : POSITION;
    float4 Tex : TEXCOORD;
    
    // 인스턴싱 데이터
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
    // -0.5, 0.5,     0.5 0.5
    // 0.5, 0.5,     0.5 0.5
    
    Output NewOutPut = (Output) 0;
    _Input.Pos += float4(0.0f, 0.5f, 0.0f, 0.0f);
    NewOutPut.Pos = mul(_Input.Pos, WorldViewProjection);
    NewOutPut.PosLocal = _Input.Pos;
    
    // 버텍스가 몇번째 버텍스 인지 알수가 없다.
    // NewOutPut.Tex
    // 00    10
    
    //// 10    11
    
    //TextureFrameSize.x -= 0.5f;
    //TextureFrameSize.y -= 0.5f;
    //TextureFramePos.x -= 0.5f;
    //TextureFramePos.y -= 0.5f;
    
    NewOutPut.Tex.x = _Input.Tex.x;
    NewOutPut.Tex.y = _Input.Tex.y;
    
    return NewOutPut;
}


Output TextureAtlas_VSINST(Input _Input)
{
    // -0.5, 0.5,     0.5 0.5
    // 0.5, 0.5,     0.5 0.5
    
    Output NewOutPut = (Output) 0;
    _Input.Pos += float4(0.0f, 0.5f, 0.0f, 0.0f);
    NewOutPut.Pos = mul(_Input.Pos, WorldViewProjection);
    NewOutPut.PosLocal = _Input.Pos;
    
    // 버텍스가 몇번째 버텍스 인지 알수가 없다.
    // NewOutPut.Tex
    // 00    10
    
    //// 10    11
    
    //TextureFrameSize.x -= 0.5f;
    //TextureFrameSize.y -= 0.5f;
    //TextureFramePos.x -= 0.5f;
    //TextureFramePos.y -= 0.5f;
    // float4(0.0f, 0.5f, 0.0f, 0.0f);
    
    NewOutPut.Tex.x = _Input.Tex.x;
    NewOutPut.Tex.y = _Input.Tex.y;
    
    
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
    {
    // 파란색
        float2 PixelUVSize = float2(1.0f / 1280.0f, 1.0f / 720.0f);
        float2 PixelUVCenter = _Input.Tex.xy;
        float2 StartUV = PixelUVCenter + (-PixelUVSize * 2);
        float2 CurUV = StartUV;
    
        float4 Result = (float4) 0.0f;
    
        for (int y = 0; y < 5; ++y)
        {
            for (int x = 0; x < 5; ++x)
            {
                Result += Tex.Sample(Smp, CurUV);
                CurUV.x += PixelUVSize.x;
            }
           
            CurUV.x = StartUV.x;
            CurUV.y += PixelUVSize.y;
        }
    
        Result /= 256.0f;
       
    // Color
    // 지금 이 색깔은?
        
        if (Result.a <= 0.0f)
        {
            clip(-1);
        }

    }
    return PlusColor;
}

