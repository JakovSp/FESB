//
//cbuffer WorldTransforms : register (b0)
//{
//	matrix World;
//	matrix Dlrow;
//};
//
//cbuffer ViewTransforms : register (b1)
//{
//	matrix View;
//};
//
//cbuffer ProjectionTransforms : register (b2)
//{
//	matrix Projection;
//};
//
//struct VertexShaderInput
//{
//	float3 pos : SV_POSITION;
//	float3 norm : NORMAL;
//	float2 tex : TEXCOORD0;
//};
//
//struct VertexShaderOutput
//{
//	float4 pos : SV_POSITION;
//	float3 norm : NORMAL;
//	float2 tex : TEXCOORD0;
//};
//
//VertexShaderOutput main(VertexShaderInput input)
//{
//	//VertexShaderOutput output;
//	//float4 pos = float4(input.pos, 1.0f);
//
//	//pos = mul(pos, World);
//	//pos = mul(pos, View);
//	//pos = mul(pos, Projection);
//	//output.pos = pos;
//
//	//output.tex = input.tex;
//
//	//float4 norm = float4(normalize(input.norm), 0.0f);
//	//norm = mul(norm, Dlrow);
//	//output.norm = normalize(norm.xyz);
//
//	return output;
//}

cbuffer WorldTransforms : register(b0) {
	matrix World;
	matrix Dlrow;
}
cbuffer ViewTransforms : register(b1) {
	matrix View;
}
cbuffer ProjectionTransforms : register(b2) {
	matrix Projection;
}
struct VertexShaderInput {
	float3 pos : SV_Position;
	vector<float, 4> color : COLOR;
};
struct VertexShaderOutput {
	float4 pos : SV_POSITION;
	float4 color : COLOR0;
};

VertexShaderOutput main(VertexShaderInput input) {
	VertexShaderOutput output;
	float4 pos = float4(input.pos, 1.0f);
	pos = mul(pos, World);
	pos = mul(pos, View);
	pos = mul(pos, Projection);
	output.pos = pos;
	output.color = input.color;
	return output;
}