#pragma once

#include "msdfgen-core.h"

#ifdef __cplusplus
extern "C"
{
#endif

	// resolve-shape-geometry.h
	bool msdfgen_resolveShapeGeometry(msdfgen_Shape* shape);


	// save-png.h
	/// Saves the bitmap as a PNG file.
	bool msdfgen_savePng_r8(const msdfgen_BitmapConstRefByte* bitmap_r, const char* filename);
	bool msdfgen_savePng_rgb8(const msdfgen_BitmapConstRefByte* bitmap_rgb, const char* filename);
	bool msdfgen_savePng_rgba8(const msdfgen_BitmapConstRefByte* bitmap_rgba, const char* filename);
	bool msdfgen_savePng_r(const msdfgen_BitmapConstRef* bitmap_r, const char* filename);
	bool msdfgen_savePng_rgb(const msdfgen_BitmapConstRef* bitmap_rgb, const char* filename);
	bool msdfgen_savePng_rgba(const msdfgen_BitmapConstRef* bitmap_rgba, const char* filename);


	// import-svg.h
	extern const int msdfgen_SVG_IMPORT_FAILURE;
	extern const int msdfgen_SVG_IMPORT_SUCCESS_FLAG;
	extern const int msdfgen_SVG_IMPORT_PARTIAL_FAILURE_FLAG;
	extern const int msdfgen_SVG_IMPORT_INCOMPLETE_FLAG;
	extern const int msdfgen_SVG_IMPORT_UNSUPPORTED_FEATURE_FLAG;
	extern const int msdfgen_SVG_IMPORT_TRANSFORMATION_IGNORED_FLAG;
	
	/// Builds a shape from an SVG path string
	bool msdfgen_buildShapeFromSvgPath(msdfgen_Shape* shape, const char* pathDef, double endpointSnapRange);

	/// Reads a single <path> element found in the specified SVG file and converts it to output Shape
	bool msdfgen_loadSvgShape(msdfgen_Shape* output, const char* filename, int pathIndex, msdfgen_Vector2* dimensions);

	/// New version - if Skia is available, reads the entire geometry of the SVG file into the output Shape, otherwise may only read one path, returns SVG import flags
	int msdfgen_loadSvgShape_skia(msdfgen_Shape* output, msdfgen_ShapeBounds* viewBox, const char* filename);


	// import-font.h
	typedef unsigned msdfgen_unicode_t;
	typedef struct msdfgen_FreetypeHandle msdfgen_FreetypeHandle;
	typedef struct msdfgen_FontHandle msdfgen_FontHandle;
	typedef unsigned msdfgen_GlyphIndex;

	/// Global metrics of a typeface (in font units).
	typedef struct {
		/// The size of one EM.
		double emSize;
		/// The vertical position of the ascender and descender relative to the baseline.
		double ascenderY, descenderY;
		/// The vertical difference between consecutive baselines.
		double lineHeight;
		/// The vertical position and thickness of the underline.
		double underlineY, underlineThickness;
	} msdfgen_FontMetrics;

	/// A structure to model a given axis of a variable font.
	typedef struct {
		/// The name of the variation axis.
		const char* name;
		/// The axis's minimum coordinate value.
		double minValue;
		/// The axis's maximum coordinate value.
		double maxValue;
		/// The axis's default coordinate value. FreeType computes meaningful default values for Adobe MM fonts.
		double defaultValue;
	} msdfgen_FontVariationAxis;

	/// Initializes the FreeType library.
	msdfgen_FreetypeHandle* msdfgen_initializeFreetype();
	/// Deinitializes the FreeType library.
	void msdfgen_deinitializeFreetype(msdfgen_FreetypeHandle* library);

	/// Loads a font file and returns its handle.
	msdfgen_FontHandle* msdfgen_loadFont(msdfgen_FreetypeHandle* library, const char* filename);
	/// Loads a font from binary data and returns its handle.
	msdfgen_FontHandle* msdfgen_loadFontData(msdfgen_FreetypeHandle* library, const unsigned char* data, int length);
	/// Unloads a font file.
	void msdfgen_destroyFont(msdfgen_FontHandle* font);
	/// Outputs the metrics of a font file.
	bool msdfgen_getFontMetrics(msdfgen_FontMetrics* metrics, msdfgen_FontHandle* font);
	/// Outputs the width of the space and tab characters.
	bool msdfgen_getFontWhitespaceWidth(double* spaceAdvance, double* tabAdvance, msdfgen_FontHandle* font);
	/// Outputs the glyph index corresponding to the specified Unicode character.
	bool msdfgen_getGlyphIndex(msdfgen_GlyphIndex* glyphIndex, msdfgen_FontHandle* font, msdfgen_unicode_t unicode);
	/// Loads the geometry of a glyph from a font file.
	bool msdfgen_loadGlyph(msdfgen_Shape* output, msdfgen_FontHandle* font, msdfgen_GlyphIndex glyphIndex, double* advance);
	bool msdfgen_loadGlyph_unicode(msdfgen_Shape* output, msdfgen_FontHandle* font, msdfgen_unicode_t unicode, double* advance);
	/// Outputs the kerning distance adjustment between two specific glyphs.
	bool msdfgen_getKerning(double* output, msdfgen_FontHandle* font, msdfgen_GlyphIndex glyphIndex1, msdfgen_GlyphIndex glyphIndex2);
	bool msdfgen_getKerning_unicode(double* output, msdfgen_FontHandle* font, msdfgen_unicode_t unicode1, msdfgen_unicode_t unicode2);

#ifdef __cplusplus
}
#endif