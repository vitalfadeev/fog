// [Fog-Graphics Library - Private API]
//
// [License]
// MIT, See COPYING file in package

// For some IDEs to enable code-assist.
#include <Fog/Core/Build.h>

#if defined(FOG_IDE)
#include <Fog/Graphics/RasterEngine/Defs_C_p.h>
#endif // FOG_IDE

namespace Fog {
namespace RasterEngine {

// ============================================================================
// [Fog::RasterEngine::C - Composite - Screen]
// ============================================================================

//! @internal
struct FOG_HIDDEN CompositeScreenC : public CompositeBaseFuncsC32<CompositeScreenC>
{
  enum { CHARACTERISTICS = OPERATOR_CHAR_SCREEN };

  static FOG_INLINE void prgb32_op_prgb32_32b(
    Face::b32_1x2& dst0, Face::b32_1x2 a0, Face::b32_1x2 b0,
    Face::b32_1x2& dst1, Face::b32_1x2 a1, Face::b32_1x2 b1)
  {
    uint32_t b0inv, b1inv;

    Face::b32_2x2Negate(b0inv, b0, b1inv, b1);
    Face::b32_2x2MulDiv255B32_2x2(dst0, a0, b0inv, dst1, a1, b1inv);
    Face::b32_2x2AddB32_2x2(dst0, dst0, b0, dst1, dst1, b1);
  }

  static FOG_INLINE void prgb32_op_xrgb32_32b(
    Face::b32_1x2& dst0, Face::b32_1x2 a0, Face::b32_1x2 b0,
    Face::b32_1x2& dst1, Face::b32_1x2 a1, Face::b32_1x2 b1)
  {
    uint32_t b0inv, b1inv;

    Face::b32_2x2Negate(b0inv, b0, b1inv, b1);
    Face::b32_2x2MulDiv255B32_2x2(dst0, a0, b0inv, dst1, a1, b1inv);
    Face::b32_2x2AddB32_2x2(dst0, dst0, b0, dst1, dst1, b1);
    Face::b32_1x2FillB1(dst1, dst1);
  }

  static FOG_INLINE void xrgb32_op_prgb32_32b(
    Face::b32_1x2& dst0, Face::b32_1x2 a0, Face::b32_1x2 b0,
    Face::b32_1x2& dst1, Face::b32_1x2 a1, Face::b32_1x2 b1)
  {
    uint32_t b0inv, b1inv;

    Face::b32_2x2Negate(b0inv, b0, b1inv, b1);
    Face::b32_2x2MulDiv255B32_2x2(dst0, a0, b0inv, dst1, a1, b1inv);
    Face::b32_2x2AddB32_2x2(dst0, dst0, b0, dst1, dst1, b1);
    Face::b32_1x2FillB1(dst1, dst1);
  }

  static FOG_INLINE void xrgb32_op_xrgb32_32b(
    Face::b32_1x2& dst0, Face::b32_1x2 a0, Face::b32_1x2 b0,
    Face::b32_1x2& dst1, Face::b32_1x2 a1, Face::b32_1x2 b1)
  {
    uint32_t b0inv, b1inv;

    Face::b32_2x2Negate(b0inv, b0, b1inv, b1);
    Face::b32_2x2MulDiv255B32_2x2(dst0, a0, b0inv, dst1, a1, b1inv);
    Face::b32_2x2AddB32_2x2(dst0, dst0, b0, dst1, dst1, b1);
    Face::b32_1x2FillB1(dst1, dst1);
  }
};

} // RasterEngine namespace
} // Fog namespace
