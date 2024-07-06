#include "../bindings/msdfgen-core.h"
#include "../bindings/msdfgen-ext.h"

#include <assert.h>

int main() {
    msdfgen_FreetypeHandle* ft = msdfgen_initializeFreetype();
    assert(ft);

    msdfgen_FontHandle* font = msdfgen_loadFont(ft, "LiberationMono.ttf");
    assert(font);

    msdfgen_Shape* shape = msdfgen_createShape();
            
    if (msdfgen_loadGlyph(shape, font, 'A', NULL)) {
        msdfgen_normalizeShape(shape);
        msdfgen_edgeColoringSimple(shape, 3.0, 0);

        float msdf[32 * 32 * 3];
        msdfgen_BitmapRef msdf_ref = { msdf, 32, 32 };
        //                                                                  scale,              translation (in em's)
        msdfgen_generateMSDF_old(&msdf_ref, shape, 4.0, (msdfgen_Vector2) { 1.0, 1.0 }, (msdfgen_Vector2) { 4.0, 4.0 }, &msdfgen_ErrorCorrectionConfig_default, true);
        msdfgen_savePng_rgb(&msdf_ref, "output.png");
    }

    msdfgen_destroyShape(shape);
    msdfgen_destroyFont(font);
    msdfgen_deinitializeFreetype(ft);

	return 0;
}