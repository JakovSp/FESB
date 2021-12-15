//Texture2D Texture : register(t0);
//
//SamplerState Sampler : register(s0);
//
//struct PixelShaderInput
//{
//	float4 pos : SV_POSITION;
//	float3 norm : NORMAL;
//	//float2 tex : TEXCOORD0;
//};
//
//float4 main(PixelShaderInput input) : SV_Target
//{
//	//input.worldnormal = normalize(input.worldnormal);
//	float3 direction = normalize(float3(10,0,1));
//
//	float4 color = Texture.Sample(Sampler, input.tex);
//
//	float magnitude = 0.8f * saturate(dot(input.norm, -direction)) + 0.5f;
//
//	return color * magnitude;
//}
struct PixelShaderInput {
	float4 pos : SV_POSITION;
	float4 color : COLOR;
};
float4 main(PixelShaderInput input) : SV_TARGET{
	return input.color;
}