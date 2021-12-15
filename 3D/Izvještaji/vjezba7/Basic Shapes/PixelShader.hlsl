struct PixelShaderInput {
	float4 pos : SV_POSITION;
	float4 color : COLOR0;
};

float4 main(struct PixelShaderInput input) : SV_TARGET
{
	return input.color;
}