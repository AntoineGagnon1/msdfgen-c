#pragma once

#ifdef __cplusplus
extern "C"
{
#endif
	typedef struct {
		double x, y;
	} msdfgen_Vector2;

	typedef struct {
		msdfgen_Vector2 scale, translate;
	} msdfgen_Projection;

	typedef struct {
		/// Specifies whether to use the version of the algorithm that supports overlapping contours with the same winding. May be set to false to improve performance when no such contours are present.
		bool overlapSupport;
	} msdfgen_GeneratorConfig;

	extern const msdfgen_GeneratorConfig msdfgen_GeneratorConfig_default;

	/// Mode of operation.
	enum msdfgen_Mode {
		/// Skips error correction pass.
		msdfgen_DISABLED,
		/// Corrects all discontinuities of the distance field regardless if edges are adversely affected.
		msdfgen_INDISCRIMINATE,
		/// Corrects artifacts at edges and other discontinuous distances only if it does not affect edges or corners.
		msdfgen_EDGE_PRIORITY,
		/// Only corrects artifacts at edges.
		msdfgen_EDGE_ONLY
	};

	enum msdfgen_DistanceCheckMode {
		/// Never computes exact shape distance.
		msdfgen_DO_NOT_CHECK_DISTANCE,
		/// Only computes exact shape distance at edges. Provides a good balance between speed and precision.
		msdfgen_CHECK_DISTANCE_AT_EDGE,
		/// Computes and compares the exact shape distance for each suspected artifact.
		msdfgen_ALWAYS_CHECK_DISTANCE
	};

	/// The configuration of the MSDF error correction pass.
	typedef struct {
		
		msdfgen_Mode mode;
		msdfgen_DistanceCheckMode distanceCheckMode;

		/// The minimum ratio between the actual and maximum expected distance delta to be considered an error.
		double minDeviationRatio;
		/// The minimum ratio between the pre-correction distance error and the post-correction distance error. Has no effect for DO_NOT_CHECK_DISTANCE.
		double minImproveRatio;
		/// An optional buffer to avoid dynamic allocation. Must have at least as many bytes as the MSDF has pixels.
		unsigned char* buffer;

	} msdfgen_ErrorCorrectionConfig;

	extern const msdfgen_ErrorCorrectionConfig msdfgen_ErrorCorrectionConfig_default;

	typedef struct {
		/// Specifies whether to use the version of the algorithm that supports overlapping contours with the same winding. May be set to false to improve performance when no such contours are present.
		bool overlapSupport;
		/// Configuration of the error correction pass.
		msdfgen_ErrorCorrectionConfig errorCorrection;
	} msdfgen_MSDFGeneratorConfig;

	extern const msdfgen_MSDFGeneratorConfig msdfgen_MSDFGeneratorConfig_default;

	typedef struct {
		float* pixels;
		int width, height;
	} msdfgen_BitmapRef;

	typedef struct {
		const float* pixels;
		int width, height;
	} msdfgen_BitmapConstRef;

	typedef struct {
		const unsigned char* pixels;
		int width, height;
	} msdfgen_BitmapConstRefByte;

	typedef struct msdfgen_Shape msdfgen_Shape;

	typedef struct Bounds {
		double l, b, r, t;
	} msdfgen_ShapeBounds;

	void msdfgen_generateSDF(const msdfgen_BitmapRef* output_r, const msdfgen_Shape* shape, const msdfgen_Projection* projection, double range, const msdfgen_GeneratorConfig* config);

	/// Generates a single-channel signed pseudo-distance field.
	void msdfgen_generatePseudoSDF(const msdfgen_BitmapRef* output_r, const msdfgen_Shape* shape, const msdfgen_Projection* projection, double range, const msdfgen_GeneratorConfig* config);

	/// Generates a multi-channel signed distance field. Edge colors must be assigned first! (See edgeColoringSimple)
	void msdfgen_generateMSDF(const msdfgen_BitmapRef* output_rgb, const msdfgen_Shape* shape, const msdfgen_Projection* projection, double range, const msdfgen_MSDFGeneratorConfig* config);

	/// Generates a multi-channel signed distance field with true distance in the alpha channel. Edge colors must be assigned first.
	void msdfgen_generateMTSDF(const msdfgen_BitmapRef* output_rgba, const msdfgen_Shape* shape, const msdfgen_Projection* projection, double range, const msdfgen_MSDFGeneratorConfig* config);

	// Old version of the function API's kept for backwards compatibility
	void msdfgen_generateSDF_old(const msdfgen_BitmapRef* output_r, const msdfgen_Shape* shape, double range, msdfgen_Vector2 scale, msdfgen_Vector2 translate, bool overlapSupport);
	void msdfgen_generatePseudoSDF_old(const msdfgen_BitmapRef* output_r, const msdfgen_Shape* shape, double range, msdfgen_Vector2 scale, msdfgen_Vector2 translate, bool overlapSupport);
	void msdfgen_generateMSDF_old(const msdfgen_BitmapRef* output_rgb, const msdfgen_Shape* shape, double range, msdfgen_Vector2 scale, msdfgen_Vector2 translate, const msdfgen_ErrorCorrectionConfig* errorCorrectionConfig, bool overlapSupport);
	void msdfgen_generateMTSDF_old(const msdfgen_BitmapRef* output_rgba, const msdfgen_Shape* shape, double range, msdfgen_Vector2 scale, msdfgen_Vector2 translate, const msdfgen_ErrorCorrectionConfig* errorCorrectionConfig, bool overlapSupport);

	// Original simpler versions of the previous functions, which work well under normal circumstances, but cannot deal with overlapping contours.
	void msdfgen_generateSDF_legacy(const msdfgen_BitmapRef* output_r, const msdfgen_Shape* shape, double range, msdfgen_Vector2 scale, msdfgen_Vector2 translate);
	void msdfgen_generatePseudoSDF_legacy(const msdfgen_BitmapRef* output_r, const msdfgen_Shape* shape, double range, msdfgen_Vector2 scale, msdfgen_Vector2 translate);
	void msdfgen_generateMSDF_legacy(const msdfgen_BitmapRef* output_rgb, const msdfgen_Shape* shape, double range, msdfgen_Vector2 scale, msdfgen_Vector2 translate, const msdfgen_ErrorCorrectionConfig* errorCorrectionConfig);
	void msdfgen_generateMTSDF_legacy(const msdfgen_BitmapRef* output_rgba, const msdfgen_Shape* shape, double range, msdfgen_Vector2 scale, msdfgen_Vector2 translate, const msdfgen_ErrorCorrectionConfig* errorCorrectionConfig);



#ifdef __cplusplus
}
#endif