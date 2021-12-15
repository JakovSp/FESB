cbuffer WorldTransforms : register(b0)
{
    matrix World;
    matrix Dlrow;
}

cbuffer ViewTransforms : register(b1)
{
    matrix View;
}

cbuffer ProjectionTransforms : register(b2)
{
    matrix Projection;
}

struct VertxeShaderInput {
    float3 pos : SV_POSITION;
    vector<float,4> color : COLOR;
};
struct  VertxeShaderOutput {
    float4 pos : SV_POSITION;
    float4 color : COLOR0;
};


VertxeShaderOutput main(VertxeShaderInput input)
{
    VertxeShaderOutput output;
    float4 pos = float4(input.pos, 1.0f);
    pos = mul(pos, World);
    pos = mul(pos, View);
    pos = mul(pos, Projection);
    output.pos = pos;
    output.color = input.color;
	return output;
}