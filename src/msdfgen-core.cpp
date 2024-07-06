#include <bindings/msdfgen-core.h>
#include <src/utils.h>

#include <msdfgen/msdfgen.h>

using namespace msdfgen;

const msdfgen_GeneratorConfig msdfgen_GeneratorConfig_default = msdfgen_GeneratorConfig{true};
const msdfgen_ErrorCorrectionConfig msdfgen_ErrorCorrectionConfig_default = msdfgen_ErrorCorrectionConfig{msdfgen_EDGE_PRIORITY, msdfgen_CHECK_DISTANCE_AT_EDGE, 1.11111111111111111 , 1.11111111111111111, (unsigned char*)0 };
const msdfgen_MSDFGeneratorConfig msdfgen_MSDFGeneratorConfig_default = msdfgen_MSDFGeneratorConfig{true, msdfgen_ErrorCorrectionConfig_default };

void msdfgen_generateSDF(const msdfgen_BitmapRef* output_r, const msdfgen_Shape* shape, const msdfgen_Projection* projection, double range, const msdfgen_GeneratorConfig* config)
{
	generateSDF(PTR_TO_BITMAP(float, 1, output_r), PTR_TO_CONST_REF(Shape, shape), PTR_TO_CONST_REF(Projection, projection), range, PTR_TO_CONST_REF(GeneratorConfig, config));
}

void msdfgen_generatePseudoSDF(const msdfgen_BitmapRef* output_r, const msdfgen_Shape* shape, const msdfgen_Projection* projection, double range, const msdfgen_GeneratorConfig* config)
{
	generatePseudoSDF(PTR_TO_BITMAP(float, 1, output_r), PTR_TO_CONST_REF(Shape, shape), PTR_TO_CONST_REF(Projection, projection), range, PTR_TO_CONST_REF(GeneratorConfig, config));
}

void msdfgen_generateMSDF(const msdfgen_BitmapRef* output_rgb, const msdfgen_Shape* shape, const msdfgen_Projection* projection, double range, const msdfgen_MSDFGeneratorConfig* config)
{
	generateMSDF(PTR_TO_BITMAP(float, 3, output_rgb), PTR_TO_CONST_REF(Shape, shape), PTR_TO_CONST_REF(Projection, projection), range, PTR_TO_CONST_REF(MSDFGeneratorConfig, config));
}

void msdfgen_generateMTSDF(const msdfgen_BitmapRef* output_rgba, const msdfgen_Shape* shape, const msdfgen_Projection* projection, double range, const msdfgen_MSDFGeneratorConfig* config)
{
	generateMTSDF(PTR_TO_BITMAP(float, 4, output_rgba), PTR_TO_CONST_REF(Shape, shape), PTR_TO_CONST_REF(Projection, projection), range, PTR_TO_CONST_REF(MSDFGeneratorConfig, config));
}

void msdfgen_generateSDF_old(const msdfgen_BitmapRef* output_r, const msdfgen_Shape* shape, double range, msdfgen_Vector2 scale, msdfgen_Vector2 translate, bool overlapSupport)
{
	generateSDF(PTR_TO_BITMAP(float, 1, output_r), PTR_TO_CONST_REF(Shape, shape), range, VEC2_CAST(scale), VEC2_CAST(translate), overlapSupport);
}

void msdfgen_generatePseudoSDF_old(const msdfgen_BitmapRef* output_r, const msdfgen_Shape* shape, double range, msdfgen_Vector2 scale, msdfgen_Vector2 translate, bool overlapSupport)
{
	generatePseudoSDF(PTR_TO_BITMAP(float, 1, output_r), PTR_TO_CONST_REF(Shape, shape), range, VEC2_CAST(scale), VEC2_CAST(translate), overlapSupport);
}

void msdfgen_generateMSDF_old(const msdfgen_BitmapRef* output_rgb, const msdfgen_Shape* shape, double range, msdfgen_Vector2 scale, msdfgen_Vector2 translate, const msdfgen_ErrorCorrectionConfig* errorCorrectionConfig, bool overlapSupport)
{
	generateMSDF(PTR_TO_BITMAP(float, 3, output_rgb), PTR_TO_CONST_REF(Shape, shape), range, VEC2_CAST(scale), VEC2_CAST(translate), PTR_TO_CONST_REF(ErrorCorrectionConfig, errorCorrectionConfig), overlapSupport);
}

void msdfgen_generateMTSDF_old(const msdfgen_BitmapRef* output_rgba, const msdfgen_Shape* shape, double range, msdfgen_Vector2 scale, msdfgen_Vector2 translate, const msdfgen_ErrorCorrectionConfig* errorCorrectionConfig, bool overlapSupport)
{
	generateMTSDF(PTR_TO_BITMAP(float, 4, output_rgba), PTR_TO_CONST_REF(Shape, shape), range, VEC2_CAST(scale), VEC2_CAST(translate), PTR_TO_CONST_REF(ErrorCorrectionConfig, errorCorrectionConfig), overlapSupport);
}

void msdfgen_generateSDF_legacy(const msdfgen_BitmapRef* output_r, const msdfgen_Shape* shape, double range, msdfgen_Vector2 scale, msdfgen_Vector2 translate)
{
	generateSDF_legacy(PTR_TO_BITMAP(float, 1, output_r), PTR_TO_CONST_REF(Shape, shape), range, VEC2_CAST(scale), VEC2_CAST(translate));
}

void msdfgen_generatePseudoSDF_legacy(const msdfgen_BitmapRef* output_r, const msdfgen_Shape* shape, double range, msdfgen_Vector2 scale, msdfgen_Vector2 translate)
{
	generatePseudoSDF_legacy(PTR_TO_BITMAP(float, 1, output_r), PTR_TO_CONST_REF(Shape, shape), range, VEC2_CAST(scale), VEC2_CAST(translate));
}

void msdfgen_generateMSDF_legacy(const msdfgen_BitmapRef* output_rgb, const msdfgen_Shape* shape, double range, msdfgen_Vector2 scale, msdfgen_Vector2 translate, const msdfgen_ErrorCorrectionConfig* errorCorrectionConfig)
{
	generateMSDF_legacy(PTR_TO_BITMAP(float, 3, output_rgb), PTR_TO_CONST_REF(Shape, shape), range, VEC2_CAST(scale), VEC2_CAST(translate), PTR_TO_CONST_REF(ErrorCorrectionConfig, errorCorrectionConfig));
}

void msdfgen_generateMTSDF_legacy(const msdfgen_BitmapRef* output_rgba, const msdfgen_Shape* shape, double range, msdfgen_Vector2 scale, msdfgen_Vector2 translate, const msdfgen_ErrorCorrectionConfig* errorCorrectionConfig)
{
	generateMTSDF_legacy(PTR_TO_BITMAP(float, 4, output_rgba), PTR_TO_CONST_REF(Shape, shape), range, VEC2_CAST(scale), VEC2_CAST(translate), PTR_TO_CONST_REF(ErrorCorrectionConfig, errorCorrectionConfig));
}